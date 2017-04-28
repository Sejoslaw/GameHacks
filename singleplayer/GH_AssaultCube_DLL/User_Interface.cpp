#include "User_Interface.h"

using namespace ACubeDLL;

int UIMain()
{
	//THIS CODE is required to start our User interface
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create the main window and run it
	User_Interface^ NewUi = gcnew User_Interface();
    Application::Run(NewUi); //Run our New user interface (linking to "User_Interface.h")
	return 1;
}

