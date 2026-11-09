// from server: 100% by auto
// roc 2010-06 0066ba90  unit: RBX::VTimerService::?$FactoryProduct  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066ba90
//
// 0066ba90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066ba94  8b5004               mov edx, dword ptr [eax + 4]
// 0066ba97  53                   push ebx
// 0066ba98  56                   push esi
// 0066ba99  57                   push edi
// 0066ba9a  8bd9                 mov ebx, ecx
// 0066ba9c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0066baa0  8d7804               lea edi, [eax + 4]
// 0066baa3  51                   push ecx
// 0066baa4  52                   push edx
// 0066baa5  50                   push eax
// 0066baa6  8bcb                 mov ecx, ebx
// 0066baa8  e853ffffff           call 0x66ba00
// 0066baad  6a01                 push 1
// 0066baaf  8bcb                 mov ecx, ebx
// 0066bab1  8bf0                 mov esi, eax
// 0066bab3  e8b8fdffff           call 0x66b870
// 0066bab8  8937                 mov dword ptr [edi], esi
// 0066baba  8b4604               mov eax, dword ptr [esi + 4]
// 0066babd  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0066bac3  8930                 mov dword ptr [eax], esi
// 0066bac5  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066bac9  85c0                 test eax, eax
// 0066bacb  7506                 jne 0x66bad3
// 0066bacd  ffd7                 call edi
// 0066bacf  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066bad3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0066bad7  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066bada  894c2418             mov dword ptr [esp + 0x18], ecx
// 0066bade  85c0                 test eax, eax
// 0066bae0  7404                 je 0x66bae6
// 0066bae2  8b00                 mov eax, dword ptr [eax]
// 0066bae4  eb02                 jmp 0x66bae8
// 0066bae6  33c0                 xor eax, eax
// 0066bae8  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0066baeb  7506                 jne 0x66baf3
// 0066baed  ffd7                 call edi
// 0066baef  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0066baf3  8b742410             mov esi, dword ptr [esp + 0x10]
// 0066baf7  c70600000000         mov dword ptr [esi], 0
// 0066bafd  894e04               mov dword ptr [esi + 4], ecx
// 0066bb00  85db                 test ebx, ebx
// 0066bb02  7502                 jne 0x66bb06
// 0066bb04  ffd7                 call edi
// 0066bb06  8b13                 mov edx, dword ptr [ebx]
// 0066bb08  5f                   pop edi
// 0066bb09  8916                 mov dword ptr [esi], edx
// 0066bb0b  8bc6                 mov eax, esi
// 0066bb0d  5e                   pop esi
// 0066bb0e  5b                   pop ebx
// 0066bb0f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
