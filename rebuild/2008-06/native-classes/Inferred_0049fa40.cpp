// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0049fa40 (placeholder name for 0049fa40 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/any.hpp>
#include "util/Name.h"
#include "AppLeaves2008/DHTMLWindowService2008.h"

namespace RBX
{
	struct SignalArgsReceiver
	{
		virtual ~SignalArgsReceiver();
		virtual void raise(const std::vector<boost::any>& arguments);
	};

	struct SignalArgsOwner
	{
		SignalArgsReceiver* receiver;
	};

	void __fastcall sub_0049fa40(SignalArgsOwner* self, int /*edx*/, std::string a, int b, std::string c)
	{
		std::vector<boost::any> arguments(3);
		arguments[0] = a;
		arguments[1] = b;
		arguments[2] = c;
		self->receiver->raise(arguments);
	}
}
