#pragma once
// >>> native-status (generated) -- do not edit >>>
// Metadata | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 3a42e7a6 | roc native-status --write
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
extern char sClasses[];

// Constructor 0040cff0 stores +0x130=1, +0x131=0, +0x132=0 and default-constructs the string at
// +0x134; destructor 0040b8a0 destroys the string, then Instance. sizeof 0x150.
class Item : public DescribedNonCreatable<Item, Instance, sItem> {
public:
    Item();
    bool unknown_130;
    bool unknown_131;
    bool unknown_132;
    std::string unknown_134;
};

// Constructor 0040dba0 stores +0x150=-1, +0x154=0; the factory 0040dc70 allocates 0x158.
class Class : public DescribedCreatable<Class, Item, sClass> {
protected:
    virtual bool askAddChild(const Instance*) const;
public:
    Class();
    int unknown_150;
    int unknown_154;
    int getImageIndex() const; // 0041fb30; name provisional (result is the list/tree image index).
    int explorerOrder() const; // 004225b0
};

// RTTI .?AVMember@Metadata@Reflection@RBX@@ (DescribedCreatable<Member, Item, sMember>). Declaration only:
// the member views read only the inherited Item flags of the lookup results.
extern char sMember[];
class Member : public DescribedCreatable<Member, Item, sMember> {
public:
    Member();
    virtual ~Member();
};
// Original creator 0040d210 allocates 0x130; constructor 0040cdc0 adds no fields.
class Classes : public DescribedCreatable<Classes, Instance, sClasses> {
protected:
    virtual bool askAddChild(const Instance*) const;
public:
    Classes();
    virtual ~Classes();
    void addClass(const ClassDescriptor&); // Original 00444cf0; name provisional.
    Class* lookup(const ClassDescriptor&, bool) const;
};
// RTTI 00929e58: common abstract Instance base, no extra fields.
class Members : public Instance {
protected:
    virtual bool askAddChild(const Instance*) const;
public:
    Members();
};
extern char sProperties[];
class Properties : public DescribedCreatable<Properties, Members, sProperties> {
public:
    Properties();
    virtual ~Properties();
};
extern char sFunctions[];
class Functions : public DescribedCreatable<Functions, Members, sFunctions> {
public:
    Functions();
    virtual ~Functions();
};
extern char sEvents[];
class Events : public DescribedCreatable<Events, Members, sEvents> {
public:
    Events();
    virtual ~Events();
};
} // namespace Metadata
} // namespace Reflection

namespace Metadata {
extern char sReflection[];

// Creator 0040b320 allocates 0x134; constructor 00444c50 clears +0x130, which 00444dd0 fills with
// the Classes child (004436e0) that lookup 00443210 searches through 00443140.
class Reflection : public DescribedCreatable<Reflection, Instance, sReflection> {
protected:
    virtual bool askAddChild(const Instance*) const;
public:
    Reflection();
    virtual ~Reflection();
    RBX::Reflection::Metadata::Classes* classes;
    void load(std::string); // Original 00444dd0; name provisional.
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
