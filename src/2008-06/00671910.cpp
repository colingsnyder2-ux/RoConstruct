// from server: 100% by auto
// roc 2008-06 00671910  unit: RBX::AdornRbxGfx  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671910
//
// 00671910  64a100000000         mov eax, dword ptr fs:[0]
// 00671916  6aff                 push -1
// 00671918  68e88e7d00           push 0x7d8ee8
// 0067191d  50                   push eax
// 0067191e  64892500000000       mov dword ptr fs:[0], esp
// 00671925  83ec28               sub esp, 0x28
// 00671928  53                   push ebx
// 00671929  55                   push ebp
// 0067192a  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0067192e  56                   push esi
// 0067192f  55                   push ebp
// 00671930  8bf1                 mov esi, ecx
// 00671932  e84920eeff           call 0x553980
// 00671937  8bd8                 mov ebx, eax
// 00671939  85f6                 test esi, esi
// 0067193b  7506                 jne 0x671943
// 0067193d  ff1590288000         call dword ptr [0x802890]
// 00671943  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671946  57                   push edi
// 00671947  8b3e                 mov edi, dword ptr [esi]
// 00671949  89442414             mov dword ptr [esp + 0x14], eax
// 0067194d  85ff                 test edi, edi
// 0067194f  7404                 je 0x671955
// 00671951  3bff                 cmp edi, edi
// 00671953  7406                 je 0x67195b
// 00671955  ff1590288000         call dword ptr [0x802890]
// 0067195b  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0067195f  7412                 je 0x671973
// 00671961  8d4b0c               lea ecx, [ebx + 0xc]
// 00671964  51                   push ecx
// 00671965  55                   push ebp
// 00671966  ff155c238000         call dword ptr [0x80235c]
// 0067196c  83c408               add esp, 8
// 0067196f  84c0                 test al, al
// 00671971  743f                 je 0x6719b2
// 00671973  55                   push ebp
// 00671974  8d4c241c             lea ecx, [esp + 0x1c]
// 00671978  ff155c248000         call dword ptr [0x80245c]
// 0067197e  33c0                 xor eax, eax
// 00671980  89442434             mov dword ptr [esp + 0x34], eax
// 00671984  8d542418             lea edx, [esp + 0x18]
// 00671988  52                   push edx
// 00671989  53                   push ebx
// 0067198a  89442448             mov dword ptr [esp + 0x48], eax
// 0067198e  57                   push edi
// 0067198f  8d44241c             lea eax, [esp + 0x1c]
// 00671993  50                   push eax
// 00671994  8bce                 mov ecx, esi
// 00671996  e815faffff           call 0x6713b0
// 0067199b  8b38                 mov edi, dword ptr [eax]
// 0067199d  8b5804               mov ebx, dword ptr [eax + 4]
// 006719a0  8d4c2418             lea ecx, [esp + 0x18]
// 006719a4  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 006719ac  ff1568248000         call dword ptr [0x802468]
// 006719b2  85ff                 test edi, edi
// 006719b4  7529                 jne 0x6719df
// 006719b6  ff1590288000         call dword ptr [0x802890]
// 006719bc  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 006719bf  5f                   pop edi
// 006719c0  7506                 jne 0x6719c8
// 006719c2  ff1590288000         call dword ptr [0x802890]
// 006719c8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006719cc  5e                   pop esi
// 006719cd  5d                   pop ebp
// 006719ce  8d4328               lea eax, [ebx + 0x28]
// 006719d1  5b                   pop ebx
// 006719d2  64890d00000000       mov dword ptr fs:[0], ecx
// 006719d9  83c434               add esp, 0x34
// 006719dc  c20400               ret 4
// 006719df  8b3f                 mov edi, dword ptr [edi]
// 006719e1  ebd9                 jmp 0x6719bc
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
