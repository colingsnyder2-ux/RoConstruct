"""Writes rbxgs-client.json: overlay patches that make the rbxgs Client tree link as one program.

rbxgs declares many template members in its headers but never defines them, and lacks forwarding
constructors its own classes call. Each patch below is either such a missing body/constructor or a
fix needed to compile; none changes behaviour that rbxgs does define. Bodies follow the 2008-verified
OpenRBX headers where those exist (cited per patch). Run from the repo root:
    python rebuild/2008-06/patches/make_rbxgs_client.py
"""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
TREE = ROOT / "tools" / "rbxgs" / "Client"
patches = {}


def patch(rel, old, new):
    text = (TREE / rel).read_text(errors="replace")
    if old and old not in text:
        raise SystemExit("%s: anchor not found: %r" % (rel, old[:60]))
    patches.setdefault(rel, []).append([old, new])


def append(rel, new):
    patch(rel, "", new)


def adopt(rel, unit):
    """Replace a header with a 2008-layout header from an exact generated unit (read locally at build time)."""
    if not (TREE / unit).exists():
        raise SystemExit("%s: no unit %s" % (rel, unit))
    patches.setdefault(rel, []).append(["@replace", unit])


def patch_adopted(rel, unit, old, new):
    """An edit to a header adopted with adopt(rel, unit); the anchor is checked against that unit."""
    if old not in (TREE / unit).read_text(errors="replace"):
        raise SystemExit("%s (adopted %s): anchor not found: %r" % (rel, unit, old[:60]))
    patches[rel].append([old, new])


# --- util/object.h: factory products (bodies as in OpenRBX util/object.h) ---
OBJ = "App/include/util/object.h"
patch(OBJ, "\tclass AbstractFactoryProduct : public Creatable<T>\n\t{\n",
      "\tclass AbstractFactoryProduct : public Creatable<T>\n\t{\n\tpublic:\n\t\ttypedef Creatable<T> CreatableBase;\n")
# Each constructor names the static creator, which instantiates it for every creatable class; its constructor
# registers the class with the factory at startup (without a use, the template static never exists and
# AbstractFactoryProduct::create finds no class). Naming it emits no code.
patch(OBJ, "\t\tFactoryProduct();\n",
      "\t\tFactoryProduct()\n\t\t{\n\t\t\t(void)&creator;\n\t\t}\n"
      "\t\ttemplate<typename Arg0Type>\n\t\tFactoryProduct(Arg0Type arg0)\n\t\t\t: DerivedClass(arg0)\n\t\t{\n\t\t\t(void)&creator;\n\t\t}\n")
append(OBJ, """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename T>
	void Creatable<T>::Deleter::operator()(T* instance)
	{
		T::predelete(instance);
		delete instance;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::className()
	{
		static const Name& n = Name::declare(*ClassName, -1);
		return n;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::getClassName() const
	{
		return className();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::Creator()
	{
		FactoryProduct::getCreators()[&FactoryProduct::className()] = this;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::~Creator()
	{
		FactoryProduct::getCreators().erase(&FactoryProduct::className());
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Class::CreatableBase::template create<Class>();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::Creator::getClassName() const
	{
		return FactoryProduct::className();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const typename FactoryProduct<Class, DerivedClass, ClassName>::Creator FactoryProduct<Class, DerivedClass, ClassName>::creator;

	template<typename DerivedClass, const char** ClassName>
	const Name& NonFactoryProduct<DerivedClass, ClassName>::className()
	{
		static const Name& n = Name::declare(*ClassName, -1);
		return n;
	}

	template<typename DerivedClass, const char** ClassName>
	const Name& NonFactoryProduct<DerivedClass, ClassName>::getClassName() const
	{
		return className();
	}
}
""")

# --- util/Name.h: Named ---
append("App/include/util/Name.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename DerivedClass, const char** ClassName>
	const Name& Named<DerivedClass, ClassName>::name()
	{
		static const Name& n = Name::declare(*ClassName, -1);
		return n;
	}

	template<typename DerivedClass, const char** ClassName>
	const Name& Named<DerivedClass, ClassName>::getName() const
	{
		return name();
	}
}
""")

# --- reflection/reflection.h: DescribedCreatable constructors ---
append("App/include/reflection/reflection.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename Class, typename DerivedClass, const char** ClassName>
	DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable()
	{
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	template<typename Arg0Type>
	DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable(Arg0Type arg0)
		: Reflection::Described<Class, ClassName, FactoryProduct<Class, DerivedClass, ClassName> >(arg0)
	{
	}
}
""")

# --- reflection/reflection.h: reference properties (values are Instance pointers; XML stores an IDREF
# the binder resolves later, through IIDREF::assignIDREF) ---
append("App/include/reflection/reflection.h", """
// rebuild overlay: RefPropDescriptor members rbxgs declares but never defines
class XmlElement;
namespace RBX
{
	// defined in rebuild glue (rbxgs/reflection_refs.cpp) so this header needs no serializer headers
	void rebuildAnnounceIDREF(IReferenceBinder& binder, const XmlElement* element, Reflection::DescribedBase* owner, const IIDREF* idref);
	void rebuildWriteIDREF(XmlElement* element, Instance* target);

	namespace Reflection
	{
		template<typename Class, typename ReturnType>
		bool RefPropDescriptor<Class, ReturnType>::isReadOnly() const
		{
			return getset->isReadOnly();
		}

		template<typename Class, typename ReturnType>
		ReturnType* RefPropDescriptor<Class, ReturnType>::getValue(const DescribedBase* object) const
		{
			return getset->getValue(object);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setValue(DescribedBase* object, ReturnType* value) const
		{
			getset->setValue(object, value);
		}

		template<typename Class, typename ReturnType>
		bool RefPropDescriptor<Class, ReturnType>::equalValues(const DescribedBase* a, const DescribedBase* b) const
		{
			return getValue(a) == getValue(b);
		}

		template<typename Class, typename ReturnType>
		DescribedBase* RefPropDescriptor<Class, ReturnType>::getRefValue(const DescribedBase* object) const
		{
			return getValue(object);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::setRefValue(DescribedBase* object, DescribedBase* value) const
		{
			setValue(object, dynamic_cast<ReturnType*>(value));
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::readValue(DescribedBase* object, const XmlElement* element, IReferenceBinder& binder) const
		{
			rebuildAnnounceIDREF(binder, element, object, this);
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::writeValue(const DescribedBase* object, XmlElement* element) const
		{
			rebuildWriteIDREF(element, getValue(object));
		}

		template<typename Class, typename ReturnType>
		void RefPropDescriptor<Class, ReturnType>::assignIDREF(DescribedBase* object, const InstanceHandle& handle) const
		{
			setValue(object, dynamic_cast<ReturnType*>(handle.getTarget().get()));
		}
	}
}
""")

# --- reflection/reflection.h: enum properties always have a text form (their item names) ---
append("App/include/reflection/reflection.h", """
// rebuild overlay: EnumPropDescriptor::hasStringValue rbxgs declares but never defines
namespace RBX
{
	namespace Reflection
	{
		template<typename Class, typename Enum>
		bool EnumPropDescriptor<Class, Enum>::hasStringValue() const
		{
			return true;
		}
	}
}
""")

# --- reflection/signal.h: generic (script) connections adapt boost::any argument vectors ---
append("App/include/reflection/signal.h", """
// rebuild overlay: SignalDescImpl members rbxgs declares but never defines
namespace RBX
{
	namespace Reflection
	{
		template<typename CallbackSignature>
		SignalDescImpl<0, CallbackSignature>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

		template<typename CallbackSignature>
		void SignalDescImpl<0, CallbackSignature>::GenericSlotAdapter::operator()()
		{
			std::vector<boost::any> args;
			wrapper->execute(args);
		}

		template<typename CallbackSignature>
		SignalDescImpl<1, CallbackSignature>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

		template<typename CallbackSignature>
		SignalDescImpl<2, CallbackSignature>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

		template<typename CallbackSignature>
		void SignalDescImpl<2, CallbackSignature>::GenericSlotAdapter::operator()(
			typename boost::function_traits<CallbackSignature>::arg1_type arg1,
			typename boost::function_traits<CallbackSignature>::arg2_type arg2)
		{
			std::vector<boost::any> args(2);
			args[0] = boost::any(arg1);
			args[1] = boost::any(arg2);
			wrapper->execute(args);
		}

#define RBX_REBUILD_CONNECT_GENERIC(N) \\
		template<typename CallbackSignature> \\
		boost::signals::connection SignalDescImpl<N, CallbackSignature>::connectGeneric( \\
			SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const \\
		{ \\
			typedef typename TSignalDesc<CallbackSignature>::TSignalInstance Typed; \\
			return static_cast<Typed*>(instance)->connect(GenericSlotAdapter(wrapper), pos); \\
		}
		RBX_REBUILD_CONNECT_GENERIC(0)
		RBX_REBUILD_CONNECT_GENERIC(1)
		RBX_REBUILD_CONNECT_GENERIC(2)
#undef RBX_REBUILD_CONNECT_GENERIC
	}
}
""")

# --- reflection/reflection.h: BoundFuncDesc constructors/execute declared without bodies.
# Variant k: arguments k..n carry defaults (k = n+1: none), matching the declared parameter lists. ---
def bound_func_desc(n, variants, with_body_members):
    tpl = "\t\ttemplate<typename Class, typename Function>\n"
    cls = "BoundFuncDesc<Class, Function, %d>" % n
    code = []
    for k in variants:
        params = ["typename %s::FunctionSig function" % cls, "const char* name"]
        inits = ["FuncDesc<Class>(name, security)", "function(function)"]
        for i in range(1, n + 1):
            params.append("const char* arg%dName" % i)
            if i >= k:
                params.append("typename %s::Arg%d default%d" % (cls, i, i))
                inits.append("default%d(default%d)" % (i, i))
            else:
                inits.append("default%d()" % i)
        params.append("Security security")
        code.append(tpl + "\t\t%s::BoundFuncDesc(%s)\n\t\t\t: %s\n\t\t{\n\t\t\tdeclareSignature(%s);\n\t\t}\n" % (
            cls, ", ".join(params), ", ".join(inits), ", ".join("arg%dName" % i for i in range(1, n + 1))))
    if with_body_members:
        names = ", ".join("const char* arg%dName" % i for i in range(1, n + 1))
        adds = "".join("\t\t\tsignature.addArgument(Name::declare(arg%dName, -1), Type::singleton<typename %s::Arg%d>(), default%d);\n"
                       % (i, cls, i, i) for i in range(1, n + 1))
        code.append(tpl + "\t\tvoid %s::declareSignature(%s)\n\t\t{\n\t\t\tsignature.resultType = &Type::singleton<typename %s::result_type>();\n%s\t\t}\n"
                    % (cls, names, cls, adds))
        gets = "".join("\t\t\tValue arg%d = default%d;\n\t\t\targuments.get(%d, arg%d);\n" % (i, i, i, i) for i in range(1, n + 1))
        args = ", ".join("arg%d.convert<typename %s::Arg%d>()" % (i, cls, i) for i in range(1, n + 1))
        code.append(tpl + "\t\tvoid %s::execute(DescribedBase* instance, Arguments& arguments) const\n\t\t{\n%s"
                    "\t\t\tClass* o = dynamic_cast<Class*>(instance);\n\t\t\tif (!o)\n\t\t\t\tthrow std::bad_cast();\n"
                    "\t\t\trebuildCall<typename %s::result_type>::run(arguments.returnValue, boost::bind(function, o, %s));\n\t\t}\n"
                    % (cls, gets, cls, args))
    return "\n".join(code)


