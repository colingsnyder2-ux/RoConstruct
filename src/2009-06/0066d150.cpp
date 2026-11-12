// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client App/util/Math.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Math.h"

#include "decomp.h"

#include <G3D/Line.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include <limits>

namespace RBX {

static float rotationStep()
{
	static const float step = static_cast<float>(G3D::twoPi() / 256.0);
	return step;
}

// FUNCTION: WEBSERVICE 0x100de860
// FUNCTION: ROBLOX 0x005efa10
bool Math::isDenormal(float f)
{
	const int bits = *reinterpret_cast<const int*>(&f);
	return (bits & 0x7f800000) == 0 && (bits & 0x7fffff) != 0;
}

// FUNCTION: WEBSERVICE 0x100de880
// FUNCTION: ROBLOX 0x005efa30
bool Math::isNanInfDenorm(float f)
{
	return f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() ||
		   f == std::numeric_limits<float>::quiet_NaN() || f == std::numeric_limits<float>::signaling_NaN() ||
		   isDenormal(f);
}

// FUNCTION: WEBSERVICE 0x100de8e0
// FUNCTION: ROBLOX 0x005efa90
bool Math::isNanInfDenormVector3(const Vector3& v)
{
	return isNanInfDenorm(v.x) || isNanInfDenorm(v.y) || isNanInfDenorm(v.z);
}

// FUNCTION: WEBSERVICE 0x100de930
// FUNCTION: ROBLOX 0x005efae0
bool Math::fixDenorm(Vector3& v)
{
	bool fixed = false;

	if (isDenormal(v.x)) {
		v.x = 0.0f;
		fixed = true;
	}
	if (isDenormal(v.y)) {
		v.y = 0.0f;
		fixed = true;
	}
	if (isDenormal(v.z)) {
		v.z = 0.0f;
		fixed = true;
	}

	return fixed;
}

// FUNCTION: WEBSERVICE 0x100de9a0
// FUNCTION: ROBLOX 0x005efb50
bool Math::legalCameraCoord(const CoordinateFrame& c)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			const float value = c.rotation[i][i];
			if (!(value > -1.2f && value < 1.2f)) {
				return false;
			}
		}

		const float value = c.translation[i];
		if (!(value > -1000000.0f && value < 1000000.0f)) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100dea30
// FUNCTION: ROBLOX 0x005efbe0
float Math::rotationFromByte(unsigned char byteAngle)
{
	const float value = byteAngle;

	return value * rotationStep() - 3.14159274f;
}

// FUNCTION: WEBSERVICE 0x100dea70
// FUNCTION: ROBLOX 0x005efc20
Matrix3 Math::getIWorldAtPoint(const Vector3& cofmPos, const Vector3& worldPos, const Matrix3& iWorldAtCofm, float mass)
{
	const float x = worldPos.x - cofmPos.x;
	const float y = worldPos.y - cofmPos.y;
	const float z = worldPos.z - cofmPos.z;

	const float xx = x * x;
	const float yy = y * y;
	const float zz = z * z;
	const float xy = x * y;
	const float xz = x * z;
	const float yz = y * z;

	return iWorldAtCofm + mass * Matrix3(yy + zz, -xy, -xz, -xy, xx + zz, -yz, -xz, -yz, xx + yy);
}

// FUNCTION: WEBSERVICE 0x100deb30
// FUNCTION: ROBLOX 0x005efce0
Matrix3 Math::momentToObjectSpace(const Matrix3& iWorld, const Matrix3& bodyRotation)
{
	return bodyRotation.transpose() * iWorld * bodyRotation;
}

// FUNCTION: WEBSERVICE 0x100deb70
// FUNCTION: ROBLOX 0x005efd20
Matrix3 Math::momentToWorldSpace(const Matrix3& iBody, const Matrix3& bodyRotation)
{
	return bodyRotation * iBody * bodyRotation.transpose();
}

