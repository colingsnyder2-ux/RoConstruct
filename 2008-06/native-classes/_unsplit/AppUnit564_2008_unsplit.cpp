// UNSPLIT CANDIDATE (2026-11-08): AppUnit564_2008 family
// Originals preserved; review before promotion.

// ---- BEGIN AppUnit564_2008GenericConvert.cpp ----
// 2008-06 native Value::genericConvert<T> instances of the reflection unit in 00564000..00570000 (inactive).
// Same body as the committed SoundValueGenericFloat.cpp (genericConvert<float> 0056d650, counted there): any_cast
// to T, else a string parsed through StringConverter<T>, else runtime_error("Unable to cast %s to %s").
#include "reflection/type.h"
#include "util/Utilities.h"
#include "util/ContentProvider.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Vector2int16.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"
#include <stdexcept>

namespace RBX
{
	namespace Reflection
	{
		template<class T>
		T& Value::genericConvert()
		{
			T* id = boost::any_cast<T>(&value);
			if (id)
				return *id;
			if (isType<std::string>())
			{
				T v;
				if (StringConverter<T>::convertToValue(*boost::any_cast<std::string>(&value), v))
				{
					value = v;
					_type = &Type::singleton<T>();
					return *boost::any_cast<T>(&value);
				}
			}
			throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), Type::singleton<T>().tag.c_str()));
		}

		template int& Value::genericConvert<int>();
		template bool& Value::genericConvert<bool>();
		template double& Value::genericConvert<double>();
		template G3D::Vector3& Value::genericConvert<G3D::Vector3>();
		template G3D::Color3& Value::genericConvert<G3D::Color3>();
		template BrickColor& Value::genericConvert<BrickColor>();
		template ContentId& Value::genericConvert<ContentId>();
		template G3D::CoordinateFrame& Value::genericConvert<G3D::CoordinateFrame>();
		template G3D::Vector2int16& Value::genericConvert<G3D::Vector2int16>();

		// 0056d090 (inline any_cast, so /Ob2; the /Ob1 build calls an out-of-line any_cast and is 103 B): any_cast to the Objects type (00938950) or runtime_error("Unable to cast value to Objects")
		template<>
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >& Value::convert<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >* result =
				boost::any_cast<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >(&value);
			if (!result)
			{
				std::string message("Unable to cast value to Objects");
				throw std::runtime_error(message);
			}
			return *result;
		}
	}
}
// ---- END AppUnit564_2008GenericConvert.cpp ----

// ---- BEGIN AppUnit564_2008Selection.cpp ----
// 2008-06 native RBX::Selection rows of the application range 00564000..00570000 (inactive), against the native
// v8datamodel/Selection.h (read-only; its layout is proven by tests/NativeSelectionLayout.cpp: size 0x174,
// selection +0x154, filteredSelections +0x15c).
#include "v8datamodel/Selection.h"

namespace RBX
{
	// 005670f0: find over filteredSelections (+0x15c) then vector<ISelectionBase*>::erase 00459830
	void Selection::removeFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.erase(std::find(filteredSelections.begin(), filteredSelections.end(), fs));
	}
}

