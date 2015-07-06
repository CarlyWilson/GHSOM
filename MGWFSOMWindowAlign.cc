//-----------------------------------------------------------------------
//
// Name: MGWFSOMWindowAlign.cc
//
// Description: Used to Preprocess wave forms by use of zero crossing, interpolate, 
//				window, and window variance
//
// Author: Carly Wilson
//
//-----------------------------------------------------------------------

#include "MGWFSOMWindowAlign.hh"
#include "MGWICubicSpline.hh"

MGWFSOMWindowAlign::MGWFSOMWindowAlign(MGWaveform waveform){
	fWindowedWF = waveform->GetVectorData();
	mu = 0.01 // should be between 0 and 1
}

void MGWFSOMWindowAlign::FindZeroCrossing(){

	size_t indexNeg = fWindowedWF.size()/2;
	size_t indexPos = indexNeg;

	if(fWindowedWF.size() % 2 == 0){
		indexNeg = indexNeg - 1;
	}

	double trueMiddle = (fWindowedWF[indexNeg] + fWindowedWF[indexPos])/2;

	bool startsPositive = trueMiddle >= 0;
	bool startsNegative = trueMiddle <= 0;

	while((indexPos < fWindowedWF.size()) && (indexNeg >= 0){
		if(startsNegative){
			if(fWindowedWF[indexPos] > 0){
				fAbsoluteZeroCrossing = indexPos;
				return;
			}
		}
		else if(startsPositive){
			if(fWindowedWF[indexPos] < 0){
				fAbsoluteZeroCrossing = indexPos;
				return;
			}
		}
		indexPos++;

		if(startsPositive){
			if(fWindowedWF[indexNeg] < 0){
				fAbsoluteZeroCrossing = indexNeg;
				return;
			}
		}
		else if(startsNegative){
			if(fWindowedWF[indexNeg] > 0){
				fAbsoluteZeroCrossing = indexNeg;
				return;
			}
		}
		indexNeg--;
	}
}

void MGWFSOMWindowAlign::InterpolateandWindow(){
	// Linear Interpolation
	if(fWindowedWF[fAbsoluteZeroCrossing] > 0){
		fLinInterp = fWindowedWF[fAbsoluteZeroCrossing]*(1 - mu) + fWindowedWF[fAbsoluteZeroCrossing + 1] * mu;
	}
	else{
		fLinInterp = fWindowedWF[fAbsoluteZeroCrossing]*(1 - mu) + fWindowedWF[fAbsoluteZeroCrossing - 1] * mu;
	}

	// CubicSpline interpolation

	double a0, a1, a2, a4, mu2;

	if(fWindowedWF[fAbsoluteZeroCrossing] > 0){
		a0 = fWindowedWF[fAbsoluteZeroCrossing + 3] - fWindowedWF[fAbsoluteZeroCrossing + 2] - fWindowedWF[fAbsoluteZeroCrossing] + fWindowedWF[fAbsoluteZeroCrossing + 1];
		a1 = fWindowedWF[fAbsoluteZeroCrossing] - fWindowedWF[fAbsoluteZeroCrossing + 1] - a0;
		a2 = fWindowedWF[fAbsoluteZeroCrossing + 2] - fWindowedWF[fAbsoluteZeroCrossing];
		a3 = fWindowedWF[fAbsoluteZeroCrossing + 1]

		fCubicSpline = a0*mu*mu2 + a1*mu2 + a2*mu + a3;
	}
	else{
		a0 = fWindowedWF[fAbsoluteZeroCrossing - 3] - fWindowedWF[fAbsoluteZeroCrossing - 2] - fWindowedWF[fAbsoluteZeroCrossing] + fWindowedWF[fAbsoluteZeroCrossing - 1];
		a1 = fWindowedWF[fAbsoluteZeroCrossing] - fWindowedWF[fAbsoluteZeroCrossing - 1] - a0;
		a2 = fWindowedWF[fAbsoluteZeroCrossing - 2] - fWindowedWF[fAbsoluteZeroCrossing];
		a3 = fWindowedWF[fAbsoluteZeroCrossing - 1]

		fCubicSpline = a0*mu*mu2 + a1*mu2 + a2*mu + a3;
	}
}

void MGWFSOMWindowAlign::WindowVariance(){
	
	fWFVar = 0;
	double mean = 0;
	double sum = 0;
	double temp = 0;

	for(int i = 0; i < fWindowedWF.size(); i++){
		sum += fWindowedWF[i];
	}

	mean = (sum/fWindowedWF.size());
	
	for(size_t i = 0; i < fWindowedWF.size(); i++){
		temp += (fWindowedWF[i] - mean) * (fWindowedWF[i] - mean);
	}

	fWFVar = (temp/fWindowedWF.size());

	// Now scale by the variance...
}

void MGWFSOMWindowAlign::setMU(double muValue){
	mu = muValue;
}
