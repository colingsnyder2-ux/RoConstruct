// from server: 100% by EspClaude
// from server: 56% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_76d7688d73e35545.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#define _DLL 1
#include <stdexcept>
#include <vector>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"
#include "reflection/type.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >& Value::convert<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >* val = boost::any_cast<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >(&value);
			if (!val)
				throw std::runtime_error("Unable to cast value to Objects");

			return *val;
		}
	}
}
