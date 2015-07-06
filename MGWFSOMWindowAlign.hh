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
		MGWFSOMWindowAlign(MGWaveform waveform);
		void FindZeroCrossing();
		void InterpolateandWindow();
		void WindowVariance();
		void setMU(double muValue);
		

	private:
		vector<double> fWindowedWF;
		double fWFVar;
		double fLinInterp;
		double fCubicSpline;
		double mu;
		size_t fAbsoluteZeroCrossing;
};

#endif
