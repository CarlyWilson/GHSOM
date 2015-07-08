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
	fWFData = waveform->GetVectorData();
	fWFRegion = sectionSize;
}

void MGWFSOMPreprocess::CalculateMeanandVariance(MGWaveform waveform){
	// By the time I got to this the article for one Pass 404'ed this is two pass instead
	size_t n = 0;
	size_t sum = 0;
	size_t sum2 = 0;
	double mean = 0;
	double variance = 0;

	for(size_t i = 0; i < fWFData.size(); i++){
		n = n + 1;
		sum = sum + fWFData[i];
	} 
	fMean = sum/n;

	for(size_t i = 0; i < fWFData.size(); i++){
		sum2 = sum2 + (fWFData[i] - mean)*(fWFData[i] - mean);
	}

	fVariance = sum2/(n-1);
}

void MGWFSOMPreprocess::CalculateOffsetandScale(double meanOneVarianceOne, double meanTwoVarianceTwo){
	fOffset = (meanTwoVarianceTwo + meanOneVarianceOne)/2;
	fScale = (meanTwoVarianceTwo - meanOneVarianceOne)/2;
}

void MGWFSOMPreprocess::TransformOutofPlace(double fOffset, double fScale){
}
