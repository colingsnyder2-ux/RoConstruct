// from server: 100% by auto
// roc 2007-03 007188f0  unit: seg_00710000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007188f0
//
// 007188f0  8b442404             mov eax, dword ptr [esp + 4]
// 007188f4  56                   push esi
// 007188f5  57                   push edi
// 007188f6  50                   push eax
// 007188f7  8bf1                 mov esi, ecx
// 007188f9  e8226a0000           call 0x71f320
// 007188fe  6a01                 push 1
// 00718900  8bce                 mov ecx, esi
// 00718902  8bf8                 mov edi, eax
// 00718904  e887410000           call 0x71ca90
// 00718909  6a00                 push 0
// 0071890b  8bce                 mov ecx, esi
// 0071890d  e87e410000           call 0x71ca90
// 00718912  8bc7                 mov eax, edi
// 00718914  5f                   pop edi
// 00718915  5e                   pop esi
// 00718916  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectMDI.cpp (function ?OnNcActivate@CXTPSkinObjectMDIClient@@IAEHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectMDI.cpp
