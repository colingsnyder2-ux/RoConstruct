// roc 2012-06 005bba10  unit: RakNet::RakPeer  size: 177 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bba10
//
// 005bba10  51                   push ecx
// 005bba11  890c24               mov dword ptr [esp], ecx
// 005bba14  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005bba17  b8af7ed051           mov eax, 0x51d07eaf
// 005bba1c  f7e1                 mul ecx
// 005bba1e  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bba22  53                   push ebx
// 005bba23  55                   push ebp
// 005bba24  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005bba28  56                   push esi
// 005bba29  57                   push edi
// 005bba2a  8bf1                 mov esi, ecx
// 005bba2c  2bf2                 sub esi, edx
// 005bba2e  55                   push ebp
// 005bba2f  d1ee                 shr esi, 1
// 005bba31  50                   push eax
// 005bba32  03f2                 add esi, edx
// 005bba34  51                   push ecx
// 005bba35  33db                 xor ebx, ebx
// 005bba37  c1ee0a               shr esi, 0xa
// 005bba3a  ff159404d900         call dword ptr [0xd90494]
// 005bba40  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005bba44  83c40c               add esp, 0xc
// 005bba47  894708               mov dword ptr [edi + 8], eax
// 005bba4a  85c0                 test eax, eax
// 005bba4c  7430                 je 0x5bba7e
// 005bba4e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bba52  55                   push ebp
// 005bba53  51                   push ecx
// 005bba54  8d14b500000000       lea edx, [esi*4]
// 005bba5b  52                   push edx
// 005bba5c  ff159404d900         call dword ptr [0xd90494]
// 005bba62  8b4f08               mov ecx, dword ptr [edi + 8]
// 005bba65  83c40c               add esp, 0xc
// 005bba68  8907                 mov dword ptr [edi], eax
// 005bba6a  85c0                 test eax, eax
// 005bba6c  751a                 jne 0x5bba88
// 005bba6e  8b442420             mov eax, dword ptr [esp + 0x20]
// 005bba72  55                   push ebp
// 005bba73  50                   push eax
// 005bba74  51                   push ecx
// 005bba75  ff159c04d900         call dword ptr [0xd9049c]
// 005bba7b  83c40c               add esp, 0xc
// 005bba7e  5f                   pop edi
// 005bba7f  5e                   pop esi
// 005bba80  5d                   pop ebp
// 005bba81  32c0                 xor al, al
// 005bba83  5b                   pop ebx
// 005bba84  59                   pop ecx
// 005bba85  c21000               ret 0x10
// 005bba88  85f6                 test esi, esi
// 005bba8a  7e18                 jle 0x5bbaa4
// 005bba8c  8d642400             lea esp, [esp]
// 005bba90  89b908060000         mov dword ptr [ecx + 0x608], edi
// 005bba96  890c98               mov dword ptr [eax + ebx*4], ecx
// 005bba99  43                   inc ebx
// 005bba9a  81c110060000         add ecx, 0x610
// 005bbaa0  3bde                 cmp ebx, esi
// 005bbaa2  7cec                 jl 0x5bba90
// 005bbaa4  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bbaa8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005bbaac  897704               mov dword ptr [edi + 4], esi
// 005bbaaf  8b02                 mov eax, dword ptr [edx]
// 005bbab1  89470c               mov dword ptr [edi + 0xc], eax
// 005bbab4  894f10               mov dword ptr [edi + 0x10], ecx
// 005bbab7  5f                   pop edi
// 005bbab8  5e                   pop esi
// 005bbab9  5d                   pop ebp
// 005bbaba  b001                 mov al, 1
// 005bbabc  5b                   pop ebx
// 005bbabd  59                   pop ecx
// 005bbabe  c21000               ret 0x10
// copied from an identical function in another client (function ?InitPage@?$MemoryPool@URecvFromStruct@RakPeer@RakNet@@@DataStructures@@IAE_NPAUPage@12@0PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp