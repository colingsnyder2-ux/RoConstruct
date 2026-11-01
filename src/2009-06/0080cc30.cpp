// from server: 100% by auto
// roc 2009-06 0080cc30  unit: CXTPTabPaintManager::CColorSetDefault  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080cc30
//
// 0080cc30  8b442418             mov eax, dword ptr [esp + 0x18]
// 0080cc34  8b4004               mov eax, dword ptr [eax + 4]
// 0080cc37  56                   push esi
// 0080cc38  85c0                 test eax, eax
// 0080cc3a  741f                 je 0x80cc5b
// 0080cc3c  8b11                 mov edx, dword ptr [ecx]
// 0080cc3e  50                   push eax
// 0080cc3f  8b4224               mov eax, dword ptr [edx + 0x24]
// 0080cc42  ffd0                 call eax
// 0080cc44  8bf0                 mov esi, eax
// 0080cc46  56                   push esi
// 0080cc47  8d4c2410             lea ecx, [esp + 0x10]
// 0080cc4b  51                   push ecx
// 0080cc4c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080cc50  e87bcbf0ff           call 0x7197d0
// 0080cc55  8bc6                 mov eax, esi
// 0080cc57  5e                   pop esi
// 0080cc58  c21800               ret 0x18
// 0080cc5b  8b717c               mov esi, dword ptr [ecx + 0x7c]
// 0080cc5e  83feff               cmp esi, -1
// 0080cc61  7503                 jne 0x80cc66
// 0080cc63  8b7178               mov esi, dword ptr [ecx + 0x78]
// 0080cc66  56                   push esi
// 0080cc67  8d4c2410             lea ecx, [esp + 0x10]
// 0080cc6b  51                   push ecx
// 0080cc6c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080cc70  e85bcbf0ff           call 0x7197d0
// 0080cc75  8bc6                 mov eax, esi
// 0080cc77  5e                   pop esi
// 0080cc78  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillClient@CXTPTabPaintManagerColorSet@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