append("App/include/reflection/reflection.h", """
// rebuild overlay: BoundFuncDesc members rbxgs declares but never defines
#include <boost/bind.hpp>
#include <typeinfo>
namespace RBX
{
	namespace Reflection
	{
		// stores the bound call's result unless it returns void
		template<typename R>
		struct rebuildCall
		{
			template<typename F>
			static void run(Value& result, F f) { result.set<R>(f()); }
		};
		template<>
		struct rebuildCall<void>
		{
			template<typename F>
			static void run(Value&, F f) { f(); }
		};

""" + bound_func_desc(1, [1], False) + "\n" + bound_func_desc(2, [3, 1], False) + "\n"
    + bound_func_desc(3, [4, 3, 2, 1], True) + "\n" + bound_func_desc(4, [5, 4, 3, 2, 1], True) + """
	}
}
""")

# --- v8datamodel/Stats.h: typed stats items (rbxgs leaves Stats unimplemented) ---
append("App/include/v8datamodel/Stats.h", """
// rebuild overlay: Stats template bodies rbxgs declares but never defines
#include <boost/bind.hpp>
#include "util/Utilities.h"
namespace RBX
{
	namespace Stats
	{
		template<typename T>
		T rebuildDeref(const T* value)
		{
			return *value;
		}

		template<typename T>
		TypedStatsItem<T>::TypedStatsItem(const T* value)
			: func(boost::bind(&rebuildDeref<T>, value))
		{
		}

		template<typename T>
		TypedStatsItem<T>::TypedStatsItem(boost::function0<T> func)
			: func(func)
		{
		}

		template<typename T>
		void TypedStatsItem<T>::update()
		{
			formatValue(func());
		}

		template<typename T>
		void Item::formatValue(const T& value)
		{
			setValue((double)value, StringConverter<T>::convertToString(value));
		}

		template<typename T>
		Item* Item::createBoundChildItem(const char* name, const T& value)
		{
			Item* item = Creatable<Instance>::create<TypedStatsItem<T> >(&value).get();
			item->setName(name);
			item->setParent(this);
			return item;
		}

		template<typename T>
		Item* Item::createChildItem(const char* name, boost::function0<T> func)
		{
			Item* item = Creatable<Instance>::create<TypedStatsItem<T> >(func).get();
			item->setName(name);
			item->setParent(this);
			return item;
		}
	}
}
""")

# --- util/StateStack.h: undo/redo stack (bounded; rbxgs declares the members only) ---
append("App/include/util/StateStack.h", """
// rebuild overlay: StateStack members rbxgs declares but never defines
namespace RBX
{
	template<typename T>
	StateStack<T>::~StateStack()
	{
		clearStack();
	}

	template<typename T>
	void StateStack<T>::clearStackAfter(int index)
	{
		while ((int)stack.size() > index + 1)
		{
			delete stack.back().undoState;
			delete stack.back().redoState;
			stack.pop_back();
		}
	}

	template<typename T>
	void StateStack<T>::pushState(std::string name, T* undoState, T* redoState)
	{
		clearStackAfter(currentState);
		StateEntry entry;
		entry.name = name;
		entry.undoState = undoState;
		entry.redoState = redoState;
		stack.push_back(entry);
		currentState = (int)stack.size() - 1;
		while (isStackTooBig() && !stack.empty())
		{
			delete stack.front().undoState;
			delete stack.front().redoState;
			stack.erase(stack.begin());
			--currentState;
		}
	}

	template<typename T>
	void StateStack<T>::pushState(const Name& name, T* undoState, T* redoState)
	{
		pushState(name.toString(), undoState, redoState);
	}

	template<typename T>
	void StateStack<T>::clearStack()
	{
		clearStackAfter(-1);
		currentState = -1;
	}

	template<typename T>
	bool StateStack<T>::canUndo(std::string& name) const
	{
		if (currentState < 0)
			return false;
		name = stack[currentState].name;
		return true;
	}

	template<typename T>
	T* StateStack<T>::undo()
	{
		return currentState < 0 ? NULL : stack[currentState--].undoState;
	}

	template<typename T>
	bool StateStack<T>::canRedo(std::string& name) const
	{
		if (currentState + 1 >= (int)stack.size())
			return false;
		name = stack[currentState + 1].name;
		return true;
	}

	template<typename T>
	T* StateStack<T>::redo()
	{
		return currentState + 1 >= (int)stack.size() ? NULL : stack[++currentState].redoState;
	}

	template<typename T>
	size_t StateStack<T>::getStackSize() const
	{
		return stack.size();
	}

	template<typename T>
	bool StateStack<T>::isStackTooBig() const
	{
		return stack.size() > 64;
	}
}
""")

# --- v8tree/Instance.h: the factory's deleter calls predelete() and the protected destructor
# (OpenRBX v8tree/Instance.h: friend class Creatable<Instance>::Deleter) ---
patch("App/include/v8tree/Instance.h", "\t\tfriend class RaiseDescendentAdded2;\n\n\tprivate:\n\t\tAssociation<Instance> assoc;",
      "\t\tfriend class RaiseDescendentAdded2;\n\t\tfriend class Creatable<Instance>::Deleter;\n\n\tprivate:\n\t\tAssociation<Instance> assoc;")

# --- v8datamodel/MouseCommand.h: the workspace dispatches input to the current command's handlers ---
patch("App/include/v8datamodel/MouseCommand.h", "\tclass MouseCommand : public INamed, public IRenderable\n\t{\n",
      "\tclass MouseCommand : public INamed, public IRenderable\n\t{\n\t\tfriend class Workspace;\n")

# --- Network/Streaming.cpp: an instance whose id is sent can be found by that id later
# (registry in glue_guid_registry.cpp) ---
patch("Network/Streaming.cpp", "namespace RBX\n{\n\tnamespace Network\n\t{\n",
      "namespace RBX\n{\n\tnamespace Network\n\t{\n\t\tvoid rebuildRegisterGuid(const Instance* instance);  // rebuild glue\n\n")
patch("Network/Streaming.cpp", "\t\t\t\tinstance->getGuid().extract(id);\n\n\t\t\t\tscopeNames.send(stream, id.scope->name);",
      "\t\t\t\tinstance->getGuid().extract(id);\n\t\t\t\trebuildRegisterGuid(instance);\n\n\t\t\t\tscopeNames.send(stream, id.scope->name);")

# --- Network/Players.cpp: the RakNet plugin adapter forwards packets to its owner ---
patch("Network/Players.cpp", "public:\n\tvirtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);\n};\n",
      "public:\n\tvirtual PluginReceiveResult OnReceive(RakPeerInterface* peer, Packet* packet);\n};\n\n"
      "// rebuild overlay: rbxgs declares this but never defines it; the owner says whether it consumed the packet\n"
      "template<class Class>\nPluginReceiveResult PluginInterfaceAdapter<Class>::OnReceive(RakPeerInterface* peer, Packet* packet)\n{\n"
      "\treturn c->OnReceive(peer, packet) ? RR_STOP_PROCESSING_AND_DEALLOCATE : RR_CONTINUE_PROCESSING;\n}\n")

# --- v8world/SimJobStage.h: hand mechanisms to a reporter round-robin, resuming where the last pass stopped ---
append("App/include/v8world/SimJobStage.h", """
// rebuild overlay: SimJobStage::reportMechanisms rbxgs declares but never defines
#include "v8world/Mechanism.h"
namespace RBX
{
	template<typename Class>
	void SimJobStage::reportMechanisms(Class& callback, MechanismTracker& tracker, const Mechanism* ignore)
	{
		if (mechanisms.empty())
			return;
		Mechanism* start = tracker.tracking() ? tracker.getMechanism() : mechanisms.front();
		Mechanism* current = start;
		do
		{
			if (current != ignore && !callback(*current))
			{
				tracker.setMechanism(nextMechanism(mechanisms, current));  // reporter is full: resume after this one
				return;
			}
			current = nextMechanism(mechanisms, current);
		} while (current != start);
		tracker.setMechanism(start);
	}
}
""")

# --- v8tree/Service.h: service lookup by class name (OpenRBX v8tree/Service.h finds by className too) ---
append("App/include/v8tree/Service.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename Class>
	Class* ServiceProvider::find() const
	{
		return dynamic_cast<Class*>(findServiceByClassName(Class::className()).get());
	}

	template<typename Class>
	Class* ServiceProvider::create() const
	{
		return dynamic_cast<Class*>(ServiceProvider::create(const_cast<ServiceProvider*>(this), Class::className()));
	}

	template<typename Class>
	Class* ServiceProvider::find(const Instance* context)
	{
		return find<Class>(findServiceProvider(context));
	}

	template<typename Class>
	Class* ServiceProvider::create(const Instance* context)
	{
		return create<Class>(findServiceProvider(context));
	}

	template<typename Class>
	size_t ServiceProvider::doGetClassIndex()
	{
		static size_t index = newIndex();
		return index;
	}

	template<typename Class>
	void ServiceProvider::callDoGetClassIndex()
	{
		doGetClassIndex<Class>();
	}
}
""")

# --- reflection/type.h: Value::convert (semantics read from the exact 2008 source of
# Value::convert<int> at 0x56dc00: held value, else parse a held string, else throw) ---
append("App/include/reflection/type.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
#include <stdexcept>
#include <stdio.h>
#include "util/Utilities.h"
namespace RBX
{
	namespace Reflection
	{
		// types without a StringConverter never convert from text
		template<typename T>
		inline bool rebuildFromString(const std::string&, T&) { return false; }
#define RBX_REBUILD_FROM_STRING(T) \\
		template<> inline bool rebuildFromString<T>(const std::string& text, T& value) { return StringConverter<T>::convertToValue(text, value); }
		RBX_REBUILD_FROM_STRING(bool) RBX_REBUILD_FROM_STRING(int) RBX_REBUILD_FROM_STRING(unsigned)
		RBX_REBUILD_FROM_STRING(float) RBX_REBUILD_FROM_STRING(double)
#undef RBX_REBUILD_FROM_STRING

		template<typename T>
		T& Value::convert()
		{
			if (T* held = boost::any_cast<T>(&value))
				return *held;
			if (const std::string* text = boost::any_cast<std::string>(&value))
			{
				T converted;
				if (rebuildFromString(*text, converted))
				{
					set(converted);
					return *boost::any_cast<T>(&value);
				}
			}
			char message[256];
			_snprintf(message, sizeof(message), "Unable to cast %s to %s", type().name.c_str(), Type::singleton<T>().name.c_str());
			throw std::runtime_error(message);
		}

		template<typename T>
		T& Value::genericConvert()
		{
			return convert<T>();
		}

		template<typename T>
		T Value::get() const
		{
			return boost::any_cast<T>(value);
		}
	}
}
""")

