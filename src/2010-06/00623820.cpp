// from server: 100% by auto
// roc 2010-06 00623820  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00623820
//
// 00623820  83ec08               sub esp, 8
// 00623823  53                   push ebx
// 00623824  55                   push ebp
// 00623825  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0062382b  56                   push esi
// 0062382c  8bf1                 mov esi, ecx
// 0062382e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00623831  8b18                 mov ebx, dword ptr [eax]
// 00623833  8b06                 mov eax, dword ptr [esi]
// 00623835  57                   push edi
// 00623836  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062383a  85ff                 test edi, edi
// 0062383c  7404                 je 0x623842
// 0062383e  3bf8                 cmp edi, eax
// 00623840  7406                 je 0x623848
// 00623842  ffd5                 call ebp
// 00623844  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00623848  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0062384c  7562                 jne 0x6238b0
// 0062384e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00623852  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00623855  8b06                 mov eax, dword ptr [esi]
// 00623857  85c9                 test ecx, ecx
// 00623859  7404                 je 0x62385f
// 0062385b  3bc8                 cmp ecx, eax
// 0062385d  7406                 je 0x623865
// 0062385f  ffd5                 call ebp
// 00623861  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00623865  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00623869  7545                 jne 0x6238b0
// 0062386b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0062386e  8b5104               mov edx, dword ptr [ecx + 4]
// 00623871  52                   push edx
// 00623872  8bce                 mov ecx, esi
// 00623874  e8e7f9ffff           call 0x623260
// 00623879  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062387c  894004               mov dword ptr [eax + 4], eax
// 0062387f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00623882  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00623889  8900                 mov dword ptr [eax], eax
// 0062388b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0062388e  894008               mov dword ptr [eax + 8], eax
// 00623891  8b4618               mov eax, dword ptr [esi + 0x18]
// 00623894  8b16                 mov edx, dword ptr [esi]
// 00623896  8b08                 mov ecx, dword ptr [eax]
// 00623898  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062389c  5f                   pop edi
// 0062389d  5e                   pop esi
// 0062389e  5d                   pop ebp
// 0062389f  894804               mov dword ptr [eax + 4], ecx
// 006238a2  8910                 mov dword ptr [eax], edx
// 006238a4  5b                   pop ebx
// 006238a5  83c408               add esp, 8
// 006238a8  c21400               ret 0x14
// 006238ab  eb03                 jmp 0x6238b0
// 006238ad  8d4900               lea ecx, [ecx]
// 006238b0  85ff                 test edi, edi
// 006238b2  7406                 je 0x6238ba
// 006238b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006238b8  7406                 je 0x6238c0
// 006238ba  ffd5                 call ebp
// 006238bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006238c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006238c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006238c8  741d                 je 0x6238e7
// 006238ca  8d4c2420             lea ecx, [esp + 0x20]
// 006238ce  e82d21ecff           call 0x4e5a00
// 006238d3  53                   push ebx
// 006238d4  57                   push edi
// 006238d5  8d442418             lea eax, [esp + 0x18]
// 006238d9  50                   push eax
// 006238da  8bce                 mov ecx, esi
// 006238dc  e89ff6ffff           call 0x622f80
// 006238e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006238e5  ebc9                 jmp 0x6238b0
// 006238e7  8b36                 mov esi, dword ptr [esi]
// 006238e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006238ed  5f                   pop edi
// 006238ee  8930                 mov dword ptr [eax], esi
// 006238f0  5e                   pop esi
// 006238f1  5d                   pop ebp
// 006238f2  895804               mov dword ptr [eax + 4], ebx
// 006238f5  5b                   pop ebx
// 006238f6  83c408               add esp, 8
// 006238f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
