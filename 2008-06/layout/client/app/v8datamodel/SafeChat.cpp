// 2008-06 native RBX::SafeChat rows (inactive) of the SafeChat unit (00657c40..00658897; its 00658000.. part is in this
// range) against the read-only gui owner header native-headers/GuiHud2008/GuiBuilder2008.h, which declares ChatOption
// and SafeChat only by the members GuiBuilder reads. Verified by tests/record_native_app_unit658.py.
//   sing                     0097d944: boost::scoped_ptr<SafeChat> (SafeChat_singleton 006587e0 swaps the new object in and
//                            deletes the old one; singleton 00658880 returns *sing)
//   once_SafeChat_singleton  0097d940: the boost::once_flag passed to boost::call_once 00557330
// GuiBuilder2008.h declares the inline SafeChat constructor, loadChatTree, loadChildren, getMessage and the ChatOption
// constructors / destructor (the recorder's proposal, landed).
#include "GuiHud2008/GuiBuilder2008.h"
#include <boost/thread/once.hpp>
#include <algorithm>

static boost::scoped_ptr<RBX::SafeChat> sing;
static boost::once_flag once_SafeChat_singleton = BOOST_ONCE_INIT;

// 006587e0 (the inline SafeChat() constructor calls loadChatTree 00658660; the old object's ~ChatOption is 00658200)
static void SafeChat_singleton()
{
	sing.reset(new RBX::SafeChat());
}

static void del(RBX::ChatOption* c)
{
	delete c;
}

namespace RBX
{
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

	// 00658880
	SafeChat& SafeChat::singleton()
	{
		boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
		return *sing;
	}
}
