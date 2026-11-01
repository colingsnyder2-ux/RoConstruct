// from server: 97% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 00690e20  unit: RBX::VBodyGyro::?$FactoryProduct  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00690e20
//
// 00690e20  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 00690e23  56                   push esi
// 00690e24  8b7034               mov esi, dword ptr [eax + 0x34]
// 00690e27  85f6                 test esi, esi
// 00690e29  743d                 je 0x690e68
// 00690e2b  807e0800             cmp byte ptr [esi + 8], 0
// 00690e2f  7407                 je 0x690e38
// 00690e31  8bce                 mov ecx, esi
// 00690e33  e858880300           call 0x6c9690
// 00690e38  8b442408             mov eax, dword ptr [esp + 8]
// 00690e3c  d900                 fld dword ptr [eax]
// 00690e3e  d88684000000         fadd dword ptr [esi + 0x84]
// 00690e44  d99e84000000         fstp dword ptr [esi + 0x84]
// 00690e4a  d94004               fld dword ptr [eax + 4]
// 00690e4d  d88688000000         fadd dword ptr [esi + 0x88]
// 00690e53  d99e88000000         fstp dword ptr [esi + 0x88]
// 00690e59  d94008               fld dword ptr [eax + 8]
// 00690e5c  d8868c000000         fadd dword ptr [esi + 0x8c]
// 00690e62  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 00690e68  5e                   pop esi
// 00690e69  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 006060b0  unit: seg_00600000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006060b0
//
// 006060b0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006060b3  56                   push esi
// 006060b4  8b702c               mov esi, dword ptr [eax + 0x2c]
// 006060b7  85f6                 test esi, esi
// 006060b9  743d                 je 0x6060f8
// 006060bb  807e0800             cmp byte ptr [esi + 8], 0
// 006060bf  7407                 je 0x6060c8
// 006060c1  8bce                 mov ecx, esi
// 006060c3  e8582c0500           call 0x658d20
// 006060c8  8b442408             mov eax, dword ptr [esp + 8]
// 006060cc  d98690000000         fld dword ptr [esi + 0x90]
// 006060d2  d800                 fadd dword ptr [eax]
// 006060d4  d99e90000000         fstp dword ptr [esi + 0x90]
// 006060da  d94004               fld dword ptr [eax + 4]
// 006060dd  d88694000000         fadd dword ptr [esi + 0x94]
// 006060e3  d99e94000000         fstp dword ptr [esi + 0x94]
// 006060e9  d94008               fld dword ptr [eax + 8]
// 006060ec  d88698000000         fadd dword ptr [esi + 0x98]
// 006060f2  d99e98000000         fstp dword ptr [esi + 0x98]
// 006060f8  5e                   pop esi
// 006060f9  c20400               ret 4

struct Vector {
    float x, y, z;
};

struct Geometry {
    unsigned char pad0[8];
    unsigned char dirty;
    unsigned char pad1[0x7b];
    float x, y, z;

    void update();
};

struct Holder {
    unsigned char pad[0x34];
    Geometry *geometry;
};

struct S {
    unsigned char pad[0x2c];
    Holder *holder;

    void translate(const Vector &offset);
};

void S::translate(const Vector &offset)
{
    Geometry *g = holder->geometry;
    if (g) {
        if (g->dirty)
            g->update();
        g->x = offset.x + g->x;
        g->y = offset.y + g->y;
        g->z = offset.z + g->z;
    }
}
