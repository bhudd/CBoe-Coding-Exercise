/*
 * PitchOrderCancel.cpp
 *
 *  Store a PitchMessage that is an Order Cancel command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchOrderCancel.h"

PitchOrderCancel::PitchOrderCancel(const char* raw) :
    PitchMessage(raw),
    m_canceledShares(std::stoi(std::string(&raw[21], 6)))
{}