// roc 2012-06 005bbce0  unit: RakNet::RakPeer  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bbce0
//
// 005bbce0  56                   push esi
// 005bbce1  57                   push edi
// 005bbce2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bbce6  8bf1                 mov esi, ecx
// 005bbce8  85ff                 test edi, edi
// 005bbcea  0f8498000000         je 0x5bbd88
// 005bbcf0  8b07                 mov eax, dword ptr [edi]
// 005bbcf2  8b5028               mov edx, dword ptr [eax + 0x28]
// 005bbcf5  8bcf                 mov ecx, edi
// 005bbcf7  ffd2                 call edx
// 005bbcf9  84c0                 test al, al
// 005bbcfb  743b                 je 0x5bbd38
// 005bbcfd  8b96dc020000         mov edx, dword ptr [esi + 0x2dc]
// 005bbd03  33c0                 xor eax, eax
// 005bbd05  85d2                 test edx, edx
// 005bbd07  766d                 jbe 0x5bbd76
// 005bbd09  8b8ed8020000         mov ecx, dword ptr [esi + 0x2d8]
// 005bbd0f  90                   nop 
// 005bbd10  3939                 cmp dword ptr [ecx], edi
// 005bbd12  740a                 je 0x5bbd1e
// 005bbd14  40                   inc eax
// 005bbd15  83c104               add ecx, 4
// 005bbd18  3bc2                 cmp eax, edx
// 005bbd1a  72f4                 jb 0x5bbd10
// 005bbd1c  eb58                 jmp 0x5bbd76
// 005bbd1e  83f8ff               cmp eax, -1
// 005bbd21  7453                 je 0x5bbd76
// 005bbd23  8b8ed8020000         mov ecx, dword ptr [esi + 0x2d8]
// 005bbd29  8b5491fc             mov edx, dword ptr [ecx + edx*4 - 4]
// 005bbd2d  891481               mov dword ptr [ecx + eax*4], edx
// 005bbd30  ff8edc020000         dec dword ptr [esi + 0x2dc]
// 005bbd36  eb3e                 jmp 0x5bbd76
// 005bbd38  8b96d0020000         mov edx, dword ptr [esi + 0x2d0]
// 005bbd3e  33c0                 xor eax, eax
// 005bbd40  85d2                 test edx, edx
// 005bbd42  7632                 jbe 0x5bbd76
// 005bbd44  8b8ecc020000         mov ecx, dword ptr [esi + 0x2cc]
// 005bbd4a  8d9b00000000         lea ebx, [ebx]
// 005bbd50  3939                 cmp dword ptr [ecx], edi
// 005bbd52  740a                 je 0x5bbd5e
// 005bbd54  40                   inc eax
// 005bbd55  83c104               add ecx, 4
// 005bbd58  3bc2                 cmp eax, edx
// 005bbd5a  72f4                 jb 0x5bbd50
// 005bbd5c  eb18                 jmp 0x5bbd76
// 005bbd5e  83f8ff               cmp eax, -1
// 005bbd61  7413                 je 0x5bbd76
// 005bbd63  8b8ecc020000         mov ecx, dword ptr [esi + 0x2cc]
// 005bbd69  8b5491fc             mov edx, dword ptr [ecx + edx*4 - 4]
// 005bbd6d  891481               mov dword ptr [ecx + eax*4], edx
// 005bbd70  ff8ed0020000         dec dword ptr [esi + 0x2d0]
// 005bbd76  8b07                 mov eax, dword ptr [edi]
// 005bbd78  8b5008               mov edx, dword ptr [eax + 8]
// 005bbd7b  8bcf                 mov ecx, edi
// 005bbd7d  ffd2                 call edx
// 005bbd7f  6a00                 push 0
// 005bbd81  8bcf                 mov ecx, edi
// 005bbd83  e8d8e7ffff           call 0x5ba560
// 005bbd88  5f                   pop edi
// 005bbd89  5e                   pop esi
// 005bbd8a  c20400               ret 4
// library raknet-4.081/RakPeer.cpp (function ?DetachPlugin@RakPeer@RakNet@@UAEXPAVPluginInterface2@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakPeer.cpp
