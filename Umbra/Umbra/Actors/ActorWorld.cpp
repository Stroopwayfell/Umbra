#include "ActorWorld.h"

#include "Actor.h"
#include "ActorTransform.h"

void ActorWorld::Spawn(Actor* actor)
{
	if (std::ranges::find(m_actors, actor) != m_actors.end())
	{
		return;
	}

	m_listChanges.emplace_back([this](Actor* spawned)
		{
			spawned->BeginPlay();
			m_actors.emplace_back(spawned);
		}, actor);
}

void ActorWorld::Destroy(Actor* actor)
{
	if (std::ranges::find(m_actors, actor) == m_actors.end())
	{
		return;
	}

	m_listChanges.emplace_back([this](Actor* spawned)
		{
			spawned->EndPlay();
			m_actors.erase(std::ranges::find(m_actors, spawned));
			delete spawned;
		}, actor);
}

ActorWorld::ActorWorld() = default;

ActorWorld::~ActorWorld()
{
	for (auto& [fnc, actor] : m_listChanges)
	{
		fnc(actor);
	}

	for (Actor* actor : m_actors)
	{
		delete actor;
	}

	m_actors.clear();

	m_listChanges.clear();
	
}

void ActorWorld::Tick(float dt)
{
	for (auto& [fnc, actor] : m_listChanges)
	{
		fnc(actor);
	}

	m_listChanges.clear();

	for (Actor* actor : m_actors)
	{
		actor->Tick(dt);
		actor->Transform()->Update();
	}
}

void ActorWorld::Render() const
{
	for (Actor* actor : m_actors)
	{
		actor->Render();
	}
}
