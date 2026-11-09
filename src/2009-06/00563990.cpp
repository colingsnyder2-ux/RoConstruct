// from server: 100% by auto
// roc 2009-06 00563990  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00563990
//
// 00563990  83ec08               sub esp, 8
// 00563993  53                   push ebx
// 00563994  55                   push ebp
// 00563995  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0056399b  56                   push esi
// 0056399c  8bf1                 mov esi, ecx
// 0056399e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005639a1  8b18                 mov ebx, dword ptr [eax]
// 005639a3  8b06                 mov eax, dword ptr [esi]
// 005639a5  57                   push edi
// 005639a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005639aa  85ff                 test edi, edi
// 005639ac  7404                 je 0x5639b2
// 005639ae  3bf8                 cmp edi, eax
// 005639b0  7406                 je 0x5639b8
// 005639b2  ffd5                 call ebp
// 005639b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005639b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005639bc  7562                 jne 0x563a20
// 005639be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005639c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005639c5  8b06                 mov eax, dword ptr [esi]
// 005639c7  85c9                 test ecx, ecx
// 005639c9  7404                 je 0x5639cf
// 005639cb  3bc8                 cmp ecx, eax
// 005639cd  7406                 je 0x5639d5
// 005639cf  ffd5                 call ebp
// 005639d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005639d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005639d9  7545                 jne 0x563a20
// 005639db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005639de  8b5104               mov edx, dword ptr [ecx + 4]
// 005639e1  52                   push edx
// 005639e2  8bce                 mov ecx, esi
// 005639e4  e827fbffff           call 0x563510
// 005639e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005639ec  894004               mov dword ptr [eax + 4], eax
// 005639ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 005639f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005639f9  8900                 mov dword ptr [eax], eax
// 005639fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005639fe  894008               mov dword ptr [eax + 8], eax
// 00563a01  8b4618               mov eax, dword ptr [esi + 0x18]
// 00563a04  8b16                 mov edx, dword ptr [esi]
// 00563a06  8b08                 mov ecx, dword ptr [eax]
// 00563a08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00563a0c  5f                   pop edi
// 00563a0d  5e                   pop esi
// 00563a0e  5d                   pop ebp
// 00563a0f  894804               mov dword ptr [eax + 4], ecx
// 00563a12  8910                 mov dword ptr [eax], edx
// 00563a14  5b                   pop ebx
// 00563a15  83c408               add esp, 8
// 00563a18  c21400               ret 0x14
// 00563a1b  eb03                 jmp 0x563a20
// 00563a1d  8d4900               lea ecx, [ecx]
// 00563a20  85ff                 test edi, edi
// 00563a22  7406                 je 0x563a2a
// 00563a24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00563a28  7406                 je 0x563a30
// 00563a2a  ffd5                 call ebp
// 00563a2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00563a30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00563a34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00563a38  741d                 je 0x563a57
// 00563a3a  8d4c2420             lea ecx, [esp + 0x20]
// 00563a3e  e8edf1ffff           call 0x562c30
// 00563a43  53                   push ebx
// 00563a44  57                   push edi
// 00563a45  8d442418             lea eax, [esp + 0x18]
// 00563a49  50                   push eax
// 00563a4a  8bce                 mov ecx, esi
// 00563a4c  e88ff5ffff           call 0x562fe0
// 00563a51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00563a55  ebc9                 jmp 0x563a20
// 00563a57  8b36                 mov esi, dword ptr [esi]
// 00563a59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00563a5d  5f                   pop edi
// 00563a5e  8930                 mov dword ptr [eax], esi
// 00563a60  5e                   pop esi
// 00563a61  5d                   pop ebp
// 00563a62  895804               mov dword ptr [eax + 4], ebx
// 00563a65  5b                   pop ebx
// 00563a66  83c408               add esp, 8
// 00563a69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
