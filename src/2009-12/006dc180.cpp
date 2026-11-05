// from server: 82% by atomic.potato
typedef void (__cdecl *CallType)(void*, void*, void*, void*, void*);

struct S
{
    int f();
};

int S::f()
{
    void* p = *(void**)((char*)this + 0x148);
    if (p)
        ((CallType)0x7f4aaa)(p, 0, (void*)0xaffe40, (void*)0xb2f074, 0);
    return 0;
}
