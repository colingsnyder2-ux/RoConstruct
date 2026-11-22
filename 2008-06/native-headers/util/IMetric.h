#pragma once
#include <string>

namespace RBX
{
	class IMetric
	{
	public:
		IMetric()
		{
		}
		virtual ~IMetric()
		{
		}
	public:
		virtual std::string getMetric(const std::string&) const = 0;
	};
}
// 2008-06 native header port of rbxgs App/include/util/IMetric.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
