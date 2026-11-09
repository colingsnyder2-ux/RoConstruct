// roc 2012-06 005baf90  unit: RakNet::RakPeer  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005baf90
//
// 005baf90  53                   push ebx
// 005baf91  55                   push ebp
// 005baf92  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005baf96  8bd9                 mov ebx, ecx
// 005baf98  85ed                 test ebp, ebp
// 005baf9a  0f84da000000         je 0x5bb07a
// 005bafa0  807d0000             cmp byte ptr [ebp], 0
// 005bafa4  0f84d0000000         je 0x5bb07a
// 005bafaa  b99840b700           mov ecx, 0xb74098
// 005bafaf  8bc5                 mov eax, ebp
// 005bafb1  8a10                 mov dl, byte ptr [eax]
// 005bafb3  3a11                 cmp dl, byte ptr [ecx]
// 005bafb5  751a                 jne 0x5bafd1
// 005bafb7  84d2                 test dl, dl
// 005bafb9  7412                 je 0x5bafcd
// 005bafbb  8a5001               mov dl, byte ptr [eax + 1]
// 005bafbe  3a5101               cmp dl, byte ptr [ecx + 1]
// 005bafc1  750e                 jne 0x5bafd1
// 005bafc3  83c002               add eax, 2
// 005bafc6  83c102               add ecx, 2
// 005bafc9  84d2                 test dl, dl
// 005bafcb  75e4                 jne 0x5bafb1
// 005bafcd  33c0                 xor eax, eax
// 005bafcf  eb05                 jmp 0x5bafd6
// 005bafd1  1bc0                 sbb eax, eax
// 005bafd3  83d8ff               sbb eax, -1
// 005bafd6  85c0                 test eax, eax
// 005bafd8  0f8495000000         je 0x5bb073
// 005bafde  b9c83ab700           mov ecx, 0xb73ac8
// 005bafe3  8bc5                 mov eax, ebp
// 005bafe5  8a10                 mov dl, byte ptr [eax]
// 005bafe7  3a11                 cmp dl, byte ptr [ecx]
// 005bafe9  751a                 jne 0x5bb005
// 005bafeb  84d2                 test dl, dl
// 005bafed  7412                 je 0x5bb001
// 005bafef  8a5001               mov dl, byte ptr [eax + 1]
// 005baff2  3a5101               cmp dl, byte ptr [ecx + 1]
// 005baff5  750e                 jne 0x5bb005
// 005baff7  83c002               add eax, 2
// 005baffa  83c102               add ecx, 2
// 005baffd  84d2                 test dl, dl
// 005bafff  75e4                 jne 0x5bafe5
// 005bb001  33c0                 xor eax, eax
// 005bb003  eb05                 jmp 0x5bb00a
// 005bb005  1bc0                 sbb eax, eax
// 005bb007  83d8ff               sbb eax, -1
// 005bb00a  85c0                 test eax, eax
// 005bb00c  7465                 je 0x5bb073
// 005bb00e  8b03                 mov eax, dword ptr [ebx]
// 005bb010  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 005bb016  56                   push esi
// 005bb017  57                   push edi
// 005bb018  8bcb                 mov ecx, ebx
// 005bb01a  ffd2                 call edx
// 005bb01c  8bf8                 mov edi, eax
// 005bb01e  33f6                 xor esi, esi
// 005bb020  85ff                 test edi, edi
// 005bb022  7e3d                 jle 0x5bb061
// 005bb024  8b03                 mov eax, dword ptr [ebx]
// 005bb026  8b90e4000000         mov edx, dword ptr [eax + 0xe4]
// 005bb02c  56                   push esi
// 005bb02d  8bcb                 mov ecx, ebx
// 005bb02f  ffd2                 call edx
// 005bb031  8bcd                 mov ecx, ebp
// 005bb033  8a11                 mov dl, byte ptr [ecx]
// 005bb035  3a10                 cmp dl, byte ptr [eax]
// 005bb037  751a                 jne 0x5bb053
// 005bb039  84d2                 test dl, dl
// 005bb03b  7412                 je 0x5bb04f
// 005bb03d  8a5101               mov dl, byte ptr [ecx + 1]
// 005bb040  3a5001               cmp dl, byte ptr [eax + 1]
// 005bb043  750e                 jne 0x5bb053
// 005bb045  83c102               add ecx, 2
// 005bb048  83c002               add eax, 2
// 005bb04b  84d2                 test dl, dl
// 005bb04d  75e4                 jne 0x5bb033
// 005bb04f  33c0                 xor eax, eax
// 005bb051  eb05                 jmp 0x5bb058
// 005bb053  1bc0                 sbb eax, eax
// 005bb055  83d8ff               sbb eax, -1
// 005bb058  85c0                 test eax, eax
// 005bb05a  740e                 je 0x5bb06a
// 005bb05c  46                   inc esi
// 005bb05d  3bf7                 cmp esi, edi
// 005bb05f  7cc3                 jl 0x5bb024
// 005bb061  5f                   pop edi
// 005bb062  5e                   pop esi
// 005bb063  5d                   pop ebp
// 005bb064  32c0                 xor al, al
// 005bb066  5b                   pop ebx
// 005bb067  c20400               ret 4
// 005bb06a  5f                   pop edi
// 005bb06b  5e                   pop esi
// 005bb06c  5d                   pop ebp
// 005bb06d  b001                 mov al, 1
// 005bb06f  5b                   pop ebx
// 005bb070  c20400               ret 4
// 005bb073  5d                   pop ebp
// 005bb074  b001                 mov al, 1
// 005bb076  5b                   pop ebx
// 005bb077  c20400               ret 4
// 005bb07a  5d                   pop ebp
// 005bb07b  32c0                 xor al, al
// 005bb07d  5b                   pop ebx
// 005bb07e  c20400               ret 4
// copied from an identical function in another client (function ?IsLocalIP@RakPeer@RakNet@@UAE_NPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp