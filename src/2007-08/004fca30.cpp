// from server: 100% by auto
// roc 2007-08 004fca30  unit: RBX::Render::AggregateChunk  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fca30
//
// 004fca30  55                   push ebp
// 004fca31  8bec                 mov ebp, esp
// 004fca33  6aff                 push -1
// 004fca35  6810e87400           push 0x74e810
// 004fca3a  64a100000000         mov eax, dword ptr fs:[0]
// 004fca40  50                   push eax
// 004fca41  83ec08               sub esp, 8
// 004fca44  53                   push ebx
// 004fca45  56                   push esi
// 004fca46  57                   push edi
// 004fca47  a188518b00           mov eax, dword ptr [0x8b5188]
// 004fca4c  33c5                 xor eax, ebp
// 004fca4e  50                   push eax
// 004fca4f  8d45f4               lea eax, [ebp - 0xc]
// 004fca52  64a300000000         mov dword ptr fs:[0], eax
// 004fca58  8965f0               mov dword ptr [ebp - 0x10], esp
// 004fca5b  8b7d08               mov edi, dword ptr [ebp + 8]
// 004fca5e  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004fca61  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004fca64  897dec               mov dword ptr [ebp - 0x14], edi
// 004fca67  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004fca6e  8bff                 mov edi, edi
// 004fca70  85f6                 test esi, esi
// 004fca72  763a                 jbe 0x4fcaae
// 004fca74  53                   push ebx
// 004fca75  57                   push edi
// 004fca76  e825fbffff           call 0x4fc5a0
// 004fca7b  83c408               add esp, 8
// 004fca7e  83ee01               sub esi, 1
// 004fca81  83c720               add edi, 0x20
// 004fca84  897d08               mov dword ptr [ebp + 8], edi
// 004fca87  ebe7                 jmp 0x4fca70
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Uninit_fill_n@PAUEdgeGroup@EdgeData@Ogre@@IU123@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@std@@YAXPAUEdgeGroup@EdgeData@Ogre@@IABU123@AAV?$allocator@UEdgeGroup@EdgeData@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
