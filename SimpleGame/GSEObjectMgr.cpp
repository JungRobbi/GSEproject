#include "stdafx.h"
#include "GSEObjectMgr.h"

GSEObjectMgr::GSEObjectMgr()
{
	//init object list
	for (int i{}; i < MAX_OBJECT_COUNT; ++i) {
		m_objects[i] = NULL;
	}
}

GSEObjectMgr::~GSEObjectMgr()
{
	for (int i{}; i < MAX_OBJECT_COUNT; ++i) {
		DeleteObject(i);
	}
}

bool GSEObjectMgr::AddObject(GSEVec3 pos, GSEVec3 size)
{
	//find empty slot
	int index{ FindEmptySlot() };

	if (index < 0)
		return false;

	m_objects[index] = new GSEObject(pos, size);
	return true;
}

GSEObject* GSEObjectMgr::GetObject(int index)
{
	if (!m_objects[index])
		return m_objects[index];
	return NULL;
}

bool GSEObjectMgr::DeleteObject(int index)
{
	if (m_objects[index]) {
		delete m_objects[index];
		m_objects[index] = NULL;
		return true;
	}
	return false;
}

int GSEObjectMgr::FindEmptySlot()
{
	for (int i{}; i < MAX_OBJECT_COUNT; ++i) {
		if (!m_objects[i]) 
			return i;
	}

	//Fail to find empty slot
	return -1;
}
