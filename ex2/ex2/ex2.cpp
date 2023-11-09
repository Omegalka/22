#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

#include "mobile_phone.h"
#include "human.h"
#include "weights.h"
#include "door.h"
#include "room.h"

class Logger
{
    static Logger* instance; // 1) приватный статический указатель на единственный экземпляр класса
    int log_сount = 0; // сколько раз происходила запись строки в файл
    string path = "C:/1/log.txt";

    Logger() // 2) конструктор - приватный (запрещает создавать объекты за пределами класса)
    {
    }

public:
    static Logger* GetInstance() // 3) публичный статический геттер на получение адреса единственного объекта
    {
        // если объекта журнала не существует - он создаётся
        return instance == nullptr ? instance = new Logger() : instance;
    }

    void Write(string message) // записать в журнал строку текста
    {
        log_сount++;
        cout << log_сount << ": " << message << "\n";
        // альтернативные варианты:
        // 1) записать строку в коллекцию (массив, список и тд) и хранить данные в памяти
        // 2) записать строку в файл
        ofstream output_file(path, ios::app);
        if (output_file.is_open())
        {
            output_file << message << "\n";
            output_file.close();
            //cout << "Строка успешно записана в файл.";
        }
        else
        {
            //cerr << "Не удалось открыть файл для записи.";
        }
        // 3) отправлять данные по сети
    }

    void Write(int value)
    {
        Write(to_string(value));
    }
};

Logger* Logger::instance = nullptr;

/// <summary>
/// class Student
/// </summary>
class Student {
private:
    string name;
    string surname;
    string fathname;
    string homeadress;
    string phone_number;

    // практика за 11 октября
    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practask_rates = nullptr;
    int practask_rates_count = 0;

    int* examtask_rates = nullptr;
    int examtask_rates_count = 0;

public:
    /// <summary>
    /// а method that allows you to change a student's name
    /// </summary>
    /// <param name="name">some new value for student name</param>
    void SetName(string name)
    {
        this->name = name;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetName() const
    {
        return name;
    }
    /// <summary>
    /// а method that allows you to change a student's surname
    /// </summary>
    /// <param name="surname">some new value for student surname</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }
    /// <summary>
    /// а method that allows you to change a student's father`s name
    /// </summary>
    /// <param name="fathname">some new value for student father`s name</param>
    void SetFathname(string fathname)
    {
        this->fathname = fathname;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetFathname() const
    {
        return fathname;
    }
    /// <summary>
    /// а method that allows you to change a student`s home adress
    /// </summary>
    /// <param name="homeadress">some new value for student home adress</param>
    void SetHomeAdress(string homeadress)
    {
        this->homeadress = homeadress;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GethomeAdress() const
    {
        return homeadress;
    }
    /// <summary>
    /// а method that allows you to change a student`s phone number
    /// </summary>
    /// <param name="phone_number">some new value for student phone number</param>
    void SetPhoneNumber(string phone_number)
    {
        this->phone_number = phone_number;
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const
    {
        return phone_number;
    }

    Student()
    {
        SetName("Alexey");
        SetSurname("Kosmolenko");
        SetFathname("Denisovich");
        SetHomeAdress("Blicker street 325a");  
        SetPhoneNumber("+1439430493049");

        Logger::GetInstance()->Write("student created" + name);
    } 
    
    Student(string name) : Student("Alexey", "Kosmolenko","Denisovich","Blicker street 325a","+1 439 4930 49"){}

    Student(string name, string surname, string fathname, string home_adress, string phone_number) {
        
        Logger::GetInstance()->Write("student deleted" + name);
        SetName(name);
        SetSurname(surname);
        SetFathname(fathname);
        SetHomeAdress(home_adress);
        SetPhoneNumber(phone_number);
    }
    /// <summary>
    /// Defines a destructor for the class Student
    /// </summary>
    ~Student() {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practask_rates != nullptr)
        {
            delete[] practask_rates;
            practask_rates = nullptr;
        }
        if (examtask_rates != nullptr)
        {
            delete[] examtask_rates;
            examtask_rates = nullptr;
        }

    }
    /// <summary>
    /// This method involves adding a grade to the student's homework grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddHometaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++) {
                temp[i] = hometask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }
    int* GetHometaskRates() const
    {
        return hometask_rates;
    }
    int GetHometaskRatesCount() const
    {
        return hometask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s hometask
    /// </summary>
    void PrintHometaskRates()
    {
        for (int i = 0; i < hometask_rates_count; i++) {
            cout << i + 1 << hometask_rates[i] << "\n";
        }
    }
    /// <summary>
    /// This method involves adding a grade to the student's practice grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddPractaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (practask_rates_count == 0)
        {
            practask_rates = new int[1];
            practask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[practask_rates_count + 1];
            for (int i = 0; i < practask_rates_count; i++) {
                temp[i] = practask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] practask_rates;
            practask_rates = temp;
        }
        practask_rates_count++;
    }
    int* GetPractaskRates() const
    {
        return practask_rates;
    }
    int GetPractaskRatesCount() const
    {
        return practask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s practice
    /// </summary>
    void PrintPractaskRates()
    {
        for (int i = 0; i < practask_rates_count; i++) {
            cout << i + 1 << practask_rates[i] << "\n";
        }
    }
    /// <summary>
    /// This method involves adding a grade to the student's exam grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddExamtaskRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "No\n";
            throw "error";
        }
        if (examtask_rates_count == 0)
        {
            examtask_rates = new int[1];
            examtask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[examtask_rates_count + 1];
            for (int i = 0; i < examtask_rates_count; i++) {
                temp[i] = examtask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] examtask_rates;
            examtask_rates = temp;
        }
        examtask_rates_count++;
    }
    int* GetExamtaskRates() const
    {
        return examtask_rates;
    }
    int GetExamtaskRatesCount() const
    {
        return examtask_rates_count;
    }
    /// <summary>
    /// show grades for the student`s exam`s
    /// </summary>
    void PrintExamtaskRates()
    {
        for (int i = 0; i < examtask_rates_count; i++) {
            cout << i + 1 << examtask_rates[i] << "\n";
        }
    }
};
/// <summary>
/// class name DateTime
/// </summary>
class DateTime
{
private:
    int day;
    int month;

public:
    /// <summary>
    /// а method that allows you to set day 
    /// </summary>
    /// <param name="day">value from 1 to 31</param> 
    void SetDay(int day)
    {
        if (day >= 1 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            cout << "No\n";
        }
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int GetDay() const
    {
        return day;
    }
    /// <summary>
    /// a method that allows you to set month
    /// </summary>
    /// <param name="month">value from 1 to 12</param>
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "No\n";
        }
    }
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int GetMonth() const
    {
        return month;
    }

