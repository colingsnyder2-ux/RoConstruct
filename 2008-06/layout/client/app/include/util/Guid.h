// =============================================================================
// Guid.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Guid.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <string>
#include "util/Name.h"

namespace RBX
{
	class Guid
	{
	public:
		struct Data
		{
		public:
			const RBX::Name* scope;
			int index;

		public:
			bool operator ==(const Data& other) const;
			bool operator >(const Data& other) const;
			bool operator <(const Data& other) const;

			std::string readableString(int scopeLength) const;
		};

	private:
		Data data;

	public:
		Guid();
		~Guid() {}

	public:
		bool operator ==(const Guid& other) const;
		bool operator >(const Guid& other) const;
		bool operator <(const Guid& other) const;

		void assign(Data);
		void extract(Data& data) const
		{
			data = this->data;
		}

		void copyDataFrom(const Guid& guid) // TODO: is this correct?
		{
			this->assign(guid.data);
		}

		std::string readableString(int scopeLength) const;

		Guid& operator =(const Guid&);

		static int compare(const Guid*, const Guid*, const Guid*, const Guid*);
		static int compare(const Guid*, const Guid*);
		static void generateGUID(std::string& result);
	};
}
