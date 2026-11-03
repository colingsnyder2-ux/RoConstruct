#pragma once
#include <boost/shared_ptr.hpp>
#include <string>
#include "v8tree/Instance.h"

// Inactive layout recovery (RTTI .?AVItem/.?AVClass@Metadata@Reflection@RBX@@, .?AVReflection@Metadata@RBX@@).
// Semantic names of the Item flags and string are not proven by the binary; they keep offset names.
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class PropertyDescriptor;
class FunctionDescriptor;
class SignalDescriptor;
namespace Metadata {
extern char sItem[];
extern char sClass[];
class Classes;

// Constructor 0040cff0 stores +0x130=1, +0x131=0, +0x132=0 and default-constructs the string at
// +0x134; destructor 0040b8a0 destroys the string, then Instance. sizeof 0x150.
class Item : public DescribedNonCreatable<Item, Instance, sItem> {
public:
    bool unknown_130;
    bool unknown_131;
    bool unknown_132;
    std::string unknown_134;
};

// Constructor 0040dba0 stores +0x150=-1, +0x154=0; the factory 0040dc70 allocates 0x158.
class Class : public DescribedCreatable<Class, Item, sClass> {
public:
    int unknown_150;
    int unknown_154;
    int getImageIndex() const; // 0041fb30; name provisional (result is the list/tree image index).
    int explorerOrder() const; // 004225b0
};

// RTTI .?AVMember@Metadata@Reflection@RBX@@ (DescribedCreatable<Member, Item, sMember>). Declaration only:
// the member views read only the inherited Item flags of the lookup results.
extern char sMember[];
class Member : public DescribedCreatable<Member, Item, sMember> {
};
} // namespace Metadata
} // namespace Reflection

namespace Metadata {
extern char sReflection[];

// Creator 0040b320 allocates 0x134; constructor 00444c50 clears +0x130, which 00444dd0 fills with
// the Classes child (004436e0) that lookup 00443210 searches through 00443140.
class Reflection : public DescribedCreatable<Reflection, Instance, sReflection> {
public:
    RBX::Reflection::Metadata::Classes* classes;
    static boost::shared_ptr<Reflection> singleton();                                           // 00445020; name provisional
    RBX::Reflection::Metadata::Class* lookup(const RBX::Reflection::ClassDescriptor&, bool) const; // 00443210; name provisional
    // Member lookups by owner class name then member name (0x130 -> findFirstChildByName(owner->name),
    // its Properties/Functions/Events child 00443780/00443820/004438c0, findFirstChildByName(name)).
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::PropertyDescriptor&) const; // 00443ab0; name provisional
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::FunctionDescriptor&) const; // 00443b00; name provisional
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::SignalDescriptor&) const;   // 00443b50; name provisional
};
} // namespace Metadata
} // namespace RBX
