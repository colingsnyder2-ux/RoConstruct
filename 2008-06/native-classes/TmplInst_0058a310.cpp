// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0058a310 ?_Buynode@?$_Tree@V?$_Tmap_traits@PAVInstance@RBX@@UHistoryItem@2@U?$less@PAVInstance@RBX@@@std@@V?$allocator@: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "v8tree/Instance.h"
#include "v8datamodel/HistoryRecord.h"
#include "util/Object.h"

template class std::_Tree<std::_Tmap_traits<RBX::Instance *,RBX::HistoryItem,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> >,0> >;
