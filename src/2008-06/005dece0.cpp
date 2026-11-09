// from server: 100% by auto
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
bool Math::isDenormal(float f)
{
	const int bits = *reinterpret_cast<const int*>(&f);
	return (bits & 0x7f800000) == 0 && (bits & 0x7fffff) != 0;
}

// FUNCTION: WEBSERVICE 0x100de880
bool Math::isNanInfDenorm(float f)
{
	return f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() ||
		   f == std::numeric_limits<float>::quiet_NaN() || f == std::numeric_limits<float>::signaling_NaN() ||
		   isDenormal(f);
}

// FUNCTION: WEBSERVICE 0x100de8e0
bool Math::isNanInfDenormVector3(const Vector3& v)
{
	return isNanInfDenorm(v.x) || isNanInfDenorm(v.y) || isNanInfDenorm(v.z);
}

// FUNCTION: WEBSERVICE 0x100de930
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

// STUB: WEBSERVICE 0x100de9a0
bool Math::legalCameraCoord(const CoordinateFrame& c)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			const float value = c.rotation[i][j];

			if (value <= -1.2f) {
				return false;
			}
			if (value >= 1.2f) {
				return false;
			}
		}

		const float value = c.translation[i];

		if (value <= -1000000.0f) {
			return false;
		}
		if (value >= 1000000.0f) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100dea30
float Math::rotationFromByte(unsigned char byteAngle)
{
	const float value = byteAngle;

	return value * rotationStep() - 3.14159274f;
}

// STUB: WEBSERVICE 0x100dea70
Matrix3 Math::getIWorldAtPoint(const Vector3& cofmPos, const Vector3& worldPos, const Matrix3& iWorldAtCofm, float mass)
{
	const float x = worldPos.x - cofmPos.x;
	const float y = worldPos.y - cofmPos.y;
	const float z = worldPos.z - cofmPos.z;

	return iWorldAtCofm + mass * Matrix3(
									 z * z + y * y,
									 -(y * x),
									 -(z * x),
									 -(y * x),
									 z * z + x * x,
									 -(z * y),
									 -(z * x),
									 -(z * y),
									 y * y + x * x
								 );
}

// FUNCTION: WEBSERVICE 0x100deb30
Matrix3 Math::momentToObjectSpace(const Matrix3& iWorld, const Matrix3& bodyRotation)
{
	return bodyRotation.transpose() * iWorld * bodyRotation;
}

// FUNCTION: WEBSERVICE 0x100deb70
Matrix3 Math::momentToWorldSpace(const Matrix3& iBody, const Matrix3& bodyRotation)
{
	return bodyRotation * iBody * bodyRotation.transpose();
}

// FUNCTION: WEBSERVICE 0x100debb0
Vector3 Math::toDiagonal(const Matrix3& m)
{
	return Vector3(m[0][0], m[1][1], m[2][2]);
}

// FUNCTION: WEBSERVICE 0x100debd0
Matrix3 Math::fromDiagonal(const Vector3& v)
{
	return Matrix3(v.x, 0.0f, 0.0f, 0.0f, v.y, 0.0f, 0.0f, 0.0f, v.z);
}

// FUNCTION: WEBSERVICE 0x100dec20
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
int Math::getOrientId(const Matrix3& matrix)
{
	const NormalId x = Vector3ToNormalId(matrix.getColumn(0));
	const NormalId y = Vector3ToNormalId(matrix.getColumn(1));

	return x * 6 + y;
}

