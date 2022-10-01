#include "stdafx.h"
#include "GSEGame.h"
#include "GSEObject.h"

GSEGame::GSEGame(GSEVec2 size)
{
	// Initialize Renderer
	m_Renderer = new Renderer((int)size.x, (int)size.y);
	m_objectMgr = new GSEObjectMgr();
	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	//test
	GSEVec3 pos = { 0, 0, 0 };
	GSEVec3 tsize = { 10, 10, 10 };
	m_objectMgr->AddObject(pos, tsize);
}

GSEGame::~GSEGame()
{
	if(m_Renderer)
		delete m_Renderer;
	if(m_objectMgr)
		delete m_objectMgr;
}

void GSEGame::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	GSEObject* temp = m_objectMgr->GetObject(0);
	m_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);
}
