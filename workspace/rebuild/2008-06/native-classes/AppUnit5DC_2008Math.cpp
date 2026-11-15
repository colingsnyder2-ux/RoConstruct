// 2008-06 native RBX::Math rows of the util/Math.cpp unit 005dd780..005df47f inside the application range
// 005dc000..005e8000 (inactive). RBX::Math is a static-only utility class: no layout, no RTTI, no vtable. The
// declarations are the donor util/Math.h (read-only; no native header declares RBX::Math). Bodies are in address order
// of the original; the unit is built with /fp:fast (x87 compare and constant forms of 005dda70 / 005dee10 / 005de1d0 /
// 005de230 only match with it). Verified by tests/record_native_app_unit5dc_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
#include "util/Math.h"
#include "util/Debug.h"
#include <cmath>

#define LODWORD(x) (*(DWORD*)(&x))

namespace RBX
{
	bool Math::isDenormal(float f)                                                   // 005dd7b0
	{
		return (LODWORD(f) & 0x7F800000) == 0 && (LODWORD(f) & 0x7FFFFF) != 0;
	}

	// 2008 body: no denormal test (005dd7d0 compares with _FInf, -_FInf, _FNan and _FSnan only). The evidence names
	// isNanInfDenorm 005dd7d0 / isNanInfDenormVector3 005dd860 are kept (record_native_app_unit609_2008.py binds
	// searchUpFine 0061033e to 005dd860 under that name). The variants with the inlined denormal test, 005dd820 (float)
	// and 005dd8b0 (Vector3), have no declaration in util/Math.h and are not recovered.
	bool Math::isNanInfDenorm(float f)                                                // 005dd7d0
	{
		return f == std::numeric_limits<float>::infinity()
			|| f == -std::numeric_limits<float>::infinity()
			|| f == std::numeric_limits<float>::quiet_NaN()
			|| f == std::numeric_limits<float>::signaling_NaN();
	}

	bool Math::isNanInfDenormVector3(const G3D::Vector3& v)                           // 005dd860
	{
		return Math::isNanInfDenorm(v.x)
			|| Math::isNanInfDenorm(v.y)
			|| Math::isNanInfDenorm(v.z);
	}

	bool Math::fixDenorm(G3D::Vector3& v)                                             // 005dd940
	{
		bool fixed = false;

		float x = v.x;
		if (Math::isDenormal(x))
		{
			v.x = 0;
			fixed = true;
		}

		float y = v.y;
		if (Math::isDenormal(y))
		{
			v.y = 0;
			fixed = true;
		}

		float z = v.z;
		if (Math::isDenormal(z))
		{
			v.z = 0;
			fixed = true;
		}

		return fixed;
	}

	bool Math::legalCameraCoord(const G3D::CoordinateFrame& c)                        // 005dd9b0
	{
		int i = 0;
		const float* transMatArr = (const float*)c.translation;
		const float* rotMatArr = (const float*)c.rotation;
		for (; i < 3; i++, transMatArr++, rotMatArr += 4)
		{
			float rotValue = *rotMatArr;
			for (int j = 0; j < 3; j++)
			{
				if (!(rotValue > -1.2f && rotValue < 1.2f))
					return false;
			}
			float transValue = *transMatArr;
			if (!(transValue > -1000000.0f && transValue < 1000000.0f))
				return false;
		}
		return true;
	}

	const float& segSizeRadians()
	{
		// 0x3cc90fda at 0083db40 (005decee / rotationFromByte) is twoPi() / 256, not the donor (pi() - 0.00001f) / 128
		static float ssr = Math::twoPi() / 256;
		return ssr;
	}

	float Math::rotationFromByte(unsigned char byteAngle)                              // 005dda30
	{
		float byteAngleFloat = byteAngle;
		return byteAngleFloat * segSizeRadians() - pi();
	}

	G3D::Matrix3 Math::getIWorldAtPoint(const G3D::Vector3& cofmPos, const G3D::Vector3& worldPos,
	                                    const G3D::Matrix3& iWorldAtCofm, float mass)   // 005dda70
	{
		G3D::Vector3 delta = worldPos - cofmPos;
		float deltaXSquared = delta.x * delta.x;
		float deltaYSquared = delta.y * delta.y;
		float deltaZSquared = delta.z * delta.z;
		float deltaYX = delta.y * delta.x;
		float deltaZX = delta.z * delta.x;
		float deltaZY = delta.z * delta.y;

		return iWorldAtCofm + mass * G3D::Matrix3(
				deltaZSquared + deltaYSquared,
				-deltaYX,
				-deltaZX,
				-deltaYX,
				deltaZSquared + deltaXSquared,
				-deltaZY,
				-deltaZX,
				-deltaZY,
				deltaYSquared + deltaXSquared
				);
	}

