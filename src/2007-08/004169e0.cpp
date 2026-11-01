// from server: 79% by colin
struct VCLuaFunction {
    void f(int);
};

extern "C" void __cdecl sub_4166C0(int);
extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_4497A0(void*, int);

void VCLuaFunction::f(int a)
{
    unsigned int cap = *(unsigned int*)((char*)this + 8);
    unsigned int pos = *(unsigned int*)((char*)this + 0x10);
    if (cap <= pos + 1)
        sub_4166C0(1);

    unsigned int idx = *(unsigned int*)((char*)this + 0xc) + *(unsigned int*)((char*)this + 0x10);
    unsigned int c2 = *(unsigned int*)((char*)this + 8);
    if (c2 <= idx)
        idx -= c2;

    int* arr = *(int**)((char*)this + 4);
    if (arr[idx] == 0)
        arr[idx] = (int)sub_62FEF6(0xc);

    sub_4497A0((void*)arr[idx], a);
    *(unsigned int*)((char*)this + 0x10) += 1;
}
