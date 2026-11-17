// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boundfunc-call3 /I{headers}/std-noinline-string
// 2008-06 native BoundFuncDesc<DHTMLWindow, void(shared_ptr<Instance>, string, string), 3>::execute 0041c610 (inactive): the
// "Bind" descriptor's execute with the separate call<void> 0041c560 (boundfunc-call3 overlay of reflection/reflection.h).
#include "AppLeaves2008/DHTMLWindow2008.h"

namespace RBX
{
	namespace Reflection
	{
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

		template void BoundFuncDesc<DHTMLWindow, void(boost::shared_ptr<Instance>, std::string, std::string), 3>::execute(DescribedBase*, Arguments&) const;
	}
}
