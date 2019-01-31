/*
 * PitchTrade.h
 *
 *  Store a PitchMessage that is a Trade command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHTRADE_H_
#define PITCHTRADE_H_

#include "PitchMessage.h"

class PitchTrade : public PitchMessage {
public:
    PitchTrade(const char* raw);
    const std::string& Symbol() const {return m_stockSymbol;}
    const int& Shares() const {return m_numShares;}
private:
    char m_sideindicator;
    int m_numShares;
    std::string m_stockSymbol;
    std::string m_price;
    std::string m_executionID;
};

#endif /* PITCHADDORDER_H_ */
