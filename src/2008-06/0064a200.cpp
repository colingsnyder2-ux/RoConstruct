// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_faceoverlapinlineaccess16b5b005730c3cc8.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Face.h"
#include <G3D/Plane.h>
namespace RBX {
inline G3D::Vector3& Face::operator[](int i) {return ((G3D::Vector3*)this)[i];}
inline const G3D::Vector3& Face::operator[](int i) const {return ((G3D::Vector3*)this)[i];}
bool Face::overlapWithinPlanes(const Face& f0, const Face& f1, float tolerance)
	{
		for (int i = 0; i < 2; ++i)
		{
			const Face& face = i == 0 ? f0 : f1;
			const Face& otherFace = i == 0 ? f1 : f0;

			G3D::Plane p0(face.c0, face.c1, face.c3);
			
			G3D::Vector3 normal;
			float distance;
			p0.getEquation(normal, distance);

			Face overlapOn1 = otherFace.projectOverlapOnMe(face);

			for (int j = 0; j < 4; ++j)
			{
				if (fabs(overlapOn1[j].dot(normal) + distance) > tolerance)
					return false;
			}
		}

		return true;
	}

	
}