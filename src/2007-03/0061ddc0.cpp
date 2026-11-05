// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/IndexBox.cpp

// Candidate translation unit (score above; library headers required).
#include "util/IndexBox.h"

namespace RBX {

// clang-format off
const float IndexBox::INDEXBOX_FACE_TO_NORMAL[6][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1},
};

const int IndexBox::INDEXBOX_FACE_TO_VERTEX[6][4] = {
	{1, 0, 2, 3},
	{0, 1, 5, 4},
	{0, 4, 6, 2},
	{4, 5, 7, 6},
	{2, 6, 7, 3},
	{1, 3, 7, 5},
};
// clang-format on

// FUNCTION: WEBSERVICE 0x1008ea60
void IndexBox::getFaceCorners(int f, Vector3& v0, Vector3& v1, Vector3& v2, Vector3& v3) const
{
	v0 = corner[INDEXBOX_FACE_TO_VERTEX[f][0]];
	v1 = corner[INDEXBOX_FACE_TO_VERTEX[f][1]];
	v2 = corner[INDEXBOX_FACE_TO_VERTEX[f][2]];
	v3 = corner[INDEXBOX_FACE_TO_VERTEX[f][3]];
}

// FUNCTION: WEBSERVICE 0x1008ec50
IndexBox::IndexBox(const Vector3& min, const Vector3& max)
{
	corner[0].x = corner[1].x = corner[2].x = corner[3].x = max.x;
	corner[4].x = corner[5].x = corner[6].x = corner[7].x = min.x;

	corner[0].y = corner[1].y = corner[4].y = corner[5].y = max.y;
	corner[2].y = corner[3].y = corner[6].y = corner[7].y = min.y;

	corner[0].z = corner[2].z = corner[4].z = corner[6].z = max.z;
	corner[1].z = corner[3].z = corner[5].z = corner[7].z = min.z;
}

} // namespace RBX
