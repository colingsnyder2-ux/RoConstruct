#pragma once
#include <boost/shared_ptr.hpp>
#include <string>
#include "v8tree/Instance.h"

// Inactive layout recovery (RTTI .?AVItem/.?AVClass@Metadata@Reflection@RBX@@, .?AVReflection@Metadata@RBX@@).
// Semantic names of the Item flags and string are not proven by the binary; they keep offset names.
namespace RBX {
namespace Reflection {
class ClassDescriptor;
namespace Metadata {
extern const char* sItem;
extern const char* sClass;
class Classes;

// Constructor 0040cff0 stores +0x130=1, +0x131=0, +0x132=0 and default-constructs the string at
// +0x134; destructor 0040b8a0 destroys the string, then Instance. sizeof 0x150.
class Item : public DescribedNonCreatable<Item, Instance, &sItem> {
public:
    bool unknown_130;
    bool unknown_131;
    bool unknown_132;
    std::string unknown_134;
};

// Constructor 0040dba0 stores +0x150=-1, +0x154=0; the factory 0040dc70 allocates 0x158.
class Class : public DescribedCreatable<Class, Item, &sClass> {
public:
    int unknown_150;
    int unknown_154;
    int getImageIndex() const; // 0041fb30; name provisional (result is the list/tree image index).
};
} // namespace Metadata
} // namespace Reflection

namespace Metadata {
extern const char* sReflection;

// Creator 0040b320 allocates 0x134; constructor 00444c50 clears +0x130, which 00444dd0 fills with
// the Classes child (004436e0) that lookup 00443210 searches through 00443140.
class Reflection : public DescribedCreatable<Reflection, Instance, &sReflection> {
public:
    RBX::Reflection::Metadata::Classes* classes;
    static boost::shared_ptr<Reflection> singleton();                                           // 00445020; name provisional
    RBX::Reflection::Metadata::Class* lookup(const RBX::Reflection::ClassDescriptor&, bool) const; // 00443210; name provisional
};
} // namespace Metadata
} // namespace RBX
