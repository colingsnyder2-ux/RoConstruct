// from server: 100% by auto
// roc 2007-03 007078e0  unit: seg_00700000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007078e0
//
// 007078e0  8b442408             mov eax, dword ptr [esp + 8]
// 007078e4  8b11                 mov edx, dword ptr [ecx]
// 007078e6  8b5208               mov edx, dword ptr [edx + 8]
// 007078e9  56                   push esi
// 007078ea  8b742414             mov esi, dword ptr [esp + 0x14]
// 007078ee  50                   push eax
// 007078ef  83ec10               sub esp, 0x10
// 007078f2  8bc4                 mov eax, esp
// 007078f4  8930                 mov dword ptr [eax], esi
// 007078f6  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007078fa  897004               mov dword ptr [eax + 4], esi
// 007078fd  8b742430             mov esi, dword ptr [esp + 0x30]
// 00707901  897008               mov dword ptr [eax + 8], esi
// 00707904  8b742434             mov esi, dword ptr [esp + 0x34]
// 00707908  89700c               mov dword ptr [eax + 0xc], esi
// 0070790b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0070790f  56                   push esi
// 00707910  ffd2                 call edx
// 00707912  8bc6                 mov eax, esi
// 00707914  5e                   pop esi
// 00707915  c21c00               ret 0x1c
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?FillTabControl@CAppearanceSetStateButtons@CXTPTabPaintManager@@UAE?AVCRect@@PAVCXTPTabManager@@PAVCDC@@V3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
