// =============================================================================
// GameSettings.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/GameSettings.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/GameSettings.h"
#include <G3D/format.h>
#include <boost/thread/recursive_mutex.hpp>
#include <stdexcept>

namespace RBX
{
	const char sGameSettings[] = "GameSettings"; // 00838478

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL; // 0096dd10

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		setName(ClassName);
		if (sing)
			throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
		sing = this;
	}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		sing = NULL;
	}

	template<typename Class, const char* ClassName>
	Class& GlobalSettingsItem<Class, ClassName>::singleton()
	{
		boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
		if (!sing)
		{
			boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
			item->setParent(GlobalSettings::singleton().get());
		}
		return *static_cast<Class*>(sing);
	}

	static Reflection::BoundProp<bool, 1> prop_FunnyPhysics(
		"FunnyPhysics",
		"Debug",
		&GameSettings::funnyPhysics,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ChatHistory(
		"ChatHistory",
		"Online",
		&GameSettings::chatHistory,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ChatScrollLength(
		"ChatScrollLength",
		"Online",
		&GameSettings::chatScrollLength,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoundEnabled(
		"SoundEnabled",
		"Sound",
		&GameSettings::soundEnabled,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_SoftwareSound(
		"SoftwareSound",
		"Sound",
		&GameSettings::softwareSound,
		Reflection::PropertyDescriptor::STANDARD);

	GameSettings::GameSettings()
		: chatHistory(50),
		  chatScrollLength(5),
		  soundEnabled(true),
		  softwareSound(false),
		  funnyPhysics(false)
	{
		setName("Game Options");
	}
}

template RBX::GameSettings& RBX::GlobalSettingsItem<RBX::GameSettings, RBX::sGameSettings>::singleton();
