// from server: 100% by auto
// roc 2009-12 004f1000  unit: seg_004f0000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f1000
//
// 004f1000  55                   push ebp
// 004f1001  8bec                 mov ebp, esp
// 004f1003  83ec08               sub esp, 8
// 004f1006  894df8               mov dword ptr [ebp - 8], ecx
// 004f1009  8b45f8               mov eax, dword ptr [ebp - 8]
// 004f100c  8b08                 mov ecx, dword ptr [eax]
// 004f100e  894dfc               mov dword ptr [ebp - 4], ecx
// 004f1011  8b55fc               mov edx, dword ptr [ebp - 4]
// 004f1014  52                   push edx
// 004f1015  e840283000           call 0x7f385a
// 004f101a  83c404               add esp, 4
// 004f101d  8be5                 mov esp, ebp
// 004f101f  5d                   pop ebp
// 004f1020  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ??1?$_Container_base_aux_alloc_real@V?$allocator@U?$pair@HH@std@@@std@@@std@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
