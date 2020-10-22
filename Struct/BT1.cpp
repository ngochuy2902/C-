/*Thông tin một học sinh bao gồm:

Họ tên.
Điểm văn, toán.
  
Viết chương trình cho phép thực hiện các thao tác trên kiểu struct học sinh để quản lý danh sách học sinh.
Nhập, xuất thông tin học sinh.
Tính điểm trung bình của mỗi học sinh.
Xếp loại theo tiêu chí: Giỏi (>= 8.0), Khá (>= 7.0). Trung bình (>= 5.0), Yếu (< 5).*/

#include <iostream>
#include <string.h>

using namespace std;

struct Student
{
    char name[30];
    float math;
    float literature;

    Student()
    {
        strncpy(name, "", 30);
        math = 0;
        literature = 0;
    };

    Student(char n[30], float m, float l)
    {
        strncpy(name, n, 30);
        math = m;
        literature = l;
    }

    void Input()
    {
        cout << "Name = ";
        cin >> name;
        cout << "Math = ";
        cin >> math;
        cout << "Literature = ";
        cin >> literature;
    }

    void Display()
    {
        cout << "Name: " << name << "  -  Math: " << math << "  -  Literature: " << literature << endl;
    }

    void Average()
    {
        float average = (math + literature) / 2;
        cout << "Average: " << average << endl;
    }

    void Ranking()
    {
        float average = (math + literature) / 2;
        cout << "Ranking: ";
        if (average >= 8)
            cout << "Excellent";
        else if (average >= 7)
            cout << "Good";
        else if (average >= 5)
            cout << "Average";
        else
            cout << "Poor";
        cout << endl;
    }
};

int main()
{
    int n_students;
    while (true)
    {
        cout << "How many students? ";
        cin >> n_students;
        if (n_students > 0)
            break;
    }

    Student students[n_students];

    for (int i = 0; i < n_students; i++)
    {
        cout << "\nStudent " << i << endl;
        students[i].Input();
    }

    for (int i = 0; i < n_students; i++)
    {
        cout << "\nStudent " << i << endl;
        students[i].Display();
        students[i].Average();
        students[i].Ranking();
    }

    return 0;
}