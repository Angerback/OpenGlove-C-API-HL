#pragma once

#include "soapBasicHttpBinding_USCOREIOGServiceProxy.h"
#include "BasicHttpBinding_USCOREIOGService.nsmap"
#include "stdsoap2.h"

class OpenGloveAPI {
private:
	BasicHttpBinding_USCOREIOGServiceProxy MyProxy;

public:
	ns4__ArrayOfGlove getGloves() {

		MyProxy.soap_endpoint = "http://localhost:8733/Design_Time_Addresses/OpenGloveWCF/OGService/";
		_ns1__GetGlovesResponse Response;
		_ns1__GetGloves Param;

		if (MyProxy.GetGloves(&Param, Response) == SOAP_OK) {
			return  (*Response.GetGlovesResult);
		}

	}

	void activate(ns4__Glove glove, int region, int intensity) {
		MyProxy.soap_endpoint = "http://localhost:8733/Design_Time_Addresses/OpenGloveWCF/OGService/";
		_ns1__ActivateResponse Response;
		_ns1__Activate Param;

		Param.gloveAddress = glove.BluetoothAddress;
		Param.intensity = &intensity;

		auto config = *(glove.GloveConfiguration);

		auto profile = *(config.GloveProfile);

		int actuator = -1;

		for (auto mapping = (*(*(profile.Mappings)).KeyValueOfstringstring).begin();
			mapping != (*(*(profile.Mappings)).KeyValueOfstringstring).end();
			mapping++)
		{
			if ((*((*(mapping._Ptr)).Key)).compare(std::to_string(region)) == 0)
			{
				actuator = std::stoi((*((*(mapping._Ptr)).Value)));
				break;
			}
		}

		if (actuator == -1) {
			return;
		}

		Param.actuator = &actuator;

		if (MyProxy.Activate(&Param, Response) == SOAP_OK)
		{

		}
	}
};

enum HandRegion {
	PalmarFingerSmallDistal,
	PalmarFingerRingDistal,
	PalmarFingerMiddleDistal,
	PalmarFingerIndexDistal,
	PalmarFingerSmallMiddle,
	PalmarFingerRingMiddle,
	PalmarFingerMiddleMiddle,
	PalmarFingerIndexMiddle,
	PalmarFingerSmallProximal,
	PalmarFingerRingProximal,
	PalmarFingerMiddleProximal,
	PalmarFingerIndexProximal,
	PalmarPalmSmallDistal,
	PalmarPalmRingDistal,
	PalmarPalmMiddleDistal,
	PalmarPalmIndexDistal,
	PalmarPalmSmallProximal,
	PalmarPalmRingProximal,
	PalmarPalmMiddleProximal,
	PalmarPalmIndexProximal,
	PalmarHypoThenarSmall,
	PalmarHypoThenarRing,
	PalmarThenarMiddle,
	PalmarThenarIndex,
	PalmarFingerThumbProximal,
	PalmarFingerThumbDistal,
	PalmarHypoThenarDistal,
	PalmarThenar,
	PalmarHypoThenarProximal,
	DorsalFingerSmallDistal,
	DorsalFingerRingDistal,
	DorsalFingerMiddleDistal,
	DorsalFingerIndexDistal,
	DorsalFingerSmallMiddle,
	DorsalFingerRingMiddle,
	DorsalFingerMiddleMiddle,
	DorsalFingerIndexMiddle,
	DorsalFingerSmallProximal,
	DorsalFingerRingProximal,
	DorsalFingerMiddleProximal,
	DorsalFingerIndexProximal,
	DorsalPalmSmallDistal,
	DorsalPalmRingDistal,
	DorsalPalmMiddleDistal,
	DorsalPalmIndexDistal,
	DorsalPalmSmallProximal,
	DorsalPalmRingProximal,
	DorsalPalmMiddleProximal,
	DorsalPalmIndexProximal,
	DorsalHypoThenarSmall,
	DorsalHypoThenarRing,
	DorsalThenarMiddle,
	DorsalThenarIndex,
	DorsalFingerThumbProximal,
	DorsalFingerThumbDistal,
	DorsalHypoThenarDistal,
	DorsalThenar,
	DorsalHypoThenarProximal
};