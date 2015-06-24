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

#include <vector>

using namespace std;

Class MGWFSOMWindowAlign{
	
	public:
		// Types will become more clear as class is completed
		MGWFSOMWindowAlign(MGWaveform waveform);
		
		void FindZeroCrossing();
		void InterpolateandWindow();
		void WindowVariance(float fWindowedWF);
		

	private:
		// Type will become more obvious as class is made. Until then float will do.
		const vector<double> fWFData;
		size_t fWFVar;
		size_t fAbsoluteZeroCrossing;
		float fWindowedWF;
};

#endif
