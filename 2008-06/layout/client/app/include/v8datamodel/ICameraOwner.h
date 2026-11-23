// =============================================================================
// ICameraOwner.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/ICameraOwner.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <vector>
#include <g3d/gcamera.h>
#include "v8datamodel/Camera.h"
#include "util/Extents.h"

namespace RBX
{
	class Primitive;
	class PartInstance;
	class __declspec(novtable) ICameraOwner
	{
	private:
		std::vector<boost::weak_ptr<PartInstance>> cameraIgnoreParts;

	public:
		ICameraOwner()
		{
		}
		virtual ~ICameraOwner()
		{
		}
	public:
		virtual Camera* getCamera() const = 0;
		virtual const G3D::GCamera& getGCamera() const = 0;
		virtual void cameraMoved() = 0;
		virtual Extents computeCameraOwnerExtents() = 0;
	public:
		void setCameraIgnoreParts(const std::vector<PartInstance*>& _set);
		void setCameraIgnoreParts(PartInstance* _set);
		void clearCameraIgnoreParts()
		{
			cameraIgnoreParts.clear();
		}
		void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives);
	};
}
