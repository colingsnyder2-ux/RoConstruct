// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
}

typedef std::vector< boost::shared_ptr<RBX::Instance> > InstanceVector;

// INFERRED: this is the copy constructor of std::vector<boost::shared_ptr<RBX::Instance>>
// (proxy alloc, _Allocate, _Uninit_copy, with a try/catch that calls _Tidy).
extern "C" InstanceVector* __fastcall fn_005acb00(InstanceVector* self, int unusedEdx, const InstanceVector* other)
{
    return new (self) InstanceVector(*other);
}
