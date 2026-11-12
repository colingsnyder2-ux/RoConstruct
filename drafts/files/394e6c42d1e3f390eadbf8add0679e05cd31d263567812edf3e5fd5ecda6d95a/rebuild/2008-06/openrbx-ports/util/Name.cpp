#include "util/Name.h"

// PORT: decomp size annotations are donor metadata, not 2008 API.

#include <boost/thread/mutex.hpp>
#include <boost/thread/once.hpp>

namespace RBX {

// PORT: omit donor-only size annotation.
// PORT: Name::NamMap is already declared in the 2008 header.

static boost::once_flag flag = BOOST_ONCE_INIT;

// FUNCTION: WEBSERVICE 0x10057ed0
// FUNCTION: ROBLOX 0x005640f0
boost::mutex& moo2()
{
	static boost::mutex mutex2;

	return mutex2;
}

// FUNCTION: WEBSERVICE 0x10057f30
// FUNCTION: ROBLOX 0x00564150
void initMoo()
{
	moo2();
}

// FUNCTION: WEBSERVICE 0x10058640
// FUNCTION: ROBLOX 0x005644f0
std::map<int, Name*>& Name::dictionary()
{
	static std::map<int, Name*> d;

	return d;
}

// FUNCTION: WEBSERVICE 0x100586d0
// FUNCTION: ROBLOX 0x00564580
Name::NamMap::~NamMap()
{
	for (iterator iter = begin(); iter != end(); ++iter) {
		delete iter->second;
	}
}

// FUNCTION: WEBSERVICE 0x100587b0
// FUNCTION: ROBLOX 0x00564660
Name::NamMap& Name::namMap()
{
	static NamMap n;

	return n;
}

// FUNCTION: WEBSERVICE 0x10058840
// FUNCTION: ROBLOX 0x005646f0
const Name& Name::declare(const char* sName, int dictionaryIndex)
{
	if (sName == NULL) {
		return getNullName();
	}

	boost::call_once(initMoo, flag);

	boost::mutex::scoped_lock lock(moo2());
	NamMap::iterator iter = namMap().find(std::string(sName));

	if (iter != namMap().end()) {
		if (dictionaryIndex != -1) {
			iter->second->dictionaryIndex = dictionaryIndex;
			dictionary()[dictionaryIndex] = iter->second;
		}

		return *iter->second;
	}

	Name* declared = new Name(sName, dictionaryIndex);
	namMap()[sName] = declared;
	dictionary()[dictionaryIndex] = declared;

	return *declared;
}

// FUNCTION: WEBSERVICE 0x10058a30
// FUNCTION: ROBLOX 0x005648e0
const Name& Name::getNullName()
{
	boost::call_once(initMoo, flag);

	boost::mutex::scoped_lock lock(moo2());
	static const Name* nullName = &declare("", 0);

	return *nullName;
}

// FUNCTION: WEBSERVICE 0x10058ad0
// FUNCTION: ROBLOX 0x00564980
const Name& Name::lookup(const std::string& sName)
{
	boost::call_once(initMoo, flag);

	boost::mutex::scoped_lock lock(moo2());
	NamMap::iterator iter = namMap().find(sName);

	if (iter != namMap().end()) {
		return *iter->second;
	}

	return getNullName();
}

// FUNCTION: WEBSERVICE 0x10058ba0
// FUNCTION: ROBLOX 0x00564a50
const Name& Name::lookup(const char* sName)
{
	if (sName == NULL) {
		return getNullName();
	}

	return lookup(std::string(sName));
}

// FUNCTION: WEBSERVICE 0x10058c70
// FUNCTION: ROBLOX 0x004afe40
// PORT: Name::empty is inline in the 2008 header (C2084).

// PORT: Name constructor is inline in the 2008 header (C2084).

} // namespace RBX
