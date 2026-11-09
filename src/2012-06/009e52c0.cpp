// roc 2012-06 009e52c0  unit: CXTSplitterWnd  size: 340 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e52c0
//
// 009e52c0  83ec08               sub esp, 8
// 009e52c3  55                   push ebp
// 009e52c4  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 009e52c8  56                   push esi
// 009e52c9  8bf1                 mov esi, ecx
// 009e52cb  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 009e52d1  83f8ff               cmp eax, -1
// 009e52d4  7412                 je 0x9e52e8
// 009e52d6  3bc5                 cmp eax, ebp
// 009e52d8  0f842e010000         je 0x9e540c
// 009e52de  8b06                 mov eax, dword ptr [esi]
// 009e52e0  8b90bc010000         mov edx, dword ptr [eax + 0x1bc]
// 009e52e6  ffd2                 call edx
// 009e52e8  8b06                 mov eax, dword ptr [esi]
// 009e52ea  8b8074010000         mov eax, dword ptr [eax + 0x174]
// 009e52f0  8d4c240c             lea ecx, [esp + 0xc]
// 009e52f4  51                   push ecx
// 009e52f5  8d54240c             lea edx, [esp + 0xc]
// 009e52f9  52                   push edx
// 009e52fa  8bce                 mov ecx, esi
// 009e52fc  89aef8000000         mov dword ptr [esi + 0xf8], ebp
// 009e5302  ffd0                 call eax
// 009e5304  85c0                 test eax, eax
// 009e5306  742f                 je 0x9e5337
// 009e5308  8b442408             mov eax, dword ptr [esp + 8]
// 009e530c  3bc5                 cmp eax, ebp
// 009e530e  7527                 jne 0x9e5337
// 009e5310  40                   inc eax
// 009e5311  3b8680000000         cmp eax, dword ptr [esi + 0x80]
// 009e5317  89442408             mov dword ptr [esp + 8], eax
// 009e531b  7c06                 jl 0x9e5323
// 009e531d  33c0                 xor eax, eax
// 009e531f  89442408             mov dword ptr [esp + 8], eax
// 009e5323  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e5327  8b16                 mov edx, dword ptr [esi]
// 009e5329  8b9278010000         mov edx, dword ptr [edx + 0x178]
// 009e532f  6a00                 push 0
// 009e5331  51                   push ecx
// 009e5332  50                   push eax
// 009e5333  8bce                 mov ecx, esi
// 009e5335  ffd2                 call edx
// 009e5337  53                   push ebx
// 009e5338  33db                 xor ebx, ebx
// 009e533a  399e84000000         cmp dword ptr [esi + 0x84], ebx
// 009e5340  57                   push edi
// 009e5341  0f8e96000000         jle 0x9e53dd
// 009e5347  53                   push ebx
// 009e5348  55                   push ebp
// 009e5349  8bce                 mov ecx, esi
// 009e534b  e8c2d8f9ff           call 0x982c12
// 009e5350  8bf8                 mov edi, eax
// 009e5352  85ff                 test edi, edi
// 009e5354  0f84b0000000         je 0x9e540a
// 009e535a  6a00                 push 0
// 009e535c  8bcf                 mov ecx, edi
// 009e535e  e841d7f9ff           call 0x982aa4
// 009e5363  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 009e5369  83f8ff               cmp eax, -1
// 009e536c  7407                 je 0x9e5375
// 009e536e  3bc3                 cmp eax, ebx
// 009e5370  8d4301               lea eax, [ebx + 1]
// 009e5373  7e02                 jle 0x9e5377
// 009e5375  8bc3                 mov eax, ebx
// 009e5377  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 009e537d  81c1900e0000         add ecx, 0xe90
// 009e5383  c1e104               shl ecx, 4
// 009e5386  03c8                 add ecx, eax
// 009e5388  51                   push ecx
// 009e5389  8bcf                 mov ecx, edi
// 009e538b  e870470b00           call 0xa99b00
// 009e5390  8d7d01               lea edi, [ebp + 1]
// 009e5393  3bbe80000000         cmp edi, dword ptr [esi + 0x80]
// 009e5399  7d35                 jge 0x9e53d0
// 009e539b  eb03                 jmp 0x9e53a0
// 009e539d  8d4900               lea ecx, [ecx]
// 009e53a0  53                   push ebx
// 009e53a1  57                   push edi
// 009e53a2  8bce                 mov ecx, esi
// 009e53a4  e869d8f9ff           call 0x982c12
// 009e53a9  8be8                 mov ebp, eax
// 009e53ab  85ed                 test ebp, ebp
// 009e53ad  745b                 je 0x9e540a
// 009e53af  53                   push ebx
// 009e53b0  8d57ff               lea edx, [edi - 1]
// 009e53b3  52                   push edx
// 009e53b4  8bce                 mov ecx, esi
// 009e53b6  e8b5d7f9ff           call 0x982b70
// 009e53bb  50                   push eax
// 009e53bc  8bcd                 mov ecx, ebp
// 009e53be  e83d470b00           call 0xa99b00
// 009e53c3  47                   inc edi
// 009e53c4  3bbe80000000         cmp edi, dword ptr [esi + 0x80]
// 009e53ca  7cd4                 jl 0x9e53a0
// 009e53cc  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 009e53d0  43                   inc ebx
// 009e53d1  3b9e84000000         cmp ebx, dword ptr [esi + 0x84]
// 009e53d7  0f8c6affffff         jl 0x9e5347
// 009e53dd  ff8e80000000         dec dword ptr [esi + 0x80]
// 009e53e3  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 009e53e9  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 009e53ef  8d546d00             lea edx, [ebp + ebp*2]
// 009e53f3  8b549108             mov edx, dword ptr [ecx + edx*4 + 8]
// 009e53f7  8d0440               lea eax, [eax + eax*2]
// 009e53fa  89548108             mov dword ptr [ecx + eax*4 + 8], edx
// 009e53fe  8b06                 mov eax, dword ptr [esi]
// 009e5400  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e5406  8bce                 mov ecx, esi
// 009e5408  ffd2                 call edx
// 009e540a  5f                   pop edi
// 009e540b  5b                   pop ebx
// 009e540c  5e                   pop esi
// 009e540d  5d                   pop ebp
// 009e540e  83c408               add esp, 8
// 009e5411  c20400               ret 4
// copied from an identical function in another client (function ?HideRow@CXTSplitterWnd@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1