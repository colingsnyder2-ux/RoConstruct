// from server: 100% by auto
// roc 2009-12 006320d0  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006320d0
//
// 006320d0  64a100000000         mov eax, dword ptr fs:[0]
// 006320d6  6aff                 push -1
// 006320d8  68a85a9400           push 0x945aa8
// 006320dd  50                   push eax
// 006320de  64892500000000       mov dword ptr fs:[0], esp
// 006320e5  83ec28               sub esp, 0x28
// 006320e8  53                   push ebx
// 006320e9  55                   push ebp
// 006320ea  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 006320ee  56                   push esi
// 006320ef  55                   push ebp
// 006320f0  8bf1                 mov esi, ecx
// 006320f2  e8c9fcffff           call 0x631dc0
// 006320f7  8bd8                 mov ebx, eax
// 006320f9  85f6                 test esi, esi
// 006320fb  7506                 jne 0x632103
// 006320fd  ff1560b79800         call dword ptr [0x98b760]
// 00632103  8b4618               mov eax, dword ptr [esi + 0x18]
// 00632106  57                   push edi
// 00632107  8b3e                 mov edi, dword ptr [esi]
// 00632109  89442414             mov dword ptr [esp + 0x14], eax
// 0063210d  85ff                 test edi, edi
// 0063210f  7404                 je 0x632115
// 00632111  3bff                 cmp edi, edi
// 00632113  7406                 je 0x63211b
// 00632115  ff1560b79800         call dword ptr [0x98b760]
// 0063211b  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0063211f  7412                 je 0x632133
// 00632121  8d4b0c               lea ecx, [ebx + 0xc]
// 00632124  51                   push ecx
// 00632125  55                   push ebp
// 00632126  ff15d8b59800         call dword ptr [0x98b5d8]
// 0063212c  83c408               add esp, 8
// 0063212f  84c0                 test al, al
// 00632131  743f                 je 0x632172
// 00632133  55                   push ebp
// 00632134  8d4c241c             lea ecx, [esp + 0x1c]
// 00632138  ff15f0b69800         call dword ptr [0x98b6f0]
// 0063213e  33c0                 xor eax, eax
// 00632140  89442434             mov dword ptr [esp + 0x34], eax
// 00632144  8d542418             lea edx, [esp + 0x18]
// 00632148  52                   push edx
// 00632149  53                   push ebx
// 0063214a  89442448             mov dword ptr [esp + 0x48], eax
// 0063214e  57                   push edi
// 0063214f  8d44241c             lea eax, [esp + 0x1c]
// 00632153  50                   push eax
// 00632154  8bce                 mov ecx, esi
// 00632156  e835fdffff           call 0x631e90
// 0063215b  8b38                 mov edi, dword ptr [eax]
// 0063215d  8b5804               mov ebx, dword ptr [eax + 4]
// 00632160  8d4c2418             lea ecx, [esp + 0x18]
// 00632164  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0063216c  ff15e4b69800         call dword ptr [0x98b6e4]
// 00632172  85ff                 test edi, edi
// 00632174  7529                 jne 0x63219f
// 00632176  ff1560b79800         call dword ptr [0x98b760]
// 0063217c  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 0063217f  5f                   pop edi
// 00632180  7506                 jne 0x632188
// 00632182  ff1560b79800         call dword ptr [0x98b760]
// 00632188  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0063218c  5e                   pop esi
// 0063218d  5d                   pop ebp
// 0063218e  8d4328               lea eax, [ebx + 0x28]
// 00632191  5b                   pop ebx
// 00632192  64890d00000000       mov dword ptr fs:[0], ecx
// 00632199  83c434               add esp, 0x34
// 0063219c  c20400               ret 4
// 0063219f  8b3f                 mov edi, dword ptr [edi]
// 006321a1  ebd9                 jmp 0x63217c
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
