// from server: 100% by atomic.potato
extern "C" void __cdecl sub_90cfe0(void*, int);
extern "C" void __cdecl sub_982114(void*);

struct S
{
    void f();
    void* field_00;
    void* field_04;
    void* field_08;
    void* field_0c;
};

void S::f()
{
    void* p = field_0c;
    if (p)
    {
        sub_90cfe0(p, *(int*)((char*)p + 0x14));
        sub_982114(p);
    }
}
