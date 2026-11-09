// from server: 100% by king_originala
struct FirstBase { char padding[20]; };
struct SecondBase { int value; };
struct Object : FirstBase, SecondBase {};

struct S {
    char padding[8];
    int (Object::*getter)();
    double f(SecondBase* object);
};

double S::f(SecondBase* object) {
    return (static_cast<Object*>(object)->*getter)();
}
