// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern unsigned int table0[];
extern unsigned int table1[];

struct Base {
    int f(int a1);
    char data[0x1c];
};

struct Tool : Base {
    int value;
    float x0, x1, x2, x3, x4, x5;
    Tool(int a1);
};

__forceinline Tool::Tool(int a1)
{
    f(a1);
    *(unsigned int* volatile*)((char*)this + 0) = table0;
    *(unsigned int* volatile*)((char*)this + 4) = table1;
    *(volatile int*)((char*)this + 0x1c) = 0;
    *(volatile float*)((char*)this + 0x20) = 0.0f;
    *(volatile float*)((char*)this + 0x24) = 0.0f;
    *(volatile float*)((char*)this + 0x28) = 0.0f;
    *(volatile float*)((char*)this + 0x2c) = 0.0f;
    *(volatile float*)((char*)this + 0x30) = 0.0f;
    *(volatile float*)((char*)this + 0x34) = 0.0f;
}

struct Context {
    char pad[0x204];
    int argument;
};

struct S {
    char pad[0xc];
    Context* context;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(context->argument);
}
