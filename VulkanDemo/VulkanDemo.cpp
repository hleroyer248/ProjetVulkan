#include <iostream>
#include "Application.h"

int main()
{
    Application app;

    try
    {
        app.Init();
        app.Run();
        app.Destroy();
    }
    catch (std::exception e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
