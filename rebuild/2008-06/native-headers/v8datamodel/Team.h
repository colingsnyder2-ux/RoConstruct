#pragma once
// >>> native-status (generated) -- do not edit >>>
// Team | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 050be389 | roc native-status --write
// 2008-06 native RBX::Team (inactive). Shape after the donor tools/rbxgs Team.h; every field,
// virtual and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 0082ea84 .?AVTeam@RBX@@ -> DescribedCreatable<Team, Instance, sTeam>
//              (21 bases; name mangled $1?sTeam@2@3QBDB, i.e. a const char array).
//   size       0x13c: Instance is 0x130; constructor 005665e0 stores +0x130 (int 0),
//              +0x134 (BrickColor 194, then 1 after setName), +0x138/+0x139 (bool 1, 1).
//   vtable     slot 2 askAddChild 00565ff0 (return true), slot 3 askSetParent 00565e00
//              (dynamic_cast to the Teams type descriptor 009455e0).
//   descriptors (dynamic initializers 007f3240..007f3300, "Data" category 00822490):
//              prop_Score 009748cc (PropDescriptor<Team,int>, getter 00565e30, setter 005666d0),
//              prop_Color 00974904 ("TeamColor", 00565e40 / 00566700),
//              prop_AutoAssignable 009748b0 (00565e50 / 00566720),
//              prop_AutoColorCharacters 009748e8 (BoundProp<bool,1>, member +0x139).
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
