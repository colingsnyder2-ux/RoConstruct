// from server: 100% by auto
// roc 2007-08 006dc620  unit: CXTPDockingPaneWindowSelect  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006dc620
//
// 006dc620  56                   push esi
// 006dc621  6a11                 push 0x11
// 006dc623  8bf1                 mov esi, ecx
// 006dc625  ff154cec7700         call dword ptr [0x77ec4c]
// 006dc62b  6685c0               test ax, ax
// 006dc62e  7c0e                 jl 0x6dc63e
// 006dc630  8b06                 mov eax, dword ptr [esi]
// 006dc632  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 006dc638  6a01                 push 1
// 006dc63a  8bce                 mov ecx, esi
// 006dc63c  ffd2                 call edx
// 006dc63e  8bce                 mov ecx, esi
// 006dc640  e8f93bf5ff           call 0x63023e
// 006dc645  5e                   pop esi
// 006dc646  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyUp@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
