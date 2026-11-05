// from server: 100% by auto
// roc 2010-06 005aca00  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005aca00
//
// 005aca00  83ec08               sub esp, 8
// 005aca03  53                   push ebx
// 005aca04  55                   push ebp
// 005aca05  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 005aca0b  56                   push esi
// 005aca0c  8bf1                 mov esi, ecx
// 005aca0e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005aca11  8b18                 mov ebx, dword ptr [eax]
// 005aca13  8b06                 mov eax, dword ptr [esi]
// 005aca15  57                   push edi
// 005aca16  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005aca1a  85ff                 test edi, edi
// 005aca1c  7404                 je 0x5aca22
// 005aca1e  3bf8                 cmp edi, eax
// 005aca20  7406                 je 0x5aca28
// 005aca22  ffd5                 call ebp
// 005aca24  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005aca28  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005aca2c  7562                 jne 0x5aca90
// 005aca2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005aca32  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005aca35  8b06                 mov eax, dword ptr [esi]
// 005aca37  85c9                 test ecx, ecx
// 005aca39  7404                 je 0x5aca3f
// 005aca3b  3bc8                 cmp ecx, eax
// 005aca3d  7406                 je 0x5aca45
// 005aca3f  ffd5                 call ebp
// 005aca41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005aca45  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005aca49  7545                 jne 0x5aca90
// 005aca4b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005aca4e  8b5104               mov edx, dword ptr [ecx + 4]
// 005aca51  52                   push edx
// 005aca52  8bce                 mov ecx, esi
// 005aca54  e837bcebff           call 0x468690
// 005aca59  8b4618               mov eax, dword ptr [esi + 0x18]
// 005aca5c  894004               mov dword ptr [eax + 4], eax
// 005aca5f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005aca62  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005aca69  8900                 mov dword ptr [eax], eax
// 005aca6b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005aca6e  894008               mov dword ptr [eax + 8], eax
// 005aca71  8b4618               mov eax, dword ptr [esi + 0x18]
// 005aca74  8b16                 mov edx, dword ptr [esi]
// 005aca76  8b08                 mov ecx, dword ptr [eax]
// 005aca78  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005aca7c  5f                   pop edi
// 005aca7d  5e                   pop esi
// 005aca7e  5d                   pop ebp
// 005aca7f  894804               mov dword ptr [eax + 4], ecx
// 005aca82  8910                 mov dword ptr [eax], edx
// 005aca84  5b                   pop ebx
// 005aca85  83c408               add esp, 8
// 005aca88  c21400               ret 0x14
// 005aca8b  eb03                 jmp 0x5aca90
// 005aca8d  8d4900               lea ecx, [ecx]
// 005aca90  85ff                 test edi, edi
// 005aca92  7406                 je 0x5aca9a
// 005aca94  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005aca98  7406                 je 0x5acaa0
// 005aca9a  ffd5                 call ebp
// 005aca9c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005acaa0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005acaa4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005acaa8  741d                 je 0x5acac7
// 005acaaa  8d4c2420             lea ecx, [esp + 0x20]
// 005acaae  e82daf1300           call 0x6e79e0
// 005acab3  53                   push ebx
// 005acab4  57                   push edi
// 005acab5  8d442418             lea eax, [esp + 0x18]
// 005acab9  50                   push eax
// 005acaba  8bce                 mov ecx, esi
// 005acabc  e86ffcffff           call 0x5ac730
// 005acac1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005acac5  ebc9                 jmp 0x5aca90
// 005acac7  8b36                 mov esi, dword ptr [esi]
// 005acac9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005acacd  5f                   pop edi
// 005acace  8930                 mov dword ptr [eax], esi
// 005acad0  5e                   pop esi
// 005acad1  5d                   pop ebp
// 005acad2  895804               mov dword ptr [eax + 4], ebx
// 005acad5  5b                   pop ebx
// 005acad6  83c408               add esp, 8
// 005acad9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
