// from server: 100% by colin
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