# Student Record Management System (SRMS)

## 🧾 Overview of the Project
This is a console-based Student Record Management System developed in the C programming language. It allows users to manage student data efficiently with functionality to add, modify, delete, search, sort, and persist records to a file.

## 💻 Tech Stack Used
- Programming Language: C
- Compilation: GCC or any standard C compiler
- Development Environment: VS Code (or any preferred IDE)
- File Handling: Text file (`students.txt`)

## ⚙️ Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/MerugaVarun/TAUSCP1102_241_2025.git
   cd TAUSCP1102_241_2025
   ```

2. Compile the C source file:
   ```bash
   gcc Student_RMS.C -o student_rms
   ```

3. Run the program:
   ```bash
   ./student_rms
   ```

## 🎮 Functionality and Usage Guide
- **Add Student**: Input name, roll number, marks; grade calculated automatically.
- **Modify Student**: Change name or marks of an existing student.
- **Delete Student**: Remove a student record by roll number.
- **Search Student**: Look up a student by roll number.
- **Display Students**: View all student records.
- **Sort Records**: Sort by roll number or marks using bubble sort.
- **File Save/Load**: Automatically saves to and loads from `students.txt`.

## 📝 Special Notes or References
- Maximum of 100 records (fixed size array).
- File `students.txt` is created automatically if it doesn't exist.
- Simple text-based menu interface for user interaction.
- For enhancements, consider using dynamic memory (`malloc`) or a GUI front-end.

---

© 2025 Varun Meruga | CLP Project
