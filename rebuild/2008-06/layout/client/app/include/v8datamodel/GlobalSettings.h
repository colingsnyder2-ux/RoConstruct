// =============================================================================
// GlobalSettings.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/GlobalSettings.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
