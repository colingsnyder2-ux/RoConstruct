// from server: 100% by auto
// roc 2008-06 004bd590  unit: ProfiledRakPeer  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd590
//
// 004bd590  8b542404             mov edx, dword ptr [esp + 4]
// 004bd594  57                   push edi
// 004bd595  8bf9                 mov edi, ecx
// 004bd597  85d2                 test edx, edx
// 004bd599  7456                 je 0x4bd5f1
// 004bd59b  8b8fac020000         mov ecx, dword ptr [edi + 0x2ac]
// 004bd5a1  56                   push esi
// 004bd5a2  33f6                 xor esi, esi
// 004bd5a4  85c9                 test ecx, ecx
// 004bd5a6  7648                 jbe 0x4bd5f0
// 004bd5a8  8b87a8020000         mov eax, dword ptr [edi + 0x2a8]
// 004bd5ae  8bff                 mov edi, edi
// 004bd5b0  3910                 cmp dword ptr [eax], edx
// 004bd5b2  740d                 je 0x4bd5c1
// 004bd5b4  46                   inc esi
// 004bd5b5  83c004               add eax, 4
// 004bd5b8  3bf1                 cmp esi, ecx
// 004bd5ba  72f4                 jb 0x4bd5b0
// 004bd5bc  5e                   pop esi
// 004bd5bd  5f                   pop edi
// 004bd5be  c20400               ret 4
// 004bd5c1  83feff               cmp esi, -1
// 004bd5c4  742a                 je 0x4bd5f0
// 004bd5c6  8b87a8020000         mov eax, dword ptr [edi + 0x2a8]
// 004bd5cc  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 004bd5cf  8b11                 mov edx, dword ptr [ecx]
// 004bd5d1  8b4208               mov eax, dword ptr [edx + 8]
// 004bd5d4  57                   push edi
// 004bd5d5  ffd0                 call eax
// 004bd5d7  8b87a8020000         mov eax, dword ptr [edi + 0x2a8]
// 004bd5dd  8b8fac020000         mov ecx, dword ptr [edi + 0x2ac]
// 004bd5e3  8b5488fc             mov edx, dword ptr [eax + ecx*4 - 4]
// 004bd5e7  8914b0               mov dword ptr [eax + esi*4], edx
// 004bd5ea  ff8fac020000         dec dword ptr [edi + 0x2ac]
// 004bd5f0  5e                   pop esi
// 004bd5f1  5f                   pop edi
// 004bd5f2  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?DetachPlugin@RakPeer@@UAEXPAVPluginInterface@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
