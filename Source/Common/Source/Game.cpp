#include <Game.hpp>
#include <cstring>
#include <System/Memory.hpp>

namespace ZEDTemplate
{
	Game::Game( )
	{
		m_pWindow = ZED_NULL;
		m_pRenderer = ZED_NULL;
		m_pInputManager = ZED_NULL;

		memset( &m_Canvas, 0, sizeof( m_Canvas ) );
	}

	Game::~Game( )
	{
		zedSafeDelete( m_pInputManager );
		zedSafeDelete( m_pRenderer );
		zedSafeDelete( m_pWindow );
	}

	ZED_UINT32 Game::Initialise( )
	{
		return ZED_OK;
	}

	ZED_UINT32 Game::Execute( )
	{
		return ZED_OK;
	}

	void Game::Update( const ZED_UINT64 p_MicroSeconds )
	{
	}

	void Game::Render( )
	{
	}
}
