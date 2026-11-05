// from server: 100% by auto
// roc 2009-12 00524220  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00524220
//
// 00524220  33c0                 xor eax, eax
// 00524222  56                   push esi
// 00524223  8bf1                 mov esi, ecx
// 00524225  85c9                 test ecx, ecx
// 00524227  7417                 je 0x524240
// 00524229  8da42400000000       lea esp, [esp]
// 00524230  3802                 cmp byte ptr [edx], al
// 00524232  7408                 je 0x52423c
// 00524234  42                   inc edx
// 00524235  83e901               sub ecx, 1
// 00524238  75f6                 jne 0x524230
// 0052423a  eb04                 jmp 0x524240
// 0052423c  85c9                 test ecx, ecx
// 0052423e  7505                 jne 0x524245
// 00524240  b857000780           mov eax, 0x80070057
// 00524245  85ff                 test edi, edi
// 00524247  7410                 je 0x524259
// 00524249  85c0                 test eax, eax
// 0052424b  7c06                 jl 0x524253
// 0052424d  2bf1                 sub esi, ecx
// 0052424f  8937                 mov dword ptr [edi], esi
// 00524251  5e                   pop esi
// 00524252  c3                   ret 
// 00524253  c70700000000         mov dword ptr [edi], 0
// 00524259  5e                   pop esi
// 0052425a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\filecore.cpp (function ?StringLengthWorkerA@@YGJPBDIPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/filecore.cpp
