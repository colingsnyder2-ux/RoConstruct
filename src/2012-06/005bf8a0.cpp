// roc 2012-06 005bf8a0  unit: RakNet::RakPeer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bf8a0
//
// 005bf8a0  53                   push ebx
// 005bf8a1  56                   push esi
// 005bf8a2  57                   push edi
// 005bf8a3  6a00                 push 0
// 005bf8a5  6a00                 push 0
// 005bf8a7  83ec28               sub esp, 0x28
// 005bf8aa  8bf4                 mov esi, esp
// 005bf8ac  8bd9                 mov ebx, ecx
// 005bf8ae  8bce                 mov ecx, esi
// 005bf8b0  e82b24faff           call 0x561ce0
// 005bf8b5  8d7e10               lea edi, [esi + 0x10]
// 005bf8b8  8bcf                 mov ecx, edi
// 005bf8ba  e87121faff           call 0x561a30
// 005bf8bf  8b442440             mov eax, dword ptr [esp + 0x40]
// 005bf8c3  8906                 mov dword ptr [esi], eax
// 005bf8c5  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005bf8c9  894e04               mov dword ptr [esi + 4], ecx
// 005bf8cc  668b542448           mov dx, word ptr [esp + 0x48]
// 005bf8d1  8d442450             lea eax, [esp + 0x50]
// 005bf8d5  50                   push eax
// 005bf8d6  8bcf                 mov ecx, edi
// 005bf8d8  66895608             mov word ptr [esi + 8], dx
// 005bf8dc  e82f1ffaff           call 0x561810
// 005bf8e1  8bcb                 mov ecx, ebx
// 005bf8e3  e8f8eeffff           call 0x5be7e0
// 005bf8e8  85c0                 test eax, eax
// 005bf8ea  7509                 jne 0x5bf8f5
// 005bf8ec  83c8ff               or eax, 0xffffffff
// 005bf8ef  5f                   pop edi
// 005bf8f0  5e                   pop esi
// 005bf8f1  5b                   pop ebx
// 005bf8f2  c22800               ret 0x28
// 005bf8f5  8b88b8110000         mov ecx, dword ptr [eax + 0x11b8]
// 005bf8fb  0b88bc110000         or ecx, dword ptr [eax + 0x11bc]
// 005bf901  750d                 jne 0x5bf910
// 005bf903  0fb780a8110000       movzx eax, word ptr [eax + 0x11a8]
// 005bf90a  5f                   pop edi
// 005bf90b  5e                   pop esi
// 005bf90c  5b                   pop ebx
// 005bf90d  c22800               ret 0x28
// 005bf910  8b90b8110000         mov edx, dword ptr [eax + 0x11b8]
// 005bf916  5f                   pop edi
// 005bf917  c1e204               shl edx, 4
// 005bf91a  0fb7840258110000     movzx eax, word ptr [edx + eax + 0x1158]
// 005bf922  5e                   pop esi
// 005bf923  5b                   pop ebx
// 005bf924  c22800               ret 0x28
// copied from an identical function in another client (function ?GetLastPing@RakPeer@RakNet@@UBEHUAddressOrGUID@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp