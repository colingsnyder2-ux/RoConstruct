// from server: 100% by auto
// roc 2009-12 004e8160  unit: seg_004e0000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e8160
//
// 004e8160  55                   push ebp
// 004e8161  8bec                 mov ebp, esp
// 004e8163  83ec0c               sub esp, 0xc
// 004e8166  894df4               mov dword ptr [ebp - 0xc], ecx
// 004e8169  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004e816c  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e816f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e8172  52                   push edx
// 004e8173  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e8176  e825050000           call 0x4e86a0
// 004e817b  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004e817e  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e8181  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004e8184  8b4218               mov eax, dword ptr [edx + 0x18]
// 004e8187  894104               mov dword ptr [ecx + 4], eax
// 004e818a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e818d  c7411c00000000       mov dword ptr [ecx + 0x1c], 0
// 004e8194  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004e8197  8b4218               mov eax, dword ptr [edx + 0x18]
// 004e819a  8945f8               mov dword ptr [ebp - 8], eax
// 004e819d  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004e81a0  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004e81a3  8b4218               mov eax, dword ptr [edx + 0x18]
// 004e81a6  8901                 mov dword ptr [ecx], eax
// 004e81a8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004e81ab  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004e81ae  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004e81b1  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e81b4  894a08               mov dword ptr [edx + 8], ecx
// 004e81b7  8be5                 mov esp, ebp
// 004e81b9  5d                   pop ebp
// 004e81ba  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?clear@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
