// from server: 100% by EspClaude
// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_claude_8ee34062043ed473.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 Instance has no GuidItem<Instance> base: target fields are 0x10 lower
// (children 0xc0, parent 0xbc, ChildRemoved notifier +4) and onAncestorChanged/
// onChildRemoving sit at vtable +0x14/+0x24 behind AbstractFactoryProduct::getClassName.
#ifndef V8TREE_INSTANCE_H
#define V8TREE_INSTANCE_H

#include "decomp.h"
#include "reflection/property.h"
#include "reflection/reflection.h"
#include "reflection/signal.h"
#include "util/Association.h"
#include "util/Events.h"
#include "util/Guid.h"
#include "util/Utilities.h"
#include "util/object.h"
#include "v8xml/XmlElement.h"

#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>

namespace RBX {

using boost::shared_ptr;

class IReferenceBinder;
class Instance;
class Name;
class ServiceProvider;

// SIZE 0x8
struct ChildAdded
{
	const boost::shared_ptr<Instance> child; // 0x00

	ChildAdded(Instance* child);

private:
	ChildAdded& operator=(const ChildAdded& other);
};

// SIZE 0x8
struct ChildRemoved
{
	const boost::shared_ptr<Instance> child; // 0x00

	ChildRemoved(Instance* child);

private:
	ChildRemoved& operator=(const ChildRemoved& other);
};

// SIZE 0x10
struct DescendentAdded
{
	const boost::shared_ptr<Instance> instance; // 0x00
	const boost::shared_ptr<Instance> parent;   // 0x08
};

// SIZE 0x10
struct DescendentRemoving
{
	const boost::shared_ptr<Instance> instance; // 0x00
	const boost::shared_ptr<Instance> parent;   // 0x08
};
// SIZE 0xc
struct AncestorChanged
{
	Instance* const child;     // 0x00
	Instance* const oldParent; // 0x04
	Instance* const newParent; // 0x08

	AncestorChanged(Instance* child, Instance* oldParent, Instance* newParent)
		: child(child), oldParent(oldParent), newParent(newParent)
	{
	}
};
// SIZE 0x8
class PropertyChanged
{
public:
	PropertyChanged(const PropertyChanged& other) : property(other.property) {}

	const Reflection::Property& getProperty() const { return property; }

	const Reflection::PropertyDescriptor& getDescriptor() const { return property.getDescriptor(); }

private:
	friend class Instance;

	PropertyChanged(const Reflection::Property& property) : property(property) {}

	Reflection::Property property; // 0x00
};

DECOMP_SIZE_ASSERT(PropertyChanged, 0x8)

// clang-format off
// TEMPLATE: WEBSERVICE 0x10047dc0
// RBX::AbstractFactoryProduct<RBX::Instance>::~AbstractFactoryProduct<RBX::Instance>
// FUNCTION: WEBSERVICE 0x10048490
// RBX::AbstractFactoryProduct<RBX::Instance>::`scalar deleting destructor'
// clang-format on
template <class T>
class AbstractFactoryProduct : public Creatable<T>
{
public:
	virtual ~AbstractFactoryProduct() {}

	virtual const Name& getClassName() const = 0; // vtable+0x04
};

extern const char sInstance[];

class Instance : public AbstractFactoryProduct<Instance>,
				 public Reflection::Described<Instance, sInstance, Reflection::DescribedBase>,
				 public Debugable,
				 public Notifier<Instance, ChildAdded>,
				 public Notifier<Instance, ChildRemoved>,
				 public Notifier<Instance, DescendentAdded>,
				 public Notifier<Instance, DescendentRemoving>,
				 public Notifier<Instance, AncestorChanged>,
				 public Notifier<Instance, PropertyChanged>,
				 public boost::enable_shared_from_this<Instance>,
				 public boost::noncopyable
{
public:
	Instance();

protected:
	Instance(const char* name);

	virtual ~Instance(); // vtable+0x00

public:
	virtual void setName(const std::string& value); // vtable+0x04

protected:
	// FUNCTION: WEBSERVICE 0x100c74e0 FOLDED
	virtual bool askAddChild(const Instance* instance) const { return false; } // vtable+0x08

	virtual bool askSetParent(const Instance* instance) const { return false; } // vtable+0x0c
	virtual void onAncestorChanged(const AncestorChanged& event);               // vtable+0x10
	virtual void onDescendentAdded(Instance* instance);                         // vtable+0x14
	virtual void onDescendentRemoving(const shared_ptr<Instance>& instance);    // vtable+0x18
	virtual void onChildAdded(Instance* child) {}                               // vtable+0x1c

	virtual void onChildRemoving(Instance* child) {} // vtable+0x20

	virtual void onChildRemoved(Instance* child) {} // vtable+0x24

private:
	virtual void onLastChildRemoved() {} // vtable+0x28

protected:
	virtual void readProperty(const XmlElement* element, IReferenceBinder& binder); // vtable+0x2c

public:
	virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {
	} // vtable+0x30
	virtual shared_ptr<Instance> createChild(const Name& className); // vtable+0x34
	virtual XmlElement* write();                                     // vtable+0x38

protected:
	virtual void onChildChanged(Instance* child, const PropertyChanged& event); // vtable+0x3c

public:
	static Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> event_childAdded;
	static Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> event_childRemoved;
	static Reflection::SignalDesc<Instance, void(shared_ptr<Instance>)> event_ancestryChanged;
	static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged;

	static const Reflection::RefPropDescriptor<Instance, Instance> propParent;

	Instance* getParent() const { return parent; }

	void setParent(Instance* newParent);

	Instance* getRootAncestor() { return parent != NULL ? parent->getRootAncestor() : this; }

	Instance* findFirstChildByName(const std::string& findName) const;

	template <class T>
	T* findFirstChildOfType() const;

	const std::string& getName() const { return name; }

	const CopyOnWrite<std::vector<shared_ptr<Instance> > >& getChildren() const { return children; }

	// FUNCTION: WEBSERVICE 0x10048320
	unsigned int numChildren() const { return children ? children->size() : 0; }

	const Instance* getChild(unsigned int index) const { return (*children)[index].get(); }
	Instance* getChild(unsigned int index) { return (*children)[index].get(); }

	// FUNCTION: WEBSERVICE 0x100469f0
	void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor)
	{
		Reflection::Property property(&descriptor, this);
		PropertyChanged event(property);

		Notifier<Instance, PropertyChanged>::raise(property);

		if (!event_propertyChanged.empty(this)) {
			event_propertyChanged.fire(this, &descriptor);
		}

		Instance* parent = this->parent;

		if (parent != NULL) {
			parent->onChildChanged(this, event);
		}
	}

