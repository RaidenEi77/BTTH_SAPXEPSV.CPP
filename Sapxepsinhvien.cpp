#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
 string id;
 string name;
 double gpa;
 int credits;
 int discipline;
};


bool isEligible(const Student& s) {
 return s.gpa >= 3.2 &&
 s.credits >= 24 &&
 s.discipline == 0;
}


bool higherRank(const Student& a, const Student& b) {
 if (a.gpa != b.gpa)
 return a.gpa > b.gpa;

 if (a.credits != b.credits)
 return a.credits > b.credits;

 return a.id < b.id;
}

// Bubble Sort
void bubbleSort(vector<Student>& students) {
 int n = students.size();

 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (!higherRank(students[j], students[j + 1])) {
 swap(students[j], students[j + 1]);
 }
 }
 }
}

int main() {
 vector<Student> ds = {
 {"SV08", "Lan", 3.70, 30, 0},
 {"SV02", "Minh", 3.85, 28, 0},
 {"SV05", "Ha", 3.70, 33, 0},
 {"SV01", "An", 3.20, 25, 0},
 {"SV07", "Binh", 3.90, 22, 0},
 {"SV06", "Dung", 3.70, 33, 0},
 {"SV03", "Vy", 3.10, 40, 0},
 {"SV04", "Huy", 3.85, 28, 1}
 };

 vector<Student> eligible;

 
 for (auto s : ds) {
 if (isEligible(s))
 eligible.push_back(s);
 }

 
 bubbleSort(eligible);

 cout << "DANH SACH XEP HANG HOC BONG\n";
 cout << "==========================\n";

 for (int i = 0; i < eligible.size(); i++) {
 cout << i + 1 << ". "
 << eligible[i].id << " - "
 << eligible[i].name << " - GPA: "
 << eligible[i].gpa << " - TC: "
 << eligible[i].credits << endl;
 }

 return 0;
}
