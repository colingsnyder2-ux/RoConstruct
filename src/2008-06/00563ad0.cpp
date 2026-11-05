// from server: 100% by king_originala
struct Base1 { int a; };
struct Base2 { int b; };
struct Object : Base1, Base2 {};

struct S {
    char padding[16];
    void (Object::*setter)(double);
    void f(void* object, const double& value);
};

void S::f(void* object, const double& value)
{
    Object* target = object
        ? reinterpret_cast<Object*>(static_cast<char*>(object) - 20)
        : 0;
    (target->*setter)(value);
}
