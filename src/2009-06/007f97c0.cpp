// from server: 100% by auto
// roc 2009-06 007f97c0  unit: CXTPTabPaintManager::CAppearanceSetStateButtons  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f97c0
//
// 007f97c0  8b442408             mov eax, dword ptr [esp + 8]
// 007f97c4  8b11                 mov edx, dword ptr [ecx]
// 007f97c6  8b5208               mov edx, dword ptr [edx + 8]
// 007f97c9  56                   push esi
// 007f97ca  8b742414             mov esi, dword ptr [esp + 0x14]
// 007f97ce  50                   push eax
// 007f97cf  83ec10               sub esp, 0x10
// 007f97d2  8bc4                 mov eax, esp
// 007f97d4  8930                 mov dword ptr [eax], esi
// 007f97d6  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007f97da  897004               mov dword ptr [eax + 4], esi
// 007f97dd  8b742430             mov esi, dword ptr [esp + 0x30]
// 007f97e1  897008               mov dword ptr [eax + 8], esi
// 007f97e4  8b742434             mov esi, dword ptr [esp + 0x34]
// 007f97e8  89700c               mov dword ptr [eax + 0xc], esi
// 007f97eb  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007f97ef  56                   push esi
// 007f97f0  ffd2                 call edx
// 007f97f2  8bc6                 mov eax, esi
// 007f97f4  5e                   pop esi
// 007f97f5  c21c00               ret 0x1c
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?FillTabControl@CAppearanceSetStateButtons@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
