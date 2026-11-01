// from server: 100% by auto
// roc 2009-12 008d4780  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d4780
//
// 008d4780  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d4784  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008d4788  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008d478c  56                   push esi
// 008d478d  8b742414             mov esi, dword ptr [esp + 0x14]
// 008d4791  57                   push edi
// 008d4792  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008d4796  50                   push eax
// 008d4797  83ec10               sub esp, 0x10
// 008d479a  8bc4                 mov eax, esp
// 008d479c  f7d9                 neg ecx
// 008d479e  8908                 mov dword ptr [eax], ecx
// 008d47a0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d47a4  f7da                 neg edx
// 008d47a6  895004               mov dword ptr [eax + 4], edx
// 008d47a9  f7de                 neg esi
// 008d47ab  f7df                 neg edi
// 008d47ad  897008               mov dword ptr [eax + 8], esi
// 008d47b0  51                   push ecx
// 008d47b1  89780c               mov dword ptr [eax + 0xc], edi
// 008d47b4  e8f7f6ffff           call 0x8d3eb0
// 008d47b9  83c418               add esp, 0x18
// 008d47bc  5f                   pop edi
// 008d47bd  5e                   pop esi
// 008d47be  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DeflateRectEx@CXTPTabPaintManagerAppearanceSet@@SAXAAVCRect@@V2@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
