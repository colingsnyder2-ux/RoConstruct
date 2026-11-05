// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_nativeobjectvalueconvert5bd45d0870ea4db6.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"
#include <g3d/color3.h>
#include <g3d/vector3.h>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"
#include "util/NormalId.h"


namespace RBX { namespace Reflection {
		template<>
		boost::shared_ptr<Instance>& Value::convert<boost::shared_ptr<Instance>>()
		{
			if (isType<void>())
			{
				value = boost::shared_ptr<Instance>();
				_type = &Type::singleton<boost::shared_ptr<Instance>>();
			}
			if (isType<boost::shared_ptr<DescribedBase>>())
			{
				boost::shared_ptr<DescribedBase>* base = boost::any_cast<boost::shared_ptr<DescribedBase>>(&value);
				if (base)
				{
					Instance* instance = dynamic_cast<Instance*>(base->get());
					if (!instance)
						throw std::runtime_error("Unable to cast value to Object");

					value = shared_from(instance);
				}
				else
				{
					value = boost::shared_ptr<Instance>();
				}

				_type = &Type::singleton<boost::shared_ptr<Instance>>();
			}

			boost::shared_ptr<Instance>* val = boost::any_cast<boost::shared_ptr<Instance>>(&value);
			if (!val)
				throw std::runtime_error("Unable to cast value to Object");
				
			return *val;
		}

}}
