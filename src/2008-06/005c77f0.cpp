// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context {
    char pad[0x204];
    void* value;
    __forceinline void* get();
};

__forceinline void* Context::get() {
    return value;
}

struct Tool {
    char storage[0x24];
    Tool(void*);
};

struct Verb {
    char pad[0x0c];
    Context* context;
    Tool* create();
};

Tool* Verb::create() {
    return new Tool(context->get());
}
