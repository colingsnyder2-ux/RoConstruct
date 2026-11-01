// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct NewNullTool {
    char storage[0x1c];
    NewNullTool(void*);
};

struct Context {
    char pad[0x204];
    void* value;
    void* getValue();
};

__forceinline void* Context::getValue() {
    return value;
}

struct ToolVerb {
    char pad[0xc];
    Context* context;
    NewNullTool* f();
};

NewNullTool* ToolVerb::f() {
    return new NewNullTool(context->getValue());
}
