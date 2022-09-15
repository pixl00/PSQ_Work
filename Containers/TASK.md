# Templates & Containers

This assignment is about a C++ tool that is very handy. Templates! It is a code generation tool, This means that we can make a function or class that is very general but can handle different types. It looks something like this. 

```
// First we say that this function or class is a template
// then we add the name for the type in this case T this is the type we put into the function when we call it
template<class T>
T Add( T n1, T n2)
{
    return ( n1 + n2 );
    // This function depends on that the + operator exists
    // Try to make templates that utilizes as little operators as possible
    // Since we can put whatever type we want into this function
    // As soon as you use a operator you have to be certain it exists
}

int main()
{
    int Res = Add<int>(4,6);
    //Res becomes 10;
}


```

What if we now have our own class and try to use Add for that type?
In this case if we do not implement the + operator it will just get compiler errors.

```
template<class T>
T Add( T n1, T n2)
{
    return ( n1 + n2 );
}

class Player
{
public:
    Player() {};
    ~Player() {};

    void SetScore(int _Score) { m_Score = _Score; };

private:
    int m_Score = 0;
};

int main()
{
    Player p1;
    Player p2;
    
    p1.m_Score = 5;
    p2.m_Score = 3;

    int Res = Add<Player>(p1,p2);
    //Compiler error! No + operator defined for Player
}


```
Another feature of C++ is operator overloading which means that almost all of the C++ operators can be overloaded or function in a different way than standard.
This is very useful for our own classes. To make our Add function work we define the + operator. It looks like this.

```
class Player
{
public:
    Player() {};
    ~Player() {};

    void SetScore(int _Score) { m_Score = _Score; };

Player operator+(const Player& other_player) { m_Score += other_player.m_Score; return *this; } 

//How the operators body looks or what it does it always up to you! In this case a Player might not make perfect sense to use + on. But we can define it with custom behaviour in this case the + operator takes the score of both Player instances and adds them.
private:
    int m_Score = 0;
};
```

## Task 1
Create a templated class called **ScopedPointer** this should keep a pointer to a T and have overloaded ->, * operators. So we can access the pointer and dereference it to get data. The class should allocate a T on the heap and deallocate it when a ScopedPointer instance goes out of scope.

```
class ScopedPointer;
int main()
{
    // Allocates a Player pointer on heap
    ScopedPointer<Player> PlayerPointer;

    // Game code goes here!

} // When we leave the scope of main the ScopedPointer needs to deallocate the pointer using delete.
```

## Task 2
Create a colletion of People they should have:
* Name
* Age
* Personnumber (Unique)
* Pets (Can be multiple)
* House address
* Email address (Unique)

All of this data should be random and I want you to generate a couple of them and add them to a collection that makes sense. std::vector, std::map are examples. Think of why you are using the type of collection. 

Make it possible to find these people based on data. Make it so I can choose what I want to search for and show me the people that apply to what I entered.

## Extra task
Look up how a std::vector works and try to implement it as closely as you can!

## Extra Extra task
Create replicas of the STL smart pointes.

