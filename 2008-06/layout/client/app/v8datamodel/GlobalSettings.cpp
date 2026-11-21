#include "v8datamodel/GlobalSettings.h"
#include "util/Name.h"
#include "util/FileSystem.h"
#include "metadata-load/v8xml/SerializerV2.h"
#include "util/standardout.h"
#include <fstream>

namespace RBX
{
	// Template members util/Object.h only declares (the same definitions as Hopper.cpp / PhysicsService.cpp).
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	static std::string getSettingsFileName()
	{
		std::string result = FileSystem::getUserAppDataDirectory(true, NULL);
		if (result.size() > 0)
			result += "\\GlobalSettings7.xml";
		return result;
	}

	void GlobalSettings::eraseSettingsStore()
	{
		::DeleteFileA(getSettingsFileName().c_str());
	}

	void GlobalSettings::loadState()
	{
		std::string fileName = getSettingsFileName();
		if (fileName.empty())
			return;
		try
		{
			std::ifstream stream(fileName.c_str(), std::ios_base::in | std::ios_base::binary);
			TextXmlParser parser(stream.rdbuf());
			std::auto_ptr<XmlElement> root(parser.parse());
			boost::recursive_mutex::scoped_lock lock(mutex);
			MergeBinder binder;
			readChildren(root.get(), binder);
			binder.resolveRefs();
		}
		catch (std::exception& e)
		{
			StandardOut::singleton()->print(MESSAGE_INFO, "Exception thrown in loadState %s", e.what());
		}
	}

	void GlobalSettings::saveState()
	{
		std::string fileName = getSettingsFileName();
		if (fileName.empty())
			return;
		std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
		writeChildren(root.get());
		std::ofstream stream(fileName.c_str(), std::ios_base::out | std::ios_base::binary);
		TextXmlWriter writer(stream);
		writer.serialize(root.get());
	}

	boost::shared_ptr<GlobalSettings> GlobalSettings::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(mutex);
		static boost::shared_ptr<GlobalSettings> sing = Creatable<Instance>::create<GlobalSettings>();
		return sing;
	}

	template const Name& NonFactoryProduct<Instance, sServiceProvider>::getClassName() const;
	template const Name& NonFactoryProduct<ServiceProvider, sGlobalSettings>::getClassName() const;
}
