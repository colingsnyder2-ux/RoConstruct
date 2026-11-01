// from server: 100% by auto
// roc 2009-06 0079a940  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079a940
//
// 0079a940  56                   push esi
// 0079a941  8bf1                 mov esi, ecx
// 0079a943  8b4608               mov eax, dword ptr [esi + 8]
// 0079a946  85c0                 test eax, eax
// 0079a948  740e                 je 0x79a958
// 0079a94a  50                   push eax
// 0079a94b  ff15b4e18900         call dword ptr [0x89e1b4]
// 0079a951  c7460800000000       mov dword ptr [esi + 8], 0
// 0079a958  5e                   pop esi
// 0079a959  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Close@CXTPResourceManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
