// roc 2012-06 00a7ba16  unit: CXTIconHandle  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7ba16
//
// 00a7ba16  8bff                 mov edi, edi
// 00a7ba18  56                   push esi
// 00a7ba19  8bf1                 mov esi, ecx
// 00a7ba1b  e873ffffff           call 0xa7b993
// 00a7ba20  b800004000           mov eax, 0x400000
// 00a7ba25  8d4e14               lea ecx, [esi + 0x14]
// 00a7ba28  c70638000000         mov dword ptr [esi], 0x38
// 00a7ba2e  894608               mov dword ptr [esi + 8], eax
// 00a7ba31  894604               mov dword ptr [esi + 4], eax
// 00a7ba34  c7460c00090000       mov dword ptr [esi + 0xc], 0x900
// 00a7ba3b  c74610f8bac200       mov dword ptr [esi + 0x10], 0xc2baf8
// 00a7ba42  e8d98798ff           call 0x404220
// 00a7ba47  85c0                 test eax, eax
// 00a7ba49  7d07                 jge 0xa7ba52
// 00a7ba4b  c60564a2e10001       mov byte ptr [0xe1a264], 1
// 00a7ba52  8bc6                 mov eax, esi
// 00a7ba54  5e                   pop esi
// 00a7ba55  c3                   ret 
// copied from an identical function in another client (function ??0CAtlBaseModule@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlbase.obj