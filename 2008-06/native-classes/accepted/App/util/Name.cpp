#include "util/Name.h"
#include "util/Debug.h"
#include <boost/thread/once.hpp>

// intentionally outside of the RBX namespace
boost::once_flag flag = BOOST_ONCE_INIT;

boost::mutex& moo2()
{
	static boost::mutex mutex2;
	return mutex2;
}

void initMoo()
{
	moo2();
}

static const RBX::Name* nullName;
static void initNullName()
{
    nullName = &RBX::Name::declare("", 0);
}

namespace RBX
{
	// seems to be inlined
	boost::mutex& Name::mutex()
	{
		boost::call_once(initMoo, flag);
		return moo2();
	}

	std::map<int, Name*>& Name::dictionary()
	{
		static std::map<int, Name*> d;
		return d;
	}

	Name::NamMap& Name::namMap()
	{
		static NamMap n;
		return n;
	}

	const Name& Name::getNullName()
	{
        static boost::once_flag nullNameFlag = BOOST_ONCE_INIT;
        boost::call_once(initNullName, nullNameFlag);
        return *nullName;
    }

	const Name& Name::declare(const char* sName, int dictionaryIndex)
	{
		if (!sName)
		{
			return getNullName();
		}

		boost::mutex::scoped_lock scoped_lock(mutex());

		NamMap::iterator iter = namMap().find(std::string(sName));
		if (iter != namMap().end())
		{
			if (dictionaryIndex != -1)
			{
				iter->second->dictionaryIndex = dictionaryIndex;
				dictionary()[dictionaryIndex] = iter->second;
			}
			return *iter->second;
		}
		else
		{
			Name* name = new Name(sName, dictionaryIndex);
			namMap()[sName] = name;
			dictionary()[dictionaryIndex] = name;
			return *name;
		}
	}

	const Name& Name::lookup(const std::string& sName)
	{
		                            ;
		boost::mutex::scoped_lock scoped_lock(mutex());

		NamMap::iterator iter = namMap().find(sName);
		if (iter != namMap().end())
		{
			return *iter->second;
		}
		else
		{
			return getNullName();
		}
	}

	const Name& Name::lookup(const char* sName)
	{
		if (!sName)
		{
			return getNullName();
		}

		return lookup(std::string(sName));
	}
}
