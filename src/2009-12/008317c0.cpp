// from server: 100% by auto
// roc 2009-12 008317c0  unit: CXTTreeBase  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008317c0
//
// 008317c0  56                   push esi
// 008317c1  57                   push edi
// 008317c2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008317c6  817f08f7fdffff       cmp dword ptr [edi + 8], 0xfffffdf7
// 008317cd  8bf1                 mov esi, ecx
// 008317cf  752d                 jne 0x8317fe
// 008317d1  8b4634               mov eax, dword ptr [esi + 0x34]
// 008317d4  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008317d7  6a00                 push 0
// 008317d9  6a00                 push 0
// 008317db  6819110000           push 0x1119
// 008317e0  51                   push ecx
// 008317e1  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008317e7  85c0                 test eax, eax
// 008317e9  7413                 je 0x8317fe
// 008317eb  6a13                 push 0x13
// 008317ed  6a00                 push 0
// 008317ef  6a00                 push 0
// 008317f1  6a00                 push 0
// 008317f3  6a00                 push 0
// 008317f5  6a00                 push 0
// 008317f7  50                   push eax
// 008317f8  ff15e0c99800         call dword ptr [0x98c9e0]
// 008317fe  8b542414             mov edx, dword ptr [esp + 0x14]
// 00831802  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00831806  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00831809  52                   push edx
// 0083180a  57                   push edi
// 0083180b  50                   push eax
// 0083180c  e8ab21fcff           call 0x7f39bc
// 00831811  5f                   pop edi
// 00831812  5e                   pop esi
// 00831813  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNotify@CXTPTreeBase@@MAEHIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
