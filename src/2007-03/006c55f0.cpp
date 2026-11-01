// from server: 100% by auto
// roc 2007-03 006c55f0  unit: seg_006c0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c55f0
//
// 006c55f0  56                   push esi
// 006c55f1  6a11                 push 0x11
// 006c55f3  8bf1                 mov esi, ecx
// 006c55f5  ff151ced7700         call dword ptr [0x77ed1c]
// 006c55fb  6685c0               test ax, ax
// 006c55fe  7c0e                 jl 0x6c560e
// 006c5600  8b06                 mov eax, dword ptr [esi]
// 006c5602  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 006c5608  6a01                 push 1
// 006c560a  8bce                 mov ecx, esi
// 006c560c  ffd2                 call edx
// 006c560e  8bce                 mov ecx, esi
// 006c5610  e8bd90f5ff           call 0x61e6d2
// 006c5615  5e                   pop esi
// 006c5616  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneKeyboardHook.cpp (function ?OnKeyUp@CXTPDockingPaneWindowSelect@@QAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneKeyboardHook.cpp
