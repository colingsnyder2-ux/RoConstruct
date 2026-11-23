// =============================================================================
// Vector3int32.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Vector3int32.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Vector3.h>

namespace RBX
{
	class Vector3int32
	{
	public:
		int x;
		int y;
		int z;

	public:
		Vector3int32() : x(0), y(0), z(0) {}
		Vector3int32(int x, int y, int z) : x(x), y(y), z(z) {}

	public:
		int& operator[](int i) { return ((int*)this)[i]; }
		const int& operator[](int i) const { return ((int*)this)[i]; }

		Vector3int32 operator+(const Vector3int32& other) const
		{
			return Vector3int32(
				this->x + other.x,
				this->y + other.y,
				this->z + other.z
			);
		}

		bool operator==(const Vector3int32& other) const
		{
			return
				this->x == other.x &&
				this->y == other.y &&
				this->z == other.z;
		}

		bool operator!=(const Vector3int32& other) const
		{
			return
				this->x != other.x ||
				this->y != other.y ||
				this->z != other.z;
		}

		G3D::Vector3 toVector3() const { return G3D::Vector3((float)x, (float)y, (float)z); }

		static Vector3int32 floor(const G3D::Vector3& v)
		{
			return Vector3int32(
				(int)std::floor(v.x),
				(int)std::floor(v.y),
				(int)std::floor(v.z)
			);
		}
	};
}
