// 2008-06 override of tools/rbxgs/Client/App/include/v8datamodel/Visit.h: class names are .data
// char arrays passed directly as template arguments (see native-headers/util/Name.h).
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
