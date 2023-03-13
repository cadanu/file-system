// file-system-controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FileController.h"

int main()
{
	FileController* fc = &FileController::Instance();
	cout << fc->GetCurrDir() << endl;

	int fs = fc->GetFileSize("FileController.cpp");
	unsigned char* buffer = new unsigned char[fs];
	fc->ReadFileAsync("FileController.cpp", buffer, fs);

	while(!fc->GetFileReadDone())
	{
		cout << "Thread running..." << endl;
	}
	if (fc->GetFileReadSuccess())
	{
		cout << "File size: " << fs << endl;
	}
	else
	{
		cout << "File read operation unsuccessful." << endl;
	}

	delete[] buffer;

}

