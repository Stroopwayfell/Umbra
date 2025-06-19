#pragma once

#include <string>

using std::string;

class ActorWorld;

class Level
{
	friend class LevelManager;

public:
	string Name() const;
	ActorWorld const* World() const;

protected:
	explicit Level(string name);
	virtual ~Level();

protected:
	virtual void OnLoaded();
	virtual void OnUnloaded();

	virtual void Tick(float dt);
	virtual void Render();

private:
	ActorWorld* m_world;
	string m_name;

};

