#include <GameStateManager.hpp>
#include <Game/GameState.hpp>

namespace ZEDTemplate
{
	GameStateManager::GameStateManager( )
	{
	}

	GameStateManager::~GameStateManager( )
	{
	}

	ZED_UINT32 GameStateManager::Initialise( )
	{
		return ZED_OK;
	}

	ZED_UINT32 GameStateManager::Update( const ZED_UINT64 p_DeltaTime )
	{
		m_GameStateStack.top( )->Update( p_DeltaTime );

		return ZED_OK;
	}

	ZED_UINT32 GameStateManager::Render( )
	{
		m_GameStateStack.top( )->Render( );

		return ZED_OK;
	}

	GameStateManager &GameStateManager::GetInstance( )
	{
		static GameStateManager Instance;
		return Instance;
	}
}


