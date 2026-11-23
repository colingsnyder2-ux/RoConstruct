// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
// INFERRED: header path for PartInstance (and through it Instance) is a guess
#include "v8datamodel/PartInstance.h"

namespace RBX {

// The generic template RBX::shared_from<Class>(Class*) is already defined by the
// native headers (the previous attempt's redefinition caused C2995).
// INFERRED: explicit instantiation emits the target symbol from the header's template.
template boost::shared_ptr<PartInstance> shared_from<PartInstance>(PartInstance*);

}
