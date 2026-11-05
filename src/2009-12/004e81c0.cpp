// from server: 100% by auto
// roc 2009-12 004e81c0  unit: seg_004e0000  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e81c0
//
// 004e81c0  55                   push ebp
// 004e81c1  8bec                 mov ebp, esp
// 004e81c3  83ec10               sub esp, 0x10
// 004e81c6  894df0               mov dword ptr [ebp - 0x10], ecx
// 004e81c9  8b4508               mov eax, dword ptr [ebp + 8]
// 004e81cc  8b4808               mov ecx, dword ptr [eax + 8]
// 004e81cf  894dfc               mov dword ptr [ebp - 4], ecx
// 004e81d2  8b5508               mov edx, dword ptr [ebp + 8]
// 004e81d5  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e81d8  8b08                 mov ecx, dword ptr [eax]
// 004e81da  894a08               mov dword ptr [edx + 8], ecx
// 004e81dd  8b55fc               mov edx, dword ptr [ebp - 4]
// 004e81e0  8b02                 mov eax, dword ptr [edx]
// 004e81e2  0fbe4815             movsx ecx, byte ptr [eax + 0x15]
// 004e81e6  85c9                 test ecx, ecx
// 004e81e8  750b                 jne 0x4e81f5
// 004e81ea  8b55fc               mov edx, dword ptr [ebp - 4]
// 004e81ed  8b02                 mov eax, dword ptr [edx]
// 004e81ef  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004e81f2  894804               mov dword ptr [eax + 4], ecx
// 004e81f5  8b55fc               mov edx, dword ptr [ebp - 4]
// 004e81f8  8b4508               mov eax, dword ptr [ebp + 8]
// 004e81fb  8b4804               mov ecx, dword ptr [eax + 4]
// 004e81fe  894a04               mov dword ptr [edx + 4], ecx
// 004e8201  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 004e8204  8b4218               mov eax, dword ptr [edx + 0x18]
// 004e8207  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004e820a  3b4804               cmp ecx, dword ptr [eax + 4]
// 004e820d  750e                 jne 0x4e821d
// 004e820f  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 004e8212  8b4218               mov eax, dword ptr [edx + 0x18]
// 004e8215  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e8218  894804               mov dword ptr [eax + 4], ecx
// 004e821b  eb32                 jmp 0x4e824f
// 004e821d  8b5508               mov edx, dword ptr [ebp + 8]
// 004e8220  8b4204               mov eax, dword ptr [edx + 4]
// 004e8223  8945f8               mov dword ptr [ebp - 8], eax
// 004e8226  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004e8229  8b5508               mov edx, dword ptr [ebp + 8]
// 004e822c  3b11                 cmp edx, dword ptr [ecx]
// 004e822e  7513                 jne 0x4e8243
// 004e8230  8b4508               mov eax, dword ptr [ebp + 8]
// 004e8233  8b4804               mov ecx, dword ptr [eax + 4]
// 004e8236  894df4               mov dword ptr [ebp - 0xc], ecx
// 004e8239  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004e823c  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e823f  8902                 mov dword ptr [edx], eax
// 004e8241  eb0c                 jmp 0x4e824f
// 004e8243  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004e8246  8b5104               mov edx, dword ptr [ecx + 4]
// 004e8249  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e824c  894208               mov dword ptr [edx + 8], eax
// 004e824f  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e8252  8b5508               mov edx, dword ptr [ebp + 8]
// 004e8255  8911                 mov dword ptr [ecx], edx
// 004e8257  8b4508               mov eax, dword ptr [ebp + 8]
// 004e825a  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e825d  894804               mov dword ptr [eax + 4], ecx
// 004e8260  8be5                 mov esp, ebp
// 004e8262  5d                   pop ebp
// 004e8263  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Lrotate@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
