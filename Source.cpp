#include<iostream>
#include<conio.h>
#include<string>
#include<cstring>
#include<fstream>
#include"faculty.h"
#include"login.h"
#include"room.h"
#include <ctime>


using namespace std;


int main()
{
    srand(time(NULL));
	int choice;

	do
	{
		cout << "Choose from one of the following(1-3)\n1-\tDoctor\n2-\tAdmin\n3-\tPatient" << endl;
		cout << "Choice: ";
		cin >> choice;
		string user, pass;
		char* user11;
		char* pass11;
		switch (choice)
		{
		case 1:	//doctor
		{
			int c;
			do
			{
				cout << "1) Sign up" << endl;
				cout << "2) Login" << endl;
				cout << "3) exit" << endl;
				cout << "Choice: ";
				cin >> c;
				Login user1, user2;
				switch (c)
				{
				case 1:	
				{
					//sign up
					Doctor d1;
					cin.ignore();
					d1.setDetail();
					cout << "Password: " << endl;
					int ppass;
					cin >> ppass;
					char temp[50];
					std::strcpy(temp, d1.getName().c_str());
					user1.setUsername(temp);
					user1.setUserpassword(ppass);
					fstream file;
					file.open("doclogin.dat", ios::out | ios::binary | ios::app);
					file.write((char*)&user1, sizeof(Login));
					file.close();
					fstream file2;
					file2.open("docData.dat", ios::out | ios::binary | ios::app);
					file2.write((char*)&d1, sizeof(Doctor));
					file2.close();

					break;
				}
				case 2:
				{
					//login
					Doctor d2;
					char nname[25];
					int ppass;
					cout << "Login page\nName: ";
					cin.ignore();
					cin.getline(nname, 25);
					cout << "Password: ";
					cin >> ppass;
					cout << "Employee ID: ";
					int empID;
					cin >> empID;
					user1.setUsername(nname);
					user1.setUserpassword(ppass);
					fstream file;
					file.open("doclogin.dat", ios::in | ios::binary | ios::app);
					bool check = true;
					while (file.read((char*)&user2, sizeof(Login)))
					{
						if (user2.getUsername() == nname && user2.getUserpassword() == ppass)
						{
							cout << "Login successful" << endl;
							fstream file2;
							file2.open("docData.dat", ios::in | ios::binary | ios::app);
							while (file2.read((char*)&d2, sizeof(Doctor)))
							{
								cout << d2.getName() << endl;
								cout << d2.getEmpID() << endl;
								if (d2.getName() == nname && d2.getEmpID() == empID)
								{
									int choice2;
									do
									{
										cout << "Doctor's Portal" << endl;
										cout << "1) Show Personal Information" << endl;
										cout << "2) Show Appointment Info" << endl;
										cout << "3) exit" << endl;
										cin >> choice2;
										switch (choice2)
										{
										case 1:
										{
											d2.printEmpinfo();
											break;
										}
										case 2:
										{
											d2.printAppInfo();
											break;
										}
										}
									} while (choice2 < 3 && choice2>0);
								}
							}
							file2.close();
							check = false;
						}
					}
					if (check)
						cout << "Login unsuccessful" << endl;
					file.close();
					break;
				}
				}
			} while (c < 3 && c>0);


			break;
		}
		case 2:	//admin
		{
			int c = 0;
			cout << "1) Login" << endl;
			cout << "2) exit" << endl;
			cout << "Choice: ";
			cin >> c;
			Login user1, user2;
			switch (c) {
				case 1:	//login
					//login
					Admin A;
					char nname[25];
					int ppass;
					cout << "Login page\nName: ";
					cin.ignore();
					cin.getline(nname, 25);
					cout << "Password: ";
					cin >> ppass;
					cout << "Employee ID: ";
					int empID;
					cin >> empID;
					user1.setUsername(nname);
					user1.setUserpassword(ppass);
					fstream file;
					file.open("Adminlogin.dat", ios::in | ios::binary | ios::app);
					bool check = true;
					while (file.read((char*)&user2, sizeof(Login)))
					{
						cout << user2.getUsername() << " " << user2.getUserpassword() << endl;
						if (user2.getUsername() == nname && user2.getUserpassword() == ppass)
						{
							cout << "Login successful" << endl;
							fstream file2;
							//file2.open("AdminData.dat", ios::in | ios::binary | ios::app);
							int choice2;
							do
							{
								cout << "Admin's Portal" << endl;
								cout << "1) Admit Patient" << endl;
								cout << "2) List all Doctors" << endl;
								cout << "3) Add new bed" << endl;
								cout << "4) List all beds" << endl;
								cout << "5) exit" << endl;
								cin >> choice2;
								Patient p2;
								Room r2;
								switch (choice2)
								{
									case 1:	//admit
									{
										int id, room;
										cout << "Enter Patient id" << endl;
										cin >> id;
										///file reading
										file2.open("patientData.dat", ios::in | ios::binary | ios::app);
										while (file2.read((char*)&p2, sizeof(Patient)))
										{
											if (p2.getPatID() == id)
											{
												break;
											}
										}
										file2.close();
										cout << "Enter Room number" << endl;
										cin >> room;
										file2.open("Rooms.dat", ios::in | ios::binary);
										while (file2.read((char*)&r2, sizeof(Room)))
										{
											if (r2.getNum() == room)
											{
												break;
												
											}
										}
										file2.close();

										//both objects created
										r2.addPatient(p2);	//patient admitted
										file2.open("Rooms.dat", ios::out | ios::binary | ios::app);
										file2.write((char*)&r2, sizeof(Room));
										file2.close();
										//cout << "@@@@@@@@" << endl;
										break;
									}
									case 2:
									{
										fstream f;
										Doctor doc;
										f.open("docData.dat", ios::in | ios::binary | ios::app);
										while (f.read((char*)&doc, sizeof(Doctor)))
										{
											doc.printEmpinfo();
											cout << endl;
										}
										f.close();
										break;
									}
									case 3:
									{
										Room R;
										cin.ignore();
										R.setDetail();
										file2.open("Rooms.dat", ios::out | ios::binary | ios::app);
										file2.write((char*)&R, sizeof(Room));
										file2.close();
										break;
									}
									case 4:
										fstream f;
										Room R;
										f.open("Rooms.dat", ios::in | ios::binary | ios::app);
										while (f.read((char*)&R, sizeof(Room)))
										{
											cout<<"Room number: "<<R.getNum();
											cout << "Room Floor: " << R.getFloor();
											//cout << "Room vacancy: " << R.checkVacancy();
											cout << endl;
										}
										f.close();
										break;
								}// while (choice2 < 3 && choice2>0);
							} while (choice2 != 5);
						}
						if (check) {
							cout << "Login unsuccessful" << endl;
						}
						file.close();
						break;	
					}
				break;	//case break

			}
			break;	//case break;
		}
		case 3:
		{
			int c;
			do
			{
				cout << "1) Sign up" << endl;
				cout << "2) Login" << endl;
				cout << "3) exit" << endl;
				cout << "Choice: ";
				cin >> c;
				Login user3, user4;
				switch (c)
				{
				case 1:
				{
					//sign up
					Patient p1;
					cin.ignore();
					p1.setDetail();
					cout << "Password: " << endl;
					int ppass;
					cin >> ppass;
					char temp[50];
					strcpy(temp, p1.getPatientname().c_str());
					user3.setUsername(temp);
					user3.setUserpassword(ppass);
					fstream file;
					file.open("patientlogin.dat", ios::out | ios::binary | ios::app);
					file.write((char*)&user3, sizeof(Login));
					file.close();
					fstream file2;
					file.open("patientData.dat", ios::out | ios::binary |ios::app);
					file.write((char*)&p1, sizeof(Patient));
					file.close();

					break;
				}
				case 2:
				{
					//login
					Patient p2;
					char nname[25];
					int ppass;
					cout << "Login page\nName: ";
					cin.ignore();
					cin.getline(nname, 25);
					cout << "Password: ";
					cin >> ppass;
					cout << "Patient ID: ";
					int pID;
					cin >> pID;
					user3.setUsername(nname);
					user3.setUserpassword(ppass);
					fstream file;
					file.open("patientlogin.dat", ios::in | ios::binary | ios::app);
					bool check = true;
					while (file.read((char*)&user4, sizeof(Login)))
					{
						
						
						if (user4.getUsername() == nname && user4.getUserpassword() == ppass)
						{
							cout << "Login successful" << endl;
							fstream file2;
							file2.open("patientData.dat", ios::in | ios::binary | ios::app);
							while (file2.read((char*)&p2, sizeof(Patient)))
							{
								
								if (p2.getPatientname() == nname && p2.getPatID() == pID)
								{
									int choice2;
									do
									{
										cout << "Patient's Portal" << endl;
										cout << "1) Show Personal Information" << endl;
										cout << "2) Set Appointment" << endl;
										cout << "3) exit" << endl;
										cout << "Choice: ";
										cin >> choice2;

										if (choice2 == 3) {
											break;
										}

										cout << choice2 << endl;
										switch (choice2)
										{
											case 1:
											{
												p2.printPatdetail();
												break;
											}
											case 2:
											{
												Doctor doc;
												cout << "Enter the Employee ID from one of the following doctors" << endl;
												fstream f;
												f.open("docData.dat", ios::in | ios::binary | ios::app);
												while (f.read((char*)&doc, sizeof(Doctor)))
												{
													doc.printEmpinfo();
													cout << endl;
												}
												f.close();
												cout << "Doctor's ID: ";
												int appoint;
												cin >> appoint;
												Appointment a1;
												a1.setDetail();
												Doctor d_arr[50];
												int index = 0;
												f.open("docData.dat", ios::in | ios::binary | ios::app);
												while (f.read((char*)&d_arr[index], sizeof(Doctor)))
												{
													if (d_arr[index].getEmpID() == appoint) {
														d_arr[index].addAppointment(a1);
													}
													index++;
												}
												f.close();
												index--;
												f.open("docData.dat", ios::out | ios::binary);
												while (index >= 0) {
													//cout  << "here" << endl;
//													d_arr[index].printAppInfo();
													f.write((char*)&d_arr[index], sizeof(Doctor));
													index--;
												}
												cout << "Appointment booked successful" << endl;
												f.close();
												break;
											}
											case 3:
											{
												break;
											}

										}

									} while (choice2 < 3 || choice2>0);
									
//									break;
								}
							}
							file.close();
							check = false;
							
//							break;
						}
					}

					if (check)
						cout << "Login unsuccessful" << endl;
					file.close();
					break;
				}
				case 3: {
					break;
				}

				}
			} while (c < 3 && c>0);

		}
//		default:
//			break;
		}
	}while (choice <= 3 && choice>0);
	return 0;
}