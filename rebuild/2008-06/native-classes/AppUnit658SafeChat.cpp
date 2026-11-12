// 2008-06 native RBX::SafeChat rows (inactive) of the SafeChat unit (00657c40..00658897; its 00658000.. part is in this
// range) against the read-only gui owner header native-headers/GuiHud2008/GuiBuilder2008.h, which declares ChatOption
// and SafeChat only by the members GuiBuilder reads. Verified by tests/record_native_app_unit658.py.
//   sing                     0097d944: boost::scoped_ptr<SafeChat> (SafeChat_singleton 006587e0 swaps the new object in and
//                            deletes the old one; singleton 00658880 returns *sing)
//   once_SafeChat_singleton  0097d940: the boost::once_flag passed to boost::call_once 00557330
// The SafeChat constructor, loadChatTree, loadChildren, getMessage and the ChatOption constructors / destructor are not
// declared by GuiBuilder2008.h; the rows that need them are built only with NATIVE_APPUNIT658_PENDING against a generated
// copy of that header (see the recorder's proposal) and are never counted.
#include "GuiHud2008/GuiBuilder2008.h"
#include <boost/thread/once.hpp>
#ifdef NATIVE_APPUNIT658_PENDING
#include <algorithm>
#endif

static boost::scoped_ptr<RBX::SafeChat> sing;
static boost::once_flag once_SafeChat_singleton = BOOST_ONCE_INIT;

// 006587e0 (needs the declared SafeChat() constructor to call loadChatTree 00658660 and the out-of-line ~ChatOption 00658200;
// without NATIVE_APPUNIT658_PENDING the implicit members make this body differ and it is not counted)
static void SafeChat_singleton()
{
	sing.reset(new RBX::SafeChat());
}

#ifdef NATIVE_APPUNIT658_PENDING
static void del(RBX::ChatOption* c)
{
	delete c;
}
#endif

namespace RBX
{
#ifdef NATIVE_APPUNIT658_PENDING
	// 00658100
	ChatOption::ChatOption()
	{
	}

	// 00658170: the text member is default-constructed (00658149-like call at 006581bd) and then assigned (006581cf)
	ChatOption::ChatOption(std::string text)
	{
		this->text = text;
	}

	// 00658200
	ChatOption::~ChatOption()
	{
		std::for_each(children.begin(), children.end(), &del);
	}
#endif

	// 00658880
	SafeChat& SafeChat::singleton()
	{
		boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
		return *sing;
	}
}
