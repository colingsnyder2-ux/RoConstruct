// from server: 100% by auto
// roc 2010-06 0080b5e0  unit: CXTPTabClientWnd  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080b5e0
//
// 0080b5e0  8b442404             mov eax, dword ptr [esp + 4]
// 0080b5e4  85c0                 test eax, eax
// 0080b5e6  7449                 je 0x80b631
// 0080b5e8  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 0080b5eb  8b5060               mov edx, dword ptr [eax + 0x60]
// 0080b5ee  8d4101               lea eax, [ecx + 1]
// 0080b5f1  85c0                 test eax, eax
// 0080b5f3  7c11                 jl 0x80b606
// 0080b5f5  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 0080b5f8  7d0c                 jge 0x80b606
// 0080b5fa  56                   push esi
// 0080b5fb  8b7258               mov esi, dword ptr [edx + 0x58]
// 0080b5fe  8b0486               mov eax, dword ptr [esi + eax*4]
// 0080b601  5e                   pop esi
// 0080b602  85c0                 test eax, eax
// 0080b604  7516                 jne 0x80b61c
// 0080b606  8d41ff               lea eax, [ecx - 1]
// 0080b609  85c0                 test eax, eax
// 0080b60b  7c24                 jl 0x80b631
// 0080b60d  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 0080b610  7d1f                 jge 0x80b631
// 0080b612  8b4a58               mov ecx, dword ptr [edx + 0x58]
// 0080b615  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0080b618  85c0                 test eax, eax
// 0080b61a  7415                 je 0x80b631
// 0080b61c  8bc8                 mov ecx, eax
// 0080b61e  e8cd4aebff           call 0x6c00f0
// 0080b623  85c0                 test eax, eax
// 0080b625  740a                 je 0x80b631
// 0080b627  89442404             mov dword ptr [esp + 4], eax
// 0080b62b  ff25fcb99e00         jmp dword ptr [0x9eb9fc]
// 0080b631  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?ActivateNextItem@CXTPTabClientWnd@@IAEXPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
