// from server: 100% by auto
// roc 2009-06 0077c5a0  unit: CXTPTabClientWnd  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077c5a0
//
// 0077c5a0  8b442404             mov eax, dword ptr [esp + 4]
// 0077c5a4  85c0                 test eax, eax
// 0077c5a6  7449                 je 0x77c5f1
// 0077c5a8  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 0077c5ab  8b5060               mov edx, dword ptr [eax + 0x60]
// 0077c5ae  8d4101               lea eax, [ecx + 1]
// 0077c5b1  85c0                 test eax, eax
// 0077c5b3  7c11                 jl 0x77c5c6
// 0077c5b5  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 0077c5b8  7d0c                 jge 0x77c5c6
// 0077c5ba  56                   push esi
// 0077c5bb  8b7258               mov esi, dword ptr [edx + 0x58]
// 0077c5be  8b0486               mov eax, dword ptr [esi + eax*4]
// 0077c5c1  5e                   pop esi
// 0077c5c2  85c0                 test eax, eax
// 0077c5c4  7516                 jne 0x77c5dc
// 0077c5c6  8d41ff               lea eax, [ecx - 1]
// 0077c5c9  85c0                 test eax, eax
// 0077c5cb  7c24                 jl 0x77c5f1
// 0077c5cd  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 0077c5d0  7d1f                 jge 0x77c5f1
// 0077c5d2  8b4a58               mov ecx, dword ptr [edx + 0x58]
// 0077c5d5  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0077c5d8  85c0                 test eax, eax
// 0077c5da  7415                 je 0x77c5f1
// 0077c5dc  8bc8                 mov ecx, eax
// 0077c5de  e8ed4ff3ff           call 0x6b15d0
// 0077c5e3  85c0                 test eax, eax
// 0077c5e5  740a                 je 0x77c5f1
// 0077c5e7  89442404             mov dword ptr [esp + 4], eax
// 0077c5eb  ff2594ec8900         jmp dword ptr [0x89ec94]
// 0077c5f1  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?ActivateNextItem@CXTPTabClientWnd@@IAEXPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
