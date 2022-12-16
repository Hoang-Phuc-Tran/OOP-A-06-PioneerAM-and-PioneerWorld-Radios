/*
 * FILE:        AmFmRadio.h
 * Project:	    PROG 1385 - Assignment 3
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		June 23, 2022
 * Description:  This file contains constants used in AmFmRadio class methods. It also contains
 a class declaration and a struct Freqs that holds 2 Frequencies (AM and FM bands).
 */ 

#ifndef _CARRADIO_H
#define _CARRADIO_H
#pragma warning (disable:4996)

#define MAX_FREQS 5			 // maximum number of presets
#define MAX_CHAR 3			 // Max length of char[]
#define MINIMUM_AM 530		 // minimum frequency of AM band
#define MAX_AM 1700			 // maximum frequency of AM band
#define MAX_AM_WORLD 1602	 // maximum frequency of Pioneer XS440-AM band
#define MINIUM_AM_WORLD 531	 // minimum requency of Pioneer XS440-AM band
#define MINIMUM_FM 87.9		 // minimum frequency of FM band
#define MAX_FM 107.9		 // maximum frequency of FM band
#define SUCCESS 0			 // 0 indicates successfully
#define FAILURE 1			 // 1 indicates failure
#define INIT_STATION 800	 // Initilize the current station is 800 as a default
#define INIT_VOLUME 4		 // Initilize the current volume is 4 as a defualt
#define Pioneer_XS440 21	 // represents Pioneer XS440 radio
#define	Pioneer_XS440_AM 22	 // represents Pioneer XS440-AM radio
#define Pioneer_XS440_WRLD 23// represents Pioneer XS440-WRLD radio
#define PIONEER_WORLD_SCAN 9 // This value is used to scan up and scan down in PioneerWorld class
#define AM 'A'				 // represents AM band
#define PM 'P'				 // represents PM band


// This struct holds 2 frequencies: AM and FM bands
struct Freqs
{
	int AMFreq;
	double FMFreq;
	double currentStation;    // Holds a value of current_station before switch to AM or FM band
	int volumeStruct;         // Holds current NewVolume before turn off the radio
};


/* NAME: AmFmRadio
 * PURPOSE: The AmFmRadio class has been created to model the AM/FM Radio.
 *   It has an on/off power,sets volume, toggles AM/FM frequency,sets and selects. It also can 
     scan up and scan down the volume. Class has the ability to get/set the member values, 
	 as well as some methods for displaying settings.
 */
class AmFmRadio
{
private:
	Freqs	button[MAX_FREQS];			// an array of 5 struct Freqs that contains the initial radio preset values
	double	current_station;			// Holding the current station of the radio
	char	frequency[MAX_CHAR];		// holding an FM or AM Frequency
	int		newVolume;					// Holding the volume value of the radio
	bool	on;							//  a true if the radio is currently powered on, and false if the radio is in the off position
	bool	displayOutPut;				// this private bool data member is set so that no output is coming from any methods
	int		typeOfRadio;				// Holding the type of radio

	Freqs	copyButton[MAX_FREQS];		// This array of Freqs is created to hold a copy of Freqs button[] 
	char	copyFrequency[MAX_CHAR];	// This char[] is created to hold a copy of frequency[]
public:
	
	// Constructors
	AmFmRadio(bool newOn = false);
	AmFmRadio(bool newOn, Freqs newButton[], int newRadioType);

	// Destructors
	virtual ~AmFmRadio(void);


	// ************** Mutators ***************
	
	//sets on to true
	void PowerToggle(void);
	//toggles frequency between AM and FM and sets current station
	virtual void ToggleFrequency(void);
	//sets button with current station by being passed a button number
	int SetButton(int button_num);
	//sets current station by being passed a button number
	int SelectCurrentStation(int button_num);
	//sets volume
	int SetVolume(void);
	// sets volume
	int SetVolume(int volume);
	// Set the frequency AM or PM for the radio
	void SetFrequency(int inputFrequency);
	// Set value for the current_station data member
	int SetCurrentStation(double newCurrentStation);


	//******************* Methods ********************** 
	
	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn(void);
	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings(void);
	//changes frequency up in increments of .2 for FM, 10 for AM
	virtual void ScanUp(void);
	//changes frequency up in decrements of .2 for FM, 10 for AM
	virtual void ScanDown(void);
	// Turn displayOutPut to False or True
	void ToggleDisplayOutPut(void);


	//******************* Accessors **********************

	double GetCurrentStation(void);     // get current_station data member
	int GetNewVolume(void);             // get newVolume data memeber
	char* GetFrequency(void);           // get "AM" / "PM" string
	Freqs* GetButton(void);             // get a number of presets
	bool GetDisplayOutPut(void);        // get displayOutPut data member
	int GetTypeOfRadio(void);			// get typeOfRadio data member

};
#endif