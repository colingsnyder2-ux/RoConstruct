// roc 2012-06 00a6a5c0  unit: CXTCaptionButton  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6a5c0
//
// 00a6a5c0  56                   push esi
// 00a6a5c1  8bf1                 mov esi, ecx
// 00a6a5c3  e8d8c4ffff           call 0xa66aa0
// 00a6a5c8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00a6a5cc  8b10                 mov edx, dword ptr [eax]
// 00a6a5ce  8b5258               mov edx, dword ptr [edx + 0x58]
// 00a6a5d1  56                   push esi
// 00a6a5d2  51                   push ecx
// 00a6a5d3  8bc8                 mov ecx, eax
// 00a6a5d5  ffd2                 call edx
// 00a6a5d7  5e                   pop esi
// 00a6a5d8  c20400               ret 4
// copied from an identical function in another client (function ?OnClick@CXTCaptionButton@ns_ROCX000071@@QAEXH@Z)

namespace ns_ROCX000071 {
struct CXTCaptionButton {
    void OnClick(int);
};

extern "C" void* __fastcall sub_710F90(CXTCaptionButton* self);

void CXTCaptionButton::OnClick(int arg)
{
    void* site = sub_710F90(this);
    void** vtbl = *(void***)site;
    void (__thiscall *fn)(void*, int, CXTCaptionButton*) = (void (__thiscall *)(void*, int, CXTCaptionButton*))vtbl[0x58 / 4];
    fn(site, arg, this);
}
}
