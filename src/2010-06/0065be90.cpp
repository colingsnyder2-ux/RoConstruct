// from server: 100% by auto
// roc 2010-06 0065be90  unit: RBX::VInstance::?$NonFactoryProduct  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065be90
//
// 0065be90  83ec08               sub esp, 8
// 0065be93  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065be97  53                   push ebx
// 0065be98  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0065be9e  56                   push esi
// 0065be9f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065bea3  57                   push edi
// 0065bea4  8bf9                 mov edi, ecx
// 0065bea6  8944240c             mov dword ptr [esp + 0xc], eax
// 0065beaa  85c0                 test eax, eax
// 0065beac  750a                 jne 0x65beb8
// 0065beae  ffd3                 call ebx
// 0065beb0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065beb4  85c0                 test eax, eax
// 0065beb6  7404                 je 0x65bebc
// 0065beb8  8b00                 mov eax, dword ptr [eax]
// 0065beba  eb02                 jmp 0x65bebe
// 0065bebc  33c0                 xor eax, eax
// 0065bebe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065bec2  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0065bec5  7502                 jne 0x65bec9
// 0065bec7  ffd3                 call ebx
// 0065bec9  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065becd  8b02                 mov eax, dword ptr [edx]
// 0065becf  89442420             mov dword ptr [esp + 0x20], eax
// 0065bed3  3b7714               cmp esi, dword ptr [edi + 0x14]
// 0065bed6  7424                 je 0x65befc
// 0065bed8  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065bedb  8b16                 mov edx, dword ptr [esi]
// 0065bedd  8911                 mov dword ptr [ecx], edx
// 0065bedf  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065bee2  8b06                 mov eax, dword ptr [esi]
// 0065bee4  894804               mov dword ptr [eax + 4], ecx
// 0065bee7  8d4e08               lea ecx, [esi + 8]
// 0065beea  ff1500a49e00         call dword ptr [0x9ea400]
// 0065bef0  56                   push esi
// 0065bef1  e8a4ba1400           call 0x7a799a
// 0065bef6  83c404               add esp, 4
// 0065bef9  ff4f18               dec dword ptr [edi + 0x18]
// 0065befc  8b0f                 mov ecx, dword ptr [edi]
// 0065befe  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065bf02  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065bf06  5f                   pop edi
// 0065bf07  5e                   pop esi
// 0065bf08  895004               mov dword ptr [eax + 4], edx
// 0065bf0b  8908                 mov dword ptr [eax], ecx
// 0065bf0d  5b                   pop ebx
// 0065bf0e  83c408               add esp, 8
// 0065bf11  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
