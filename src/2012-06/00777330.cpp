// from server: 100% by tajop
struct S_func_00777330 {
    char pad0[132];
    int m_field84;
    char pad88[48];
    int m_fieldB8;
    char padBC[540];
    int m_field2D8;
    int m_field2DC;
    int f(int arg);
};

extern "C" int __stdcall sub_776FC0(int);
extern "C" char vb_BB138C[], vb_BB1084[];
extern "C" char vt_BB0114[], vt_BB0108[], vt_BB00FC[], vt_BB00F0[], vt_BB00E8[],
    vt_BB00D0[], vt_BB00A4[], vt_BB0078[], vt_BB0070[], vt_BB0068[];

int S_func_00777330::f(int arg)
{
    if (arg != 0) {
        m_field84 = (int)vb_BB138C;
        m_fieldB8 =(int)vb_BB1084;
    }
    sub_776FC0(0);
    int eax = m_field84;
    *(int*)this = (int)vt_BB0114;
    *(int*)((char*)this + 4) = (int)vt_BB0108;
    *(int*)((char*)this + 0x18) = (int)vt_BB00FC;
    *(int*)((char*)this + 0x1C) = (int)vt_BB00F0;
    *(int*)((char*)this + 0x80) = (int)vt_BB00E8;
    *(int*)((char*)this + 0x90) = (int)vt_BB00D0;
    *(int*)((char*)this + 0x9C) = (int)vt_BB00A4;
    *(int*)((char*)this + 0xB4) = (int)vt_BB0078;
    *(int*)((char*)this + 0xC8) = (int)vt_BB0070;
    int ecx = *(int*)(eax + 4);
    *(int*)((char*)this + ecx + 0x84) = (int)vt_BB0068;
    int edx = m_field84;
    int eax2 = *(int*)(edx + 4);
    *(int*)((char*)this + eax2 + 0x80) = 0;
    m_field2D8 = 0;
    m_field2DC = 0;
    return (int)this;
}
