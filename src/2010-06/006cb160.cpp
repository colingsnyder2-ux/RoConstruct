// from server: 30% by atomic.potato
struct T;
typedef T* E;

struct Vec {
    E* first;
    Vec(E* p) { first = p; }
    void push_back(E v);
};

struct Inner {
    char pad[0x1bc];
    bool get(int i);
};

struct Outer {
    char pad0[4];
    Vec v;
    Inner inner;
    void f();
};

extern "C" void __stdcall ctor6206c0(Vec* self, E* p);
extern "C" void __stdcall ctor6206d0(Vec* self, E v);
extern "C" bool __stdcall get620a20(Inner* self, int i);

void Outer::f()
{
    Vec tmp(0);
    ctor6206c0(&tmp, 0);
    bool b0 = get620a20(&inner, 0);
    ctor6206d0(&tmp, (E)(unsigned char)b0);
    bool b1 = get620a20(&inner, 1);
    ctor6206d0(&tmp, (E)(unsigned char)b1);
    bool b2 = get620a20(&inner, 2);
    ctor6206d0(&tmp, (E)(unsigned char)b2);
}
