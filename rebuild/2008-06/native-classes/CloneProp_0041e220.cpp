// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 0041e220: clone of exact 00401030 (rebuild/2008-06/native-classes/CAboutRobloxDialog.cpp), same masked bytes; classindex (clone_propagate.py, byte-proved standalone)
#include <boost/thread/once.hpp>
#include "util/NativeContentProvider.h"
#include "v8tree/Service.h"

namespace RBX {
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
}
template void RBX::ServiceProvider::callDoGetClassIndex<RBX::ContentProvider>();
