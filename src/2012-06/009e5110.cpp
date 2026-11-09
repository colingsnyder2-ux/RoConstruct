// roc 2012-06 009e5110  unit: CXTSplitterWnd  size: 423 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5110
//
// 009e5110  83ec0c               sub esp, 0xc
// 009e5113  56                   push esi
// 009e5114  8bf1                 mov esi, ecx
// 009e5116  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 009e511c  3b4658               cmp eax, dword ptr [esi + 0x58]
// 009e511f  750d                 jne 0x9e512e
// 009e5121  83bef8000000ff       cmp dword ptr [esi + 0xf8], -1
// 009e5128  0f8484010000         je 0x9e52b2
// 009e512e  8b9694000000         mov edx, dword ptr [esi + 0x94]
// 009e5134  53                   push ebx
// 009e5135  55                   push ebp
// 009e5136  57                   push edi
// 009e5137  8bbef8000000         mov edi, dword ptr [esi + 0xf8]
// 009e513d  8d0c40               lea ecx, [eax + eax*2]
// 009e5140  c786f8000000ffffffff mov dword ptr [esi + 0xf8], 0xffffffff
// 009e514a  8b4c8a08             mov ecx, dword ptr [edx + ecx*4 + 8]
// 009e514e  40                   inc eax
// 009e514f  33db                 xor ebx, ebx
// 009e5151  399e84000000         cmp dword ptr [esi + 0x84], ebx
// 009e5157  897c2410             mov dword ptr [esp + 0x10], edi
// 009e515b  894c2418             mov dword ptr [esp + 0x18], ecx
// 009e515f  898680000000         mov dword ptr [esi + 0x80], eax
// 009e5165  0f8eb0000000         jle 0x9e521b
// 009e516b  eb03                 jmp 0x9e5170
// 009e516d  8d4900               lea ecx, [ecx]
// 009e5170  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 009e5176  83f8ff               cmp eax, -1
// 009e5179  7407                 je 0x9e5182
// 009e517b  3bc3                 cmp eax, ebx
// 009e517d  8d4301               lea eax, [ebx + 1]
// 009e5180  7e02                 jle 0x9e5184
// 009e5182  8bc3                 mov eax, ebx
// 009e5184  8b9680000000         mov edx, dword ptr [esi + 0x80]
// 009e518a  81c2900e0000         add edx, 0xe90
// 009e5190  c1e204               shl edx, 4
// 009e5193  03d0                 add edx, eax
// 009e5195  52                   push edx
// 009e5196  8bce                 mov ecx, esi
// 009e5198  e853def9ff           call 0x982ff0
// 009e519d  8be8                 mov ebp, eax
// 009e519f  896c2414             mov dword ptr [esp + 0x14], ebp
// 009e51a3  85ed                 test ebp, ebp
// 009e51a5  0f8404010000         je 0x9e52af
// 009e51ab  6a08                 push 8
// 009e51ad  8bcd                 mov ecx, ebp
// 009e51af  e8f0d8f9ff           call 0x982aa4
// 009e51b4  8bbe80000000         mov edi, dword ptr [esi + 0x80]
// 009e51ba  83ef02               sub edi, 2
// 009e51bd  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 009e51c1  7c32                 jl 0x9e51f5
// 009e51c3  53                   push ebx
// 009e51c4  57                   push edi
// 009e51c5  8bce                 mov ecx, esi
// 009e51c7  e846daf9ff           call 0x982c12
// 009e51cc  8be8                 mov ebp, eax
// 009e51ce  85ed                 test ebp, ebp
// 009e51d0  0f84d9000000         je 0x9e52af
// 009e51d6  53                   push ebx
// 009e51d7  8d4701               lea eax, [edi + 1]
// 009e51da  50                   push eax
// 009e51db  8bce                 mov ecx, esi
// 009e51dd  e88ed9f9ff           call 0x982b70
// 009e51e2  50                   push eax
// 009e51e3  8bcd                 mov ecx, ebp
// 009e51e5  e816490b00           call 0xa99b00
// 009e51ea  4f                   dec edi
// 009e51eb  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 009e51ef  7dd2                 jge 0x9e51c3
// 009e51f1  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 009e51f5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e51f9  53                   push ebx
// 009e51fa  51                   push ecx
// 009e51fb  8bce                 mov ecx, esi
// 009e51fd  e86ed9f9ff           call 0x982b70
// 009e5202  50                   push eax
// 009e5203  8bcd                 mov ecx, ebp
// 009e5205  e8f6480b00           call 0xa99b00
// 009e520a  43                   inc ebx
// 009e520b  3b9e84000000         cmp ebx, dword ptr [esi + 0x84]
// 009e5211  0f8c59ffffff         jl 0x9e5170
// 009e5217  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 009e521b  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 009e5221  83f8ff               cmp eax, -1
// 009e5224  7431                 je 0x9e5257
// 009e5226  8b9680000000         mov edx, dword ptr [esi + 0x80]
// 009e522c  81c2900e0000         add edx, 0xe90
// 009e5232  c1e204               shl edx, 4
// 009e5235  03d0                 add edx, eax
// 009e5237  52                   push edx
// 009e5238  8bce                 mov ecx, esi
// 009e523a  e8b1ddf9ff           call 0x982ff0
// 009e523f  85c0                 test eax, eax
// 009e5241  7414                 je 0x9e5257
// 009e5243  8d8f900e0000         lea ecx, [edi + 0xe90]
// 009e5249  c1e104               shl ecx, 4
// 009e524c  034e5c               add ecx, dword ptr [esi + 0x5c]
// 009e524f  51                   push ecx
// 009e5250  8bc8                 mov ecx, eax
// 009e5252  e8a9480b00           call 0xa99b00
// 009e5257  8d4f01               lea ecx, [edi + 1]
// 009e525a  3b8e80000000         cmp ecx, dword ptr [esi + 0x80]
// 009e5260  7d29                 jge 0x9e528b
// 009e5262  8d1449               lea edx, [ecx + ecx*2]
// 009e5265  03d2                 add edx, edx
// 009e5267  03d2                 add edx, edx
// 009e5269  8da42400000000       lea esp, [esp]
// 009e5270  8b8694000000         mov eax, dword ptr [esi + 0x94]
// 009e5276  8b5c10fc             mov ebx, dword ptr [eax + edx - 4]
// 009e527a  03c2                 add eax, edx
// 009e527c  41                   inc ecx
// 009e527d  895804               mov dword ptr [eax + 4], ebx
// 009e5280  83c20c               add edx, 0xc
// 009e5283  3b8e80000000         cmp ecx, dword ptr [esi + 0x80]
// 009e5289  7ce5                 jl 0x9e5270
// 009e528b  8b9694000000         mov edx, dword ptr [esi + 0x94]
// 009e5291  8b442418             mov eax, dword ptr [esp + 0x18]
// 009e5295  8d0c7f               lea ecx, [edi + edi*2]
// 009e5298  5f                   pop edi
// 009e5299  89448a04             mov dword ptr [edx + ecx*4 + 4], eax
// 009e529d  8b16                 mov edx, dword ptr [esi]
// 009e529f  8b8250010000         mov eax, dword ptr [edx + 0x150]
// 009e52a5  5d                   pop ebp
// 009e52a6  5b                   pop ebx
// 009e52a7  8bce                 mov ecx, esi
// 009e52a9  5e                   pop esi
// 009e52aa  83c40c               add esp, 0xc
// 009e52ad  ffe0                 jmp eax
// 009e52af  5f                   pop edi
// 009e52b0  5d                   pop ebp
// 009e52b1  5b                   pop ebx
// 009e52b2  5e                   pop esi
// 009e52b3  83c40c               add esp, 0xc
// 009e52b6  c3                   ret 
// copied from an identical function in another client (function ?ShowRow@CXTSplitterWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1