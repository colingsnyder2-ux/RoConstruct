// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Service.h"

namespace RBX
{
	boost::shared_ptr<Instance> ServiceProvider::findServiceByClassName(const Name& className) const
	{
		std::map<const Name*, boost::shared_ptr<Instance> >::const_iterator it = serviceMap.find(&className);
		if (it != serviceMap.end())
			return it->second;

		return boost::shared_ptr<Instance>();
	}
}
