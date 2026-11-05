// from server: 100% by auto
// roc 2007-03 00595140  unit: seg_00590000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00595140
//
// 00595140  53                   push ebx
// 00595141  56                   push esi
// 00595142  8bf1                 mov esi, ecx
// 00595144  f6460c0f             test byte ptr [esi + 0xc], 0xf
// 00595148  57                   push edi
// 00595149  7515                 jne 0x595160
// 0059514b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0059514e  83c010               add eax, 0x10
// 00595151  c1e804               shr eax, 4
// 00595154  394608               cmp dword ptr [esi + 8], eax
// 00595157  7707                 ja 0x595160
// 00595159  6a01                 push 1
// 0059515b  e880feffff           call 0x594fe0
// 00595160  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00595163  85db                 test ebx, ebx
// 00595165  7506                 jne 0x59516d
// 00595167  8b5e08               mov ebx, dword ptr [esi + 8]
// 0059516a  c1e304               shl ebx, 4
// 0059516d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00595170  83eb01               sub ebx, 1
// 00595173  8bfb                 mov edi, ebx
// 00595175  c1ef04               shr edi, 4
// 00595178  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0059517c  7511                 jne 0x59518f
// 0059517e  6a10                 push 0x10
// 00595180  8d4e01               lea ecx, [esi + 1]
// 00595183  ff15c8e57700         call dword ptr [0x77e5c8]
// 00595189  8b5604               mov edx, dword ptr [esi + 4]
// 0059518c  8904ba               mov dword ptr [edx + edi*4], eax
// 0059518f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00595192  8b442410             mov eax, dword ptr [esp + 0x10]
// 00595196  8bd3                 mov edx, ebx
// 00595198  83e20f               and edx, 0xf
// 0059519b  0314b9               add edx, dword ptr [ecx + edi*4]
// 0059519e  50                   push eax
// 0059519f  52                   push edx
// 005951a0  8d4e01               lea ecx, [esi + 1]
// 005951a3  ff15f8e47700         call dword ptr [0x77e4f8]
// 005951a9  83461001             add dword ptr [esi + 0x10], 1
// 005951ad  5f                   pop edi
// 005951ae  895e0c               mov dword ptr [esi + 0xc], ebx
// 005951b1  5e                   pop esi
// 005951b2  5b                   pop ebx
// 005951b3  c20400               ret 4
// standard library deque<char> (function ?push_front@?$deque@DV?$allocator@D@std@@@std@@QAEXABD@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