#ifdef NATIVE_APPUNIT564_PENDING
// Pending-build-only (generated v8datamodel/Selection.h copy, proposal): the 2008 class name is a const char array
// (RTTI .?AV?$FactoryProduct@VSelection@RBX@@VInstance@2@$1?sSelection@2@3QBDB@RBX@@, string 0082ec58), and the
// class declares its constructor 00568180, destructor 00566f00, onEvent 005682e0, raiseAdded/raiseRemoved
// 00566ba0 / 00566d50, toggleSelection 00567210, addFilteredSelection 00567180, getSelection2 00566a80 and
// setSelection(shared_ptr<const Instances>) 00568330. Bodies after the donor Selection.cpp. onEvent 005682e0 is
// declared but not built: it calls the non-const Instance::getRootAncestor() 0042a5f0, which the native
// v8tree/Instance.h does not declare (proposal).
namespace RBX
{
	const char sSelection[] = "Selection";

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

// Dynamic initializers 007f3330 / 007f3360.
static RBX::Reflection::BoundFuncDesc<RBX::Selection, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(void), 0> func_getSelection(&RBX::Selection::getSelection2, "Get", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1> func_setSelection(&RBX::Selection::setSelection, "Set", "selection", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

namespace RBX
{
	Selection::Selection()
		: selection(std::vector<boost::shared_ptr<Instance> >())
	{
		setName("Selection");
	}

	Selection::~Selection()
	{
	}

	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Selection::getSelection2()
	{
		return selection.read();
	}

	void Selection::addFilteredSelection(ISelectionBase* fs)
	{
		filteredSelections.push_back(fs);
	}

	void Selection::raiseAdded(boost::shared_ptr<Instance> instance)
	{
		SelectionChanged event(instance, boost::shared_ptr<Instance>());
		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
			(*iter)->onSelectionChanged(event);
		Notifier<Selection, SelectionChanged>::raise(event);
	}

	void Selection::raiseRemoved(boost::shared_ptr<Instance> source)
	{
		SelectionChanged event(boost::shared_ptr<Instance>(), source);
		for (std::vector<ISelectionBase*>::iterator iter = filteredSelections.begin(); iter != filteredSelections.end(); iter++)
			(*iter)->onSelectionChanged(event);
		Notifier<Selection, SelectionChanged>::raise(event);
	}

	void Selection::toggleSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
		std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared);
		if (found == sel->end())
		{
			sel->push_back(shared);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(shared);
		}
		else
		{
			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(shared);
		}
	}

	void Selection::addToSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> shared = shared_from(instance);
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
		std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared);
		if (found == sel->end())
		{
			sel->push_back(shared);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(shared);
		}
	}

	void Selection::removeFromSelection(const Instance* instance)
	{
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
		std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared_from(instance));
		if (found != sel->end())
		{
			boost::shared_ptr<Instance> nonConst = *found;
			sel->erase(found);
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(nonConst);
		}
	}

	// 005675d0: the loop test is size() > 0 (sar 3; test; jbe), not the donor's empty() (test 0xfffffff8)
	void Selection::clearSelection()
	{
		while (selection->size() > 0)
		{
			boost::shared_ptr<Instance> instance = selection->back();
			selection.write()->pop_back();
			instance->Notifier<Instance, AncestorChanged>::removeListener(this);
			raiseRemoved(instance);
		}
	}

	// 00567770
	void Selection::setSelection(Instance* instance)
	{
		boost::shared_ptr<Instance> inst = shared_from(instance);
		while (selection->size() > 0)
		{
			boost::shared_ptr<Instance> item = selection->back();
			if (item == inst)
			{
				if (selection->size() == 1)
					return;
				boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();
				sel->back() = sel->front();
				sel->front() = item;
			}
			else
			{
				selection.write()->pop_back();
				item->Notifier<Instance, AncestorChanged>::removeListener(this);
				raiseRemoved(item);
			}
		}
		if (inst)
		{
			selection.write()->push_back(inst);
			instance->Notifier<Instance, AncestorChanged>::addListener(this);
			raiseAdded(inst);
		}
	}

	void Selection::setSelection(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > value)
	{
		setSelection(value->begin(), value->end());
	}
}
#endif
// ---- END AppUnit564_2008Selection.cpp ----

// ---- BEGIN AppUnit564_2008Type.cpp ----
// 2008-06 native reflection type singletons of the application range 00564000..00570000 (inactive).
// Type::singleton<T> 0056ca70..0056cfb0: a function-local static Type(name, typeid(T)) built through the out-of-line
// Type(const char*, const type_info&) 0056bd90 (emitted here as the header-inline COMDAT), destroyed at exit by the
// atexit stubs 007fd210..007fd2d0. The name strings and type descriptors are read from the pushes of each body.
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "util/ContentProvider.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	namespace Reflection
	{
		// 0056ca70: "Object" 00821634, type descriptor 00937010 (boost::shared_ptr<DescribedBase>)
		template<>
		const Type& Type::singleton<boost::shared_ptr<DescribedBase> >()
		{
			static Type type("Object", typeid(boost::shared_ptr<DescribedBase>));
			return type;
		}

		// 0056cae0: "Instance" 0082d92c, 00935980 (boost::shared_ptr<Instance>)
		template<>
		const Type& Type::singleton<boost::shared_ptr<Instance> >()
		{
			static Type type("Instance", typeid(boost::shared_ptr<Instance>));
			return type;
		}

		// 0056cb50: "Objects" 0082f6a0, 00938950 (boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >)
		template<>
		const Type& Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			static Type type("Objects", typeid(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >));
			return type;
		}

		// 0056cbc0: "int" 00820df4, 0092bed0
		template<>
		const Type& Type::singleton<int>()
		{
			static Type type("int", typeid(int));
			return type;
		}

		// 0056cc30: "bool" 00820dec, 00929644
		template<>
		const Type& Type::singleton<bool>()
		{
			static Type type("bool", typeid(bool));
			return type;
		}

		// 0056cca0: "float" 00820e10, 0092bedc
		template<>
		const Type& Type::singleton<float>()
		{
			static Type type("float", typeid(float));
			return type;
		}

		// 0056cd10: "double" 0082f6a8, 0092bee8
		template<>
		const Type& Type::singleton<double>()
		{
			static Type type("double", typeid(double));
			return type;
		}

		// 0056cd80: "Content" 0082f6b0, 0092bf44 (RBX::ContentId)
		template<>
		const Type& Type::singleton<ContentId>()
		{
			static Type type("Content", typeid(ContentId));
			return type;
		}

		// 0056cdf0: "string" 0082f6b8, 0092bef8
		template<>
		const Type& Type::singleton<std::string>()
		{
			static Type type("string", typeid(std::string));
			return type;
		}

		// 0056ce60: "Vector3" 0082f6c0, 00946364
		template<>
		const Type& Type::singleton<G3D::Vector3>()
		{
			static Type type("Vector3", typeid(G3D::Vector3));
			return type;
		}

		// 0056ced0: "Vector2int16" 0082f6c8, 00931034
		template<>
		const Type& Type::singleton<G3D::Vector2int16>()
		{
			static Type type("Vector2int16", typeid(G3D::Vector2int16));
			return type;
		}

		// 0056cf40: "Color3" 0082f6d8, 009463a4
		template<>
		const Type& Type::singleton<G3D::Color3>()
		{
			static Type type("Color3", typeid(G3D::Color3));
			return type;
		}

		// 0056cfb0: "Table" 0082f6e0, 0092bf60 (std::vector<Value>, the header's ValueCollection)
		template<>
		const Type& Type::singleton<ValueCollection>()
		{
			static Type type("Table", typeid(ValueCollection));
			return type;
		}
		// 0056d120: "BrickColor" 0082f710, 00935398, tag "int" 00820df4: the tagged Type(name, type, tag) 004897a0
		template<>
		const Type& Type::singleton<BrickColor>()
		{
			static Type type("BrickColor", typeid(BrickColor), "int");
			return type;
		}
	}
}
// ---- END AppUnit564_2008Type.cpp ----

