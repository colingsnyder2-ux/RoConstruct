// from server: 100% by auto
// roc 2010-06 00888510  unit: CXTPTabPaintManager::CAppearanceSetStateButtons  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888510
//
// 00888510  8b442408             mov eax, dword ptr [esp + 8]
// 00888514  8b11                 mov edx, dword ptr [ecx]
// 00888516  8b5208               mov edx, dword ptr [edx + 8]
// 00888519  56                   push esi
// 0088851a  8b742414             mov esi, dword ptr [esp + 0x14]
// 0088851e  50                   push eax
// 0088851f  83ec10               sub esp, 0x10
// 00888522  8bc4                 mov eax, esp
// 00888524  8930                 mov dword ptr [eax], esi
// 00888526  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0088852a  897004               mov dword ptr [eax + 4], esi
// 0088852d  8b742430             mov esi, dword ptr [esp + 0x30]
// 00888531  897008               mov dword ptr [eax + 8], esi
// 00888534  8b742434             mov esi, dword ptr [esp + 0x34]
// 00888538  89700c               mov dword ptr [eax + 0xc], esi
// 0088853b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0088853f  56                   push esi
// 00888540  ffd2                 call edx
// 00888542  8bc6                 mov eax, esi
// 00888544  5e                   pop esi
// 00888545  c21c00               ret 0x1c
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?FillTabControl@CAppearanceSetStateButtons@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