	void readProperties(const XmlElement* element, IReferenceBinder& binder);
	void readChild(const XmlElement* childElement, IReferenceBinder& binder);
	void readChildren(const XmlElement* element, IReferenceBinder& binder);
	void writeChildren(XmlElement* element);

	bool contains(const Instance* instance) const;

	bool canAddChild(const Instance* child) const
	{
		if (child->contains(this) || child->parent == this) {
			return false;
		}

		return askAddChild(child) || child->askSetParent(this);
	}

	bool canSetParent(const Instance* parent) const { return parent == NULL || parent->canAddChild(this); }

	// clang-format off
	// TEMPLATE: WEBSERVICE 0x10059dc0
	// RBX::Instance::getTypedRoot<RBX::PVInstance>
	// FUNCTION: WEBSERVICE 0x10005d00
	// RBX::Instance::getParent
	// clang-format on
	template <class T>
	const T* getTypedRoot() const
	{
		const Instance* root = this;
		const T* typedParent = dynamic_cast<const T*>(parent);

		while (typedParent != NULL) {
			root = typedParent;
			typedParent = dynamic_cast<const T*>(typedParent->parent);
		}

		return static_cast<const T*>(root);
	}

	// FUNCTION: WEBSERVICE 0x10047cd0
	bool isAncestorOf(const Instance* descendent) const
	{
		if (descendent == NULL) {
			return false;
		}

		descendent = descendent->parent;

		if (descendent == this) {
			return true;
		}

		return isAncestorOf(descendent);
	}

	// FUNCTION: WEBSERVICE 0x10047d90
	bool isDescendentOf(const Instance* ancestor) const
	{
		const Instance* walk = parent;

		while (ancestor != walk) {
			if (walk == 0) {
				return false;
			}

			walk = walk->parent;
		}

		return true;
	}

private:
	friend class Creatable<Instance>::Deleter;

	void predelete();
	static void predelete(Instance* instance);

	static void signalDescendentAdded(Instance* instance, Instance* beginParent, Instance* oldParent);
	static void signalDescendentRemoving(
		const shared_ptr<Instance>& instance,
		Instance* beginParent,
		Instance* newParent
	);

	Association<Instance> assoc;                                      // 0xbc
	Instance* parent;                                                 // 0xcc
	CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > children; // 0xd0
	std::string name;                                                 // 0xd8
	bool archivable;                                                  // 0xf4
};



template <class T, class Base, const char* sName>
class DescribedNonCreatable : public Reflection::Described<T, sName, NonFactoryProduct<Base, sName> >
{
public:
	DescribedNonCreatable() {}

	template <class U>
	DescribedNonCreatable(U* joint) : Reflection::Described<T, sName, NonFactoryProduct<Base, sName> >(joint)
	{
	}
};

