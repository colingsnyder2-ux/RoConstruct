// from server: 100% by auto
// roc 2009-06 00418060  unit: RBX::VTool::?$FactoryProduct::Creator  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418060
//
// 00418060  53                   push ebx
// 00418061  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00418067  56                   push esi
// 00418068  8bf1                 mov esi, ecx
// 0041806a  8b06                 mov eax, dword ptr [esi]
// 0041806c  57                   push edi
// 0041806d  8b7e04               mov edi, dword ptr [esi + 4]
// 00418070  85c0                 test eax, eax
// 00418072  7508                 jne 0x41807c
// 00418074  ffd3                 call ebx
// 00418076  8b06                 mov eax, dword ptr [esi]
// 00418078  85c0                 test eax, eax
// 0041807a  7404                 je 0x418080
// 0041807c  8b08                 mov ecx, dword ptr [eax]
// 0041807e  eb02                 jmp 0x418082
// 00418080  33c9                 xor ecx, ecx
// 00418082  85c0                 test eax, eax
// 00418084  7404                 je 0x41808a
// 00418086  8b00                 mov eax, dword ptr [eax]
// 00418088  eb02                 jmp 0x41808c
// 0041808a  33c0                 xor eax, eax
// 0041808c  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0041808f  034118               add eax, dword ptr [ecx + 0x18]
// 00418092  394604               cmp dword ptr [esi + 4], eax
// 00418095  7202                 jb 0x418099
// 00418097  ffd3                 call ebx
// 00418099  8b36                 mov esi, dword ptr [esi]
// 0041809b  85f6                 test esi, esi
// 0041809d  7404                 je 0x4180a3
// 0041809f  8b06                 mov eax, dword ptr [esi]
// 004180a1  eb02                 jmp 0x4180a5
// 004180a3  33c0                 xor eax, eax
// 004180a5  397814               cmp dword ptr [eax + 0x14], edi
// 004180a8  770d                 ja 0x4180b7
// 004180aa  85f6                 test esi, esi
// 004180ac  7404                 je 0x4180b2
// 004180ae  8b06                 mov eax, dword ptr [esi]
// 004180b0  eb02                 jmp 0x4180b4
// 004180b2  33c0                 xor eax, eax
// 004180b4  2b7814               sub edi, dword ptr [eax + 0x14]
// 004180b7  85f6                 test esi, esi
// 004180b9  740c                 je 0x4180c7
// 004180bb  8b36                 mov esi, dword ptr [esi]
// 004180bd  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004180c0  8b04b9               mov eax, dword ptr [ecx + edi*4]
// 004180c3  5f                   pop edi
// 004180c4  5e                   pop esi
// 004180c5  5b                   pop ebx
// 004180c6  c3                   ret 
// 004180c7  33c0                 xor eax, eax
// 004180c9  8b5010               mov edx, dword ptr [eax + 0x10]
// 004180cc  8b04ba               mov eax, dword ptr [edx + edi*4]
// 004180cf  5f                   pop edi
// 004180d0  5e                   pop esi
// 004180d1  5b                   pop ebx
// 004180d2  c3                   ret 
// standard library deque<string> (function ??D?$_Deque_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$00@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@XZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
