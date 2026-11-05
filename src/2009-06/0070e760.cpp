// from server: 100% by auto
// roc 2009-06 0070e760  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070e760
//
// 0070e760  51                   push ecx
// 0070e761  8b542410             mov edx, dword ptr [esp + 0x10]
// 0070e765  56                   push esi
// 0070e766  8b742410             mov esi, dword ptr [esp + 0x10]
// 0070e76a  57                   push edi
// 0070e76b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0070e76f  c644240800           mov byte ptr [esp + 8], 0
// 0070e774  8b442408             mov eax, dword ptr [esp + 8]
// 0070e778  50                   push eax
// 0070e779  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070e77d  52                   push edx
// 0070e77e  83c108               add ecx, 8
// 0070e781  51                   push ecx
// 0070e782  50                   push eax
// 0070e783  56                   push esi
// 0070e784  57                   push edi
// 0070e785  e826fdffff           call 0x70e4b0
// 0070e78a  83c418               add esp, 0x18
// 0070e78d  8d04f7               lea eax, [edi + esi*8]
// 0070e790  5f                   pop edi
// 0070e791  5e                   pop esi
// 0070e792  59                   pop ecx
// 0070e793  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
