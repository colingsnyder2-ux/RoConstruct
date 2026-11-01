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
