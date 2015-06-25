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

MGWFSOMPreprocess::CalculateMeanandVariance(MGWaveform waveform, double sectionSize){
	
}

MGWFSOMPreprocess::CalculateOffsetandScale(double meanOneVarianceOne, double meanTwoVarianceTwo){
	fOffset = (meanTwoVarianceTwo + meanOneVarianceOne)/2;
	fScale = (meanTwoVarianceTwo - meanOneVarianceOne)/2;
}

MGWFSOMPreprocess::TransformOutofPlace(double fOffset, double fScale){
	// There are a lot of different TransformOutofPlaces in MGDO. Need more information about what it needs to do so I can pick the right one?
}
