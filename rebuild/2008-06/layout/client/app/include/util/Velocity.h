// =============================================================================
// Velocity.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Velocity.h
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
#include <G3D/Matrix3.h>

namespace RBX
{
	class Velocity
	{
		public:
			G3D::Vector3 linear;
			G3D::Vector3 rotational;
			bool operator==(const Velocity&) const;
			bool operator!=(const Velocity&) const;
			Velocity(const G3D::Vector3& _linear, const G3D::Vector3& _rotational) : linear(_linear), rotational(_rotational) {}
			Velocity():linear(G3D::Vector3::zero()),rotational(G3D::Vector3::zero()) {}
			Velocity operator+(const Velocity&) const;
			Velocity operator-() const;
			G3D::Vector3 linearVelocityAtOffset(const G3D::Vector3& vec3) const
			{
				return this->linear + this->rotational.cross(vec3);
			}
			Velocity velocityAtOffset(const G3D::Vector3&) const;
			Velocity rotateBy(const G3D::Matrix3&) const;

			static const Velocity& zero()
			{
				static Velocity v;
				return v;
			}
	};
}
