// 2008-06 native rows of the GlobalSettings translation unit 00568460..005691af of the application range
// 00568000..0056c000 (inactive). Verified by tests/record_native_app_unit568.py; the unit map is in its receipt.
//
// The unit is the 2008 v8datamodel/GlobalSettings.cpp. In link order it is the first to emit the inline
// ServiceProvider constructor / destructor chain and the GlobalSettings class-name templates:
//   * the settings file name helper 00568460 (FileSystem::getUserAppDataDirectory(true, NULL) 005a7ac0, then
//     "\GlobalSettings7.xml" 0082ef48 when the directory is not empty); callers eraseSettingsStore 005684d0,
//     loadState 00568790 and saveState 00568933;
//   * eraseSettingsStore 005684d0 (DeleteFileA through the IAT), loadState 00568760 (ifstream in|binary,
//     TextXmlParser 00415350, parse 0058f6c0, mutex lock, MergeBinder 00443e50 / readChildren 0055b6a0 /
//     resolveRefs 00443d60, catch(std::exception&) printing "Exception thrown in loadState %s" 0082f038 with
//     StandardOut::print 005693a0) and saveState 00568910 (SerializerV2::newRootElement 00591a30, writeChildren
//     00558110, ofstream out|binary, TextXmlWriter / XmlWriter 0058fff0, serialize 0058e810);
//   * NonFactoryProduct<Instance, sServiceProvider>() 00568520, DescribedNonCreatable<ServiceProvider>() 00568a50,
//     ~ServiceProvider 00568af0, NonFactoryProduct<ServiceProvider, sGlobalSettings>() 00568d70,
//     DescribedNonCreatable<GlobalSettings>() 00568ed0, GlobalSettings() 00568f80 (setName "Global Settings"
//     0082f4dc), the folded ??_G 00568d40 and its adjustor thunks, Creatable::create<GlobalSettings> 00569070
//     (malloc 0x1c8 = sizeof(GlobalSettings)), shared_ptr<GlobalSettings>(p, Deleter) 00568690 and singleton 005690f0;
//   * Name::doDeclare / callDoDeclare <sServiceProvider> 00568580 / 005685f0 ("ServiceProvider" 0082f7d8) and
//     <sGlobalSettings> 00568df0 / 00568ea0 ("GlobalSettings" 0082ef38), and the two getClassName overrides
//     00568740 / 00568eb0 (slot 1 of the +0x10 vtables 0082efd4 / 0082f490).
// ServiceProvider() 00568bf0 is emitted here too, but the current v8tree/Service.h declares ServiceProvider
// __declspec(novtable) while the 2008 constructor stores its vtables: that row is pending-build-only (proposal).
// Headers are read-only here (v8datamodel/GlobalSettings.h, v8tree/Service.h, util/Object.h, util/Name.h,
// util/FileSystem.h, the MergeBinder / SerializerV2 declarations of metadata-load/v8xml/SerializerV2.h).
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

	// 00568460: file-local (no evidence name); the result is returned by value.
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
