// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00616320 (placeholder name for 00616320 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <set>
#include <boost/ref.hpp>
#include "util/Name.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

boost::reference_wrapper<Selection> sub_00616320(std::set<PartInstance*>::const_iterator first, std::set<PartInstance*>::const_iterator last, boost::reference_wrapper<Selection> selection)
{
	for (; first != last; ++first)
		selection.get().removeFromSelection(*first);
	return selection;
}

}
