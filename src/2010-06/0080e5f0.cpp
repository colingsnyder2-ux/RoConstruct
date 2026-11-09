// from server: 100% by auto
// roc 2010-06 0080e5f0  unit: CXTThemeManager  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e5f0
//
// 0080e5f0  56                   push esi
// 0080e5f1  57                   push edi
// 0080e5f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080e5f6  8bf1                 mov esi, ecx
// 0080e5f8  85ff                 test edi, edi
// 0080e5fa  742c                 je 0x80e628
// 0080e5fc  8b4610               mov eax, dword ptr [esi + 0x10]
// 0080e5ff  85c0                 test eax, eax
// 0080e601  7409                 je 0x80e60c
// 0080e603  56                   push esi
// 0080e604  8d4808               lea ecx, [eax + 8]
// 0080e607  e814ee1600           call 0x97d420
// 0080e60c  57                   push edi
// 0080e60d  897e08               mov dword ptr [esi + 8], edi
// 0080e610  e8fbfeffff           call 0x80e510
// 0080e615  8bc8                 mov ecx, eax
// 0080e617  e834fcffff           call 0x80e250
// 0080e61c  56                   push esi
// 0080e61d  8d4808               lea ecx, [eax + 8]
// 0080e620  894610               mov dword ptr [esi + 0x10], eax
// 0080e623  e8f2ed1600           call 0x97d41a
// 0080e628  5f                   pop edi
// 0080e629  5e                   pop esi
// 0080e62a  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTThemeManager.cpp (function ?InitStyleHost@CXTThemeManagerStyleHost@@IAEXPAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTThemeManager.cpp
