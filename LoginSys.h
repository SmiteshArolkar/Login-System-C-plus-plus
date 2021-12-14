#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LoginSystem
{
public:LoginSystem();

private:
	string m_Username, m_Password;
	void getUsername();
	void getPassword();
	void CreatRegisterFile();
	void Cleaup();
	int VerifyUser();
	bool IsUserNameValid();
};