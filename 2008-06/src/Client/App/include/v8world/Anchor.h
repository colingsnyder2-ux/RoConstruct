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
