#define ContentProvider DonorContentProvider
#include "NativeSlingshotWorkerTrial.h"
#undef ContentProvider
#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderSlingshotOverlay.cpp"
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
