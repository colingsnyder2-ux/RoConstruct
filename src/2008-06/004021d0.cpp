// from server: 100% by auto
// roc 2008-06 004021d0  unit: VCWorkspace::?$CComObject  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004021d0
//
// 004021d0  51                   push ecx
// 004021d1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004021d5  6a00                 push 0
// 004021d7  6a00                 push 0
// 004021d9  6a00                 push 0
// 004021db  6a00                 push 0
// 004021dd  6a00                 push 0
// 004021df  6a00                 push 0
// 004021e1  6a00                 push 0
// 004021e3  8d44241c             lea eax, [esp + 0x1c]
// 004021e7  50                   push eax
// 004021e8  6a00                 push 0
// 004021ea  6a00                 push 0
// 004021ec  6a00                 push 0
// 004021ee  51                   push ecx
// 004021ef  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004021f7  ff1518208000         call dword ptr [0x802018]
// 004021fd  85c0                 test eax, eax
// 004021ff  7406                 je 0x402207
// 00402201  33c0                 xor eax, eax
// 00402203  59                   pop ecx
// 00402204  c20400               ret 4
// 00402207  33d2                 xor edx, edx
// 00402209  3b1424               cmp edx, dword ptr [esp]
// 0040220c  1bc0                 sbb eax, eax
// 0040220e  f7d8                 neg eax
// 00402210  59                   pop ecx
// 00402211  c20400               ret 4
// library atl-8.0/atl.cpp (function ?HasSubKeys@CRegParser@ATL@@IAEHPAUHKEY__@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
