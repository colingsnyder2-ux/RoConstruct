// from server: 100% by auto
// roc 2007-03 0069ee40  unit: seg_00690000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069ee40
//
// 0069ee40  56                   push esi
// 0069ee41  8bf1                 mov esi, ecx
// 0069ee43  803e00               cmp byte ptr [esi], 0
// 0069ee46  740e                 je 0x69ee56
// 0069ee48  e843f5f7ff           call 0x61e390
// 0069ee4d  8b4e04               mov ecx, dword ptr [esi + 4]
// 0069ee50  89480c               mov dword ptr [eax + 0xc], ecx
// 0069ee53  c60600               mov byte ptr [esi], 0
// 0069ee56  5e                   pop esi
// 0069ee57  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?Undo@CManageState@CXTPResourceManager@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
