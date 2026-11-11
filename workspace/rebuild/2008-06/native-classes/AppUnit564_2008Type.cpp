// 2008-06 native reflection type singletons of the application range 00564000..00570000 (inactive).
// Type::singleton<T> 0056ca70..0056cfb0: a function-local static Type(name, typeid(T)) built through the out-of-line
// Type(const char*, const type_info&) 0056bd90 (emitted here as the header-inline COMDAT), destroyed at exit by the
// atexit stubs 007fd210..007fd2d0. The name strings and type descriptors are read from the pushes of each body.
// >>> native-status (generated) -- do not edit >>>
// AppUnit564_2008Type | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src bd946f16 | roc native-status --write
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
