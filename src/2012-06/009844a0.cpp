// from server: 100% by Yeetserama
// roc 2012-06 009844a0  unit: boost::exception  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009844a0
//
// 009844a0  8bff                 mov edi, edi
// 009844a2  55                   push ebp
// 009844a3  8bec                 mov ebp, esp
// 009844a5  56                   push esi
// 009844a6  8bf1                 mov esi, ecx
// 009844a8  8b4608               mov eax, dword ptr [esi + 8]
// 009844ab  c70698cdc000         mov dword ptr [esi], 0xc0cd98
// 009844b1  85c0                 test eax, eax
// 009844b3  7408                 je 0x9844bd
// 009844b5  8b08                 mov ecx, dword ptr [eax]
// 009844b7  8b5108               mov edx, dword ptr [ecx + 8]
// 009844ba  50                   push eax
// 009844bb  ffd2                 call edx
// 009844bd  837e0c00             cmp dword ptr [esi + 0xc], 0
// 009844c1  7417                 je 0x9844da
// 009844c3  ff15ac22b200         call dword ptr [0xb222ac]
// 009844c9  85c0                 test eax, eax
// 009844cb  740d                 je 0x9844da
// 009844cd  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 009844d0  51                   push ecx
// 009844d1  6a00                 push 0
// 009844d3  50                   push eax
// 009844d4  ff15a822b200         call dword ptr [0xb222a8]
// 009844da  f6450801             test byte ptr [ebp + 8], 1
// 009844de  7409                 je 0x9844e9
// 009844e0  56                   push esi
// 009844e1  e82edcffff           call 0x982114
// 009844e6  83c404               add esp, 4
// 009844e9  8bc6                 mov eax, esi
// 009844eb  5e                   pop esi
// 009844ec  5d                   pop ebp
// 009844ed  c20400               ret 4
// copied from an identical function in another client (function ??_G_com_error@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-comsupp-rtm comsupp.lib/f:/dd/vctools/compiler/cxxfe/sl/vccom/ANSI/objr/i386/comraise.obj