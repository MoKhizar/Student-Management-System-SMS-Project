#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
#include<conio.h>
#include<fstream>
#include<algorithm>
#include<cctype>
using namespace std;
const string admin[2][2] = {
	{"umrndem", "umarspass"},
	{"khizar", "khizarspass"}
};
const int NO_OF_SUBJECTS = 16;
string SUBJECTS[NO_OF_SUBJECTS] = {
		"Intro to CS",
		"Mathematics I",
		"Mathematics II",
		"Programming",
		"Data Structures",
		"Discrete Math",
		"OOP",
		"Digital Logic",
		"Computer Architecture",
		"Operating Systems",
		"Database Systems",
		"Software Engineering",
		"Computer Networks",
		"Data Communications",
		"Automata Theory",
		"Algorithm Design"
};
string SUBJECTSWITHCH[NO_OF_SUBJECTS] = {
		"1.Intro to CS",
		"3.Mathematics I",
		"3.Mathematics II",
		"3.Programming",
		"4.Data Structures",
		"3.Discrete Math",
		"4.OOP",
		"4.Digital Logic",
		"3.Computer Architecture",
		"2.Operating Systems",
		"2.Database Systems",
		"2.Software Engineering",
		"3.Computer Networks",
		"1.Data Communications",
		"2.Automata Theory",
		"1.Algorithm Design"
};
string toLowerCase(const string str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
		return tolower(c);
		});
	return result;
}
string capitalizeWords(const string str) {
	string result = str;
	bool capitalizeNext = true;
	for (int i = 0; i < result.length(); i++) {
		if (isspace(result[i])) {
			capitalizeNext = true;
		}
		else if (capitalizeNext) {
			result[i] = toupper(result[i]);
			capitalizeNext = false;
		}
		else {
			result[i] = tolower(result[i]);
		}
	}
	return result;
}
void displayoptions(string message, int size, string options[], int opt) {
	cout << message << endl;
	for (int i = 0; i < size; i++) {
		if (i % 5 == 0 && i != 0) cout << endl;
		if (i == opt) { cout << "<" << options[i] << ">    "; }
		else { cout << options[i] << "    "; }
	}
	cout << endl;
}
int optionmenu(string message, int size, string options[], bool helper = false) {
	int chosen = 0;
	do {
		system("cls");
		displayoptions(message, size, options, chosen);
		int input = _getch();
		if (input == 0 || input == 224) {
			input = _getch();
			if (input == 77) { chosen = (chosen + 1) % size; }
			else if (input == 75) { chosen = (chosen - 1 + size) % size; }
			else if (helper && (input == 134 || input == 88)) { return -1; }
		}
		else if (input == 13) { return chosen; }
	} while (true);
}
int dashfinder(const string filename) {
	ifstream file(filename);
	int lastnumber = 0;
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			int position = line.find('-');
			string number = line.substr(0, position);
			int num = stoi(number);
			if (num > lastnumber) {
				lastnumber = num;
			}
		}
		file.close();
		return lastnumber;
	}
	else {
		cout << "Error opening file" << endl;
		return -1;
	}
}
string passgenerator() {
	string result = "";
	srand(time(0));
	for (int i = 0; i < 8; i++) {
		char randomChar;
		int randomvalue = rand() % 62;
		if (randomvalue < 10) {
			randomChar = static_cast<char>('0' + randomvalue);
		}
		else if (randomvalue < 36) {
			randomChar = static_cast<char>('A' + (randomvalue - 10));
		}
		else {
			randomChar = static_cast<char>('a' + (randomvalue - 36));
		}
		result += randomChar;
	}
	return result;
}
void addStudent() {
	int count = dashfinder("students.txt") + 1;
	string pass, name;
	cout << "Enter the name of the Student" << endl;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	getline(cin, name);
	name = capitalizeWords(name);

	string options[2] = { "Manually", "Randomly" };
	int temp = optionmenu("Do you want to set a password for '" + name + "' manually or randomly generate it?", 2, options);
	if (temp == 0) {
		cout << "Enter the password: " << endl;
		cin >> pass;
	}
	else if (temp == 1) {
		pass = passgenerator();
	}

	string batchOptions[4] = { "2021", "2022", "2023", "2024" };
	int batchChoice = optionmenu("Select the batch for the student:", 4, batchOptions);
	string prefix;
	if (batchChoice == 0) {
		prefix = "21F";
	}
	else if (batchChoice == 1) {
		prefix = "22F";
	}
	else if (batchChoice == 2) {
		prefix = "23F";
	}
	else if (batchChoice == 3) {
		prefix = "24F";
	}

	string sectionOptions[] = {
		"BS(CS)-1A", "BS(CS)-1B", "BS(CS)-3A", "BS(CS)-3B", "BS(CS)-5A", "BS(CS)-5B", "BS(CS)-7A", "BS(CS)-7B",
		"BS(SE)-1", "BS(SE)-3", "BS(SE)-5", "BS(SE)-7"
	};
	int sectionChoice = optionmenu("Select the section for the student:", 12, sectionOptions);
	string section;
	if (sectionChoice == 0) {
		section = "BSCS1A";
	}
	else if (sectionChoice == 1) {
		section = "BSCS1B";
	}
	else if (sectionChoice == 2) {
		section = "BSCS3A";
	}
	else if (sectionChoice == 3) {
		section = "BSCS3B";
	}
	else if (sectionChoice == 4) {
		section = "BSCS5A";
	}
	else if (sectionChoice == 5) {
		section = "BSCS5B";
	}
	else if (sectionChoice == 6) {
		section = "BSCS7A";
	}
	else if (sectionChoice == 7) {
		section = "BSCS7B";
	}
	else if (sectionChoice == 8) {
		section = "BSSE1";
	}
	else if (sectionChoice == 9) {
		section = "BSSE3";
	}
	else if (sectionChoice == 10) {
		section = "BSSE5";
	}
	else if (sectionChoice == 11) {
		section = "BSSE7";
	}

	srand(time(0));
	int rollnoGenerated;
	bool rollnoExists = true;
	string rollno;
	while (rollnoExists) {
		rollnoGenerated = rand() % 10000;
		rollnoExists = false;
		ifstream studentFile("students.txt");
		string line;
		while (getline(studentFile, line) && !rollnoExists) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:");
			string existingRollno = line.substr(rollStart, rollEnd - rollStart);
			if (existingRollno == prefix + "-" + to_string(rollnoGenerated)) {
				rollnoExists = true;
			}
		}
		studentFile.close();
	}

	if (rollnoGenerated < 10) {
		rollno = prefix + "-000" + to_string(rollnoGenerated);
	}
	else if (rollnoGenerated < 100) {
		rollno = prefix + "-00" + to_string(rollnoGenerated);
	}
	else if (rollnoGenerated < 1000) {
		rollno = prefix + "-0" + to_string(rollnoGenerated);
	}
	else {
		rollno = prefix + "-" + to_string(rollnoGenerated);
	}

	ofstream student("students.txt", ios::app);
	if (!student.is_open()) {
		SetFileAttributesW(L"studentx.txt", FILE_ATTRIBUTE_NORMAL);
		student.open("students.txt", ios::app);
	}
	if (student.is_open()) {
		student << count << "- SECTION: " << section << " NAME: " << name
			<< " ROLLNO: " << rollno << " PASS: " << pass << " CGPA: NA" << endl;
		cout << "The student '" << name << "' has been generated with the roll number '"
			<< rollno << "', password '" << pass << "', section '" << section << "', and CGPA 'NA'." << endl;
		student.close();
		count++;
		SetFileAttributesW(L"studentx.txt", FILE_ATTRIBUTE_READONLY);
		system("pause");
	}
	else {
		cout << "Error opening file" << endl;
	}

	string message = "Would you like to add another student?";
	string options2[2] = { "Yes", "No" };
	int temp2 = optionmenu(message, 2, options2);
	if (temp2 == 0) {
		addStudent();
	}
}
void addTeacher() {
	int count = dashfinder("teachers.txt") + 1;
	string name, user, pass, subject;
	cout << endl;
	cout << "Enter Name: ";
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	getline(cin, name);
	name = capitalizeWords(name);

	string username;
	bool usernameExists = false;
	do {
		cout << "Enter Username: ";
		cin >> username;
		username = toLowerCase(username);
		if (username == "exit") {
			cout << "Username cannot be 'exit'. Please choose a different username." << endl;
			usernameExists = true;
		}
		else {
			ifstream teacherFile("teachers.txt");
			string line;
			usernameExists = false;
			while (getline(teacherFile, line)) {
				int userStart = line.find("USER: ") + 6;
				int userEnd = line.find(" PASS:");
				string existingUser = line.substr(userStart, userEnd - userStart);
				if (username == existingUser) {
					usernameExists = true;
					cout << "Username already exists. Please choose a different username." << endl;
					break;
				}
			}
			teacherFile.close();
		}
	} while (username == "exit" || usernameExists);

	cout << "Enter Password: ";
	cin >> pass;

	int temp = optionmenu("Choose the subject.", NO_OF_SUBJECTS, SUBJECTS);
	string subjects = SUBJECTS[temp];

	ofstream teacher("teachers.txt", ios::app);
	if (!teacher.is_open()) {
		SetFileAttributesW(L"teachers.txt", FILE_ATTRIBUTE_NORMAL);
		teacher.open("teachers.txt", ios::app);
	}

	teacher << count << "- NAME: " << name << " USER: " << username << " PASS: " << pass << " SUBJECT: " << subjects << endl;
	teacher.close();
	cout << name << " Teacher added successfully!" << endl;
	count++;

	SetFileAttributesW(L"teachers.txt", FILE_ATTRIBUTE_READONLY);

	string message = "Would you like to add another teacher?";
	string yesnooptions[2] = { "Yes", "No" };
	int temp2 = optionmenu(message, 2, yesnooptions);
	if (temp2 == 0) {
		addTeacher();
	}
}
void deleteStudent() {
	string roll;
	int count = 1;
	cout << "Enter the rollno of the student that you want to delete: ";
	cin >> roll;
	if (roll[2] == 'f') {
		roll[2] = 'F';
	}
	ifstream student("students.txt");
	ofstream tempfile("temps.txt");
	SetFileAttributesW(L"students.txt", FILE_ATTRIBUTE_NORMAL);
	bool found = false;
	if (student.is_open() && tempfile.is_open()) {
		string line;
		while (getline(student, line)) {
			int rollnostart = line.find("ROLLNO: ") + 8;
			int rollnoend = line.find(" PASS:", rollnostart);
			string rollno = line.substr(rollnostart, rollnoend - rollnostart);
			if (roll != rollno) {
				tempfile << count << "- " << line.substr(line.find("-") + 2) << endl;
				count++;
			}
			else {
				found = true;
			}
		}
		student.close();
		tempfile.close();
		if (found) {
			string options[2] = { "Yes", "No" };
			int temp = optionmenu("Are you sure you want to delete this studentr", 2, options);
			if (temp == 0) {
				remove("students.txt");
				rename("temps.txt", "students.txt");
				SetFileAttributesW(L"students.txt", FILE_ATTRIBUTE_READONLY);
				cout << "student with Roll no. '" << roll << "' deleted successfully" << endl;
			}
			else {
				cout << "Returning to main menu" << endl;
			}system("pause");
		}
		else {
			remove("temps.txt");
			cout << "No student with the Roll no. '" << roll << "' exists in the records" << endl;
			system("pause");
		}
	}
	else {
		cout << "Error opening files" << endl;
	}
	string message = "Would you like to delete another student?";
	string options[2] = { "Yes", "No" };
	int temp = optionmenu(message, 2, options);
	if (temp == 0) {
		deleteStudent();
	}
}
void deleteTeacher() {
	string user;
	int count = 1;
	cout << "Enter the username of the teacher that you want to delete: ";
	cin >> user;
	user = toLowerCase(user);
	ifstream teacher("teachers.txt");
	ofstream tempfile("tempt.txt");
	SetFileAttributesW(L"teachers.txt", FILE_ATTRIBUTE_NORMAL);
	bool found = false;
	if (teacher.is_open() && tempfile.is_open()) {
		string line;
		while (getline(teacher, line)) {
			int userstart = line.find("USER: ") + 6;
			int userend = line.find(" PASS:", userstart);
			string username = line.substr(userstart, userend - userstart);

			if (user != username) {
				tempfile << count << "- " << line.substr(line.find("-") + 2) << endl;
				count++;
			}
			else {
				found = true;
			}
		}
		teacher.close();
		tempfile.close();
		if (found) {
			string options[2] = { "Yes", "No" };
			int temp = optionmenu("Are you sure you want to delete this teacher", 2, options);
			if (temp == 0) {
				remove("teachers.txt");

				rename("tempt.txt", "teachers.txt");
				SetFileAttributesW(L"teachers.txt", FILE_ATTRIBUTE_READONLY);
				cout << "Teacher with username '" << user << "' deleted successfully" << endl;
			}
			else {
				cout << "Returning to main menu" << endl;
			}system("pause");
		}
		else {
			remove("tempt.txt");
			cout << "No teacher with the username '" << user << "' exists in the records" << endl;
			system("pause");
		}
	}
	else {
		cout << "Error opening files" << endl;
	}
	string message = "Would you like to delete another teacher?";
	string options[2] = { "Yes", "No" };
	int temp = optionmenu(message, 2, options);
	if (temp == 0) {
		deleteTeacher();
	}
}
bool studentlogin(string& CGPA, string& ROLLNO) {
	bool loggedin = false;
	string roll, pass;
	do {
		cout << "Please enter your roll number for the student login: ";
		cin >> roll;
		if (roll == "exit") {
			cout << "Exiting...." << endl;
			system("pause");
			return false;
		}
		if (roll[2] == 'f') {
			roll[2] = 'F';
		}
		ifstream file("students.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line) && !loggedin) {
				int rollstart = line.find("ROLLNO: ") + 8;
				int rollend = line.find(" PASS:", rollstart);
				string rollno = line.substr(rollstart, rollend - rollstart);
				if (roll == rollno) {
					do {
						cout << "Enter the password for " << roll << ": ";
						cin >> pass;
						int passstart = line.find("PASS: ") + 6;
						int passend = line.find(" CGPA:", passstart);
						string password = line.substr(passstart, passend - passstart);
						if (pass == password) {
							ROLLNO = rollno;
							loggedin = true;
							int cgpastart = line.find("CGPA: ") + 6;
							CGPA = line.substr(cgpastart);
							if (CGPA.find("NA") == 0) {
								CGPA = "NA";
							}
							else {
								int spacepos = CGPA.find(' ');
								if (spacepos != -1)
									CGPA = CGPA.substr(0, spacepos);
							}
							int namestart = line.find("NAME: ") + 6;
							int nameend = line.find(" ROLLNO:", namestart);
							string name = line.substr(namestart, nameend - namestart);
							cout << "Logging in....";
							Sleep(3000);
							cout << "Welcome Back, Mr/Mrs. " << name << "!" << endl;
							system("pause");
						}
						else {
							cout << "The entered password is incorrect. Please try again." << endl;
						}
					} while (!loggedin);
				}
			}
			file.close();
		}
		if (!loggedin) {
			cout << "Incorrect Roll No. Please try again." << endl;
		}
	} while (!loggedin);
	return loggedin;
}
bool teacherlogin(string& subject) {
	bool loggedin = false;
	string user, pass;
	bool usernamefound = false;

	do {
		cout << "Please enter your username for the teacher login: ";
		cin >> user;
		user = toLowerCase(user);
		if (user == "exit") {
			cout << "Exiting...." << endl;
			system("pause");
			return false;
		}
		ifstream file("teachers.txt");
		if (file.is_open()) {
			string line;
			string name;
			while (getline(file, line) && !loggedin) {
				int userstart = line.find("USER: ") + 6;
				int userend = line.find(" PASS:", userstart);
				string username = line.substr(userstart, userend - userstart);
				if (user == username) {
					usernamefound = true;
					do {
						cout << "Enter the password for " << user << ": ";
						cin >> pass;
						int passstart = line.find("PASS: ") + 6;
						int passend = line.find(" SUBJECT:", passstart);
						string password = line.substr(passstart, passend - passstart);
						if (pass == password) {
							loggedin = true;
							cout << "Logging in....";
							int namestart = line.find("NAME: ") + 6;
							int nameend = line.find(" USER:", namestart);
							name = line.substr(namestart, nameend - namestart);
							Sleep(3000);
							int subjectstart = line.find("SUBJECT: ") + 9;
							subject = line.substr(subjectstart);
							cout << "Welcome Back Mr/Mrs. " << name << "!" << endl;
							system("pause");
						}
						else {
							cout << "The entered password is incorrect. Please try again." << endl;
						}
					} while (!loggedin);
				}
			}
			file.close();
		}
		else {
			cout << "Error opening file." << endl;
		}
		if (!usernamefound) {
			cout << "Incorrect username. Please try again." << endl;
		}
	} while (!loggedin);

	return loggedin;
}
void displaySubjectFiles(string ROLLNO) {
	for (int i = 0; i < 16; i++) {
		string formattedSubject = SUBJECTS[i];
		for (int j = 0; j < formattedSubject.length(); j++) {
			if (formattedSubject[j] == ' ')
				formattedSubject[j] = '_';
		}
		string fileName = ROLLNO + "_" + formattedSubject + ".txt";
		ifstream file(fileName);
		if (file.is_open()) {
			cout << "Marks of " << SUBJECTS[i] << ":" << endl;
			string line;
			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
		}
		else {
			cout << "Records for " << SUBJECTS[i] << " do not exist." << endl;
		}
		cout << "-------------------------------------------" << endl;
	}
}
void studentMenu(string CGPA, string ROLLNO) {
	string options[3] = { "View Grades", "View CGPA", "Exit" };
	string message = "Choose what you would like to do below\n";
	int temp = optionmenu(message, 3, options);
	if (temp == 0) {
		displaySubjectFiles(ROLLNO);
		system("pause");
	}
	else if (temp == 1) {
		if (CGPA == "NA") {
			cout << "Your GPA is not available, contact your teacher to update your GPA" << endl;
			system("pause");
		}
		else {
			cout << "Your CGPA is: " << CGPA << endl;
			system("pause");
		}
	}
	else if (temp == 2) {

	}
}
void adminlogin() {
	int tries = 0;
	string user, pass;

	do {
		cout << "Please enter your username for the admin login: ";
		cin >> user;
		cin.ignore();

		if (user == admin[0][0] || user == admin[1][0]) {
			int index = (user == admin[0][0]) ? 0 : 1;
			cout << "Please enter your password: ";
			getline(cin, pass);

			if (pass == admin[index][1]) {
				cout << "Logging in.....";
				Sleep(3000);
				cout << "Welcome back " << (index == 0 ? "Muhammad Umar Nadeem" : "Cheema Saahib") << "!" << endl;
				system("pause");

				string options[2] = { "Add Teacher", "Delete Teacher" };
				int temp = optionmenu("Choose from the options below", 2, options);
				ifstream file("teachers.txt");

				if (temp == 0) {
					addTeacher();
				}
				else if (temp == 1) {
					if (file.is_open() && file.peek() != EOF) {
						file.close();
						deleteTeacher();
					}
					else {
						cout << "No teachers exist in the record, add teachers to be able to delete teachers." << endl;
						system("pause");
					}
				}
				return;
			}
			else {
				cout << "You have entered an incorrect password, please try again :(" << endl;
			}
		}
		else {
			cout << "You have entered a wrong username." << endl;
		}

		tries++;
		if (tries < 3) {
			cout << "You have " << (3 - tries) << " attempt(s) remaining." << endl;
		}

	} while (tries < 3);
	cout << "You have entered wrong credentials too many times." << endl;
}
void calculateCGPA(string rollno) {
	float totalgpa = 0;
	int totalCreditHours = 0;
	for (int i = 0; i < NO_OF_SUBJECTS; i++) {
		int creditHours = stoi(SUBJECTSWITHCH[i].substr(0, SUBJECTSWITHCH[i].find('.')));
		string subjectName = SUBJECTSWITHCH[i].substr(SUBJECTSWITHCH[i].find('.') + 1);
		string filename = rollno + "_" + subjectName + ".txt";
		ifstream subjectFile(filename);
		float gpa = 0.0;
		if (subjectFile.is_open()) {
			string line;
			while (getline(subjectFile, line)) {
				if (line.find("GPA: ") != string::npos) {
					int gpaPos = line.find("GPA: ") + 5;
					int statusPos = line.find(" (", gpaPos);
					string gpaStr = line.substr(gpaPos, statusPos - gpaPos);
					gpa = stof(gpaStr);
					break;
				}
			}
			subjectFile.close();
		}
		else {
			cout << "Warning: File for " << subjectName << " not found. GPA set to 0." << endl;
		}

		totalgpa += gpa * creditHours;
		totalCreditHours += creditHours;
	}
	float cgpa;
	if (totalCreditHours > 0) {
		cgpa = totalgpa / totalCreditHours;
	}
	else {
		cgpa = 0.0;
	}
	string status;
	if (cgpa < 1.0) status = "FAIL";
	else if (cgpa >= 1.0 && cgpa < 2.0) status = "WARNING";
	else status = "PASS";
	ifstream studentFile("students.txt");
	ofstream tempFile("temp.txt");
	if (studentFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(studentFile, line)) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:", rollStart);
			string roll = line.substr(rollStart, rollEnd - rollStart);
			if (roll == rollno) {
				int passPos = line.find("PASS: ") + 6;
				int passEnd = line.find(" CGPA: ", passPos);
				string password = line.substr(passPos, passEnd - passPos);

				tempFile << line.substr(0, passPos) << password << " CGPA: "
					<< fixed << setprecision(2) << cgpa << " (" << status << ")" << endl;
			}
			else {
				tempFile << line << endl;
			}
		}
		studentFile.close();
		tempFile.close();
		remove("students.txt");
		rename("temp.txt", "students.txt");

		cout << "CGPA calculated and updated successfully for roll number " << rollno
			<< ": " << fixed << setprecision(2) << cgpa << " (" << status << ")" << endl;
	}
	else {
		cout << "Error opening student file!" << endl;
	}
}
float calculateGPA(int totalMarks) {
	float gpa = 0.0;
	if (totalMarks >= 90) {
		gpa = 4.0;
	}
	else if (totalMarks >= 85) {
		gpa = 3.7;
	}
	else if (totalMarks >= 80) {
		gpa = 3.5;
	}
	else if (totalMarks >= 75) {
		gpa = 3.2;
	}
	else if (totalMarks >= 70) {
		gpa = 3.0;
	}
	else if (totalMarks >= 65) {
		gpa = 2.7;
	}
	else if (totalMarks >= 60) {
		gpa = 2.5;
	}
	else if (totalMarks >= 55) {
		gpa = 2.2;
	}
	else if (totalMarks >= 50) {
		gpa = 2.0;
	}
	else if (totalMarks >= 45) {
		gpa = 1.5;
	}
	else if (totalMarks >= 40) {
		gpa = 1.0;
	}
	else {
		gpa = 0.0;
	}

	return gpa;
}
void assignmarks(string subject) {
	ifstream student("students.txt");
	const int MAX_ROLLNOS = 9999;
	string rollNumbers[MAX_ROLLNOS];
	int rollCount = 0;

	if (student.is_open()) {
		string line;

		while (getline(student, line) && rollCount < MAX_ROLLNOS) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:", rollStart);
			rollNumbers[rollCount] = line.substr(rollStart, rollEnd - rollStart);
			rollCount++;
		}
		student.close();

		if (rollCount == 0) {
			cout << "No roll numbers found in the student file." << endl;
			return;
		}

		while (true) {
			string message = "Choose which type of evaluation you want to update for all students in subject " + subject + " (or select Exit to leave):";
			string options[6] = { "Quizzes", "Assignments", "Sessional-I", "Sessional-II", "Finals", "Exit" };
			int evaluationType = optionmenu(message, 6, options);

			if (evaluationType == 5) {
				cout << "Exiting the evaluation menu." << endl;
				Sleep(3000);
				break;
			}

			cout << "You selected " << options[evaluationType] << "." << endl;

			for (int i = 0; i < rollCount; i++) {
				string rollno = rollNumbers[i];

				string evaluations[7] = {
					"Total Marks: 0",
					"GPA: 0.00(PASS)",
					"Quizzes: 0",
					"Assignments: 0",
					"Sessional-I: 0",
					"Sessional-II: 0",
					"Finals: 0"
				};

				ifstream file(rollno + "_" + subject + ".txt");
				if (!file.is_open()) {
					ofstream newFile(rollno + "_" + subject + ".txt");
					if (newFile.is_open()) {
						for (int j = 0; j < 7; j++) {
							newFile << evaluations[j] << endl;
						}
						newFile.close();
					}
					else {
						cout << "Error creating the file for roll number " << rollno << "." << endl;
						continue;
					}
				}
				else {
					for (int j = 0; j < 7; j++) {
						getline(file, evaluations[j]);
					}
					file.close();
				}

				int marks;
				do {
					cout << "Enter the marks for " << options[evaluationType] << " of " << rollno << ": ";
					cin >> marks;
					bool invalidMarks = marks < 0 ||
						((evaluationType == 0 || evaluationType == 1) && marks > 10) ||
						((evaluationType == 2 || evaluationType == 3) && marks > 15) ||
						(evaluationType == 4 && marks > 50);
					if (invalidMarks) {
						cout << "Invalid input. ";
						if (evaluationType == 0 || evaluationType == 1) {
							cout << "Quizzes and assignments marks must be between 0 and 10.";
						}
						else if (evaluationType == 2 || evaluationType == 3) {
							cout << "Sessional marks must be between 0 and 15.";
						}
						else if (evaluationType == 4) {
							cout << "Finals marks must be between 0 and 50.";
						}
						cout << " Please enter again." << endl;
					}
					else {
						break;
					}
				} while (true);

				evaluations[evaluationType + 2] = options[evaluationType] + ": " + to_string(marks);
				int totalMarks = 0;
				for (int j = 2; j < 7; j++) {
					int markIndex = evaluations[j].find(":") + 2;
					totalMarks += stoi(evaluations[j].substr(markIndex));
				}
				evaluations[0] = "Total Marks: " + to_string(totalMarks);

				float gpa = calculateGPA(totalMarks);
				string status = (gpa >= 1 && gpa < 4) ? "PASS" : "FAIL";
				evaluations[1] = "GPA: " + to_string(gpa) + "(" + status + ")";

				string studentfile = rollno + "_" + subject + ".txt";
				wstring wideStudentFile(studentfile.begin(), studentfile.end());

				ofstream marksfile(studentfile, ios::trunc);
				if (!marksfile.is_open()) {
					SetFileAttributesW(wideStudentFile.c_str(), FILE_ATTRIBUTE_NORMAL);
					marksfile.open(studentfile, ios::app);
				}
				for (int j = 0; j < 7; j++) {
					marksfile << evaluations[j] << endl;
				}
				marksfile.close();
				SetFileAttributesW(wideStudentFile.c_str(), FILE_ATTRIBUTE_READONLY);

				cout << "Marks for " << options[evaluationType] << " updated successfully for " << rollno << "." << endl;
			}

			cout << "All marks for " << options[evaluationType] << " updated successfully." << endl;
			system("pause");
		}
	}
	else {
		cout << "Error opening student file." << endl;
	}
}
void displayCGPA(string rollno) {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		string line;
		bool rollnoExists = false;
		while (getline(studentFile, line)) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:", rollStart);
			string roll = line.substr(rollStart, rollEnd - rollStart);
			if (roll == rollno) {
				rollnoExists = true;
				int cgpaStart = line.find("CGPA: ") + 6;
				string cgpa = line.substr(cgpaStart);
				if (cgpa == "NA") {
					cout << "CGPA for roll number " << rollno << " is not available.\n";
					cout << "Please contact your instructor to calculate your CGPA." << endl;
				}
				else {
					cout << "CGPA for roll number " << rollno << ": " << cgpa << endl;
				}
				break;
			}
		}
		if (!rollnoExists) {
			cout << "Roll number " << rollno << " not found in the student file." << endl;
		}
		studentFile.close();
	}
	else {
		cout << "Error opening students.txt file!" << endl;
	}
}
void listPassedStudents() {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		string line;
		cout << "List of Passed Students:" << endl;
		bool foundPassedStudent = false;

		while (getline(studentFile, line)) {
			int cgpaPos = line.find("CGPA: ");
			if (cgpaPos != string::npos) {
				int statusPosStart = line.find("(", cgpaPos);
				int statusPosEnd = line.find(")", statusPosStart);
				if (statusPosStart != string::npos && statusPosEnd != string::npos) {
					string status = line.substr(statusPosStart + 1, statusPosEnd - statusPosStart - 1);
					if (status == "PASS") {
						int rollStart = line.find("ROLLNO: ") + 8;
						int rollEnd = line.find(" ", rollStart);
						string rollNo = line.substr(rollStart, rollEnd - rollStart);
						int nameEnd = line.find(" ROLLNO: ");
						string name = line.substr(5, nameEnd - 5);
						cout << "Student: " << name << " (Roll No: " << rollNo << ")" << endl;
						foundPassedStudent = true;
					}
				}
			}
		}

		studentFile.clear();
		studentFile.seekg(0, ios::beg);

		cout << "\nList of Warning Students:" << endl;
		bool foundWarningStudent = false;

		while (getline(studentFile, line)) {
			int cgpaPos = line.find("CGPA: ");
			if (cgpaPos != string::npos) {
				int statusPosStart = line.find("(", cgpaPos);
				int statusPosEnd = line.find(")", statusPosStart);
				if (statusPosStart != string::npos && statusPosEnd != string::npos) {
					string status = line.substr(statusPosStart + 1, statusPosEnd - statusPosStart - 1);
					if (status == "WARNING") {
						int rollStart = line.find("ROLLNO: ") + 8;
						int rollEnd = line.find(" ", rollStart);
						string rollNo = line.substr(rollStart, rollEnd - rollStart);
						int nameEnd = line.find(" ROLLNO: ");
						string name = line.substr(5, nameEnd - 5);
						cout << "Student: " << name << " (Roll No: " << rollNo << ")" << endl;
						foundWarningStudent = true;
					}
				}
			}
		}

		if (!foundPassedStudent) {
			cout << "No students with PASS status found.\n";
		}

		if (!foundWarningStudent) {
			cout << "No students with WARNING status found.\n";
		}

		studentFile.close();
	}
	else {
		cout << "Error opening student file!\n";
	}
	system("pause");
}
void listFailedStudents() {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		string line;
		while (getline(studentFile, line)) {
			int cgpaPos = line.find("CGPA: ");
			if (cgpaPos != string::npos) {
				int statusPosStart = line.find("(", cgpaPos);
				int statusPosEnd = line.find(")", statusPosStart);
				if (statusPosStart != string::npos && statusPosEnd != string::npos) {
					string status = line.substr(statusPosStart + 1, statusPosEnd - statusPosStart - 1);
					if (status == "FAIL") {
						int rollStart = line.find("ROLLNO: ") + 8;
						int rollEnd = line.find(" ", rollStart);
						string rollNo = line.substr(rollStart, rollEnd - rollStart);
						int nameStart = line.find("NAME: ") + 6;
						int nameEnd = line.find(" ROLLNO: ");
						string name = line.substr(nameStart, nameEnd - nameStart);
						cout << "Student: " << name << " (Roll No: " << rollNo << ")" << endl;
					}
				}
			}
		}
		studentFile.close();
	}
	system("pause");
}
void listPassedStudentsForSubject(string subjectName) {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		cout << "List of Passed Students for " << subjectName << ":\n";
		string line;
		bool foundAnyPassedStudent = false;
		while (getline(studentFile, line)) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:", rollStart);
			string rollno = line.substr(rollStart, rollEnd - rollStart);
			int nameStart = line.find("NAME: ") + 6;
			int nameEnd = line.find(" ROLLNO:", nameStart);
			string name = line.substr(nameStart, nameEnd - nameStart);
			string filename = rollno + "_" + subjectName + ".txt";
			ifstream subjectFile(filename);
			if (subjectFile.is_open()) {
				string subjectLine;
				bool passedStatusFound = false;
				while (getline(subjectFile, subjectLine)) {
					int statusPos = subjectLine.find("GPA: ");
					if (statusPos != -1) {
						string status = subjectLine.substr(statusPos + 5);
						if (status.find("(PASS)") != -1) {
							passedStatusFound = true;
							break;
						}
					}
				}
				subjectFile.close();
				if (passedStatusFound) {
					cout << "Student: " << name << " (Roll No: " << rollno << ")\n";
					foundAnyPassedStudent = true;
				}
			}
		}
		if (!foundAnyPassedStudent) {
			cout << "No passed students found for " << subjectName << ".\n";
		}
		studentFile.close();
	}
	else {
		cout << "Error opening student file!\n";
	}
}
void listFailedStudentsForSubject(string subjectName) {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		cout << "List of Failed Students for " << subjectName << ":" << endl;
		string line;
		while (getline(studentFile, line)) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" PASS:", rollStart);
			string rollno = line.substr(rollStart, rollEnd - rollStart);
			string filename = rollno + "_" + subjectName + ".txt";
			ifstream subjectFile(filename);
			if (subjectFile.is_open()) {
				string subjectLine;
				while (getline(subjectFile, subjectLine)) {
					if (subjectLine.find("FAIL") != string::npos) {
						int nameStart = line.find("NAME: ") + 6;
						int nameEnd = line.find(" ROLLNO:", nameStart);
						string name = line.substr(nameStart, nameEnd - nameStart);
						cout << "Student: " << name << " (Roll No: " << rollno << ")" << endl;
						break;
					}
				}
				subjectFile.close();
			}
		}
		studentFile.close();
	}
	else {
		cout << "Error opening student file!" << endl;
	}
}
void calculateAverageGPA(string subjectName) {
	ifstream studentFile("students.txt");
	if (studentFile.is_open()) {
		string line;
		int totalStudents = 0;
		float totalGPA = 0.0f;
		int validEntries = 0;
		while (getline(studentFile, line)) {
			int rollStart = line.find("ROLLNO: ") + 8;
			int rollEnd = line.find(" ", rollStart);
			string rollno = line.substr(rollStart, rollEnd - rollStart);
			string filename = rollno + "_" + subjectName + ".txt";
			ifstream subjectFile(filename);
			if (subjectFile.is_open()) {
				string subjectLine;
				float gpa = -1.0f;
				while (getline(subjectFile, subjectLine)) {
					if (subjectLine.find("GPA: ") != string::npos) {
						int gpaStart = subjectLine.find("GPA: ") + 5;
						int gpaEnd = subjectLine.find("(", gpaStart);
						string gpaStr = subjectLine.substr(gpaStart, gpaEnd - gpaStart);
						gpa = stof(gpaStr);
						break;
					}
				}
				if (gpa >= 0.0f) {
					totalGPA += gpa;
					validEntries++;
				}
				subjectFile.close();
			}
		}
		studentFile.close();
		if (validEntries > 0) {
			cout << "Average GPA for " << subjectName << ": " << totalGPA / validEntries << endl;
		}
		else {
			cout << "No valid GPA entries for subject: " << subjectName << endl;
		}
	}
	else {
		cout << "Error opening student file!" << endl;
	}system("pause");
}
void calculateAverageCGPA() {
	ifstream studentFile("students.txt");
	if (!studentFile.is_open()) {
		cout << "Error opening student records file!" << endl;
		return;
	}
	string line;
	float totalCGPA = 0.0f;
	int validEntries = 0;
	while (getline(studentFile, line)) {
		int cgpaStart = line.find("CGPA: ") + 6;
		int cgpaEnd = line.find("(", cgpaStart);
		if (cgpaEnd == string::npos) {
			cgpaEnd = line.find(" ", cgpaStart);
		}
		string cgpaStr = line.substr(cgpaStart, cgpaEnd - cgpaStart);
		if (cgpaStr == "NA") continue;

		float cgpa = stof(cgpaStr);
		totalCGPA += cgpa;
		validEntries++;
	}
	studentFile.close();
	if (validEntries > 0) {
		float averageCGPA = totalCGPA / validEntries;
		cout << "Average CGPA of all students: " << fixed << setprecision(2) << averageCGPA << endl;
	}
	else {
		cout << "No valid CGPA entries found!" << endl;
	}system("pause");
}
void teacherMenu(string subject) {
	string options[10] = { "Add Student", "Delete Student", "Calculate CGPA", "Average GPA", "Assign Marks", "List Passed Students For Subject", "List Failed Students For Subject","List Passed Students", "List Failed Students", "Exit" };
	string message = "Choose what you would like to do below\nPress F12 for help\n";
	int temp = optionmenu(message, 10, options, true);
	if (temp == 0) {
		addStudent();
	}
	else if (temp == 1) {
		ifstream file("students.txt");
		if (file.is_open() && file.peek() != EOF) {
			file.close();
			deleteStudent();
		}
		else {
			cout << "No records of students exist, add students from teacher functions to delete them." << endl;
			system("pause");
		}
	}
	else if (temp == 2) {
		string rollno;
		cout << "Enter the Enrollment Number of the student: ";
		cin >> rollno;
		calculateCGPA(rollno);
	}
	else if (temp == 3) {
		string options2[2] = { "Individual Subject", "Overall GPA" };
		int temp2 = optionmenu("", 2, options2);
		if (temp2 == 0) {
			calculateAverageGPA(subject);
		}
		else if (temp2 == 1) {
			calculateAverageCGPA();
		}
	}
	else if (temp == 4) {
		assignmarks(subject);
	}
	else if (temp == 5) {
		listPassedStudentsForSubject(subject);
	}
	else if (temp == 6) {
		listFailedStudentsForSubject(subject);
	}
	else if (temp == 7) {
		listPassedStudents();
	}
	else if (temp == 8) {
		listFailedStudents();
	}
	else if (temp == 9) {
		return;
	}
	else if (temp == -1) {
		system("cls");
		cout << "\033[1;31mAdd Student\033[0m" << endl;
		cout << "Adds a new student to the system. The teacher will input the student's details and the student will be added to the database." << endl;
		cout << "\033[1;31mDelete Student\033[0m" << endl;
		cout << "Deletes a student from the system based on their Roll Number. The system will remove all records of the student from the database." << endl;
		cout << "\033[1;32mCalculate CGPA\033[0m" << endl;
		cout << "Calculates the CGPA (Cumulative Grade Point Average) of a student based on their grades in various subjects. This helps in evaluating the student's academic performance." << endl;
		cout << "\033[1;32mAverage CGPA\033[0m" << endl;
		cout << "Computes the average CGPA of all students in the system, providing an overview of the overall academic performance in the class." << endl;
		cout << "\033[1;34mAssign Marks\033[0m" << endl;
		cout << "Allows teachers to assign marks to students for different subjects. This is a crucial function for grading and evaluating student progress." << endl;
		cout << "\033[1;36mList Passed Students\033[0m" << endl;
		cout << "Filters and displays students who have a CGPA or GPA for a particular subject greater than or equal to 1.0, indicating that they have passed based on the criteria." << endl;
		cout << "\033[1;36mList Failed Students\033[0m" << endl;
		cout << "Filters and displays students who have a CGPA or GPA for a particular subject less than 1.0, indicating that they have failed based on the criteria." << endl;
		cout << endl;
		system("pause");
	}
}
void SMS() {
	system("CLS");//This Function Clears the screen

	cout << setw(70);
	cout << "Welcome to Student management system" << endl;
	ifstream SMS("SMS.txt");
	if (SMS.is_open()) {
		string line;
		while (getline(SMS, line)) {
			cout << setw(85);
			cout << line << endl;
		}
	}
	Sleep(5000);
	system("CLS");//This Function Clears the screen

}
int main() {
	system("color 34");
	if (!SetCurrentDirectory(L"data")) {
		CreateDirectory(L"data", NULL);
		SetCurrentDirectory(L"data");
	}
	SMS();
	string options[4] = { "Admin", "Teacher", "Student", "Exit" };
	string message = "This is the SMS main menu.\nSelect from the options down below, use the arrow keys to navigate\nPress F12 key for details regarding options.";
	while (true) {
		int option = optionmenu(message, 4, options, true);
		if (option == 0) {
			adminlogin();
		}
		else if (option == 1) {
			ifstream file("teachers.txt");
			bool validfile = false;
			if (file.is_open() && file.peek() != EOF) {
				validfile = true;
			}file.close();
			if (validfile) {
				string subject;
				if (teacherlogin(subject)) {
					teacherMenu(subject);
				}
			}
			else {
				cout << "No teachers exist in the system, use admin functions to add teacher data" << endl;
				Sleep(3000);
			}
		}
		else if (option == 2) {
			string CGPA, ROLLNO;
			ifstream file("students.txt");
			bool validfile = false;
			if ((file.is_open()) && file.peek() != EOF) {
				validfile = true;
			}file.close();
			if (validfile) {
				if (studentlogin(CGPA, ROLLNO)) {
					studentMenu(CGPA, ROLLNO);
				}
			}
			else {
				cout << "No students exist in the system, use teacher functions to add student data" << endl;
				Sleep(3000);
			}
		}
		else if (option == 3) {
			cout << "Goodbye!" << endl;
			return 0;
		}
		else if (option == -1) {
			system("cls");
			cout << "\033[1;31mAdministrator (Admin)\033[0m" << endl;
			cout << "Controls the core functionality of the system such as adding and deleting teachers." << endl;
			cout << endl;
			cout << "\033[1;32mTeacher\033[0m" << endl;
			cout << "Can add and remove students, assign them grades, and access data regarding student and subject-specific GPA and overall GPA of all students." << endl;
			cout << endl;
			cout << "\033[1;34mStudent\033[0m" << endl;
			cout << "Can access their relevant data such as viewing their individual subject GPA and CGPA." << endl;
			cout << endl;
			system("pause");
		}
	}

}