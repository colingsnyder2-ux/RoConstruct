// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct First {
    virtual void first();
};

struct Second {
    virtual void second();
};

struct Base : First, Second {
    char storage[0x28];
    Base(void*, int, int);
};

struct Tool : Base {
    Tool(void* p);
    virtual void first();
    virtual void second();
};

inline Tool::Tool(void* p) : Base(p, 1, 5) {}

struct Context {
    char padding[0x204];
    void* value;
};

struct S {
    char padding[0x0c];
    Context* context;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(context->value);
}
