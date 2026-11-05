// from server: 51% by atomic.potato
struct S_func_0042a8a0 {
    char pad0[0x108];
    char m_flag108;
    char pad1[0x2e7];
    char m_field3f0;
    char pad2[0x9b];
    char m_field28c;
    char pad3[0x5f];
    int m_field_ec;
    char pad4[0x50];
    char m_field140;
    void f();
};

extern "C" int __stdcall sub_853730(int, int, int);
extern "C" int __stdcall sub_8541c0(int);
extern "C" int __stdcall sub_852010(int);
extern "C" int __stdcall sub_7f3b48(int, int);
extern "C" int __stdcall sub_858e70(int, int);
extern "C" int __stdcall sub_816a70(int);
extern "C" int __stdcall sub_838640(int);
extern "C" int __stdcall sub_98de80(int, int);
extern "C" int __stdcall sub_429710(int, int, int);
extern "C" int __stdcall sub_42a850(int);

void S_func_0042a8a0::f()
{
    if (m_flag108 != 0)
        return;
    int local8 = 0;
    int localc = 0;
    sub_853730(0, (int)&localc, 0x9a4494);
    if (sub_8541c0((int)&local8) != 0) {
        sub_429710((int)this, (int)&local8, 1);
        int r = sub_98de80((int)((char*)this + 0x10c), 1);
        sub_852010(r);
    }
    sub_7f3b48((int)((char*)this + 0x3f0), 0);
    sub_858e70((int)((char*)this + 0x28c), 0);
    sub_816a70(m_field_ec);
    sub_838640((int)((char*)this + 0x140));
    void** vt = *(void***)this;
    int (*fn)(void*, int) = (int (*)(void*, int))vt[0x158 / 4];
    fn(this, 1);
    m_flag108 = 1;
    sub_42a850((int)&local8);
}
