
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime> 

using namespace std;

class Boardgames
{
private:
	static int iteratorId;
	int boardgameId;
	string name;
	int quantity;
	float price;

public:

	Boardgames(string N = "", int Q = 0, float P = 0)
	{  
		this->name = N;
		this->quantity = Q;
		this->price = P;
		this->boardgameId = iteratorId;
		this->iteratorId ++ ;

	}

	~Boardgames()
	{

	}

	int getIdBoardgame()
	{
		return this->boardgameId;
	}


	void setName(string N)
	{
		this->name = N;
    }
	string getName()
	{
		return this->name;
	}


    void setQuantity(int Q)
	{
		this->quantity = Q;
	}
	int getQuantity()
	{
		return this->quantity;
	}


	void setPrice(float P)
	{
		this->price = P;
	}
	float getPrice()
	{
		return this->price;
	}

	friend ostream& operator<<(ostream& os, const Boardgames& B);
	friend istream& operator>> (istream& is, Boardgames& B);

	Boardgames operator+(const Boardgames& B)
	{
		this->quantity = this->quantity + B.quantity;
		return *this;

	}

	Boardgames operator += (int Q)
	{
		
		this->quantity += Q;
		return *this;
	}

	Boardgames operator -= ( int Q)
	{
		
		this->quantity -= Q;
		return *this;
	}

};
int Boardgames::iteratorId = 1;

ostream& operator << (ostream& os, const Boardgames& B)
{
	os << endl;
	os << "Id boardgame: " << B.boardgameId << endl;
	os << "Nume boardgame : " << B.name << endl;
	os << "Cantitatea din stoc: " << B.quantity << endl;
	os << "Pret: " << B.price << endl;

	return os;

}

istream& operator >> (istream& is, Boardgames& B)
{   
	fflush(stdin);
	cout << "Introduceti numele boardgameului: " << endl;
	getline(is ,B.name);
	cout << "Introduceti cantitatea in care a fost achizitionat: " << endl;
	is >> B.quantity;
	cout << "Introduceti pretul unitar: " << endl;
	is >> B.price;

	return is;
}



class Client
{
private:
	static int iteratorId;
	int clientId;
	string clientSurename;
	string clientGivenName;
	string email;
public:
	
	Client(string CS = "", string CG = "", string E = "")
	{
		this->clientSurename = CS;
		this->clientGivenName = CG;
		this->email = E;
		this->clientId = iteratorId;
		this->iteratorId++;
	}

	~Client()
	{

	}

	int getClientId()
	{
		return this->clientId;
	}


	void setClientSurename(string CS)
	{
		this->clientSurename = CS;
	}
    string getClientSurename()
	{
		return this->clientSurename;
	}


	void setClientGivenName(string CG)
	{
		this->clientGivenName = CG;
	}
    string getClientGivenName()
	{
		return this->clientGivenName;
	}


	void setEmail(string E)
	{
		this->email = E;
	}
	string getEmail()
	{
		return this->email;
	}

	friend ostream& operator << (ostream& os, const Client& C);
	friend istream& operator >> (istream& is, Client& C);


	
};

int Client::iteratorId = 1;

ostream& operator << (ostream& os, const Client& C)
{
	os << endl;
	os << "Idul clientului:" << C.clientId << endl;
	os << "Prenumele clientului: " << C.clientSurename << endl;
	os << "Numele  clientului: " << C.clientGivenName << endl;
	os << "Emailul clientului: " << C.email << endl;
	return  os;
}

istream& operator >> (istream& is, Client& C)
{
	cout << "Introduceti prenumele clientului: " << endl;
	is >> C.clientSurename;
	cout << "Introduceti numele clientului: "<< endl;
	is >> C.clientGivenName;
	cout << "Introduceti mailul clientului: " << endl;
	is >> C.email;
	return is;
}



class Sales
{
private:
	int clientId;
	int boardgameId;
	int date[3];
	int quantity;
public:
	Sales(int CI = 0, int BI = 0, int Z=0,int M=0,int Y=0, int  Q = 0)
	{
		this->clientId = CI;
		this->boardgameId = BI;
		this->date[0] = Z;
		this->date[1] = M;
		this->date[2] = Y;
        this->quantity = Q;
	}

	~Sales()
	{

	}

