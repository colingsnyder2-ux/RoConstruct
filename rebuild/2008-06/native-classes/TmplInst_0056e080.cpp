// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0056e080 ??$static_pointer_cast@VDescribedBase@Reflection@RBX@@VInstance@3@@boost@@YA?AV?$shared_ptr@VDescribedBase@Ref: explicit template instantiation (generic_templates.py, function form, byte-proved standalone)
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include "reflection/Metadata.h"
#include "v8tree/Instance.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Reflection::DescribedBase> boost::static_pointer_cast<RBX::Reflection::DescribedBase,RBX::Instance>(boost::shared_ptr<RBX::Instance> const &);
