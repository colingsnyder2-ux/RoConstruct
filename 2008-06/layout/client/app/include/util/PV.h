// =============================================================================
// PV.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/PV.h
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
#include <G3D/CoordinateFrame.h>
#include "util/Velocity.h"

namespace RBX
{
	class PV
	{
	public:
		G3D::CoordinateFrame position;
		RBX::Velocity velocity;
	public:
		PV(const G3D::CoordinateFrame& _position, const Velocity& _velocity)
			: position(_position),
			  velocity(_velocity)
		{}

		PV(const PV& other)
			: position(other.position),
			  velocity(other.velocity)
		{}

		PV() : position(), velocity() {};
		~PV() {};
	public:
		bool operator==(const PV&) const;
		bool operator!=(const PV&) const;
		PV inverse() const;
		PV toObjectSpace(const PV&) const;
		G3D::Vector3 linearVelocityAtPoint(const G3D::Vector3& pointVec3) const
		{
			return this->velocity.linearVelocityAtOffset(pointVec3 - this->position.translation);
		}
		Velocity velocityAtPoint(const G3D::Vector3& worldPos) const
		{
			G3D::Vector3 v1 = worldPos - this->position.translation;
			G3D::Vector3 v2 = this->velocity.rotational.cross(v1);
			return Velocity(this->velocity.linear + v2, this->velocity.rotational);
		}
		Velocity velocityAtLocalOffset(const G3D::Vector3&) const;
		PV pvAtLocalOffset(const G3D::Vector3& localOffset) const
		{
			G3D::CoordinateFrame cf(G3D::Matrix3::identity(), localOffset);
			return this->pvAtLocalCoord(cf);
		}
		PV pvAtLocalCoord(const G3D::CoordinateFrame& localCoord) const
		{
			G3D::CoordinateFrame worldPos = this->position * localCoord;
			Velocity worldVel = this->velocityAtPoint(worldPos.translation);
			return PV(worldPos, worldVel);
		}
	};
}
