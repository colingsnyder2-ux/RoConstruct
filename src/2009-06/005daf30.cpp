// from server: 100% by auto
// roc 2009-06 005daf30  unit: RBX::VInstance::?$NonFactoryProduct  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005daf30
//
// 005daf30  83ec08               sub esp, 8
// 005daf33  8b442410             mov eax, dword ptr [esp + 0x10]
// 005daf37  53                   push ebx
// 005daf38  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 005daf3e  56                   push esi
// 005daf3f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005daf43  57                   push edi
// 005daf44  8bf9                 mov edi, ecx
// 005daf46  8944240c             mov dword ptr [esp + 0xc], eax
// 005daf4a  85c0                 test eax, eax
// 005daf4c  750a                 jne 0x5daf58
// 005daf4e  ffd3                 call ebx
// 005daf50  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005daf54  85c0                 test eax, eax
// 005daf56  7404                 je 0x5daf5c
// 005daf58  8b00                 mov eax, dword ptr [eax]
// 005daf5a  eb02                 jmp 0x5daf5e
// 005daf5c  33c0                 xor eax, eax
// 005daf5e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005daf62  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005daf65  7502                 jne 0x5daf69
// 005daf67  ffd3                 call ebx
// 005daf69  8b542420             mov edx, dword ptr [esp + 0x20]
// 005daf6d  8b02                 mov eax, dword ptr [edx]
// 005daf6f  89442420             mov dword ptr [esp + 0x20], eax
// 005daf73  3b7714               cmp esi, dword ptr [edi + 0x14]
// 005daf76  7424                 je 0x5daf9c
// 005daf78  8b4e04               mov ecx, dword ptr [esi + 4]
// 005daf7b  8b16                 mov edx, dword ptr [esi]
// 005daf7d  8911                 mov dword ptr [ecx], edx
// 005daf7f  8b4e04               mov ecx, dword ptr [esi + 4]
// 005daf82  8b06                 mov eax, dword ptr [esi]
// 005daf84  894804               mov dword ptr [eax + 4], ecx
// 005daf87  8d4e08               lea ecx, [esi + 8]
// 005daf8a  ff15c4e48900         call dword ptr [0x89e4c4]
// 005daf90  56                   push esi
// 005daf91  e89cda1300           call 0x718a32
// 005daf96  83c404               add esp, 4
// 005daf99  ff4f18               dec dword ptr [edi + 0x18]
// 005daf9c  8b0f                 mov ecx, dword ptr [edi]
// 005daf9e  8b442418             mov eax, dword ptr [esp + 0x18]
// 005dafa2  8b542420             mov edx, dword ptr [esp + 0x20]
// 005dafa6  5f                   pop edi
// 005dafa7  5e                   pop esi
// 005dafa8  895004               mov dword ptr [eax + 4], edx
// 005dafab  8908                 mov dword ptr [eax], ecx
// 005dafad  5b                   pop ebx
// 005dafae  83c408               add esp, 8
// 005dafb1  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
