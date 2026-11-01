// from server: 100% by colin
struct S_func_005971c0 {
    char pad0[0x110];
    int m_x;
    int f(int);
};

extern "C" void __fastcall sub_0045aac0(void*);

int S_func_005971c0::f(int a)
{
    sub_0045aac0(this);
    m_x = a;
    *(int*)((char*)this + 0x00) = 0x7b0fcc;
    *(int*)((char*)this + 0x04) = 0x7b0fc4;
    *(int*)((char*)this + 0x10) = 0x7b0fbc;
    *(int*)((char*)this + 0x14) = 0x7b0fac;
    *(int*)((char*)this + 0x2c) = 0x7b0f9c;
    *(int*)((char*)this + 0x44) = 0x7b0f8c;
    *(int*)((char*)this + 0x5c) = 0x7b0f7c;
    *(int*)((char*)this + 0x74) = 0x7b0f6c;
    *(int*)((char*)this + 0x8c) = 0x7b0f5c;
    return (int)this;
}
