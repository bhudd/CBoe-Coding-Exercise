/*
 * PitchManager.h
 *
 *  Handles the processing of PITCH messages from cin
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHMANAGER_H_
#define PITCHMANAGER_H_

#define PITCH_DEBUG
// #undef PITCH_DEBUG

#include <unordered_map>
#include <map>
#include <memory>
#include "PitchAddOrder.h"

class PitchManager;
typedef void(PitchManager::*processFunc)(const char*);

class PitchManager {
public:
    PitchManager();

private:
    void ProcessAddOrderShort(const char*);
    void ProcessOrderCancel(const char*);
    void ProcessOrderExecuted(const char*);
    void ProcessTradeShort(const char*);
    void ProcessAddOrderLong(const char*);
    void ProcessSymbolClear(const char*);
    void ProcessTradeLong(const char*);

    static const std::unordered_map<char, processFunc> m_funcMap;
    std::unordered_map<std::string, std::unique_ptr<PitchAddOrder>> m_openOrders;
    std::unordered_map<std::string, int> m_executedOrders;
};

#endif /* PITCHMANAGER_H_ */
