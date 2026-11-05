// roc 2012-06 009e5c80  unit: CXTSplitterWnd  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5c80
//
// 009e5c80  56                   push esi
// 009e5c81  8bf1                 mov esi, ecx
// 009e5c83  83be0401000000       cmp dword ptr [esi + 0x104], 0
// 009e5c8a  7410                 je 0x9e5c9c
// 009e5c8c  6a00                 push 0
// 009e5c8e  ff153021b200         call dword ptr [0xb22130]
// 009e5c94  50                   push eax
// 009e5c95  e854cff9ff           call 0x982bee
// 009e5c9a  eb05                 jmp 0x9e5ca1
// 009e5c9c  e8673c0b00           call 0xa99908
// 009e5ca1  8b16                 mov edx, dword ptr [esi]
// 009e5ca3  8b92dc010000         mov edx, dword ptr [edx + 0x1dc]
// 009e5ca9  50                   push eax
// 009e5caa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009e5cae  50                   push eax
// 009e5caf  8bce                 mov ecx, esi
// 009e5cb1  ffd2                 call edx
// 009e5cb3  5e                   pop esi
// 009e5cb4  c20400               ret 4
// copied from an identical function in another client (function ?OnInvertTracker@CXTSplitterWnd@@MAEXABVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1