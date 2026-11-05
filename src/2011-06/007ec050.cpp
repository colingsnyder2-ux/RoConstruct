// from server: 29% by atomic.potato
extern "C" int __cdecl sub_542780();
extern "C" void __cdecl sub_758D30(void*, void*);

struct Climbing {
    char pad[0x108];
    void* field_108;
    void f();
};

void Climbing::f()
{
    void* esi = field_108;
    int eax = sub_542780();
    int* ecx = *(int**)((char*)esi + 0x30);
    ecx = *(int**)((char*)ecx + 0x38);
    if (ecx != 0)
    {
        char* edi = (char*)this + 0x38;
        sub_758D30(edi, (void*)eax);
    }
}
