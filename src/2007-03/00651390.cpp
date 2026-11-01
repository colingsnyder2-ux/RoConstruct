// from server: 100% by auto
// roc 2007-03 00651390  unit: seg_00650000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651390
//
// 00651390  56                   push esi
// 00651391  57                   push edi
// 00651392  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00651396  817f08f7fdffff       cmp dword ptr [edi + 8], 0xfffffdf7
// 0065139d  8bf1                 mov esi, ecx
// 0065139f  752d                 jne 0x6513ce
// 006513a1  8b4634               mov eax, dword ptr [esi + 0x34]
// 006513a4  8b4820               mov ecx, dword ptr [eax + 0x20]
// 006513a7  6a00                 push 0
// 006513a9  6a00                 push 0
// 006513ab  6819110000           push 0x1119
// 006513b0  51                   push ecx
// 006513b1  ff1550ee7700         call dword ptr [0x77ee50]
// 006513b7  85c0                 test eax, eax
// 006513b9  7413                 je 0x6513ce
// 006513bb  6a13                 push 0x13
// 006513bd  6a00                 push 0
// 006513bf  6a00                 push 0
// 006513c1  6a00                 push 0
// 006513c3  6a00                 push 0
// 006513c5  6a00                 push 0
// 006513c7  50                   push eax
// 006513c8  ff156cef7700         call dword ptr [0x77ef6c]
// 006513ce  8b542414             mov edx, dword ptr [esp + 0x14]
// 006513d2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006513d6  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 006513d9  52                   push edx
// 006513da  57                   push edi
// 006513db  50                   push eax
// 006513dc  e871cefcff           call 0x61e252
// 006513e1  5f                   pop edi
// 006513e2  5e                   pop esi
// 006513e3  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnNotify@CXTPTreeBase@@MAEHIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
