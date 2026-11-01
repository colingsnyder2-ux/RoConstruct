// from server: 100% by auto
// roc 2009-06 00781d30  unit: CXTPDockingPane  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781d30
//
// 00781d30  8d442404             lea eax, [esp + 4]
// 00781d34  50                   push eax
// 00781d35  e896eefdff           call 0x760bd0
// 00781d3a  85c0                 test eax, eax
// 00781d3c  7408                 je 0x781d46
// 00781d3e  b857000780           mov eax, 0x80070057
// 00781d43  c21400               ret 0x14
// 00781d46  682cd38f00           push 0x8fd32c
// 00781d4b  ff15d8e98900         call dword ptr [0x89e9d8]
// 00781d51  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00781d55  8901                 mov dword ptr [ecx], eax
// 00781d57  33c0                 xor eax, eax
// 00781d59  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleDefaultAction@CXTPDockingPane@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
