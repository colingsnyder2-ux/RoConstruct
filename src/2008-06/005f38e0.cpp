// from server: 100% by auto
// from server: 85% by colin
// roc 2008-06 005f38e0  unit: std::D::V?$allocator::V?$zlib_decompressor_impl::?$symmetric_filter::Uimpl::?$sp_counted_impl_p  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f38e0
//
// 005f38e0  55                   push ebp
// 005f38e1  8bec                 mov ebp, esp
// 005f38e3  6aff                 push -1
// 005f38e5  6800747d00           push 0x7d7400
// 005f38ea  64a100000000         mov eax, dword ptr fs:[0]
// 005f38f0  50                   push eax
// 005f38f1  64892500000000       mov dword ptr fs:[0], esp
// 005f38f8  83ec08               sub esp, 8
// 005f38fb  8b4104               mov eax, dword ptr [ecx + 4]
// 005f38fe  53                   push ebx
// 005f38ff  56                   push esi
// 005f3900  894dec               mov dword ptr [ebp - 0x14], ecx
// 005f3903  8b09                 mov ecx, dword ptr [ecx]
// 005f3905  8b09                 mov ecx, dword ptr [ecx]
// 005f3907  57                   push edi
// 005f3908  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f390b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f3912  a802                 test al, 2
// 005f3914  7410                 je 0x5f3926
// 005f3916  8b4108               mov eax, dword ptr [ecx + 8]
// 005f3919  8b5004               mov edx, dword ptr [eax + 4]
// 005f391c  8b4c0a30             mov ecx, dword ptr [edx + ecx + 0x30]
// 005f3920  ff1570238000         call dword ptr [0x802370]
// 005f3926  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f3929  5f                   pop edi
// 005f392a  5e                   pop esi
// 005f392b  64890d00000000       mov dword ptr fs:[0], ecx
// 005f3932  5b                   pop ebx
// 005f3933  8be5                 mov esp, ebp
// 005f3935  5d                   pop ebp
// 005f3936  c3                   ret 

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_unit_9ef8423e6ab5aac9.cpp
