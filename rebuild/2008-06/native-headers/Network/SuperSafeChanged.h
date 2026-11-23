#pragma once

namespace RBX
{
	class SuperSafeChanged
	{
	public:
		bool superSafeOn;

		SuperSafeChanged(bool on) : superSafeOn(on) {}
	};
}
// 2008-06 native header port of rbxgs Network/include/Network/SuperSafeChanged.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
