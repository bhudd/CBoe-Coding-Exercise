/*
 * PitchAddOrder.h
 *
 *  Store a PitchMessage that is an Add Order command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHADDORDER_H_
#define PITCHADDORDER_H_

#include "PitchMessage.h"

class PitchAddOrder : public PitchMessage {
public:
    PitchAddOrder(const char* raw);
    bool RemoveShares(const int& shares);
    const int& OpenShares() const {return m_numShares;}
    const std::string& Symbol() const {return m_stockSymbol;}
private:
    char m_sideindicator;
    int m_numShares;
    std::string m_stockSymbol;
    std::string m_price;
    char m_display;
};

#endif /* PITCHADDORDER_H_ */