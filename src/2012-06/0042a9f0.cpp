// from server: 100% by Xemicl
// roc 2012-06 0042a9f0  unit: CEnabledCmdUI  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a9f0
//
// 0042a9f0  53                   push ebx
// 0042a9f1  56                   push esi
// 0042a9f2  57                   push edi
// 0042a9f3  8bf1                 mov esi, ecx
// 0042a9f5  e8662e5900           call 0x9bd860
// 0042a9fa  6a0f                 push 0xf
// 0042a9fc  8bc8                 mov ecx, eax
// 0042a9fe  e8dd255900           call 0x9bcfe0
// 0042aa03  8bd8                 mov ebx, eax
// 0042aa05  e8562e5900           call 0x9bd860
// 0042aa0a  6a0d                 push 0xd
// 0042aa0c  8bc8                 mov ecx, eax
// 0042aa0e  e8cd255900           call 0x9bcfe0
// 0042aa13  8bc8                 mov ecx, eax
// 0042aa15  c1e810               shr eax, 0x10
// 0042aa18  0fb6c0               movzx eax, al
// 0042aa1b  8bd3                 mov edx, ebx
// 0042aa1d  c1ea10               shr edx, 0x10
// 0042aa20  0fb6d2               movzx edx, dl
// 0042aa23  03c2                 add eax, edx
// 0042aa25  99                   cdq 
// 0042aa26  2bc2                 sub eax, edx
// 0042aa28  d1f8                 sar eax, 1
// 0042aa2a  0fb6f8               movzx edi, al
// 0042aa2d  8bc1                 mov eax, ecx
// 0042aa2f  c1e808               shr eax, 8
// 0042aa32  0fb6c0               movzx eax, al
// 0042aa35  8bd3                 mov edx, ebx
// 0042aa37  c1ea08               shr edx, 8
// 0042aa3a  0fb6d2               movzx edx, dl
// 0042aa3d  03c2                 add eax, edx
// 0042aa3f  99                   cdq 
// 0042aa40  2bc2                 sub eax, edx
// 0042aa42  d1f8                 sar eax, 1
// 0042aa44  0fb6c0               movzx eax, al
// 0042aa47  c1e708               shl edi, 8
// 0042aa4a  0bf8                 or edi, eax
// 0042aa4c  0fb6c9               movzx ecx, cl
// 0042aa4f  0fb6c3               movzx eax, bl
// 0042aa52  03c1                 add eax, ecx
// 0042aa54  99                   cdq 
// 0042aa55  2bc2                 sub eax, edx
// 0042aa57  d1f8                 sar eax, 1
// 0042aa59  0fb6d0               movzx edx, al
// 0042aa5c  c1e708               shl edi, 8
// 0042aa5f  0bfa                 or edi, edx
// 0042aa61  57                   push edi
// 0042aa62  6a0f                 push 0xf
// 0042aa64  e8f72d5900           call 0x9bd860
// 0042aa69  8bc8                 mov ecx, eax
// 0042aa6b  e8d0275900           call 0x9bd240
// 0042aa70  8bce                 mov ecx, esi
// 0042aa72  e839fbffff           call 0x42a5b0
// 0042aa77  53                   push ebx
// 0042aa78  6a0f                 push 0xf
// 0042aa7a  e8e12d5900           call 0x9bd860
// 0042aa7f  8bc8                 mov ecx, eax
// 0042aa81  e8ba275900           call 0x9bd240
// 0042aa86  5f                   pop edi
// 0042aa87  5e                   pop esi
// 0042aa88  5b                   pop ebx
// 0042aa89  c3                   ret 
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