#include <MainMenuState.hpp>
#include <GameStateManager.hpp>
#include <Renderer/Renderer.hpp>
#include <Utility/InputBinder.hpp>
#include <Utility/EventRouter.hpp>

namespace ZEDTemplate
{
	MainMenuState::MainMenuState( )
	{
		m_pInputBinder = new ZED::Utility::InputBinder( );
		m_pEventRouter = new ZED::Utility::EventRouter( "Main Menu", ZED_TRUE,
			2 );
	}

	MainMenuState::~MainMenuState( )
	{
	}

	ZED_UINT32 MainMenuState::Enter( )
	{
		zedTrace( "[ZED Template::MainMenuState::Enter] <INFO> "
			"Entering Main Menu State\n" );

		ZED::Utility::SetGlobalEventRouter( this->m_pEventRouter );
		GameStateManager::GetInstance( ).SetInputBinder( m_pInputBinder );

		GameStateManager::GetInstance( ).GetRenderer( )->ClearColour( 0.2f,
			0.2f, 0.8f );

		return ZED_OK;
	}

	void MainMenuState::Update( const ZED_UINT64 p_DeltaTime )
	{
	}

	void MainMenuState::Render( )
	{
	}

	ZED_UINT32 MainMenuState::Exit( )
	{
		zedTrace( "[ZED Template::MainMenuState::Exit] <INFO> "
			"Exiting Main Menu State\n" );
		GameStateManager::GetInstance( ).Quit( );
		return ZED_OK;
	}

	ZED_CHAR8 *MainMenuState::GetName( ) const
	{
		return "Main Menu";
	}
}

