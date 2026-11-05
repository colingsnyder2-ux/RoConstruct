// from server: 100% by auto
// roc 2009-06 004ceb00  unit: RBX::Network::VPlayers::?$EventDesc  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ceb00
//
// 004ceb00  33c0                 xor eax, eax
// 004ceb02  56                   push esi
// 004ceb03  8bf1                 mov esi, ecx
// 004ceb05  85c9                 test ecx, ecx
// 004ceb07  7417                 je 0x4ceb20
// 004ceb09  8da42400000000       lea esp, [esp]
// 004ceb10  3802                 cmp byte ptr [edx], al
// 004ceb12  7408                 je 0x4ceb1c
// 004ceb14  42                   inc edx
// 004ceb15  83e901               sub ecx, 1
// 004ceb18  75f6                 jne 0x4ceb10
// 004ceb1a  eb04                 jmp 0x4ceb20
// 004ceb1c  85c9                 test ecx, ecx
// 004ceb1e  7505                 jne 0x4ceb25
// 004ceb20  b857000780           mov eax, 0x80070057
// 004ceb25  85ff                 test edi, edi
// 004ceb27  7410                 je 0x4ceb39
// 004ceb29  85c0                 test eax, eax
// 004ceb2b  7c06                 jl 0x4ceb33
// 004ceb2d  2bf1                 sub esi, ecx
// 004ceb2f  8937                 mov dword ptr [edi], esi
// 004ceb31  5e                   pop esi
// 004ceb32  c3                   ret 
// 004ceb33  c70700000000         mov dword ptr [edi], 0
// 004ceb39  5e                   pop esi
// 004ceb3a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\filecore.cpp (function ?StringLengthWorkerA@@YGJPBDIPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filecore.cpp
