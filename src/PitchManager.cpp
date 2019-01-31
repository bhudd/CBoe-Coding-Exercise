/*
 * PitchManager.cpp
 *
 *  Handles the processing of PITCH messages from cin
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchManager.h"
#include "PitchOrderCancel.h"
#include "PitchOrderExecuted.h"
#include "PitchTrade.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const std::unordered_map<char, processFunc> PitchManager::m_funcMap = {
    {'A', &PitchManager::ProcessAddOrderShort},
    {'E', &PitchManager::ProcessOrderExecuted},
    {'X', &PitchManager::ProcessOrderCancel},
    {'P', &PitchManager::ProcessTradeShort},
    {'d', &PitchManager::ProcessAddOrderLong},
    {'s', &PitchManager::ProcessSymbolClear},
    {'r', &PitchManager::ProcessTradeLong}
};

const bool Comparator(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
    return a.second > b.second;
}

#include <chrono>
using namespace std::chrono;

PitchManager::PitchManager()
{
    auto start = high_resolution_clock::now();
    std::string temp;
#ifdef PITCH_DEBUG
    std::ifstream is("out");
    while(std::getline(is, temp))
#else
    while(std::getline(std::cin, temp) && !temp.empty())
#endif
    {
        // message type is offset 8 of actual message, but
        // we have an extra 'S' at the beginning of each message
        (this->*m_funcMap.at(temp.data()[9]))(&temp.data()[1]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << std::endl;

    start = high_resolution_clock::now();
    // after processing, sort.
    std::vector<std::pair<std::string, int>> elems(m_executedOrders.begin(), m_executedOrders.end());
    std::sort(elems.begin(), elems.end(), Comparator);

    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    // top 10!
    int last = 10;
    if(m_executedOrders.size() < 10)
        last = m_executedOrders.size();
    // only print as many as we have if we have <10 executed orders (highly unlikely...)
    for(int i = 0; i < last; ++i)
        printf("%s %d\n", elems[i].first.c_str(), elems[i].second);
}

void PitchManager::ProcessAddOrderShort(const char* msgData)
{
    auto p = std::unique_ptr<PitchAddOrder>(new PitchAddOrder(msgData));
    m_openOrders[p->OrderID()] = std::move(p);
}

void PitchManager::ProcessOrderExecuted(const char* msgData)
{
    PitchOrderExecuted p(msgData);

    // add the executed shares
    m_executedOrders[m_openOrders[p.OrderID()]->Symbol()] += p.ExecutedShares();
        
    // remove executed shares from open order.
    // if we execute all shares of this open order, remove it
    if(m_openOrders[p.OrderID()]->RemoveShares(p.ExecutedShares()))
        m_openOrders.erase(p.OrderID());
}

void PitchManager::ProcessOrderCancel(const char* msgData)
{
    PitchOrderCancel p(msgData);
    // remove canceled shares from open order.
    // if we execute all shares of this open order, remove it
    if(m_openOrders[p.OrderID()]->RemoveShares(p.CanceledShares()))
        m_openOrders.erase(p.OrderID());
}

void PitchManager::ProcessTradeShort(const char* msgData)
{
    PitchTrade p(msgData);
    // add directly to the executed orders
    m_executedOrders[p.Symbol()] += p.Shares();
}

void PitchManager::ProcessAddOrderLong(const char*)
{
    // unused in example
}

void PitchManager::ProcessSymbolClear(const char*)
{
    // unused in example
}

void PitchManager::ProcessTradeLong(const char*)
{
    // unused in example
}
