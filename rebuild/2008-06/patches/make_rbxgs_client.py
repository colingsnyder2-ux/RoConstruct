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

# --- reflection/property.h: typed access through the descriptor ---
append("App/include/reflection/property.h", """
// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	namespace Reflection
	{
		template<typename T>
		T ConstProperty::getValue() const
		{
			return static_cast<const TypedPropertyDescriptor<T>*>(descriptor)->getValue(instance);
		}

		template<typename T>
		void Property::setValue(const T& value)
		{
			static_cast<const TypedPropertyDescriptor<T>*>(descriptor)->setValue(getInstance(), value);
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

out.write_text(json.dumps(patches, indent=1) + "\n", encoding="utf-8")
print("%d files, %d patches -> %s" % (len(patches), sum(map(len, patches.values())), out))