template <class T, class Base, const char* sName>
// clang-format off
	// FUNCTION: WEBSERVICE 0x10043190
	// RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::~DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>
	// FUNCTION: WEBSERVICE 0x100c74e0 FOLDED
	// RBX::Instance::askSetParent
	// FUNCTION: WEBSERVICE 0x10043270
	// RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::raise
	// FUNCTION: WEBSERVICE 0x10043920
	// RBX::Notifier<RBX::Instance,RBX::PropertyChanged>::raise
	// FUNCTION: WEBSERVICE 0x100459e0
	// RBX::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>::DescribedCreatable<RBX::Lighting,RBX::Instance,&RBX::sLighting>
	// FUNCTION: WEBSERVICE 0x1004c040
	// RBX::Reflection::SignalDesc<RBX::Instance,void __cdecl(boost::shared_ptr<RBX::Instance>)>::SignalDesc<RBX::Instance,void __cdecl(boost::shared_ptr<RBX::Instance>)>
	// FUNCTION: WEBSERVICE 0x100543a0
	// RBX::DescribedCreatable<RBX::RunService,RBX::Instance,&RBX::sRunService>::~DescribedCreatable<RBX::RunService,RBX::Instance,&RBX::sRunService>
	// FUNCTION: WEBSERVICE 0x100563e0
	// RBX::DescribedCreatable<RBX::RunService,RBX::Instance,&RBX::sRunService>::DescribedCreatable<RBX::RunService,RBX::Instance,&RBX::sRunService>
	// FUNCTION: WEBSERVICE 0x1005cde0
	// RBX::Instance::getRootAncestor
	// FUNCTION: WEBSERVICE 0x1005d000
	// RBX::DescribedCreatable<RBX::Selection,RBX::Instance,&RBX::sSelection>::~DescribedCreatable<RBX::Selection,RBX::Instance,&RBX::sSelection>
	// FUNCTION: WEBSERVICE 0x1005e3f0
	// RBX::DescribedCreatable<RBX::Selection,RBX::Instance,&RBX::sSelection>::DescribedCreatable<RBX::Selection,RBX::Instance,&RBX::sSelection>
	// FUNCTION: WEBSERVICE 0x10061210
	// RBX::DescribedCreatable<RBX::ScriptContext,RBX::Instance,&RBX::sScriptContext>::~DescribedCreatable<RBX::ScriptContext,RBX::Instance,&RBX::sScriptContext>
	// FUNCTION: WEBSERVICE 0x10065660
	// RBX::DescribedCreatable<RBX::ScriptContext,RBX::Instance,&RBX::sScriptContext>::DescribedCreatable<RBX::ScriptContext,RBX::Instance,&RBX::sScriptContext>
	// FUNCTION: WEBSERVICE 0x10068be0
	// RBX::DescribedCreatable<RBX::Script,RBX::Instance,&RBX::sScript>::~DescribedCreatable<RBX::Script,RBX::Instance,&RBX::sScript>
	// FUNCTION: WEBSERVICE 0x10068ff0
	// RBX::DescribedCreatable<RBX::LocalScript,RBX::Script,&RBX::sLocalScript>::~DescribedCreatable<RBX::LocalScript,RBX::Script,&RBX::sLocalScript>
	// FUNCTION: WEBSERVICE 0x10069880
	// RBX::DescribedCreatable<RBX::Script,RBX::Instance,&RBX::sScript>::DescribedCreatable<RBX::Script,RBX::Instance,&RBX::sScript><char const *>
	// FUNCTION: WEBSERVICE 0x10069be0
	// RBX::DescribedCreatable<RBX::LocalScript,RBX::Script,&RBX::sLocalScript>::DescribedCreatable<RBX::LocalScript,RBX::Script,&RBX::sLocalScript>
	// FUNCTION: WEBSERVICE 0x100826c0
	// RBX::DescribedCreatable<RBX::Soundscape::SoundChannel,RBX::Instance,&RBX::Soundscape::sSoundChannel>::DescribedCreatable<RBX::Soundscape::SoundChannel,RBX::Instance,&RBX::Soundscape::sSoundChannel>
	// TEMPLATE: WEBSERVICE 0x1008c6f0
	// RBX::DescribedCreatable<RBX::Message,RBX::Instance,&RBX::sMessage>::~DescribedCreatable<RBX::Message,RBX::Instance,&RBX::sMessage>
	// FUNCTION: WEBSERVICE 0x1008cb80
	// RBX::DescribedCreatable<RBX::ObjectValue,RBX::Instance,&RBX::sObjectValue>::~DescribedCreatable<RBX::ObjectValue,RBX::Instance,&RBX::sObjectValue>
	// FUNCTION: WEBSERVICE 0x1008de10
	// RBX::DescribedCreatable<RBX::Hint,RBX::Message,&RBX::sHint>::DescribedCreatable<RBX::Hint,RBX::Message,&RBX::sHint>
	// FUNCTION: WEBSERVICE 0x1008e2c0
	// RBX::DescribedCreatable<RBX::ObjectValue,RBX::Instance,&RBX::sObjectValue>::DescribedCreatable<RBX::ObjectValue,RBX::Instance,&RBX::sObjectValue>
	// TEMPLATE: WEBSERVICE 0x1009b4b0
	// RBX::DescribedCreatable<RBX::PartInstance,RBX::PVInstance,&RBX::sPart>::~DescribedCreatable<RBX::PartInstance,RBX::PVInstance,&RBX::sPart>
	// TEMPLATE: WEBSERVICE 0x1009ee20
	// RBX::DescribedCreatable<RBX::PartInstance,RBX::PVInstance,&RBX::sPart>::DescribedCreatable<RBX::PartInstance,RBX::PVInstance,&RBX::sPart><char const *>
	// TEMPLATE: WEBSERVICE 0x100946f0
	// RBX::DescribedCreatable<RBX::Sky,RBX::Instance,&RBX::sSky>::~DescribedCreatable<RBX::Sky,RBX::Instance,&RBX::sSky>
	// TEMPLATE: WEBSERVICE 0x100a10f0
	// RBX::DescribedCreatable<RBX::Humanoid,RBX::Instance,&RBX::sHumanoid>::~DescribedCreatable<RBX::Humanoid,RBX::Instance,&RBX::sHumanoid>
	// TEMPLATE: WEBSERVICE 0x10095060
	// RBX::DescribedCreatable<RBX::Sky,RBX::Instance,&RBX::sSky>::DescribedCreatable<RBX::Sky,RBX::Instance,&RBX::sSky>
	// FUNCTION: WEBSERVICE 0x100a3b60
	// RBX::DescribedCreatable<RBX::Humanoid,RBX::Instance,&RBX::sHumanoid>::DescribedCreatable<RBX::Humanoid,RBX::Instance,&RBX::sHumanoid>
	// FUNCTION: WEBSERVICE 0x100b3b30
	// RBX::DescribedCreatable<RBX::DebugSettings,RBX::GlobalSettings::Item,&RBX::sDebugSettings>::~DescribedCreatable<RBX::DebugSettings,RBX::GlobalSettings::Item,&RBX::sDebugSettings>
	// FUNCTION: WEBSERVICE 0x100b4f20
	// RBX::DescribedCreatable<RBX::DebugSettings,RBX::GlobalSettings::Item,&RBX::sDebugSettings>::DescribedCreatable<RBX::DebugSettings,RBX::GlobalSettings::Item,&RBX::sDebugSettings>
	// FUNCTION: WEBSERVICE 0x100be000
	// RBX::DescribedCreatable<RBX::Team,RBX::Instance,&RBX::sTeam>::~DescribedCreatable<RBX::Team,RBX::Instance,&RBX::sTeam>
	// FUNCTION: WEBSERVICE 0x100be560
	// RBX::DescribedCreatable<RBX::Team,RBX::Instance,&RBX::sTeam>::DescribedCreatable<RBX::Team,RBX::Instance,&RBX::sTeam>
	// FUNCTION: WEBSERVICE 0x100c2ee0
	// RBX::DescribedCreatable<RBX::Camera,RBX::Instance,&RBX::sCamera>::~DescribedCreatable<RBX::Camera,RBX::Instance,&RBX::sCamera>
	// FUNCTION: WEBSERVICE 0x100c4030
	// RBX::DescribedCreatable<RBX::Camera,RBX::Instance,&RBX::sCamera>::DescribedCreatable<RBX::Camera,RBX::Instance,&RBX::sCamera>
	// FUNCTION: WEBSERVICE 0x100c5b70
	// RBX::DescribedCreatable<RBX::ControllerService,RBX::Instance,&RBX::sControllerService>::~DescribedCreatable<RBX::ControllerService,RBX::Instance,&RBX::sControllerService>
	// FUNCTION: WEBSERVICE 0x100c6a90
	// RBX::DescribedCreatable<RBX::ControllerService,RBX::Instance,&RBX::sControllerService>::DescribedCreatable<RBX::ControllerService,RBX::Instance,&RBX::sControllerService>
	// FUNCTION: WEBSERVICE 0x100d87f0
	// RBX::DescribedCreatable<RBX::Snap,RBX::AutoJoint,&RBX::sSnap>::~DescribedCreatable<RBX::Snap,RBX::AutoJoint,&RBX::sSnap>
	// FUNCTION: WEBSERVICE 0x100d8800
	// RBX::DescribedCreatable<RBX::Motor,RBX::AutoJoint,&RBX::sMotor>::~DescribedCreatable<RBX::Motor,RBX::AutoJoint,&RBX::sMotor>
	// FUNCTION: WEBSERVICE 0x100d9440
	// RBX::DescribedCreatable<RBX::Snap,RBX::AutoJoint,&RBX::sSnap>::DescribedCreatable<RBX::Snap,RBX::AutoJoint,&RBX::sSnap><RBX::Joint *>
	// FUNCTION: WEBSERVICE 0x100d94e0
	// RBX::DescribedCreatable<RBX::Weld,RBX::AutoJoint,&RBX::sWeld>::DescribedCreatable<RBX::Weld,RBX::AutoJoint,&RBX::sWeld><RBX::Joint *>
	// FUNCTION: WEBSERVICE 0x100d95c0
	// RBX::DescribedCreatable<RBX::Glue,RBX::AutoJoint,&RBX::sGlue>::DescribedCreatable<RBX::Glue,RBX::AutoJoint,&RBX::sGlue><RBX::GlueJoint *>
	// FUNCTION: WEBSERVICE 0x100d96d0
	// RBX::DescribedCreatable<RBX::Rotate,RBX::AutoJoint,&RBX::sRotate>::DescribedCreatable<RBX::Rotate,RBX::AutoJoint,&RBX::sRotate><RBX::Joint *>
	// FUNCTION: WEBSERVICE 0x100d9790
	// RBX::DescribedCreatable<RBX::RotateP,RBX::AutoJoint,&RBX::sRotateP>::DescribedCreatable<RBX::RotateP,RBX::AutoJoint,&RBX::sRotateP><RBX::Joint *>
	// FUNCTION: WEBSERVICE 0x100d9870
	// RBX::DescribedCreatable<RBX::RotateV,RBX::AutoJoint,&RBX::sRotateV>::DescribedCreatable<RBX::RotateV,RBX::AutoJoint,&RBX::sRotateV><RBX::Joint *>
	// FUNCTION: WEBSERVICE 0x100d9970
	// RBX::DescribedCreatable<RBX::Motor,RBX::AutoJoint,&RBX::sMotor>::DescribedCreatable<RBX::Motor,RBX::AutoJoint,&RBX::sMotor><RBX::MotorJoint *>
	// FUNCTION: WEBSERVICE 0x100da960
	// RBX::DescribedCreatable<RBX::Teams,RBX::Instance,&RBX::sTeams>::~DescribedCreatable<RBX::Teams,RBX::Instance,&RBX::sTeams>
	// FUNCTION: WEBSERVICE 0x100db0d0
	// RBX::DescribedCreatable<RBX::Teams,RBX::Instance,&RBX::sTeams>::DescribedCreatable<RBX::Teams,RBX::Instance,&RBX::sTeams>
	// FUNCTION: WEBSERVICE 0x100db930
	// RBX::DescribedCreatable<RBX::Accoutrement,RBX::Instance,&RBX::sAccoutrement>::~DescribedCreatable<RBX::Accoutrement,RBX::Instance,&RBX::sAccoutrement>
	// FUNCTION: WEBSERVICE 0x100dc280
	// RBX::DescribedCreatable<RBX::Hat,RBX::Accoutrement,&RBX::sHat>::~DescribedCreatable<RBX::Hat,RBX::Accoutrement,&RBX::sHat>
	// FUNCTION: WEBSERVICE 0x100dcc10
	// RBX::DescribedCreatable<RBX::Accoutrement,RBX::Instance,&RBX::sAccoutrement>::DescribedCreatable<RBX::Accoutrement,RBX::Instance,&RBX::sAccoutrement>
	// STUB: WEBSERVICE 0x100dd680
	// RBX::DescribedCreatable<RBX::Hat,RBX::Accoutrement,&RBX::sHat>::DescribedCreatable<RBX::Hat,RBX::Accoutrement,&RBX::sHat>
	// FUNCTION: WEBSERVICE 0x100de230
	// RBX::DescribedCreatable<RBX::GameSettings,RBX::GlobalSettings::Item,&RBX::sGameSettings>::~DescribedCreatable<RBX::GameSettings,RBX::GlobalSettings::Item,&RBX::sGameSettings>
	// FUNCTION: WEBSERVICE 0x100de4c0
	// RBX::DescribedCreatable<RBX::GameSettings,RBX::GlobalSettings::Item,&RBX::sGameSettings>::DescribedCreatable<RBX::GameSettings,RBX::GlobalSettings::Item,&RBX::sGameSettings>
	// FUNCTION: WEBSERVICE 0x100e0920
	// RBX::DescribedCreatable<RBX::ShirtGraphic,RBX::CharacterAppearance,&RBX::sShirtGraphic>::~DescribedCreatable<RBX::ShirtGraphic,RBX::CharacterAppearance,&RBX::sShirtGraphic>
	// FUNCTION: WEBSERVICE 0x100e0a80
	// RBX::DescribedCreatable<RBX::Skin,RBX::CharacterAppearance,&RBX::sSkin>::~DescribedCreatable<RBX::Skin,RBX::CharacterAppearance,&RBX::sSkin>
	// FUNCTION: WEBSERVICE 0x100e0b50
	// RBX::DescribedCreatable<RBX::BodyColors,RBX::CharacterAppearance,&RBX::sBodyColors>::~DescribedCreatable<RBX::BodyColors,RBX::CharacterAppearance,&RBX::sBodyColors>
	// FUNCTION: WEBSERVICE 0x100e0d50
	// RBX::DescribedCreatable<RBX::Shirt,RBX::ShirtGraphic,&RBX::sShirt>::~DescribedCreatable<RBX::Shirt,RBX::ShirtGraphic,&RBX::sShirt>
	// FUNCTION: WEBSERVICE 0x100e11c0
	// RBX::DescribedCreatable<RBX::ShirtGraphic,RBX::CharacterAppearance,&RBX::sShirtGraphic>::DescribedCreatable<RBX::ShirtGraphic,RBX::CharacterAppearance,&RBX::sShirtGraphic>
	// FUNCTION: WEBSERVICE 0x100e12b0
	// RBX::DescribedCreatable<RBX::BodyColors,RBX::CharacterAppearance,&RBX::sBodyColors>::DescribedCreatable<RBX::BodyColors,RBX::CharacterAppearance,&RBX::sBodyColors>
	// FUNCTION: WEBSERVICE 0x100e13a0
	// RBX::DescribedCreatable<RBX::Skin,RBX::CharacterAppearance,&RBX::sSkin>::DescribedCreatable<RBX::Skin,RBX::CharacterAppearance,&RBX::sSkin>
	// FUNCTION: WEBSERVICE 0x100e1840
	// RBX::DescribedCreatable<RBX::Shirt,RBX::ShirtGraphic,&RBX::sShirt>::DescribedCreatable<RBX::Shirt,RBX::ShirtGraphic,&RBX::sShirt>
	// FUNCTION: WEBSERVICE 0x100e2100
	// RBX::DescribedCreatable<RBX::Explosion,RBX::Instance,&RBX::sExplosion>::~DescribedCreatable<RBX::Explosion,RBX::Instance,&RBX::sExplosion>
	// FUNCTION: WEBSERVICE 0x100e2c00
	// RBX::DescribedCreatable<RBX::Explosion,RBX::Instance,&RBX::sExplosion>::DescribedCreatable<RBX::Explosion,RBX::Instance,&RBX::sExplosion>
	// FUNCTION: WEBSERVICE 0x100e46f0
	// RBX::DescribedCreatable<RBX::VelocityMotor,RBX::JointInstance,&RBX::sVelocityMotor>::~DescribedCreatable<RBX::VelocityMotor,RBX::JointInstance,&RBX::sVelocityMotor>
	// FUNCTION: WEBSERVICE 0x100e4ea0
	// RBX::DescribedCreatable<RBX::Hole,RBX::Feature,&RBX::sHole>::~DescribedCreatable<RBX::Hole,RBX::Feature,&RBX::sHole>
	// FUNCTION: WEBSERVICE 0x100e4eb0
	// RBX::DescribedCreatable<RBX::MotorFeature,RBX::Feature,&RBX::sMotorFeature>::~DescribedCreatable<RBX::MotorFeature,RBX::Feature,&RBX::sMotorFeature>
	// FUNCTION: WEBSERVICE 0x100e6c20
	// RBX::DescribedCreatable<RBX::VelocityMotor,RBX::JointInstance,&RBX::sVelocityMotor>::DescribedCreatable<RBX::VelocityMotor,RBX::JointInstance,&RBX::sVelocityMotor><RBX::MotorJoint *>
	// FUNCTION: WEBSERVICE 0x100e7730
	// RBX::DescribedCreatable<RBX::MotorFeature,RBX::Feature,&RBX::sMotorFeature>::DescribedCreatable<RBX::MotorFeature,RBX::Feature,&RBX::sMotorFeature>
	// FUNCTION: WEBSERVICE 0x100e77d0
	// RBX::DescribedCreatable<RBX::Hole,RBX::Feature,&RBX::sHole>::DescribedCreatable<RBX::Hole,RBX::Feature,&RBX::sHole>
	// FUNCTION: WEBSERVICE 0x100e8050
	// RBX::DescribedCreatable<RBX::FlagStandService,RBX::Instance,&RBX::sFlagStandService>::~DescribedCreatable<RBX::FlagStandService,RBX::Instance,&RBX::sFlagStandService>
	// FUNCTION: WEBSERVICE 0x100e89f0
	// RBX::DescribedCreatable<RBX::FlagStandService,RBX::Instance,&RBX::sFlagStandService>::DescribedCreatable<RBX::FlagStandService,RBX::Instance,&RBX::sFlagStandService>
	// FUNCTION: WEBSERVICE 0x100e9460
	// RBX::DescribedCreatable<RBX::ForceField,RBX::Instance,&RBX::sForceField>::~DescribedCreatable<RBX::ForceField,RBX::Instance,&RBX::sForceField>
	// FUNCTION: WEBSERVICE 0x100e96e0
	// RBX::DescribedCreatable<RBX::ForceField,RBX::Instance,&RBX::sForceField>::DescribedCreatable<RBX::ForceField,RBX::Instance,&RBX::sForceField>
	// FUNCTION: WEBSERVICE 0x100e9d30
	// RBX::DescribedCreatable<RBX::GeometryService,RBX::Instance,&RBX::sGeometryService>::DescribedCreatable<RBX::GeometryService,RBX::Instance,&RBX::sGeometryService><char *>
	// FUNCTION: WEBSERVICE 0x100ec040
	// RBX::DescribedCreatable<RBX::Rocket,RBX::BodyMover,&RBX::sRocket>::~DescribedCreatable<RBX::Rocket,RBX::BodyMover,&RBX::sRocket>
	// FUNCTION: WEBSERVICE 0x100ec050
	// RBX::DescribedCreatable<RBX::BodyGyro,RBX::BodyMover,&RBX::sBodyGyro>::~DescribedCreatable<RBX::BodyGyro,RBX::BodyMover,&RBX::sBodyGyro>
	// FUNCTION: WEBSERVICE 0x100ece60
	// RBX::DescribedCreatable<RBX::BodyGyro,RBX::BodyMover,&RBX::sBodyGyro>::DescribedCreatable<RBX::BodyGyro,RBX::BodyMover,&RBX::sBodyGyro><char *>
	// FUNCTION: WEBSERVICE 0x100ecf60
	// RBX::DescribedCreatable<RBX::BodyPosition,RBX::BodyMover,&RBX::sBodyPosition>::DescribedCreatable<RBX::BodyPosition,RBX::BodyMover,&RBX::sBodyPosition><char *>
	// FUNCTION: WEBSERVICE 0x100ed010
	// RBX::DescribedCreatable<RBX::BodyVelocity,RBX::BodyMover,&RBX::sBodyVelocity>::DescribedCreatable<RBX::BodyVelocity,RBX::BodyMover,&RBX::sBodyVelocity><char *>
	// FUNCTION: WEBSERVICE 0x100ed1b0
	// RBX::DescribedCreatable<RBX::BodyForce,RBX::BodyMover,&RBX::sBodyForce>::DescribedCreatable<RBX::BodyForce,RBX::BodyMover,&RBX::sBodyForce><char *>
	// FUNCTION: WEBSERVICE 0x100ed380
	// RBX::DescribedCreatable<RBX::BodyThrust,RBX::BodyMover,&RBX::sBodyThrust>::DescribedCreatable<RBX::BodyThrust,RBX::BodyMover,&RBX::sBodyThrust><char *>
	// FUNCTION: WEBSERVICE 0x100eddb0
	// RBX::DescribedCreatable<RBX::Rocket,RBX::BodyMover,&RBX::sRocket>::DescribedCreatable<RBX::Rocket,RBX::BodyMover,&RBX::sRocket><char *>
	// FUNCTION: WEBSERVICE 0x100ee970
	// RBX::DescribedCreatable<RBX::Message,RBX::Instance,&RBX::sMessage>::DescribedCreatable<RBX::Message,RBX::Instance,&RBX::sMessage><char const *>
	// FUNCTION: WEBSERVICE 0x100f8d50
	// RBX::DescribedCreatable<RBX::Visit,RBX::Instance,&RBX::sVisit>::~DescribedCreatable<RBX::Visit,RBX::Instance,&RBX::sVisit>
	// FUNCTION: WEBSERVICE 0x100f94e0
	// RBX::DescribedCreatable<RBX::Visit,RBX::Instance,&RBX::sVisit>::DescribedCreatable<RBX::Visit,RBX::Instance,&RBX::sVisit>
	// FUNCTION: WEBSERVICE 0x100fa020
	// RBX::DescribedCreatable<RBX::DebrisService,RBX::Instance,&RBX::sDebrisService>::~DescribedCreatable<RBX::DebrisService,RBX::Instance,&RBX::sDebrisService>
	// FUNCTION: WEBSERVICE 0x100fac30
	// RBX::DescribedCreatable<RBX::DebrisService,RBX::Instance,&RBX::sDebrisService>::DescribedCreatable<RBX::DebrisService,RBX::Instance,&RBX::sDebrisService><char *>
	// FUNCTION: WEBSERVICE 0x100fb690
	// RBX::DescribedCreatable<RBX::TimerService,RBX::Instance,&RBX::sTimerService>::~DescribedCreatable<RBX::TimerService,RBX::Instance,&RBX::sTimerService>
	// FUNCTION: WEBSERVICE 0x100fbc60
	// RBX::DescribedCreatable<RBX::TimerService,RBX::Instance,&RBX::sTimerService>::DescribedCreatable<RBX::TimerService,RBX::Instance,&RBX::sTimerService>
	// FUNCTION: WEBSERVICE 0x100fc3f0
	// RBX::DescribedCreatable<RBX::Seat,RBX::PartInstance,&RBX::sSeat>::~DescribedCreatable<RBX::Seat,RBX::PartInstance,&RBX::sSeat>
	// STUB: WEBSERVICE 0x100fcfd0
	// RBX::DescribedCreatable<RBX::Seat,RBX::PartInstance,&RBX::sSeat>::DescribedCreatable<RBX::Seat,RBX::PartInstance,&RBX::sSeat>
	// FUNCTION: WEBSERVICE 0x100fda80
	// RBX::DescribedCreatable<RBX::SpawnerService,RBX::Instance,&RBX::sSpawnerService>::~DescribedCreatable<RBX::SpawnerService,RBX::Instance,&RBX::sSpawnerService>
	// FUNCTION: WEBSERVICE 0x100feae0
	// RBX::DescribedCreatable<RBX::SpawnerService,RBX::Instance,&RBX::sSpawnerService>::DescribedCreatable<RBX::SpawnerService,RBX::Instance,&RBX::sSpawnerService>
	// FUNCTION: WEBSERVICE 0x100ffb30
	// RBX::DescribedCreatable<RBX::Texture,RBX::Decal,&RBX::sTexture>::~DescribedCreatable<RBX::Texture,RBX::Decal,&RBX::sTexture>
	// TEMPLATE: WEBSERVICE 0x100ffe70
	// RBX::DescribedCreatable<RBX::Decal,RBX::FaceInstance,&RBX::sDecal>::DescribedCreatable<RBX::Decal,RBX::FaceInstance,&RBX::sDecal>
	// TEMPLATE: WEBSERVICE 0x101002f0
	// RBX::DescribedCreatable<RBX::Texture,RBX::Decal,&RBX::sTexture>::DescribedCreatable<RBX::Texture,RBX::Decal,&RBX::sTexture>
	// FUNCTION: WEBSERVICE 0x1012cc20
	// RBX::DescribedCreatable<RBX::SpecialShape,RBX::Instance,&RBX::sSpecialShape>::~DescribedCreatable<RBX::SpecialShape,RBX::Instance,&RBX::sSpecialShape>
	// FUNCTION: WEBSERVICE 0x1012d890
	// RBX::DescribedCreatable<RBX::SpecialShape,RBX::Instance,&RBX::sSpecialShape>::DescribedCreatable<RBX::SpecialShape,RBX::Instance,&RBX::sSpecialShape>
