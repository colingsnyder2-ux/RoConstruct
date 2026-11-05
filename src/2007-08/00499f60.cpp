// from server: 100% by auto
// roc 2007-08 00499f60  unit: RBX::Network::Client  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00499f60
//
// 00499f60  8b542404             mov edx, dword ptr [esp + 4]
// 00499f64  83ec08               sub esp, 8
// 00499f67  53                   push ebx
// 00499f68  8bd9                 mov ebx, ecx
// 00499f6a  8b4308               mov eax, dword ptr [ebx + 8]
// 00499f6d  b9ffffff0f           mov ecx, 0xfffffff
// 00499f72  2bc8                 sub ecx, eax
// 00499f74  3bca                 cmp ecx, edx
// 00499f76  7305                 jae 0x499f7d
// 00499f78  e8b3b10000           call 0x4a5130
// 00499f7d  8bc8                 mov ecx, eax
// 00499f7f  d1e9                 shr ecx, 1
// 00499f81  83f908               cmp ecx, 8
// 00499f84  7305                 jae 0x499f8b
// 00499f86  b908000000           mov ecx, 8
// 00499f8b  3bd1                 cmp edx, ecx
// 00499f8d  55                   push ebp
// 00499f8e  56                   push esi
// 00499f8f  57                   push edi
// 00499f90  7311                 jae 0x499fa3
// 00499f92  beffffff0f           mov esi, 0xfffffff
// 00499f97  2bf1                 sub esi, ecx
// 00499f99  3bc6                 cmp eax, esi
// 00499f9b  7706                 ja 0x499fa3
// 00499f9d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00499fa1  8bd1                 mov edx, ecx
// 00499fa3  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00499fa6  03c2                 add eax, edx
// 00499fa8  6a00                 push 0
// 00499faa  50                   push eax
// 00499fab  c1ed02               shr ebp, 2
// 00499fae  e8ad5d1100           call 0x5afd60
// 00499fb3  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00499fb6  89442418             mov dword ptr [esp + 0x18], eax
// 00499fba  8d34ad00000000       lea esi, [ebp*4]
// 00499fc1  8d3c06               lea edi, [esi + eax]
// 00499fc4  8b4308               mov eax, dword ptr [ebx + 8]
// 00499fc7  03c0                 add eax, eax
// 00499fc9  03c0                 add eax, eax
// 00499fcb  8d140e               lea edx, [esi + ecx]
// 00499fce  2bc2                 sub eax, edx
// 00499fd0  03c1                 add eax, ecx
// 00499fd2  83c408               add esp, 8
// 00499fd5  c1f802               sar eax, 2
// 00499fd8  8d048500000000       lea eax, [eax*4]
// 00499fdf  8d0c38               lea ecx, [eax + edi]
// 00499fe2  894c2414             mov dword ptr [esp + 0x14], ecx
// 00499fe6  7415                 je 0x499ffd
// 00499fe8  50                   push eax
// 00499fe9  52                   push edx
// 00499fea  50                   push eax
// 00499feb  57                   push edi
// 00499fec  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 00499ff2  ffd7                 call edi
// 00499ff4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00499ff8  83c410               add esp, 0x10
// 00499ffb  eb06                 jmp 0x49a003
// 00499ffd  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0049a003  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049a007  3be8                 cmp ebp, eax
// 0049a009  7735                 ja 0x49a040
// 0049a00b  8b4304               mov eax, dword ptr [ebx + 4]
// 0049a00e  c1fe02               sar esi, 2
// 0049a011  8d14b500000000       lea edx, [esi*4]
// 0049a018  8d340a               lea esi, [edx + ecx]
// 0049a01b  7409                 je 0x49a026
// 0049a01d  52                   push edx
// 0049a01e  50                   push eax
// 0049a01f  52                   push edx
// 0049a020  51                   push ecx
// 0049a021  ffd7                 call edi
// 0049a023  83c410               add esp, 0x10
// 0049a026  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049a02a  2bcd                 sub ecx, ebp
// 0049a02c  7406                 je 0x49a034
// 0049a02e  33c0                 xor eax, eax
// 0049a030  8bfe                 mov edi, esi
// 0049a032  f3ab                 rep stosd dword ptr es:[edi], eax
// 0049a034  85ed                 test ebp, ebp
// 0049a036  765a                 jbe 0x49a092
// 0049a038  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0049a03c  8bcd                 mov ecx, ebp
// 0049a03e  eb4e                 jmp 0x49a08e
// 0049a040  8b5304               mov edx, dword ptr [ebx + 4]
// 0049a043  8d2c8500000000       lea ebp, [eax*4]
// 0049a04a  8bc5                 mov eax, ebp
// 0049a04c  c1f802               sar eax, 2
// 0049a04f  740d                 je 0x49a05e
// 0049a051  03c0                 add eax, eax
// 0049a053  03c0                 add eax, eax
// 0049a055  50                   push eax
// 0049a056  52                   push edx
// 0049a057  50                   push eax
// 0049a058  51                   push ecx
// 0049a059  ffd7                 call edi
// 0049a05b  83c410               add esp, 0x10
// 0049a05e  8b4304               mov eax, dword ptr [ebx + 4]
// 0049a061  8b542410             mov edx, dword ptr [esp + 0x10]
// 0049a065  8d0c28               lea ecx, [eax + ebp]
// 0049a068  2bf1                 sub esi, ecx
// 0049a06a  03f0                 add esi, eax
// 0049a06c  c1fe02               sar esi, 2
// 0049a06f  8d04b500000000       lea eax, [esi*4]
// 0049a076  8d3410               lea esi, [eax + edx]
// 0049a079  7409                 je 0x49a084
// 0049a07b  50                   push eax
// 0049a07c  51                   push ecx
// 0049a07d  50                   push eax
// 0049a07e  52                   push edx
// 0049a07f  ffd7                 call edi
// 0049a081  83c410               add esp, 0x10
// 0049a084  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049a088  85c9                 test ecx, ecx
// 0049a08a  7606                 jbe 0x49a092
// 0049a08c  8bfe                 mov edi, esi
// 0049a08e  33c0                 xor eax, eax
// 0049a090  f3ab                 rep stosd dword ptr es:[edi], eax
// 0049a092  8b4304               mov eax, dword ptr [ebx + 4]
// 0049a095  85c0                 test eax, eax
// 0049a097  5f                   pop edi
// 0049a098  5e                   pop esi
// 0049a099  5d                   pop ebp
// 0049a09a  7409                 je 0x49a0a5
// 0049a09c  50                   push eax
// 0049a09d  e8c05b1900           call 0x62fc62
// 0049a0a2  83c404               add esp, 4
// 0049a0a5  8b542404             mov edx, dword ptr [esp + 4]
// 0049a0a9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0049a0ad  014308               add dword ptr [ebx + 8], eax
// 0049a0b0  895304               mov dword ptr [ebx + 4], edx
// 0049a0b3  5b                   pop ebx
// 0049a0b4  83c408               add esp, 8
// 0049a0b7  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
