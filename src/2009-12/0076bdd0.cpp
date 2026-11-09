// from server: 31% by atomic.potato
struct VInstance {
    void* vfptr;
    char pad[0x18];
    void* field1c;
    void* field20;
    void* construct(int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_67eaf0();
extern "C" void* __stdcall sub_650c60();
extern "C" void __stdcall sub_662b90(void*, void*, void*, int, int, int, int);
extern "C" void* __stdcall sub_76b9f0(void*);
extern "C" void __stdcall sub_7f385a(void*);

void* VInstance::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    void* p1 = sub_67eaf0();
    void* p2 = sub_650c60();
    sub_662b90(this, p2, p1, a1, a2, a3, a4);
    void* tmp = 0;
    sub_76b9f0(&tmp);
    this->field20 = tmp;
    this->vfptr = (void*)0x9e7ffc;
    this->field1c = (void*)0x9e7ff4;
    sub_7f385a((void*)a5);

    return this;
}
