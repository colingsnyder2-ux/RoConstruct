#pragma once
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "util/Object.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

namespace RBX
{
	extern const char* sGlobalSettings;

	class GlobalSettings : public DescribedNonCreatable<GlobalSettings, ServiceProvider, &sGlobalSettings>
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

	template<typename Class, const char** ClassName>
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

// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename Class, const char** ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL;

	template<typename Class, const char** ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		sing = this;
	}

	template<typename Class, const char** ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		if (sing == this)
			sing = NULL;
	}

	template<typename Class, const char** ClassName>
	Class& GlobalSettingsItem<Class, ClassName>::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
		if (!sing)
			ServiceProvider::create<Class>(GlobalSettings::singleton().get());
		return *static_cast<Class*>(sing);
	}
}
