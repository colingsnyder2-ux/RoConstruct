// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boundfunc-call3 /I{headers}/std-noinline-string
// 2008-06 native BoundFuncDesc<DataModel, std::string(std::string, std::string, bool), 3> (inactive): the descriptor type
// of the DataModel.cpp static "HttpPost" (initializer 007f3570: this 00975158, &DataModel::httpPost 0057be10 with a zero
// adjustor, "HttpPost" 0083047c, "url" 0080f08c, "data" 00827a04, "synchronous" 00830470, default3 false, security 4;
// atexit 007fd4f0). Identity: the constructor's vtable 00830080 has the RTTI type descriptor
// .?AV?$BoundFuncDesc@VDataModel@RBX@@$$A6A?AV?$basic_string@...@V34@0_N@Z$02@Reflection@RBX@@; slot 1 is execute
// 005797b0, which calls call<std::string> 005796d0 (the boundfunc-call3 overlay's separate call member).
// The static itself is not defined here: core v8datamodel/DataModel.h declares no DataModel::httpPost.
#include "v8datamodel/DataModel.h"
#include "reflection/reflection.h"
#include <string>

namespace RBX
{
	namespace Reflection
	{
		// 00579600 (ret 0x20): the 3-argument constructor with a default for the last argument (reflection/reflection.h
		// declares it without a body): FuncDesc<DataModel> (classDescriptor 005788c0, FunctionDescriptor 00595790), the
		// 8-byte member pointer at +0x38, default1/default2 Value() (00594ac0) at +0x40/+0x48, default3 Value(bool) at
		// +0x50 (Type::singleton<bool> 0056cc30, new holder<bool>), then declareSignature 00575460.
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 3>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 3>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			const char* arg3Name,
			typename BoundFuncDesc<Class, Function, 3>::Arg3 default3,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2(),
			  default3(default3)
		{
			declareSignature(arg1Name, arg2Name, arg3Name);
		}

		// 00575460 (thiscall, ret 0xc; called only by the constructor 00579600): resultType = Type::singleton<std::string>
		// 0056cdf0 into signature +0x14, then three SignatureDescriptor::addArgument 00594b40 calls with
		// Name::declare(argName, -1) 00553f90 and Type::singleton<std::string> / <std::string> / <bool> 0056cc30 against
		// default1 +0x40 / default2 +0x48 / default3 +0x50. reflection/reflection.h declares it without a body; the same
		// template body is in AppLeaves2008DHTMLWindow.cpp for its own instantiation.
		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 3>::declareSignature(const char* arg1Name, const char* arg2Name, const char* arg3Name)
		{
			signature.resultType = &Type::singleton<typename result_type>();
			signature.addArgument(Name::declare(arg1Name, -1), Type::singleton<typename Arg1>(), default1);
			signature.addArgument(Name::declare(arg2Name, -1), Type::singleton<typename Arg2>(), default2);
			signature.addArgument(Name::declare(arg3Name, -1), Type::singleton<typename Arg3>(), default3);
		}

		// 005797b0 (vtable 00830080 slot 1): the arguments copied from the defaults and fetched by index, the
		// dynamic_cast to DataModel (bad_cast when null), then call<std::string> 005796d0.
		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 3>::execute(DescribedBase* instance, Arguments& arguments) const
		{
			Value arg1 = default1;
			arguments.get(1, arg1);
			Value arg2 = default2;
			arguments.get(2, arg2);
			Value arg3 = default3;
			arguments.get(3, arg3);

			Class* o = dynamic_cast<Class*>(instance);
			if (!o)
				throw std::bad_cast();

			call<typename result_type>(o, arguments.returnValue, arg1, arg2, arg3);
		}

		template class BoundFuncDesc<DataModel, std::string(std::string, std::string, bool), 3>;
	}
}
