// roc 2012-06 009e5420  unit: CXTSplitterWnd  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5420
//
// 009e5420  8b442408             mov eax, dword ptr [esp + 8]
// 009e5424  53                   push ebx
// 009e5425  56                   push esi
// 009e5426  57                   push edi
// 009e5427  8bd9                 mov ebx, ecx
// 009e5429  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e542d  50                   push eax
// 009e542e  51                   push ecx
// 009e542f  8bcb                 mov ecx, ebx
// 009e5431  e8dcd7f9ff           call 0x982c12
// 009e5436  50                   push eax
// 009e5437  e89ed6f9ff           call 0x982ada
// 009e543c  50                   push eax
// 009e543d  e8a4d0f9ff           call 0x9824e6
// 009e5442  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 009e5446  8bf0                 mov esi, eax
// 009e5448  83c408               add esp, 8
// 009e544b  3bf7                 cmp esi, edi
// 009e544d  7508                 jne 0x9e5457
// 009e544f  5f                   pop edi
// 009e5450  5e                   pop esi
// 009e5451  33c0                 xor eax, eax
// 009e5453  5b                   pop ebx
// 009e5454  c20c00               ret 0xc
// 009e5457  55                   push ebp
// 009e5458  8bce                 mov ecx, esi
// 009e545a  e871430b00           call 0xa997d0
// 009e545f  8bcf                 mov ecx, edi
// 009e5461  8be8                 mov ebp, eax
// 009e5463  e868430b00           call 0xa997d0
// 009e5468  6a00                 push 0
// 009e546a  8bce                 mov ecx, esi
// 009e546c  8944241c             mov dword ptr [esp + 0x1c], eax
// 009e5470  e82fd6f9ff           call 0x982aa4
// 009e5475  6a00                 push 0
// 009e5477  8bcf                 mov ecx, edi
// 009e5479  e826d6f9ff           call 0x982aa4
// 009e547e  8b542418             mov edx, dword ptr [esp + 0x18]
// 009e5482  52                   push edx
// 009e5483  8bce                 mov ecx, esi
// 009e5485  e876460b00           call 0xa99b00
// 009e548a  55                   push ebp
// 009e548b  8bcf                 mov ecx, edi
// 009e548d  e86e460b00           call 0xa99b00
// 009e5492  6a05                 push 5
// 009e5494  8bce                 mov ecx, esi
// 009e5496  e809d6f9ff           call 0x982aa4
// 009e549b  6a05                 push 5
// 009e549d  8bcf                 mov ecx, edi
// 009e549f  e800d6f9ff           call 0x982aa4
// 009e54a4  8b03                 mov eax, dword ptr [ebx]
// 009e54a6  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e54ac  8bcb                 mov ecx, ebx
// 009e54ae  ffd2                 call edx
// 009e54b0  5d                   pop ebp
// 009e54b1  5f                   pop edi
// 009e54b2  5e                   pop esi
// 009e54b3  b801000000           mov eax, 1
// 009e54b8  5b                   pop ebx
// 009e54b9  c20c00               ret 0xc
// copied from an identical function in another client (function ?SwitchView@CXTSplitterWnd@@UAEHHHPAVCView@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1