// ---- BEGIN AppUnit564_2008ValueConvert.cpp ----
// 2008-06 native Value::convert<T> numeric specializations of the reflection unit in 00564000..00570000 (inactive).
// Built /Ob1 like the committed SoundValueConvertFloat.cpp (convert<float> 0056ed00, counted there): each one checks
// the held type against the other numeric types in the order the target compares type descriptors, stores the
// converted value, sets the Type singleton and falls through to genericConvert<T> (tail call).
#include "reflection/type.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include "util/ContentProvider.h"

namespace RBX
{
	namespace Reflection
	{
		// 0056ea60: float (0092bedc, G3D::iRound -> fld/fistp), double (0092bee8), bool (00929644); singleton<int> 0056cbc0
		template<>
		int& Value::convert<int>()
		{
			if (isType<float>())
			{
				value = G3D::iRound(boost::any_cast<float>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<double>())
			{
				value = G3D::iRound(boost::any_cast<double>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<bool>())
			{
				value = (int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<int>();
			}
			return genericConvert<int>();
		}

		// 0056ebb0: int (0092bed0), float (fcomp against 0.0f), double; singleton<bool> 0056cc30
		template<>
		bool& Value::convert<bool>()
		{
			if (isType<int>())
			{
				value = boost::any_cast<int>(value) != 0;
				_type = &Type::singleton<bool>();
			}
			if (isType<float>())
			{
				value = boost::any_cast<float>(value) != 0.0f;
				_type = &Type::singleton<bool>();
			}
			if (isType<double>())
			{
				value = boost::any_cast<double>(value) != 0.0;
				_type = &Type::singleton<bool>();
			}
			return genericConvert<bool>();
		}

		// 0056ee50: int, bool, float; singleton<double> 0056cd10
		template<>
		double& Value::convert<double>()
		{
			if (isType<int>())
			{
				value = (double)boost::any_cast<int>(value);
				_type = &Type::singleton<double>();
			}
			if (isType<bool>())
			{
				value = (double)(int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<double>();
			}
			if (isType<float>())
			{
				value = (double)boost::any_cast<float>(value);
				_type = &Type::singleton<double>();
			}
			return genericConvert<double>();
		}
		// 0056efa0..0056efe0: one-instruction forwarders (jmp genericConvert<T> 0056d890 / 0056d9b0 / 0056dae0 /
		// 0056dc00 / 0056dd20)
		template<>
		G3D::Vector3& Value::convert<G3D::Vector3>()
		{
			return genericConvert<G3D::Vector3>();
		}

		template<>
		G3D::CoordinateFrame& Value::convert<G3D::CoordinateFrame>()
		{
			return genericConvert<G3D::CoordinateFrame>();
		}

		template<>
		G3D::Vector2int16& Value::convert<G3D::Vector2int16>()
		{
			return genericConvert<G3D::Vector2int16>();
		}

		template<>
		G3D::Color3& Value::convert<G3D::Color3>()
		{
			return genericConvert<G3D::Color3>();
		}

		template<>
		BrickColor& Value::convert<BrickColor>()
		{
			return genericConvert<BrickColor>();
		}

		// 0056eff0: a held std::string (0092bef8) becomes ContentId(string) (00615440); singleton<ContentId> 0056cd80;
		// then genericConvert<ContentId> 0056de80
		template<>
		ContentId& Value::convert<ContentId>()
		{
			if (isType<std::string>())
			{
				value = ContentId(boost::any_cast<std::string>(value));
				_type = &Type::singleton<ContentId>();
			}
			return genericConvert<ContentId>();
		}
	}
}
// ---- END AppUnit564_2008ValueConvert.cpp ----

