# Student-Management-System-SMS-Project
Project Overview:
The Student Management System is a file-based C++ application designed to manage student records with three main sections: Admin, Student, and Teacher. The system utilizes file handling for data storage, allowing the persistence of student, teacher, and admin information across sessions. This project is an ideal first-year project, focusing on core programming concepts like file handling, data storage, and basic user interfaces.
<br><hr>
Key Features:<br><hr>
Admin Section:
<br>
Add Student Records: Admin can add new student records including personal information like name, roll number, age, and course.<br>
Manage Teacher Records: Admin can add or update teacher information like name, subject taught, and employee ID.<br>
View All Records: Admin can view both student and teacher records.<br>
Delete Records: Admin can delete student or teacher records from the system.<br><hr>
Student Section:
<br><hr>
View Personal Records: Students can view their own information stored in the system.<br>
Update Own Details: Students can update their personal details (such as contact info or address) by verifying their identity.<br><hr>
Teacher Section:
<br><hr>
View Student Records: Teachers can access records of the students they teach, including grades and personal information.<br>
Add/Update Grades: Teachers can add or update grades for students.<br>
Data Persistence: All records (students, teachers) are stored in files, ensuring that data is saved and retrieved efficiently.<br><hr>

Technologies Used:
<br><hr>
C++: The core language used for implementing the system, focusing on object-oriented programming.<br>
File Handling: Used to store and retrieve data about students, teachers, and admins in text files.<br>
Text-Based Interface: Simple menu-driven interface allowing interaction with the system.<br><hr>
Core Concepts:<br><hr>
File Handling: Data (such as student and teacher records) is saved to files (e.g., students.txt, teachers.txt) using fstream to handle input/output operations.<br><hr>
How It Works:<br><hr>
Admin Login:<br><br>

Admin can login by entering credentials (username and password).<br>
Admin can perform CRUD operations (Create, Read, Update, Delete) on student and teacher records.<br>
The data is saved in separate files (e.g., students.txt, teachers.txt).<br>
Student Section:<br><br>

Students can login with their roll number.<br>
They can view their records and update their details, if needed, and the updated data is written back to the file.<br>
Teacher Section:<br><br>

Teachers can login with their ID.<br>
They can view student records related to their course and update grades.<br>
File Handling:<br><br>

Data is stored in text files. For example:<br>
students.txt: Contains student records in a specific format (e.g., roll number, name, age, course).<br>
teachers.txt: Contains teacher records in a similar format.<br>
The system uses fstream to read and write data to these files.