	void setClientId(int CI)
	{
		this->clientId = CI;
	}
    int getClientId()
	{
		return this->clientId;
	}

	void setBoardgameId(int BI)
	{
		this->boardgameId = BI;
	}
    int getBoardgameId()
	{
		return this->boardgameId;
	}

	void setSaleDay(int Z)
	{
		this->date[0] =Z;
	}
	int getSaleDay()
	{
		return this->date[0];
	}

	void setSaleMonth(int M)
	{
		this->date[1] = M;
	}
	int getSaleMonth()
	{
		return this->date[1];
	}


	void setSaleYear(int Y)
	{
		this->date[2] = Y;
	}
	int getSaleYear()
	{
		return this->date[2];
	}

	void setQuantity(int Q)
	{
		this->quantity = Q;
	}
	int getQuantity()
	{
		return this->quantity;
	}

	friend ostream& operator << (ostream& os, const Sales& S);
	friend istream& operator  >> (istream& is, Sales& S);
};

ostream& operator << (ostream& os, const Sales& S)
{   os<<endl;

	os << "Idul clientului: " << S.clientId << endl;
	os << "Idul boardgameului: " << S.boardgameId << endl;
	os << "Data vanzarii: " << S.date[0] << "/" << S.date[1] << "/" << S.date[2] << endl;
	os << "Cantitatea vanduta:" << S.quantity << endl;
	return os;
}

istream& operator >> (istream& is, Sales& S)
{
	cout << "Idul clientului: " << endl;
	is >> S.clientId;
	cout << "Idul boardgameului: " << endl;
	is >> S.boardgameId;
	cout << "Ziua vanzarii :" << endl;
	is >> S.date[0];
	cout << "Luna vanzarii: " << endl;
	is >> S.date[1];
	cout << "Anul vanzarii: " << endl;
	is >> S.date[2];
	cout << "Cantitatea vanduta: " << endl;
	is >> S.quantity;
	return is;
}


