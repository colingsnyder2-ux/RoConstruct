// from server: 100% by auto
// roc 2009-12 008eae90  unit: CXTPScrollBase  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eae90
//
// 008eae90  8b442408             mov eax, dword ptr [esp + 8]
// 008eae94  56                   push esi
// 008eae95  8b742408             mov esi, dword ptr [esp + 8]
// 008eae99  8b5640               mov edx, dword ptr [esi + 0x40]
// 008eae9c  3bc2                 cmp eax, edx
// 008eae9e  7d04                 jge 0x8eaea4
// 008eaea0  8b06                 mov eax, dword ptr [esi]
// 008eaea2  5e                   pop esi
// 008eaea3  c3                   ret 
// 008eaea4  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 008eaea7  57                   push edi
// 008eaea8  8d3c11               lea edi, [ecx + edx]
// 008eaeab  3bc7                 cmp eax, edi
// 008eaead  7c1c                 jl 0x8eaecb
// 008eaeaf  8b4608               mov eax, dword ptr [esi + 8]
// 008eaeb2  85c0                 test eax, eax
// 008eaeb4  740b                 je 0x8eaec1
// 008eaeb6  8d48ff               lea ecx, [eax - 1]
// 008eaeb9  8b4604               mov eax, dword ptr [esi + 4]
// 008eaebc  5f                   pop edi
// 008eaebd  2bc1                 sub eax, ecx
// 008eaebf  5e                   pop esi
// 008eaec0  c3                   ret 
// 008eaec1  8b4604               mov eax, dword ptr [esi + 4]
// 008eaec4  33c9                 xor ecx, ecx
// 008eaec6  5f                   pop edi
// 008eaec7  2bc1                 sub eax, ecx
// 008eaec9  5e                   pop esi
// 008eaeca  c3                   ret 
// 008eaecb  85c9                 test ecx, ecx
// 008eaecd  7423                 je 0x8eaef2
// 008eaecf  8b7e08               mov edi, dword ptr [esi + 8]
// 008eaed2  85ff                 test edi, edi
// 008eaed4  7403                 je 0x8eaed9
// 008eaed6  4f                   dec edi
// 008eaed7  eb02                 jmp 0x8eaedb
// 008eaed9  33ff                 xor edi, edi
// 008eaedb  2bc2                 sub eax, edx
// 008eaedd  51                   push ecx
// 008eaede  50                   push eax
// 008eaedf  8b4604               mov eax, dword ptr [esi + 4]
// 008eaee2  2b06                 sub eax, dword ptr [esi]
// 008eaee4  2bc7                 sub eax, edi
// 008eaee6  50                   push eax
// 008eaee7  ff15a0b29800         call dword ptr [0x98b2a0]
// 008eaeed  0306                 add eax, dword ptr [esi]
// 008eaeef  5f                   pop edi
// 008eaef0  5e                   pop esi
// 008eaef1  c3                   ret 
// 008eaef2  8b06                 mov eax, dword ptr [esi]
// 008eaef4  5f                   pop edi
// 008eaef5  48                   dec eax
// 008eaef6  5e                   pop esi
// 008eaef7  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SBPosFromPx@@YAHPAUSCROLLBARPOSINFO@CXTPScrollBase@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
