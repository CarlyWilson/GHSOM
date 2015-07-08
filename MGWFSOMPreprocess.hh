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
#include <MGWaveform.hh>

using namespace std;

Class MGWFSOMPreprocess{
	
	public:
		MGWFSOMPreprocess(MGWaveform waveform, double sectionSize);
		void CalculateMeanandVariance(MGWaveform waveform, double sectionSize);
		void CalculateOffsetandScale(double meanOneVarianceOne, double meanTwoVarianceTwo);
		void TransformOutofPlace(float fOffset, float fScale);

	private:
		vector<double> fWFData;
		double fWFRegion;
		double fVariance;
		double fMean;
		float fWindowSize;
		float fOffset;
		float fScale;
		float fBaselineRMS;
		float fFlattopRMS;
};

#endif
