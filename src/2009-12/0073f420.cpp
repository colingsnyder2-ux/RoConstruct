// from server: 100% by auto
// roc 2009-12 0073f420  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073f420
//
// 0073f420  6aff                 push -1
// 0073f422  68888f9400           push 0x948f88
// 0073f427  64a100000000         mov eax, dword ptr fs:[0]
// 0073f42d  50                   push eax
// 0073f42e  64892500000000       mov dword ptr fs:[0], esp
// 0073f435  83ec0c               sub esp, 0xc
// 0073f438  56                   push esi
// 0073f439  8bf1                 mov esi, ecx
// 0073f43b  89742404             mov dword ptr [esp + 4], esi
// 0073f43f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073f442  8b0e                 mov ecx, dword ptr [esi]
// 0073f444  8b10                 mov edx, dword ptr [eax]
// 0073f446  50                   push eax
// 0073f447  51                   push ecx
// 0073f448  52                   push edx
// 0073f449  51                   push ecx
// 0073f44a  8d442418             lea eax, [esp + 0x18]
// 0073f44e  50                   push eax
// 0073f44f  8bce                 mov ecx, esi
// 0073f451  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0073f459  e8e2feffff           call 0x73f340
// 0073f45e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0073f461  51                   push ecx
// 0073f462  e8f3430b00           call 0x7f385a
// 0073f467  8b16                 mov edx, dword ptr [esi]
// 0073f469  52                   push edx
// 0073f46a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0073f471  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0073f478  e8dd430b00           call 0x7f385a
// 0073f47d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0073f481  83c408               add esp, 8
// 0073f484  5e                   pop esi
// 0073f485  64890d00000000       mov dword ptr fs:[0], ecx
// 0073f48c  83c418               add esp, 0x18
// 0073f48f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
