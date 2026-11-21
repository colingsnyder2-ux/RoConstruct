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
