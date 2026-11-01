// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct First {
    virtual void first();
};

struct Second {
    virtual void second();
};

struct Base : First, Second {
    char padding[28];
    Base(void*);
};

struct Tool : Base {
    bool state;
    Tool(void*);
    virtual void first();
    virtual void second();
};

inline Tool::Tool(void* p) : Base(p), state(false) {}

struct Context {
    char padding[0x204];
    void* value;
};

struct Verb {
    char padding[0x0c];
    Context* context;
    Tool* create();
};

Tool* Verb::create()
{
    return new Tool(context->value);
}
