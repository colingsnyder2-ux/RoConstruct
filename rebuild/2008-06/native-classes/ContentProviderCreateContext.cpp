// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// >>> native-status (generated) -- do not edit >>>
// ContentProviderCreateContext | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | named 1 | 0 unproved | no mapped strings | by auto
// <<< native-status | src 173cac78 | roc native-status --write
#include "util/NativeContentProvider.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ShootTools.h"
namespace RBX {
template<> ContentProvider* ServiceProvider::create<ContentProvider>(const Instance* context) {
 while (context) {
  const ServiceProvider* provider=dynamic_cast<const ServiceProvider*>(context);
  if (provider) return provider->create<ContentProvider>();
  context=context->getParent();
 }
 return NULL;
}
}