    DateTime(int day) : DateTime(day, month){}

    DateTime(int day, int month) {
        SetDay(day);
        SetMonth(month);
    }
    
};
class Group
{
    Student** students = nullptr;
    int student_count = 0;
    string group_name;
    string specializ;
    int course;

public:
    Group()
    {
        SetGroupName(group_name);
        SetSpecializ(specializ);
        SetCourseNumber(course);

        Logger::GetInstance()->Write("group created" + group_name);
    }

    Group(const Group& field) //конструктор копирования
    {
        Logger::GetInstance()->Write("group deleted" + group_name);
        this->student_count = field.student_count;
        this->group_name = field.group_name;
        this->specializ = field.specializ;
        this->course = field.course;
        this->students = new Student * [this->student_count];
        for(int i = 0; i < this->student_count; i++)
        {
            this->students[i] = field.students[i];
        }
    }

    ~Group()
    {
        if (students != nullptr)
        {
            for (int i = 0; i < student_count; i++)
            {
                delete students[i];
            }
            delete[] students;
        }
    }

    void SetStudentCount(int student_count)
    {
        if (student_count > 0)
        {
            this->student_count = student_count;
        }
        else
        {
            cout << "No\n";
        }
    }
    int GetStudentCount() const
    {
        return student_count;
    }
    
