// from server: 100% by tester
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context;

struct Tool {
    char storage[56];
    Tool(Context* context);
};

struct Verb {
    char padding[24];
    Context* context;
    Tool* create();
};

Tool* Verb::create()
{
    return new Tool(context);
}
