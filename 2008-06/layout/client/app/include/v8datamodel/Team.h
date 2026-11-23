// =============================================================================
// Team.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Team.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"

struct NativeTeamLayout;

namespace RBX
{
	extern const char sTeam[];

	class Team : public DescribedCreatable<Team, Instance, sTeam>
	{
		friend struct ::NativeTeamLayout; // tests/NativeTeamLayout.cpp offset asserts
	protected:
		int score;                 // +0x130
		BrickColor color;          // +0x134
		bool autoAssignable;       // +0x138
		bool autoColorCharacters;  // +0x139

	public:
		static Reflection::BoundProp<bool, 1> prop_AutoColorCharacters;

	public:
		Team();                    // 005665e0
		virtual ~Team() {}         // 00565f90 (deleting 00566170)

		virtual bool askAddChild(const Instance* instance) const
		{
			return true;           // 00565ff0
		}
		virtual bool askSetParent(const Instance* instance) const; // 00565e00

		int getScore() const;                   // 00565e30 (ICF-shared getter)
		void setScore(int newScore);            // 005666d0
		BrickColor getTeamColor() const;        // 00565e40
		void setTeamColor(BrickColor newColor); // 00566700
		bool getAutoAssignable() const;         // 00565e50
		void setAutoAssignable(bool value);     // 00566720
	};
}
