// from server: 100% by auto
// roc 2012-06 0046eed0  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046eed0
//
// 0046eed0  83ec08               sub esp, 8
// 0046eed3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046eed7  56                   push esi
// 0046eed8  8d442404             lea eax, [esp + 4]
// 0046eedc  50                   push eax
// 0046eedd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046eee1  8d4c240c             lea ecx, [esp + 0xc]
// 0046eee5  51                   push ecx
// 0046eee6  52                   push edx
// 0046eee7  50                   push eax
// 0046eee8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046eef0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046eef8  e8c3f9ffff           call 0x46e8c0
// 0046eefd  8bf0                 mov esi, eax
// 0046eeff  85f6                 test esi, esi
// 0046ef01  7c70                 jl 0x46ef73
// 0046ef03  8b442404             mov eax, dword ptr [esp + 4]
// 0046ef07  8b08                 mov ecx, dword ptr [eax]
// 0046ef09  8d542414             lea edx, [esp + 0x14]
// 0046ef0d  52                   push edx
// 0046ef0e  50                   push eax
// 0046ef0f  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0046ef12  ffd0                 call eax
// 0046ef14  8bf0                 mov esi, eax
// 0046ef16  85f6                 test esi, esi
// 0046ef18  7c59                 jl 0x46ef73
// 0046ef1a  803d2864e10001       cmp byte ptr [0xe16428], 1
// 0046ef21  751f                 jne 0x46ef42
// 0046ef23  68c49eb500           push 0xb59ec4
// 0046ef28  ff15ec22b200         call dword ptr [0xb222ec]
// 0046ef2e  85c0                 test eax, eax
// 0046ef30  7410                 je 0x46ef42
// 0046ef32  68a89eb500           push 0xb59ea8
// 0046ef37  50                   push eax
// 0046ef38  ff15b021b200         call dword ptr [0xb221b0]
// 0046ef3e  85c0                 test eax, eax
// 0046ef40  7505                 jne 0x46ef47
// 0046ef42  a1602bb200           mov eax, dword ptr [0xb22b60]
// 0046ef47  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046ef4b  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0046ef4e  52                   push edx
// 0046ef4f  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0046ef52  52                   push edx
// 0046ef53  0fb7511a             movzx edx, word ptr [ecx + 0x1a]
// 0046ef57  52                   push edx
// 0046ef58  0fb75118             movzx edx, word ptr [ecx + 0x18]
// 0046ef5c  52                   push edx
// 0046ef5d  51                   push ecx
// 0046ef5e  ffd0                 call eax
// 0046ef60  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046ef64  8bf0                 mov esi, eax
// 0046ef66  8b442404             mov eax, dword ptr [esp + 4]
// 0046ef6a  8b08                 mov ecx, dword ptr [eax]
// 0046ef6c  52                   push edx
// 0046ef6d  50                   push eax
// 0046ef6e  8b4130               mov eax, dword ptr [ecx + 0x30]
// 0046ef71  ffd0                 call eax
// 0046ef73  8b442404             mov eax, dword ptr [esp + 4]
// 0046ef77  85c0                 test eax, eax
// 0046ef79  7408                 je 0x46ef83
// 0046ef7b  8b08                 mov ecx, dword ptr [eax]
// 0046ef7d  8b5108               mov edx, dword ptr [ecx + 8]
// 0046ef80  50                   push eax
// 0046ef81  ffd2                 call edx
// 0046ef83  8b442408             mov eax, dword ptr [esp + 8]
// 0046ef87  50                   push eax
// 0046ef88  ff15042bb200         call dword ptr [0xb22b04]
// 0046ef8e  8bc6                 mov eax, esi
// 0046ef90  5e                   pop esi
// 0046ef91  83c408               add esp, 8
// 0046ef94  c20800               ret 8
// library atl-9.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
