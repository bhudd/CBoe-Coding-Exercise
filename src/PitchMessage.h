/*
 * PitchMessage.h
 *
 *  Store a PitchMessage, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHMESSAGE_H_
#define PITCHMESSAGE_H_

#include <string>

class PitchMessage {
public:
    PitchMessage(const char* raw);
    const std::string& OrderID() const {return m_orderID;}
private:
    std::string m_timeStamp;
    char m_messageType;
    std::string m_orderID; //base-36 numeric
};

#endif /* PITCHMESSAGE_H_ */
