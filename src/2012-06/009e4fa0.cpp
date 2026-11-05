// roc 2012-06 009e4fa0  unit: CXTSplitterWnd  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e4fa0
//
// 009e4fa0  83ec0c               sub esp, 0xc
// 009e4fa3  55                   push ebp
// 009e4fa4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 009e4fa8  56                   push esi
// 009e4fa9  8bf1                 mov esi, ecx
// 009e4fab  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 009e4fb1  83f8ff               cmp eax, -1
// 009e4fb4  7412                 je 0x9e4fc8
// 009e4fb6  3bc5                 cmp eax, ebp
// 009e4fb8  0f843b010000         je 0x9e50f9
// 009e4fbe  8b06                 mov eax, dword ptr [esi]
// 009e4fc0  8b90b4010000         mov edx, dword ptr [eax + 0x1b4]
// 009e4fc6  ffd2                 call edx
// 009e4fc8  8b06                 mov eax, dword ptr [esi]
// 009e4fca  8b8074010000         mov eax, dword ptr [eax + 0x174]
// 009e4fd0  8d4c240c             lea ecx, [esp + 0xc]
// 009e4fd4  51                   push ecx
// 009e4fd5  8d542414             lea edx, [esp + 0x14]
// 009e4fd9  52                   push edx
// 009e4fda  8bce                 mov ecx, esi
// 009e4fdc  89aef4000000         mov dword ptr [esi + 0xf4], ebp
// 009e4fe2  ffd0                 call eax
// 009e4fe4  85c0                 test eax, eax
// 009e4fe6  742f                 je 0x9e5017
// 009e4fe8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009e4fec  3bc5                 cmp eax, ebp
// 009e4fee  7527                 jne 0x9e5017
// 009e4ff0  40                   inc eax
// 009e4ff1  3b8684000000         cmp eax, dword ptr [esi + 0x84]
// 009e4ff7  8944240c             mov dword ptr [esp + 0xc], eax
// 009e4ffb  7c06                 jl 0x9e5003
// 009e4ffd  33c0                 xor eax, eax
// 009e4fff  8944240c             mov dword ptr [esp + 0xc], eax
// 009e5003  8b16                 mov edx, dword ptr [esi]
// 009e5005  8b9278010000         mov edx, dword ptr [edx + 0x178]
// 009e500b  6a00                 push 0
// 009e500d  50                   push eax
// 009e500e  8b442418             mov eax, dword ptr [esp + 0x18]
// 009e5012  50                   push eax
// 009e5013  8bce                 mov ecx, esi
// 009e5015  ffd2                 call edx
// 009e5017  53                   push ebx
// 009e5018  33db                 xor ebx, ebx
// 009e501a  399e80000000         cmp dword ptr [esi + 0x80], ebx
// 009e5020  57                   push edi
// 009e5021  0f8ea3000000         jle 0x9e50ca
// 009e5027  895c2410             mov dword ptr [esp + 0x10], ebx
// 009e502b  eb03                 jmp 0x9e5030
// 009e502d  8d4900               lea ecx, [ecx]
// 009e5030  55                   push ebp
// 009e5031  53                   push ebx
// 009e5032  8bce                 mov ecx, esi
// 009e5034  e8d9dbf9ff           call 0x982c12
// 009e5039  8bf8                 mov edi, eax
// 009e503b  85ff                 test edi, edi
// 009e503d  0f84b4000000         je 0x9e50f7
// 009e5043  6a00                 push 0
// 009e5045  8bcf                 mov ecx, edi
// 009e5047  e858daf9ff           call 0x982aa4
// 009e504c  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 009e5052  83f8ff               cmp eax, -1
// 009e5055  740d                 je 0x9e5064
// 009e5057  3bc3                 cmp eax, ebx
// 009e5059  7f09                 jg 0x9e5064
// 009e505b  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e505f  83c010               add eax, 0x10
// 009e5062  eb04                 jmp 0x9e5068
// 009e5064  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e5068  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 009e506e  0500e90000           add eax, 0xe900
// 009e5073  03c8                 add ecx, eax
// 009e5075  51                   push ecx
// 009e5076  8bcf                 mov ecx, edi
// 009e5078  e8834a0b00           call 0xa99b00
// 009e507d  8d7d01               lea edi, [ebp + 1]
// 009e5080  3bbe84000000         cmp edi, dword ptr [esi + 0x84]
// 009e5086  7d30                 jge 0x9e50b8
// 009e5088  57                   push edi
// 009e5089  53                   push ebx
// 009e508a  8bce                 mov ecx, esi
// 009e508c  e881dbf9ff           call 0x982c12
// 009e5091  8be8                 mov ebp, eax
// 009e5093  85ed                 test ebp, ebp
// 009e5095  7460                 je 0x9e50f7
// 009e5097  8d57ff               lea edx, [edi - 1]
// 009e509a  52                   push edx
// 009e509b  53                   push ebx
// 009e509c  8bce                 mov ecx, esi
// 009e509e  e8cddaf9ff           call 0x982b70
// 009e50a3  50                   push eax
// 009e50a4  8bcd                 mov ecx, ebp
// 009e50a6  e8554a0b00           call 0xa99b00
// 009e50ab  47                   inc edi
// 009e50ac  3bbe84000000         cmp edi, dword ptr [esi + 0x84]
// 009e50b2  7cd4                 jl 0x9e5088
// 009e50b4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 009e50b8  8344241010           add dword ptr [esp + 0x10], 0x10
// 009e50bd  43                   inc ebx
// 009e50be  3b9e80000000         cmp ebx, dword ptr [esi + 0x80]
// 009e50c4  0f8c66ffffff         jl 0x9e5030
// 009e50ca  ff8e84000000         dec dword ptr [esi + 0x84]
// 009e50d0  8b8e90000000         mov ecx, dword ptr [esi + 0x90]
// 009e50d6  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 009e50dc  8d546d00             lea edx, [ebp + ebp*2]
// 009e50e0  8b549108             mov edx, dword ptr [ecx + edx*4 + 8]
// 009e50e4  8d0440               lea eax, [eax + eax*2]
// 009e50e7  89548108             mov dword ptr [ecx + eax*4 + 8], edx
// 009e50eb  8b06                 mov eax, dword ptr [esi]
// 009e50ed  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e50f3  8bce                 mov ecx, esi
// 009e50f5  ffd2                 call edx
// 009e50f7  5f                   pop edi
// 009e50f8  5b                   pop ebx
// 009e50f9  5e                   pop esi
// 009e50fa  5d                   pop ebp
// 009e50fb  83c40c               add esp, 0xc
// 009e50fe  c20400               ret 4
// copied from an identical function in another client (function ?HideColumn@CXTSplitterWnd@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1