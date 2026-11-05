// from server: 50% by Intel
struct S {
    void* f();
};

void* S::f()
{
    void* v1 = *(void**)((char*)this + 0x10);
    void* v2 = *(void**)((char*)this + 0xC);
    return ((void* (__stdcall *)(void*))v2)(v1);
}
