// from server: 100% by king_originala
struct Object {
    typedef void (__thiscall *Method)(Object*, int, int, int, int);
    Method* table;
};

struct S {
    char padding[0x2d50];
    Object* object;
    int first;
    int second;

    void f();
    void finish(int);
};

void S::f()
{
    if (object)
        object->table[25](object, first, second, 1, 0);
    finish(0);
}
