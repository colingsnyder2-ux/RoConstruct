// from server: 100% by Yeetserama
// roc 2010-06 008ebcf0  unit: seg_008e0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ebcf0
//
// 008ebcf0  d905549aa800         fld dword ptr [0xa89a54]
// 008ebcf6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008ebcfa  8b542418             mov edx, dword ptr [esp + 0x18]
// 008ebcfe  83ec08               sub esp, 8
// 008ebd01  d95c2404             fstp dword ptr [esp + 4]
// 008ebd05  d9ee                 fldz 
// 008ebd07  d91c24               fstp dword ptr [esp]
// 008ebd0a  d944241c             fld dword ptr [esp + 0x1c]
// 008ebd0e  50                   push eax
// 008ebd0f  8b442418             mov eax, dword ptr [esp + 0x18]
// 008ebd13  52                   push edx
// 008ebd14  8b542418             mov edx, dword ptr [esp + 0x18]
// 008ebd18  83ec08               sub esp, 8
// 008ebd1b  d95c2404             fstp dword ptr [esp + 4]
// 008ebd1f  d9442428             fld dword ptr [esp + 0x28]
// 008ebd23  d91c24               fstp dword ptr [esp]
// 008ebd26  50                   push eax
// 008ebd27  8b442420             mov eax, dword ptr [esp + 0x20]
// 008ebd2b  52                   push edx
// 008ebd2c  50                   push eax
// 008ebd2d  e81ebaffff           call 0x8e7750
// 008ebd32  c21c00               ret 0x1c
// copied from an identical function in another client (function ?generate@MeshGeneratorAnalog@@QAEPAXPAX00MMHH@Z)

// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Codegen analog: target ret 0x1c and call 00687860 prove the argument mapping.
// The target loads 360.0f from 0084e97c and passes 0.0f as the preceding argument.
class MeshGeneratorAnalog {
public:
    void* generate(void*, void*, void*, float, float, int, int, float, float);
    void* generate(void*, void*, void*, float, float, int, int);
};
void* MeshGeneratorAnalog::generate(void* a, void* b, void* c,
                                   float d, float e, int f, int g) {
    return generate(a, b, c, d, e, f, g, 0.0f, 360.0f);
}