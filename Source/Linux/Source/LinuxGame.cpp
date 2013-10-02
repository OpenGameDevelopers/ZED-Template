#include <Game.hpp>
#include <System/LinuxWindow.hpp>
#include <Renderer/LinuxRendererOGL3.hpp>
#include <System/LinuxInputManager.hpp>

namespace ZEDTemplate
{
	ZED_UINT32 Game::Initialise( )
	{
		m_pWindow = new ZED::System::LinuxWindow( );

		if( !m_pWindow )
		{
			zedTrace( "[ZEDTemplate::Game::Initialise] <ERROR> "
				"Failed to create a new window\n" );
				
			return ZED_FAIL;
		}

		m_pRenderer = new ZED::Renderer::LinuxRendererOGL3( );

		if( !m_pRenderer )
		{
			zedTrace( "[ZEDTemplate::Game::Initialise] <ERROR> "
				"Faield to create a new renderer\n" );
			return ZED_FAIL;
		}

		ZED_UINT32 X = 0, Y = 0, Width = 1280, Height = 720;
		ZED_UINT32 WindowStyle = ZED_WINDOW_STYLE_MINIMISE |
			ZED_WINDOW_STYLE_CLOSE | ZED_WINDOW_STYLE_TITLEBAR |
			ZED_WINDOW_STYLE_MOVE;

		m_pWindow->Create( X, Y, Width, Height, 0, 0, WindowStyle );

		m_Canvas.Width( Width );
		m_Canvas.Height( Height );
		m_Canvas.BackBufferCount( 1 );
		m_Canvas.ColourFormat( ZED_FORMAT_ARGB8 );
		m_Canvas.DepthStencilFormat( ZED_FORMAT_D24S8 );

		m_pRenderer->Create( m_Canvas, ( *m_pWindow ) );

		m_pRenderer->ClearColour( 1.0f, 0.0f, 0.0f );
		m_pRenderer->SetRenderState( ZED_RENDERSTATE_CULLMODE,
			ZED_CULLMODE_NONE );
		m_pRenderer->SetRenderState( ZED_RENDERSTATE_DEPTH, ZED_ENABLE );
		m_pRenderer->SetClippingPlanes( 1.0f, 100000.0f );
		m_pRenderer->PerspectiveProjectionMatrix( 45.0f,
			static_cast< ZED_FLOAT32 >( Width ) /
			static_cast< ZED_FLOAT32 >( Height ) );

		ZED::System::ZED_WINDOWDATA WindowData = m_pWindow->WindowData( );

		m_pInputManager =
			new ZED::System::LinuxInputManager( WindowData.pX11Display );

		m_pInputManager->AddDevice( &m_Keyboard );

		return ZED_OK;
	}
}

