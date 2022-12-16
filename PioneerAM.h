/*
 * FILE:        PioneerAM.h
 * Project:	    PROG 1385 - Assignment 6
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		August 05, 2022
 * Description:  This file contains a class declaration which is inherited from 
   the PioneerCarRadio class and its methods*/

#pragma once
#include "PioneerCarRadio.h"


/* NAME: PioneerAM
* PURPOSE:  The PioneerAM is inherited from the PioneerCarRadio class. This class is used to instantiate
* new PioneerAM radio objects. it operates in the AM band only and There is no ability to change to the FM band 
*/
class PioneerAM : public PioneerCarRadio
{
private:
public:

	// constructor
	PioneerAM(bool newOn, Freqs newButton[MAX_FREQS], int newRadioType) : PioneerCarRadio(false, newButton, newRadioType) {}

	/*  -- Method Header Comment
	Name	: ~PioneerAM -- DESTRUCTOR
	Purpose : to destroy the PioneerAM object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	a final message from the object before being destroyed
	Returns	:	Nothing
	*/
	virtual ~PioneerAM(void)
	{
		if (GetDisplayOutPut())
		{
			cout << "Destroying Pioneer XS440-AM Radio\n";
		}
	}

	/*  -- Method Header Comment
	Name	: 	void ToggleFrequency(void)
	Purpose : This method will save the current_station before switching AM 
			frequency to FM frequency and otherwise. However this method only sets AM band
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	NONE
	*/
	void ToggleFrequency(void)
	{
		SetFrequency(AM);
	}

	/*  -- Method Header Comment
	Name	: ScanUp
	Purpose : This method will change the current_station by incrementing by 10 on AM band
	Inputs	:	NONE
	Outputs	:	the value of current_station and frequency
	Returns	:	NONE
	*/
	void ScanUp(void)
	{
		// Check the curret station if it is max value or not
		if (GetCurrentStation() >= MAX_AM)
		{
			SetCurrentStation(MINIMUM_AM);
		}
		else
		{
			// if is not max value then increase by 10
			SetCurrentStation(GetCurrentStation() + 10);
		}

		if (GetDisplayOutPut())
		{
			printf("\nCurrent station: %f\n", GetCurrentStation());

			// Check and only display AM band
			if (strcmp(GetFrequency(), "AM"))
			{
				printf(" AM\n");
			}
		}
	}

	/*  -- Method Header Comment
	Name	: ScanDown
	Purpose : This method will change the current_station by incrementing by 10 on AM band
	Inputs	:	NONE
	Outputs	:	the value of current_station and frequency
	Returns	:	NONE
	*/
	void ScanDown(void)
	{
		// Check the curret station if it is minimum value or not
		if (GetCurrentStation() <= MINIMUM_AM)
		{
			SetCurrentStation(MAX_AM);
		}
		else
		{
			// if is not max value then decrease by 10
			SetCurrentStation(GetCurrentStation() - 10);
		}

		if (GetDisplayOutPut())
		{
			printf("\nCurrent station: %f\n", GetCurrentStation());

			// Check and only display AM band
			if (strcmp(GetFrequency(), "AM"))
			{
				printf(" AM\n");
			}
		}
	}

};