#include "stdafx.h"
#include "GSEGame.h"

GSEGame::GSEGame(int x, int y)
{
	// Initialize Renderer
	m_Renderer = new Renderer(x, y);
	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
}

GSEGame::~GSEGame()
{
}

void GSEGame::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	m_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);
}
