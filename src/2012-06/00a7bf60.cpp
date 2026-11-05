// roc 2012-06 00a7bf60  unit: CXTIconHandle  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bf60
//
// 00a7bf60  8bff                 mov edi, edi
// 00a7bf62  56                   push esi
// 00a7bf63  8bf1                 mov esi, ecx
// 00a7bf65  57                   push edi
// 00a7bf66  8d7e10               lea edi, [esi + 0x10]
// 00a7bf69  8bcf                 mov ecx, edi
// 00a7bf6b  e8908298ff           call 0x404200
// 00a7bf70  832600               and dword ptr [esi], 0
// 00a7bf73  8bcf                 mov ecx, edi
// 00a7bf75  c7460400004000       mov dword ptr [esi + 4], 0x400000
// 00a7bf7c  c74608ac10d400       mov dword ptr [esi + 8], 0xd410ac
// 00a7bf83  c7460cb010d400       mov dword ptr [esi + 0xc], 0xd410b0
// 00a7bf8a  e8918298ff           call 0x404220
// 00a7bf8f  85c0                 test eax, eax
// 00a7bf91  7d09                 jge 0xa7bf9c
// 00a7bf93  c60564a2e10001       mov byte ptr [0xe1a264], 1
// 00a7bf9a  eb06                 jmp 0xa7bfa2
// 00a7bf9c  c70628000000         mov dword ptr [esi], 0x28
// 00a7bfa2  5f                   pop edi
// 00a7bfa3  8bc6                 mov eax, esi
// 00a7bfa5  5e                   pop esi
// 00a7bfa6  c3                   ret 
// copied from an identical function in another client (function ??0CAtlComModule@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlcommodule.obj