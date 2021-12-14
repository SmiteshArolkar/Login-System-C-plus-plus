#include "LoginSys.h"

LoginSystem::LoginSystem()
{
	int choice;
	do {
		std::cout << "1:Register\t 2:Login" << std::endl;
		cin >> choice;
		switch (choice)
		{
		case 1://Register
			getUsername();
			if(IsUserNameValid())
			{ 
				getPassword();

				CreatRegisterFile();
			}
			else
			{
				cout << "Username Already Taken" << endl;
			}
			
			
			Cleaup();

			break;
		case 2://login
			if (VerifyUser())
			{
				cout << "Login Successful" << endl;
			}
			else
			{
				cout << "Username Or Password Incorrect" << endl;
			}
			Cleaup();
			break;
		}

	} while (choice);
}

void LoginSystem::getUsername()
{
	cout << "Username : " <<endl;
	cin >> m_Username;
	cout << endl;
}

void LoginSystem::getPassword()
{
	cout << "Password : " << endl;
	cin >> m_Password;
	cout << endl;
}

void LoginSystem::CreatRegisterFile()
{
	string writeToFile = m_Username + "_" + m_Password + "\n";
	ofstream myFile("Data\\" + m_Username + ".txt");
	myFile << m_Password;
	myFile.close();
}

void LoginSystem::Cleaup()
{
	m_Username = "";
	m_Password = "";
}

int LoginSystem::VerifyUser()
{
	string u_password;
	getUsername();
	getPassword();
	fstream myFile("Data//" + m_Username + ".txt");
	if (myFile.good())
	{
		while (getline(myFile,u_password))
		{
			if (u_password == m_Password)
			{
				return 1;
				break;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	
}

bool LoginSystem::IsUserNameValid()
{
	ifstream myFile("Data\\" + m_Username + ".txt");
	if (myFile.good())
	{
		myFile.close();
		return false;
	}
	else
		return true;
}
