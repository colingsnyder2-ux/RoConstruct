// roc 2012-06 009e5540  unit: CXTSplitterWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5540
//
// 009e5540  8b442404             mov eax, dword ptr [esp + 4]
// 009e5544  83f801               cmp eax, 1
// 009e5547  743b                 je 0x9e5584
// 009e5549  83f865               cmp eax, 0x65
// 009e554c  7c05                 jl 0x9e5553
// 009e554e  83f873               cmp eax, 0x73
// 009e5551  7e31                 jle 0x9e5584
// 009e5553  83f802               cmp eax, 2
// 009e5556  7417                 je 0x9e556f
// 009e5558  3dc9000000           cmp eax, 0xc9
// 009e555d  7c07                 jl 0x9e5566
// 009e555f  3dd7000000           cmp eax, 0xd7
// 009e5564  7e09                 jle 0x9e556f
// 009e5566  89442404             mov dword ptr [esp + 4], eax
// 009e556a  e997450b00           jmp 0xa99b06
// 009e556f  e8dc8c0000           call 0x9ee250
// 009e5574  8b80b4000000         mov eax, dword ptr [eax + 0xb4]
// 009e557a  89442404             mov dword ptr [esp + 4], eax
// 009e557e  ff25783bb200         jmp dword ptr [0xb23b78]
// 009e5584  e8c78c0000           call 0x9ee250
// 009e5589  8b88b8000000         mov ecx, dword ptr [eax + 0xb8]
// 009e558f  894c2404             mov dword ptr [esp + 4], ecx
// 009e5593  ff25783bb200         jmp dword ptr [0xb23b78]
// copied from an identical function in another client (function ?SetSplitCursor@CXTSplitterWnd@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1