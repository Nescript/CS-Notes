#include <iostream>
#include <vector>

using namespace std;

class Animal
{
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void speak() const = 0;
    virtual void eat() const = 0;
    virtual void display() const
    {
        cout << "Name: " << name << ", ";
        cout << "Age: " << age << ", ";
    }
    virtual ~Animal() 
    {
        cout << "~Animal: " << name << endl;
    }
};

class Lion : public Animal
{
private:
    int maneLength;
public:
    Lion(string n, int a, int len) : Animal(n, a), maneLength(len) {}
    void speak() const override
    {
        cout << name << " roars: ROAR!" << endl;
    }
    void eat() const override
    {
        cout << name << " eats meat" << endl;
    }
    void display() const override
    {
        Animal::display();
        cout << "Mane Length: " << maneLength << "cm" << endl;
    }
    ~Lion()
    {
        cout << "~Lion: " << name << endl;
    }
};

class Elephant : public Animal
{
private:
    double trunkLength;
public:
    Elephant(string n, int a, double tru) : Animal(n, a), trunkLength(tru) {}
    void speak() const override
    {
        cout << name << " trumpets: PAAAH!" << endl;
    }
    void eat() const override
    {
        cout << name << " eats grass and fruits" << endl;
    }
    void display() const override
    {
        Animal::display();
        cout << "Trunk Length: " << trunkLength << "m" <<endl;
    }
    ~Elephant()
    {
        cout << "~Elephant: " << name << endl;
    }
};

class Monkey : public Animal
{
private:
    bool canClimb;
public:
    Monkey(string n, int a, bool c) : Animal(n, a), canClimb(c) {}
    void speak() const override
    {
        cout << name <<" chatters: Ooh ooh ah ah!" << endl;
    }
    void eat() const override
    {
        cout << name << " eats bananas" << endl;
    }
    void display() const override
    {
        Animal::display();
        if (canClimb) cout << "Can Climb: Yes" << endl;
        else cout << " Can Climb: No" << endl;
    }
    ~Monkey()
    {
        cout << "~Monkey: " << name << endl;
    }
};

class Zoo
{
private:
    vector<Animal*> animals;
public:
    void addAnimal(Animal* a)
    {
        animals.push_back(a);
    }
    void showAllAnimals() const
    {
        for (vector<Animal*>::const_iterator iter = animals.begin(); iter != animals.end(); ++iter)
        {
            (*iter)->display();
        }//这段我不会，ai写的
    }
    void feedAllAnimals() const
    {
        for (vector<Animal*>::const_iterator iter = animals.begin(); iter != animals.end(); ++iter)
        {
            (*iter)->eat();
        }
    }
    void makeAllSpeak() const
    {
        for (vector<Animal*>::const_iterator iter = animals.begin(); iter != animals.end(); ++iter)
        {
            (*iter)->speak();
        }
    }
    ~Zoo() 
    {
        Animal* a;
        while (!animals.empty())
        {
            a = animals.back();
            animals.pop_back();
            delete a;
        }
    }
};

int main() {
    Zoo zoo;
    
    zoo.addAnimal(new Lion("Simba", 5, 20));
    zoo.addAnimal(new Elephant("Dumbo", 10, 2.5));
    zoo.addAnimal(new Monkey("George", 3, true));
    zoo.addAnimal(new Lion("Nala", 4, 15));
    
    cout << "=== All Animals ===" << endl;
    zoo.showAllAnimals();
    
    cout << "\n=== Feeding Time ===" << endl;
    zoo.feedAllAnimals();
    
    cout << "\n=== Make Some Noise ===" << endl;
    zoo.makeAllSpeak();
    
    cout << "\n=== Zoo Closing ===" << endl;
    
    return 0;
}