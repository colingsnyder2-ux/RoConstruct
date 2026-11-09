// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_propertyreader2008layoute425037faeaa137c.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#include <security/SecurityContext.h>
#include <v8tree/Instance.h>
#include <reflection/property.h>
#include <boost/shared_ptr.hpp>
struct Descriptor {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual std::string getStringValue(const RBX::Reflection::DescribedBase*) const;};
struct PropertyReader {boost::shared_ptr<RBX::Instance> instance; const Descriptor* descriptor;std::string get() const;};
std::string PropertyReader::get()const { RBX::Security::Impersonator impersonator(RBX::Security::GameScript);return descriptor->getStringValue(instance.get()?reinterpret_cast<const RBX::Reflection::DescribedBase*>(reinterpret_cast<const char*>(instance.get())+0x14):0);}
