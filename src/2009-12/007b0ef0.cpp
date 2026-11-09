// from server: 68% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall target();

void S::f()
{
    char* p = *(char**)((char*)this + 0x34);
    if (*(unsigned char*)(p + 8))
        target();
}
