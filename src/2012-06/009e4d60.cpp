// roc 2012-06 009e4d60  unit: CXTPDockingPane  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e4d60
//
// 009e4d60  6aff                 push -1
// 009e4d62  68980fae00           push 0xae0f98
// 009e4d67  64a100000000         mov eax, dword ptr fs:[0]
// 009e4d6d  50                   push eax
// 009e4d6e  51                   push ecx
// 009e4d6f  56                   push esi
// 009e4d70  a1d027e000           mov eax, dword ptr [0xe027d0]
// 009e4d75  33c4                 xor eax, esp
// 009e4d77  50                   push eax
// 009e4d78  8d44240c             lea eax, [esp + 0xc]
// 009e4d7c  64a300000000         mov dword ptr fs:[0], eax
// 009e4d82  8bf1                 mov esi, ecx
// 009e4d84  89742408             mov dword ptr [esp + 8], esi
// 009e4d88  8d8edc000000         lea ecx, [esi + 0xdc]
// 009e4d8e  c7069475c100         mov dword ptr [esi], 0xc17594
// 009e4d94  c7018475c100         mov dword ptr [ecx], 0xc17584
// 009e4d9a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 009e4da2  e8e91a0000           call 0x9e6890
// 009e4da7  8bce                 mov ecx, esi
// 009e4da9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 009e4db1  e8ae4c0b00           call 0xa99a64
// 009e4db6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e4dba  64890d00000000       mov dword ptr fs:[0], ecx
// 009e4dc1  59                   pop ecx
// 009e4dc2  5e                   pop esi
// 009e4dc3  83c410               add esp, 0x10
// 009e4dc6  c3                   ret 
// copied from an identical function in another client (function ??1CXTSplitterWnd@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1