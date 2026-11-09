// from server: 100% by auto
// roc 2010-06 0089b2f0  unit: CXTPScrollBase  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b2f0
//
// 0089b2f0  8b442408             mov eax, dword ptr [esp + 8]
// 0089b2f4  56                   push esi
// 0089b2f5  8b742408             mov esi, dword ptr [esp + 8]
// 0089b2f9  8b5640               mov edx, dword ptr [esi + 0x40]
// 0089b2fc  3bc2                 cmp eax, edx
// 0089b2fe  7d04                 jge 0x89b304
// 0089b300  8b06                 mov eax, dword ptr [esi]
// 0089b302  5e                   pop esi
// 0089b303  c3                   ret 
// 0089b304  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0089b307  57                   push edi
// 0089b308  8d3c11               lea edi, [ecx + edx]
// 0089b30b  3bc7                 cmp eax, edi
// 0089b30d  7c1c                 jl 0x89b32b
// 0089b30f  8b4608               mov eax, dword ptr [esi + 8]
// 0089b312  85c0                 test eax, eax
// 0089b314  740b                 je 0x89b321
// 0089b316  8d48ff               lea ecx, [eax - 1]
// 0089b319  8b4604               mov eax, dword ptr [esi + 4]
// 0089b31c  5f                   pop edi
// 0089b31d  2bc1                 sub eax, ecx
// 0089b31f  5e                   pop esi
// 0089b320  c3                   ret 
// 0089b321  8b4604               mov eax, dword ptr [esi + 4]
// 0089b324  33c9                 xor ecx, ecx
// 0089b326  5f                   pop edi
// 0089b327  2bc1                 sub eax, ecx
// 0089b329  5e                   pop esi
// 0089b32a  c3                   ret 
// 0089b32b  85c9                 test ecx, ecx
// 0089b32d  7423                 je 0x89b352
// 0089b32f  8b7e08               mov edi, dword ptr [esi + 8]
// 0089b332  85ff                 test edi, edi
// 0089b334  7403                 je 0x89b339
// 0089b336  4f                   dec edi
// 0089b337  eb02                 jmp 0x89b33b
// 0089b339  33ff                 xor edi, edi
// 0089b33b  2bc2                 sub eax, edx
// 0089b33d  51                   push ecx
// 0089b33e  50                   push eax
// 0089b33f  8b4604               mov eax, dword ptr [esi + 4]
// 0089b342  2b06                 sub eax, dword ptr [esi]
// 0089b344  2bc7                 sub eax, edi
// 0089b346  50                   push eax
// 0089b347  ff15c8a29e00         call dword ptr [0x9ea2c8]
// 0089b34d  0306                 add eax, dword ptr [esi]
// 0089b34f  5f                   pop edi
// 0089b350  5e                   pop esi
// 0089b351  c3                   ret 
// 0089b352  8b06                 mov eax, dword ptr [esi]
// 0089b354  5f                   pop edi
// 0089b355  48                   dec eax
// 0089b356  5e                   pop esi
// 0089b357  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?SBPosFromPx@@YAHPAUSCROLLBARPOSINFO@CXTPScrollBase@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
