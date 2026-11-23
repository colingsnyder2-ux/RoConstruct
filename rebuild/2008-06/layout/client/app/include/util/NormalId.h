// =============================================================================
// NormalId.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/NormalId.h
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
	enum NormalId
	{
		NORM_X = 0,
		NORM_Y = 1,
		NORM_Z = 2,
		NORM_X_NEG = 3,
		NORM_Y_NEG = 4,
		NORM_Z_NEG = 5,
		NORM_UNDEFINED = 6,
	};

	RBX::NormalId normalIdOpposite(RBX::NormalId normalId);
	bool validNormalId(NormalId normalId);

	NormalId Vector3ToNormalId(const G3D::Vector3& v);
	NormalId Matrix3ToNormalId(const G3D::Matrix3& m);
	NormalId intToNormalId(int num);

	NormalId normalIdToU(NormalId id);
	NormalId normalIdToV(NormalId id);

	const G3D::Vector3& normalIdToVector3(NormalId normalId);
	const G3D::Matrix3& normalIdToMatrix3(NormalId normalId);

	G3D::Matrix3 normalIdToMatrix3Internal(NormalId normalId);

	G3D::Vector3 uvwToObject(const G3D::Vector3& uvwPt, NormalId faceId);

	template<NormalId faceId>
	G3D::Vector3 uvwToObject(const G3D::Vector3& v);

	G3D::Vector3 objectToUvw(const G3D::Vector3& objectPt, NormalId faceId);
	G3D::Vector3 mapToUvw_Legacy(const G3D::Vector3& ptInObject, NormalId faceId);
}
