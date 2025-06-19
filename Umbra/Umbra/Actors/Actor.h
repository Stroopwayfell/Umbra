#pragma once

#include <raylib/raylib.h>

class ActorTransform;

class Actor
{
	friend class ActorWorld;

public:
	Actor();
	Actor(Vector2 location, Vector2 scale, float rotation = 0.f);
	virtual ~Actor();

public:
	ActorTransform* Transform() const;

protected:
	virtual void BeginPlay();

	virtual void Tick(float dt);
	virtual void Render();

	virtual void EndPlay();

private:
	ActorTransform* m_transform;

};

