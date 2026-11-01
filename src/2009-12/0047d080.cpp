// from server: 100% by auto
// roc 2009-12 0047d080  unit: RBX::LDraw2Lua::LDrawParser  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047d080
//
// 0047d080  83ec08               sub esp, 8
// 0047d083  53                   push ebx
// 0047d084  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0047d088  56                   push esi
// 0047d089  8bf1                 mov esi, ecx
// 0047d08b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047d08e  57                   push edi
// 0047d08f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0047d092  8bc8                 mov ecx, eax
// 0047d094  2bcf                 sub ecx, edi
// 0047d096  c1f902               sar ecx, 2
// 0047d099  3bcb                 cmp ecx, ebx
// 0047d09b  7705                 ja 0x47d0a2
// 0047d09d  e85e933400           call 0x7c6400
// 0047d0a2  3bf8                 cmp edi, eax
// 0047d0a4  7606                 jbe 0x47d0ac
// 0047d0a6  ff1560b79800         call dword ptr [0x98b760]
// 0047d0ac  8b36                 mov esi, dword ptr [esi]
// 0047d0ae  55                   push ebp
// 0047d0af  8bee                 mov ebp, esi
// 0047d0b1  897c2414             mov dword ptr [esp + 0x14], edi
// 0047d0b5  85f6                 test esi, esi
// 0047d0b7  7518                 jne 0x47d0d1
// 0047d0b9  ff1560b79800         call dword ptr [0x98b760]
// 0047d0bf  33c0                 xor eax, eax
// 0047d0c1  8d3c9f               lea edi, [edi + ebx*4]
// 0047d0c4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047d0c7  7713                 ja 0x47d0dc
// 0047d0c9  85f6                 test esi, esi
// 0047d0cb  7408                 je 0x47d0d5
// 0047d0cd  8b36                 mov esi, dword ptr [esi]
// 0047d0cf  eb06                 jmp 0x47d0d7
// 0047d0d1  8b06                 mov eax, dword ptr [esi]
// 0047d0d3  ebec                 jmp 0x47d0c1
// 0047d0d5  33f6                 xor esi, esi
// 0047d0d7  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0047d0da  730a                 jae 0x47d0e6
// 0047d0dc  8b3560b79800         mov esi, dword ptr [0x98b760]
// 0047d0e2  ffd6                 call esi
// 0047d0e4  eb06                 jmp 0x47d0ec
// 0047d0e6  8b3560b79800         mov esi, dword ptr [0x98b760]
// 0047d0ec  85ed                 test ebp, ebp
// 0047d0ee  7517                 jne 0x47d107
// 0047d0f0  ffd6                 call esi
// 0047d0f2  33c0                 xor eax, eax
// 0047d0f4  5d                   pop ebp
// 0047d0f5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047d0f8  7202                 jb 0x47d0fc
// 0047d0fa  ffd6                 call esi
// 0047d0fc  8bc7                 mov eax, edi
// 0047d0fe  5f                   pop edi
// 0047d0ff  5e                   pop esi
// 0047d100  5b                   pop ebx
// 0047d101  83c408               add esp, 8
// 0047d104  c20400               ret 4
// 0047d107  8b4500               mov eax, dword ptr [ebp]
// 0047d10a  ebe8                 jmp 0x47d0f4
// standard library vector<ptr> (function ?at@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
