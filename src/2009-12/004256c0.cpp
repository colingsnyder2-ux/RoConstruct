// from server: 100% by auto
// roc 2009-12 004256c0  unit: MainLogManager  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004256c0
//
// 004256c0  83ec08               sub esp, 8
// 004256c3  53                   push ebx
// 004256c4  55                   push ebp
// 004256c5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004256cb  56                   push esi
// 004256cc  8bf1                 mov esi, ecx
// 004256ce  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004256d1  57                   push edi
// 004256d2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004256d5  8bcb                 mov ecx, ebx
// 004256d7  2bcf                 sub ecx, edi
// 004256d9  b893244992           mov eax, 0x92492493
// 004256de  f7e9                 imul ecx
// 004256e0  03d1                 add edx, ecx
// 004256e2  c1fa04               sar edx, 4
// 004256e5  8bc2                 mov eax, edx
// 004256e7  c1e81f               shr eax, 0x1f
// 004256ea  03c2                 add eax, edx
// 004256ec  7504                 jne 0x4256f2
// 004256ee  33ff                 xor edi, edi
// 004256f0  eb2f                 jmp 0x425721
// 004256f2  3bfb                 cmp edi, ebx
// 004256f4  7602                 jbe 0x4256f8
// 004256f6  ffd5                 call ebp
// 004256f8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004256fc  8b06                 mov eax, dword ptr [esi]
// 004256fe  85c9                 test ecx, ecx
// 00425700  7404                 je 0x425706
// 00425702  3bc8                 cmp ecx, eax
// 00425704  7402                 je 0x425708
// 00425706  ffd5                 call ebp
// 00425708  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0042570c  2bcf                 sub ecx, edi
// 0042570e  b893244992           mov eax, 0x92492493
// 00425713  f7e9                 imul ecx
// 00425715  03d1                 add edx, ecx
// 00425717  c1fa04               sar edx, 4
// 0042571a  8bfa                 mov edi, edx
// 0042571c  c1ef1f               shr edi, 0x1f
// 0042571f  03fa                 add edi, edx
// 00425721  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00425725  8b542424             mov edx, dword ptr [esp + 0x24]
// 00425729  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042572d  51                   push ecx
// 0042572e  6a01                 push 1
// 00425730  52                   push edx
// 00425731  50                   push eax
// 00425732  8bce                 mov ecx, esi
// 00425734  e8f7faffff           call 0x425230
// 00425739  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0042573c  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0042573f  7602                 jbe 0x425743
// 00425741  ffd5                 call ebp
// 00425743  8b36                 mov esi, dword ptr [esi]
// 00425745  57                   push edi
// 00425746  8d4c2414             lea ecx, [esp + 0x14]
// 0042574a  89742414             mov dword ptr [esp + 0x14], esi
// 0042574e  895c2418             mov dword ptr [esp + 0x18], ebx
// 00425752  e869e3ffff           call 0x423ac0
// 00425757  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042575b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042575f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00425763  5f                   pop edi
// 00425764  5e                   pop esi
// 00425765  5d                   pop ebp
// 00425766  8908                 mov dword ptr [eax], ecx
// 00425768  895004               mov dword ptr [eax + 4], edx
// 0042576b  5b                   pop ebx
// 0042576c  83c408               add esp, 8
// 0042576f  c21000               ret 0x10
// standard library vector<string> (function ?insert@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Vector_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@V?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
