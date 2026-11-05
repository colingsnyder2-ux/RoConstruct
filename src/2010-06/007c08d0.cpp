// from server: 100% by auto
// roc 2010-06 007c08d0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c08d0
//
// 007c08d0  83ec0c               sub esp, 0xc
// 007c08d3  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 007c08d6  f7d8                 neg eax
// 007c08d8  1bc0                 sbb eax, eax
// 007c08da  890424               mov dword ptr [esp], eax
// 007c08dd  742b                 je 0x7c090a
// 007c08df  56                   push esi
// 007c08e0  8d7120               lea esi, [ecx + 0x20]
// 007c08e3  8d442408             lea eax, [esp + 8]
// 007c08e7  50                   push eax
// 007c08e8  8d4c2410             lea ecx, [esp + 0x10]
// 007c08ec  51                   push ecx
// 007c08ed  8d54240c             lea edx, [esp + 0xc]
// 007c08f1  52                   push edx
// 007c08f2  8bce                 mov ecx, esi
// 007c08f4  e897f90a00           call 0x870290
// 007c08f9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007c08fd  e8cefeffff           call 0x7c07d0
// 007c0902  837c240400           cmp dword ptr [esp + 4], 0
// 007c0907  75da                 jne 0x7c08e3
// 007c0909  5e                   pop esi
// 007c090a  83c40c               add esp, 0xc
// 007c090d  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?RefreshAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