// FUNCTION: WEBSERVICE 0x100debb0
// FUNCTION: ROBLOX 0x005efd60
Vector3 Math::toDiagonal(const Matrix3& m)
{
	return Vector3(m[0][0], m[1][1], m[2][2]);
}

// FUNCTION: WEBSERVICE 0x100debd0
// FUNCTION: ROBLOX 0x005efd80
Matrix3 Math::fromDiagonal(const Vector3& v)
{
	return Matrix3(v.x, 0.0f, 0.0f, 0.0f, v.y, 0.0f, 0.0f, 0.0f, v.z);
}

// FUNCTION: WEBSERVICE 0x100dec20
// FUNCTION: ROBLOX 0x005efdd0
bool Math::isAxisAligned(const Matrix3& matrix)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			const float value = matrix[i][j];
			if (value != 0.0f && value != 1.0f && value != -1.0f) {
				return false;
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100dec90
// FUNCTION: ROBLOX 0x005efe40
int Math::getOrientId(const Matrix3& matrix)
{
	const NormalId x = Vector3ToNormalId(matrix.getColumn(0));
	const NormalId y = Vector3ToNormalId(matrix.getColumn(1));

	return x * 6 + y;
}

// FUNCTION: WEBSERVICE 0x100dece0
// FUNCTION: ROBLOX 0x005efe90
void Math::idToMatrix3(int orientId, Matrix3& matrix)
{
	const NormalId xId = intToNormalId(orientId / 6);
	const NormalId yId = intToNormalId(orientId % 6);

	const Vector3 vX = normalIdToVector3(xId);
	const Vector3 vY = normalIdToVector3(yId);
	const Vector3 vZ = vX.cross(vY);

	matrix.setColumn(0, vX);
	matrix.setColumn(1, vY);
	matrix.setColumn(2, vZ);
}

// FUNCTION: WEBSERVICE 0x100dedc0
// FUNCTION: ROBLOX 0x005eff70
Matrix3 Math::rotateAboutZ(const Matrix3& matrix, float radians)
{
	Matrix3 rotMatrix = Matrix3::identity();

	const float sinR = sinf(radians);
	const float cosR = cosf(radians);

	rotMatrix.setColumn(0, Vector3(cosR, sinR, 0.0f));
	rotMatrix.setColumn(1, Vector3(-sinR, cosR, 0.0f));

	return matrix * rotMatrix;
}

// FUNCTION: WEBSERVICE 0x100dee50
// FUNCTION: ROBLOX 0x005f0000
Matrix3 Math::snapToAxes(const Matrix3& align)
{
	float dots[3][3];

	float best = 0.0f;
	int aBest = -1;
	int tBest = -1;

	for (int a = 0; a < 3; ++a) {
		Vector3 aAxis = align.getColumn(a);

		for (int i = 0; i < 3; ++i) {
			float t = Matrix3::identity().getColumn(i).dot(aAxis);

			dots[a][i] = t;

			if (fabs(t) > fabs(best)) {
				tBest = i;
				best = t;
				aBest = a;
			}
		}
	}

	Vector3 bestV = Matrix3::identity().getColumn(tBest);

	if (best < 0.0f) {
		bestV.x = bestV.x * -1.0f;
		bestV.y = bestV.y * -1.0f;
		bestV.z = bestV.z * -1.0f;
	}

	float second = 0.0f;
	int aSecond = -1;
	int tSecond = -1;

	for (int a = 0; a < 3; ++a) {
		if (a != aBest) {
			for (int i = 0; i < 3; ++i) {
				if (i != tBest && fabs(dots[a][i]) > fabs(second)) {
					second = dots[a][i];
					tSecond = i;
					aSecond = a;
				}
			}
		}
	}

	Vector3 secondV = Matrix3::identity().getColumn(tSecond);

	if (second < 0.0f) {
		secondV.x = secondV.x * -1.0f;
		secondV.y = secondV.y * -1.0f;
		secondV.z = secondV.z * -1.0f;
	}

	int aThird = (3 - aSecond) - aBest;
	int third = (3 - tSecond) - tBest;

	Vector3 thirdV = Matrix3::identity().getColumn(third);

	if (dots[aThird][third] < 0.0f) {
		thirdV.x = thirdV.x * -1.0f;
		thirdV.y = thirdV.y * -1.0f;
		thirdV.z = thirdV.z * -1.0f;
	}

	Matrix3 answer;

	answer.setColumn(aBest, bestV);
	answer.setColumn(aSecond, secondV);
	answer.setColumn(aThird, thirdV);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100df0a0
// FUNCTION: ROBLOX 0x005f0250
Vector3 Math::iRoundVector3(const Vector3& point)
{
	return Vector3(
		static_cast<float>(G3D::iRound(point.x)),
		static_cast<float>(G3D::iRound(point.y)),
		static_cast<float>(G3D::iRound(point.z))
	);
}

// FUNCTION: WEBSERVICE 0x100df100
// FUNCTION: ROBLOX 0x005f02b0
float Math::angleToE0(const Vector2& v)
{
	Vector2 u = v;
	u.unitize();

	const float answer = acosf(u.x);

	if (u.y < 0.0f) {
		return 6.28318548f - answer;
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x100df150
// FUNCTION: ROBLOX 0x005f0300
float Math::angle(const Vector3& v0, const Vector3& v1)
{
	const float dot = v0.dot(v1);

	if (dot >= 1.0f) {
		return 0.0f;
	}
	if (dot <= -1.0f) {
		return 3.14159274f;
	}

	return acosf(dot);
}

// FUNCTION: ROBLOX 0x005f0350
float Math::elevationAngle(const Vector3& p_unk0x04)
{
	if (p_unk0x04.y >= 1.0f) {
		return 1.57079637f;
	}
	if (p_unk0x04.y <= -1.0f) {
		return -1.57079637f;
	}

	return asinf(p_unk0x04.y);
}

// FUNCTION: WEBSERVICE 0x100df1a0
// FUNCTION: ROBLOX 0x005f0390
bool Math::fuzzyEq(const Vector3& v0, const Vector3& v1, float epsilon)
{
	for (int i = 0; i < 3; ++i) {
		const float a = v0[i];
		const float b = v1[i];

		if (a != b && !(fabsf(a - b) <= (fabsf(a) + 1.0f) * epsilon)) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100df200
// FUNCTION: ROBLOX 0x005f03f0
bool Math::fuzzyEq(const Matrix3& m0, const Matrix3& m1, float epsilon)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			const float a = m0[i][j];
			const float b = m1[i][j];

			if (a != b && !(fabsf(a - b) <= (fabsf(a) + 1.0f) * epsilon)) {
				return false;
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100df270
// FUNCTION: ROBLOX 0x005f0460
bool Math::fuzzyEq(const CoordinateFrame& c0, const CoordinateFrame& c1, float epsT, float epsR)
{
	if (!fuzzyEq(c0.translation, c1.translation, epsT)) {
		return false;
	}

	return fuzzyEq(c0.rotation, c1.rotation, epsR) ? true : false;
}

// FUNCTION: WEBSERVICE 0x100df2c0
// FUNCTION: ROBLOX 0x005f04b0
Matrix3 Math::alignAxesClosest(const Matrix3& align, const Matrix3& target)
{
	float dots[3][3];

	float best = 0.0f;
	int aBest = -1;
	int iBest = -1;

	for (int a = 0; a < 3; ++a) {
		Vector3 aAxis = align.getColumn(a);

		for (int i = 0; i < 3; ++i) {
			Vector3 tAxis = target.getColumn(i);

			dots[a][i] = aAxis.dot(tAxis);

			if (fabs(dots[a][i]) > fabs(best)) {
				aBest = a;
				best = dots[a][i];
				iBest = i;
			}
		}
	}

	Vector3 bestV = align.getColumn(aBest) * (best >= 0.0f ? 1.0f : -1.0f);

	float second = 0.0f;
	int aSecond = -1;
	int iSecond = -1;

	for (int a = 0; a < 3; ++a) {
		if (a != aBest) {
			for (int i = 0; i < 3; ++i) {
				if (i != iBest) {
					if (fabs(dots[a][i]) > fabs(second)) {
						aSecond = a;
						second = dots[a][i];
						iSecond = i;
					}
				}
			}
		}
	}

	Vector3 secondV = align.getColumn(aSecond) * (second >= 0.0f ? 1.0f : -1.0f);

	int aThird = (3 - aSecond) - aBest;
	int iThird = (3 - iSecond) - iBest;

	Vector3 thirdV = align.getColumn(aThird) * (dots[aThird][iThird] >= 0.0f ? 1.0f : -1.0f);

	Matrix3 answer;

	answer.setColumn(iBest, bestV);
	answer.setColumn(iSecond, secondV);
	answer.setColumn(iThird, thirdV);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100df530
// FUNCTION: ROBLOX 0x005f0720
NormalId Math::getClosestObjectNormalId(const Vector3& worldV, const Matrix3& objectR)
{
	const Vector3 objectNormal = worldV * objectR;

	const float x = fabsf(objectNormal.x);
	const float y = fabsf(objectNormal.y);
	const float z = fabsf(objectNormal.z);

	if (x > y) {
		if (x > z) {
			return objectNormal.x > 0.0f ? NORM_X : NORM_X_NEG;
		}

		return objectNormal.z > 0.0f ? NORM_Z : NORM_Z_NEG;
	}

	if (y > z) {
		return objectNormal.y > 0.0f ? NORM_Y : NORM_Y_NEG;
	}

	return objectNormal.z > 0.0f ? NORM_Z : NORM_Z_NEG;
}

// FUNCTION: WEBSERVICE 0x100df600
// FUNCTION: ROBLOX 0x005f07f0
Vector3 Math::vector3Abs(const Vector3& v)
{
	return Vector3(fabsf(v.x), fabsf(v.y), fabsf(v.z));
}

// FUNCTION: WEBSERVICE 0x100df620
// FUNCTION: ROBLOX 0x005f0810
float Math::getHeading(const Vector3& look)
{
	return atan2f(-look.x, -look.z);
}

// STUB: WEBSERVICE 0x100df630
// STUB: ROBLOX 0x005f0820
void Math::getHeadingElevation(const CoordinateFrame& c, float& heading, float& elevation)
{
	const Vector3 look = c.rotation.getColumn(2) * CoordinateFrame::zLookDirection;

	heading = atan2f(-look.x, -look.z);
	elevation = asinf(look.y);
}

// FUNCTION: WEBSERVICE 0x100df690
// FUNCTION: ROBLOX 0x005f0880
void Math::setHeadingElevation(CoordinateFrame& c, float heading, float elevation)
{
	const float y = sinf(elevation);
	const float flat = sqrtf(1.0f - y * y);
	const Vector3 look(-sinf(heading) * flat, y, -cosf(heading) * flat);

	c.lookAt(c.translation + look.direction());
}

// FUNCTION: WEBSERVICE 0x100df710
// FUNCTION: ROBLOX 0x005f0900
void Math::rotateMatrixAboutY90(Matrix3& matrix, int times)
{
	static const Matrix3 y90(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	for (int i = 0; i < times; ++i) {
		matrix = y90 * matrix;
	}
}

// FUNCTION: WEBSERVICE 0x100df7d0
// FUNCTION: ROBLOX 0x005f09c0
const Matrix3& Math::matrixRotateY()
{
	static const Matrix3 m(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	return m;
}

// FUNCTION: WEBSERVICE 0x100df860
// FUNCTION: ROBLOX 0x005f0a50
const Matrix3& Math::matrixTiltZ()
{
	static const Matrix3 m(0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	return m;
}

// FUNCTION: ROBLOX 0x005f0ad0
const Matrix3& Math::matrixTiltNegativeZ()
{
	static const Matrix3 m(0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	return m;
}

// FUNCTION: ROBLOX 0x005f0b50
const Matrix3 Math::matrixTiltQuadrant(int p_unk0x04)
{
	switch (p_unk0x04) {
	case 0:
		return Matrix3(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
	case 1:
		return matrixTiltZ();
	case 2:
		return Matrix3(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f);
	case 3:
		return matrixTiltNegativeZ();
	default:
		return Matrix3::identity();
	}
}

// FUNCTION: ROBLOX 0x005f0c20
int Math::toYAxisQuadrant(const CoordinateFrame& p_unk0x04)
{
	Vector3 look = p_unk0x04.lookVector();

	return radiansToQuadrant(atan2(-look.x, -look.z));
}

// FUNCTION: WEBSERVICE 0x100df8e0
// FUNCTION: ROBLOX 0x005f0c90
const Matrix3& Math::getAxisRotationMatrix(int face)
{
	static const Matrix3 y = Matrix3::fromEulerAnglesXYZ(0.0f, 0.0f, 1.57079637f);
	static const Matrix3 z = Matrix3::fromEulerAnglesXYZ(0.0f, 1.57079637f, 0.0f);
	static const Matrix3 y_neg = y;
	static const Matrix3 z_neg = z;

	switch (face) {
	case NORM_X:
		return Matrix3::identity();
	case NORM_Y:
		return y;
	case NORM_Z:
		return z;
	case NORM_X_NEG:
		return Matrix3::identity();
	case NORM_Y_NEG:
		return y_neg;
	case NORM_Z_NEG:
		return z_neg;
	}

	return Matrix3::identity();
}

// FUNCTION: WEBSERVICE 0x100dfa70
// FUNCTION: ROBLOX 0x005f0e20
CoordinateFrame Math::getFocusSpace(const CoordinateFrame& focus)
{
	const Vector3 look = focus.rotation.getColumn(2) * CoordinateFrame::zLookDirection;
	const float heading = atan2f(-look.x, -look.z);

	CoordinateFrame answer = focus;
	setHeadingElevation(answer, heading, 0.0f);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100dfaf0
// FUNCTION: ROBLOX 0x005f0ea0
unsigned char rotationToByteBase(float angle)
{
	const float fAngle = (angle + 3.14159274f) / rotationStep();
	int iAngle = G3D::iRound(fAngle);

	iAngle = std::max(0, iAngle);

	return static_cast<unsigned char>(std::min(255, iAngle));
}

// FUNCTION: WEBSERVICE 0x100dfb70
// FUNCTION: ROBLOX 0x005f0f20
unsigned char Math::rotationToByte(float angle)
{
	return rotationToByteBase(angle);
}

// FUNCTION: ROBLOX 0x005f0f40
float Math::computeLaunchAngle(float v, float x, float y, float g)
{
	g = fabs(g);
	float disc = v * v * v * v - g * (x * x * g + 2.0f * y * v * v);
	if (disc <= 0.0f) {
		return 0.78539819f;
	}

	float root = sqrt(disc);
	float a = atan((v * v + root) / (g * x));
	float b = atan((v * v - root) / (g * x));
	return std::min(a, b);
}

// FUNCTION: WEBSERVICE 0x100dfb90
// FUNCTION: ROBLOX 0x005f0fd0
Vector3 Math::toGrid(const Vector3& v, const Vector3& grid)
{
	const Vector3 units = v / grid;

	return grid * iRoundVector3(units);
}

// FUNCTION: WEBSERVICE 0x100dfc10
// FUNCTION: ROBLOX 0x005f1050
Vector3 Math::toGrid(const Vector3& v, float grid)
{
	const Vector3 steps(grid, grid, grid);

	return toGrid(v, steps);
}

// FUNCTION: WEBSERVICE 0x100dfc50
// FUNCTION: ROBLOX 0x005f1090
CoordinateFrame Math::snapToGrid(const CoordinateFrame& snap, float grid)
{
	const Vector3 steps(grid, grid, grid);
	const Vector3 translation = toGrid(snap.translation, steps);

	return CoordinateFrame(snapToAxes(snap.rotation), translation);
}

// FUNCTION: WEBSERVICE 0x100dfcc0
// FUNCTION: ROBLOX 0x005f1100
CoordinateFrame Math::snapToGrid(const CoordinateFrame& snap, const Vector3& grid)
{
	return CoordinateFrame(snapToAxes(snap.rotation), toGrid(snap.translation, grid));
}

// STUB: WEBSERVICE 0x100dfd20
// STUB: ROBLOX 0x005f1160
bool Math::fuzzyAxisAligned(const Matrix3& m0, const Matrix3& m1, float radTolerance)
{
	Vector3 a1[3];

	for (int i = 0; i < 3; ++i) {
		a1[i] = m1.getColumn(i);
	}

	for (int i = 0; i < 3; ++i) {
		Vector3 a0 = m0.getColumn(i);

		bool found = false;

		for (int j = 0; j < 3; ++j) {
			if (a0.cross(a1[j]).magnitude() < radTolerance) {
				found = true;
				break;
			}
		}

		if (!found) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100dfe20
// FUNCTION: ROBLOX 0x005f1260
bool Math::orthonormalizeIfNecessary(Matrix3& m)
{
	if (!m.isOrthonormal()) {
		m.orthonormalize();
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100dfe40
// FUNCTION: ROBLOX 0x005f1280
Vector3 Math::sortVector3(const Vector3& v)
{
	Vector3 sorted = v;

	if (sorted.z < sorted.y) {
		std::swap(sorted.z, sorted.y);
	}
	if (sorted.y < sorted.x) {
		std::swap(sorted.y, sorted.x);
	}
	if (sorted.z < sorted.y) {
		std::swap(sorted.z, sorted.y);
	}

	return sorted;
}

// FUNCTION: WEBSERVICE 0x100dfea0
// FUNCTION: ROBLOX 0x005f12e0
float Math::maxAxisLength(const Vector3& v)
{
	const float answer[3] = {fabsf(v.x), fabsf(v.y), fabsf(v.z)};

	return std::max(answer[0], std::max(answer[1], answer[2]));
}

// FUNCTION: ROBLOX 0x005f1330
Vector3 Math::closestPointOnRay(const Ray& p_unk0x08, const Ray& p_unk0x0c)
{
	Vector3 pa = p_unk0x08.origin;
	Vector3 pb = p_unk0x0c.origin;
	Vector3 ua = p_unk0x08.direction;
	Vector3 ub = p_unk0x0c.direction;
	Vector3 p = pb - pa;
	float uaub = ua.dot(ub);
	float q1 = ua.dot(p);
	float q2 = -ub.dot(p);
	float d = 1.0f - uaub * uaub;
	if (d > 0.00001) {
		float alpha = (q1 + uaub * q2) / d;
		return pa + ua * alpha;
	}
	return pa;
}

// FUNCTION: WEBSERVICE 0x100dfef0
// FUNCTION: ROBLOX 0x005f1440
bool Math::intersectRayPlane(const Ray& ray, const Plane& plane, Vector3& hit)
{
	const float dotProd = ray.direction.dot(plane.normal());

	if (plane.halfSpaceContains(ray.origin) ? dotProd < 0.0f : dotProd > 0.0f) {
		const G3D::Line line = G3D::Line::fromPointAndDirection(ray.origin, ray.direction);

		hit = line.intersection(plane);

		return true;
	}

	hit = Vector3::inf();

	return false;
}

} // namespace RBX