// FUNCTION: WEBSERVICE 0x1007d2e0
// RBX::DescribedCreatable<RBX::Soundscape::SoundChannel,RBX::Instance,&RBX::Soundscape::sSoundChannel>::`scalar deleting destructor'
// TEMPLATE: WEBSERVICE 0x1007daf0
// RBX::DescribedCreatable<RBX::Soundscape::SoundChannel,RBX::Instance,&RBX::Soundscape::sSoundChannel>::~DescribedCreatable<RBX::Soundscape::SoundChannel,RBX::Instance,&RBX::Soundscape::sSoundChannel>
// FUNCTION: WEBSERVICE 0x10094680
// RBX::DescribedCreatable<RBX::Sky,RBX::Instance,&RBX::sSky>::`scalar deleting destructor'
// FUNCTION: WEBSERVICE 0x1009ac30
// RBX::DescribedCreatable<RBX::PartInstance,RBX::PVInstance,&RBX::sPart>::`scalar deleting destructor'
// TEMPLATE: WEBSERVICE 0x100ffa20
// RBX::DescribedCreatable<RBX::Decal,RBX::FaceInstance,&RBX::sDecal>::~DescribedCreatable<RBX::Decal,RBX::FaceInstance,&RBX::sDecal>
// FUNCTION: WEBSERVICE 0x100fff50
// RBX::DescribedCreatable<RBX::Decal,RBX::FaceInstance,&RBX::sDecal>::`scalar deleting destructor'
// clang-format on
class DescribedCreatable : public Reflection::Described<T, sName, FactoryProduct<T, Base, sName> >
{
protected:
	DescribedCreatable() {}

