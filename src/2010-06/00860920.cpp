// from server: 100% by auto
// roc 2010-06 00860920  unit: CXTPDockingPaneWindowSelect  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00860920
//
// 00860920  56                   push esi
// 00860921  6a11                 push 0x11
// 00860923  8bf1                 mov esi, ecx
// 00860925  ff157cbc9e00         call dword ptr [0x9ebc7c]
// 0086092b  6685c0               test ax, ax
// 0086092e  7c0e                 jl 0x86093e
// 00860930  8b06                 mov eax, dword ptr [esi]
// 00860932  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 00860938  6a01                 push 1
// 0086093a  8bce                 mov ecx, esi
// 0086093c  ffd2                 call edx
// 0086093e  8bce                 mov ecx, esi
// 00860940  e82b76f4ff           call 0x7a7f70
// 00860945  5e                   pop esi
// 00860946  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyUp@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
