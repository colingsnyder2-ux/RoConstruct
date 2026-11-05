// from server: 100% by auto
// roc 2010-06 00531c90  unit: RBX::G3DPart  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00531c90
//
// 00531c90  83ec08               sub esp, 8
// 00531c93  53                   push ebx
// 00531c94  55                   push ebp
// 00531c95  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00531c9b  56                   push esi
// 00531c9c  8bf1                 mov esi, ecx
// 00531c9e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00531ca1  8b18                 mov ebx, dword ptr [eax]
// 00531ca3  8b06                 mov eax, dword ptr [esi]
// 00531ca5  57                   push edi
// 00531ca6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00531caa  85ff                 test edi, edi
// 00531cac  7404                 je 0x531cb2
// 00531cae  3bf8                 cmp edi, eax
// 00531cb0  7406                 je 0x531cb8
// 00531cb2  ffd5                 call ebp
// 00531cb4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00531cb8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00531cbc  7562                 jne 0x531d20
// 00531cbe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00531cc2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00531cc5  8b06                 mov eax, dword ptr [esi]
// 00531cc7  85c9                 test ecx, ecx
// 00531cc9  7404                 je 0x531ccf
// 00531ccb  3bc8                 cmp ecx, eax
// 00531ccd  7406                 je 0x531cd5
// 00531ccf  ffd5                 call ebp
// 00531cd1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00531cd5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00531cd9  7545                 jne 0x531d20
// 00531cdb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00531cde  8b5104               mov edx, dword ptr [ecx + 4]
// 00531ce1  52                   push edx
// 00531ce2  8bce                 mov ecx, esi
// 00531ce4  e867e8ffff           call 0x530550
// 00531ce9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00531cec  894004               mov dword ptr [eax + 4], eax
// 00531cef  8b4618               mov eax, dword ptr [esi + 0x18]
// 00531cf2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00531cf9  8900                 mov dword ptr [eax], eax
// 00531cfb  8b4618               mov eax, dword ptr [esi + 0x18]
// 00531cfe  894008               mov dword ptr [eax + 8], eax
// 00531d01  8b4618               mov eax, dword ptr [esi + 0x18]
// 00531d04  8b16                 mov edx, dword ptr [esi]
// 00531d06  8b08                 mov ecx, dword ptr [eax]
// 00531d08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00531d0c  5f                   pop edi
// 00531d0d  5e                   pop esi
// 00531d0e  5d                   pop ebp
// 00531d0f  894804               mov dword ptr [eax + 4], ecx
// 00531d12  8910                 mov dword ptr [eax], edx
// 00531d14  5b                   pop ebx
// 00531d15  83c408               add esp, 8
// 00531d18  c21400               ret 0x14
// 00531d1b  eb03                 jmp 0x531d20
// 00531d1d  8d4900               lea ecx, [ecx]
// 00531d20  85ff                 test edi, edi
// 00531d22  7406                 je 0x531d2a
// 00531d24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00531d28  7406                 je 0x531d30
// 00531d2a  ffd5                 call ebp
// 00531d2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00531d30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00531d34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00531d38  741d                 je 0x531d57
// 00531d3a  8d4c2420             lea ecx, [esp + 0x20]
// 00531d3e  e86dd82300           call 0x76f5b0
// 00531d43  53                   push ebx
// 00531d44  57                   push edi
// 00531d45  8d442418             lea eax, [esp + 0x18]
// 00531d49  50                   push eax
// 00531d4a  8bce                 mov ecx, esi
// 00531d4c  e8dfe4ffff           call 0x530230
// 00531d51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00531d55  ebc9                 jmp 0x531d20
// 00531d57  8b36                 mov esi, dword ptr [esi]
// 00531d59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00531d5d  5f                   pop edi
// 00531d5e  8930                 mov dword ptr [eax], esi
// 00531d60  5e                   pop esi
// 00531d61  5d                   pop ebp
// 00531d62  895804               mov dword ptr [eax + 4], ebx
// 00531d65  5b                   pop ebx
// 00531d66  83c408               add esp, 8
// 00531d69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
