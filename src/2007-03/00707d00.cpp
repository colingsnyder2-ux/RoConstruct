// from server: 100% by auto
// roc 2007-03 00707d00  unit: seg_00700000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707d00
//
// 00707d00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00707d04  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00707d08  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00707d0c  56                   push esi
// 00707d0d  8b742414             mov esi, dword ptr [esp + 0x14]
// 00707d11  57                   push edi
// 00707d12  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00707d16  50                   push eax
// 00707d17  83ec10               sub esp, 0x10
// 00707d1a  8bc4                 mov eax, esp
// 00707d1c  f7d9                 neg ecx
// 00707d1e  8908                 mov dword ptr [eax], ecx
// 00707d20  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00707d24  f7da                 neg edx
// 00707d26  895004               mov dword ptr [eax + 4], edx
// 00707d29  f7de                 neg esi
// 00707d2b  f7df                 neg edi
// 00707d2d  897008               mov dword ptr [eax + 8], esi
// 00707d30  51                   push ecx
// 00707d31  89780c               mov dword ptr [eax + 0xc], edi
// 00707d34  e807f7ffff           call 0x707440
// 00707d39  83c418               add esp, 0x18
// 00707d3c  5f                   pop edi
// 00707d3d  5e                   pop esi
// 00707d3e  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DeflateRectEx@CXTPTabPaintManagerAppearanceSet@@SAXAAVCRect@@V2@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
