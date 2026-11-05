// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_fuzzyaxisnormordercac65da0e8379ec5.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
	bool fuzzyAxisAligned(const G3D::Matrix3& m0, const G3D::Matrix3& m1, float radTolerance)
	{
		G3D::Vector3 vectors[3] = {G3D::Vector3(), G3D::Vector3(), G3D::Vector3()};

		for (int i = 0; i < 3; i++)
		{
			vectors[i] = m1.getColumn(i);
		}

		for (int i = 0; i < 3; i++)
		{
			G3D::Vector3 m0Column = m0.getColumn(i);
			G3D::Vector3* vector = vectors; 
			int count = 0;
			while (count < 3)
			{
				G3D::Vector3 cross=m0Column.cross(*vector);
                if (sqrtf(cross.z*cross.z + cross.y*cross.y + cross.x*cross.x) < radTolerance)
					break;
				count++;
				vector++;
				if (count >= 3)
					return false;
			}
		}
		return true;
	}
