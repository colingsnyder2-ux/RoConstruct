// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0055a190: explicit instantiation of the class the body at 0055a190 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <boost/shared_ptr.hpp>
#include <vector>
#include "reflection/Metadata.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
template class RBX::Reflection::BoundFuncDesc<class RBX::Instance,class boost::shared_ptr<class std::vector<class boost::shared_ptr<class RBX::Instance>,class std::allocator<class boost::shared_ptr<class RBX::Instance> > > const > __cdecl(void),0>;
