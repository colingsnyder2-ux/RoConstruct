// from server: 100% by Xemicl
// roc 2012-06 004bd160  unit: RBX::ViewRbxGfx  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004bd160
//
// 004bd160  64a100000000         mov eax, dword ptr fs:[0]
// 004bd166  6aff                 push -1
// 004bd168  686a25ac00           push 0xac256a
// 004bd16d  50                   push eax
// 004bd16e  8b442410             mov eax, dword ptr [esp + 0x10]
// 004bd172  64892500000000       mov dword ptr fs:[0], esp
// 004bd179  83ec44               sub esp, 0x44
// 004bd17c  3dffffff1f           cmp eax, 0x1fffffff
// 004bd181  7653                 jbe 0x4bd1d6
// 004bd183  68944db600           push 0xb64d94
// 004bd188  8d4c2404             lea ecx, [esp + 4]
// 004bd18c  ff154826b200         call dword ptr [0xb22648]
// 004bd192  8d4c241c             lea ecx, [esp + 0x1c]
// 004bd196  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 004bd19e  ff15dc29b200         call dword ptr [0xb229dc]
// 004bd1a4  8d0424               lea eax, [esp]
// 004bd1a7  50                   push eax
// 004bd1a8  8d4c242c             lea ecx, [esp + 0x2c]
// 004bd1ac  c644245001           mov byte ptr [esp + 0x50], 1
// 004bd1b1  c7442420a02eb400     mov dword ptr [esp + 0x20], 0xb42ea0
// 004bd1b9  ff154426b200         call dword ptr [0xb22644]
// 004bd1bf  c744241cac2eb400     mov dword ptr [esp + 0x1c], 0xb42eac
// 004bd1c7  8d4c241c             lea ecx, [esp + 0x1c]
// 004bd1cb  51                   push ecx
// 004bd1cc  c644245002           mov byte ptr [esp + 0x50], 2
// 004bd1d1  e87afeffff           call 0x4bd050
// 004bd1d6  85c0                 test eax, eax
// 004bd1d8  7511                 jne 0x4bd1eb
// 004bd1da  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004bd1de  64890d00000000       mov dword ptr fs:[0], ecx
// 004bd1e5  83c450               add esp, 0x50
// 004bd1e8  c20400               ret 4
// 004bd1eb  6a00                 push 0
// 004bd1ed  50                   push eax
// 004bd1ee  e8adba3600           call 0x828ca0
// 004bd1f3  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004bd1f7  83c408               add esp, 8
// 004bd1fa  64890d00000000       mov dword ptr fs:[0], ecx
// 004bd201  83c450               add esp, 0x50
// 004bd204  c20400               ret 4
// copied from an identical function in another client (function ?allocate@?$circular_buffer@UItem8@@V?$allocator@UItem8@@@std@@@boost@@QAEPAUItem8@@I@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <memory>
namespace boost {
template<class E> __declspec(noreturn) void throw_exception(const E& e);
template<class T, class Alloc = std::allocator<T> >
class circular_buffer {
public:
	typedef typename Alloc::size_type size_type;
	typedef typename Alloc::pointer pointer;
	Alloc m_alloc;
	size_type max_size() const { return m_alloc.max_size(); }
	pointer allocate(size_type n)
	{
		if (n > max_size())
			throw_exception(std::length_error("circular_buffer"));
		return (n == 0) ? 0 : m_alloc.allocate(n, 0);
	}
};
}
struct Item8 { int a; int b; };
template Item8* boost::circular_buffer<Item8>::allocate(size_type);