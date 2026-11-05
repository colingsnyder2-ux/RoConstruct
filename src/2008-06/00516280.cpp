// from server: 100% by auto
// roc 2008-06 00516280  unit: G3D::BinaryInput  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00516280
//
// 00516280  83ec18               sub esp, 0x18
// 00516283  53                   push ebx
// 00516284  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00516288  56                   push esi
// 00516289  8bf1                 mov esi, ecx
// 0051628b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0051628e  57                   push edi
// 0051628f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00516292  8bc7                 mov eax, edi
// 00516294  2bc1                 sub eax, ecx
// 00516296  3bd8                 cmp ebx, eax
// 00516298  762c                 jbe 0x5162c6
// 0051629a  3bcf                 cmp ecx, edi
// 0051629c  7606                 jbe 0x5162a4
// 0051629e  ff1590288000         call dword ptr [0x802890]
// 005162a4  8b560c               mov edx, dword ptr [esi + 0xc]
// 005162a7  2b5610               sub edx, dword ptr [esi + 0x10]
// 005162aa  8b06                 mov eax, dword ptr [esi]
// 005162ac  8d4c242c             lea ecx, [esp + 0x2c]
// 005162b0  51                   push ecx
// 005162b1  03d3                 add edx, ebx
// 005162b3  52                   push edx
// 005162b4  57                   push edi
// 005162b5  50                   push eax
// 005162b6  8bce                 mov ecx, esi
// 005162b8  e843feffff           call 0x516100
// 005162bd  5f                   pop edi
// 005162be  5e                   pop esi
// 005162bf  5b                   pop ebx
// 005162c0  83c418               add esp, 0x18
// 005162c3  c20800               ret 8
// 005162c6  7352                 jae 0x51631a
// 005162c8  3bcf                 cmp ecx, edi
// 005162ca  7606                 jbe 0x5162d2
// 005162cc  ff1590288000         call dword ptr [0x802890]
// 005162d2  8b06                 mov eax, dword ptr [esi]
// 005162d4  55                   push ebp
// 005162d5  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 005162d8  89442418             mov dword ptr [esp + 0x18], eax
// 005162dc  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 005162df  7606                 jbe 0x5162e7
// 005162e1  ff1590288000         call dword ptr [0x802890]
// 005162e7  8b0e                 mov ecx, dword ptr [esi]
// 005162e9  53                   push ebx
// 005162ea  8d542424             lea edx, [esp + 0x24]
// 005162ee  894c2414             mov dword ptr [esp + 0x14], ecx
// 005162f2  52                   push edx
// 005162f3  8d4c2418             lea ecx, [esp + 0x18]
// 005162f7  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005162fb  e8e0fbffff           call 0x515ee0
// 00516300  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00516304  8b5004               mov edx, dword ptr [eax + 4]
// 00516307  8b00                 mov eax, dword ptr [eax]
// 00516309  57                   push edi
// 0051630a  51                   push ecx
// 0051630b  52                   push edx
// 0051630c  50                   push eax
// 0051630d  8d4c2428             lea ecx, [esp + 0x28]
// 00516311  51                   push ecx
// 00516312  8bce                 mov ecx, esi
// 00516314  e897fcffff           call 0x515fb0
// 00516319  5d                   pop ebp
// 0051631a  5f                   pop edi
// 0051631b  5e                   pop esi
// 0051631c  5b                   pop ebx
// 0051631d  83c418               add esp, 0x18
// 00516320  c20800               ret 8
// standard library vector<char> (function ?resize@?$vector@DV?$allocator@D@std@@@std@@QAEXID@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
