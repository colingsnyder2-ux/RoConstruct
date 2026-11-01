// from server: 100% by auto
// roc 2007-03 0069ee60  unit: seg_00690000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069ee60
//
// 0069ee60  56                   push esi
// 0069ee61  8bf1                 mov esi, ecx
// 0069ee63  8b4608               mov eax, dword ptr [esi + 8]
// 0069ee66  85c0                 test eax, eax
// 0069ee68  740e                 je 0x69ee78
// 0069ee6a  50                   push eax
// 0069ee6b  ff159cd27700         call dword ptr [0x77d29c]
// 0069ee71  c7460800000000       mov dword ptr [esi + 8], 0
// 0069ee78  5e                   pop esi
// 0069ee79  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Close@CXTPResourceManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
