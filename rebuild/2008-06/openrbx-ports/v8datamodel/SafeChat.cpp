#include "v8datamodel/SafeChat.h"

// PORT: omit donor modern-compiler prelude for 2008 MSVC.
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread/once.hpp>
#include <fstream>

static const RBX::Name& utterance = RBX::Name::declare("utterance", -1);

static boost::scoped_ptr<RBX::SafeChat> sing;

static boost::once_flag once_SafeChat_singleton = BOOST_ONCE_INIT;

namespace RBX {

static void deleteChatOption(ChatOption* option)
{
	delete option;
}

// FUNCTION: ROBLOX 0x00660930
static std::string FUN_00660930()
{
	std::string file = ContentProvider::singleton().getAssetFile("Fonts\\safechat.xml");
	return file;
}

// FUNCTION: ROBLOX 0x00660e50
ChatOption::ChatOption()
{
}

// FUNCTION: ROBLOX 0x00660ea0
ChatOption::ChatOption(std::string text)
{
	this->text = text;
}

// FUNCTION: WEBSERVICE 0x10120d60
// FUNCTION: ROBLOX 0x00660f20
ChatOption::~ChatOption()
{
	std::for_each(children.begin(), children.end(), deleteChatOption);
}

// FUNCTION: ROBLOX 0x00661070
// PORT: match 2008 const XML traversal declaration.
void SafeChat::loadChildren(ChatOption* parent, const XmlElement* element)
{
	for (const XmlElement* child = element->findFirstChildByTag(utterance); child != NULL;
		 child = element->findNextChildWithSameTag(child)) {
		std::string text;
		child->getValue(text);
		boost::algorithm::trim(text);

		ChatOption* option = new ChatOption(text);
		parent->children.push_back(option);
		loadChildren(option, const_cast<XmlElement*>(child));
	}
}

// FUNCTION: ROBLOX 0x00661200
std::string SafeChat::getMessage(std::vector<std::string> path)
{
	ChatOption* option = chatRoot.get();

	for (unsigned int i = 1; i < path.size(); i++) {
		int index = boost::lexical_cast<int>(path[i]);

		if (index >= option->children.size()) {
			return "";
		}

		option = option->children[index];
	}

	return option->text;
}

// FUNCTION: ROBLOX 0x00661330
void SafeChat::loadChatTree()
{
	std::string fileName = FUN_00660930();
	std::ifstream stream(fileName.c_str(), std::ios_base::in | std::ios_base::binary);
	TextXmlParser parser(stream.rdbuf());
	std::auto_ptr<XmlElement> root = parser.parse();

	chatRoot.reset(new ChatOption());
	chatRoot->text = "ROOT";
	loadChildren(chatRoot.get(), root.get());
}

SafeChat::SafeChat()
{
	loadChatTree();
}

// FUNCTION: ROBLOX 0x006614b0
static void SafeChat_singleton()
{
	sing.reset(new SafeChat());
}

// FUNCTION: ROBLOX 0x00661550
SafeChat& SafeChat::singleton()
{
	boost::call_once(SafeChat_singleton, once_SafeChat_singleton);
	return *sing;
}

} // namespace RBX
