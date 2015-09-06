#include "dbMonkey.h"

using System::String;
using System::Windows::Forms::Application;

[System::STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew dbMonkey::dbMonkey());
	return 0;
}
