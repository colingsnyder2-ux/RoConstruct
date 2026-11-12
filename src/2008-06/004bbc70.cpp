// from server: 100% by auto
// roc 2008-06 004bbc70  unit: ProfiledRakPeer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbc70
//
// 004bbc70  56                   push esi
// 004bbc71  8bf1                 mov esi, ecx
// 004bbc73  8b06                 mov eax, dword ptr [esi]
// 004bbc75  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004bbc78  ffd2                 call edx
// 004bbc7a  84c0                 test al, al
// 004bbc7c  7406                 je 0x4bbc84
// 004bbc7e  32c0                 xor al, al
// 004bbc80  5e                   pop esi
// 004bbc81  c20400               ret 4
// 004bbc84  80be0c07000000       cmp byte ptr [esi + 0x70c], 0
// 004bbc8b  74f1                 je 0x4bbc7e
// 004bbc8d  57                   push edi
// 004bbc8e  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bbc92  81c6cc020000         add esi, 0x2cc
// 004bbc98  b900010000           mov ecx, 0x100
// 004bbc9d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bbc9f  5f                   pop edi
// 004bbca0  b001                 mov al, 1
// 004bbca2  5e                   pop esi
// 004bbca3  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?GetOutgoingFrequencyTable@RakPeer@@UAE_NQAI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
