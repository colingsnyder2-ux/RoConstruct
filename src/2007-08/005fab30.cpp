// from server: 60% by colin
struct S_func_005fab30
{
    char pad0[0xc];
    int m_fieldc;
    char pad10[0x284];
    int m_field294;
    char pad298[0x40];
    int m_field2d8;
    char pad2dc[0x10];
    int m_fieldec;
    int f(int a);
};

extern "C" void __stdcall sub_005fa030();
extern "C" void* __cdecl sub_00591370();

int S_func_005fab30::f(int a)
{
    int* p = (int*)m_field2d8;
    m_field294 = 0x7a4cac;
    int* q = (int*)p[1];
    *(int*)((char*)q + (int)this + 0x298) = 0x7a4ca4;
    sub_005fa030();
    int* r = (int*)m_fieldec;
    *(int*)((char*)this + 0) = 0x7c2094;
    *(int*)((char*)this + 4) = 0x7c2088;
    *(int*)((char*)this + 0x10) = 0x7c2080;
    *(int*)((char*)this + 0x14) = 0x7c2070;
    *(int*)((char*)this + 0x2c) = 0x7c2060;
    *(int*)((char*)this + 0x44) = 0x7c2050;
    *(int*)((char*)this + 0x5c) = 0x7c2040;
    *(int*)((char*)this + 0x74) = 0x7c2030;
    *(int*)((char*)this + 0x8c) = 0x7c2020;
    *(int*)((char*)this + 0xe8) = 0x7c2014;
    *(int*)((char*)this + 0x158) = 0x7c2004;
    *(int*)((char*)this + 0x170) = 0x7c1ff8;
    *(int*)((char*)this + 0x17c) = 0x7c1fe0;
    int* s = (int*)r[1];
    *(int*)((char*)s + (int)this + 0xec) = 0x7c1fd4;
    int* t = (int*)m_fieldec;
    int* u = (int*)t[2];
    *(int*)((char*)u + (int)this + 0xec) = 0x7c1fcc;
    int* v = (int*)m_fieldec;
    int* w = (int*)v[3];
    *(int*)((char*)w + (int)this + 0xec) = 0x7c1fb0;
    int* x = (int*)m_fieldec;
    int* y = (int*)x[1];
    int z = (int)y - 0x198;
    *(int*)((char*)y + (int)this + 0xe8) = z;
    int* aa = (int*)m_fieldec;
    int* ab = (int*)aa[2];
    int ac = (int)ab - 0x1a0;
    *(int*)((char*)ab + (int)this + 0xe8) = ac;
    int* ad = (int*)m_fieldec;
    int* ae = (int*)ad[3];
    int af = (int)ae - 0x1a8;
    *(int*)((char*)ae + (int)this + 0xe8) = af;
    m_fieldc = (int)sub_00591370();
    return (int)this;
}
