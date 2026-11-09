// roc 2012-06 009e5b10  unit: CXTSplitterWnd  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5b10
//
// 009e5b10  6aff                 push -1
// 009e5b12  682810ae00           push 0xae1028
// 009e5b17  64a100000000         mov eax, dword ptr fs:[0]
// 009e5b1d  50                   push eax
// 009e5b1e  83ec24               sub esp, 0x24
// 009e5b21  55                   push ebp
// 009e5b22  56                   push esi
// 009e5b23  57                   push edi
// 009e5b24  a1d027e000           mov eax, dword ptr [0xe027d0]
// 009e5b29  33c4                 xor eax, esp
// 009e5b2b  50                   push eax
// 009e5b2c  8d442434             lea eax, [esp + 0x34]
// 009e5b30  64a300000000         mov dword ptr fs:[0], eax
// 009e5b36  8bf1                 mov esi, ecx
// 009e5b38  83befc00000000       cmp dword ptr [esi + 0xfc], 0
// 009e5b3f  0f8517010000         jne 0x9e5c5c
// 009e5b45  56                   push esi
// 009e5b46  8d4c2424             lea ecx, [esp + 0x24]
// 009e5b4a  e84d3a0b00           call 0xa9959c
// 009e5b4f  8d4c2420             lea ecx, [esp + 0x20]
// 009e5b53  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 009e5b5b  e8d23a0b00           call 0xa99632
// 009e5b60  f6860801000001       test byte ptr [esi + 0x108], 1
// 009e5b67  8be8                 mov ebp, eax
// 009e5b69  7457                 je 0x9e5bc2
// 009e5b6b  8b06                 mov eax, dword ptr [esi]
// 009e5b6d  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 009e5b73  8d4c2410             lea ecx, [esp + 0x10]
// 009e5b77  51                   push ecx
// 009e5b78  8bce                 mov ecx, esi
// 009e5b7a  ffd2                 call edx
// 009e5b7c  8b442444             mov eax, dword ptr [esp + 0x44]
// 009e5b80  8b5008               mov edx, dword ptr [eax + 8]
// 009e5b83  8b4804               mov ecx, dword ptr [eax + 4]
// 009e5b86  8b700c               mov esi, dword ptr [eax + 0xc]
// 009e5b89  8bfa                 mov edi, edx
// 009e5b8b  2b38                 sub edi, dword ptr [eax]
// 009e5b8d  2bf1                 sub esi, ecx
// 009e5b8f  3bfe                 cmp edi, esi
// 009e5b91  7d19                 jge 0x9e5bac
// 009e5b93  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 009e5b97  8d442410             lea eax, [esp + 0x10]
// 009e5b9b  50                   push eax
// 009e5b9c  51                   push ecx
// 009e5b9d  89542420             mov dword ptr [esp + 0x20], edx
// 009e5ba1  ff15d43cb200         call dword ptr [0xb23cd4]
// 009e5ba7  e995000000           jmp 0x9e5c41
// 009e5bac  8d442410             lea eax, [esp + 0x10]
// 009e5bb0  894c241c             mov dword ptr [esp + 0x1c], ecx
// 009e5bb4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 009e5bb8  50                   push eax
// 009e5bb9  51                   push ecx
// 009e5bba  ff15d43cb200         call dword ptr [0xb23cd4]
// 009e5bc0  eb7f                 jmp 0x9e5c41
// 009e5bc2  8b542444             mov edx, dword ptr [esp + 0x44]
// 009e5bc6  52                   push edx
// 009e5bc7  8d442414             lea eax, [esp + 0x14]
// 009e5bcb  50                   push eax
// 009e5bcc  ff15ec3ab200         call dword ptr [0xb23aec]
// 009e5bd2  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 009e5bd6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 009e5bda  8b742414             mov esi, dword ptr [esp + 0x14]
// 009e5bde  8bc7                 mov eax, edi
// 009e5be0  2b442410             sub eax, dword ptr [esp + 0x10]
// 009e5be4  2bce                 sub ecx, esi
// 009e5be6  33d2                 xor edx, edx
// 009e5be8  3bc8                 cmp ecx, eax
// 009e5bea  0f9fc2               setg dl
// 009e5bed  85d2                 test edx, edx
// 009e5bef  740e                 je 0x9e5bff
// 009e5bf1  83f804               cmp eax, 4
// 009e5bf4  7415                 je 0x9e5c0b
// 009e5bf6  83c7fc               add edi, -4
// 009e5bf9  897c2410             mov dword ptr [esp + 0x10], edi
// 009e5bfd  eb0c                 jmp 0x9e5c0b
// 009e5bff  83f904               cmp ecx, 4
// 009e5c02  7407                 je 0x9e5c0b
// 009e5c04  83c604               add esi, 4
// 009e5c07  8974241c             mov dword ptr [esp + 0x1c], esi
// 009e5c0b  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 009e5c0f  51                   push ecx
// 009e5c10  8d4c2424             lea ecx, [esp + 0x24]
// 009e5c14  e8e3390b00           call 0xa995fc
// 009e5c19  8b542414             mov edx, dword ptr [esp + 0x14]
// 009e5c1d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009e5c21  8b742410             mov esi, dword ptr [esp + 0x10]
// 009e5c25  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009e5c29  6849005a00           push 0x5a0049
// 009e5c2e  2bc2                 sub eax, edx
// 009e5c30  50                   push eax
// 009e5c31  2bce                 sub ecx, esi
// 009e5c33  51                   push ecx
// 009e5c34  52                   push edx
// 009e5c35  8b542434             mov edx, dword ptr [esp + 0x34]
// 009e5c39  56                   push esi
// 009e5c3a  52                   push edx
// 009e5c3b  ff153821b200         call dword ptr [0xb22138]
// 009e5c41  55                   push ebp
// 009e5c42  8d4c2424             lea ecx, [esp + 0x24]
// 009e5c46  e8ed390b00           call 0xa99638
// 009e5c4b  8d4c2420             lea ecx, [esp + 0x20]
// 009e5c4f  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 009e5c57  e83a390b00           call 0xa99596
// 009e5c5c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 009e5c60  64890d00000000       mov dword ptr fs:[0], ecx
// 009e5c67  59                   pop ecx
// 009e5c68  5f                   pop edi
// 009e5c69  5e                   pop esi
// 009e5c6a  5d                   pop ebp
// 009e5c6b  83c430               add esp, 0x30
// 009e5c6e  c20800               ret 8
// copied from an identical function in another client (function ?DrawTracker@CXTSplitterWnd@@MAEXABVCRect@@PAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1