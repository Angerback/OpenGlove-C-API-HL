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
	}

    return 0;
}

