// OpenGloveAPICPPFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "OpenGloveAPI.h"

int main()
{	
	OpenGloveAPI api;

	ns4__ArrayOfGlove response = api.getGloves();

	for (auto glove = response.Glove.begin();
		glove != response.Glove.end();
		glove++)
	{
		std::cout << "Guante: " << *((*(*glove._Ptr)).Name) << std::endl;
		api.activate((*(*glove._Ptr)), PalmarFingerIndexDistal, 250);
	}


	for (auto glove = response.Glove.begin();
		glove != response.Glove.end();
		glove++)
	{
		api.activate((*(*glove._Ptr)), PalmarFingerIndexDistal, 0);
	}

    return 0;
}

