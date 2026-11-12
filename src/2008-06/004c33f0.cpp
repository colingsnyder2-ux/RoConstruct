// from server: 100% by auto
// roc 2008-06 004c33f0  unit: ProfiledRakPeer  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c33f0
//
// 004c33f0  81ec80000000         sub esp, 0x80
// 004c33f6  53                   push ebx
// 004c33f7  8b9c248c000000       mov ebx, dword ptr [esp + 0x8c]
// 004c33fe  55                   push ebp
// 004c33ff  8bac248c000000       mov ebp, dword ptr [esp + 0x8c]
// 004c3406  56                   push esi
// 004c3407  57                   push edi
// 004c3408  53                   push ebx
// 004c3409  55                   push ebp
// 004c340a  e8d1daffff           call 0x4c0ee0
// 004c340f  33c0                 xor eax, eax
// 004c3411  b908000000           mov ecx, 8
// 004c3416  8bf3                 mov esi, ebx
// 004c3418  8d7c2438             lea edi, [esp + 0x38]
// 004c341c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c341e  89442418             mov dword ptr [esp + 0x18], eax
// 004c3422  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c3426  89442420             mov dword ptr [esp + 0x20], eax
// 004c342a  89442424             mov dword ptr [esp + 0x24], eax
// 004c342e  89442428             mov dword ptr [esp + 0x28], eax
// 004c3432  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c3436  89442430             mov dword ptr [esp + 0x30], eax
// 004c343a  89442434             mov dword ptr [esp + 0x34], eax
// 004c343e  8d442418             lea eax, [esp + 0x18]
// 004c3442  50                   push eax
// 004c3443  e82892ffff           call 0x4bc670
// 004c3448  33c0                 xor eax, eax
// 004c344a  b908000000           mov ecx, 8
// 004c344f  8bf5                 mov esi, ebp
// 004c3451  8d7c245c             lea edi, [esp + 0x5c]
// 004c3455  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c3457  8d4c241c             lea ecx, [esp + 0x1c]
// 004c345b  51                   push ecx
// 004c345c  8d542460             lea edx, [esp + 0x60]
// 004c3460  89842480000000       mov dword ptr [esp + 0x80], eax
// 004c3467  89842484000000       mov dword ptr [esp + 0x84], eax
// 004c346e  89842488000000       mov dword ptr [esp + 0x88], eax
// 004c3475  8984248c000000       mov dword ptr [esp + 0x8c], eax
// 004c347c  89842490000000       mov dword ptr [esp + 0x90], eax
// 004c3483  89842494000000       mov dword ptr [esp + 0x94], eax
// 004c348a  89842498000000       mov dword ptr [esp + 0x98], eax
// 004c3491  8984249c000000       mov dword ptr [esp + 0x9c], eax
// 004c3498  52                   push edx
// 004c3499  8bc2                 mov eax, edx
// 004c349b  50                   push eax
// 004c349c  51                   push ecx
// 004c349d  e87ea8ffff           call 0x4bdd20
// 004c34a2  83c41c               add esp, 0x1c
// 004c34a5  8bfb                 mov edi, ebx
// 004c34a7  b908000000           mov ecx, 8
// 004c34ac  8d742450             lea esi, [esp + 0x50]
// 004c34b0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c34b2  5f                   pop edi
// 004c34b3  5e                   pop esi
// 004c34b4  5d                   pop ebp
// 004c34b5  5b                   pop ebx
// 004c34b6  81c480000000         add esp, 0x80
// 004c34bc  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$computeNRinverse@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
