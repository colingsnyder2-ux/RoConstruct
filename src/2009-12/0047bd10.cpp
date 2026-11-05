// from server: 100% by auto
// roc 2009-12 0047bd10  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047bd10
//
// 0047bd10  83ec08               sub esp, 8
// 0047bd13  53                   push ebx
// 0047bd14  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047bd18  56                   push esi
// 0047bd19  8bf1                 mov esi, ecx
// 0047bd1b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047bd1e  57                   push edi
// 0047bd1f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0047bd22  8bc8                 mov ecx, eax
// 0047bd24  2bcf                 sub ecx, edi
// 0047bd26  c1f906               sar ecx, 6
// 0047bd29  3bcb                 cmp ecx, ebx
// 0047bd2b  7705                 ja 0x47bd32
// 0047bd2d  e8cea63400           call 0x7c6400
// 0047bd32  3bf8                 cmp edi, eax
// 0047bd34  7606                 jbe 0x47bd3c
// 0047bd36  ff1560b79800         call dword ptr [0x98b760]
// 0047bd3c  8b36                 mov esi, dword ptr [esi]
// 0047bd3e  55                   push ebp
// 0047bd3f  8bee                 mov ebp, esi
// 0047bd41  897c2414             mov dword ptr [esp + 0x14], edi
// 0047bd45  85f6                 test esi, esi
// 0047bd47  751a                 jne 0x47bd63
// 0047bd49  ff1560b79800         call dword ptr [0x98b760]
// 0047bd4f  33c0                 xor eax, eax
// 0047bd51  c1e306               shl ebx, 6
// 0047bd54  03fb                 add edi, ebx
// 0047bd56  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047bd59  7713                 ja 0x47bd6e
// 0047bd5b  85f6                 test esi, esi
// 0047bd5d  7408                 je 0x47bd67
// 0047bd5f  8b36                 mov esi, dword ptr [esi]
// 0047bd61  eb06                 jmp 0x47bd69
// 0047bd63  8b06                 mov eax, dword ptr [esi]
// 0047bd65  ebea                 jmp 0x47bd51
// 0047bd67  33f6                 xor esi, esi
// 0047bd69  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0047bd6c  730a                 jae 0x47bd78
// 0047bd6e  8b3560b79800         mov esi, dword ptr [0x98b760]
// 0047bd74  ffd6                 call esi
// 0047bd76  eb06                 jmp 0x47bd7e
// 0047bd78  8b3560b79800         mov esi, dword ptr [0x98b760]
// 0047bd7e  85ed                 test ebp, ebp
// 0047bd80  7517                 jne 0x47bd99
// 0047bd82  ffd6                 call esi
// 0047bd84  33c0                 xor eax, eax
// 0047bd86  5d                   pop ebp
// 0047bd87  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047bd8a  7202                 jb 0x47bd8e
// 0047bd8c  ffd6                 call esi
// 0047bd8e  8bc7                 mov eax, edi
// 0047bd90  5f                   pop edi
// 0047bd91  5e                   pop esi
// 0047bd92  5b                   pop ebx
// 0047bd93  83c408               add esp, 8
// 0047bd96  c20400               ret 4
// 0047bd99  8b4500               mov eax, dword ptr [ebp]
// 0047bd9c  ebe8                 jmp 0x47bd86
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
