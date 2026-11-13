// 2008-06 override of Source/App/include/v8datamodel/GlobalSettings.h: class-name template parameters take the
// char array itself (const char*), as the 2008 binary pushes .data name arrays directly.
#pragma once
// >>> native-status (generated) -- do not edit >>>
// GlobalSettings | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src a51f9ca2 | roc native-status --write
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "util/Object.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

namespace RBX
{
	extern char sGlobalSettings[];

	class GlobalSettings : public DescribedNonCreatable<GlobalSettings, ServiceProvider, sGlobalSettings>
	{
	public:
		class Item : public NonFactoryProduct<Instance, NULL>
		{
		protected:
			virtual bool askAddChild(const Instance* instance) const
			{
				return dynamic_cast<const GlobalSettings::Item*>(instance) != NULL;
			}
		};

	public:
		static boost::recursive_mutex mutex;

		GlobalSettings()
		{
			setName("Global Settings");
		}
		void loadState();
		void saveState();
		void eraseSettingsStore();

	public:
		static boost::shared_ptr<GlobalSettings> singleton();
	};

	template<typename Class, const char* ClassName>
	class GlobalSettingsItem : public DescribedCreatable<Class, GlobalSettings::Item, ClassName>, public Service
	{
	private:
		static GlobalSettingsItem* sing;

	protected:
		GlobalSettingsItem();
		~GlobalSettingsItem();

	public:
		static Class& singleton();
	};
}
