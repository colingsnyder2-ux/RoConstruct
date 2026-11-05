// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct S_func_006159f0 {
    char data[28];
    int f(int a1);
};

struct Tool : S_func_006159f0 {
    char flag;
    char padding[3];
    Tool(int a1);
};

inline Tool::Tool(int a1)
{
    f(a1);
    flag = 0;
    *(int*)((char*)this + 0) = 0x8336a4;
    *(int*)((char*)this + 4) = 0x833688;
}

struct S {
    char padding[12];
    char* owner;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(*(int*)(owner + 0x204));
}
