// from server: 100% by auto
// roc 2009-12 008d4360  unit: CXTPTabPaintManager::CAppearanceSetStateButtons  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d4360
//
// 008d4360  8b442408             mov eax, dword ptr [esp + 8]
// 008d4364  8b11                 mov edx, dword ptr [ecx]
// 008d4366  8b5208               mov edx, dword ptr [edx + 8]
// 008d4369  56                   push esi
// 008d436a  8b742414             mov esi, dword ptr [esp + 0x14]
// 008d436e  50                   push eax
// 008d436f  83ec10               sub esp, 0x10
// 008d4372  8bc4                 mov eax, esp
// 008d4374  8930                 mov dword ptr [eax], esi
// 008d4376  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 008d437a  897004               mov dword ptr [eax + 4], esi
// 008d437d  8b742430             mov esi, dword ptr [esp + 0x30]
// 008d4381  897008               mov dword ptr [eax + 8], esi
// 008d4384  8b742434             mov esi, dword ptr [esp + 0x34]
// 008d4388  89700c               mov dword ptr [eax + 0xc], esi
// 008d438b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 008d438f  56                   push esi
// 008d4390  ffd2                 call edx
// 008d4392  8bc6                 mov eax, esi
// 008d4394  5e                   pop esi
// 008d4395  c21c00               ret 0x1c
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?FillTabControl@CAppearanceSetStateButtons@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