# --- reflection/property.h: typed access through the descriptor. 2008 0x4accd0/0x4ad060
# check the descriptor with RTTI and throw bad_cast; 0x4acd50/0x4ad240 do likewise for writes. ---
append("App/include/reflection/property.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
#include <boost/cast.hpp>
namespace RBX
{
	namespace Reflection
	{
		template<typename T>
		T ConstProperty::getValue() const
		{
			return boost::polymorphic_cast<const TypedPropertyDescriptor<T>*>(descriptor)->getValue(instance);
		}

		template<typename T>
		void Property::setValue(const T& value)
		{
			boost::polymorphic_cast<const TypedPropertyDescriptor<T>*>(descriptor)->setValue(getInstance(), value);
		}
	}
}
""")

# --- util/Utilities.h: CopyOnWrite (bodies as in OpenRBX util/Utilities.h) ---
append("App/include/util/Utilities.h", """
// rebuild overlay: template bodies rbxgs declares but never defines (as OpenRBX util/Utilities.h)
namespace RBX
{
	template<typename T>
	boost::shared_ptr<T>& CopyOnWrite<T>::write()
	{
		if (!object)
			object = boost::shared_ptr<T>(new T());
		else if (object.use_count() > 1)
			object = boost::shared_ptr<T>(new T(*object));
		return object;
	}

	template<typename T>
	void CopyOnWrite<T>::reset()
	{
		object.reset();
	}
}
""")

# --- util/Association.h: per-type slots (rbxgs: "uses templated functions: add those in manually") ---
append("App/include/util/Association.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename Associated>
	Association<Associated>::Item::~Item()
	{
	}

	template<typename Associated>
	template<typename T>
	Association<Associated>::TItem<T>::TItem()
		: t()
	{
	}

	template<typename Associated>
	size_t& Association<Associated>::count()
	{
		static size_t n = 0;
		return n;
	}

	// one slot index per associated type, allocated on first use
	template<typename Associated, typename T>
	size_t rebuildAssociationSlot(size_t& count)
	{
		static size_t slot = count++;
		return slot;
	}

	template<typename Associated>
	Association<Associated>::~Association()
	{
		for (size_t i = 0; i < items.size(); ++i)
			delete items[i];
	}

	template<typename Associated>
	template<typename T>
	bool Association<Associated>::contains() const
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		return slot < items.size() && items[slot] != NULL;
	}

	template<typename Associated>
	template<typename T>
	T& Association<Associated>::get()
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		if (items.size() <= slot)
			items.resize(slot + 1, NULL);
		if (!items[slot])
			items[slot] = new TItem<T>();
		return static_cast<TItem<T>*>(items[slot])->t;
	}

	template<typename Associated>
	template<typename T>
	void Association<Associated>::remove()
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		if (slot < items.size())
		{
			delete items[slot];
			items[slot] = NULL;
		}
	}
}
""")

# --- v8datamodel/GlobalSettings.h: settings items are lazily created services of GlobalSettings ---
append("App/include/v8datamodel/GlobalSettings.h", """
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
""")

