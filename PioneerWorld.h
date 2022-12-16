/*
 * FILE:        PioneerWorld.h
 * Project:	    PROG 1385 - Assignment 6
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		August 05, 2022
 * Description:  This file contains a class declaration which is inherited from
   the PioneerAM class and its methods*/

#pragma once
#include "PioneerAM.h"

   /* NAME: PioneerWorld
   * PURPOSE:  The PioneerWorld is inherited from the PioneerAM class. This class is used to instantiate
   * new PioneerWorld radio objects. it operates in the AM band only and There is no ability to change to the FM band
   */
class PioneerWorld : public PioneerAM
{
private:
public:

	// constructor
	PioneerWorld(bool newOn, Freqs newButton[MAX_FREQS], int newRadioType) : PioneerAM(false, newButton, newRadioType) {}

	/*  -- Method Header Comment
	Name	: ~PioneerWorld -- DESTRUCTOR
	Purpose : to destroy the PioneerWorld object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	a final message from the object before being destroyed
	Returns	:	Nothing
	*/
	virtual ~PioneerWorld(void)
	{
		if (GetDisplayOutPut())
		{
			cout << "Destroying Pioneer XS440-WRLD Radio\n";
		}
	}

	/*  -- Method Header Comment
	Name	: ScanUp
	Purpose : This method will change the current_station by incrementing by 9 on AM band
	Inputs	:	NONE
	Outputs	:	the value of current_station and frequency
	Returns	:	NONE
	*/
	void ScanUp(void)
	{
		// Check the curret station if it is max value or not
		if (GetCurrentStation() >= MAX_AM_WORLD)
		{
			SetCurrentStation(MINIUM_AM_WORLD);
		}
		else
		{
			// if is not max value then increase by 9
			SetCurrentStation(GetCurrentStation() + 9);
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
		if (GetCurrentStation() <= MINIUM_AM_WORLD)
		{
			SetCurrentStation(MAX_AM_WORLD);
		}
		else
		{
			// if is not max value then decrease by 10
			SetCurrentStation(GetCurrentStation() - 9);
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