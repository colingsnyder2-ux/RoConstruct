// from server: 100% by auto
// roc 2010-06 007c6df0  unit: CXTPToolBar  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c6df0
//
// 007c6df0  e803611b00           call 0x97cef8
// 007c6df5  85c0                 test eax, eax
// 007c6df7  7501                 jne 0x7c6dfa
// 007c6df9  c3                   ret 
// 007c6dfa  56                   push esi
// 007c6dfb  57                   push edi
// 007c6dfc  ff1580ba9e00         call dword ptr [0x9eba80]
// 007c6e02  50                   push eax
// 007c6e03  e8620efeff           call 0x7a7c6a
// 007c6e08  8bf0                 mov esi, eax
// 007c6e0a  85f6                 test esi, esi
// 007c6e0c  7430                 je 0x7c6e3e
// 007c6e0e  8b3d28bc9e00         mov edi, dword ptr [0x9ebc28]
// 007c6e14  8b4620               mov eax, dword ptr [esi + 0x20]
// 007c6e17  50                   push eax
// 007c6e18  ffd7                 call edi
// 007c6e1a  85c0                 test eax, eax
// 007c6e1c  7420                 je 0x7c6e3e
// 007c6e1e  8bce                 mov ecx, esi
// 007c6e20  e8690efeff           call 0x7a7c8e
// 007c6e25  8bf0                 mov esi, eax
// 007c6e27  56                   push esi
// 007c6e28  e8c5601b00           call 0x97cef2
// 007c6e2d  50                   push eax
// 007c6e2e  e84b0ffeff           call 0x7a7d7e
// 007c6e33  83c408               add esp, 8
// 007c6e36  85c0                 test eax, eax
// 007c6e38  7509                 jne 0x7c6e43
// 007c6e3a  85f6                 test esi, esi
// 007c6e3c  75d6                 jne 0x7c6e14
// 007c6e3e  5f                   pop edi
// 007c6e3f  33c0                 xor eax, eax
// 007c6e41  5e                   pop esi
// 007c6e42  c3                   ret 
// 007c6e43  5f                   pop edi
// 007c6e44  b801000000           mov eax, 1
// 007c6e49  5e                   pop esi
// 007c6e4a  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPToolBar.cpp (function ?IsFloatingFrameFocused@CXTPToolBar@@ABEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPToolBar.cpp
