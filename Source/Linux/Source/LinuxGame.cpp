#include <Game.hpp>
#include <System/LinuxWindow.hpp>
#include <System/LinuxWindowData.hpp>
#include <System/LinuxInputManager.hpp>
#include <Renderer/RendererFactory.hpp>

namespace ZEDTemplate
{
	ZED_UINT32 Game::PreInitialise( )
	{
		m_pWindow = new ZED::System::LinuxWindow( );

		if( !m_pWindow )
		{
			zedTrace( "[ZED Template::Game::PreInitialise] <ERROR> "
				"Failed to create a new window\n" );
				
			return ZED_FAIL;
		}

		m_pWindowData = new ZED::System::LinuxWindowData( );

		if( !m_pWindowData )
		{
			zedTrace( "[ZED Template::Game::PreInitialise] <ERROR> "
				"Failed to instantiate window data\n" );

			return ZED_FAIL;
		}

		if( ZED::Renderer::CreateRenderer( "OpenGL 3", &m_pRenderer ) !=
			ZED_OK )
		{
			zedTrace( "[ZED Template::Game::PreInitialise] <ERROR> "
				"Failed to create the renderer\n" );

			return ZED_FAIL;
		}

		if( !m_pRenderer )
		{
			zedTrace( "[ZED Template::Game::PreInitialise] <ERROR> "
				"Failed to create a new renderer\n" );

			return ZED_FAIL;
		}

		m_pInputManager = new ZED::System::LinuxInputManager( );

		if( !m_pInputManager )
		{
			zedTrace( "[ZED Template::Game::PreInitialise] <ERROR> "
				"Failed to create new input manager\n" );

			return ZED_FAIL;
		}

		return ZED_OK;
	}
}

