// from server: 100% by auto
// roc 2011-06 008bdc20  unit: CXTPDockingPaneWindowSelect  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bdc20
//
// 008bdc20  56                   push esi
// 008bdc21  6a11                 push 0x11
// 008bdc23  8bf1                 mov esi, ecx
// 008bdc25  ff15601aa400         call dword ptr [0xa41a60]
// 008bdc2b  6685c0               test ax, ax
// 008bdc2e  7c0e                 jl 0x8bdc3e
// 008bdc30  8b06                 mov eax, dword ptr [esi]
// 008bdc32  8b9094000000         mov edx, dword ptr [eax + 0x94]
// 008bdc38  6a01                 push 1
// 008bdc3a  8bce                 mov ecx, esi
// 008bdc3c  ffd2                 call edx
// 008bdc3e  8bce                 mov ecx, esi
// 008bdc40  e8e9c9f4ff           call 0x80a62e
// 008bdc45  5e                   pop esi
// 008bdc46  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyUp@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
