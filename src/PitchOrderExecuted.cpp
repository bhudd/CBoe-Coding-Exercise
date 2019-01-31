/*
 * PitchOrderExecuted.cpp
 *
 *  Store a PitchMessage that is an Order Executed command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchOrderExecuted.h"

PitchOrderExecuted::PitchOrderExecuted(const char* raw) :
    PitchMessage(raw),
    m_executedShares(std::stoi(std::string(&raw[21], 6))),
    m_executionID(&raw[27], 12)
{}