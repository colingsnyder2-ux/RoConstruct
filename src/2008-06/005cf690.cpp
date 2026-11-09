// from server: 100% by king_originala
struct __multiple_inheritance Object;
typedef void (Object::*Setter)(int);

struct S {
    char padding[8];
    Setter setter;
    void f(char* object, int value);
};

void S::f(char* object, int value)
{
    Object* target = reinterpret_cast<Object*>(object ? object - 20 : 0);
    (target->*setter)(value);
}
