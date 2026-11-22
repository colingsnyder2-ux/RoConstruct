#pragma once

namespace RBX
{
	class Primitive;

	class HitTestFilter
	{
	public:
		enum Result
		{
			STOP_TEST,
			IGNORE_PRIM,
			INCLUDE_PRIM
		};

	public:
		virtual Result filterResult(const Primitive* testMe) const = 0;
	};
}
// 2008-06 native header port of rbxgs App/include/util/HitTestFilter.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
