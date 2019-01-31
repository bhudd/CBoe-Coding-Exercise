
/*
 * PitchTrade.cpp
 *
 *  Store a PitchMessage that is a Trade command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchTrade.h"

PitchTrade::PitchTrade(const char* raw) :
    PitchMessage(raw),
    m_sideindicator(raw[21]),
    m_numShares(std::stoi(std::string(&raw[22], 6))),
    m_stockSymbol(&raw[28], 6),
    m_price(&raw[34], 10),
    m_executionID(&raw[44], 12)
{}