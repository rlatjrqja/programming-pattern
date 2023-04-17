#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "동물 : 응애 (동물이 생성됐습니다)" << endl;
    }
    virtual ~Animal()
    {
        cout << "동물 : ... (동물이 죽었습니다)" << endl;
    }
    virtual void Talk()
    {
        cout << "동물 : (동물이 울고 있습니다)" << endl;
    }

private:

};

class Hamster : public Animal
{
public:
    Hamster() 
    {
        cout << "햄스터 : 찍찍 (햄스터가 생성됐습니다)" << endl;
    }
    ~Hamster()
    {
        cout << "햄스터 : 찌이익... (햄스터가 죽었습니다)" << endl;
    }
    void Talk()
    {
        cout << "햄스터 : (햄스터가 울고 있습니다)" << endl;
    }

private:

};

class Cat : public Animal
{
public:
    int age;

    Cat()
    {
        cout << "고양이 : 야옹 (고양이가 생성됐습니다)" << endl;
    }
    ~Cat()
    {
        cout << "고양이 : 으악 (고양이가 죽었습니다)" << endl;
    }
    void Talk()
    {
        cout << "고양이 : (고양이가 울고 있습니다)" << endl;
    }
};

class Tiger : public Animal
{
public:
    Tiger()
    {
        cout << "호랑이 : 어흥 (호랑이가 생성됐습니다)" << endl;
    };
    ~Tiger()
    {
        cout << "호랑이 : 으아악 (호랑이가 죽었습니다)" << endl;
    };
    void Talk()
    {
        cout << "호랑이 : (호랑이가 울고 있습니다)" << endl;
    }

private:

};

int main()
{

    // # 예제2
    /*
    cout << "고양이에 대해 공부를 시작합니다." << endl;
    cout << endl;
    Animal* cat = new Tiger();
    cat->Talk();
    Tiger* tiger = (Tiger*)cat;
    tiger->Talk();
    tiger->Talk();
    delete(tiger);
    */



    // # 예제1
    /*
    Cat *A, *B;
    A = new Cat();
    B = new Cat();
    A->age = 2;
    B->age = 7;
    A = B;
    B->age++;
    cout << A->age + ", " + B->age << endl;
    */



    // # 예제3
    int AnimalNum = 3;
    Animal** ani = new Animal * [AnimalNum];

    ani[0] = new Tiger();
    ani[1] = new Cat();
    ani[2] = new Hamster();

    for (size_t i =0; i < AnimalNum; i++)
    {
        ani[i]->Talk();
        delete(ani[i]);
    }
}