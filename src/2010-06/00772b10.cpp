// from server: 100% by auto
// roc 2010-06 00772b10  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00772b10
//
// 00772b10  83ec08               sub esp, 8
// 00772b13  53                   push ebx
// 00772b14  55                   push ebp
// 00772b15  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00772b1b  56                   push esi
// 00772b1c  8bf1                 mov esi, ecx
// 00772b1e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772b21  8b18                 mov ebx, dword ptr [eax]
// 00772b23  8b06                 mov eax, dword ptr [esi]
// 00772b25  57                   push edi
// 00772b26  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772b2a  85ff                 test edi, edi
// 00772b2c  7404                 je 0x772b32
// 00772b2e  3bf8                 cmp edi, eax
// 00772b30  7406                 je 0x772b38
// 00772b32  ffd5                 call ebp
// 00772b34  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772b38  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00772b3c  7562                 jne 0x772ba0
// 00772b3e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00772b42  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00772b45  8b06                 mov eax, dword ptr [esi]
// 00772b47  85c9                 test ecx, ecx
// 00772b49  7404                 je 0x772b4f
// 00772b4b  3bc8                 cmp ecx, eax
// 00772b4d  7406                 je 0x772b55
// 00772b4f  ffd5                 call ebp
// 00772b51  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772b55  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00772b59  7545                 jne 0x772ba0
// 00772b5b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00772b5e  8b5104               mov edx, dword ptr [ecx + 4]
// 00772b61  52                   push edx
// 00772b62  8bce                 mov ecx, esi
// 00772b64  e8f7f4ffff           call 0x772060
// 00772b69  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772b6c  894004               mov dword ptr [eax + 4], eax
// 00772b6f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772b72  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00772b79  8900                 mov dword ptr [eax], eax
// 00772b7b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772b7e  894008               mov dword ptr [eax + 8], eax
// 00772b81  8b4618               mov eax, dword ptr [esi + 0x18]
// 00772b84  8b16                 mov edx, dword ptr [esi]
// 00772b86  8b08                 mov ecx, dword ptr [eax]
// 00772b88  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00772b8c  5f                   pop edi
// 00772b8d  5e                   pop esi
// 00772b8e  5d                   pop ebp
// 00772b8f  894804               mov dword ptr [eax + 4], ecx
// 00772b92  8910                 mov dword ptr [eax], edx
// 00772b94  5b                   pop ebx
// 00772b95  83c408               add esp, 8
// 00772b98  c21400               ret 0x14
// 00772b9b  eb03                 jmp 0x772ba0
// 00772b9d  8d4900               lea ecx, [ecx]
// 00772ba0  85ff                 test edi, edi
// 00772ba2  7406                 je 0x772baa
// 00772ba4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00772ba8  7406                 je 0x772bb0
// 00772baa  ffd5                 call ebp
// 00772bac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772bb0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00772bb4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00772bb8  741d                 je 0x772bd7
// 00772bba  8d4c2420             lea ecx, [esp + 0x20]
// 00772bbe  e8edc8eeff           call 0x65f4b0
// 00772bc3  53                   push ebx
// 00772bc4  57                   push edi
// 00772bc5  8d442418             lea eax, [esp + 0x18]
// 00772bc9  50                   push eax
// 00772bca  8bce                 mov ecx, esi
// 00772bcc  e81ff1ffff           call 0x771cf0
// 00772bd1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772bd5  ebc9                 jmp 0x772ba0
// 00772bd7  8b36                 mov esi, dword ptr [esi]
// 00772bd9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00772bdd  5f                   pop edi
// 00772bde  8930                 mov dword ptr [eax], esi
// 00772be0  5e                   pop esi
// 00772be1  5d                   pop ebp
// 00772be2  895804               mov dword ptr [eax + 4], ebx
// 00772be5  5b                   pop ebx
// 00772be6  83c408               add esp, 8
// 00772be9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
