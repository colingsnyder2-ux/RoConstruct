// from server: 100% by auto
// roc 2009-06 0062cee0  unit: RBX::ArrowTool  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062cee0
//
// 0062cee0  83ec08               sub esp, 8
// 0062cee3  53                   push ebx
// 0062cee4  55                   push ebp
// 0062cee5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0062ceeb  56                   push esi
// 0062ceec  8bf1                 mov esi, ecx
// 0062ceee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cef1  8b18                 mov ebx, dword ptr [eax]
// 0062cef3  8b06                 mov eax, dword ptr [esi]
// 0062cef5  57                   push edi
// 0062cef6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062cefa  85ff                 test edi, edi
// 0062cefc  7404                 je 0x62cf02
// 0062cefe  3bf8                 cmp edi, eax
// 0062cf00  7406                 je 0x62cf08
// 0062cf02  ffd5                 call ebp
// 0062cf04  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062cf08  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0062cf0c  7562                 jne 0x62cf70
// 0062cf0e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0062cf12  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0062cf15  8b06                 mov eax, dword ptr [esi]
// 0062cf17  85c9                 test ecx, ecx
// 0062cf19  7404                 je 0x62cf1f
// 0062cf1b  3bc8                 cmp ecx, eax
// 0062cf1d  7406                 je 0x62cf25
// 0062cf1f  ffd5                 call ebp
// 0062cf21  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062cf25  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0062cf29  7545                 jne 0x62cf70
// 0062cf2b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0062cf2e  8b5104               mov edx, dword ptr [ecx + 4]
// 0062cf31  52                   push edx
// 0062cf32  8bce                 mov ecx, esi
// 0062cf34  e807ecffff           call 0x62bb40
// 0062cf39  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cf3c  894004               mov dword ptr [eax + 4], eax
// 0062cf3f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cf42  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0062cf49  8900                 mov dword ptr [eax], eax
// 0062cf4b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cf4e  894008               mov dword ptr [eax + 8], eax
// 0062cf51  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062cf54  8b16                 mov edx, dword ptr [esi]
// 0062cf56  8b08                 mov ecx, dword ptr [eax]
// 0062cf58  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062cf5c  5f                   pop edi
// 0062cf5d  5e                   pop esi
// 0062cf5e  5d                   pop ebp
// 0062cf5f  894804               mov dword ptr [eax + 4], ecx
// 0062cf62  8910                 mov dword ptr [eax], edx
// 0062cf64  5b                   pop ebx
// 0062cf65  83c408               add esp, 8
// 0062cf68  c21400               ret 0x14
// 0062cf6b  eb03                 jmp 0x62cf70
// 0062cf6d  8d4900               lea ecx, [ecx]
// 0062cf70  85ff                 test edi, edi
// 0062cf72  7406                 je 0x62cf7a
// 0062cf74  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0062cf78  7406                 je 0x62cf80
// 0062cf7a  ffd5                 call ebp
// 0062cf7c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062cf80  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0062cf84  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0062cf88  741d                 je 0x62cfa7
// 0062cf8a  8d4c2420             lea ecx, [esp + 0x20]
// 0062cf8e  e8bd980800           call 0x6b6850
// 0062cf93  53                   push ebx
// 0062cf94  57                   push edi
// 0062cf95  8d442418             lea eax, [esp + 0x18]
// 0062cf99  50                   push eax
// 0062cf9a  8bce                 mov ecx, esi
// 0062cf9c  e86ffcffff           call 0x62cc10
// 0062cfa1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062cfa5  ebc9                 jmp 0x62cf70
// 0062cfa7  8b36                 mov esi, dword ptr [esi]
// 0062cfa9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062cfad  5f                   pop edi
// 0062cfae  8930                 mov dword ptr [eax], esi
// 0062cfb0  5e                   pop esi
// 0062cfb1  5d                   pop ebp
// 0062cfb2  895804               mov dword ptr [eax + 4], ebx
// 0062cfb5  5b                   pop ebx
// 0062cfb6  83c408               add esp, 8
// 0062cfb9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
