#pragma once

#include <functional>
#include <vector>

using std::function;
using std::pair;
using std::vector;

class Actor;

class ActorWorld
{
	friend class Level;

public:
	void Spawn(Actor* actor);
	void Destroy(Actor* actor);

private:
	vector<Actor*> m_actors;
	vector<pair<function<void(Actor*)>, Actor*>> m_listChanges;

protected:
	ActorWorld();
	~ActorWorld();

private:
	void Tick(float dt);
	void Render() const;

};

