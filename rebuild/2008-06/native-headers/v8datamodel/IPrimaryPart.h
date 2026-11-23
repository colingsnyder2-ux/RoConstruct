#pragma once

namespace RBX
{
	class PartInstance;
	class __declspec(novtable) IPrimaryPart
	{
	public:
		virtual PartInstance* getPrimaryPart() = 0;
		virtual const PartInstance* getPrimaryPartConst() const = 0;
	};
}
// 2008-06 native header port of rbxgs App/include/v8datamodel/IPrimaryPart.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
