/*
 * PitchMessage.cpp
 *
 *  Store a PitchMessage, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#include "PitchMessage.h"

PitchMessage::PitchMessage(const char* raw) :
    m_timeStamp(raw, 8),
    m_messageType(raw[8]),
    m_orderID(&raw[9], 12)
{}