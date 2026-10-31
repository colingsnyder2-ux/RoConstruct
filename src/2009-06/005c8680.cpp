// from server: 80% by EspClaude
// from server: 100% by colin
// roc 2008-06 00546f50  unit: seg_00540000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00546f50
//
// 00546f50  55                   push ebp
// 00546f51  8bec                 mov ebp, esp
// 00546f53  6aff                 push -1
// 00546f55  68b1cd7c00           push 0x7ccdb1
// 00546f5a  64a100000000         mov eax, dword ptr fs:[0]
// 00546f60  50                   push eax
// 00546f61  83ec10               sub esp, 0x10
// 00546f64  a1c05c9600           mov eax, dword ptr [0x965cc0]
// 00546f69  33c5                 xor eax, ebp
// 00546f6b  50                   push eax
// 00546f6c  8d45f4               lea eax, [ebp - 0xc]
// 00546f6f  64a300000000         mov dword ptr fs:[0], eax
// 00546f75  8b4508               mov eax, dword ptr [ebp + 8]
// 00546f78  8945f0               mov dword ptr [ebp - 0x10], eax
// 00546f7b  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 00546f7e  51                   push ecx
// 00546f7f  6a04                 push 4
// 00546f81  e8eaa6ebff           call 0x401670
// 00546f86  83c408               add esp, 8
// 00546f89  8945e8               mov dword ptr [ebp - 0x18], eax
// 00546f8c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00546f93  837de800             cmp dword ptr [ebp - 0x18], 0
// 00546f97  7411                 je 0x546faa
// 00546f99  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00546f9c  52                   push edx
// 00546f9d  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 00546fa0  e87b98faff           call 0x4f0820
// 00546fa5  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00546fa8  eb07                 jmp 0x546fb1
// 00546faa  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 00546fb1  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 00546fb4  8945ec               mov dword ptr [ebp - 0x14], eax
// 00546fb7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00546fbe  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00546fc1  64890d00000000       mov dword ptr fs:[0], ecx
// 00546fc8  59                   pop ecx
// 00546fc9  8be5                 mov esp, ebp
// 00546fcb  5d                   pop ebp
// 00546fcc  c3                   ret 

// 2008-06 00546f50 std::_Construct<Vertex, Vertex>(Vertex*, const Vertex&)
// Authentic VC9 <xmemory> _Construct; the 2008 build instantiated it with a
// 4-byte Vertex (target passes 4 to the placement operator new, not 0x18).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD

#include <memory>
#include <xmemory>

class Vertex
{
public:
	int m_position;
	Vertex();
	Vertex(const Vertex&);
};

void ConstructStub(Vertex* p, const Vertex& val)
{
	std::_Construct(p, val);
}