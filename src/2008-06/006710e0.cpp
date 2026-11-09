// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/util/Name.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Name.h"

#include "decomp.h"

#include <boost/thread/mutex.hpp>
#include <boost/thread/once.hpp>

namespace RBX {

DECOMP_SIZE_ASSERT(Name, 0x20)

class Name::NamMap : public std::map<std::string, Name*>
{
public:
	~NamMap();
};

static boost::once_flag flag = BOOST_ONCE_INIT;

// FUNCTION: WEBSERVICE 0x10057ed0
boost::mutex& moo2()
{
	static boost::mutex mutex2;

	return mutex2;
}

// FUNCTION: WEBSERVICE 0x10057f30
void initMoo()
{
	moo2();
}

// FUNCTION: WEBSERVICE 0x10058640
std::map<int, Name*>& Name::dictionary()
{
	static std::map<int, Name*> d;

	return d;
}

// FUNCTION: WEBSERVICE 0x100586d0
Name::NamMap::~NamMap()
{
	for (iterator iter = begin(); iter != end(); ++iter) {
		delete iter->second;
	}
}

// FUNCTION: WEBSERVICE 0x100587b0
Name::NamMap& Name::namMap()
{
	static NamMap n;

	return n;
}

// FUNCTION: WEBSERVICE 0x10058840
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
const Name& Name::getNullName()
{
	boost::call_once(initMoo, flag);

	boost::mutex::scoped_lock lock(moo2());
	static const Name* nullName = &declare("", 0);

	return *nullName;
}

// FUNCTION: WEBSERVICE 0x10058ad0
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
const Name& Name::lookup(const char* sName)
{
	if (sName == NULL) {
		return getNullName();
	}

	return lookup(std::string(sName));
}

// FUNCTION: WEBSERVICE 0x10058c70
bool Name::empty() const
{
	return this == &getNullName();
}

Name::Name(const char* name, int dictionaryIndex) : dictionaryIndex(dictionaryIndex), name(name)
{
}

} // namespace RBX
