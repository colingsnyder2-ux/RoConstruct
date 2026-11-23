// =============================================================================
// DragUtilities.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/DragUtilities.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include "util/Extents.h"
#include <boost/weak_ptr.hpp>
#include <vector>

namespace RBX
{
	class Primitive;
	class ContactManager;
	class World;
	class Instance;
	class PVInstance;
	class PartInstance;

	class DragUtilities
	{
	private:
		static const G3D::Array<const Primitive*>* toConstPrimitives(const G3D::Array<Primitive*>* primArray)
		{
			return (G3D::Array<const Primitive*>*)primArray;
		}
	public:
		static bool notJoined(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static bool notJoinedToOutsiders(const std::vector<boost::weak_ptr<PartInstance>>&);
		static void unJoinFromOutsiders(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void joinToOutsiders(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void unJoin(const std::vector<boost::weak_ptr<PartInstance>>&);
		static void join(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void unJoinAndSetDragging(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void joinAndStopDragging(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void clean(PartInstance* part);
		static void clean(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void move(const std::vector<boost::weak_ptr<PartInstance>>& parts, G3D::CoordinateFrame from, G3D::CoordinateFrame to);
		static void alignToGrid(PartInstance* part);
		static void moveAndClean(PartInstance* part, const G3D::Vector3& pos);
		static void pvsToParts(const std::vector<PVInstance*>& pvInstances, std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void instancesToParts(const std::vector<Instance*>& instances, std::vector<boost::weak_ptr<PartInstance>>& parts);
		static World* partsToPrimitives(const std::vector<boost::weak_ptr<PartInstance>>& parts, G3D::Array<Primitive*>& primitives);
		static Extents computeExtents(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static bool hitObjectOrPlane(
			const ContactManager& contactManager,
			const G3D::Ray& unitSearchRay,
			const G3D::Array<Primitive*>* ignorePrims,
			G3D::Vector3& hit);
		static bool anyPartAlive(const std::vector<boost::weak_ptr<PartInstance>>& parts);
		static void getPrimitives2(boost::shared_ptr<Instance>, std::vector<Primitive*>&);
		static void getPrimitives(const Instance*, std::vector<Primitive*>&);
		static void getPrimitivesConst(const Instance* instance, std::vector<const Primitive*>& primitives);
	};
}
