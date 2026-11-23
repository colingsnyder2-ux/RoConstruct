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
#include <fstream>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>
#include "util/Name.h"
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"

namespace RBX
{
	namespace LDraw2Lua
	{
		std::string resolveMapPath(const char*);   // 0055d0b0
	}
}

// Dynamic initializer of the reference (stored as a pointer in .data 0097d948; read by loadChildren 00658378).
static const RBX::Name& utterance = RBX::Name::declare("utterance", -1);

// 00657c40 (registry placeholder func_00657c40; file-local, result in esi): the SafeChat tree file. INFERRED name: the
// 2007 openrbx analog is the unnamed FUN_00660930 (ContentProvider getAssetFile there; resolveMapPath 0055d0b0 here).
static std::string safeChatFile()
{
	return RBX::LDraw2Lua::resolveMapPath("Fonts\\safechat.xml");   // 0084c1f0
}

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

	// 00658360 (thiscall, ret 8): one ChatOption per <utterance> child, its trimmed text (boost::algorithm::trim:
	// is_space 00657c10 / trim helpers 006582b0), then recursion. Statement shape after the 2007 openrbx
	// SafeChat::loadChildren.
	void SafeChat::loadChildren(ChatOption* parent, const XmlElement* parentElement)
	{
		for (const XmlElement* child = parentElement->findFirstChildByTag(utterance); child != NULL;
			 child = parentElement->findNextChildWithSameTag(child))
		{
			std::string text;
			child->getValue(text);
			boost::algorithm::trim(text);

			ChatOption* option = new ChatOption(text);
			parent->children.push_back(option);
			loadChildren(option, child);
		}
	}

	// 006584e0 (thiscall, ret 0x1c: result pointer and the vector by value): walks the tree by the numeric path
	// components after the first (lexical_cast<int> 005be120); "" (0080b716) when an index is out of range.
	std::string SafeChat::getMessage(std::vector<std::string> code)
	{
		ChatOption* option = chatRoot.get();

		for (unsigned int i = 1; i < code.size(); i++)
		{
			int index = boost::lexical_cast<int>(code[i]);

			if (index >= option->children.size())
				return "";

			option = option->children[index];
		}

		return option->text;
	}

	// 00658660 (thiscall): parses the SafeChat XML (ifstream in|binary 0x21, TextXmlParser 00415350, parse 0058f6c0)
	// into a new root ChatOption named "ROOT" (0084c204).
	void SafeChat::loadChatTree()
	{
		std::string fileName = safeChatFile();
		std::ifstream stream(fileName.c_str(), std::ios_base::in | std::ios_base::binary);
		TextXmlParser parser(stream.rdbuf());
		std::auto_ptr<XmlElement> root = parser.parse();

		chatRoot.reset(new ChatOption());
		chatRoot->text = "ROOT";
		loadChildren(chatRoot.get(), root.get());
	}

	// 00658880
	SafeChat& SafeChat::singleton()
	{
		boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
		return *sing;
	}
}