    void SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }
    string GetGroupName() const
    {
        return group_name;
    }

    void SetSpecializ(string specializ)
    {
        this->specializ = specializ;
    }
    string GetSpecializ() const
    {
        return specializ;
    }

    void SetCourseNumber(int course)
    {
        this->course = course;
    }
    int GetCourseNumber() const
    {
        return course;
    }

    int StudentCount() const
    {
        return student_count;
    }

    Student GetStudent(int index) const
    {
        if (index < student_count)
        {
            return *students[index];
        }
        else
        {
            cout << "No\n";
        }
    }

    void AddStudent(const Student& new_student)
    {
        Student** temp = new Student * [student_count + 1];
        for (int i = 0; i < student_count; i++)
        {
            temp[i] = new Student(*students[i]);
        }
        temp[student_count] = new Student(new_student);
        delete[] students;
        students = temp;
        student_count++;
        
        /*if (student_count < 16)
        {
            cout << "To many students!\n";
            throw "Error";
        }*/
    }

    void RemoveStudent()
    {
        if (student_count == 0)
        {
            
            cout << "Where are students?\n";
            return;
        }
        int minidex = 0;
        int lowaverage = students[0]->GetHometaskRatesCount();
        for (int i = 1; i < student_count; i++)
        {
            int nowaverage = students[i]->GetHometaskRatesCount();
            if (nowaverage < lowaverage)
            {
                lowaverage = nowaverage;
                minidex = i;
            }
        }
        for (int i = minidex; i < student_count - 1; i++)
        {
            students[i] = students[i + 1];
        }
        student_count--;
    }

    void MergeWithGroup(Group& another_group)
    {
        for (int i = 0; i < another_group.StudentCount(); i++)
        {
            this->AddStudent(another_group.GetStudent(i));
        }

        int k = another_group.StudentCount();
        for (int i = 0; i < k; i++)
        {
            another_group.RemoveStudent();
        }
    }
        
    void GoStudent(Group& another, int index)
    {
        if (index >= 0 && index < student_count)
        {
            another.AddStudent(*students[index]);
            for (int i = index; i < student_count - 1; i++)
            {
                students[i] = students[i + 1];
            }
            student_count--;
        }
    }
};

class Application {

private:
    static Application* instance;
    string title;

    Application() {
        
    }

public:

    static Application* GetInstance() {
        if (instance == nullptr) {
            instance = new Application();
        }
        return instance;
    }

    void SetTitle(const string& newTitle) {
        this->title = newTitle;
    }

    void StartRandomize() {

        cout << "Randomize started\n";
    }

    void Exit() {

        cout << "Exiting the application\n";
        delete instance;
        instance = nullptr;
    }

    void ClearScreen() {
        
        cout << "Clearing the screen";
    }

    void SetTextColor(int colorcode) {
        
        cout << "Setting text color to " << colorcode << "\n";
    }

    void Run() {

        cout << "Running the application: " << title << "\n";
    }
};


Application* Application::instance = nullptr;


int main()
{
    string UserName = "anon";
    Group g;
    Logger::GetInstance()->Write("User " + UserName + " add students to group");

    Student* student1 = new Student(" Student1");
    Student* student2 = new Student(" Student2");

    delete student1;
    delete student2;

    Logger::GetInstance()->Write("User " + UserName + " close app");





    /*s.AddHometaskRate(12);
    s.AddHometaskRate(6);
    s.AddHometaskRate(1);
    s.AddHometaskRate(8);
    s.PrintHometaskRates();

    s.AddPractaskRate(12);
    s.AddPractaskRate(5);
    s.AddPractaskRate(3);
    s.AddPractaskRate(8);
    s.PrintPractaskRates();*/



    /*Application* app = Application::GetInstance();
    app->SetTitle("My Console App");

    app->StartRandomize();
    app->SetTextColor(2);
    app->Run();
    app->ClearScreen();

    Application* anotherApp = Application::GetInstance(); 
    anotherApp->Run();*/

    

    /*Group g;

    g.SetGroupName("Group");
    g.SetSpecializ("Programmers");
    g.SetCourseNumber(3);

    for (int i = 0; i < 15; i++)
    {
        Student s("Vasylij");

        for (int ht = 0; ht < 5; ht++)
            s.AddHometaskRate(rand() % 12 + 1);

        g.AddStudent(s);

    }
    Group g1;

    g1.SetGroupName("Group1");
    g1.SetSpecializ("Designers");
    g1.SetCourseNumber(3);

    for (int i = 0; i < 15; i++)
    {
        Student s("Sasha");

        for (int ht = 0; ht < 5; ht++)
            s.AddHometaskRate(rand() % 12 + 1);

        g.AddStudent(s);

    }
    g.MergeWithGroup(g1);*/
}




