// from server: 100% by auto
// roc 2008-06 00401d90  unit: VCWorkspace::?$CComObject  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401d90
//
// 00401d90  8b442404             mov eax, dword ptr [esp + 4]
// 00401d94  83f864               cmp eax, 0x64
// 00401d97  56                   push esi
// 00401d98  8bf1                 mov esi, ecx
// 00401d9a  7d05                 jge 0x401da1
// 00401d9c  b8e8030000           mov eax, 0x3e8
// 00401da1  33c9                 xor ecx, ecx
// 00401da3  c70600000000         mov dword ptr [esi], 0
// 00401da9  894604               mov dword ptr [esi + 4], eax
// 00401dac  7705                 ja 0x401db3
// 00401dae  83f8ff               cmp eax, -1
// 00401db1  7604                 jbe 0x401db7
// 00401db3  33c0                 xor eax, eax
// 00401db5  eb07                 jmp 0x401dbe
// 00401db7  50                   push eax
// 00401db8  ff150c418000         call dword ptr [0x80410c]
// 00401dbe  894608               mov dword ptr [esi + 8], eax
// 00401dc1  85c0                 test eax, eax
// 00401dc3  7403                 je 0x401dc8
// 00401dc5  c60000               mov byte ptr [eax], 0
// 00401dc8  8bc6                 mov eax, esi
// 00401dca  5e                   pop esi
// 00401dcb  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
