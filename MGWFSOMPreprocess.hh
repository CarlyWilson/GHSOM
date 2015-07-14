//-----------------------------------------------------------------------
//
// Name: MGWFSOMPreprocess.hh
//
// Description: Used to Preprocess wave forms by use of mean, variance, offset, and scale
//
// Author: Carly Wilson
//
//-----------------------------------------------------------------------

#ifndef MGWFSOMPREPROCESS_HH_
#define MGWFSOMPREPROCESS_HH_

#include <iostream>
#include <MGTWaveform.hh>

using namespace std;

Class MGWFSOMPreprocess{
	
	public:
		MGWFSOMPreprocess(MGWaveform waveform, double sectionSize);
		void CalculateMeanandVariance(MGWaveform waveform, double sectionSize);
		void CalculateOffsetandScale();
		void TransformOutofPlace(double fOffset, double fScale);

	private:
		vector<double> fWFData;
		MGWaveform fWaveform;
		vector<double> fMeanVariance;
		double fWFRegion;
		double fWindowSize;
		double fOffset;
		double fScale;
		double fBaselineRMS;
		double fFlattopRMS;
};

#endif
