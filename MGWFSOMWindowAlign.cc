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
}

void MGWFSOMWindowAlign::FindZeroCrossing(){

	int indexNeg = fWindowedWF.size()/2;
	int indexPos = indexNeg;

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
	//Interpolate the absolute zero crossing using linear interpolation
	// Use a cubic splice interpolation
	fWindowedWF->InterpolateAtPoint(fWFVar);
}

void MGWFSOMWindowAlign::WindowVariance(){
	
	double variance = 0;
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

	variance = (temp/fWindowedWF.size());

	// Now scale by the variance...
}
