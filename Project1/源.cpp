#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ����ѧ����
class Student {
public:
    Student(string name, int id, int age) {
        this->name = name;
        this->id = id;
        this->age = age;
    }

    string getName() { return name; }
    int getId() { return id; }
    int getAge() { return age; }

private:
    string name;  // ����
    int id;       // ѧ��
    int age;      // ����
};

// ����ѧ��������
class StudentManager {
public:
    // ���ѧ��
    void addStudent(string name, int id, int age) {
        Student student(name, id, age);
        students.push_back(student);
        cout << "���ѧ���ɹ���" << endl;
    }

    // ��ѯѧ����Ϣ
    void queryStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                cout << "ѧ��������" << students[i].getName() << endl;
                cout << "ѧ��ѧ�ţ�" << students[i].getId() << endl;
                cout << "ѧ�����䣺" << students[i].getAge() << endl;
                return;
            }
        }
        cout << "δ�ҵ���ѧ����" << endl;
    }

    // ɾ��ѧ��
    void deleteStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "ɾ���ɹ���" << endl;
                return;
            }
        }
        cout << "δ�ҵ���ѧ����" << endl;
    }

private:
    vector<Student> students;  // ѧ���б�
};

// ������
int main() {
    StudentManager manager;
    int choice = 0;
    while (true) {
        cout << "��ѡ���ܣ�" << endl;
        cout << "1. ���ѧ��" << endl;
        cout << "2. ��ѯѧ����Ϣ" << endl;
        cout << "3. ɾ��ѧ��" << endl;
        cout << "4. �˳�" << endl;
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, age;
            cout << "������ѧ��������" << endl;
            cin >> name;
            cout << "������ѧ��ѧ�ţ�" << endl;
            cin >> id;
            cout << "������ѧ�����䣺" << endl;
            cin >> age;
            manager.addStudent(name, id, age);
        }
        else if (choice == 2) {
            int id;
            cout << "������ѧ��ѧ�ţ�" << endl;
            cin >> id;
            manager.queryStudent(id);
        }
        else if (choice == 3) {
            int id;
            cout << "������ѧ��ѧ�ţ�" << endl;
            cin >> id;
            manager.deleteStudent(id);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "��������������ѡ��" << endl;
        }
    }
    return 0;
}
