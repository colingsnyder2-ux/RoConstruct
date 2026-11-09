// from server: 100% by colin
// roc 2007-08 0054aeb0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054aeb0
//
// 0054aeb0  56                   push esi
// 0054aeb1  57                   push edi
// 0054aeb2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0054aeb6  8bf1                 mov esi, ecx
// 0054aeb8  397e04               cmp dword ptr [esi + 4], edi
// 0054aebb  7427                 je 0x54aee4
// 0054aebd  6a00                 push 0
// 0054aebf  57                   push edi
// 0054aec0  8d4c2414             lea ecx, [esp + 0x14]
// 0054aec4  ff1518e67700         call dword ptr [0x77e618]
// 0054aeca  8b5604               mov edx, dword ptr [esi + 4]
// 0054aecd  897e04               mov dword ptr [esi + 4], edi
// 0054aed0  8b0e                 mov ecx, dword ptr [esi]
// 0054aed2  85c9                 test ecx, ecx
// 0054aed4  8906                 mov dword ptr [esi], eax
// 0054aed6  740c                 je 0x54aee4
// 0054aed8  52                   push edx
// 0054aed9  51                   push ecx
// 0054aeda  8d4c2414             lea ecx, [esp + 0x14]
// 0054aede  ff1510e67700         call dword ptr [0x77e610]
// 0054aee4  5f                   pop edi
// 0054aee5  5e                   pop esi
// 0054aee6  c20400               ret 4
// copied from an identical function in another client (function ?resize@?$basic_buffer@DV?$allocator@D@std@@@detail@iostreams@boost@@QAEXH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp