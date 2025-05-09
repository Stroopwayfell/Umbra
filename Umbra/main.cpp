#include <iostream>

#include <Umbra/Application.h>

#if _DEBUG
	#define #_CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// main that returns an integer
int main()
{
#if _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif


    Application* app = new Application();

    int returnState = app->Run();

    delete app;

    return returnState;

    return EXIT_SUCCESS;
}