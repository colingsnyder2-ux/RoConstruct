// from server: 100% by auto
// roc 2009-12 0091ff50  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0091ff50
//
// 0091ff50  55                   push ebp
// 0091ff51  8bec                 mov ebp, esp
// 0091ff53  83ec0c               sub esp, 0xc
// 0091ff56  894df4               mov dword ptr [ebp - 0xc], ecx
// 0091ff59  8b4508               mov eax, dword ptr [ebp + 8]
// 0091ff5c  8b08                 mov ecx, dword ptr [eax]
// 0091ff5e  894dfc               mov dword ptr [ebp - 4], ecx
// 0091ff61  8b5508               mov edx, dword ptr [ebp + 8]
// 0091ff64  8b45fc               mov eax, dword ptr [ebp - 4]
// 0091ff67  8b4808               mov ecx, dword ptr [eax + 8]
// 0091ff6a  890a                 mov dword ptr [edx], ecx
// 0091ff6c  8b55fc               mov edx, dword ptr [ebp - 4]
// 0091ff6f  8b4208               mov eax, dword ptr [edx + 8]
// 0091ff72  0fbe4815             movsx ecx, byte ptr [eax + 0x15]
// 0091ff76  85c9                 test ecx, ecx
// 0091ff78  750c                 jne 0x91ff86
// 0091ff7a  8b55fc               mov edx, dword ptr [ebp - 4]
// 0091ff7d  8b4208               mov eax, dword ptr [edx + 8]
// 0091ff80  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0091ff83  894804               mov dword ptr [eax + 4], ecx
// 0091ff86  8b55fc               mov edx, dword ptr [ebp - 4]
// 0091ff89  8b4508               mov eax, dword ptr [ebp + 8]
// 0091ff8c  8b4804               mov ecx, dword ptr [eax + 4]
// 0091ff8f  894a04               mov dword ptr [edx + 4], ecx
// 0091ff92  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 0091ff95  8b4218               mov eax, dword ptr [edx + 0x18]
// 0091ff98  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0091ff9b  3b4804               cmp ecx, dword ptr [eax + 4]
// 0091ff9e  750e                 jne 0x91ffae
// 0091ffa0  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 0091ffa3  8b4218               mov eax, dword ptr [edx + 0x18]
// 0091ffa6  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0091ffa9  894804               mov dword ptr [eax + 4], ecx
// 0091ffac  eb2d                 jmp 0x91ffdb
// 0091ffae  8b5508               mov edx, dword ptr [ebp + 8]
// 0091ffb1  8b4204               mov eax, dword ptr [edx + 4]
// 0091ffb4  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0091ffb7  3b4808               cmp ecx, dword ptr [eax + 8]
// 0091ffba  750e                 jne 0x91ffca
// 0091ffbc  8b5508               mov edx, dword ptr [ebp + 8]
// 0091ffbf  8b4204               mov eax, dword ptr [edx + 4]
// 0091ffc2  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0091ffc5  894808               mov dword ptr [eax + 8], ecx
// 0091ffc8  eb11                 jmp 0x91ffdb
// 0091ffca  8b5508               mov edx, dword ptr [ebp + 8]
// 0091ffcd  8b4204               mov eax, dword ptr [edx + 4]
// 0091ffd0  8945f8               mov dword ptr [ebp - 8], eax
// 0091ffd3  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091ffd6  8b55fc               mov edx, dword ptr [ebp - 4]
// 0091ffd9  8911                 mov dword ptr [ecx], edx
// 0091ffdb  8b45fc               mov eax, dword ptr [ebp - 4]
// 0091ffde  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0091ffe1  894808               mov dword ptr [eax + 8], ecx
// 0091ffe4  8b5508               mov edx, dword ptr [ebp + 8]
// 0091ffe7  8b45fc               mov eax, dword ptr [ebp - 4]
// 0091ffea  894204               mov dword ptr [edx + 4], eax
// 0091ffed  8be5                 mov esp, ebp
// 0091ffef  5d                   pop ebp
// 0091fff0  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?_Rrotate@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