// FUNCTION: WEBSERVICE 0x100dece0
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
Matrix3 Math::snapToAxes(const Matrix3& align)
{
	float dots[3][3];

	float tBest = 0.0f;
	int aBest = -1;
	int best = -1;

	for (int a = 0; a < 3; ++a) {
		Vector3 aAxis = align.getColumn(a);

		for (int i = 0; i < 3; ++i) {
			float t = Matrix3::identity().getColumn(i).dot(aAxis);

			dots[a][i] = t;

			if (fabs(t) > fabs(tBest)) {
				best = i;
				tBest = t;
				aBest = a;
			}
		}
	}

	Vector3 bestV = Matrix3::identity().getColumn(best);

	if (tBest < 0.0f) {
		bestV.x = bestV.x * -1.0f;
		bestV.y = bestV.y * -1.0f;
		bestV.z = bestV.z * -1.0f;
	}

	float tSecond = 0.0f;
	int aSecond = -1;
	int second = -1;

	for (int a = 0; a < 3; ++a) {
		if (a != aBest) {
			for (int i = 0; i < 3; ++i) {
				if (i != best && fabs(dots[a][i]) > fabs(tSecond)) {
					tSecond = dots[a][i];
					second = i;
					aSecond = a;
				}
			}
		}
	}

	Vector3 secondV = Matrix3::identity().getColumn(second);

	if (tSecond < 0.0f) {
		secondV.x = secondV.x * -1.0f;
		secondV.y = secondV.y * -1.0f;
		secondV.z = secondV.z * -1.0f;
	}

	int aThird = (3 - aSecond) - aBest;
	int third = (3 - second) - best;

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
Vector3 Math::iRoundVector3(const Vector3& point)
{
	return Vector3(
		static_cast<float>(G3D::iRound(point.x)),
		static_cast<float>(G3D::iRound(point.y)),
		static_cast<float>(G3D::iRound(point.z))
	);
}

// FUNCTION: WEBSERVICE 0x100df100
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

// FUNCTION: WEBSERVICE 0x100df1a0
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
bool Math::fuzzyEq(const CoordinateFrame& c0, const CoordinateFrame& c1, float epsT, float epsR)
{
	if (!fuzzyEq(c0.translation, c1.translation, epsT)) {
		return false;
	}

	return fuzzyEq(c0.rotation, c1.rotation, epsR) ? true : false;
}

// STUB: WEBSERVICE 0x100df2c0
Matrix3 Math::alignAxesClosest(const Matrix3& align, const Matrix3& target)
{
	float dots[3][3];

	float tBest = 0.0f;
	int aBest = -1;
	int best = -1;

	for (int a = 0; a < 3; ++a) {
		Vector3 aAxis = align.getColumn(a);

		for (int i = 0; i < 3; ++i) {
			Vector3 tAxis = target.getColumn(i);

			float t = tAxis.dot(aAxis);

			dots[a][i] = t;

			if (fabs(t) > fabs(tBest)) {
				best = i;
				aBest = a;
				tBest = t;
			}
		}
	}

	Vector3 bestV = align.getColumn(aBest) * Math::sign(tBest);

	float tSecond = 0.0f;
	int aSecond = -1;
	int second = -1;

	for (int a = 0; a < 3; ++a) {
		if (a != aBest) {
			for (int i = 0; i < 3; ++i) {
				if (i != best && fabs(dots[a][i]) > fabs(tSecond)) {
					tSecond = dots[a][i];
					second = i;
					aSecond = a;
				}
			}
		}
	}

	Vector3 secondV = align.getColumn(aSecond) * Math::sign(tSecond);

	int aThird = (3 - aSecond) - aBest;
	int third = (3 - second) - best;

	Vector3 thirdV = align.getColumn(aThird) * Math::sign(dots[aThird][third]);

	Matrix3 answer;

	answer.setColumn(best, bestV);
	answer.setColumn(second, secondV);
	answer.setColumn(third, thirdV);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100df530
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
Vector3 Math::vector3Abs(const Vector3& v)
{
	return Vector3(fabsf(v.x), fabsf(v.y), fabsf(v.z));
}

// FUNCTION: WEBSERVICE 0x100df620
float Math::getHeading(const Vector3& look)
{
	return atan2f(-look.x, -look.z);
}

// STUB: WEBSERVICE 0x100df630
void Math::getHeadingElevation(const CoordinateFrame& c, float& heading, float& elevation)
{
	const Vector3 look = c.rotation.getColumn(2) * CoordinateFrame::zLookDirection;

	heading = atan2f(-look.x, -look.z);
	elevation = asinf(look.y);
}

// FUNCTION: WEBSERVICE 0x100df690
void Math::setHeadingElevation(CoordinateFrame& c, float heading, float elevation)
{
	const float y = sinf(elevation);
	const float flat = sqrtf(1.0f - y * y);
	const Vector3 look(-sinf(heading) * flat, y, -cosf(heading) * flat);

	c.lookAt(c.translation + look.direction());
}

// FUNCTION: WEBSERVICE 0x100df710
void Math::rotateMatrixAboutY90(Matrix3& matrix, int times)
{
	static const Matrix3 y90(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	for (int i = 0; i < times; ++i) {
		matrix = y90 * matrix;
	}
}

// FUNCTION: WEBSERVICE 0x100df7d0
const Matrix3& Math::matrixRotateY()
{
	static const Matrix3 m(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	return m;
}

// FUNCTION: WEBSERVICE 0x100df860
const Matrix3& Math::matrixTiltZ()
{
	static const Matrix3 m(0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	return m;
}

// STUB: WEBSERVICE 0x100df8e0
const Matrix3& Math::getAxisRotationMatrix(int face)
{
	static const Matrix3 y = Matrix3::fromEulerAnglesXYZ(0.0f, 0.0f, 1.57079637f);
	static const Matrix3 z = Matrix3::fromEulerAnglesXYZ(0.0f, 1.57079637f, 0.0f);
	static const Matrix3 y_neg = y;
	static const Matrix3 z_neg = z;

	switch (face) {
	case NORM_X:
	case NORM_X_NEG:
		break;
	case NORM_Y:
		return y;
	case NORM_Z:
		return z;
	case NORM_Y_NEG:
		return y_neg;
	case NORM_Z_NEG:
		return z_neg;
	}

	return Matrix3::identity();
}

// STUB: WEBSERVICE 0x100dfa70
CoordinateFrame Math::getFocusSpace(const CoordinateFrame& focus)
{
	const Vector3 look = focus.rotation.getColumn(2) * CoordinateFrame::zLookDirection;
	const float heading = atan2f(-look.x, -look.z);

	CoordinateFrame answer = focus;
	setHeadingElevation(answer, heading, 0.0f);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100dfaf0
unsigned char rotationToByteBase(float angle)
{
	const float fAngle = (angle + 3.14159274f) / rotationStep();
	int iAngle = G3D::iRound(fAngle);

	iAngle = std::max(0, iAngle);

	return static_cast<unsigned char>(std::min(255, iAngle));
}

// FUNCTION: WEBSERVICE 0x100dfb70
unsigned char Math::rotationToByte(float angle)
{
	return rotationToByteBase(angle);
}

// FUNCTION: WEBSERVICE 0x100dfb90
Vector3 Math::toGrid(const Vector3& v, const Vector3& grid)
{
	const Vector3 units = v / grid;

	return grid * iRoundVector3(units);
}

// FUNCTION: WEBSERVICE 0x100dfc10
Vector3 Math::toGrid(const Vector3& v, float grid)
{
	const Vector3 steps(grid, grid, grid);

	return toGrid(v, steps);
}

// FUNCTION: WEBSERVICE 0x100dfc50
CoordinateFrame Math::snapToGrid(const CoordinateFrame& snap, float grid)
{
	const Vector3 steps(grid, grid, grid);
	const Vector3 translation = toGrid(snap.translation, steps);

	return CoordinateFrame(snapToAxes(snap.rotation), translation);
}

// FUNCTION: WEBSERVICE 0x100dfcc0
CoordinateFrame Math::snapToGrid(const CoordinateFrame& snap, const Vector3& grid)
{
	return CoordinateFrame(snapToAxes(snap.rotation), toGrid(snap.translation, grid));
}

// STUB: WEBSERVICE 0x100dfd20
bool Math::fuzzyAxisAligned(const Matrix3& m0, const Matrix3& m1, float radTolerance)
{
	Vector3 a1[3];

	for (int i = 0; i < 3; ++i) {
		a1[i] = m1.getColumn(i);
	}

	for (int i = 0; i < 3; ++i) {
		const Vector3 a0 = m0.getColumn(i);

		int j;

		for (j = 0; j < 3; ++j) {
			if (a0.cross(a1[j]).magnitude() < radTolerance) {
				break;
			}
		}

		if (j == 3) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100dfe20
bool Math::orthonormalizeIfNecessary(Matrix3& m)
{
	if (!m.isOrthonormal()) {
		m.orthonormalize();
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100dfe40
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
float Math::maxAxisLength(const Vector3& v)
{
	const float answer[3] = {fabsf(v.x), fabsf(v.y), fabsf(v.z)};

	return std::max(answer[0], std::max(answer[1], answer[2]));
}

// FUNCTION: WEBSERVICE 0x100dfef0
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
