#pragma once

#include "soapBasicHttpBinding_USCOREIOGServiceProxy.h"
#include "BasicHttpBinding_USCOREIOGService.nsmap"
#include "stdsoap2.h"

class OpenGloveAPI {
private:
	BasicHttpBinding_USCOREIOGServiceProxy MyProxy;

public:
	ns4__ArrayOfGlove getGloves() {
		/* Uncomment two following strings and modify path to the
		service according to your network configuration */
		// static const char* const pszEndPoint=”http://localhost:8080/MyService/”;
		// MyProxy.soap_endpoint=pszEndPoint;
		MyProxy.soap_endpoint = "http://localhost:8733/Design_Time_Addresses/OpenGloveWCF/OGService/";
		_ns1__GetGlovesResponse Response;
		_ns1__GetGloves Param;

		if (MyProxy.GetGloves(&Param, Response) == SOAP_OK) {
			return  (*Response.GetGlovesResult);
		}

	}
};
