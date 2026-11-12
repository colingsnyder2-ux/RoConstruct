// from server: 100% by colin
// roc 2007-08 004b8ee0  unit: RakPeer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8ee0
//
// 004b8ee0  56                   push esi
// 004b8ee1  8bf1                 mov esi, ecx
// 004b8ee3  8b06                 mov eax, dword ptr [esi]
// 004b8ee5  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004b8ee8  ffd2                 call edx
// 004b8eea  84c0                 test al, al
// 004b8eec  7406                 je 0x4b8ef4
// 004b8eee  32c0                 xor al, al
// 004b8ef0  5e                   pop esi
// 004b8ef1  c20400               ret 4
// 004b8ef4  80be0c07000000       cmp byte ptr [esi + 0x70c], 0
// 004b8efb  74f1                 je 0x4b8eee
// 004b8efd  57                   push edi
// 004b8efe  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004b8f02  81c6cc020000         add esi, 0x2cc
// 004b8f08  b900010000           mov ecx, 0x100
// 004b8f0d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004b8f0f  5f                   pop edi
// 004b8f10  b001                 mov al, 1
// 004b8f12  5e                   pop esi
// 004b8f13  c20400               ret 4
// copied from an identical function in another client (function ?GetOutgoingFrequencyTable@RakPeer@@UAE_NQAI@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp