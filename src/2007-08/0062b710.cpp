// from server: 44% by colin
// roc 2007-08 0062b710  unit: RBX::GroupDragTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062b710
//
// 0062b710  dec1                 faddp st(1)
// 0062b712  d95c2418             fstp dword ptr [esp + 0x18]
// 0062b716  d88ea4000000         fmul dword ptr [esi + 0xa4]
// 0062b71c  d98698000000         fld dword ptr [esi + 0x98]
// 0062b722  deca                 fmulp st(2)
// 0062b724  dec1                 faddp st(1)
// 0062b726  d9868c000000         fld dword ptr [esi + 0x8c]
// 0062b72c  deca                 fmulp st(2)
// 0062b72e  dec1                 faddp st(1)
// 0062b730  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062b734  e8674de7ff           call 0x4a04a0
// 0062b739  d9442408             fld dword ptr [esp + 8]
// 0062b73d  d8642414             fsub dword ptr [esp + 0x14]
// 0062b741  d944240c             fld dword ptr [esp + 0xc]
// 0062b745  d8642418             fsub dword ptr [esp + 0x18]
// 0062b749  d9442410             fld dword ptr [esp + 0x10]
// 0062b74d  d864241c             fsub dword ptr [esp + 0x1c]
// 0062b751  dcc8                 fmul st(0), st(0)
// 0062b753  d9c1                 fld st(1)
// 0062b755  deca                 fmulp st(2)
// 0062b757  dec1                 faddp st(1)
// 0062b759  d9c1                 fld st(1)
// 0062b75b  5f                   pop edi
// 0062b75c  deca                 fmulp st(2)
// 0062b75e  5e                   pop esi
// 0062b75f  dec1                 faddp st(1)
// 0062b761  d9fa                 fsqrt 
// 0062b763  83c430               add esp, 0x30
// 0062b766  c3                   ret 

struct GroupDragTool {
    char pad0[0x8c];
    float field8c;
    char pad90[0x8];
    float field98;
    char pad9c[0x8];
    float fielda4;
    float func(float a, float b, float c, float d, float e, float f);
};

extern "C" void __cdecl sub_4a04a0();

float GroupDragTool::func(float a, float b, float c, float d, float e, float f)
{
    float t1 = c * this->fielda4;
    float t2 = b * this->field98 + t1;
    float t3 = a * this->field8c + t2;
    sub_4a04a0();
    float dx = a - d;
    float dy = b - e;
    float dz = c - f;
    return dx * dx + dy * dy + dz * dz;
}
