// from server: 100% by atomic.potato
struct S
{
    char pad[12];
    void* field0C;
    void f();
};

extern "C" void __cdecl sub_90e980(void*, unsigned long);
extern "C" void __cdecl sub_982114(void*);

void S::f()
{
    void* p = field0C;
    if (p != 0)
    {
        sub_90e980(p, *(unsigned long*)((char*)p + 0x0c));
        sub_982114(p);
    }
}
