// =============================================================================
// Units.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Units.h
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
	class Units
	{
		public:
			static float mPerRbx();
			static float rbxPerM();
			static float rbxPerMM();
			static G3D::Vector3 kmsVelocityToRbx(const G3D::Vector3&);
			static G3D::Vector3 kmsAccelerationToRbx(const G3D::Vector3& kmsAccel);
			static G3D::Vector3 kmsForceToRbx(const G3D::Vector3&);
			static float kmsForceToRbx(float);
			static G3D::Vector3 kmsTorqueToRbx(const G3D::Vector3&);
			static float kmsDensityToRbx(float);
			static G3D::Vector3 kmsKRotToRbx(const G3D::Vector3&);
			static G3D::Vector3 kmsKRotDampToRbx(const G3D::Vector3&);
	};
}
