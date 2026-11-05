// from server: 100% by Yeetserama
// roc 2012-06 004f2a90  unit: seg_004f0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f2a90
//
// 004f2a90  d9050ca2b600         fld dword ptr [0xb6a20c]
// 004f2a96  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f2a9a  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f2a9e  83ec08               sub esp, 8
// 004f2aa1  d95c2404             fstp dword ptr [esp + 4]
// 004f2aa5  d9ee                 fldz 
// 004f2aa7  d91c24               fstp dword ptr [esp]
// 004f2aaa  d944241c             fld dword ptr [esp + 0x1c]
// 004f2aae  50                   push eax
// 004f2aaf  8b442418             mov eax, dword ptr [esp + 0x18]
// 004f2ab3  52                   push edx
// 004f2ab4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f2ab8  83ec08               sub esp, 8
// 004f2abb  d95c2404             fstp dword ptr [esp + 4]
// 004f2abf  d9442428             fld dword ptr [esp + 0x28]
// 004f2ac3  d91c24               fstp dword ptr [esp]
// 004f2ac6  50                   push eax
// 004f2ac7  8b442420             mov eax, dword ptr [esp + 0x20]
// 004f2acb  52                   push edx
// 004f2acc  50                   push eax
// 004f2acd  e8bebeffff           call 0x4ee990
// 004f2ad2  c21c00               ret 0x1c
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