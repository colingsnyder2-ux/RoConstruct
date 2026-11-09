// from server: 100% by auto
// roc 2008-06 004dde30  unit: RBX::RenderBase::Mesh::Level  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dde30
//
// 004dde30  83ec08               sub esp, 8
// 004dde33  53                   push ebx
// 004dde34  55                   push ebp
// 004dde35  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004dde3b  56                   push esi
// 004dde3c  8bf1                 mov esi, ecx
// 004dde3e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dde41  8b18                 mov ebx, dword ptr [eax]
// 004dde43  8b06                 mov eax, dword ptr [esi]
// 004dde45  57                   push edi
// 004dde46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dde4a  85ff                 test edi, edi
// 004dde4c  7404                 je 0x4dde52
// 004dde4e  3bf8                 cmp edi, eax
// 004dde50  7406                 je 0x4dde58
// 004dde52  ffd5                 call ebp
// 004dde54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dde58  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004dde5c  7562                 jne 0x4ddec0
// 004dde5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004dde62  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004dde65  8b06                 mov eax, dword ptr [esi]
// 004dde67  85c9                 test ecx, ecx
// 004dde69  7404                 je 0x4dde6f
// 004dde6b  3bc8                 cmp ecx, eax
// 004dde6d  7406                 je 0x4dde75
// 004dde6f  ffd5                 call ebp
// 004dde71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dde75  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004dde79  7545                 jne 0x4ddec0
// 004dde7b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004dde7e  8b5104               mov edx, dword ptr [ecx + 4]
// 004dde81  52                   push edx
// 004dde82  8bce                 mov ecx, esi
// 004dde84  e8a7f5ffff           call 0x4dd430
// 004dde89  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dde8c  894004               mov dword ptr [eax + 4], eax
// 004dde8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dde92  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004dde99  8900                 mov dword ptr [eax], eax
// 004dde9b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004dde9e  894008               mov dword ptr [eax + 8], eax
// 004ddea1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ddea4  8b16                 mov edx, dword ptr [esi]
// 004ddea6  8b08                 mov ecx, dword ptr [eax]
// 004ddea8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ddeac  5f                   pop edi
// 004ddead  5e                   pop esi
// 004ddeae  5d                   pop ebp
// 004ddeaf  894804               mov dword ptr [eax + 4], ecx
// 004ddeb2  8910                 mov dword ptr [eax], edx
// 004ddeb4  5b                   pop ebx
// 004ddeb5  83c408               add esp, 8
// 004ddeb8  c21400               ret 0x14
// 004ddebb  eb03                 jmp 0x4ddec0
// 004ddebd  8d4900               lea ecx, [ecx]
// 004ddec0  85ff                 test edi, edi
// 004ddec2  7406                 je 0x4ddeca
// 004ddec4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ddec8  7406                 je 0x4dded0
// 004ddeca  ffd5                 call ebp
// 004ddecc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004dded0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004dded4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004dded8  741d                 je 0x4ddef7
// 004ddeda  8d4c2420             lea ecx, [esp + 0x20]
// 004ddede  e87dc0f2ff           call 0x409f60
// 004ddee3  53                   push ebx
// 004ddee4  57                   push edi
// 004ddee5  8d442418             lea eax, [esp + 0x18]
// 004ddee9  50                   push eax
// 004ddeea  8bce                 mov ecx, esi
// 004ddeec  e8dff0ffff           call 0x4dcfd0
// 004ddef1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ddef5  ebc9                 jmp 0x4ddec0
// 004ddef7  8b36                 mov esi, dword ptr [esi]
// 004ddef9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ddefd  5f                   pop edi
// 004ddefe  8930                 mov dword ptr [eax], esi
// 004ddf00  5e                   pop esi
// 004ddf01  5d                   pop ebp
// 004ddf02  895804               mov dword ptr [eax + 4], ebx
// 004ddf05  5b                   pop ebx
// 004ddf06  83c408               add esp, 8
// 004ddf09  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
