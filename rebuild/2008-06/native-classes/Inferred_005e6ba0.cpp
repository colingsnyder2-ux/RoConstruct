// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNATIVE_CLUMP_DECL
// INFERRED: RBX::Clump::sub_005e6ba0 (placeholder name for 005e6ba0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

void RBX::Clump::sub_005e6ba0(G3D::Array<const void*>& edges)
{
	RBX::EdgeIterator it = RBX::EdgeIterator::begin(rootPrimitive);
	static RBX::EdgeIterator stop;
	RBX::EdgeIterator finish = stop;
	while (it != finish)
	{
		edges.append(*it);
		++it;
	}
}
