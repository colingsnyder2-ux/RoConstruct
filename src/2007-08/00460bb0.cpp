// from server: 64% by colin
struct S_00460bb0 {
    char pad[0x18];
    int field_18;
    void method(int, int);
};

extern "C" void __stdcall sub_0041d870(void*);
extern "C" void __stdcall sub_77d2f8(void*);

void S_00460bb0::method(int arg1, int arg2)
{
    int local;
    char flag;
    void* p = (void*)(field_18 + 0x2c);
    local = (int)p;
    flag = 0;
    sub_0041d870(&local);
    void (__thiscall *fn)(void*, int, int) = *(void (__thiscall **)(void*, int, int))((*(int*)this) + 0xc);
    fn(this, local, arg1);
    if (flag == 0) {
        sub_77d2f8((void*)local);
    }
}
