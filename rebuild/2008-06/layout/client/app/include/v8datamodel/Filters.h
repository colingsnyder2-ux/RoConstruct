// =============================================================================
// Filters.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Filters.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "util/HitTestFilter.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include <boost/shared_ptr.hpp>

namespace RBX
{
	class Unlocked : public HitTestFilter
	{
	public:
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const
		{
			return unlocked(testMe) ? HitTestFilter::INCLUDE_PRIM : HitTestFilter::STOP_TEST;
		}

		static bool unlocked(const Primitive* testMe);
	};

	class PartByLocalCharacter : public HitTestFilter
	{
	protected:
		boost::shared_ptr<ModelInstance> character;
		boost::shared_ptr<PartInstance> head;

	public:
		PartByLocalCharacter(Instance* root);
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;
	};

	class UnlockedPartByLocalCharacter : public PartByLocalCharacter
	{
	public:
		UnlockedPartByLocalCharacter(Instance*);
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;
	};
}