int main()
{
	vector<Boardgames> boardgameList;
	vector<Client> clientList;
	vector <Sales> salesList;
	int option=0;

	do
	{
		cout << endl;
		cout << "Alegeti una din optiuni: " << endl<<endl;
		cout << "1.  Adaugare boardgame in inventar " << endl;
		cout << "2.  Adaugare client " << endl;
		cout << "3.  Inregistrare vanzare " << endl;
		cout << "4.  Determinati cel mai fidel client " << endl;
		cout << "5.  Determinati cel mai bine vandut joc " << endl;
		cout << "6.  Salvati cel mai fidel client si cel mai bine vandut joc intr-un fisier  " << endl;
		cout << "7.  Afisati lista jocurilor din inventar  " << endl;
		cout << "8.  Afisati lista clientilor " << endl;
		cout << "9.  Afisati lista vanzarilor " << endl;
		cout << "10. Mariti stocul unui boardgame " << endl;
		cout << "11. Iesire " << endl<<endl;
	
		cin >> option;
		cin.ignore();
		switch(option)
		{	
				case 1:
				{
					Boardgames B1;
					cin >> B1;
					int position;
					int alreadyExists = 0;
					for (unsigned i=0 ;i<boardgameList.size() && alreadyExists == 0 ;i++)
					{
						if (boardgameList[i].getName() == B1.getName())
						{
							alreadyExists = 1;
							position = i;
						}
					}

					if (alreadyExists)
					{
						boardgameList[position] + B1;
					}
					else
						boardgameList.push_back(B1);
				} break;

				case 2:
				{  
					Client C1;
					cin >> C1;
					int alreadyExists = 0;
					for (unsigned i = 0; i < clientList.size() && alreadyExists == 0; i++)
					{
						if (clientList[i].getEmail() == C1.getEmail())
						{
							alreadyExists = 1;
						}

					}

					if (alreadyExists) {
						cout << endl;
						cout << "Clientul deja exista!";
						cout << endl;
					}
					else
						clientList.push_back(C1);
					

				}break;

				case 3:
				{	 Sales S1;
					cin >> S1;
					salesList.push_back(S1);
					for (unsigned i = 0; i < boardgameList.size(); i++)
					{
						if (salesList[salesList.size() - 1].getBoardgameId() == boardgameList[i].getIdBoardgame())
							boardgameList[i] -=  salesList[salesList.size()-1].getQuantity();
				
					}

				}break;

				case 4:
				{if (salesList.empty() == 1)
					cout << "Nu exista vanzari inregistrate! " << endl;
				else
				{

					unsigned frecvency[100] = { 0 };
					for (unsigned i = 0; i < salesList.size(); i++)
					{
						frecvency[salesList[i].getClientId()-1] += salesList[i].getQuantity();

					}

					unsigned max = frecvency[0];
					unsigned position = 0;
					for (unsigned i = 1; i < 100; i++)
					{
						if (frecvency[i] > max)
						{
							max = frecvency[i];
							position = i;
						}

					}

					cout << endl;
					cout << "Cel mai fidel client este: " << position+1 << "." << clientList[position].getClientGivenName() << " " << clientList[position].getClientSurename() << ", mail:  " << clientList[position].getEmail();
				}
				}break;

				case 5:
				{
					{if (boardgameList.empty() == 1)
						cout << "Nu exista boardgameuri inregistrate! " << endl;
					else
						{

							unsigned frecvency[100] = { 0 };
							for (unsigned i = 0; i < salesList.size(); i++)
							{
							frecvency[salesList[i].getBoardgameId() - 1] += salesList[i].getQuantity();

							}

							unsigned max = frecvency[0];
							unsigned position = 0;
							for (unsigned i = 1; i < 100; i++)
							{
							if (frecvency[i] > max)
							{
								max = frecvency[i];
								position = i;
							}

							}

							cout << endl;
							cout << "Cel mai vandut boardgame este: " << position + 1 << ". " << boardgameList[position].getName() << endl;
						}
					}

				}break;

				case 6:
				{ 
					ofstream outfile;
				outfile.open("file.dat", ios::out);



				// current date and time on the current system
				time_t now = time(0);

				// convert now to string form
				char* date_time = ctime(&now);

				outfile << "Cel mai fidel client pana in data de " << date_time << endl;

				if (salesList.empty() == 1)
					outfile << "Nu exista vanzari inregistrate! " << endl;
				else
				{
					unsigned frecvency[100] = { 0 };
					for (unsigned i = 0; i < salesList.size(); i++)
					{
						frecvency[salesList[i].getClientId() - 1] += salesList[i].getQuantity();

					}

					unsigned max = frecvency[0];
					unsigned position = 0;
					for (unsigned i = 1; i < 100; i++)
					{
						if (frecvency[i] > max)
						{
							max = frecvency[i];
							position = i;
						}

					}

					outfile << endl;
					outfile << clientList[position] << endl;

					
				}
				outfile << endl;
				outfile << "Cel mai vandut boardgame pana la data  " << date_time << endl;
				if (boardgameList.empty() == 1)
					outfile << "Nu exista boardgameuri inregistrate! " << endl;
				else
				{

					unsigned frecvency[100] = { 0 };
					for (unsigned i = 0; i < salesList.size(); i++)
					{
						frecvency[salesList[i].getBoardgameId() - 1] += salesList[i].getQuantity();

					}

					unsigned max = frecvency[0];
					unsigned position = 0;
					for (unsigned i = 1; i < 100; i++)
					{
						if (frecvency[i] > max)
						{
							max = frecvency[i];
							position = i;
						}

					}

					outfile << endl;
					outfile << boardgameList[position] << endl;
				}

				outfile.close();
				cout << "Salvarea in fisier s-a incheiat cu succes!" << endl;

				}break;

				case 7:
				{
					for (unsigned i = 0; i < boardgameList.size(); i++)
						cout << boardgameList[i] << endl;

				}break;

				case 8:
				{    for (unsigned i = 0; i < clientList.size(); i++)
					cout << clientList[i] << endl;

				}break;

				case 9:
				{   for (unsigned i = 0; i < salesList.size(); i++)
					cout << salesList[i] << endl;

				}break;

				case 10:
				{	int ID, Q;
					cout << "Introduceti idul boardgameului caruia doriti sa-i mariti stocul:  " << endl;
					cin >> ID;
					cout << "Introduceti cantitatea achizitionata:" << endl;
					cin >> Q;
					for (unsigned i = 0; i < boardgameList.size(); i++)
					{
						if (boardgameList[i].getIdBoardgame() == ID)
							boardgameList[i] += Q;
					}
				}break;


				case 11:
				{
					option = 0;
				}break;
		}

	} while (option != 0);

	return 0;
}