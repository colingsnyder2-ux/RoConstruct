// from server: 100% by auto
// roc 2009-06 00735730  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00735730
//
// 00735730  83ec0c               sub esp, 0xc
// 00735733  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 00735736  f7d8                 neg eax
// 00735738  1bc0                 sbb eax, eax
// 0073573a  890424               mov dword ptr [esp], eax
// 0073573d  742b                 je 0x73576a
// 0073573f  56                   push esi
// 00735740  8d7120               lea esi, [ecx + 0x20]
// 00735743  8d442408             lea eax, [esp + 8]
// 00735747  50                   push eax
// 00735748  8d4c2410             lea ecx, [esp + 0x10]
// 0073574c  51                   push ecx
// 0073574d  8d54240c             lea edx, [esp + 0xc]
// 00735751  52                   push edx
// 00735752  8bce                 mov ecx, esi
// 00735754  e817d90500           call 0x793070
// 00735759  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0073575d  e8cefeffff           call 0x735630
// 00735762  837c240400           cmp dword ptr [esp + 4], 0
// 00735767  75da                 jne 0x735743
// 00735769  5e                   pop esi
// 0073576a  83c40c               add esp, 0xc
// 0073576d  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RefreshAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
