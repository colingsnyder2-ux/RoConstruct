// from server: 100% by Xemicl
// roc 2012-06 009843e0  unit: boost::exception  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009843e0
//
// 009843e0  8bff                 mov edi, edi
// 009843e2  56                   push esi
// 009843e3  8bf1                 mov esi, ecx
// 009843e5  8b4608               mov eax, dword ptr [esi + 8]
// 009843e8  c70698cdc000         mov dword ptr [esi], 0xc0cd98
// 009843ee  85c0                 test eax, eax
// 009843f0  7408                 je 0x9843fa
// 009843f2  8b08                 mov ecx, dword ptr [eax]
// 009843f4  8b5108               mov edx, dword ptr [ecx + 8]
// 009843f7  50                   push eax
// 009843f8  ffd2                 call edx
// 009843fa  837e0c00             cmp dword ptr [esi + 0xc], 0
// 009843fe  7417                 je 0x984417
// 00984400  ff15ac22b200         call dword ptr [0xb222ac]
// 00984406  85c0                 test eax, eax
// 00984408  740d                 je 0x984417
// 0098440a  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0098440d  51                   push ecx
// 0098440e  6a00                 push 0
// 00984410  50                   push eax
// 00984411  ff15a822b200         call dword ptr [0xb222a8]
// 00984417  5e                   pop esi
// 00984418  c3                   ret 
// copied from an identical function in another client (function ??1_com_error@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-comsupp-rtm comsupp.lib/f:/dd/vctools/compiler/cxxfe/sl/vccom/ANSI/objr/i386/comraise.obj