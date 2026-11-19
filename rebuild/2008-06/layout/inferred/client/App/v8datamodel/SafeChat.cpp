#include "GuiHud2008/GuiBuilder2008.h"
#include <boost/thread/once.hpp>
#include <algorithm>

static boost::scoped_ptr<RBX::SafeChat> sing;
static boost::once_flag once_SafeChat_singleton = BOOST_ONCE_INIT;

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
	ChatOption::ChatOption()
	{
	}

	ChatOption::ChatOption(std::string text)
	{
		this->text = text;
	}

	ChatOption::~ChatOption()
	{
		std::for_each(children.begin(), children.end(), &del);
	}

	SafeChat& SafeChat::singleton()
	{
		boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
		return *sing;
	}
}
