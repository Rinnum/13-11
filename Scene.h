#pragma once

class Scene
{
public:
	inline Scene() {}
	inline virtual void update(float deltaTime){}
	inline virtual void render(){}
};

extern int sceneIndex;
