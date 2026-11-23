// =============================================================================
// BrickMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/BrickMesh.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "ViewNew/RenderBaseMesh.h"
#include <boost/thread/once.hpp>

namespace RBX
{
	namespace ViewNew
	{
		class BrickMesh : public RenderBase::Mesh
		{
		public:
			static const float normalPerturbation;    // 00826e3c
			static const float bevel;                 // 00826e38 (0.0f; read only by the PBB Face / Side strips)

			struct Cache;
		private:
			static Cache* cache;                      // 00972754
			static boost::once_flag cacheFlag;        // 00972870
			static void initCache();                  // 004e5360
			static void releaseUnused();              // 004e5710
		public:
			static void flushCache();                 // 004e5670
		};
	}
}
