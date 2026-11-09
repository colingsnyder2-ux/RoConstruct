// from server: 100% by auto
// roc 2009-12 005d2290  unit: RBX::VRenderSurfaceTypes::?$Table  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d2290
//
// 005d2290  83ec08               sub esp, 8
// 005d2293  53                   push ebx
// 005d2294  55                   push ebp
// 005d2295  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 005d229b  56                   push esi
// 005d229c  8bf1                 mov esi, ecx
// 005d229e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d22a1  8b18                 mov ebx, dword ptr [eax]
// 005d22a3  8b06                 mov eax, dword ptr [esi]
// 005d22a5  57                   push edi
// 005d22a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d22aa  85ff                 test edi, edi
// 005d22ac  7404                 je 0x5d22b2
// 005d22ae  3bf8                 cmp edi, eax
// 005d22b0  7406                 je 0x5d22b8
// 005d22b2  ffd5                 call ebp
// 005d22b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d22b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005d22bc  7562                 jne 0x5d2320
// 005d22be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d22c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005d22c5  8b06                 mov eax, dword ptr [esi]
// 005d22c7  85c9                 test ecx, ecx
// 005d22c9  7404                 je 0x5d22cf
// 005d22cb  3bc8                 cmp ecx, eax
// 005d22cd  7406                 je 0x5d22d5
// 005d22cf  ffd5                 call ebp
// 005d22d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d22d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005d22d9  7545                 jne 0x5d2320
// 005d22db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d22de  8b5104               mov edx, dword ptr [ecx + 4]
// 005d22e1  52                   push edx
// 005d22e2  8bce                 mov ecx, esi
// 005d22e4  e8d7e6ffff           call 0x5d09c0
// 005d22e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d22ec  894004               mov dword ptr [eax + 4], eax
// 005d22ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d22f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d22f9  8900                 mov dword ptr [eax], eax
// 005d22fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d22fe  894008               mov dword ptr [eax + 8], eax
// 005d2301  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d2304  8b16                 mov edx, dword ptr [esi]
// 005d2306  8b08                 mov ecx, dword ptr [eax]
// 005d2308  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d230c  5f                   pop edi
// 005d230d  5e                   pop esi
// 005d230e  5d                   pop ebp
// 005d230f  894804               mov dword ptr [eax + 4], ecx
// 005d2312  8910                 mov dword ptr [eax], edx
// 005d2314  5b                   pop ebx
// 005d2315  83c408               add esp, 8
// 005d2318  c21400               ret 0x14
// 005d231b  eb03                 jmp 0x5d2320
// 005d231d  8d4900               lea ecx, [ecx]
// 005d2320  85ff                 test edi, edi
// 005d2322  7406                 je 0x5d232a
// 005d2324  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005d2328  7406                 je 0x5d2330
// 005d232a  ffd5                 call ebp
// 005d232c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d2330  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005d2334  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005d2338  741d                 je 0x5d2357
// 005d233a  8d4c2420             lea ecx, [esp + 0x20]
// 005d233e  e8bdcdebff           call 0x48f100
// 005d2343  53                   push ebx
// 005d2344  57                   push edi
// 005d2345  8d442418             lea eax, [esp + 0x18]
// 005d2349  50                   push eax
// 005d234a  8bce                 mov ecx, esi
// 005d234c  e8bfe2ffff           call 0x5d0610
// 005d2351  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d2355  ebc9                 jmp 0x5d2320
// 005d2357  8b36                 mov esi, dword ptr [esi]
// 005d2359  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d235d  5f                   pop edi
// 005d235e  8930                 mov dword ptr [eax], esi
// 005d2360  5e                   pop esi
// 005d2361  5d                   pop ebp
// 005d2362  895804               mov dword ptr [eax + 4], ebx
// 005d2365  5b                   pop ebx
// 005d2366  83c408               add esp, 8
// 005d2369  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