	template <class U>
	DescribedCreatable(U arg0) : Reflection::Described<T, sName, FactoryProduct<T, Base, sName> >(arg0)
	{
	}
};

// clang-format off
// SYNTHETIC: WEBSERVICE 0x10218690
// `dynamic initializer for 'RBX::Instance::event_childAdded''
// SYNTHETIC: WEBSERVICE 0x102186b0
// `dynamic initializer for 'RBX::Instance::event_childRemoved''
// SYNTHETIC: WEBSERVICE 0x10218730
// `dynamic initializer for 'RBX::Instance::event_propertyChanged''
// SYNTHETIC: WEBSERVICE 0x102217c0
// `dynamic atexit destructor for 'RBX::Instance::event_propertyChanged''
// SYNTHETIC: WEBSERVICE 0x10221780
// `dynamic atexit destructor for 'RBX::Instance::event_childRemoved''
// SYNTHETIC: WEBSERVICE 0x102217e0
// `dynamic atexit destructor for 'RBX::Instance::event_childAdded''
// clang-format on

// clang-format off
// TEMPLATE: WEBSERVICE 0x1005aff0
// RBX::Instance::findFirstChildOfType<RBX::Humanoid>
// clang-format on
template <class T>
T* Instance::findFirstChildOfType() const
{
	if (getChildren()) {
		std::vector<shared_ptr<Instance> >::const_iterator end = getChildren()->end();

		for (std::vector<shared_ptr<Instance> >::const_iterator iter = getChildren()->begin(); iter != end; ++iter) {
			T* child = dynamic_cast<T*>(iter->get());

			if (child != NULL) {
				return child;
			}
		}
	}

	return NULL;
}

} // namespace RBX

#endif // V8TREE_INSTANCE_H


#include <algorithm>

namespace RBX {

inline ChildRemoved::ChildRemoved(Instance* child)
    : child(shared_from(child))
{
}

// The body is the authentic November 2007 RBXGS implementation.  It is emitted
// against the later OpenRBX class declaration, whose virtual ordering matches
// the 2008-06 target (onAncestorChanged +0x10, onChildRemoving +0x20).
void Instance::predelete()
{
    while (children) {
        boost::shared_ptr<Instance> child;

        {
            boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > c = children.write();

            child = *(c->end() - 1);

            signalDescendentRemoving(child, this, NULL);

            this->onChildRemoving(child.get());
            child->parent = NULL;
            c->pop_back();

            if (c->empty()) {
                children.reset();
            }
        }

        event_childRemoved.fire(this, child);
        Notifier<Instance, ChildRemoved>::raise(ChildRemoved(child.get()));

        child->onAncestorChanged(AncestorChanged(child.get(), this, NULL));
        child->raisePropertyChanged(propParent);
    }
}

} // namespace RBX