	G3D::Matrix3 Math::momentToObjectSpace(const G3D::Matrix3& iWorld, const G3D::Matrix3& bodyRotation)  // 005ddb30
	{
		return bodyRotation.transpose() * iWorld * bodyRotation;
	}

	G3D::Matrix3 Math::momentToWorldSpace(const G3D::Matrix3& iBody, const G3D::Matrix3& bodyRotation)    // 005ddb70
	{
		return (bodyRotation * iBody) * bodyRotation.transpose();
	}

	G3D::Vector3 Math::toDiagonal(const G3D::Matrix3& m)                               // 005ddbb0
	{
		return G3D::Vector3(m[0][0], m[1][1], m[2][2]);
	}

	G3D::Matrix3 Math::fromDiagonal(const G3D::Vector3& v)                             // 005ddbd0
	{
		return G3D::Matrix3(v.x, 0, 0, 0, v.y, 0, 0, 0, v.z);
	}

	bool Math::isAxisAligned(const G3D::Matrix3& matrix)                               // 005ddc20
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				float f = matrix[i][j];
				if (f != 0 && f != 1 && f != -1)
					return false;
			}
		}

		return true;
	}

	int Math::getOrientId(const G3D::Matrix3& matrix)                                  // 005ddc90
	{
		NormalId ColumnNormId = Vector3ToNormalId(matrix.getColumn(0));
		return Vector3ToNormalId(matrix.getColumn(1)) + 6 * ColumnNormId;
	}

	void Math::idToMatrix3(int orientId, G3D::Matrix3& matrix)                         // 005ddce0
	{
		NormalId norm1 = intToNormalId(orientId / 6);
		NormalId norm2 = intToNormalId(orientId % 6);
		G3D::Vector3 norm1Vec3 = normalIdToVector3(norm1);
		G3D::Vector3 norm2Vec3 = normalIdToVector3(norm2);
		G3D::Vector3 cross = norm1Vec3.cross(norm2Vec3);
		matrix.setColumn(0, norm1Vec3);
		matrix.setColumn(1, norm2Vec3);
		matrix.setColumn(2, cross);
	}

	G3D::Matrix3 Math::rotateAboutZ(const G3D::Matrix3& matrix, float radians)         // 005dddc0
	{
		G3D::Matrix3 m(G3D::Matrix3::identity());
		float sinR = sin(radians);
		float cosR = cos(radians);

		m.setColumn(0, G3D::Vector3(cosR, sinR, 0));
		m.setColumn(1, G3D::Vector3(-sinR, cosR, 0));

		return matrix * m;
	}

	G3D::Matrix3 Math::snapToAxes(const G3D::Matrix3& align)                          // 005dde50
	{
		G3D::Matrix3 unkMat;
		float aBest = 0.0f;
		int bestV = -1;
		int second = -1;
		
		for (int i = 0; i < 3; i++)
		{
			G3D::Vector3 loopColumn = align.getColumn(i);
			for (int j = 0; j < 3; j++)
			{
				float dotProd = G3D::Matrix3::identity().getColumn(j).dot(loopColumn);
				unkMat[i][j] = dotProd;
				if (fabs(dotProd) > fabs(aBest))
				{
					bestV = i;
					second = j;
					aBest = dotProd;
				}
			}
		}
		
		G3D::Vector3 myColumn = G3D::Matrix3::identity().getColumn(second);
		if (aBest < 0.0f)
		{
			myColumn *= -1.0f;
		}

		int v10 = -1;
		int v11 = -1;
		float v9 = 0.0f;
		
		for (int i = 0; i < 3; i++)
		{
			if (i != bestV)
			{
				for (int j = 0; j < 3; j++)
				{
					if (j != second)
					{
						if (fabs(unkMat[i][j]) > fabs(v9))
						{
							v9 = unkMat[i][j];
							v10 = i;
							v11 = j;
						}
					}
				}
			}
		}

		G3D::Vector3 myColumn2 = G3D::Matrix3::identity().getColumn(v11);
		if (v9 < 0.0f)
		{
			myColumn2 *= -1.0f;
		}

		int v15 = 3 - v10 - bestV;
		int calcColmTemp = 3 - v11 - second;
		G3D::Vector3 myColumn3 = G3D::Matrix3::identity().getColumn(calcColmTemp);
		if (unkMat[v15][calcColmTemp] < 0.0f)
		{
			myColumn3 *= -1.0f;
		}

		G3D::Matrix3 result;
		result.setColumn(bestV, myColumn);
		result.setColumn(v10, myColumn2);
		result.setColumn(v15, myColumn3);
		return result;
	}

	G3D::Vector3 Math::iRoundVector3(const G3D::Vector3& point)                        // 005de090
	{
		return G3D::Vector3(Math::iRound(point.x), Math::iRound(point.y), Math::iRound(point.z));
	}

	float Math::angleToE0(const G3D::Vector2& v)                                       // 005de0f0
	{
		G3D::Vector2 copy(v);
		copy.unitize();

		float f = acos(copy.x);
		if (copy.y < 0)
			return 2 * pi() - f;                 // 0x40c90fdb at 0083db44 (2 * pi()), not twoPi() 0x40c90fda
		return f;
	}

	float Math::angle(const G3D::Vector3& v0, const G3D::Vector3& v1)                  // 005de140
	{
		float f = v0.z * v1.z + v0.y * v1.y + v0.x * v1.x;
		if (f >= 1)
			return 0;
		if (f <= -1)
			return pi();
		return acos(f);
	}

	// 005de190 has no evidence name; elevationAngle is the util/Math.h float(const Vector3&) member whose body fits
	// (asin of y, clamped to +-pi/2 with float constants 0081e374 / 0081e370; callers 005cc083 / 005cc8d9)
	float Math::elevationAngle(const G3D::Vector3& v)                                  // 005de190
	{
		if (v.y >= 1)
			return piHalf();
		if (v.y <= -1)
			return -piHalf();
		return asin(v.y);
	}

	bool Math::fuzzyEq(const G3D::Vector3& v0, const G3D::Vector3& v1, float epsilon)  // 005de1d0
	{
		for (int i = 0; i < 3; i++)
		{
			if (!Math::fuzzyEq(v0[i], v1[i], epsilon))
				return false;
		}

		return true;
	}

	bool Math::fuzzyEq(const G3D::Matrix3& m0, const G3D::Matrix3& m1, float epsilon)  // 005de230
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (!Math::fuzzyEq(m0[i][j], m1[i][j], epsilon))
					return false;
			}
		}

		return true;
	}

	bool Math::fuzzyEq(const G3D::CoordinateFrame& c0, const G3D::CoordinateFrame& c1, float epsT, float epsR)  // 005de2a0
	{
		bool tRes = Math::fuzzyEq(c0.translation, c1.translation, epsT);
		if (!tRes)
			return false;

		bool rRes = Math::fuzzyEq(c0.rotation, c1.rotation, epsR);
		return rRes ? true : false;
	}

	bool Math::fuzzyEq(float f0, float f1, float epsilon)                              // inlined into 005de1d0 / 005de230
	{
		float num1 = fabs(f0) + 1;
		float num2 = fabs(f0 - f1);

		return (f0 == f1 || num2 <= num1 * epsilon);
	}

	G3D::Matrix3 Math::alignAxesClosest(const G3D::Matrix3& align, const G3D::Matrix3& target)  // 005de2f0
	{
		float dots[3][3];
		int maxI = -1, maxJ = -1;
		float maxDot = 0.0f;

		for (int i = 0; i < 3; i++)
		{
			G3D::Vector3 aAxis = align.getColumn(i);
			for (int j = 0; j < 3; j++)
			{
				G3D::Vector3 tAxis = target.getColumn(j);
				float atDot = aAxis.dot(tAxis);
				dots[i][j] = atDot;

				if (fabs(atDot) > fabs(maxDot))
				{
					maxI = i;
					maxJ = j;
					maxDot = atDot;
				}
			}
		}

		float mult = (maxDot >= 0.0f) ? 1.0f : -1.0f;
		G3D::Vector3 bestV = align.getColumn(maxI) * mult;

		float maxDot1 = 0.0f;
		int maxI1 = -1, maxJ1 = -1;

		for (int i = 0; i < 3; i++)
		{
			if (i != maxI)
				for (int j = 0; j < 3; j++)
				{
					if (j != maxJ && fabs(dots[i][j]) > fabs(maxDot1))
					{
						maxDot1 = dots[i][j];
						maxI1 = i;
						maxJ1 = j;
					}
				}
		}

		float mult1 = (maxDot1 >= 0.0f) ? 1.0f : -1.0f;
		G3D::Vector3 secondV = align.getColumn(maxI1) * mult1;

		int maxI2 = (3 - maxI1) - maxI;
		int maxJ2 = (3 - maxJ1) - maxJ;

		float maxDot2 = dots[maxI2][maxJ2];
		float mult2 = (maxDot2 >= 0.0f) ? 1.0f : -1.0f;

		G3D::Vector3 thirdV = align.getColumn(maxI2) * mult2;

		G3D::Matrix3 result;
		result.setColumn(maxJ, bestV);
		result.setColumn(maxJ1, secondV);
		result.setColumn(maxJ2, thirdV);

		return result;
	}

	NormalId Math::getClosestObjectNormalId(const G3D::Vector3& worldV, const G3D::Matrix3& objectR)  // 005de560
	{
		G3D::Vector3 worldObjMul = worldV * objectR;
		float absX = fabs(worldObjMul.x);
		float absY = fabs(worldObjMul.y);
		float absZ = fabs(worldObjMul.z);
		if (absX > absY)
		{
			if (absX > absZ)
			{
				return worldObjMul.x > 0 ? NORM_X : NORM_X_NEG;
			}
			else
			{
				return worldObjMul.z > 0 ? NORM_Z : NORM_Z_NEG;
			}
		}
		else if (absY > absZ)
		{
			return worldObjMul.y > 0 ? NORM_Y : NORM_Y_NEG;
		}
		return worldObjMul.z > 0 ? NORM_Z : NORM_Z_NEG;
	}

	G3D::Vector3 Math::vector3Abs(const G3D::Vector3& v)                               // 005de630
	{
		return G3D::Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
	}

	float Math::getHeading(const G3D::Vector3& look)                                   // 005de650
	{
		return atan2(-look.x, -look.z);
	}

	float Math::getElevation(const G3D::Vector3& look)
	{
		return asin(look.y);
	}

	void Math::getHeadingElevation(const G3D::CoordinateFrame& c, float& heading, float& elevation)  // 005de660
	{
		G3D::Vector3 lookVector = c.getLookVector();

		heading = Math::getHeading(lookVector);
		elevation = Math::getElevation(lookVector);
	}

	void Math::setHeadingElevation(G3D::CoordinateFrame& c, float heading, float elevation)  // 005de6c0
	{
		float Y = sin(elevation);
		float unk = sqrtf(1 - Y * Y);
		float X = -(sin(heading) * unk);
		float Z = -(unk * cos(heading));
		c.lookAt(c.translation + G3D::Vector3(X, Y, Z).direction());
	}

	void Math::rotateMatrixAboutY90(G3D::Matrix3& matrix, int times)                   // 005de740
	{
		static G3D::Matrix3 y90(0, 0, 1, 0, 1, 0, -1, 0, 0);

		for (int i = 0; i < times; ++i)
		{
			matrix = y90 * matrix;
		}
	}

	const G3D::Matrix3& Math::matrixRotateY()                                          // 005de800
	{
		static G3D::Matrix3 rotateY(0, 0, 1, 0, 1, 0, -1, 0, 0);
		return rotateY;
	}

	const G3D::Matrix3& Math::matrixTiltZ()                                            // 005de890
	{
		static G3D::Matrix3 tiltZ(0, 1, 0, -1, 0, 0, 0, 0, 1);
		return tiltZ;
	}

	const G3D::Matrix3& Math::matrixTiltNegativeZ()                                    // 005de910
	{
		static G3D::Matrix3 tiltNegativeZ(0, -1, 0, 1, 0, 0, 0, 0, 1);
		return tiltNegativeZ;
	}

	// jump table 005dea48: quadrants 0 / 2 build the X tilts, 1 / 3 copy matrixTiltZ 005de890 / matrixTiltNegativeZ
	// 005de910, default G3D::Matrix3::identity()
	const G3D::Matrix3 Math::matrixTiltQuadrant(int quadrant)                          // 005de990
	{
		switch (quadrant)
		{
		case 0:
			return G3D::Matrix3(1, 0, 0, 0, 0, -1, 0, 1, 0);
		case 1:
			return matrixTiltZ();
		case 2:
			return G3D::Matrix3(1, 0, 0, 0, 0, 1, 0, -1, 0);
		case 3:
			return matrixTiltNegativeZ();
		default:
			return G3D::Matrix3::identity();
		}
	}

	// floor((heading + 9pi/4) * 4 / 2pi) % 4: constants 7.0685835f (0x40e231d6, 2 * pi() + pi() / 4) 0083db50, 4.0f 00826e6c, 1/2pi (double) 0083db48
	int Math::toYAxisQuadrant(const G3D::CoordinateFrame& c)                           // 005dea60
	{
		float heading = getHeading(c.lookVector());
		return (int)floor((heading + 2 * Math::pi() + Math::pi() / 4) * 4 / G3D::twoPi()) % 4;
	}

	G3D::CoordinateFrame Math::getFocusSpace(const G3D::CoordinateFrame& focus)         // 005dec60
	{
		G3D::Vector3 look = focus.lookVector();
		float heading = Math::getHeading(look);

		// 005deca1 calls the Matrix3 copy 00513220 and copies +0x24..+0x2c inline: the CoordinateFrame copy constructor
		G3D::CoordinateFrame cf(focus);
		Math::setHeadingElevation(cf, heading, 0);
		return cf;
	}

	G3D::uint8 rotationToByteBase(float angle)                                       // 005dece0
	{
		RBXASSERT(angle <= Math::pi());
		RBXASSERT(angle >= -Math::pi());

		float result = (angle + Math::pi()) / segSizeRadians();
		int resInt = G3D::iRound(result);

		RBXASSERT(resInt >= -1);
		RBXASSERT(resInt <= 256);

		resInt = std::max(0, resInt);
		resInt = std::min(255, resInt);

		G3D::uint8 byte = (G3D::uint8)resInt;

		RBXASSERT(byte <= 255);

		return byte;
	}

	// Math::radWrap is not in this unit: 005ded68 calls 005cbec0 (ControllerService range)
	G3D::uint8 Math::rotationToByte(float angle)                                       // 005ded60
	{
		return rotationToByteBase(Math::radWrap(angle));
	}

	G3D::Vector3 Math::toGrid(const G3D::Vector3& v, const G3D::Vector3& grid)          // 005dee10
	{
		G3D::Vector3 units = v / grid;
		return grid * Math::iRoundVector3(units);
	}

	G3D::Vector3 Math::toGrid(const G3D::Vector3& v, float grid)                        // 005dee90
	{
		return Math::toGrid(v, G3D::Vector3(grid, grid, grid));
	}

	G3D::CoordinateFrame Math::snapToGrid(const G3D::CoordinateFrame& snap, float grid)  // 005deed0
	{
		return G3D::CoordinateFrame(Math::snapToAxes(snap.rotation), Math::toGrid(snap.translation, grid));
	}

	G3D::CoordinateFrame Math::snapToGrid(const G3D::CoordinateFrame& snap, const G3D::Vector3& grid)  // 005def40
	{
		return G3D::CoordinateFrame(Math::snapToAxes(snap.rotation), Math::toGrid(snap.translation, grid));
	}

	bool Math::fuzzyAxisAligned(const G3D::Matrix3& m0, const G3D::Matrix3& m1, float radTolerance)  // 005defa0
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
				G3D::Vector3 cross = m0Column.cross(*vector);
				if (sqrtf(cross.z * cross.z + cross.y * cross.y + cross.x * cross.x) < radTolerance)
					break;
				count++;
				vector++;
				if (count >= 3)
					return false;
			}
		}
		return true;
	}

	bool Math::isOrthonormal(const G3D::Matrix3& m)
	{
		return m.isOrthonormal();
	}

	bool Math::orthonormalizeIfNecessary(G3D::Matrix3& m)                              // 005df0a0
	{
		if (!Math::isOrthonormal(m))
		{
			m.orthonormalize();
			return true;
		}

		return false;
	}

	G3D::Vector3 Math::sortVector3(const G3D::Vector3& v)                              // 005df1b0
	{
		G3D::Vector3 result = v;

		if (result.z < result.y)
		{
			std::swap(result.z, result.y);
		}

		if (result.y < result.x)
		{
			std::swap(result.y, result.x);
		}

		if (result.z < result.y)
		{
			std::swap(result.z, result.y);
		}

		return result;
	}

	float Math::maxAxisLength(const G3D::Vector3& v)                                   // 005df220
	{
		G3D::Vector3 vAbs = G3D::Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
		return std::max(vAbs.x, std::max(vAbs.y, vAbs.z));
	}

	bool Math::intersectRayPlane(const G3D::Ray& ray, const G3D::Plane& plane, G3D::Vector3& hit)  // 005df380
	{
		float dotProd = ray.direction.dot(plane.normal());
		if (plane.halfSpaceContains(ray.origin))
		{
			if (!(dotProd < 0.0f))
			{
				hit = G3D::Vector3::inf();
				return false;
			}
		}
		else if (!(dotProd > 0.0f))
		{
			hit = G3D::Vector3::inf();
			return false;
		}
		G3D::Line myLine = G3D::Line::fromPointAndDirection(ray.origin, ray.direction);
		hit = myLine.intersection(plane);
		return true;
	}
}
