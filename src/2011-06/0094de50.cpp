// from server: 100% by Yeetserama
// roc 2011-06 0094de50  unit: seg_00940000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0094de50
//
// 0094de50  d9057c70af00         fld dword ptr [0xaf707c]
// 0094de56  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0094de5a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0094de5e  83ec08               sub esp, 8
// 0094de61  d95c2404             fstp dword ptr [esp + 4]
// 0094de65  d9ee                 fldz 
// 0094de67  d91c24               fstp dword ptr [esp]
// 0094de6a  d944241c             fld dword ptr [esp + 0x1c]
// 0094de6e  50                   push eax
// 0094de6f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0094de73  52                   push edx
// 0094de74  8b542418             mov edx, dword ptr [esp + 0x18]
// 0094de78  83ec08               sub esp, 8
// 0094de7b  d95c2404             fstp dword ptr [esp + 4]
// 0094de7f  d9442428             fld dword ptr [esp + 0x28]
// 0094de83  d91c24               fstp dword ptr [esp]
// 0094de86  50                   push eax
// 0094de87  8b442420             mov eax, dword ptr [esp + 0x20]
// 0094de8b  52                   push edx
// 0094de8c  50                   push eax
// 0094de8d  e8aebeffff           call 0x949d40
// 0094de92  c21c00               ret 0x1c
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