// from server: 25% by colin
struct S_0045abd0 {
    char pad0[0x110];
    int m_field110;
    int m_field114;
    int m_field118;
    S_0045abd0* ctor(int);
};

extern "C" void __stdcall sub_0045aac0();
extern "C" void __stdcall sub_00459c20(int, int);

S_0045abd0* S_0045abd0::ctor(int arg)
{
    sub_0045aac0();
    *(int*)((char*)this + 0) = 0x79397c;
    *(int*)((char*)this + 4) = 0x793970;
    *(int*)((char*)this + 0x10) = 0x793968;
    *(int*)((char*)this + 0x14) = 0x793958;
    *(int*)((char*)this + 0x2c) = 0x793948;
    *(int*)((char*)this + 0x44) = 0x793938;
    *(int*)((char*)this + 0x5c) = 0x793928;
    *(int*)((char*)this + 0x74) = 0x793918;
    *(int*)((char*)this + 0x8c) = 0x793908;
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x114) = 0;
    *(int*)((char*)this + 0x118) = 0;
    sub_00459c20(0x5b9940, arg);
    return this;
}
