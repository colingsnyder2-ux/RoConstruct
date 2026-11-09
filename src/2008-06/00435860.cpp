// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_declaration_descriptor_public_name_cstr_e4dda9fbc10cd43e.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/function.h", "roc_signature_public_accessor_function_e334687d4a8aba35.cpp")
#pragma include_alias("reflection/signal.h", "roc_signature_public_accessor_signal_b33900fd226b9b4a.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_enum_item_genuine_owner_header4eec83b4b5d2a3a5.cpp")
#pragma include_alias("xstring", "roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp")
#pragma include_alias(<xstring>, <roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp>)
// Native00435860: descriptor casts, real signature lists, metadata lookups.
#define _CPPUNWIND 1
#define _AFXDLL
#include <afxwin.h>
#include <string>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include "reflection/object.h"
#include "reflection/enumconverter.h"
#include "G3D/format.h"
using namespace RBX;
using namespace RBX::Reflection;
// Pointer-only metadata API, from genuine ReflectionMetadata.h. Native lookups
// 443210/443ab0/443b00/443b50 use descriptor references and return object pointers.
namespace RBX { namespace Reflection { namespace Metadata {
class Class;
class Member;
class Reflection {
public:
    static boost::shared_ptr<Reflection> singleton();
    Class* get(const ClassDescriptor&, bool) const;
    Member* get(const PropertyDescriptor&) const;
    Member* get(const FunctionDescriptor&) const;
    Member* get(const SignalDescriptor&) const;
};
} } }
class CDeclarationView {
public:
    void setDeclaration(const void*, const char*, const char*);
    void showDescriptor(const Descriptor*);
};
// Native435550 takes count/text pointers and a signature-item reference.
void appendArgument(int*, std::string*, const SignatureDescriptor::Item&);
void CDeclarationView::showDescriptor(const Descriptor* descriptor)
{
    if (!descriptor) {
        setDeclaration(NULL, NULL, NULL);
        return;
    }
    std::string declaration;
    const void* metadata = NULL;
    const ClassDescriptor* owner = NULL;
    if (const FunctionDescriptor* function = dynamic_cast<const FunctionDescriptor*>(descriptor)) {
        declaration = function->getSignature().resultType->name.toString();
        declaration += " ";
        declaration += function->name.toString();
        declaration += "(";
        int count = 0;
        std::for_each(function->getSignature().arguments.begin(), function->getSignature().arguments.end(), boost::bind(&appendArgument, &count, &declaration, _1));
        declaration += ")";
        owner = &function->owner;
        metadata = Metadata::Reflection::singleton()->get(*function);
    } else if (const PropertyDescriptor* property = dynamic_cast<const PropertyDescriptor*>(descriptor)) {
        declaration = property->type.name.toString();
        declaration += " ";
        declaration += property->name.toString();
        owner = &property->owner;
        metadata = Metadata::Reflection::singleton()->get(*property);
    } else if (const SignalDescriptor* signal = dynamic_cast<const SignalDescriptor*>(descriptor)) {
        declaration = "event ";
        declaration += signal->name.toString();
        declaration += "(";
        int count = 0;
        std::for_each(signal->getSignature().arguments.begin(), signal->getSignature().arguments.end(), boost::bind(&appendArgument, &count, &declaration, _1));
        declaration += ")";
        owner = &signal->owner;
        metadata = Metadata::Reflection::singleton()->get(*signal);
    } else if (const EnumDescriptor::Item* item = dynamic_cast<const EnumDescriptor::Item*>(descriptor)) {
        declaration = G3D::format("%d: %s", item->value, item->name.c_str());
    } else if (const ClassDescriptor* cls = dynamic_cast<const ClassDescriptor*>(descriptor)) {
        declaration = cls->name.toString();
        metadata = Metadata::Reflection::singleton()->get(*cls, false);
    } else {
        declaration = descriptor->name.toString();
    }
    setDeclaration(metadata, declaration.c_str(), owner ? owner->name.c_str() : NULL);
}
