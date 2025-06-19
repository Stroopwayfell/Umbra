#pragma once

#include <raylib/raylib.h>

class ActorTransform
{
	friend class ActorWorld;

public:
	Vector2 location;
	Vector2 scale;
	float rotation;

public:
	ActorTransform();
	ActorTransform(Vector2 location);
	ActorTransform(Vector2 location, Vector2 scale);
	ActorTransform(Vector2 location, Vector2 scale, float rotation);

public:
	Vector2 Forward() const;
	Vector2 Right() const;

private:
	Matrix m_transform;

private:
	void Update();

};

