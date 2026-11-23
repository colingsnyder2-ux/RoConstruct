// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Block static face tables (inactive). Values read from the exe .rdata: BLOCK_FACE_TO_VERTEX at
// 0084aec8 (6x4 ints, [face][vertex] -> vertex index) and BLOCK_FACE_VERTEX_TO_EDGE at 0084af28 (6x4 ints).
// Declarations: native-headers/v8world/Block2008.h. The only definition of these two symbols in the native tree.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Contact2008.h"
#include "v8world/Block2008.h"

namespace RBX
{
	const int Block::BLOCK_FACE_TO_VERTEX[6][4] = {
		{0, 2, 3, 1}, {0, 1, 5, 4}, {0, 4, 6, 2}, {4, 5, 7, 6}, {2, 6, 7, 3}, {1, 3, 7, 5}};

	const int Block::BLOCK_FACE_VERTEX_TO_EDGE[6][4] = {
		{4, 11, 5, 8}, {8, 3, 9, 0}, {0, 7, 1, 4}, {9, 6, 10, 7}, {1, 10, 2, 11}, {5, 2, 6, 3}};
}
