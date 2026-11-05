// from server: 100% by auto
// roc 2007-03 00401db0  unit: seg_00400000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401db0
//
// 00401db0  8b442404             mov eax, dword ptr [esp + 4]
// 00401db4  83f864               cmp eax, 0x64
// 00401db7  56                   push esi
// 00401db8  8bf1                 mov esi, ecx
// 00401dba  7d05                 jge 0x401dc1
// 00401dbc  b8e8030000           mov eax, 0x3e8
// 00401dc1  33c9                 xor ecx, ecx
// 00401dc3  c70600000000         mov dword ptr [esi], 0
// 00401dc9  894604               mov dword ptr [esi + 4], eax
// 00401dcc  7705                 ja 0x401dd3
// 00401dce  83f8ff               cmp eax, -1
// 00401dd1  7604                 jbe 0x401dd7
// 00401dd3  33c0                 xor eax, eax
// 00401dd5  eb07                 jmp 0x401dde
// 00401dd7  50                   push eax
// 00401dd8  ff153cf17700         call dword ptr [0x77f13c]
// 00401dde  85c0                 test eax, eax
// 00401de0  894608               mov dword ptr [esi + 8], eax
// 00401de3  7403                 je 0x401de8
// 00401de5  c60000               mov byte ptr [eax], 0
// 00401de8  8bc6                 mov eax, esi
// 00401dea  5e                   pop esi
// 00401deb  c20400               ret 4
// library atl-8.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
