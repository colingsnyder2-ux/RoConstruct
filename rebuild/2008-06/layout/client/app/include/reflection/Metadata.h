// =============================================================================
// Metadata.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/reflection/Metadata.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/shared_ptr.hpp>
#include <string>
#include "v8tree/Instance.h"

namespace RBX
{
namespace Reflection
{
class ClassDescriptor;
class PropertyDescriptor;
class FunctionDescriptor;
class SignalDescriptor;
namespace Metadata
{
extern char sItem[];
extern char sClass[];
class Classes;
extern char sClasses[];

class Item : public DescribedNonCreatable<Item, Instance, sItem> {
public:
    Item();
    bool unknown_130;
    bool unknown_131;
    bool unknown_132;
    std::string unknown_134;
};

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

extern char sMember[];
class Member : public DescribedCreatable<Member, Item, sMember> {
public:
    Member();
    virtual ~Member();
};
class Classes : public DescribedCreatable<Classes, Instance, sClasses> {
protected:
    virtual bool askAddChild(const Instance*) const;
public:
    Classes();
    virtual ~Classes();
    void addClass(const ClassDescriptor&); // Original 00444cf0; name provisional.
    Class* lookup(const ClassDescriptor&, bool) const;
};
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

namespace Metadata
{
extern char sReflection[];

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
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::PropertyDescriptor&) const; // 00443ab0; name provisional
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::FunctionDescriptor&) const; // 00443b00; name provisional
    RBX::Reflection::Metadata::Member* lookup(const RBX::Reflection::SignalDescriptor&) const;   // 00443b50; name provisional
};
} // namespace Metadata
} // namespace RBX
