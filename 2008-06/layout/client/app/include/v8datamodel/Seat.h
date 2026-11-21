#pragma once
#include "v8datamodel/PartInstance.h"
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>

struct NativeSeatLayout;

namespace RBX
{
	class Weld;
	class Humanoid;

	extern char sSeat[];

	class Seat : public DescribedCreatable<Seat, PartInstance, sSeat>
	{
		friend struct ::NativeSeatLayout; // tests/NativeSeatLayout.cpp offset asserts (pending PartInstance)

	private:
		boost::signals::scoped_connection seatTouched;      // +0x3e8
		boost::signals::scoped_connection humanoidSeated;   // +0x3fc
		double sleepTime;                                   // +0x410 (getLocalTime() when the character left)
		boost::shared_ptr<Weld> weld;                       // +0x418

	private:
		void onEvent_seatTouched(boost::shared_ptr<Instance> other);
		void onEvent_humanoidSeated(bool active);
		void seatCharacter(Humanoid* humanoid);

	public:
		Seat();                                             // 0063d390

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
}
