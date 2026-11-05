// from server: 100% by auto
// roc 2010-06 0091b340  unit: RBX::GfxAttachement  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0091b340
//
// 0091b340  55                   push ebp
// 0091b341  8bec                 mov ebp, esp
// 0091b343  83ec08               sub esp, 8
// 0091b346  894df8               mov dword ptr [ebp - 8], ecx
// 0091b349  8b45f8               mov eax, dword ptr [ebp - 8]
// 0091b34c  8b08                 mov ecx, dword ptr [eax]
// 0091b34e  894dfc               mov dword ptr [ebp - 4], ecx
// 0091b351  8b55fc               mov edx, dword ptr [ebp - 4]
// 0091b354  52                   push edx
// 0091b355  e840c6e8ff           call 0x7a799a
// 0091b35a  83c404               add esp, 4
// 0091b35d  8be5                 mov esp, ebp
// 0091b35f  5d                   pop ebp
// 0091b360  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ??1?$_Container_base_aux_alloc_real@V?$allocator@U?$pair@HH@std@@@std@@@std@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
