#pragma once
#include "v8datamodel/Tool.h"
#include "v8datamodel/BrickColor.h"
#include <boost/signals/connection.hpp>

struct NativeFlagFamilyLayout;

namespace RBX
{
	class TimerService;

	namespace Network
	{
		class Player;
	}

	extern const char sFlag[];

	class Flag : public DescribedCreatable<Flag, Tool, sFlag>
	{
		friend struct ::NativeFlagFamilyLayout;

		enum FlagState
		{
			NOTHING,
			LOOSE,
			IN_STAND,
			EQUIPPED
		};

	private:
		boost::shared_ptr<Instance> evilClone;              // +0x268
		FlagState state;                                    // +0x270 (donor; not accessed in 2008-06)
		boost::signals::scoped_connection flagTouched;      // +0x274
		TimerService* timer;                                // +0x288

	public:
		BrickColor teamColor;                               // +0x28c

	private:
		void onEvent_flagTouched(boost::shared_ptr<Instance>);
		void doUglyPeriodicCloneHack();                     // 00618f70

	protected:
		virtual bool canUnequip()
		{
			return false;
		}

		virtual bool canBePickedUpByPlayer(Network::Player* p); // 00618390

	public:
		BrickColor getTeamColor() const;                    // 00618380
		void setTeamColor(BrickColor color);                // 00619a60
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*); // 006194a0 (by body shape; not attempted)
		Flag();                                             // 00619820
		virtual ~Flag();                                    // 00618670
		virtual void onChildAdded(Instance* instance);      // 00619970 (by body shape; not attempted)
	};
}
