// =============================================================================
// GuidItem.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/GuidItem.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "util/Guid.h"

namespace RBX
{
template<class T>
class __declspec(novtable) GuidItem {
public:
	GuidItem() : registeredGuid(false) {}
	~GuidItem();
	void registerGuid();
	// INFERRED: Replicator item writers 004b47b0/004b8620/004b6d10 read the guid inline (`lea ecx,[instance+8]`)
	const Guid& getGuid() const { return guid; }
protected:
	virtual void onGuidChanged() {}
	bool registeredGuid;
	Guid guid;
	public:
		void sub_004b3dd0(const RBX::Guid::Data& data);   // INFERRED: 004b3dd0, placeholder name (identity tier), body byte-proved (Inferred_004b3dd0.cpp)
};
}
