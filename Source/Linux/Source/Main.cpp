#include <iostream>
#include <Game.hpp>

int main( int p_Argc, char **p_ppArgv )
{
	std::cout << "ZED Template" << std::endl;

	ZEDTemplate::Game TheGame;

	if( TheGame.Initialise( ) != ZED_OK )
	{
		std::cout << "[ZED Template::main] <ERROR> Failed to initialise the "
			"game" << std::endl;

		return ZED_FAIL;
	}

	return TheGame.Execute( );
}

