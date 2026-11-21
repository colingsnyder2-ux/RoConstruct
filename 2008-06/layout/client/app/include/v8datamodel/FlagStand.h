#pragma once
#include "v8datamodel/PartInstance.h"
#include <boost/signals/connection.hpp>

struct NativeFlagFamilyLayout;

namespace RBX
{
	class Flag;

	extern char sFlagStand[];

	class FlagStand : public DescribedCreatable<FlagStand, PartInstance, sFlagStand>
	{
		friend struct ::NativeFlagFamilyLayout; // tests/NativeFlagFamilyLayout.cpp offset asserts (pending PartInstance)

	private:
		boost::signals::scoped_connection standTouched;     // +0x3e8

	public:
		BrickColor teamColor;                               // +0x3fc

	private:
		void onEvent_standTouched(boost::shared_ptr<Instance>);

	public:
		FlagStand();                                        // 0062c9c0

		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);

		void AffixFlag(Flag* flag);                         // 0062bdc0 (calls Tool::getHandle 005fd760)
		Flag* GetFlag();                                    // 0062b900 (embedded Primitive +0x228, dynamic_cast<Flag*>)
		BrickColor getTeamColor() const;                    // 0062b8f0
		void setTeamColor(BrickColor color);                // 0062cdc0
	};
}
