// 2008-06 native RBX::IndexBox (inactive), declared in native-headers/leaves2008/IndexBox2008.h. Original unit
// 007bbe30 getFaceCorners, 007bbed0 IndexBox(min, max) and the tables 00875da0..00875fc7; the inline destructor
// 0066f8d0 / ??_G 0066f8e0 are emitted with the vtable. Built with /fp:fast (the constructor 007bbed0 chains the corner stores without spills).
// Verified by tests/record_native_leaves2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// Leaves2008IndexBox | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 059ec078 | roc native-status --write
#include "leaves2008/IndexBox2008.h"

namespace RBX
{
	const float IndexBox::INDEXBOX_FACE_TO_NORMAL[6][3] =
	{
		{  1.0f,  0.0f,  0.0f },
		{  0.0f,  1.0f,  0.0f },
		{  0.0f,  0.0f,  1.0f },
		{ -1.0f,  0.0f,  0.0f },
		{  0.0f, -1.0f,  0.0f },
		{  0.0f,  0.0f, -1.0f }
	};

	const int IndexBox::INDEXBOX_FACE_TO_VERTEX[6][4] =
	{
		{ 1, 0, 2, 3 },
		{ 0, 1, 5, 4 },
		{ 0, 4, 6, 2 },
		{ 4, 5, 7, 6 },
		{ 2, 6, 7, 3 },
		{ 1, 3, 7, 5 }
	};

	const int IndexBox::INDEXBOX_EDGE_TO_VERTEX_AND_NORMALS[12][4] =
	{
		{ 0, 2, 0, 2 },
		{ 2, 3, 0, 4 },
		{ 3, 1, 0, 5 },
		{ 1, 0, 0, 1 },
		{ 0, 4, 2, 1 },
		{ 2, 6, 4, 2 },
		{ 3, 7, 5, 4 },
		{ 1, 5, 1, 5 },
		{ 6, 4, 3, 2 },
		{ 4, 5, 3, 1 },
		{ 5, 7, 3, 5 },
		{ 7, 6, 3, 4 }
	};

	const int IndexBox::INDEXBOX_FACE_EDGE_TO_NORMAL[6][4] =
	{
		{ 1, 2, 4, 5 },
		{ 0, 5, 3, 2 },
		{ 1, 3, 4, 0 },
		{ 1, 5, 4, 2 },
		{ 2, 3, 5, 0 },
		{ 0, 4, 3, 1 }
	};

	IndexBox::IndexBox(const G3D::Vector3& min, const G3D::Vector3& max)
	{
		corner[0].x = corner[1].x = corner[2].x = corner[3].x = max.x;
		corner[4].x = corner[5].x = corner[6].x = corner[7].x = min.x;

		corner[0].y = corner[1].y = corner[4].y = corner[5].y = max.y;
		corner[2].y = corner[3].y = corner[6].y = corner[7].y = min.y;

		corner[0].z = corner[2].z = corner[4].z = corner[6].z = max.z;
		corner[1].z = corner[3].z = corner[5].z = corner[7].z = min.z;
	}

	void IndexBox::getFaceCorners(int f, G3D::Vector3& v0, G3D::Vector3& v1, G3D::Vector3& v2, G3D::Vector3& v3) const
	{
		v0 = corner[INDEXBOX_FACE_TO_VERTEX[f][0]];
		v1 = corner[INDEXBOX_FACE_TO_VERTEX[f][1]];
		v2 = corner[INDEXBOX_FACE_TO_VERTEX[f][2]];
		v3 = corner[INDEXBOX_FACE_TO_VERTEX[f][3]];
	}
}
