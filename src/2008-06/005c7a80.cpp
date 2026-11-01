// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual void first();
};

struct Secondary {
    virtual void second();
};

struct Base : Primary, Secondary {
    char storage[40];
    Base(int, int, int);
};

struct Product : Base {
    Product(int);
    virtual void first();
    virtual void second();
};

inline Product::Product(int value) : Base(value, 1, 5) {
}

struct SlingshotTool {
    char padding[0x18];
    int value;
    Product* func();
};

Product* SlingshotTool::func() {
    return new Product(value);
}
