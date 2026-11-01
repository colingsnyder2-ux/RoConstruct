// from server: 100% by auto
// roc 2009-06 008102f0  unit: CXTPScrollBase  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008102f0
//
// 008102f0  8b442408             mov eax, dword ptr [esp + 8]
// 008102f4  56                   push esi
// 008102f5  8b742408             mov esi, dword ptr [esp + 8]
// 008102f9  8b5640               mov edx, dword ptr [esi + 0x40]
// 008102fc  3bc2                 cmp eax, edx
// 008102fe  7d04                 jge 0x810304
// 00810300  8b06                 mov eax, dword ptr [esi]
// 00810302  5e                   pop esi
// 00810303  c3                   ret 
// 00810304  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00810307  57                   push edi
// 00810308  8d3c11               lea edi, [ecx + edx]
// 0081030b  3bc7                 cmp eax, edi
// 0081030d  7c1c                 jl 0x81032b
// 0081030f  8b4608               mov eax, dword ptr [esi + 8]
// 00810312  85c0                 test eax, eax
// 00810314  740b                 je 0x810321
// 00810316  8d48ff               lea ecx, [eax - 1]
// 00810319  8b4604               mov eax, dword ptr [esi + 4]
// 0081031c  5f                   pop edi
// 0081031d  2bc1                 sub eax, ecx
// 0081031f  5e                   pop esi
// 00810320  c3                   ret 
// 00810321  8b4604               mov eax, dword ptr [esi + 4]
// 00810324  33c9                 xor ecx, ecx
// 00810326  5f                   pop edi
// 00810327  2bc1                 sub eax, ecx
// 00810329  5e                   pop esi
// 0081032a  c3                   ret 
// 0081032b  85c9                 test ecx, ecx
// 0081032d  7423                 je 0x810352
// 0081032f  8b7e08               mov edi, dword ptr [esi + 8]
// 00810332  85ff                 test edi, edi
// 00810334  7403                 je 0x810339
// 00810336  4f                   dec edi
// 00810337  eb02                 jmp 0x81033b
// 00810339  33ff                 xor edi, edi
// 0081033b  2bc2                 sub eax, edx
// 0081033d  51                   push ecx
// 0081033e  50                   push eax
// 0081033f  8b4604               mov eax, dword ptr [esi + 4]
// 00810342  2b06                 sub eax, dword ptr [esi]
// 00810344  2bc7                 sub eax, edi
// 00810346  50                   push eax
// 00810347  ff1574e28900         call dword ptr [0x89e274]
// 0081034d  0306                 add eax, dword ptr [esi]
// 0081034f  5f                   pop edi
// 00810350  5e                   pop esi
// 00810351  c3                   ret 
// 00810352  8b06                 mov eax, dword ptr [esi]
// 00810354  5f                   pop edi
// 00810355  48                   dec eax
// 00810356  5e                   pop esi
// 00810357  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SBPosFromPx@@YAHPAUSCROLLBARPOSINFO@CXTPScrollBase@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
