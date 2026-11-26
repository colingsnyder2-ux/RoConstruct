// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00777330  unit: RBX::VPartInstance::?$ActionStation  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00777330
//
// 00777330  837c240400           cmp dword ptr [esp + 4], 0
// 00777335  56                   push esi
// 00777336  8bf1                 mov esi, ecx
// 00777338  7414                 je 0x77734e
// 0077733a  c786840000008c13bb00 mov dword ptr [esi + 0x84], 0xbb138c
// 00777344  c786b80000008410bb00 mov dword ptr [esi + 0xb8], 0xbb1084
// 0077734e  6a00                 push 0
// 00777350  e86bfcffff           call 0x776fc0
// 00777355  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 0077735b  c7061401bb00         mov dword ptr [esi], 0xbb0114
// 00777361  c746040801bb00       mov dword ptr [esi + 4], 0xbb0108
// 00777368  c74618fc00bb00       mov dword ptr [esi + 0x18], 0xbb00fc
// 0077736f  c7461cf000bb00       mov dword ptr [esi + 0x1c], 0xbb00f0
// 00777376  c78680000000e800bb00 mov dword ptr [esi + 0x80], 0xbb00e8
// 00777380  c78690000000d000bb00 mov dword ptr [esi + 0x90], 0xbb00d0
// 0077738a  c7869c000000a400bb00 mov dword ptr [esi + 0x9c], 0xbb00a4
// 00777394  c786b40000007800bb00 mov dword ptr [esi + 0xb4], 0xbb0078
// 0077739e  c786c80000007000bb00 mov dword ptr [esi + 0xc8], 0xbb0070
// 007773a8  8b4804               mov ecx, dword ptr [eax + 4]
// 007773ab  c78431840000006800bb00 mov dword ptr [ecx + esi + 0x84], 0xbb0068
// 007773b6  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 007773bc  8b4204               mov eax, dword ptr [edx + 4]
// 007773bf  c784308000000000000000 mov dword ptr [eax + esi + 0x80], 0
// 007773ca  c786d802000000000000 mov dword ptr [esi + 0x2d8], 0
// 007773d4  c786dc02000000000000 mov dword ptr [esi + 0x2dc], 0
// 007773de  8bc6                 mov eax, esi
// 007773e0  5e                   pop esi
// 007773e1  c20400               ret 4

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
