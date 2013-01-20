
#ifndef I_ENGINE_SERVER_H
#define I_ENGINE_SERVER_H

//
// this is the interface of the engine to the game server
//
class IEngineServer
{
public:
	
};

//
// This is the interface of the game server to the engine
//
class IGameServer
{
public:
	virtual void	Init( IEngineServer *pEngine ) = 0;
	virtual void	Shutdown() = 0;

	virtual void	GameStart() = 0;
	virtual void	GameEnd() = 0;

	// called each frame by the engine
	virtual void	GameFrame() = 0;
};

#endif // I_ENGINE_SERVER_H