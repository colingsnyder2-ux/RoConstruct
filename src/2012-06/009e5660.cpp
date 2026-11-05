// roc 2012-06 009e5660  unit: CXTSplitterWnd  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5660
//
// 009e5660  56                   push esi
// 009e5661  8b742410             mov esi, dword ptr [esp + 0x10]
// 009e5665  57                   push edi
// 009e5666  8bf9                 mov edi, ecx
// 009e5668  85f6                 test esi, esi
// 009e566a  7513                 jne 0x9e567f
// 009e566c  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e5670  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e5674  50                   push eax
// 009e5675  51                   push ecx
// 009e5676  8bcf                 mov ecx, edi
// 009e5678  e895d5f9ff           call 0x982c12
// 009e567d  8bf0                 mov esi, eax
// 009e567f  e856d4f9ff           call 0x982ada
// 009e5684  50                   push eax
// 009e5685  8bce                 mov ecx, esi
// 009e5687  e80ad0f9ff           call 0x982696
// 009e568c  85c0                 test eax, eax
// 009e568e  7416                 je 0x9e56a6
// 009e5690  8bcf                 mov ecx, edi
// 009e5692  e819cef9ff           call 0x9824b0
// 009e5697  6a01                 push 1
// 009e5699  56                   push esi
// 009e569a  8bc8                 mov ecx, eax
// 009e569c  e889d8f9ff           call 0x982f2a
// 009e56a1  5f                   pop edi
// 009e56a2  5e                   pop esi
// 009e56a3  c20c00               ret 0xc
// 009e56a6  8bce                 mov ecx, esi
// 009e56a8  e8f7cdf9ff           call 0x9824a4
// 009e56ad  5f                   pop edi
// 009e56ae  5e                   pop esi
// 009e56af  c20c00               ret 0xc
// copied from an identical function in another client (function ?SetActivePane@CXTSplitterWnd@@UAEXHHPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1