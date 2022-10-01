#pragma once
#include "Renderer.h"
class GSEGame
{

	Renderer* m_Renderer = NULL;

public:
	GSEGame(int x, int y);
	virtual ~GSEGame();
	
	void RenderScene();

};

