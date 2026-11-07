// Source-derived world pipeline port from openrbx include/v8world/Clump2.h.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
// >>> native-status (generated) -- do not edit >>>
// Clump | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src d61ee90d | roc native-status --write
#ifndef V8WORLD_CLUMP2_H
#define V8WORLD_CLUMP2_H


#include <cstddef>

namespace RBX {

class Edge;
class Joint;
class Primitive;

// SIZE 0x08
class PrimIterator
{
public:
	enum SearchType
	{
		IN_CLUMP = 0,
		IN_ASSEMBLY = 1,
	};

private:
	Primitive* primitive;  // 0x00
	SearchType searchType; // 0x04

	static bool isParent(Primitive* parentCandidate, Primitive* child, Joint* joint, SearchType searchType);
	static Primitive* findFirstChild(Primitive* primitive, SearchType searchType);
	static Primitive* findNextSibling(Primitive* parent, Primitive* child, SearchType searchType);
	static Primitive* findNextRelative(Primitive* parent, Primitive* child, SearchType searchType);

	PrimIterator(Primitive* primitive, SearchType searchType) : primitive(primitive), searchType(searchType) {}

public:
	static PrimIterator begin(Primitive* primitive, SearchType searchType)
	{
		return PrimIterator(primitive, searchType);
	}
	static PrimIterator end(SearchType searchType) { return PrimIterator(NULL, searchType); }

	Primitive* operator*() const { return primitive; }

	bool operator==(const PrimIterator& other) const { return primitive == other.primitive; }
	bool operator!=(const PrimIterator& other) const { return primitive != other.primitive; }

	PrimIterator& operator++();

	static Primitive* findParent(Primitive* primitive, SearchType searchType);
};


// SIZE 0x08
class EdgeIterator
{
public:
	static EdgeIterator begin(Primitive* primitive);

	EdgeIterator() : primitive(NULL), edge(NULL) {}

	EdgeIterator(Primitive* primitive, Edge* edge) : primitive(primitive), edge(edge) {}

	static EdgeIterator& end();

	EdgeIterator& operator++();

	Edge* operator*() const { return edge; }

	bool operator==(const EdgeIterator& other) const { return edge == other.edge && primitive == other.primitive; }

	bool operator!=(const EdgeIterator& other) const { return !(*this == other); }

private:
	static Edge* getNextExternalUtil(Primitive* primitive, Edge* edge);

	void findEdgeOnNextPrimitive();

	Primitive* primitive; // 0x00
	Edge* edge;           // 0x04
};


inline EdgeIterator& EdgeIterator::end()
{
	static EdgeIterator temp;
	return temp;
}

} // namespace RBX

#endif // V8WORLD_CLUMP2_H

#include "v8world/Assembly.h"
