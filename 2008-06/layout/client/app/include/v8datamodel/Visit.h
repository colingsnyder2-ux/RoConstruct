// =============================================================================
// Visit.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Visit.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "v8tree/Service.h"

namespace RBX
{
	extern char sVisit[];

	class Visit : public DescribedCreatable<Visit, Instance, sVisit>, public Service
	{
	private:
		std::string uploadUrl;
		boost::scoped_ptr<worker_thread> pingThread;

	public:
		Visit();
		virtual ~Visit();
		void setPing(std::string url, int interval);

		void setUploadUrl(std::string value)
		{
			uploadUrl = value;
		}

		std::string getUploadUrl()
		{
			return uploadUrl;
		}

		virtual XmlElement* write()
		{
			return NULL;
		}

	public:
		static worker_thread::work_result ping(std::string url, int interval);
	};
}
