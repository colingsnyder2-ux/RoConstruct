// from server: 100% by auto
// roc 2009-12 0057d350  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d350
//
// 0057d350  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057d354  8b5004               mov edx, dword ptr [eax + 4]
// 0057d357  53                   push ebx
// 0057d358  56                   push esi
// 0057d359  57                   push edi
// 0057d35a  8bd9                 mov ebx, ecx
// 0057d35c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057d360  8d7804               lea edi, [eax + 4]
// 0057d363  51                   push ecx
// 0057d364  52                   push edx
// 0057d365  50                   push eax
// 0057d366  8bcb                 mov ecx, ebx
// 0057d368  e8c3f0ffff           call 0x57c430
// 0057d36d  6a01                 push 1
// 0057d36f  8bcb                 mov ecx, ebx
// 0057d371  8bf0                 mov esi, eax
// 0057d373  e8d8e21000           call 0x68b650
// 0057d378  8937                 mov dword ptr [edi], esi
// 0057d37a  8b4604               mov eax, dword ptr [esi + 4]
// 0057d37d  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0057d383  8930                 mov dword ptr [eax], esi
// 0057d385  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057d389  85c0                 test eax, eax
// 0057d38b  7506                 jne 0x57d393
// 0057d38d  ffd7                 call edi
// 0057d38f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0057d393  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057d397  8b4904               mov ecx, dword ptr [ecx + 4]
// 0057d39a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0057d39e  85c0                 test eax, eax
// 0057d3a0  7404                 je 0x57d3a6
// 0057d3a2  8b00                 mov eax, dword ptr [eax]
// 0057d3a4  eb02                 jmp 0x57d3a8
// 0057d3a6  33c0                 xor eax, eax
// 0057d3a8  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0057d3ab  7506                 jne 0x57d3b3
// 0057d3ad  ffd7                 call edi
// 0057d3af  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057d3b3  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057d3b7  c70600000000         mov dword ptr [esi], 0
// 0057d3bd  894e04               mov dword ptr [esi + 4], ecx
// 0057d3c0  85db                 test ebx, ebx
// 0057d3c2  7502                 jne 0x57d3c6
// 0057d3c4  ffd7                 call edi
// 0057d3c6  8b13                 mov edx, dword ptr [ebx]
// 0057d3c8  5f                   pop edi
// 0057d3c9  8916                 mov dword ptr [esi], edx
// 0057d3cb  8bc6                 mov eax, esi
// 0057d3cd  5e                   pop esi
// 0057d3ce  5b                   pop ebx
// 0057d3cf  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
