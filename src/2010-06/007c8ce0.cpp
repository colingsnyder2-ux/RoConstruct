// from server: 100% by auto
// roc 2010-06 007c8ce0  unit: CXTPCommandBarKeyboardTip  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8ce0
//
// 007c8ce0  56                   push esi
// 007c8ce1  8bf1                 mov esi, ecx
// 007c8ce3  8d4e5c               lea ecx, [esi + 0x5c]
// 007c8ce6  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 007c8cec  8d4e58               lea ecx, [esi + 0x58]
// 007c8cef  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 007c8cf5  8d4e54               lea ecx, [esi + 0x54]
// 007c8cf8  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 007c8cfe  8bce                 mov ecx, esi
// 007c8d00  e851f7fdff           call 0x7a8456
// 007c8d05  f644240801           test byte ptr [esp + 8], 1
// 007c8d0a  7409                 je 0x7c8d15
// 007c8d0c  56                   push esi
// 007c8d0d  e888ecfdff           call 0x7a799a
// 007c8d12  83c404               add esp, 4
// 007c8d15  8bc6                 mov eax, esi
// 007c8d17  5e                   pop esi
// 007c8d18  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ??_GCXTPCommandBarKeyboardTip@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
