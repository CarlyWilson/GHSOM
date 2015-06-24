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

MGWFSOMWindowAlign::MGWFSOMWindowAlign(MGWaveform waveform){
	fWFData = waveform->GetVectorData();
}

void MGWFSOMWindowAlign::FindZeroCrossing(){

	int indexNeg = fWFData.size()/2;
	int indexPos = indexNeg;

	if(fWFData.size() % 2 == 0){
		indexNeg = indexNeg - 1;
	}

	double trueMiddle = (fWFData[indexNeg] + fWFData[indexPos])/2;

	bool startsPositive = trueMiddle >= 0;
	bool startsNegative = trueMiddle <= 0;

	while((indexPos < fWFData.size()) && (indexNeg >= 0){
		if(startsNegative){
			if(fWFData[indexPos] > 0){
				fAbsoluteZeroCrossing = indexPos;
				return;
			}
		}
		else if(startsPositive){
			if(fWFData[indexPos] < 0){
				fAbsoluteZeroCrossing = indexPos;
				return;
			}
		}
		indexPos++;

		if(startsPositive){
			if(fWFData[indexNeg] < 0){
				fAbsoluteZeroCrossing = indexNeg;
				return;
			}
		}
		else if(startsNegative){
			if(fWFData[indexNeg] > 0){
				fAbsoluteZeroCrossing = indexNeg;
				return;
			}
		}
		indexNeg--;
	}
}

void MGWFSOMWindowAlign::InterpolateandWindow(){
}

void MGWFSOMWindowAlign::WindowVariance(float fWindowedWF){
}
