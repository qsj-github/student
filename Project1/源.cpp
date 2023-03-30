#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 定义学生类
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
    string name;  // 姓名
    int id;       // 学号
    int age;      // 年龄
};

// 定义学生管理类
class StudentManager {
public:
    // 添加学生
    void addStudent(string name, int id, int age) {
        Student student(name, id, age);
        students.push_back(student);
        cout << "添加学生成功！" << endl;
    }

    // 查询学生信息
    void queryStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                cout << "学生姓名：" << students[i].getName() << endl;
                cout << "学生学号：" << students[i].getId() << endl;
                cout << "学生年龄：" << students[i].getAge() << endl;
                return;
            }
        }
        cout << "未找到该学生！" << endl;
    }

    // 删除学生
    void deleteStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "删除成功！" << endl;
                return;
            }
        }
        cout << "未找到该学生！" << endl;
    }

private:
    vector<Student> students;  // 学生列表
};

// 主函数
int main() {
    StudentManager manager;
    int choice = 0;
    while (true) {
        cout << "请选择功能：" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 查询学生信息" << endl;
        cout << "3. 删除学生" << endl;
        cout << "4. 退出" << endl;
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, age;
            cout << "请输入学生姓名：" << endl;
            cin >> name;
            cout << "请输入学生学号：" << endl;
            cin >> id;
            cout << "请输入学生年龄：" << endl;
            cin >> age;
            manager.addStudent(name, id, age);
        }
        else if (choice == 2) {
            int id;
            cout << "请输入学生学号：" << endl;
            cin >> id;
            manager.queryStudent(id);
        }
        else if (choice == 3) {
            int id;
            cout << "请输入学生学号：" << endl;
            cin >> id;
            manager.deleteStudent(id);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "输入有误，请重新选择！" << endl;
        }
    }
    return 0;
}
