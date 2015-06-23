//-----------------------------------------------------------------------
//
// Name: MGWFSOMWindowAlign.hh
//
// Description: Used to Preprocess wave forms by use of zero crossing, interpolate, 
//				window, and window variance
//
// Author: Carly Wilson
//
//-----------------------------------------------------------------------

#ifndef MGWFSOMWINDOWALIGN_HH_
#define MGWFSOMWINDOWALIGN_HH_

#include <iostream>
#include <MGWaveform.hh>

using namespace std;

Class MGWFSOMWindowAlign{
	
	public:
		// Types will become more clear as class is completed
		MGWFSOMWindowAlign(MGWaveform waveform, float sectionSize);// I'm assuming here that it takes the same input as MGWFSOMPreprocess?
		float FindZeroCrossing(MGWaveform waveform);
		
		void InterpolateandWindow(float fAbsoluteZeroCrossing);
		void WindowVariance(float fWindowedWF);
		

	private:
		// Type will become more obvious as class is made. Until then float will do.
		float fWindowedWF;
		float fWFVar;
		float fAbsoluteZeroCrossing;
};

#endif
