// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned int table1;
    unsigned int table2;
    char storage[64];
    Base(void*);
};

struct Object : Base {
    Object(void*);
};

inline Object::Object(void* p) : Base(p) {
    table1 = 0x839464;
    table2 = 0x83944c;
}

struct S {
    char padding[24];
    void* context;
    Object* f();
};

Object* S::f() {
    return new Object(context);
}
