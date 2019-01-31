/*
 * PitchOrderCancel.h
 *
 *  Store a PitchMessage that is an Order Cancel command, as defined in the following standard: 
 *  http://cdn.batstrading.com/resources/membership/BATS_US_EQUITIES_TCP_PITCH_SPECIFICATION.pdf
 *  Created on: Jul 5, 2018
 *      Author: bhuddleston
 */

#ifndef PITCHORDERCANCEL_H_
#define PITCHORDERCANCEL_H_

#include "PitchMessage.h"

class PitchOrderCancel : public PitchMessage {
public:
    PitchOrderCancel(const char* raw);
    const int& CanceledShares() const {return m_canceledShares;}
private:
    int m_canceledShares;
};

#endif /* PITCHORDERCANCEL_H_ */
