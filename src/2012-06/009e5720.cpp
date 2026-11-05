// roc 2012-06 009e5720  unit: CXTSplitterWnd  size: 210 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5720
//
// 009e5720  6aff                 push -1
// 009e5722  68c80fae00           push 0xae0fc8
// 009e5727  64a100000000         mov eax, dword ptr fs:[0]
// 009e572d  50                   push eax
// 009e572e  51                   push ecx
// 009e572f  56                   push esi
// 009e5730  57                   push edi
// 009e5731  a1d027e000           mov eax, dword ptr [0xe027d0]
// 009e5736  33c4                 xor eax, esp
// 009e5738  50                   push eax
// 009e5739  8d442410             lea eax, [esp + 0x10]
// 009e573d  64a300000000         mov dword ptr fs:[0], eax
// 009e5743  8bf1                 mov esi, ecx
// 009e5745  8974240c             mov dword ptr [esp + 0xc], esi
// 009e5749  e8c4430b00           call 0xa99b12
// 009e574e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 009e5756  8dbedc000000         lea edi, [esi + 0xdc]
// 009e575c  e8eff5ffff           call 0x9e4d50
// 009e5761  50                   push eax
// 009e5762  8bcf                 mov ecx, edi
// 009e5764  e887160000           call 0x9e6df0
// 009e5769  83c8ff               or eax, 0xffffffff
// 009e576c  8bc8                 mov ecx, eax
// 009e576e  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 009e5774  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 009e577a  89860c010000         mov dword ptr [esi + 0x10c], eax
// 009e5780  b806000000           mov eax, 6
// 009e5785  6a00                 push 0
// 009e5787  894660               mov dword ptr [esi + 0x60], eax
// 009e578a  894664               mov dword ptr [esi + 0x64], eax
// 009e578d  894670               mov dword ptr [esi + 0x70], eax
// 009e5790  894674               mov dword ptr [esi + 0x74], eax
// 009e5793  8d86fc000000         lea eax, [esi + 0xfc]
// 009e5799  50                   push eax
// 009e579a  6a00                 push 0
// 009e579c  6a26                 push 0x26
// 009e579e  c7069475c100         mov dword ptr [esi], 0xc17594
// 009e57a4  c7078475c100         mov dword ptr [edi], 0xc17584
// 009e57aa  898e10010000         mov dword ptr [esi + 0x110], ecx
// 009e57b0  c7860801000002000000 mov dword ptr [esi + 0x108], 2
// 009e57ba  c7860401000001000000 mov dword ptr [esi + 0x104], 1
// 009e57c4  ff15543ab200         call dword ptr [0xb23a54]
// 009e57ca  c7860001000000000000 mov dword ptr [esi + 0x100], 0
// 009e57d4  c7861401000000000000 mov dword ptr [esi + 0x114], 0
// 009e57de  8bc6                 mov eax, esi
// 009e57e0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e57e4  64890d00000000       mov dword ptr fs:[0], ecx
// 009e57eb  59                   pop ecx
// 009e57ec  5f                   pop edi
// 009e57ed  5e                   pop esi
// 009e57ee  83c410               add esp, 0x10
// 009e57f1  c3                   ret 
// copied from an identical function in another client (function ??0CXTSplitterWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1