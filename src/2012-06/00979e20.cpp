// from server: 100% by Xemicl
// roc 2012-06 00979e20  unit: RBX::Limits::VCounter::V?$shared_ptr::?$thread_specific_ptr::delete_data  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00979e20
//
// 00979e20  56                   push esi
// 00979e21  8b31                 mov esi, dword ptr [ecx]
// 00979e23  85f6                 test esi, esi
// 00979e25  7426                 je 0x979e4d
// 00979e27  8d4604               lea eax, [esi + 4]
// 00979e2a  83c9ff               or ecx, 0xffffffff
// 00979e2d  f00fc108             lock xadd dword ptr [eax], ecx
// 00979e31  751a                 jne 0x979e4d
// 00979e33  8b16                 mov edx, dword ptr [esi]
// 00979e35  8b02                 mov eax, dword ptr [edx]
// 00979e37  6a00                 push 0
// 00979e39  8bce                 mov ecx, esi
// 00979e3b  ffd0                 call eax
// 00979e3d  56                   push esi
// 00979e3e  6a00                 push 0
// 00979e40  ff15ac22b200         call dword ptr [0xb222ac]
// 00979e46  50                   push eax
// 00979e47  ff15a822b200         call dword ptr [0xb222a8]
// 00979e4d  5e                   pop esi
// 00979e4e  c3                   ret 
// copied from an identical function in another client (function ??1NodePtr@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
#include <intrin.h>
struct Node {
	virtual ~Node();
	long refs;
};
struct NodePtr {
	Node* p;
	~NodePtr();
};
NodePtr::~NodePtr()
{
	Node* n = p;
	if (n) {
		if (_InterlockedDecrement(&n->refs) == 0) {
			n->~Node();
			HeapFree(GetProcessHeap(), 0, n);
		}
	}
}