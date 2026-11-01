// from server: 100% by auto
// roc 2009-06 00444dc0  unit: G3D::_WeakPtr  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444dc0
//
// 00444dc0  51                   push ecx
// 00444dc1  56                   push esi
// 00444dc2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00444dc6  8b4608               mov eax, dword ptr [esi + 8]
// 00444dc9  c744240400000000     mov dword ptr [esp + 4], 0
// 00444dd1  85c0                 test eax, eax
// 00444dd3  7505                 jne 0x444dda
// 00444dd5  5e                   pop esi
// 00444dd6  59                   pop ecx
// 00444dd7  c20c00               ret 0xc
// 00444dda  8b560c               mov edx, dword ptr [esi + 0xc]
// 00444ddd  57                   push edi
// 00444dde  8d4c2408             lea ecx, [esp + 8]
// 00444de2  51                   push ecx
// 00444de3  685cd08a00           push 0x8ad05c
// 00444de8  52                   push edx
// 00444de9  ffd0                 call eax
// 00444deb  8bf8                 mov edi, eax
// 00444ded  85ff                 test edi, edi
// 00444def  7c1e                 jl 0x444e0f
// 00444df1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00444df5  8b542414             mov edx, dword ptr [esp + 0x14]
// 00444df9  8d4614               lea eax, [esi + 0x14]
// 00444dfc  50                   push eax
// 00444dfd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00444e01  51                   push ecx
// 00444e02  8b0e                 mov ecx, dword ptr [esi]
// 00444e04  52                   push edx
// 00444e05  50                   push eax
// 00444e06  51                   push ecx
// 00444e07  ff15f4028a00         call dword ptr [0x8a02f4]
// 00444e0d  8bf8                 mov edi, eax
// 00444e0f  8b442408             mov eax, dword ptr [esp + 8]
// 00444e13  85c0                 test eax, eax
// 00444e15  7408                 je 0x444e1f
// 00444e17  8b10                 mov edx, dword ptr [eax]
// 00444e19  50                   push eax
// 00444e1a  8b4208               mov eax, dword ptr [edx + 8]
// 00444e1d  ffd0                 call eax
// 00444e1f  8bc7                 mov eax, edi
// 00444e21  5f                   pop edi
// 00444e22  5e                   pop esi
// 00444e23  59                   pop ecx
// 00444e24  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
