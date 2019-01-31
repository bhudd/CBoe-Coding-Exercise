/*
 * PitchOrderExecuted.h
 *
 *  Store a PitchMessage that is an Order Executed command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHORDEREXECUTED_H_
#define PITCHORDEREXECUTED_H_

#include "PitchMessage.h"

class PitchOrderExecuted : public PitchMessage {
public:
    PitchOrderExecuted(const char* raw);
    const int& ExecutedShares() const {return m_executedShares;}
private:
    int m_executedShares;
    std::string m_executionID;
};

#endif /* PITCHORDEREXECUTED_H_ */
