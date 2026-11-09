// roc 2012-06 009e55a0  unit: CXTSplitterWnd  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e55a0
//
// 009e55a0  8b442408             mov eax, dword ptr [esp + 8]
// 009e55a4  56                   push esi
// 009e55a5  8bf1                 mov esi, ecx
// 009e55a7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009e55ab  50                   push eax
// 009e55ac  51                   push ecx
// 009e55ad  8bce                 mov ecx, esi
// 009e55af  e858450b00           call 0xa99b0c
// 009e55b4  83be0001000000       cmp dword ptr [esi + 0x100], 0
// 009e55bb  7524                 jne 0x9e55e1
// 009e55bd  57                   push edi
// 009e55be  6a00                 push 0
// 009e55c0  8dbefc000000         lea edi, [esi + 0xfc]
// 009e55c6  57                   push edi
// 009e55c7  6a00                 push 0
// 009e55c9  6a26                 push 0x26
// 009e55cb  ff15543ab200         call dword ptr [0xb23a54]
// 009e55d1  f6860801000002       test byte ptr [esi + 0x108], 2
// 009e55d8  7406                 je 0x9e55e0
// 009e55da  c70700000000         mov dword ptr [edi], 0
// 009e55e0  5f                   pop edi
// 009e55e1  5e                   pop esi
// 009e55e2  c20800               ret 8
// copied from an identical function in another client (function ?OnSettingChange@CXTSplitterWnd@@IAEXIPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1