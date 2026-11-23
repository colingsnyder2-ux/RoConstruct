#pragma once

namespace RBX
{
	class Primitive;

	class Anchor
	{
	private:
		Primitive* primitive;

	public:
		Anchor(Primitive* primitive) : primitive(primitive) {}
		Primitive* getPrimitive()
		{
			return primitive;
		}
	};
}
// 2008-06 native header port of rbxgs App/include/v8world/Anchor.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