out = Path(__file__).with_name("rbxgs-client.json")
# --- Phase 4 canonical headers: 2008 layouts adopted from the exact generated units (header-catalog.json) ---
# EnumDescriptor::Item {owner, value, index}, pure lookup, EnumDesc enumToItem: native-owner header, 7 exact units;
# the genuine-owner header (3 units) agrees on Item.
adopt("App/include/reflection/enumconverter.h", "App/roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
# IRenderable: index accessors public (VS2008 checks them inside IndexArray<..., &IRenderable::indexFunc2d>
# in Workspace); layout unchanged. Same text as 53 exact units' header.
adopt("App/include/util/IRenderable.h", "App/roc_espeon_renderableindexaccessae7c6fa24fc9f234.cpp")
# JointInstance holds weak_ptr<PartInstance> part[2]; Gyro's part is a weak_ptr (17 and 14 exact units).
adopt("App/include/v8datamodel/JointInstance.h", "App/roc_unit_ffc89e90dbae649c.cpp")
adopt("App/include/v8datamodel/Gyro.h", "App/roc_unit_49d5cd98eaed3b87.cpp")


def patch_all(rel, old, new):
    """Every occurrence of old in rel (anchor checked against the original file)."""
    if old not in (TREE / rel).read_text(errors="replace"):
        raise SystemExit("%s: anchor not found: %r" % (rel, old[:60]))
    patches.setdefault(rel, []).append(["@all:" + old, new])


# ScriptContext::reportError: the Lua error is data, not a format (a non-string error object is NULL here)
patch_all("App/script/ScriptContext.cpp", "StandardOut::singleton()->print(MESSAGE_ERROR, lua_tostring(thread, -1));",
          "StandardOut::singleton()->print(MESSAGE_ERROR, \"%s\", lua_tostring(thread, -1) ? lua_tostring(thread, -1) : \"(error object)\");")
patch("App/script/ScriptContext.cpp", "        std::string err = lua_tostring(thread, -1);\n",
      "        std::string err = lua_tostring(thread, -1) ? lua_tostring(thread, -1) : \"(error object)\";\n")
# LuaBridge: a C++ exception from a member access must become a Lua error carrying its message (Lua built as
# C++ catches it with catch(...) and the script only sees a non-string error object)
patch("App/include/lua/LuaBridge.h",
      "                const char* name = luaL_checkstring(L, 2);\n                T& object = getObject(L, 1);\n"
      "                on_newindex(object, name, L);\n                return 0;\n",
      "                const char* name = luaL_checkstring(L, 2);\n                T& object = getObject(L, 1);\n"
      "                try\n                {\n                    on_newindex(object, name, L);\n                    return 0;\n"
      "                }\n                catch (std::exception& e)\n                {\n                    lua_pushstring(L, e.what());\n"
      "                }\n                return lua_error(L);\n")
patch("App/include/lua/LuaBridge.h",
      "                const char* name = luaL_checkstring(L, 2);\n                T& object = getObject(L, 1);\n"
      "                return on_index(object, name, L);\n",
      "                const char* name = luaL_checkstring(L, 2);\n                T& object = getObject(L, 1);\n"
      "                try\n                {\n                    return on_index(object, name, L);\n"
      "                }\n                catch (std::exception& e)\n                {\n                    lua_pushstring(L, e.what());\n"
      "                }\n                return lua_error(L);\n")
# The object and signal bridges specialise on_newindex in their .cpp files, but LuaBridge.h gives the generic
# member an inline body ("cannot be assigned to"), so every other unit used that body and no script could set a
# property. Declaring the specialisations where the bridges are declared makes every unit call them.
# the generic member is declared in the class and defined out of it, so the specialisations below are ordinary
# (emitted) functions rather than inline ones MSVC drops from their own unit
patch("App/include/lua/LuaBridge.h",
      "            static void on_newindex(T& object, const char* name, lua_State* L)\n            {\n"
      "                throw std::runtime_error(G3D::format(\"%s cannot be assigned to\", name));\n            }\n",
      "            static void on_newindex(T& object, const char* name, lua_State* L);\n")
append("App/include/lua/LuaBridge.h", """
namespace RBX { namespace Reflection { class DescribedBase; class SignalInstance; } }
namespace RBX
{
    namespace Lua
    {
        template <typename T, bool isComparable>
        void Bridge<T, isComparable>::on_newindex(T& object, const char* name, lua_State* L)
        {
            throw std::runtime_error(G3D::format("%s cannot be assigned to", name));
        }
        template<>
        void Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>::on_newindex(boost::shared_ptr<Reflection::DescribedBase>& object, const char* name, lua_State* L);
        template<>
        void Bridge<boost::shared_ptr<Reflection::SignalInstance>, false>::on_newindex(boost::shared_ptr<Reflection::SignalInstance>& object, const char* name, lua_State* L);
    }
}
""")
# TextXmlParser::readText: consume each character (rbxgs peeks with sgetc forever and runs out of memory)
patch("App/v8xml/XmlSerializer.cpp", "\twhile ((char)buffer->sgetc() != '<')\n\t\ttext += buffer->sgetc();\n",
      "\twhile ((char)buffer->sgetc() != '<')\n\t\ttext += (char)buffer->sbumpc();\n")
# TextXmlParser::parse: the root element has no parent to be added to (rbxgs dereferences the empty stack's NULL)
patch("App/v8xml/XmlSerializer.cpp", "\t\t\tcurrentElement->pushBackChild(newElement);\n",
      "\t\t\tif (currentElement)\n\t\t\t\tcurrentElement->pushBackChild(newElement);\n")

# Gyro.cpp against the weak_ptr part: lock where it is used, expired() where it was compared with NULL
GYRO = "App/v8datamodel/Gyro.cpp"
patch(GYRO, "\t\t  part(NULL)", "\t\t  part()")
patch(GYRO, "RBXASSERT(part == NULL);", "RBXASSERT(part.expired());")
patch(GYRO, "(part != NULL) ?", "!part.expired() ?")
patch(GYRO, "part = dynamic_cast<PartInstance*>(event.newParent);",
      "part = boost::shared_dynamic_cast<PartInstance>(shared_from(event.newParent));")
patch(GYRO, "if (active && !firedEvent && part)", "if (active && !firedEvent && !part.expired())")
patch_all(GYRO, "part->", "part.lock()->")
# Instance derives first from GuidItem<Instance> {vptr, registeredGuid @4, guid @8}, then
# enable_shared_from_this (37 exact units; 15 others place onGuidChanged elsewhere in the vtable: unresolved).
# getGuid/assignGuid are out of line (glue_instance_core.cpp); GuidItem's members are protected for them.
INST, INST_UNIT = "App/include/v8tree/Instance.h", "App/roc_unit_b34763c2f3d3f398.cpp"
adopt(INST, INST_UNIT)
patch_adopted(INST, INST_UNIT, "\tvirtual ~GuidItem() {}\n\nprivate:\n\tbool registeredGuid;",
              "\tvirtual ~GuidItem() {}\n\nprotected:\n\tbool registeredGuid;")
# reflection/object.h: the 4-unit variant is the rbxgs text unchanged; adopting it by name admits those units
adopt("App/include/reflection/object.h", "App/roc_espeon_machineheadercadaaebe20af2047.cpp")
# Instance.cpp: guid is a GuidItem<Instance> member now, constructed by that base
patch_all("App/v8tree/Instance.cpp", "\t\t  archivable(true),\n\t\t  guid()", "\t\t  archivable(true)")
# the factory's deleter calls predelete() and the protected destructor (as the patch above, on the adopted text)
patch_adopted(INST, INST_UNIT, "\t\tfriend class RaiseDescendentAdded2;\n\n\tprivate:\n\t\tAssociation<Instance> assoc;",
              "\t\tfriend class RaiseDescendentAdded2;\n\t\tfriend class Creatable<Instance>::Deleter;\n\n\tprivate:\n\t\tAssociation<Instance> assoc;")

# --- 2008 has no AutoJoint: Weld/Snap/Glue/Rotate*/Motor derive from JointInstance (RTTI base list of Weld:
# DescribedCreatable<Weld, JointInstance, &sWeld>; no .?AVAutoJoint@RBX@@ in the exe), which is 0x154 bytes with
# weak_ptr<PartInstance> part[2] @0x140 and joint @0x150 (abi-evidence: Weld allocates 0x154). The 2008
# JointInstance(Joint*) constructor (0x5e3870) sets joint, calls setJointOwner, then assigns
# shared_from(PartInstance::fromPrimitive(joint->getPrimitive(i))) to part[0] and part[1]: AutoJoint's body. ---
JOINT, JOINT_UNIT = "App/include/v8datamodel/JointInstance.h", "App/roc_unit_ffc89e90dbae649c.cpp"
_joint_text = (TREE / JOINT_UNIT).read_text(errors="replace")
_auto_start = _joint_text.index("\textern const char* sAutoJoint;\n")
_auto_end = _joint_text.index("\t};\n", _auto_start) + len("\t};\n")
patch_adopted(JOINT, JOINT_UNIT, _joint_text[_auto_start:_auto_end], "")
patch_adopted(JOINT, JOINT_UNIT, "\tpublic:\n\t\tJointInstance(Joint* joint);\n\t\t~JointInstance();\n",
              "\t\tvoid setPart(int i, PartInstance* value);\n\t\tvoid setPartNull(int);\n\t\tvoid setPrimitiveFromPart(int);\n\n"
              "\t\tvirtual bool askSetParent(const Instance* instance) const;\n"
              "\t\tvirtual void onAncestorChanged(const AncestorChanged& event);\n\n\t\tWorld* computeWorld();\n\n"
              "\tpublic:\n\t\tJointInstance(Joint* joint);\n\t\t~JointInstance();\n\n"
              "\t\tPartInstance* getPart0() const;\n\t\tPartInstance* getPart1() const;\n\n"
              "\t\tvoid setPart0(PartInstance* value);\n\t\tvoid setPart1(PartInstance* value);\n\n"
              "\t\tconst G3D::CoordinateFrame& getC0() const;\n\t\tconst G3D::CoordinateFrame& getC1() const;\n\n"
              "\t\tvoid setC0(const G3D::CoordinateFrame& value);\n\t\tvoid setC1(const G3D::CoordinateFrame& value);\n")
if "AutoJoint" not in _joint_text[:_auto_start] + _joint_text[_auto_end:]:
    raise SystemExit("JointInstance.h: no subclass of AutoJoint left to rebase")
patches[JOINT].append(["@all:AutoJoint", "JointInstance"])

JOINT_CPP = "App/v8datamodel/JointInstance.cpp"
_cpp = (TREE / JOINT_CPP).read_text(errors="replace")
_ctor_start = _cpp.index("\tconst char* sAutoJoint = \"AutoJoint\";\n")
_ctor_end = _cpp.index("\tPartInstance* AutoJoint::getPart0() const")
patch(JOINT_CPP, _cpp[_ctor_start:_ctor_end], "")
patch(JOINT_CPP, "\t\t: joint(joint)\n\t{\n\t\tjoint->setJointOwner(this);\n\t}\n",
      "\t\t: joint(joint)\n\t{\n\t\tjoint->setJointOwner(this);\n\n"
      "\t\tPartInstance* part0 = PartInstance::fromPrimitive(joint->getPrimitive(0));\n"
      "\t\tPartInstance* part1 = PartInstance::fromPrimitive(joint->getPrimitive(1));\n\n"
      "\t\tpart[0] = shared_from(part0);\n\t\tpart[1] = shared_from(part1);\n\t}\n")
patch(JOINT_CPP, "\tJointInstance::~JointInstance()\n\t{\n",
      "\tJointInstance::~JointInstance()\n\t{\n\t\tsetPart(0, NULL);\n\t\tsetPart(1, NULL);\n\n")
patch(JOINT_CPP, "\t\treturn part[0].get();", "\t\treturn part[0].lock().get();")
patch(JOINT_CPP, "\t\treturn part[1].get();", "\t\treturn part[1].lock().get();")
patch(JOINT_CPP, "\t\tif (part[i].get() != value)", "\t\tif (part[i].lock().get() != value)")
patch_all(JOINT_CPP, "AutoJoint", "JointInstance")
patch_all("App/humanoid/Humanoid.cpp", "AutoJoint", "JointInstance")

# --- IModelModifier (RTTI .?AVIModelModifier@RBX@@, in neither tree): a polymorphic interface whose only vtable
# slot is the destructor (Skin's IModelModifier vtable 0x83c82c: `sub ecx, 0x130; jmp` to Skin's deleting
# destructor). ModelInstance cross-casts dynamic_cast<IModelModifier*>(Instance*) (exact 0x584fc0). Bases per RTTI:
# CharacterAppearance (BodyColors, Clothing, Pants, Shirt, ShirtGraphic, Skin) at 0x130 right after Instance;
# Humanoid at 0x1a0 between ICharacterSubject and Listener<RunService, Stepped>. Each adds the 4 bytes the 2008
# allocation sizes show (Skin 0x138, BodyColors 0x14c, ShirtGraphic 0x154, Humanoid 0x22c). ---
patch_adopted(INST, INST_UNIT, "\textern const char* sInstance;\n",
              "\tclass IModelModifier\n\t{\n\tpublic:\n\t\tvirtual ~IModelModifier() {}\n\t};\n\n\textern const char* sInstance;\n")
patch("App/include/v8datamodel/CharacterAppearance.h", "\tclass CharacterAppearance : public Instance\n",
      "\tclass CharacterAppearance : public Instance, public IModelModifier\n")
patch("App/include/humanoid/Humanoid.h", "\t\t\t\t\t public ICharacterSubject,\n\t\t\t\t\t public Listener<RunService, Stepped>\n",
      "\t\t\t\t\t public ICharacterSubject,\n\t\t\t\t\t public IModelModifier,\n\t\t\t\t\t public Listener<RunService, Stepped>\n")

# ModelInstance keeps its IModelModifier children: std::vector<IModelModifier*> at 0x1ec, right after
# candidatePrimaryPart (exact removeIModelModifier 0x584fc0 reads _Myfirst/_Mylast at 0x1f8/0x1fc; the 2008
# destructor 0x584790 frees the vector's proxy at 0x1ec and buffer at 0x1f8). Allocation 0x2a4 = +0x18.
patch("App/include/v8datamodel/ModelInstance.h", "\t\tboost::shared_ptr<PartInstance> candidatePrimaryPart;\n",
      "\t\tboost::shared_ptr<PartInstance> candidatePrimaryPart;\n\t\tstd::vector<IModelModifier*> modifiers;\n")
# FaceInstance (Decal, Texture) is also an IRenderable: RTTI places it at 0x130 after Instance, and the 2008 Decal
# constructor (0x598400) puts texture at 0x144 (rbxgs 0x134); allocation 0x16c.
FACE = "App/include/v8datamodel/FaceInstance.h"
patch(FACE, '#include "util/NormalId.h"\n', '#include "util/NormalId.h"\n#include "util/IRenderable.h"\n')
patch(FACE, "\tclass FaceInstance : public Reflection::Described<FaceInstance, &sFaceInstance, Instance> \n",
      "\tclass FaceInstance : public Reflection::Described<FaceInstance, &sFaceInstance, Instance>, public IRenderable\n")
# DebrisService: rbxgs pads 8 bytes before queue to stand in for GuidItem's members missing from its Instance; with
# the adopted 2008 Instance (0x130) the 2008 constructor (0x63be90) has queue at 0x130, maxItems 0x150, timer 0x154.
adopt("App/include/v8datamodel/DebrisService.h", "App/roc_native_debris_header_2c0ad23d27535ab8.cpp")
# IDataState is a bare interface in 2008: DataModel's RTTI base list has no StateStack, and IDataState spans only
# 0x1f0..0x1f4 (vptr) between VerbContainer and Evaluator.
patch("App/include/v8tree/Verb.h", "\tclass __declspec(novtable) IDataState : public StateStack<XmlState> // NOTE: may not be intended for this file\n",
      "\tclass __declspec(novtable) IDataState\n")
# without the StateStack base DataModel has no isStackTooBig override (it only overrode StateStack's virtual)
patch("App/include/v8datamodel/DataModel.h", "\t\tvirtual bool isStackTooBig() const;\n\n", "")
# --- Primitive, 2008 layout (0xfc bytes; PartInstance embeds it at 0x228). The exact 2008 constructor (0x5e8770)
# stores: guidSetExternally 0x10, edgeVersion 0x14 = 1, contacts {owner 0x18, Array 0x1c, Array 0x28} and joints
# {owner 0x34, ...}, worldIndex 0x50 = -1, traverseId 0x54 = -1, world 0x58, clump 0x5c, clumpDepth 0x60 = -1,
# spatialNodes 0x64, ..., geometry 0x9c, body 0xa0, myOwner 0xa4, dragging/anchored/0xaa/0xab bytes, canCollide 0xac,
# controller 0xe8, JointK 0xec. An EdgeList is arrays, not an intrusive list: the exact 0x5e8990 appends the edge,
# records its index in the edge (0x14 for primitive 0, 0x18 for 1) and appends the other primitive; the exact
# 0x5e8610 swap-removes it and fixes the moved edge's index. Edge keeps those indices where rbxgs had next0/next1. ---
EDGE_H = "App/include/v8world/Edge.h"
patch(EDGE_H, "\t\tEdge* next0;\n\t\tEdge* next1;\n", "\t\tint index0;\n\t\tint index1;\n")
patch(EDGE_H, "\t\tEdge* getNext(const Primitive* p) const\n\t\t{\n\t\t\treturn p == prim0 ? next0 : next1;\n\t\t}\n"
      "\t\tvoid setNext(Primitive* p, Edge* e)\n\t\t{\n\t\t\tif (p == prim0)\n\t\t\t\tnext0 = e;\n\t\t\telse\n\t\t\t\tnext1 = e;\n\t\t}\n",
      "\t\tint getIndex(const Primitive* p) const\n\t\t{\n\t\t\treturn p == prim0 ? index0 : index1;\n\t\t}\n"
      "\t\tvoid setIndex(const Primitive* p, int i)\n\t\t{\n\t\t\tif (p == prim0)\n\t\t\t\tindex0 = i;\n\t\t\telse\n\t\t\t\tindex1 = i;\n\t\t}\n")
patch("App/v8world/Edge.cpp", "\t\t  next0(NULL),\n\t\t  next1(NULL),\n", "\t\t  index0(-1),\n\t\t  index1(-1),\n")

PRIM_H, PRIM_CPP = "App/include/v8world/Primitive.h", "App/v8world/Primitive.cpp"
_prim_h = (TREE / PRIM_H).read_text(errors="replace")
_el_start = _prim_h.index("\tclass EdgeList\n")
_el_end = _prim_h.index("\t};\n", _el_start) + len("\t};\n")
patch(PRIM_H, _prim_h[_el_start:_el_end],
      "\tclass EdgeList\n\t{\n\tpublic:\n\t\tPrimitive* owner;\n\t\tG3D::Array<Edge*> edges;\n"
      "\t\tG3D::Array<Primitive*> neighbors; // the other primitive of each edge\n\n"
      "\tpublic:\n\t\tEdgeList(Primitive* owner) : owner(owner) {}\n\n\t\tbool hasEdge();\n"
      "\t\tvoid insertEdge(Edge* e);\n\t\tvoid removeEdge(Edge* e);\n\t\tEdge* first() const;\n\t\tEdge* next(Edge* e) const;\n\t};\n")
patch(PRIM_H, "\t\tbool guidSetExternally;\n\t\tEdgeList contacts;\n\t\tEdgeList joints;\n\t\tint worldIndex;\n"
      "\t\tWorld* world;\n\t\tClump* clump;\n\t\tint clumpDepth;\n\t\tint traverseId;\n",
      "\t\tbool guidSetExternally;\n\t\tint edgeVersion;\n\t\tEdgeList contacts;\n\t\tEdgeList joints;\n\t\tint worldIndex;\n"
      "\t\tint traverseId;\n\t\tWorld* world;\n\t\tClump* clump;\n\t\tint clumpDepth;\n")
patch(PRIM_H, "\t\tIMoving* myOwner;\n\t\tAnchor* anchorObject;\n\t\tbool dragging;\n\t\tbool anchored;\n\t\tbool canCollide;\n\t\tbool canSleep;\n",
      "\t\tIMoving* myOwner;\n\t\tbool dragging;\n\t\tbool anchored;\n\t\tbool flag0xaa; // 0xaa: third of the dragging/anchored set (exact 0x5e8140); name unknown\n"
      "\t\tbool canSleep;\n\t\tbool canCollide;\n")
# rbxgs keeps an Anchor* in Primitive; the 2008 Primitive has no slot for it (and 2008 anchors through an
# AnchorJoint class rbxgs lacks). Until that is reconstructed, the Anchor objects live in a rebuild-side table
# (glue_anchor_registry.cpp, tracked shim) so the layout stays 2008's.
patch(PRIM_H, "\t\t\treturn anchorObject != NULL;\n\t\t}\n\t\tAnchor* getAnchorObject()\n\t\t{\n\t\t\treturn anchorObject;\n\t\t}\n",
      "\t\t\treturn getAnchorObject() != NULL;\n\t\t}\n\t\tAnchor* getAnchorObject() const; // rebuild shim (glue_anchor_registry.cpp)\n"
      "\t\tvoid setAnchorObject(Anchor* anchor);\n")
patch(PRIM_CPP, "\t\t\tRBXASSERT(!anchorObject);\n\t\t\tanchorObject = new Anchor(this);",
      "\t\t\tRBXASSERT(!getAnchorObject());\n\t\t\tsetAnchorObject(new Anchor(this));")
patch(PRIM_CPP, "\t\t\tRBXASSERT(anchorObject);", "\t\t\tRBXASSERT(getAnchorObject());")
patch(PRIM_CPP, "\t\t\tif (anchorObject)\n\t\t\t\tdelete anchorObject;\n\n\t\t\tanchorObject = NULL;",
      "\t\t\tdelete getAnchorObject();\n\t\t\tsetAnchorObject(NULL);")
patch(PRIM_H, "\t\t\treturn joints.num;", "\t\t\treturn joints.edges.size();")
patch(PRIM_H, "\t\t\treturn contacts.num;", "\t\t\treturn contacts.edges.size();")


patch(PRIM_CPP, "\t\tmyOwner(NULL),\n\t\tanchorObject(NULL),\n\t\tdragging(false),\n\t\tanchored(false),\n",
      "\t\tmyOwner(NULL),\n\t\tdragging(false),\n\t\tanchored(false),\n\t\tflag0xaa(false),\n")
patch(PRIM_CPP, "\t\tspatialNodes(NULL),\n\t\tworldIndex(-1),\n",
      "\t\tspatialNodes(NULL),\n\t\tedgeVersion(1),\n\t\tcontacts(this),\n\t\tjoints(this),\n\t\tworldIndex(-1),\n")
patch(PRIM_CPP, "\t\treturn joints.first ? joints.first : contacts.first;",
      "\t\treturn joints.edges.size() ? joints.first() : contacts.first();")
patch(PRIM_CPP, "\t\treturn rbx_static_cast<Joint*>(joints.first);", "\t\treturn rbx_static_cast<Joint*>(joints.first());")
patch(PRIM_CPP, "\t\treturn rbx_static_cast<Contact*>(contacts.first);", "\t\treturn rbx_static_cast<Contact*>(contacts.first());")
patch(PRIM_CPP, "\t\treturn rbx_static_cast<Joint*>(prev->getNext(this));", "\t\treturn rbx_static_cast<Joint*>(joints.next(prev));")
patch(PRIM_CPP, "\t\treturn rbx_static_cast<Contact*>(prev->getNext(this));", "\t\treturn rbx_static_cast<Contact*>(contacts.next(prev));")
patch(PRIM_CPP, "\t\tEdge* next = e->getNext(this);\n\n\t\tif (next)\n\t\t\treturn next;\n\t\telse\n\t\t\treturn Joint::isJoint(e) ? contacts.first : NULL;",
      "\t\tif (Joint::isJoint(e))\n\t\t{\n\t\t\tEdge* next = joints.next(e);\n\t\t\treturn next ? next : contacts.first();\n\t\t}\n\t\treturn contacts.next(e);")
for _verb in ("insertEdge", "removeEdge"):
    for _i, _list in ((0, "joints"), (1, "joints"), (0, "contacts"), (1, "contacts")):
        _old = "EdgeList::%s(p%d, e, e->getPrimitive(%d)->%s);" % (_verb, _i, _i, _list)
        patch_all(PRIM_CPP, _old, "e->getPrimitive(%d)->%s.%s(e);" % (_i, _list, _verb))
_cpp_p = (TREE / PRIM_CPP).read_text(errors="replace")
_ins = _cpp_p.index("\tvoid EdgeList::insertEdge(Primitive* p, Edge* e, EdgeList& list)\n")
_rem_end = _cpp_p.index("\t\tlist.num--;\n\t}\n", _ins) + len("\t\tlist.num--;\n\t}\n")
patch(PRIM_CPP, _cpp_p[_ins:_rem_end],
      "\tvoid EdgeList::insertEdge(Edge* e)\n\t{\n\t\te->setIndex(owner, edges.size());\n\t\tedges.append(e);\n"
      "\t\tneighbors.append(e->otherPrimitive(owner));\n\t}\n\n"
      "\tvoid EdgeList::removeEdge(Edge* e)\n\t{\n\t\tint index = e->getIndex(owner);\n\t\tEdge* lastEdge = edges.last();\n"
      "\t\tPrimitive* lastNeighbor = neighbors.last();\n\t\tedges[index] = lastEdge;\n\t\tneighbors[index] = lastNeighbor;\n"
      "\t\tedges.popDiscard();\n\t\tneighbors.popDiscard();\n\t\tlastEdge->setIndex(owner, index);\n\t\te->setIndex(owner, -1);\n\t}\n\n"
      "\tEdge* EdgeList::first() const\n\t{\n\t\treturn edges.size() ? edges[0] : NULL;\n\t}\n\n"
      "\tEdge* EdgeList::next(Edge* e) const\n\t{\n\t\tint i = e->getIndex(owner) + 1;\n\t\treturn i < edges.size() ? edges[i] : NULL;\n\t}\n")
# --- PartInstance embeds its Primitive (2008 constructor 0x59d4d0 constructs Primitive(GEOMETRY_BLOCK) in place at
# this+0x228; the next member, myWorld, is at 0x324 = 0x228 + 0xfc) and has a ContentId after SurfacesNeedAdorn at
# 0x3c8 (std::string constructed in place, mimeTypePtr = &Name::getNullName() at +0x1c), ending at 0x3e8 where the
# vbtable puts the virtual bases (vbtable 0x849e6c: -308, 696, 704, 712). Allocation 0x404. ---
PI_H, PI_CPP = "App/include/v8datamodel/PartInstance.h", "App/v8datamodel/PartInstance.cpp"
patch(PI_H, '#include "util/ISelectable3d.h"\n', '#include "util/ISelectable3d.h"\n#include "util/ContentProvider.h"\n')
patch(PI_H, "\t\tboost::scoped_ptr<Primitive> primitive;\n", "\t\tPrimitive primitive;\n")
patch(PI_H, "\t\tComputeProp<bool, PartInstance> SurfacesNeedAdorn;\n",
      "\t\tComputeProp<bool, PartInstance> SurfacesNeedAdorn;\n\t\tContentId contentId0x3c8; // 0x3c8; name and use unknown\n")
patch_all(PI_H, "primitive.get()", "&primitive")
patch(PI_CPP, "\t\t  primitive(new Primitive(Geometry::GEOMETRY_BLOCK)),\n", "\t\t  primitive(Geometry::GEOMETRY_BLOCK),\n")
patch_all(PI_CPP, "primitive.get()", "&primitive")
patch_all(PI_CPP, "primitive->", "primitive.")
# Body is 0xdc bytes in 2008 (Primitive's constructor 0x5e8770 allocates 0xdc for it; rbxgs 0xd0). The exact 2008
# Body constructor (0x6149c0) stores kernelIndex 0x0 = -1, then 0x4 = -1, 0x8 = 0, byte 0xc = false, root 0x10 = this,
# parent 0x14, index 0x18 = -1, ... pv 0x94: rbxgs's members shifted by 0xc. KernelIndex itself is 4 bytes (Humanoid's
# RTTI: KernelIndex 0x134, IControllable 0x138), so the 12 bytes are Body's own; their names and use are unknown.
patch("App/include/v8kernel/Body.h", "\t\t\tint& getIndex() {return index;};\n\t\t\tBody *root;\n",
      "\t\t\tint& getIndex() {return index;};\n\t\t\tint unknown0x4;    // 0x4 = -1 in the 2008 constructor; name and use unknown\n"
      "\t\t\tvoid* unknown0x8;  // 0x8 = 0\n\t\t\tbool unknown0xc;   // 0xc = false\n\t\t\tBody *root;\n")
patch("App/v8kernel/Body.cpp", "Body::Body()\n\t:index(-1),\n",
      "Body::Body()\n\t:unknown0x4(-1),\n\tunknown0x8(NULL),\n\tunknown0xc(false),\n\tindex(-1),\n")
# --- Workspace members, 2008 order (constructor 0x5a4d90, destructor 0x5a28c0; allocation 0x45c): idleMouseEvent
# 0x3b8, a pointer 0x3cc = 0, isSimulating 0x3d0, pendingScripts 0x3d4, scriptContext 0x3f4, inMouselookMode 0x3f8,
# a shared_ptr 0x3fc, currentCamera 0x404 (Creatable::create<Camera>), three doubles 0x410/0x418/0x420 (0x40c is
# alignment), five CodeProfilers 0x428..0x438 named by the constructor's strings (no ThreadProfiler), and
# imageServerViewHack 0x43c = 0. The unnamed members are recorded as unknown. ---
WS_H, WS_CPP = "App/include/v8datamodel/Workspace.h", "App/v8datamodel/Workspace.cpp"
patch(WS_H, "\t\tUIEvent idleMouseEvent;\n\t\tmutable boost::shared_ptr<Camera> currentCamera;\n\t\tbool isSimulating;\n"
      "\t\tstd::set<Script*> pendingScripts;\n\t\tScriptContext* scriptContext;\n\t\tbool inMouselookMode;\n\tpublic:\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStep;\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceStepped;\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceHeartbeat;\n"
      "\t\tboost::scoped_ptr<Profiling::ThreadProfiler> profileRun;\n",
      "\t\tUIEvent idleMouseEvent;\n\t\tvoid* unknown0x3cc; // 0x3cc = 0; name and type unknown\n\t\tbool isSimulating;\n"
      "\t\tstd::set<Script*> pendingScripts;\n\t\tScriptContext* scriptContext;\n\t\tbool inMouselookMode;\n"
      "\t\tboost::shared_ptr<void> unknown0x3fc; // 0x3fc; pointee type unknown\n"
      "\t\tmutable boost::shared_ptr<Camera> currentCamera;\n"
      "\t\tdouble unknown0x410[3]; // 0x410..0x428, zeroed by the constructor; names unknown\n\tpublic:\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStep; // \"DataModel Step\"\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStepInner; // \"Workspace Step\"\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileWorkspaceAssemble; // \"Workspace Assemble\"\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceStepped;\n"
      "\t\tboost::scoped_ptr<Profiling::CodeProfiler> profileRunServiceHeartbeat;\n")
patch(WS_CPP, "\t\t  profileWorkspaceStep(new Profiling::CodeProfiler(\"DataModel Step\")),\n"
      "\t\t  profileRunServiceStepped(new Profiling::CodeProfiler(\"RunService Stepped\")),\n"
      "\t\t  profileRunServiceHeartbeat(new Profiling::CodeProfiler(\"RunService Heartbeat\")),\n"
      "\t\t  profileRun(new Profiling::ThreadProfiler(\"Run Thread\")),\n",
      "\t\t  unknown0x3cc(NULL),\n"
      "\t\t  profileWorkspaceStep(new Profiling::CodeProfiler(\"DataModel Step\")),\n"
      "\t\t  profileWorkspaceStepInner(new Profiling::CodeProfiler(\"Workspace Step\")),\n"
      "\t\t  profileWorkspaceAssemble(new Profiling::CodeProfiler(\"Workspace Assemble\")),\n"
      "\t\t  profileRunServiceStepped(new Profiling::CodeProfiler(\"RunService Stepped\")),\n"
      "\t\t  profileRunServiceHeartbeat(new Profiling::CodeProfiler(\"RunService Heartbeat\")),\n")
patch(WS_CPP, "\t\tRBXASSERT(dataState);\n\t\tsetName(\"Workspace\");\n",
      "\t\tRBXASSERT(dataState);\n\t\tunknown0x410[0] = unknown0x410[1] = unknown0x410[2] = 0.0;\n\t\tsetName(\"Workspace\");\n")
# ScriptContext (allocation 0x1f8): the 2008 constructor (0x5ae490) matches rbxgs through statsItem (0x1b0), then
# zeroes two doubles (0x1b8, 0x1c0) and two dwords (0x1c8, 0x1cc), constructs a boost::mutex at 0x1d0 (0x594c90)
# and a boost::condition at 0x1d8 (0x5f1bd0, which also builds RunService's two boost::conditions at 0x24c/0x264),
# and puts allocator at 0x1f0. Names are unknown and recorded as such.
patch("App/include/script/ScriptContext.h", "        boost::shared_ptr<Stats::Item> statsItem;\n",
      "        boost::shared_ptr<Stats::Item> statsItem;\n"
      "        double unknown0x1b8[2];   // zeroed by the 2008 constructor; names unknown\n"
      "        void* unknown0x1c8[2];\n"
      "        boost::mutex unknownMutex0x1d0;\n"
      "        boost::condition unknownCondition0x1d8;\n")
patch("App/include/script/ScriptContext.h", '#include "script/Script.h"\n',
      '#include "script/Script.h"\n#include <boost/thread/mutex.hpp>\n#include <boost/thread/condition.hpp>\n')
# --- RunService members, 2008 (constructor 0x556b00, destructor 0x555c00; allocation 0x2d8): runState 0x1b4, a double
# 0x1b8, framePeriod 0x1c0 (a float constant), four doubles 0x1c8..0x1e8, a G3D::Stopwatch 0x1e8 (ctor 0x512060),
# runMutex 0x240, stopRequested 0x248, the two boost::conditions 0x24c/0x264 (0x5f1bd0), runThread 0x27c, viewMutex
# 0x280, views 0x288, invalidRunViewCount 0x2a8, a boost::mutex 0x2ac, a std::deque 0x2b4 (container proxy + four
# zeroed words, as DebrisService's queue), runDisabled 0x2d4. Unnamed members and the deque's element type unknown. ---
RS_H = "App/include/util/RunStateOwner.h"
patch(RS_H, "\t\tRunState runState;\n\t\tboost::mutex runMutex;\n\t\tbool stopRequested;\n"
      "\t\tboost::condition runViewsDoneCondition;\n\t\tboost::condition stateChangedCondition;\n\t\tfloat framePeriod;\n"
      "\t\tboost::scoped_ptr<boost::thread> runThread;\n\t\tboost::mutex viewMutex;\n\t\tstd::map<IRunView*, bool> views;\n"
      "\t\tint invalidRunViewCount;\n",
      "\t\tRunState runState;\n\t\tdouble unknown0x1b8;\n\t\tfloat framePeriod;\n"
      "\t\tdouble unknown0x1c8[4]; // names unknown\n\t\tG3D::Stopwatch unknownStopwatch0x1e8;\n"
      "\t\tboost::mutex runMutex;\n\t\tbool stopRequested;\n"
      "\t\tboost::condition runViewsDoneCondition;\n\t\tboost::condition stateChangedCondition;\n"
      "\t\tboost::scoped_ptr<boost::thread> runThread;\n\t\tboost::mutex viewMutex;\n\t\tstd::map<IRunView*, bool> views;\n"
      "\t\tint invalidRunViewCount;\n\t\tboost::mutex unknownMutex0x2ac;\n"
      "\t\tstd::deque<void*> unknownQueue0x2b4; // element type unknown\n")
patch(RS_H, "#include <boost/scoped_ptr.hpp>\n", "#include <boost/scoped_ptr.hpp>\n#include <G3D/Stopwatch.h>\n#include <deque>\n")
# Player (allocation 0x1d8): the 2008 constructor (0x493da0) matches rbxgs through userId (0x1b4), then zeroes twelve
# 16-bit words 0x1b8..0x1d0 before lastActivityTime (double, 0x1d0). Their names and grouping are unknown.
patch("Network/include/Network/Player.h", "\t\t\tint userId;\n\t\t\tG3D::RealTime lastActivityTime;\n",
      "\t\t\tint userId;\n\t\t\tshort unknown0x1b8[12]; // zeroed by the 2008 constructor; names and grouping unknown\n"
      "\t\t\tG3D::RealTime lastActivityTime;\n")
# Lighting (allocation 0x2e0): the 2008 constructor (0x5e1a40) stores four floats 0x254..0x264 after clearColor,
# timeOfDay at 0x268 (built from a string by 0x5e0c20), twenty-five floats 0x270..0x2d4, and sky at 0x2d4. The
# floats' names are unknown.
patch("App/include/v8datamodel/Lighting.h", "\t\tG3D::Color4 clearColor;\n\t\tboost::posix_time::time_duration timeOfDay;\n",
      "\t\tG3D::Color4 clearColor;\n\t\tfloat unknown0x254[4]; // set by the 2008 constructor; names unknown\n"
      "\t\tboost::posix_time::time_duration timeOfDay;\n\t\tfloat unknown0x270[25]; // names unknown\n")
# DataModel (allocation 0x264): the 2008 destructor (0x57ad70) frees members up to mutex (0x25c) and nothing at
# 0x264, so 2008 has no timeState pointer. Its TimeState lives in a rebuild-side table (glue_timestate_registry.cpp,
# tracked shim) until 2008's time keeping is placed (RunService has timing members and a Stopwatch).
DM_H, DM_CPP = "App/include/v8datamodel/DataModel.h", "App/v8datamodel/DataModel.cpp"
patch(DM_H, "\t\tboost::scoped_ptr<TimeState> timeState;\n", "")
patch(DM_H, "\t\tTimeState* getTimeState();\n", "\t\tTimeState* getTimeState() const; // rebuild shim (glue_timestate_registry.cpp)\n")
patch(DM_CPP, "\t\t  timeState(new TimeState),\n", "")
patch_all(DM_CPP, "timeState->", "getTimeState()->")
# FunctionDescriptor::Security has the opposite values in 2008: the exact descriptor initializers in the exe pass 0
# for any-caller functions (Clone 0x7f2940, GetPlayers 0x7f1920) and 1 for trusted ones (CreateLocalPlayer).
patch("App/include/reflection/function.h", "\t\t\t\tNeedTrustedCaller = 0,\n\t\t\t\tAnyCaller = 1\n",
      "\t\t\t\tAnyCaller = 0,\n\t\t\t\tNeedTrustedCaller = 1\n")

# BlockBlockContact: 0x607c60 reads G3D array data/count at 0x34/0x38 and resizes
# the bool array at 0x40. Destructor 0x60d5a0 frees both aligned buffers. Constructor
# 0x60d500 zeroes dwords 0x4c/0x50, stores 1e9f at 0x54, axis/body at 0x58/0x60,
# and feature[2] at 0x64. 0x6087a0 reads the cached plane flag as a byte at 0x5c.
# Caller 0x60d7fe allocates 0x7c before calling this constructor at 0x60d81c.
CONTACT_H, CONTACT_CPP = "App/include/v8world/Contact.h", "App/v8world/Contact.cpp"
patch(CONTACT_H, "\t\tstd::vector<ContactConnector *,std::allocator<ContactConnector *> > connectors;\n"
      "\t\tstd::vector<bool,std::allocator<bool> > matched;\n\t\tint separatingAxisId;\n",
      "\t\tG3D::Array<ContactConnector*> connectors;\n\t\tG3D::Array<bool> matched;\n"
      "\t\tint unknown0x4c; // 0x60d500: zero; name unknown\n"
      "\t\tint unknown0x50; // 0x60d500: zero; name unknown\n"
      "\t\tfloat unknown0x54; // 0x60d500: 1e9f; 0x608830 caches collision result\n"
      "\t\tint separatingAxisId;\n"
      "\t\tbool unknown0x5c; // 0x6087a0: cached plane-contact flag\n")
patch(CONTACT_CPP, "\t\t:Contact(p0, p1),\n\t\tseparatingAxisId(0),\n\t\tseparatingBodyId(0)\n",
      "\t\t:Contact(p0, p1),\n\t\tunknown0x54(1e9f),\n\t\tseparatingAxisId(0),\n\t\tseparatingBodyId(0)\n")
patch(CONTACT_CPP, "\t\tthis->feature[1] = -1;\n\t}\n\t\n\tBlockBlockContact::~BlockBlockContact()",
      "\t\tthis->feature[1] = -1;\n\t\tunknown0x4c = 0;\n\t\tunknown0x50 = 0;\n\t}\n\t\n\tBlockBlockContact::~BlockBlockContact()")
patch(CONTACT_CPP, "\t\t\t\tfastRemoveIndex<ContactConnector*>(this->connectors, i);\n"
      "\t\t\t\tfastRemoveIndex<bool>(this->matched, i);",
      "\t\t\t\tthis->connectors.fastRemove(i);\n\t\t\t\tthis->matched.fastRemove(i);")
patch(CONTACT_CPP, "\t\tthis->connectors.push_back(connector);\n\t\tthis->matched.push_back(true);",
      "\t\tthis->connectors.append(connector);\n\t\tthis->matched.append(true);")
# 0x607c60 passes false to both resize calls; 0x6087a0 explicitly clears bools.
patch(CONTACT_CPP, "\t\tthis->connectors.resize(0);\n\t\tthis->matched.resize(0);",
      "\t\tthis->connectors.resize(0, false);\n\t\tthis->matched.resize(0, false);")
patch(CONTACT_CPP, "\t\t\t\tmatched.resize(0);\n\t\t\t\tmatched.resize(connectors.size());",
      "\t\t\t\tmatched.resize(connectors.size(), false);\n"
      "\t\t\t\tfor (int i = 0; i < connectors.size(); ++i)\n\t\t\t\t\tmatched[i] = false;")

# GetSet has two flag slots before get/set (0x4accd0 getter +8, 0x4acd50 setter +12).
# RTTI vtables distinguish them: GetImpl 0x8226b8 = true/false, SetImpl 0x842870 =
# false/true, GetSetImpl 0x815c18 = false/false. The second flag is isWriteOnly.
patch("App/include/reflection/property.h",
      "\t\t\tclass GetSet\n\t\t\t{\n\t\t\tpublic:\n\t\t\t\tvirtual bool isReadOnly() const = 0;\n",
      "\t\t\tclass GetSet\n\t\t\t{\n\t\t\tpublic:\n\t\t\t\tvirtual bool isReadOnly() const = 0;\n"
      "\t\t\t\tvirtual bool isWriteOnly() const { return false; }\n")
_set_only_getter = ("\t\t\t\tvirtual ReturnType getValue(const DescribedBase* object) const\n"
                    "\t\t\t\t{\n\t\t\t\t\tthrow std::runtime_error(\"can't get value\");\n")
patch("App/include/reflection/reflection.h", _set_only_getter,
      "\t\t\t\tvirtual bool isWriteOnly() const { return true; }\n" + _set_only_getter)

# Workspace camera delegation in 2008 omits the later rbxgs assertion calls:
# 0x5a0210 is only virtual getCamera() + Camera::gCamera at 0x130 (13 bytes);
# 0x5a0260 clears isSimulating at 0x3d0, gets the camera via ICameraOwner at
# 0x288, then tail-calls Camera::autoMode (31 bytes), with no guard branches.
patch(WS_CPP, "\t\tRBXASSERT(getCamera());\n", "")
patch(WS_CPP, "\t\tRBXASSERT(isSimulating);\n\t\tisSimulating = false;\n",
      "\t\tisSimulating = false;\n")
patch(WS_CPP, "\t\tRBXASSERT(!getCurrentMouseCommand()->captured());\n", "")

# RootInstance: exact mined snippets 0x590190 (computeIdeInsertPoint, 167 bytes)
# and 0x590b50 (moveToIdeInsertPoint) use /fp:fast. Their member offsets and
# virtual bounds slot already agree; parse the TU's inline vector operations
# with precise floating-point optimization disabled, as in those exact profiles.
patch("App/v8datamodel/RootInstance.cpp", '#include "v8datamodel/RootInstance.h"\n',
      '#pragma float_control(precise, off)\n#include "v8datamodel/RootInstance.h"\n')

# BallBallContact RTTI vtable 0x8436bc slot 5 names cleanup 0x60cb50 (16 bytes):
# test connector at 0x34 and skip Contact::deleteConnector when it is null.
patch(CONTACT_CPP, "\tvoid BallBallContact::deleteAllConnectors()\n\t{\n"
      "\t\tthis->deleteConnector(this->ballBallConnector);\n\t}\n",
      "\tvoid BallBallContact::deleteAllConnectors()\n\t{\n"
      "\t\tif (this->ballBallConnector)\n\t\t\tthis->deleteConnector(this->ballBallConnector);\n\t}\n")

# LuaArguments::get at 0x61bcb0 forwards offset 0xc, L 0x10 and true to
# 0x5ad380. The latter returns bool, stores Lua numbers as double and treats
# nil as missing only when requested. Its table recursion passes false;
# readResults at 0x5ad6d0 passes true (push 1 at 0x5ad74a).
LUA_ARGS = "App/include/script/LuaArguments.h"
patch(LUA_ARGS, "                // TODO: check match\n                int pos = index + offset;\n"
      "                RBXASSERT(pos > 0);\n                get(L, pos, value);\n",
      "                get(L, index + offset, value, true);\n")
lua_args_text = (TREE / LUA_ARGS).read_text(errors="replace")
lua_get_old = lua_args_text[lua_args_text.index("            // TODO: 97.00%\n"):
                            lua_args_text.index("            static int push(")]
lua_get_new = lua_get_old.replace("            // TODO: 97.00%\n", "")
lua_get_new = lua_get_new.replace("static void get(lua_State* L, int luaIndex, Reflection::Value& value)",
                                "static bool get(lua_State* L, int luaIndex, Reflection::Value& value, bool nilIsMissing)")
lua_get_new = lua_get_new.replace("float rhs = lua_tonumber", "double rhs = lua_tonumber")
lua_get_new = lua_get_new.replace("return;", "return true;")
lua_get_new = lua_get_new.replace("LuaArguments::get(L, -1, ival);", "LuaArguments::get(L, -1, ival, false);")
lua_get_new = lua_get_new.replace("                    case LUA_TNIL:\n",
                                "                    case LUA_TNIL:\n                        if (nilIsMissing)\n                            return false;\n")
lua_get_new = lua_get_new.replace("                if (luaIndex <= lua_gettop(L))\n",
                                "                if (luaIndex > lua_gettop(L))\n                    return false;\n\n")
lua_get_new = lua_get_new.replace("                    }\n                }\n            }\n",
                                "                    }\n                }\n                return true;\n            }\n")
patch(LUA_ARGS, lua_get_old, lua_get_new)
patch("App/script/ScriptContext.cpp",
      "Lua::LuaArguments::get(thread, static_cast<int>(i+1), result.get()->at(i));",
      "Lua::LuaArguments::get(thread, static_cast<int>(i+1), result.get()->at(i), true);")

# --- 2008-06 kernel: Body.cpp/SimBody.cpp TU (claim "RBX::RevoluteLink"). Per-address evidence:
# makeCofmDirty 00613f70 (first level inlined, recursion via call, assertions out, SimBody
# dirty byte at +8), setPv 00613fb0 (parent guard, 0x48 PV copy, inlined getNextStateIndex),
# setVelocity 00614040 (same; dirty byte +8), setMass 006140b0 (fcom against the member:
# /fp:fast profile; makeCofmDirty inlined), setMoment 00614110 (Matrix3::operator!= call on
# the member, makeCofmDirty inlined, rep movsd copy), step 00614200 (ret 4: ONE bool
# parameter at [esp+0x50]; simBody->step() called with NO argument; SimBody::pv at +0xc;
# inlined getNextStateIndex), setMeInParent(Link*) 00614380 (body missing from the tree;
# link!=value -> link->setBody(NULL) inlined as [link+4]=0, value->setBody(this) as
# [value+4]=this, makeCofmDirty inlined, root->advanceStateIndex inlined), resetRoot
# 00614530 (no leading assertion; children indexed without the IndexArray operator[]
# assertion), onChildRemoved 00614760 (fastRemove inlined including Array::resize(n-1,
# false) at 0x5fa770 and child->index = -1; delete cofm; makeCofmDirty inlined), setParent
# 006148b0 (no assertions; onChildRemoved/onChildAdded/~SimBody+delete/new SimBody calls;
# calcRoot call 0x613ef0; inlined root store then a per-child resetRoot call loop),
# ctor 006149c0 (layout shift above; new(0xb4) -> SimBody size 0xb4; EH states: children
# state 0, new state 1, NO base-destruction state => the KernelIndex destructor is trivial;
# no delete-on-throw funclet => SimBody's constructor is nothrow from Body.cpp), ~Body
# 00614ac0 (no assertions; setParent(NULL), ~SimBody+delete, children data freed with
# alignedFree inline; state 0 = children), initialize 00614b40 (?initialize@@YAXXZ, a
# CRT-registered free function assigning a global Body* at 0x97bec4 from a plain
# `new Body()` with a null check; the tree's lazy static local with guard + atexit is
# wrong). 2008 SimBody ctor 00658ae0: body +0, float dt +4 (fldz), dirty +8, pv +0xc,
# quaternion +0x54 (0,0,0,1), angMomentum +0x64, momentRecip +0x70, massRecip +0x7c (NOT
# initialized), constantForceY +0x80, force +0x84, torque +0x90, two more zero vectors at
# +0x9c and +0xa8, size 0xb4. Kernel::insertBody 005fb160 inlines fastAppend without its
# assertions; Kernel::deletePoint 005fb3c0 (owned) has no assertion checks, so the
# IndexArray helper assertions do not exist in 2008. ---
KI_H = "App/include/v8kernel/KernelIndex.h"
patch(KI_H,
      "\t\t\tKernelIndex::KernelIndex():kernelIndex(-1) {}\n"
      "\t\t\tKernelIndex::~KernelIndex() {RBXASSERT(kernelIndex == -1);}\n",
      "\t\t\tKernelIndex::KernelIndex():kernelIndex(-1) {}\n")
# IndexArray: no assertions in fastAppend, fastRemove or operator[] in 2008.
IA_H = "App/include/util/IndexArray.h"
patch_all(IA_H, "\t\t\tRBXASSERT(indexOf(array[index]) == index);\n", "")
patch(IA_H,
      "\t\tvoid fastAppend(tInstance* item)\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(item);\n"
      "\t\t\tRBXASSERT(indexOf(item) == -1);\n"
      "\t\t\tindexOf(item) = array.size();\n",
      "\t\tvoid fastAppend(tInstance* item)\n"
      "\t\t{\n"
      "\t\t\tindexOf(item) = array.size();\n")
patch(IA_H,
      "\t\tvoid fastRemove(tInstance* item)\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(array.find(item) != array.end());\n\n"
      "\t\t\tint removeIndex = indexOf(item);\n"
      "\t\t\tRBXASSERT(removeIndex >= 0);\n"
      "\t\t\tRBXASSERT(array[removeIndex] == item);\n",
      "\t\tvoid fastRemove(tInstance* item)\n"
      "\t\t{\n"
      "\t\t\tint removeIndex = indexOf(item);\n")
# SimBody: 2008 layout (0xb4) and the no-argument step.
SB_H, SB_CPP = "App/include/v8kernel/SimBody.h", "App/v8kernel/SimBody.cpp"
patch(SB_H,
      "\t\t\tBody *body;\n\t\t\tbool dirty;\n",
      "\t  Body *body;\n"
      "\t  float dt;   // 0x4: ctor 00658ae0 stores 0.0f; SimBody::step() (no parameter) reads it\n"
      "\t  bool dirty;\n")
patch(SB_H,
      "\t\tSimBody(RBX::Body* body);\n",
      "\t\tSimBody(RBX::Body* body) throw();   // 006149c0 has no delete-on-throw funclet\n")
patch(SB_H,
      "\t\tvoid step(float dt);\n",
      "\t\tvoid step();\n")
patch(SB_H,
      "\t\t\tG3D::Vector3 force;\n\t\t\tG3D::Vector3 torque;\n",
      "\t\tG3D::Vector3 force;\n"
      "\t\tG3D::Vector3 torque;\n"
      "\t\tG3D::Vector3 unknown0x9c;  // 00658ae0 zero-initializes; name and use unknown\n"
      "\t\tG3D::Vector3 unknown0xa8;  // 00658ae0 zero-initializes; name and use unknown\n")
patch(SB_CPP,
      "SimBody::SimBody(RBX::Body* _body)\n"
      "\t\t\t:body(_body),\n"
      "\t\t\tdirty(1),\n"
      "\t\t\tforce(G3D::Vector3::zero()),\n"
      "\t\t\ttorque(G3D::Vector3::zero()),\n"
      "\t\t\tconstantForceY(0.0f)\n"
      "{}\n",
      "SimBody::SimBody(RBX::Body* _body) throw()\n"
      "\t\t\t:body(_body),\n"
      "\t\t\tdt(0.0f),\n"
      "\t\t\tdirty(1),\n"
      "\t\t\tforce(G3D::Vector3::zero()),\n"
      "\t\t\ttorque(G3D::Vector3::zero()),\n"
      "\t\t\tconstantForceY(0.0f),\n"
      "\t\t\tunknown0x9c(G3D::Vector3::zero()),\n"
      "\t\t\tunknown0xa8(G3D::Vector3::zero())\n"
      "{}\n")
patch(SB_CPP,
      "void SimBody::step(float dt)\n",
      "void SimBody::step()\n")
# Body: one bool parameter to step (00614200 ret 4). Keep the older Kernel caller's
# genuine two-argument API: its timestep now belongs in SimBody's cached field.
patch("App/include/v8kernel/Body.h",
      "\t\tvoid step(float, bool);\n",
      "\t\tvoid step(float dt, bool throttling) { simBody->dt = dt; step(throttling); }\n"
      "\t\tvoid step(bool);\n")
BODY_CPP = "App/v8kernel/Body.cpp"
# 006140b0 compares with fcom: the 2008 TU used the fp:fast profile.
patch(BODY_CPP,
      '#include "v8kernel/Body.h"\n#include "v8kernel/SimBody.h"\n#include "util/Debug.h"\n',
      '#pragma float_control(precise, off)\n'
      '#include "v8kernel/Body.h"\n#include "v8kernel/SimBody.h"\n#include "util/Debug.h"\n')
patch(BODY_CPP,
      "Body::~Body()\n"
      "{\n"
      "\tRBXASSERT(numChildren() == 0);\n"
      "\tif (parent)\n"
      "\t\tsetParent(NULL);\n"
      "\tRBXASSERT(!parent);\n"
      "\tRBXASSERT(!link);\n"
      "\tRBXASSERT(index == -1);\n"
      "\tRBXASSERT(simBody);\n"
      "\tdelete simBody;\n"
      "\tsimBody = NULL;\n"
      "\tRBXASSERT(!cofm);\n"
      "\tRBXASSERT(root == this);\n"
      "}\n",
      "Body::~Body()\n"
      "{\n"
      "\tif (parent)\n"
      "\t\tsetParent(NULL);\n"
      "\tdelete simBody;\n"
      "\tsimBody = NULL;\n"
      "}\n")
patch(BODY_CPP,
      "void Body::makeCofmDirty()\n"
      "{\n"
      "\tif (cofm && cofm->getIsDirty())\n"
      "\t{\n"
      "\t\t// TODO: this match is super fake, i dont know roblox managed to create this cursed assertion\n"
      "\t\t#if defined(_DEBUG) || defined(_RELEASEASSERT)\n"
      "\t\tif (Debugable::assertAction == Debugable::CrashOnAssert)\n"
      "\t\t{\n"
      "\t\t\tif (parent)\n"
      "\t\t\t\tparent->validateParentCofmDirty();\n"
      "\t\t\tRBXASSERT(getRootSimBody()->getDirty());\n"
      "\t\t}\n"
      "\t\t#endif\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tif (getParent())\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(!simBody);\n"
      "\t\t\tgetParent()->makeCofmDirty();\n"
      "\t\t}\n"
      "\t\telse\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(root == this);\n"
      "\t\t\tif (simBody)\n"
      "\t\t\t\tsimBody->makeDirty();\n"
      "\t\t}\n"
      "\t\tif (cofm)\n"
      "\t\t{\n"
      "\t\t\tcofm->makeDirty();\n"
      "\t\t\tRBXASSERT(numChildren() > 0);\n"
      "\t\t}\n"
      "\t\telse\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(!numChildren());\n"
      "\t\t}\n"
      "\t}\n"
      "}\n",
      "void Body::makeCofmDirty()\n"
      "{\n"
      "\tif (cofm && cofm->getIsDirty())\n"
      "\t{\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tif (getParent())\n"
      "\t\t\tgetParent()->makeCofmDirty();\n"
      "\t\telse if (simBody)\n"
      "\t\t\tsimBody->makeDirty();\n"
      "\t\tif (cofm)\n"
      "\t\t\tcofm->makeDirty();\n"
      "\t}\n"
      "}\n")
patch(BODY_CPP,
      "void Body::step(float dt, bool throttling)\n"
      "{\n"
      "\tRBXASSERT(!getParent());\n"
      "\tRBXASSERT(simBody);\n\n"
      "\tif (throttling && canThrottle)\n"
      "\t{\n"
      "\t\tsimBody->resetAccumulators();\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tsimBody->step(dt);\n\n"
      "\t\tpv = cofm == NULL ? simBody->pv : simBody->getOwnerPV();\n"
      "\t\tadvanceStateIndex();\n"
      "\t}\n"
      "}\n",
      "void Body::step(bool throttling)\n"
      "{\n"
      "\tif (throttling && canThrottle)\n"
      "\t{\n"
      "\t\tsimBody->resetAccumulators();\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tsimBody->step();\n"
      "\t\tpv = cofm == NULL ? simBody->pv : simBody->getOwnerPV();\n"
      "\t\tadvanceStateIndex();\n"
      "\t}\n"
      "}\n")
patch(BODY_CPP,
      "void Body::setParent(Body* newParent)\n"
      "{\n"
      "\tRBXASSERT(!newParent || newParent->getParent() != this);\n"
      "\tRBXASSERT(newParent != this);\n\n"
      "\tif (parent != newParent)\n"
      "\t{\n",
      "void Body::setParent(Body* newParent)\n"
      "{\n"
      "\tif (parent != newParent)\n"
      "\t{\n")
patch(BODY_CPP,
      "\t\tif (getParent())\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(root == getParent()->getRoot());\n"
      "\t\t\tRBXASSERT(!simBody);\n"
      "\t\t\tparent->onChildRemoved(this);\n"
      "\t\t}\n"
      "\t\telse\n"
      "\t\t{\n"
      "\t\t\tRBXASSERT(root = this);\n"
      "\t\t\tRBXASSERT(simBody);\n"
      "\t\t\tdelete simBody;\n"
      "\t\t\tsimBody = NULL;\n"
      "\t\t}\n",
      "\t\tif (getParent())\n"
      "\t\t{\n"
      "\t\t\tparent->onChildRemoved(this);\n"
      "\t\t}\n"
      "\t\telse\n"
      "\t\t{\n"
      "\t\t\tdelete simBody;\n"
      "\t\t\tsimBody = NULL;\n"
      "\t\t}\n")
patch(BODY_CPP,
      "\t\tBody* myRoot = getParent() ? getParent()->calcRoot() : this;\n"
      "\t\tmyRoot->advanceStateIndex();\n"
      "\t\tresetRoot(myRoot);\n"
      "\t}\n"
      "}\n",
      "\t\tBody* myRoot = getParent() ? getParent()->calcRoot() : this;\n"
      "\t\tmyRoot->advanceStateIndex();\n"
      "\t\troot = myRoot;\n"
      "\t\tfor (int i = 0; i < children.size(); i++)\n"
      "\t\t\tchildren[i]->resetRoot(myRoot);\n"
      "\t}\n"
      "}\n")
patch(BODY_CPP,
      "void Body::setPv(const PV& _pv)\n"
      "{\n"
      "\tif (parent)\n"
      "\t{\n"
      "\t\tRBXASSERT(0);\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tpv = _pv;\n"
      "\t\tif (simBody)\n"
      "\t\t\tsimBody->makeDirty();\n"
      "\t\tadvanceStateIndex();\n"
      "\t}\n"
      "\tRBXASSERT(Math::longestVector3Component(pv.position.translation) < 1000000.0);\n"
      "\tRBXASSERT(Math::isOrthonormal(pv.position.rotation));\n"
      "\tRBXASSERT(!Math::isNanInfDenormVector3(pv.position.translation));\n"
      "\tRBXASSERT(!Math::isNanInfDenormVector3(pv.velocity.linear));\n"
      "\tRBXASSERT(!Math::isNanInfDenormVector3(pv.velocity.rotational));\n"
      "}\n",
      "void Body::setPv(const PV& _pv)\n"
      "{\n"
      "\tif (!parent)\n"
      "\t{\n"
      "\t\tpv = _pv;\n"
      "\t\tif (simBody)\n"
      "\t\t\tsimBody->makeDirty();\n"
      "\t\tadvanceStateIndex();\n"
      "\t}\n"
      "}\n")
patch(BODY_CPP,
      "void Body::resetRoot(RBX::Body* newRoot)\n"
      "{\n"
      "\tRBXASSERT(newRoot == calcRoot());\n"
      "\troot = newRoot;\n",
      "void Body::resetRoot(RBX::Body* newRoot)\n"
      "{\n"
      "\troot = newRoot;\n")
patch(BODY_CPP,
      "void Body::onChildRemoved(RBX::Body* child)\n"
      "{\n"
      "\tRBXASSERT(cofm);\n"
      "\tchildren.fastRemove(child);\n",
      "void Body::onChildRemoved(RBX::Body* child)\n"
      "{\n"
      "\tchildren.fastRemove(child);\n")
# setMeInParent(RBX::Link*) is declared in Body.h but never defined in the tree; 00614380.
patch(BODY_CPP,
      "\tif (getParent())\n"
      "\t{\n"
      "\t\tmeInParent = _meInParent;\n"
      "\t\tmakeCofmDirty();\n"
      "\t\troot->advanceStateIndex();\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tRBXASSERT(0);\n"
      "\t}\n"
      "}\n",
      "\tif (getParent())\n"
      "\t{\n"
      "\t\tmeInParent = _meInParent;\n"
      "\t\tmakeCofmDirty();\n"
      "\t\troot->advanceStateIndex();\n"
      "\t}\n"
      "\telse\n"
      "\t{\n"
      "\t\tRBXASSERT(0);\n"
      "\t}\n"
      "}\n\n"
      "void Body::setMeInParent(RBX::Link* value)\n"
      "{\n"
      "\tif (link && link != value)\n"
      "\t\tlink->setBody(NULL);\n"
      "\tif (getParent())\n"
      "\t{\n"
      "\t\tlink = value;\n"
      "\t\tvalue->setBody(this);\n"
      "\t\tmakeCofmDirty();\n"
      "\t\troot->advanceStateIndex();\n"
      "\t}\n"
      "}\n")
# 00614b40 is ?initialize@@YAXXZ: a plain `new Body()` into a global Body* (0x97bec4).
patch(BODY_CPP,
      "Body* Body::getWorldBody()\n"
      "{\n"
      "\tstatic Body b = Body();\n"
      "\treturn &b;\n"
      "}\n",
      "static Body* gWorldBody = NULL;   // 2008: the global Body* at 0x97bec4\n\n"
      "static void initialize()           // 00614b40 ?initialize@@YAXXZ\n"
      "{\n"
      "\tgWorldBody = new Body();\n"
      "}\n\n"
      "Body* Body::getWorldBody()\n"
      "{\n"
      "\tif (!gWorldBody)\n"
      "\t\tinitialize();\n"
      "\treturn gWorldBody;\n"
      "}\n")
# Independently accepted promotions are declarative edits, never uploaded Python.
# The server verifier validates anchors and all ABI/runtime gates before publishing.
native_promotions = out.with_name("native-promotions.json")
if native_promotions.exists():
    import sys
    sys.path.insert(0, str(ROOT))
    from roc.integration import merge_patches
    batches = json.loads(native_promotions.read_text(encoding="utf-8"))
    for batch in batches if isinstance(batches, list) else [batches]:
        patches = merge_patches(patches, batch)

out.write_text(json.dumps(patches, indent=1) + "\n", encoding="utf-8")
print("%d files, %d patches -> %s" % (len(patches), sum(map(len, patches.values())), out))
