// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include <boost/shared_ptr.hpp>

namespace RBX {

// INFERRED: the headers already define template shared_from<T> (C2995 on redefinition),
// so only emit the explicit instantiation for PartInstance.
template boost::shared_ptr<PartInstance> shared_from<PartInstance>(PartInstance*);

}
