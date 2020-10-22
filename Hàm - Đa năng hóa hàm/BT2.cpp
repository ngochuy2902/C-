#include <iostream>

using namespace std;

struct Student
{
    float math;
    float literature;
    float average;
};

istream& operator>>(istream &is, Student &st)
{
    cout<<"Math: "; is>>st.math;
    cout<<"Literature: "; is>>st.literature;
    st.average = (st.math*2 + st.literature) / 3;
    return is;
}

ostream& operator<<(ostream &os, const Student &st)
{
    os<<"Math: "<<st.math<<endl;
    os<<"Literature: "<<st.literature<<endl;
    os<<"Average: "<<st.average<<endl;
    return os;
}

bool operator>(Student st1, Student st2)
{
    if (st1.average>st2.average) return true;
    return false;
}

bool operator<(Student st1, Student st2)
{
    if (st1.average<st2.average) return true;
    return false;
}

int main()
{
    Student st1, st2;
    cout<<"+ Enter student 1"<<endl;
    cin>>st1;
    cout<<"+ Enter student 2"<<endl;
    cin>>st2;
    cout<<"--------------------"<<endl;
    cout<<"+ Student 1"<<endl; cout<<st1;
    cout<<"+ Student 2"<<endl; cout<<st2;
    if (st1>st2) cout<<"Student 1 is better than Student 2"<<endl;
    if (st1<st2) cout<<"Student 1 is worse than Student 2"<<endl;
}

