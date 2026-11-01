// from server: 100% by auto
// roc 2007-03 00625d90  unit: seg_00620000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625d90
//
// 00625d90  83ec0c               sub esp, 0xc
// 00625d93  56                   push esi
// 00625d94  8bf1                 mov esi, ecx
// 00625d96  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00625d99  f7d8                 neg eax
// 00625d9b  1bc0                 sbb eax, eax
// 00625d9d  89442404             mov dword ptr [esp + 4], eax
// 00625da1  742b                 je 0x625dce
// 00625da3  57                   push edi
// 00625da4  8d7e10               lea edi, [esi + 0x10]
// 00625da7  8d44240c             lea eax, [esp + 0xc]
// 00625dab  50                   push eax
// 00625dac  8d4c2414             lea ecx, [esp + 0x14]
// 00625db0  51                   push ecx
// 00625db1  8d542410             lea edx, [esp + 0x10]
// 00625db5  52                   push edx
// 00625db6  8bcf                 mov ecx, edi
// 00625db8  e843f7ffff           call 0x625500
// 00625dbd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00625dc1  e8ac88ffff           call 0x61e672
// 00625dc6  837c240800           cmp dword ptr [esp + 8], 0
// 00625dcb  75da                 jne 0x625da7
// 00625dcd  5f                   pop edi
// 00625dce  8d4e10               lea ecx, [esi + 0x10]
// 00625dd1  5e                   pop esi
// 00625dd2  83c40c               add esp, 0xc
// 00625dd5  e9e65b0000           jmp 0x62b9c0
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerImageList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
