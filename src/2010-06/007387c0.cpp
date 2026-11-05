// from server: 100% by auto
// roc 2010-06 007387c0  unit: seg_00730000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007387c0
//
// 007387c0  83ec10               sub esp, 0x10
// 007387c3  56                   push esi
// 007387c4  57                   push edi
// 007387c5  8bf9                 mov edi, ecx
// 007387c7  8b4718               mov eax, dword ptr [edi + 0x18]
// 007387ca  8b771c               mov esi, dword ptr [edi + 0x1c]
// 007387cd  03f0                 add esi, eax
// 007387cf  3bc6                 cmp eax, esi
// 007387d1  7606                 jbe 0x7387d9
// 007387d3  ff150ca99e00         call dword ptr [0x9ea90c]
// 007387d9  8b3f                 mov edi, dword ptr [edi]
// 007387db  6aff                 push -1
// 007387dd  8d4c240c             lea ecx, [esp + 0xc]
// 007387e1  897c240c             mov dword ptr [esp + 0xc], edi
// 007387e5  89742410             mov dword ptr [esp + 0x10], esi
// 007387e9  e872faffff           call 0x738260
// 007387ee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007387f2  8b442408             mov eax, dword ptr [esp + 8]
// 007387f6  894c2414             mov dword ptr [esp + 0x14], ecx
// 007387fa  8d4c2410             lea ecx, [esp + 0x10]
// 007387fe  89442410             mov dword ptr [esp + 0x10], eax
// 00738802  e809afe9ff           call 0x5d3710
// 00738807  5f                   pop edi
// 00738808  5e                   pop esi
// 00738809  83c410               add esp, 0x10
// 0073880c  c3                   ret 
// standard library deque<ptr> (function ?back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
