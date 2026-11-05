// from server: 100% by auto
// roc 2010-06 0064cac0  unit: RBX::VWidget::?$NonFactoryProduct  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064cac0
//
// 0064cac0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064cac4  8b5004               mov edx, dword ptr [eax + 4]
// 0064cac7  53                   push ebx
// 0064cac8  56                   push esi
// 0064cac9  57                   push edi
// 0064caca  8bd9                 mov ebx, ecx
// 0064cacc  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0064cad0  8d7804               lea edi, [eax + 4]
// 0064cad3  51                   push ecx
// 0064cad4  52                   push edx
// 0064cad5  50                   push eax
// 0064cad6  8bcb                 mov ecx, ebx
// 0064cad8  e873fbffff           call 0x64c650
// 0064cadd  6a01                 push 1
// 0064cadf  8bcb                 mov ecx, ebx
// 0064cae1  8bf0                 mov esi, eax
// 0064cae3  e808f4ffff           call 0x64bef0
// 0064cae8  8937                 mov dword ptr [edi], esi
// 0064caea  8b4604               mov eax, dword ptr [esi + 4]
// 0064caed  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0064caf3  8930                 mov dword ptr [eax], esi
// 0064caf5  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064caf9  85c0                 test eax, eax
// 0064cafb  7506                 jne 0x64cb03
// 0064cafd  ffd7                 call edi
// 0064caff  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064cb03  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064cb07  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064cb0a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0064cb0e  85c0                 test eax, eax
// 0064cb10  7404                 je 0x64cb16
// 0064cb12  8b00                 mov eax, dword ptr [eax]
// 0064cb14  eb02                 jmp 0x64cb18
// 0064cb16  33c0                 xor eax, eax
// 0064cb18  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0064cb1b  7506                 jne 0x64cb23
// 0064cb1d  ffd7                 call edi
// 0064cb1f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064cb23  8b742410             mov esi, dword ptr [esp + 0x10]
// 0064cb27  c70600000000         mov dword ptr [esi], 0
// 0064cb2d  894e04               mov dword ptr [esi + 4], ecx
// 0064cb30  85db                 test ebx, ebx
// 0064cb32  7502                 jne 0x64cb36
// 0064cb34  ffd7                 call edi
// 0064cb36  8b13                 mov edx, dword ptr [ebx]
// 0064cb38  5f                   pop edi
// 0064cb39  8916                 mov dword ptr [esi], edx
// 0064cb3b  8bc6                 mov eax, esi
// 0064cb3d  5e                   pop esi
// 0064cb3e  5b                   pop ebx
// 0064cb3f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
