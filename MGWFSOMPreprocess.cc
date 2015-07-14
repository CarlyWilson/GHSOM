//-----------------------------------------------------------------------
//
// Name: MGWFSOMPreprocess.cc
// 
// Description: Used to Preprocess wave forms by use of mean, variance, offset, and scale
// 
// Author: Carly Wilson
//
//-----------------------------------------------------------------------

#include "MGWFSOMPreprocess.hh"

MGWFSOMPreprocess::MGWFSOMPreprocess(MGWaveform waveform, double sectionSize){
	fWaveform = waveform;
	
	fWFData = waveform->GetVectorData();
	fWFRegion = sectionSize;
}

void MGWFSOMPreprocess::CalculateMeanandVariance(MGWaveform waveform, double sectionSize){
	// By the time I got to this the article for one Pass 404'ed this is two pass instead
	size_t n = 0;
	size_t sum = 0;
	size_t sum2 = 0;
	double mean = 0;
	double variance = 0;

	for(size_t i = 0; i < sectionSize; i++){
		n = n + 1;
		sum = sum + fWFData[i];
	} 
	mean = sum/n;

	for(size_t i = 0; i < sectionSize; i++){
		sum2 = sum2 + (fWFData[i] - mean)*(fWFData[i] - mean);
	}

	variance = sum2/(n-1);

	fMeanVariance[0] = mean;
	fMeanVariance[1] = variance;
}

void MGWFSOMPreprocess::CalculateOffsetandScale(){
	//mean1var1 is baseline, mean2var2 is flattop
	fBaselineRMS = GetBaseline(fWaveform);
	fFlattopRMS = 0 // cannot find! Is it called something else?

	meanOneVarianceOne = fBaselineRMS;
	meanTwoVarianceTwo = fFlattopRMS;

	fOffset = (meanTwoVarianceTwo + meanOneVarianceOne)/2;
	fScale = (meanTwoVarianceTwo - meanOneVarianceOne)/2;
}

void MGWFSOMPreprocess::TransformOutofPlace(double fOffset, double fScale){
	// not sure how to scale
}
