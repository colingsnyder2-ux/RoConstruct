// =============================================================================
// SafeChat.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/SafeChat.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8xml/XmlElement.h"
#include <boost/scoped_ptr.hpp>
#include <vector>
#include <string>

namespace RBX
{
	class ChatOption
	{
	public:
		std::vector<ChatOption*> children;
		std::string text;

	public:
		ChatOption(std::string text);
		ChatOption();
		~ChatOption();
	};

	class SafeChat
	{
	private:
		boost::scoped_ptr<ChatOption> chatRoot;

	public:
		SafeChat();
		ChatOption* getChatRoot()
		{
			return chatRoot.get();
		}
		std::string getMessage(std::vector<std::string> code);
	private:
		void loadChatTree();
		void saveChatTree();
		void loadChildren(ChatOption* parentOption, const XmlElement* parentElement);

	public:
		static SafeChat& singleton();
	};
}
