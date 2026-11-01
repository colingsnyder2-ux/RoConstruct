// from server: 100% by auto
// roc 2009-12 008385f0  unit: CXTPControls  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008385f0
//
// 008385f0  8b442404             mov eax, dword ptr [esp + 4]
// 008385f4  85c0                 test eax, eax
// 008385f6  7416                 je 0x83860e
// 008385f8  8d4820               lea ecx, [eax + 0x20]
// 008385fb  8b01                 mov eax, dword ptr [ecx]
// 008385fd  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00838600  ffd2                 call edx
// 00838602  85c0                 test eax, eax
// 00838604  7408                 je 0x83860e
// 00838606  b801000000           mov eax, 1
// 0083860b  c20400               ret 4
// 0083860e  33c0                 xor eax, eax
// 00838610  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneHidden@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
