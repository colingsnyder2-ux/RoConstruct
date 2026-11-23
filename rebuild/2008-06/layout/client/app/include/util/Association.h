// =============================================================================
// Association.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Association.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <vector>

namespace RBX
{
	// NOTE: this class uses templated functions: add those in manually
	template<typename Associated>
	class Association
	{
	public:
		class Item
		{
		public:
			virtual ~Item();
		};

		template<typename T>
		class TItem : public Item
		{
		public:
			T t;

		public:
			TItem();
		};

	private:
		std::vector<Item*> items;

	public:
		~Association()
		{
			std::vector<Item*>::iterator it = items.begin();
			std::vector<Item*>::iterator end = items.end();

			while(it != end)
			{
				delete (*it);
				it++;
			}
		}

	private:
		static size_t& count();

	public:
		template<typename T>
		bool contains() const;

		template<typename T>
		T& get();

		template<typename T>
		void remove();
	};
}
