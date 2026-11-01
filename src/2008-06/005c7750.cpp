// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Tool {
    char data[0x38];
    Tool(void*);
};

struct Context {
    char pad[0x204];
    void* value;
    __forceinline void* get();
};

__forceinline void* Context::get() {
    return value;
}

struct S {
    char pad[0x0c];
    Context* context;
    Tool* f();
};

Tool* S::f() {
    return new Tool(context->get());
}
