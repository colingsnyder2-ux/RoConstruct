// roc 2012-06 009e54c0  unit: CXTSplitterWnd  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e54c0
//
// 009e54c0  8b442408             mov eax, dword ptr [esp + 8]
// 009e54c4  53                   push ebx
// 009e54c5  56                   push esi
// 009e54c6  57                   push edi
// 009e54c7  8bf9                 mov edi, ecx
// 009e54c9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e54cd  50                   push eax
// 009e54ce  51                   push ecx
// 009e54cf  8bcf                 mov ecx, edi
// 009e54d1  e83cd7f9ff           call 0x982c12
// 009e54d6  50                   push eax
// 009e54d7  e8fed5f9ff           call 0x982ada
// 009e54dc  50                   push eax
// 009e54dd  e804d0f9ff           call 0x9824e6
// 009e54e2  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 009e54e6  8bf0                 mov esi, eax
// 009e54e8  83c408               add esp, 8
// 009e54eb  3bf3                 cmp esi, ebx
// 009e54ed  7508                 jne 0x9e54f7
// 009e54ef  5f                   pop edi
// 009e54f0  5e                   pop esi
// 009e54f1  33c0                 xor eax, eax
// 009e54f3  5b                   pop ebx
// 009e54f4  c20c00               ret 0xc
// 009e54f7  55                   push ebp
// 009e54f8  8bce                 mov ecx, esi
// 009e54fa  e8d1420b00           call 0xa997d0
// 009e54ff  6a00                 push 0
// 009e5501  8bce                 mov ecx, esi
// 009e5503  8be8                 mov ebp, eax
// 009e5505  e8f6450b00           call 0xa99b00
// 009e550a  55                   push ebp
// 009e550b  8bcb                 mov ecx, ebx
// 009e550d  e8ee450b00           call 0xa99b00
// 009e5512  6a00                 push 0
// 009e5514  8bce                 mov ecx, esi
// 009e5516  e889d5f9ff           call 0x982aa4
// 009e551b  6a05                 push 5
// 009e551d  8bcb                 mov ecx, ebx
// 009e551f  e880d5f9ff           call 0x982aa4
// 009e5524  8b17                 mov edx, dword ptr [edi]
// 009e5526  8b8250010000         mov eax, dword ptr [edx + 0x150]
// 009e552c  8bcf                 mov ecx, edi
// 009e552e  ffd0                 call eax
// 009e5530  5d                   pop ebp
// 009e5531  5f                   pop edi
// 009e5532  8bc6                 mov eax, esi
// 009e5534  5e                   pop esi
// 009e5535  5b                   pop ebx
// 009e5536  c20c00               ret 0xc
// copied from an identical function in another client (function ?ReplaceView@CXTSplitterWnd@@UAEPAVCView@@HHPAV2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1