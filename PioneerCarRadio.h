/*
 * FILE:        PioneerCarRadio.h
 * Project:	    PROG 1385 - Assignment 5
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		July 21, 2022
 * Description:  This file contains a class declaration which is inherited from the AmFmRadio class*/

// PRAGMA
#pragma once

#include "AmFmRadio.h"
#include <iomanip>
#include <conio.h>
#include <iostream>

using namespace std;



/*NAME:  PioneerCarRadio
* PURPOSE : The AmFmRadio is inherited from the AmFmRadio class. This class is used as
a user interface based on buttons (represented by keypresses obtained through a getch() function call)
*/
class PioneerCarRadio : public AmFmRadio
{
public:

	// constructor
	PioneerCarRadio(bool newOn, Freqs newButton[MAX_FREQS], int newRadioType);

	// Destructor
	virtual ~PioneerCarRadio(void);

	// Display the information of the radio
	void DisplayRadio(void);

	// Get user input and control the interface of the radio
	int RadioManagement(void);

};