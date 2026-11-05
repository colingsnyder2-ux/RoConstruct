// roc 2012-06 009e5cc0  unit: CXTSplitterWnd  size: 409 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5cc0
//
// 009e5cc0  51                   push ecx
// 009e5cc1  56                   push esi
// 009e5cc2  8bf1                 mov esi, ecx
// 009e5cc4  83befc00000000       cmp dword ptr [esi + 0xfc], 0
// 009e5ccb  c7861401000000000000 mov dword ptr [esi + 0x114], 0
// 009e5cd5  7537                 jne 0x9e5d0e
// 009e5cd7  e8f6380b00           call 0xa995d2
// 009e5cdc  a900000002           test eax, 0x2000000
// 009e5ce1  741a                 je 0x9e5cfd
// 009e5ce3  6a00                 push 0
// 009e5ce5  6a00                 push 0
// 009e5ce7  6800000006           push 0x6000000
// 009e5cec  8bce                 mov ecx, esi
// 009e5cee  e865cbf9ff           call 0x982858
// 009e5cf3  c7861401000001000000 mov dword ptr [esi + 0x114], 1
// 009e5cfd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009e5d01  50                   push eax
// 009e5d02  8bce                 mov ecx, esi
// 009e5d04  e81b3e0b00           call 0xa99b24
// 009e5d09  5e                   pop esi
// 009e5d0a  59                   pop ecx
// 009e5d0b  c20400               ret 4
// 009e5d0e  53                   push ebx
// 009e5d0f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 009e5d13  85db                 test ebx, ebx
// 009e5d15  0f8438010000         je 0x9e5e53
// 009e5d1b  8b16                 mov edx, dword ptr [esi]
// 009e5d1d  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 009e5d23  55                   push ebp
// 009e5d24  57                   push edi
// 009e5d25  8dbea8000000         lea edi, [esi + 0xa8]
// 009e5d2b  57                   push edi
// 009e5d2c  ffd0                 call eax
// 009e5d2e  8d8bd3feffff         lea ecx, [ebx - 0x12d]
// 009e5d34  81f9e0000000         cmp ecx, 0xe0
// 009e5d3a  775c                 ja 0x9e5d98
// 009e5d3c  8d83d3feffff         lea eax, [ebx - 0x12d]
// 009e5d42  99                   cdq 
// 009e5d43  b90f000000           mov ecx, 0xf
// 009e5d48  f7f9                 idiv ecx
// 009e5d4a  8d8eb8000000         lea ecx, [esi + 0xb8]
// 009e5d50  51                   push ecx
// 009e5d51  8bce                 mov ecx, esi
// 009e5d53  8bfa                 mov edi, edx
// 009e5d55  8b16                 mov edx, dword ptr [esi]
// 009e5d57  8b9298010000         mov edx, dword ptr [edx + 0x198]
// 009e5d5d  83c065               add eax, 0x65
// 009e5d60  50                   push eax
// 009e5d61  ffd2                 call edx
// 009e5d63  8b06                 mov eax, dword ptr [esi]
// 009e5d65  8b9098010000         mov edx, dword ptr [eax + 0x198]
// 009e5d6b  8baea4000000         mov ebp, dword ptr [esi + 0xa4]
// 009e5d71  8d8ec8000000         lea ecx, [esi + 0xc8]
// 009e5d77  51                   push ecx
// 009e5d78  81c7c9000000         add edi, 0xc9
// 009e5d7e  57                   push edi
// 009e5d7f  8bce                 mov ecx, esi
// 009e5d81  c7869c00000001000000 mov dword ptr [esi + 0x9c], 1
// 009e5d8b  ffd2                 call edx
// 009e5d8d  89aea4000000         mov dword ptr [esi + 0xa4], ebp
// 009e5d93  e98c000000           jmp 0x9e5e24
// 009e5d98  8bce                 mov ecx, esi
// 009e5d9a  83fb03               cmp ebx, 3
// 009e5d9d  7573                 jne 0x9e5e12
// 009e5d9f  8b06                 mov eax, dword ptr [esi]
// 009e5da1  8b9098010000         mov edx, dword ptr [eax + 0x198]
// 009e5da7  8d9eb8000000         lea ebx, [esi + 0xb8]
// 009e5dad  53                   push ebx
// 009e5dae  6a01                 push 1
// 009e5db0  ffd2                 call edx
// 009e5db2  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 009e5db8  8b16                 mov edx, dword ptr [esi]
// 009e5dba  8daec8000000         lea ebp, [esi + 0xc8]
// 009e5dc0  55                   push ebp
// 009e5dc1  89442414             mov dword ptr [esp + 0x14], eax
// 009e5dc5  8b8298010000         mov eax, dword ptr [edx + 0x198]
// 009e5dcb  6a02                 push 2
// 009e5dcd  8bce                 mov ecx, esi
// 009e5dcf  c7869c00000001000000 mov dword ptr [esi + 0x9c], 1
// 009e5dd9  ffd0                 call eax
// 009e5ddb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e5ddf  898ea4000000         mov dword ptr [esi + 0xa4], ecx
// 009e5de5  8b470c               mov eax, dword ptr [edi + 0xc]
// 009e5de8  2b4704               sub eax, dword ptr [edi + 4]
// 009e5deb  99                   cdq 
// 009e5dec  2bc2                 sub eax, edx
// 009e5dee  d1f8                 sar eax, 1
// 009e5df0  50                   push eax
// 009e5df1  6a00                 push 0
// 009e5df3  53                   push ebx
// 009e5df4  8b1df43ab200         mov ebx, dword ptr [0xb23af4]
// 009e5dfa  ffd3                 call ebx
// 009e5dfc  8b4708               mov eax, dword ptr [edi + 8]
// 009e5dff  2b07                 sub eax, dword ptr [edi]
// 009e5e01  6a00                 push 0
// 009e5e03  99                   cdq 
// 009e5e04  2bc2                 sub eax, edx
// 009e5e06  d1f8                 sar eax, 1
// 009e5e08  50                   push eax
// 009e5e09  55                   push ebp
// 009e5e0a  ffd3                 call ebx
// 009e5e0c  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 009e5e10  eb12                 jmp 0x9e5e24
// 009e5e12  8b16                 mov edx, dword ptr [esi]
// 009e5e14  8b9298010000         mov edx, dword ptr [edx + 0x198]
// 009e5e1a  8d86b8000000         lea eax, [esi + 0xb8]
// 009e5e20  50                   push eax
// 009e5e21  53                   push ebx
// 009e5e22  ffd2                 call edx
// 009e5e24  8b4620               mov eax, dword ptr [esi + 0x20]
// 009e5e27  50                   push eax
// 009e5e28  ff15803ab200         call dword ptr [0xb23a80]
// 009e5e2e  50                   push eax
// 009e5e2f  e832c8f9ff           call 0x982666
// 009e5e34  8b16                 mov edx, dword ptr [esi]
// 009e5e36  8b82a8010000         mov eax, dword ptr [edx + 0x1a8]
// 009e5e3c  53                   push ebx
// 009e5e3d  8bce                 mov ecx, esi
// 009e5e3f  c7869800000001000000 mov dword ptr [esi + 0x98], 1
// 009e5e49  899ed8000000         mov dword ptr [esi + 0xd8], ebx
// 009e5e4f  ffd0                 call eax
// 009e5e51  5f                   pop edi
// 009e5e52  5d                   pop ebp
// 009e5e53  5b                   pop ebx
// 009e5e54  5e                   pop esi
// 009e5e55  59                   pop ecx
// 009e5e56  c20400               ret 4
// copied from an identical function in another client (function ?StartTracking@CXTSplitterWnd@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1