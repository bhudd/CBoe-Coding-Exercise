
/*
 * PitchAddOrder.cpp
 *
 *  Store a PitchMessage that is an Add Order command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchAddOrder.h"

PitchAddOrder::PitchAddOrder(const char* raw) :
    PitchMessage(raw),
    m_sideindicator(raw[21]),
    m_numShares(std::stoi(std::string(&raw[22], 6))),
    m_stockSymbol(&raw[28], 6),
    m_price(&raw[34], 10),
    m_display(raw[44])
{}

/**
 * Returns true if removed all shares, false otherwise
 */
bool PitchAddOrder::RemoveShares(const int& canceledShares)
{
    m_numShares -= canceledShares;
    return m_numShares == 0;
}