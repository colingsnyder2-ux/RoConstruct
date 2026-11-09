// from server: 100% by auto
// roc 2010-06 006aa630  unit: boost::Vthread::?$sp_counted_impl_p  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006aa630
//
// 006aa630  53                   push ebx
// 006aa631  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006aa637  56                   push esi
// 006aa638  8b31                 mov esi, dword ptr [ecx]
// 006aa63a  57                   push edi
// 006aa63b  8b7904               mov edi, dword ptr [ecx + 4]
// 006aa63e  85f6                 test esi, esi
// 006aa640  7518                 jne 0x6aa65a
// 006aa642  ffd3                 call ebx
// 006aa644  33c0                 xor eax, eax
// 006aa646  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006aa64a  8d3ccf               lea edi, [edi + ecx*8]
// 006aa64d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006aa650  7713                 ja 0x6aa665
// 006aa652  85f6                 test esi, esi
// 006aa654  7408                 je 0x6aa65e
// 006aa656  8b06                 mov eax, dword ptr [esi]
// 006aa658  eb06                 jmp 0x6aa660
// 006aa65a  8b06                 mov eax, dword ptr [esi]
// 006aa65c  ebe8                 jmp 0x6aa646
// 006aa65e  33c0                 xor eax, eax
// 006aa660  3b780c               cmp edi, dword ptr [eax + 0xc]
// 006aa663  7302                 jae 0x6aa667
// 006aa665  ffd3                 call ebx
// 006aa667  8b442410             mov eax, dword ptr [esp + 0x10]
// 006aa66b  897804               mov dword ptr [eax + 4], edi
// 006aa66e  5f                   pop edi
// 006aa66f  8930                 mov dword ptr [eax], esi
// 006aa671  5e                   pop esi
// 006aa672  5b                   pop ebx
// 006aa673  c20800               ret 8
// standard library vector<double> (function ??H?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBE?AV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
