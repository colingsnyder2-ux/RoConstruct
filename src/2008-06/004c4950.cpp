// from server: 100% by auto
// roc 2008-06 004c4950  unit: ProfiledRakPeer  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4950
//
// 004c4950  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c4954  8b542408             mov edx, dword ptr [esp + 8]
// 004c4958  56                   push esi
// 004c4959  57                   push edi
// 004c495a  50                   push eax
// 004c495b  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c495f  8bf1                 mov esi, ecx
// 004c4961  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c4965  6a00                 push 0
// 004c4967  51                   push ecx
// 004c4968  52                   push edx
// 004c4969  50                   push eax
// 004c496a  8bce                 mov ecx, esi
// 004c496c  e8cfdeffff           call 0x4c2840
// 004c4971  33ff                 xor edi, edi
// 004c4973  39beac020000         cmp dword ptr [esi + 0x2ac], edi
// 004c4979  7629                 jbe 0x4c49a4
// 004c497b  eb03                 jmp 0x4c4980
// 004c497d  8d4900               lea ecx, [ecx]
// 004c4980  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c4984  8b8ea8020000         mov ecx, dword ptr [esi + 0x2a8]
// 004c498a  8b0cb9               mov ecx, dword ptr [ecx + edi*4]
// 004c498d  8b11                 mov edx, dword ptr [ecx]
// 004c498f  8b521c               mov edx, dword ptr [edx + 0x1c]
// 004c4992  50                   push eax
// 004c4993  8b442410             mov eax, dword ptr [esp + 0x10]
// 004c4997  50                   push eax
// 004c4998  56                   push esi
// 004c4999  ffd2                 call edx
// 004c499b  47                   inc edi
// 004c499c  3bbeac020000         cmp edi, dword ptr [esi + 0x2ac]
// 004c49a2  72dc                 jb 0x4c4980
// 004c49a4  5f                   pop edi
// 004c49a5  5e                   pop esi
// 004c49a6  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?CloseConnection@RakPeer@@UAEXUSystemAddress@@_NE@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
