// from server: 100% by auto
// roc 2009-06 007f9be0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f9be0
//
// 007f9be0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007f9be4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007f9be8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007f9bec  56                   push esi
// 007f9bed  8b742414             mov esi, dword ptr [esp + 0x14]
// 007f9bf1  57                   push edi
// 007f9bf2  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007f9bf6  50                   push eax
// 007f9bf7  83ec10               sub esp, 0x10
// 007f9bfa  8bc4                 mov eax, esp
// 007f9bfc  f7d9                 neg ecx
// 007f9bfe  8908                 mov dword ptr [eax], ecx
// 007f9c00  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007f9c04  f7da                 neg edx
// 007f9c06  895004               mov dword ptr [eax + 4], edx
// 007f9c09  f7de                 neg esi
// 007f9c0b  f7df                 neg edi
// 007f9c0d  897008               mov dword ptr [eax + 8], esi
// 007f9c10  51                   push ecx
// 007f9c11  89780c               mov dword ptr [eax + 0xc], edi
// 007f9c14  e8f7f6ffff           call 0x7f9310
// 007f9c19  83c418               add esp, 0x18
// 007f9c1c  5f                   pop edi
// 007f9c1d  5e                   pop esi
// 007f9c1e  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DeflateRectEx@CXTPTabPaintManagerAppearanceSet@@SAXAAVCRect@@V2@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
