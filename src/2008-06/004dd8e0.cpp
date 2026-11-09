// from server: 100% by auto
// roc 2008-06 004dd8e0  unit: RBX::RenderBase::Mesh::Level  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd8e0
//
// 004dd8e0  83ec08               sub esp, 8
// 004dd8e3  53                   push ebx
// 004dd8e4  55                   push ebp
// 004dd8e5  56                   push esi
// 004dd8e6  8bf1                 mov esi, ecx
// 004dd8e8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004dd8eb  57                   push edi
// 004dd8ec  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004dd8ef  8bc8                 mov ecx, eax
// 004dd8f1  2bcf                 sub ecx, edi
// 004dd8f3  f7c1feffffff         test ecx, 0xfffffffe
// 004dd8f9  7504                 jne 0x4dd8ff
// 004dd8fb  33db                 xor ebx, ebx
// 004dd8fd  eb26                 jmp 0x4dd925
// 004dd8ff  3bf8                 cmp edi, eax
// 004dd901  7606                 jbe 0x4dd909
// 004dd903  ff1590288000         call dword ptr [0x802890]
// 004dd909  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004dd90d  8b06                 mov eax, dword ptr [esi]
// 004dd90f  85c9                 test ecx, ecx
// 004dd911  7404                 je 0x4dd917
// 004dd913  3bc8                 cmp ecx, eax
// 004dd915  7406                 je 0x4dd91d
// 004dd917  ff1590288000         call dword ptr [0x802890]
// 004dd91d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004dd921  2bdf                 sub ebx, edi
// 004dd923  d1fb                 sar ebx, 1
// 004dd925  8b542428             mov edx, dword ptr [esp + 0x28]
// 004dd929  8b442424             mov eax, dword ptr [esp + 0x24]
// 004dd92d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004dd931  52                   push edx
// 004dd932  6a01                 push 1
// 004dd934  50                   push eax
// 004dd935  51                   push ecx
// 004dd936  8bce                 mov ecx, esi
// 004dd938  e843fbffff           call 0x4dd480
// 004dd93d  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004dd940  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004dd943  7606                 jbe 0x4dd94b
// 004dd945  ff1590288000         call dword ptr [0x802890]
// 004dd94b  8b36                 mov esi, dword ptr [esi]
// 004dd94d  8bee                 mov ebp, esi
// 004dd94f  897c2414             mov dword ptr [esp + 0x14], edi
// 004dd953  85f6                 test esi, esi
// 004dd955  7518                 jne 0x4dd96f
// 004dd957  ff1590288000         call dword ptr [0x802890]
// 004dd95d  33c0                 xor eax, eax
// 004dd95f  8d3c5f               lea edi, [edi + ebx*2]
// 004dd962  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004dd965  7713                 ja 0x4dd97a
// 004dd967  85f6                 test esi, esi
// 004dd969  7408                 je 0x4dd973
// 004dd96b  8b36                 mov esi, dword ptr [esi]
// 004dd96d  eb06                 jmp 0x4dd975
// 004dd96f  8b06                 mov eax, dword ptr [esi]
// 004dd971  ebec                 jmp 0x4dd95f
// 004dd973  33f6                 xor esi, esi
// 004dd975  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004dd978  7306                 jae 0x4dd980
// 004dd97a  ff1590288000         call dword ptr [0x802890]
// 004dd980  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004dd984  897804               mov dword ptr [eax + 4], edi
// 004dd987  5f                   pop edi
// 004dd988  5e                   pop esi
// 004dd989  8928                 mov dword ptr [eax], ebp
// 004dd98b  5d                   pop ebp
// 004dd98c  5b                   pop ebx
// 004dd98d  83c408               add esp, 8
// 004dd990  c21000               ret 0x10
// standard library vector<short> (function ?insert@?$vector@FV?$allocator@F@std@@@std@@QAE?AV?$_Vector_iterator@FV?$allocator@F@std@@@2@V?$_Vector_const_iterator@FV?$allocator@F@std@@@2@ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
