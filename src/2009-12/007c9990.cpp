// from server: 100% by auto
// roc 2009-12 007c9990  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c9990
//
// 007c9990  83ec08               sub esp, 8
// 007c9993  53                   push ebx
// 007c9994  55                   push ebp
// 007c9995  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007c999b  56                   push esi
// 007c999c  8bf1                 mov esi, ecx
// 007c999e  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c99a1  8b18                 mov ebx, dword ptr [eax]
// 007c99a3  8b06                 mov eax, dword ptr [esi]
// 007c99a5  57                   push edi
// 007c99a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c99aa  85ff                 test edi, edi
// 007c99ac  7404                 je 0x7c99b2
// 007c99ae  3bf8                 cmp edi, eax
// 007c99b0  7406                 je 0x7c99b8
// 007c99b2  ffd5                 call ebp
// 007c99b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c99b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007c99bc  7562                 jne 0x7c9a20
// 007c99be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c99c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007c99c5  8b06                 mov eax, dword ptr [esi]
// 007c99c7  85c9                 test ecx, ecx
// 007c99c9  7404                 je 0x7c99cf
// 007c99cb  3bc8                 cmp ecx, eax
// 007c99cd  7406                 je 0x7c99d5
// 007c99cf  ffd5                 call ebp
// 007c99d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c99d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007c99d9  7545                 jne 0x7c9a20
// 007c99db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c99de  8b5104               mov edx, dword ptr [ecx + 4]
// 007c99e1  52                   push edx
// 007c99e2  8bce                 mov ecx, esi
// 007c99e4  e847f5ffff           call 0x7c8f30
// 007c99e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c99ec  894004               mov dword ptr [eax + 4], eax
// 007c99ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c99f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c99f9  8900                 mov dword ptr [eax], eax
// 007c99fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c99fe  894008               mov dword ptr [eax + 8], eax
// 007c9a01  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c9a04  8b16                 mov edx, dword ptr [esi]
// 007c9a06  8b08                 mov ecx, dword ptr [eax]
// 007c9a08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c9a0c  5f                   pop edi
// 007c9a0d  5e                   pop esi
// 007c9a0e  5d                   pop ebp
// 007c9a0f  894804               mov dword ptr [eax + 4], ecx
// 007c9a12  8910                 mov dword ptr [eax], edx
// 007c9a14  5b                   pop ebx
// 007c9a15  83c408               add esp, 8
// 007c9a18  c21400               ret 0x14
// 007c9a1b  eb03                 jmp 0x7c9a20
// 007c9a1d  8d4900               lea ecx, [ecx]
// 007c9a20  85ff                 test edi, edi
// 007c9a22  7406                 je 0x7c9a2a
// 007c9a24  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007c9a28  7406                 je 0x7c9a30
// 007c9a2a  ffd5                 call ebp
// 007c9a2c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9a30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007c9a34  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007c9a38  741d                 je 0x7c9a57
// 007c9a3a  8d4c2420             lea ecx, [esp + 0x20]
// 007c9a3e  e82dccffff           call 0x7c6670
// 007c9a43  53                   push ebx
// 007c9a44  57                   push edi
// 007c9a45  8d442418             lea eax, [esp + 0x18]
// 007c9a49  50                   push eax
// 007c9a4a  8bce                 mov ecx, esi
// 007c9a4c  e8ffeeffff           call 0x7c8950
// 007c9a51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9a55  ebc9                 jmp 0x7c9a20
// 007c9a57  8b36                 mov esi, dword ptr [esi]
// 007c9a59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c9a5d  5f                   pop edi
// 007c9a5e  8930                 mov dword ptr [eax], esi
// 007c9a60  5e                   pop esi
// 007c9a61  5d                   pop ebp
// 007c9a62  895804               mov dword ptr [eax + 4], ebx
// 007c9a65  5b                   pop ebx
// 007c9a66  83c408               add esp, 8
// 007c9a69  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
