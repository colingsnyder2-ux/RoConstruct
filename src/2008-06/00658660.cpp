// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_safechatprivatepath0e11a464aa6b8fd4.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlSerializer.h", "roc_ldraw_native_parser_prefix66bda9c32708866c.cpp")
#include "v8datamodel/SafeChat.h"
#include "util/ContentProvider.h"
#include "v8xml/XmlSerializer.h"
#include "util/Debug.h"
#include <fstream>
#include <boost/thread/once.hpp>
#include <boost/algorithm/string.hpp>

static const RBX::Name& utterance = RBX::Name::declare("utterance", -1);
static boost::scoped_ptr<RBX::SafeChat> sing;
static boost::once_flag once_SafeChat_singleton = BOOST_ONCE_INIT;

static void SafeChat_singleton()
{
	sing.reset(new RBX::SafeChat());
}

std::string contentPath(const char*);
static __declspec(noinline) std::string getChatTreeFile()
{
	return contentPath("Fonts\\safechat.xml");
}

static void del(RBX::ChatOption* c)
{
	delete c;
}

namespace RBX
{
	ChatOption::ChatOption(std::string text)
		: text(text)
	{
	}

	ChatOption::ChatOption()
	{
	}

	ChatOption::~ChatOption()
	{
		std::for_each(children.begin(), children.end(), &del);
	}

	SafeChat::SafeChat()
	{
		loadChatTree();
	}

	std::string SafeChat::getMessage(std::vector<std::string> code)
	{
		RBXASSERT(chatRoot);
		RBXASSERT(code[0] == "sc");

		ChatOption* currentOption = chatRoot.get();

		for (size_t i = 1; i < code.size(); ++i)
		{
			int iCode = boost::lexical_cast<int>(code[i]);
			if (static_cast<size_t>(iCode) >= currentOption->children.size())
				return "";

			currentOption = currentOption->children[iCode];
		}

		return currentOption->text;
	}

	void SafeChat::loadChatTree()
	{
		std::string chatTreeFile = getChatTreeFile();
		std::ifstream chatTreeStream(chatTreeFile.c_str(), std::ios::in | std::ios::binary);

		TextXmlParser machine(chatTreeStream.rdbuf());
		std::auto_ptr<XmlElement> chatTree = machine.parse();

		chatRoot.reset(new ChatOption());
		chatRoot->text = "ROOT";
		loadChildren(chatRoot.get(), chatTree.get());
	}

	void SafeChat::loadChildren(ChatOption* parentOption, const XmlElement* parentElement)
	{
		for (const XmlElement* element = parentElement->findFirstChildByTag(utterance); element != NULL; element = parentElement->findNextChildWithSameTag(element))
		{
			std::string text;
			bool succeeded = element->getValue(text);
			RBXASSERT(succeeded);

			boost::trim(text);

			ChatOption* option = new ChatOption(text);
			parentOption->children.push_back(option);
			loadChildren(option, element);
		}
	}

	SafeChat& SafeChat::singleton()
	{
		boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
		return *sing;
	}
}
