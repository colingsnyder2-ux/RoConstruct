// from server: 100% by auto
// roc 2009-06 006e4490  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4490
//
// 006e4490  83ec08               sub esp, 8
// 006e4493  53                   push ebx
// 006e4494  55                   push ebp
// 006e4495  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006e449b  56                   push esi
// 006e449c  8bf1                 mov esi, ecx
// 006e449e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e44a1  8b18                 mov ebx, dword ptr [eax]
// 006e44a3  8b06                 mov eax, dword ptr [esi]
// 006e44a5  57                   push edi
// 006e44a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e44aa  85ff                 test edi, edi
// 006e44ac  7404                 je 0x6e44b2
// 006e44ae  3bf8                 cmp edi, eax
// 006e44b0  7406                 je 0x6e44b8
// 006e44b2  ffd5                 call ebp
// 006e44b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e44b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006e44bc  7562                 jne 0x6e4520
// 006e44be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e44c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006e44c5  8b06                 mov eax, dword ptr [esi]
// 006e44c7  85c9                 test ecx, ecx
// 006e44c9  7404                 je 0x6e44cf
// 006e44cb  3bc8                 cmp ecx, eax
// 006e44cd  7406                 je 0x6e44d5
// 006e44cf  ffd5                 call ebp
// 006e44d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e44d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006e44d9  7545                 jne 0x6e4520
// 006e44db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e44de  8b5104               mov edx, dword ptr [ecx + 4]
// 006e44e1  52                   push edx
// 006e44e2  8bce                 mov ecx, esi
// 006e44e4  e8a7f1ffff           call 0x6e3690
// 006e44e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e44ec  894004               mov dword ptr [eax + 4], eax
// 006e44ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e44f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e44f9  8900                 mov dword ptr [eax], eax
// 006e44fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e44fe  894008               mov dword ptr [eax + 8], eax
// 006e4501  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e4504  8b16                 mov edx, dword ptr [esi]
// 006e4506  8b08                 mov ecx, dword ptr [eax]
// 006e4508  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e450c  5f                   pop edi
// 006e450d  5e                   pop esi
// 006e450e  5d                   pop ebp
// 006e450f  894804               mov dword ptr [eax + 4], ecx
// 006e4512  8910                 mov dword ptr [eax], edx
// 006e4514  5b                   pop ebx
// 006e4515  83c408               add esp, 8
// 006e4518  c21400               ret 0x14
// 006e451b  eb03                 jmp 0x6e4520
// 006e451d  8d4900               lea ecx, [ecx]
// 006e4520  85ff                 test edi, edi
// 006e4522  7406                 je 0x6e452a
// 006e4524  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006e4528  7406                 je 0x6e4530
// 006e452a  ffd5                 call ebp
// 006e452c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e4530  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006e4534  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006e4538  741d                 je 0x6e4557
// 006e453a  8d4c2420             lea ecx, [esp + 0x20]
// 006e453e  e82d33e3ff           call 0x517870
// 006e4543  53                   push ebx
// 006e4544  57                   push edi
// 006e4545  8d442418             lea eax, [esp + 0x18]
// 006e4549  50                   push eax
// 006e454a  8bce                 mov ecx, esi
// 006e454c  e8dfecffff           call 0x6e3230
// 006e4551  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006e4555  ebc9                 jmp 0x6e4520
// 006e4557  8b36                 mov esi, dword ptr [esi]
// 006e4559  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e455d  5f                   pop edi
// 006e455e  8930                 mov dword ptr [eax], esi
// 006e4560  5e                   pop esi
// 006e4561  5d                   pop ebp
// 006e4562  895804               mov dword ptr [eax + 4], ebx
// 006e4565  5b                   pop ebx
// 006e4566  83c408               add esp, 8
// 006e4569  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
