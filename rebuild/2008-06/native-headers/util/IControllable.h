#pragma once

namespace RBX
{
	class __declspec(novtable) IControllable
	{
	public:
		IControllable()
		{
		}
		virtual ~IControllable()
		{
		}

	public:
		virtual bool isControllable() const = 0;
	};
}
// 2008-06 native header port of rbxgs App/include/util/IControllable.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
