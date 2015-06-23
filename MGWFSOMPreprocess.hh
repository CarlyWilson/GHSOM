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
		// Not entirly sure about regular tpes that this point. It'll become more clear as class is made
		MGWFSOMPreprocess(MGWaveform waveform, float sectionSize);

		float CalculateMeanandVariance(MGWaveform waveform, float sectionSize);
		void CalculateOffsetandScale(float meanOneVarianceOne, float meanTwoVarianceTwo);// based off of Ben's powerpoint
		void TransformOutofPlace(float fOffset, float fScale);

	private:
		// Types these should be will become more obvious as class is completed, float meanwhile
		float fWFRegion;
		float fWindowSize;
		float fOffset;
		float fScale;
		float fBaselineRMS;
		float fFlattopRMS;
};

#endif
