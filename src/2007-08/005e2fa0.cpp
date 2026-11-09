// from server: 100% by auto
// roc 2007-08 005e2fa0  unit: RBX::IMovingManager  size: 187 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e2fa0
//
// 005e2fa0  64a100000000         mov eax, dword ptr fs:[0]
// 005e2fa6  6aff                 push -1
// 005e2fa8  68a8aa7500           push 0x75aaa8
// 005e2fad  50                   push eax
// 005e2fae  64892500000000       mov dword ptr fs:[0], esp
// 005e2fb5  83ec28               sub esp, 0x28
// 005e2fb8  53                   push ebx
// 005e2fb9  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 005e2fbd  56                   push esi
// 005e2fbe  57                   push edi
// 005e2fbf  53                   push ebx
// 005e2fc0  8bf1                 mov esi, ecx
// 005e2fc2  e899fcf5ff           call 0x542c60
// 005e2fc7  85f6                 test esi, esi
// 005e2fc9  8bf8                 mov edi, eax
// 005e2fcb  7506                 jne 0x5e2fd3
// 005e2fcd  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e2fd3  3b7e04               cmp edi, dword ptr [esi + 4]
// 005e2fd6  7412                 je 0x5e2fea
// 005e2fd8  8d470c               lea eax, [edi + 0xc]
// 005e2fdb  50                   push eax
// 005e2fdc  53                   push ebx
// 005e2fdd  ff1520e67700         call dword ptr [0x77e620]
// 005e2fe3  83c408               add esp, 8
// 005e2fe6  84c0                 test al, al
// 005e2fe8  7445                 je 0x5e302f
// 005e2fea  53                   push ebx
// 005e2feb  8d4c2418             lea ecx, [esp + 0x18]
// 005e2fef  ff159ce67700         call dword ptr [0x77e69c]
// 005e2ff5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005e2ffd  8d4c2414             lea ecx, [esp + 0x14]
// 005e3001  51                   push ecx
// 005e3002  57                   push edi
// 005e3003  56                   push esi
// 005e3004  8d542418             lea edx, [esp + 0x18]
// 005e3008  52                   push edx
// 005e3009  8bce                 mov ecx, esi
// 005e300b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005e3013  e878fdffff           call 0x5e2d90
// 005e3018  8b30                 mov esi, dword ptr [eax]
// 005e301a  8b7804               mov edi, dword ptr [eax + 4]
// 005e301d  8d4c2414             lea ecx, [esp + 0x14]
// 005e3021  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 005e3029  ff15ace67700         call dword ptr [0x77e6ac]
// 005e302f  85f6                 test esi, esi
// 005e3031  7506                 jne 0x5e3039
// 005e3033  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e3039  3b7e04               cmp edi, dword ptr [esi + 4]
// 005e303c  7506                 jne 0x5e3044
// 005e303e  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e3044  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005e3048  8d4728               lea eax, [edi + 0x28]
// 005e304b  5f                   pop edi
// 005e304c  5e                   pop esi
// 005e304d  5b                   pop ebx
// 005e304e  64890d00000000       mov dword ptr fs:[0], ecx
// 005e3055  83c434               add esp, 0x34
// 005e3058  c20400               ret 4
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
