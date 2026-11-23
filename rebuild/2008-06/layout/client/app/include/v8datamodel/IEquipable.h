// =============================================================================
// IEquipable.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/IEquipable.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/shared_ptr.hpp>
#include <G3D/CoordinateFrame.h>
#include <string>

namespace RBX
{
	class Weld;
	class PartInstance;
	class Workspace;

	class __declspec(novtable) IEquipable
	{
	protected:
		boost::shared_ptr<Weld> weld;
		Workspace* workspace;

	protected:
		void buildWeld(
			PartInstance* humanoidPart,
			PartInstance* gadgetPart,
			const G3D::CoordinateFrame& humanoidCoord,
			const G3D::CoordinateFrame& gadgetCoord,
			const std::string& name);
	protected:
		IEquipable();
		virtual ~IEquipable();
	};
}
