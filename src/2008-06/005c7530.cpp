// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char table1[];
extern char table2[];

struct Base {
    void* primary;
    void* secondary;
    char pad[0x1c];
    Base(void*);
};

struct Tool : Base {
    Tool(void* p) : Base(p) {
        primary = table1;
        secondary = table2;
    }
};

struct Context {
    char pad[0x204];
    void* value;
};

struct Verb {
    char pad[0x0c];
    Context* context;
    Tool* f();
};

Tool* Verb::f() {
    return new Tool(context->value);
}
