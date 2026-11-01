// from server: 100% by auto
// roc 2009-12 0080c7e0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c7e0
//
// 0080c7e0  83ec0c               sub esp, 0xc
// 0080c7e3  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 0080c7e6  f7d8                 neg eax
// 0080c7e8  1bc0                 sbb eax, eax
// 0080c7ea  890424               mov dword ptr [esp], eax
// 0080c7ed  742b                 je 0x80c81a
// 0080c7ef  56                   push esi
// 0080c7f0  8d7120               lea esi, [ecx + 0x20]
// 0080c7f3  8d442408             lea eax, [esp + 8]
// 0080c7f7  50                   push eax
// 0080c7f8  8d4c2410             lea ecx, [esp + 0x10]
// 0080c7fc  51                   push ecx
// 0080c7fd  8d54240c             lea edx, [esp + 0xc]
// 0080c801  52                   push edx
// 0080c802  8bce                 mov ecx, esi
// 0080c804  e817d0ffff           call 0x809820
// 0080c809  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080c80d  e8cefeffff           call 0x80c6e0
// 0080c812  837c240400           cmp dword ptr [esp + 4], 0
// 0080c817  75da                 jne 0x80c7f3
// 0080c819  5e                   pop esi
// 0080c81a  83c40c               add esp, 0xc
// 0080c81d  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RefreshAll@CXTPImageManagerIconSet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
