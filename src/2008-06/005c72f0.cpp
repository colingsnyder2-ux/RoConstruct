// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    void* table1;
    void* table2;
    char padding[0x1c];
    Base(void*);
};

struct Tool : Base {
    Tool(void*);
};

__forceinline Tool::Tool(void* p) : Base(p) {
    table1 = (void*)0x8397f4;
    table2 = (void*)0x8397dc;
}

struct Context {
    char padding[0x204];
    void* value;
};

struct Obj {
    char padding[0xc];
    Context* context;
    Tool* f();
};

Tool* Obj::f() {
    return new Tool(context->value);
}
