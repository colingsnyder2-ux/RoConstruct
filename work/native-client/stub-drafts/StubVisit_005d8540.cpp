// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0x005d8540: Instance::visitDescendents<boost::bind(void(*)(shared_ptr<Instance>, void*), _1, void*)> (this -> children at +0x108,
// the bound pair {callback, argument} is re-passed by value on the recursive call). Header template in native-headers.
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
typedef void (__cdecl *VisitCallback)(boost::shared_ptr<RBX::Instance>, void*);
typedef boost::_bi::bind_t<void, VisitCallback, boost::_bi::list2<boost::arg<1>, boost::_bi::value<void*> > > VisitBinder;
template void RBX::Instance::visitDescendents<VisitBinder>(VisitBinder) const;
