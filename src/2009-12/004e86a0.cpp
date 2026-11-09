// from server: 100% by auto
// roc 2009-12 004e86a0  unit: seg_004e0000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e86a0
//
// 004e86a0  55                   push ebp
// 004e86a1  8bec                 mov ebp, esp
// 004e86a3  83ec08               sub esp, 8
// 004e86a6  894df8               mov dword ptr [ebp - 8], ecx
// 004e86a9  8b4508               mov eax, dword ptr [ebp + 8]
// 004e86ac  8945fc               mov dword ptr [ebp - 4], eax
// 004e86af  eb06                 jmp 0x4e86b7
// 004e86b1  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e86b4  894d08               mov dword ptr [ebp + 8], ecx
// 004e86b7  8b55fc               mov edx, dword ptr [ebp - 4]
// 004e86ba  0fbe4215             movsx eax, byte ptr [edx + 0x15]
// 004e86be  85c0                 test eax, eax
// 004e86c0  7525                 jne 0x4e86e7
// 004e86c2  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e86c5  8b5108               mov edx, dword ptr [ecx + 8]
// 004e86c8  52                   push edx
// 004e86c9  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004e86cc  e8cfffffff           call 0x4e86a0
// 004e86d1  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e86d4  8b08                 mov ecx, dword ptr [eax]
// 004e86d6  894dfc               mov dword ptr [ebp - 4], ecx
// 004e86d9  8b5508               mov edx, dword ptr [ebp + 8]
// 004e86dc  52                   push edx
// 004e86dd  e878b13000           call 0x7f385a
// 004e86e2  83c404               add esp, 4
// 004e86e5  ebca                 jmp 0x4e86b1
// 004e86e7  8be5                 mov esp, ebp
// 004e86e9  5d                   pop ebp
// 004e86ea  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Erase@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
