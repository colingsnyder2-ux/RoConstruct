// from server: 100% by colin
// 2008-06 005469e0 std::_Uninit_fill_n<Vertex*, int, Vertex, allocator<Vertex>,
// _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag>
// Authentic VC9 <memory> _Uninit_fill_n; target loop stride is 4 (a 4-byte
// Vertex), the WildMagic 2 Vertex is 0x18.
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

void UninitFillStub(Vertex* first, unsigned int count, const Vertex& val,
	std::allocator<Vertex>& al)
{
	std::_Uninit_fill_n(first, count, val, al,
		std::_Nonscalar_ptr_iterator_tag(), std::_Range_checked_iterator_tag());
}