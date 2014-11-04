#ifndef __ZEDTEMPLATE_MAINMENUSTATE_HPP__
#define __ZEDTEMPLATE_MAINMENUSTATE_HPP__

#include <System/DataTypes.hpp>
#include <Game/GameState.hpp>

namespace ZEDTemplate
{
	class MainMenuState : public ZED::Game::GameState
	{
	public:
		MainMenuState( );
		virtual ~MainMenuState( );

		virtual ZED_UINT32 Enter( );
		virtual void Update( const ZED_UINT64 p_DeltaTime );
		virtual void Render( );
		virtual ZED_UINT32 Exit( );

		virtual ZED_CHAR8 *GetName( ) const;
	private:
	};
}


#endif // __ZEDTEMPLATE_MAINMENUSTATE_HPP__

