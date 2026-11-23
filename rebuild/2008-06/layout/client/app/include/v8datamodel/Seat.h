// =============================================================================
// Seat.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Seat.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
