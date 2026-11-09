// from server: 100% by auto
// roc 2012-06 007b34a0  unit: RBX::FileMeshDataV2  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b34a0
//
// 007b34a0  83ec24               sub esp, 0x24
// 007b34a3  33c0                 xor eax, eax
// 007b34a5  56                   push esi
// 007b34a6  57                   push edi
// 007b34a7  8bd1                 mov edx, ecx
// 007b34a9  83ec24               sub esp, 0x24
// 007b34ac  8944242c             mov dword ptr [esp + 0x2c], eax
// 007b34b0  89442430             mov dword ptr [esp + 0x30], eax
// 007b34b4  89442434             mov dword ptr [esp + 0x34], eax
// 007b34b8  89442438             mov dword ptr [esp + 0x38], eax
// 007b34bc  8944243c             mov dword ptr [esp + 0x3c], eax
// 007b34c0  89442440             mov dword ptr [esp + 0x40], eax
// 007b34c4  89442444             mov dword ptr [esp + 0x44], eax
// 007b34c8  89442448             mov dword ptr [esp + 0x48], eax
// 007b34cc  8944244c             mov dword ptr [esp + 0x4c], eax
// 007b34d0  8b442454             mov eax, dword ptr [esp + 0x54]
// 007b34d4  8bfc                 mov edi, esp
// 007b34d6  b909000000           mov ecx, 9
// 007b34db  8d74242c             lea esi, [esp + 0x2c]
// 007b34df  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b34e1  50                   push eax
// 007b34e2  8bca                 mov ecx, edx
// 007b34e4  e857f9ffff           call 0x7b2e40
// 007b34e9  5f                   pop edi
// 007b34ea  5e                   pop esi
// 007b34eb  83c424               add esp, 0x24
// 007b34ee  c20400               ret 4
// standard library vector<pod36> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
