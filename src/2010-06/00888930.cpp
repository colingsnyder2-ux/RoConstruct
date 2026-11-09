// from server: 100% by auto
// roc 2010-06 00888930  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888930
//
// 00888930  8b442418             mov eax, dword ptr [esp + 0x18]
// 00888934  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00888938  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0088893c  56                   push esi
// 0088893d  8b742414             mov esi, dword ptr [esp + 0x14]
// 00888941  57                   push edi
// 00888942  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00888946  50                   push eax
// 00888947  83ec10               sub esp, 0x10
// 0088894a  8bc4                 mov eax, esp
// 0088894c  f7d9                 neg ecx
// 0088894e  8908                 mov dword ptr [eax], ecx
// 00888950  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00888954  f7da                 neg edx
// 00888956  895004               mov dword ptr [eax + 4], edx
// 00888959  f7de                 neg esi
// 0088895b  f7df                 neg edi
// 0088895d  897008               mov dword ptr [eax + 8], esi
// 00888960  51                   push ecx
// 00888961  89780c               mov dword ptr [eax + 0xc], edi
// 00888964  e8f7f6ffff           call 0x888060
// 00888969  83c418               add esp, 0x18
// 0088896c  5f                   pop edi
// 0088896d  5e                   pop esi
// 0088896e  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?DeflateRectEx@CAppearanceSet@CXTPTabPaintManager@@SAXAAVCRect@@V3@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
