#pragma once
#include "v8datamodel/PartInstance.h"
#include <boost/signals/connection.hpp>

struct NativeSpawnLayout;

namespace RBX
{
	extern char sSpawnLocation[];

	class SpawnLocation : public DescribedCreatable<SpawnLocation, PartInstance, sSpawnLocation>
	{
		friend struct ::NativeSpawnLayout; // tests/NativeSpawnLayout.cpp offset asserts (pending PartInstance)

	private:
		BrickColor teamColor;                               // +0x3e8
		boost::signals::scoped_connection spawnerTouched;   // +0x3ec

	public:
		bool neutral;                                       // +0x400
		bool allowTeamChangeOnTouch;                        // +0x401
		int duration;                                       // +0x404 ("Duration", category "Forcefield")

	public:
		static Reflection::BoundProp<int, 1> prop_Duration;
		static Reflection::BoundProp<bool, 1> prop_Neutral;
		static Reflection::BoundProp<bool, 1> prop_AllowTeamChangeOnTouch;

	public:
		SpawnLocation();                                    // 005d3490

		BrickColor getTeamColor() const;                    // 005d1ba0
		void setTeamColor(BrickColor color);                // 005d37b0

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
}
