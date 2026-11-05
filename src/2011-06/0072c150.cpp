// from server: 100% by auto
// roc 2011-06 0072c150  unit: RBX::FileMeshDataV2  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072c150
//
// 0072c150  83ec24               sub esp, 0x24
// 0072c153  33c0                 xor eax, eax
// 0072c155  56                   push esi
// 0072c156  57                   push edi
// 0072c157  8bd1                 mov edx, ecx
// 0072c159  83ec24               sub esp, 0x24
// 0072c15c  8944242c             mov dword ptr [esp + 0x2c], eax
// 0072c160  89442430             mov dword ptr [esp + 0x30], eax
// 0072c164  89442434             mov dword ptr [esp + 0x34], eax
// 0072c168  89442438             mov dword ptr [esp + 0x38], eax
// 0072c16c  8944243c             mov dword ptr [esp + 0x3c], eax
// 0072c170  89442440             mov dword ptr [esp + 0x40], eax
// 0072c174  89442444             mov dword ptr [esp + 0x44], eax
// 0072c178  89442448             mov dword ptr [esp + 0x48], eax
// 0072c17c  8944244c             mov dword ptr [esp + 0x4c], eax
// 0072c180  8b442454             mov eax, dword ptr [esp + 0x54]
// 0072c184  8bfc                 mov edi, esp
// 0072c186  b909000000           mov ecx, 9
// 0072c18b  8d74242c             lea esi, [esp + 0x2c]
// 0072c18f  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0072c191  50                   push eax
// 0072c192  8bca                 mov ecx, edx
// 0072c194  e817f7ffff           call 0x72b8b0
// 0072c199  5f                   pop edi
// 0072c19a  5e                   pop esi
// 0072c19b  83c424               add esp, 0x24
// 0072c19e  c20400               ret 4
// standard library vector<pod36> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
