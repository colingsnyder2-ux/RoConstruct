// from server: 100% by auto
// roc 2009-06 004db820  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004db820
//
// 004db820  6aff                 push -1
// 004db822  68485e8500           push 0x855e48
// 004db827  64a100000000         mov eax, dword ptr fs:[0]
// 004db82d  50                   push eax
// 004db82e  64892500000000       mov dword ptr fs:[0], esp
// 004db835  83ec0c               sub esp, 0xc
// 004db838  56                   push esi
// 004db839  8bf1                 mov esi, ecx
// 004db83b  89742404             mov dword ptr [esp + 4], esi
// 004db83f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004db842  8b0e                 mov ecx, dword ptr [esi]
// 004db844  8b10                 mov edx, dword ptr [eax]
// 004db846  50                   push eax
// 004db847  51                   push ecx
// 004db848  52                   push edx
// 004db849  51                   push ecx
// 004db84a  8d442418             lea eax, [esp + 0x18]
// 004db84e  50                   push eax
// 004db84f  8bce                 mov ecx, esi
// 004db851  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004db859  e882f5ffff           call 0x4dade0
// 004db85e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004db861  51                   push ecx
// 004db862  e8cbd12300           call 0x718a32
// 004db867  8b16                 mov edx, dword ptr [esi]
// 004db869  52                   push edx
// 004db86a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004db871  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004db878  e8b5d12300           call 0x718a32
// 004db87d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004db881  83c408               add esp, 8
// 004db884  5e                   pop esi
// 004db885  64890d00000000       mov dword ptr fs:[0], ecx
// 004db88c  83c418               add esp, 0x18
// 004db88f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
