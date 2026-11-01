// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned int words[18];
    Base(int);
};

struct Cursor : Base {
    Cursor(int);
};

inline Cursor::Cursor(int value) : Base(value) {
    words[0] = 0x008391bc;
    words[1] = 0x008391a0;
}

struct S {
    char padding[24];
    int value;
    Cursor* f();
};

Cursor* S::f() {
    return new Cursor(value);
}
