// from server: 100% by auto
// roc 2009-06 00410020  unit: boost::Vbad_weak_ptr::?$error_info_injector  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410020
//
// 00410020  53                   push ebx
// 00410021  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00410027  56                   push esi
// 00410028  8b31                 mov esi, dword ptr [ecx]
// 0041002a  57                   push edi
// 0041002b  8b7904               mov edi, dword ptr [ecx + 4]
// 0041002e  85f6                 test esi, esi
// 00410030  7518                 jne 0x41004a
// 00410032  ffd3                 call ebx
// 00410034  33c0                 xor eax, eax
// 00410036  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041003a  8d3ccf               lea edi, [edi + ecx*8]
// 0041003d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00410040  7713                 ja 0x410055
// 00410042  85f6                 test esi, esi
// 00410044  7408                 je 0x41004e
// 00410046  8b06                 mov eax, dword ptr [esi]
// 00410048  eb06                 jmp 0x410050
// 0041004a  8b06                 mov eax, dword ptr [esi]
// 0041004c  ebe8                 jmp 0x410036
// 0041004e  33c0                 xor eax, eax
// 00410050  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00410053  7302                 jae 0x410057
// 00410055  ffd3                 call ebx
// 00410057  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041005b  897804               mov dword ptr [eax + 4], edi
// 0041005e  5f                   pop edi
// 0041005f  8930                 mov dword ptr [eax], esi
// 00410061  5e                   pop esi
// 00410062  5b                   pop ebx
// 00410063  c20800               ret 8
// standard library vector<double> (function ??H?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBE?AV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
