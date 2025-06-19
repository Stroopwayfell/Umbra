#include "Level.h"

#include "Umbra/Actors/ActorWorld.h"

string Level::Name() const
{
	return m_name;
}

ActorWorld const* Level::World() const
{
	return m_world;
}

Level::Level(string name)
	:m_world{ new ActorWorld }, m_name{ std::move(name) }
{
}

Level::~Level()
{
	delete m_world;
	m_world = nullptr;
}

void Level::OnLoaded()
{
}

void Level::OnUnloaded()
{
}

void Level::Tick(float dt)
{
}

void Level::Render()
{
}
