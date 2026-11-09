// from server: 100% by auto
// roc 2007-03 0068c2b0  unit: seg_00680000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c2b0
//
// 0068c2b0  83ec10               sub esp, 0x10
// 0068c2b3  56                   push esi
// 0068c2b4  8bf1                 mov esi, ecx
// 0068c2b6  e81724f9ff           call 0x61e6d2
// 0068c2bb  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0068c2c1  50                   push eax
// 0068c2c2  ff1574ed7700         call dword ptr [0x77ed74]
// 0068c2c8  85c0                 test eax, eax
// 0068c2ca  7433                 je 0x68c2ff
// 0068c2cc  8b16                 mov edx, dword ptr [esi]
// 0068c2ce  8b9274010000         mov edx, dword ptr [edx + 0x174]
// 0068c2d4  57                   push edi
// 0068c2d5  8d442408             lea eax, [esp + 8]
// 0068c2d9  50                   push eax
// 0068c2da  8bce                 mov ecx, esi
// 0068c2dc  ffd2                 call edx
// 0068c2de  8b4804               mov ecx, dword ptr [eax + 4]
// 0068c2e1  8b780c               mov edi, dword ptr [eax + 0xc]
// 0068c2e4  8b10                 mov edx, dword ptr [eax]
// 0068c2e6  8b4008               mov eax, dword ptr [eax + 8]
// 0068c2e9  6a01                 push 1
// 0068c2eb  2bf9                 sub edi, ecx
// 0068c2ed  57                   push edi
// 0068c2ee  2bc2                 sub eax, edx
// 0068c2f0  50                   push eax
// 0068c2f1  51                   push ecx
// 0068c2f2  52                   push edx
// 0068c2f3  8d8edc000000         lea ecx, [esi + 0xdc]
// 0068c2f9  e8be21f9ff           call 0x61e4bc
// 0068c2fe  5f                   pop edi
// 0068c2ff  5e                   pop esi
// 0068c300  83c410               add esp, 0x10
// 0068c303  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnWindowPosChanged@CXTCaption@@IAEXPAUtagWINDOWPOS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
