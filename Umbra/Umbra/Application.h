#pragma once

class Screen;

class Application
{
public:
	static Screen* GetScreen();

public:
	Application();
	~Application();

public:
	int Run();

private:
	static Screen* m_screen;

};

