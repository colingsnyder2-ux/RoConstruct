// from server: 100% by auto
// roc 2012-06 0044dea0  unit: boost::gregorian::Ubad_day_of_year::?$error_info_injector  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044dea0
//
// 0044dea0  53                   push ebx
// 0044dea1  56                   push esi
// 0044dea2  8bf1                 mov esi, ecx
// 0044dea4  33db                 xor ebx, ebx
// 0044dea6  57                   push edi
// 0044dea7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044deaa  7440                 je 0x44deec
// 0044deac  83cfff               or edi, 0xffffffff
// 0044deaf  90                   nop 
// 0044deb0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044deb3  3bc3                 cmp eax, ebx
// 0044deb5  7430                 je 0x44dee7
// 0044deb7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044deba  8b5614               mov edx, dword ptr [esi + 0x14]
// 0044debd  8d4408ff             lea eax, [eax + ecx - 1]
// 0044dec1  8bc8                 mov ecx, eax
// 0044dec3  c1e904               shr ecx, 4
// 0044dec6  3bd1                 cmp edx, ecx
// 0044dec8  7702                 ja 0x44decc
// 0044deca  2bca                 sub ecx, edx
// 0044decc  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044decf  83e00f               and eax, 0xf
// 0044ded2  03048a               add eax, dword ptr [edx + ecx*4]
// 0044ded5  8d4e0c               lea ecx, [esi + 0xc]
// 0044ded8  50                   push eax
// 0044ded9  ff152826b200         call dword ptr [0xb22628]
// 0044dedf  017e1c               add dword ptr [esi + 0x1c], edi
// 0044dee2  7503                 jne 0x44dee7
// 0044dee4  895e18               mov dword ptr [esi + 0x18], ebx
// 0044dee7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044deea  75c4                 jne 0x44deb0
// 0044deec  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0044deef  3bfb                 cmp edi, ebx
// 0044def1  761e                 jbe 0x44df11
// 0044def3  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044def6  4f                   dec edi
// 0044def7  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0044defa  8d04b8               lea eax, [eax + edi*4]
// 0044defd  740e                 je 0x44df0d
// 0044deff  8b08                 mov ecx, dword ptr [eax]
// 0044df01  6a10                 push 0x10
// 0044df03  51                   push ecx
// 0044df04  8d4e0c               lea ecx, [esi + 0xc]
// 0044df07  ff15f825b200         call dword ptr [0xb225f8]
// 0044df0d  3bfb                 cmp edi, ebx
// 0044df0f  77e2                 ja 0x44def3
// 0044df11  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044df14  3bc3                 cmp eax, ebx
// 0044df16  7409                 je 0x44df21
// 0044df18  50                   push eax
// 0044df19  e8f6415300           call 0x982114
// 0044df1e  83c404               add esp, 4
// 0044df21  5f                   pop edi
// 0044df22  895e10               mov dword ptr [esi + 0x10], ebx
// 0044df25  895e14               mov dword ptr [esi + 0x14], ebx
// 0044df28  5e                   pop esi
// 0044df29  5b                   pop ebx
// 0044df2a  c3                   ret 
// standard library deque<char> (function ?_Tidy@?$deque@DV?$allocator@D@std@@@std@@IAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
