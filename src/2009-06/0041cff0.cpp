// from server: 100% by EspClaude
// roc 2009-06 0041cff0  unit: CEnabledCmdUI  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cff0
//
// 0041cff0  53                   push ebx
// 0041cff1  56                   push esi
// 0041cff2  57                   push edi
// 0041cff3  8bf1                 mov esi, ecx
// 0041cff5  e8267b3300           call 0x754b20
// 0041cffa  6a0f                 push 0xf
// 0041cffc  8bc8                 mov ecx, eax
// 0041cffe  e89d723300           call 0x7542a0
// 0041d003  8bd8                 mov ebx, eax
// 0041d005  e8167b3300           call 0x754b20
// 0041d00a  6a0d                 push 0xd
// 0041d00c  8bc8                 mov ecx, eax
// 0041d00e  e88d723300           call 0x7542a0
// 0041d013  8bc8                 mov ecx, eax
// 0041d015  c1e810               shr eax, 0x10
// 0041d018  0fb6c0               movzx eax, al
// 0041d01b  8bd3                 mov edx, ebx
// 0041d01d  c1ea10               shr edx, 0x10
// 0041d020  0fb6d2               movzx edx, dl
// 0041d023  03c2                 add eax, edx
// 0041d025  99                   cdq 
// 0041d026  2bc2                 sub eax, edx
// 0041d028  d1f8                 sar eax, 1
// 0041d02a  0fb6f8               movzx edi, al
// 0041d02d  8bc1                 mov eax, ecx
// 0041d02f  c1e808               shr eax, 8
// 0041d032  0fb6c0               movzx eax, al
// 0041d035  8bd3                 mov edx, ebx
// 0041d037  c1ea08               shr edx, 8
// 0041d03a  0fb6d2               movzx edx, dl
// 0041d03d  03c2                 add eax, edx
// 0041d03f  99                   cdq 
// 0041d040  2bc2                 sub eax, edx
// 0041d042  d1f8                 sar eax, 1
// 0041d044  0fb6c0               movzx eax, al
// 0041d047  c1e708               shl edi, 8
// 0041d04a  0bf8                 or edi, eax
// 0041d04c  0fb6c9               movzx ecx, cl
// 0041d04f  0fb6c3               movzx eax, bl
// 0041d052  03c1                 add eax, ecx
// 0041d054  99                   cdq 
// 0041d055  2bc2                 sub eax, edx
// 0041d057  d1f8                 sar eax, 1
// 0041d059  0fb6d0               movzx edx, al
// 0041d05c  c1e708               shl edi, 8
// 0041d05f  0bfa                 or edi, edx
// 0041d061  57                   push edi
// 0041d062  6a0f                 push 0xf
// 0041d064  e8b77a3300           call 0x754b20
// 0041d069  8bc8                 mov ecx, eax
// 0041d06b  e890743300           call 0x754500
// 0041d070  8bce                 mov ecx, esi
// 0041d072  e8e9faffff           call 0x41cb60
// 0041d077  53                   push ebx
// 0041d078  6a0f                 push 0xf
// 0041d07a  e8a17a3300           call 0x754b20
// 0041d07f  8bc8                 mov ecx, eax
// 0041d081  e87a743300           call 0x754500
// 0041d086  5f                   pop edi
// 0041d087  5e                   pop esi
// 0041d088  5b                   pop ebx
// 0041d089  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000080@@QAEXXZ)

namespace ns_ROCX000080 {
typedef unsigned long Color;

struct ColorManager
{
    Color GetColor(int index);
    void SetColor(int index, Color color);
};

ColorManager* __cdecl GetColorManager();

struct S
{
    void f();
    void draw();
};

void S::f()
{
    ColorManager* manager = GetColorManager();
    Color oldColor = manager->GetColor(15);
    manager = GetColorManager();
    Color otherColor = manager->GetColor(13);

    unsigned int mixed = (unsigned char)(
        ((unsigned char)(otherColor >> 16) +
         (unsigned char)(oldColor >> 16)) / 2);

    mixed = (mixed << 8) | (unsigned char)(
        ((unsigned char)(otherColor >> 8) +
         (unsigned char)(oldColor >> 8)) / 2);

    mixed = (mixed << 8) | (unsigned char)(
        ((unsigned char)otherColor + (unsigned char)oldColor) / 2);

    GetColorManager()->SetColor(15, mixed);
    draw();
    GetColorManager()->SetColor(15, oldColor);
}
}
