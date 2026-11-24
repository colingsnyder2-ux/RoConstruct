// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <string>
#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include "LuaBridge2008/LuaSignalBridge2008.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "LuaBridge2008/LuaArguments2008.h"

// INFERRED: unknown callees, fixed naming convention
extern "C" int __fastcall fn_0061aac0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_004ab530(void* self, int unusedEdx, int a1, int a2);

// INFERRED: the static helpers of LuaBridge2008Instance.cpp are not visible through the headers, so they are declared by address.
namespace RBX { class Instance; }
extern "C" void fn_0061bcd0(RBX::Instance* instance);
extern "C" void fn_0061b190(RBX::Reflection::Property p, lua_State* L, int index);

namespace RBX {
namespace Lua {

// INFERRED: reads the protected ConstProperty::descriptor member
struct PropAccess : public Reflection::ConstProperty
{
    static const void* get(const Reflection::ConstProperty& p)
    {
        return p.*(&PropAccess::descriptor);
    }
};

// INFERRED: the Bridge template/specialisation is declared in the bridge headers.
template<>
void Bridge<boost::shared_ptr<Reflection::DescribedBase>, 0>::on_newindex(
    boost::shared_ptr<Reflection::DescribedBase>& object,
    const char* name,
    lua_State* L)
{
    if (!object)
        throw std::runtime_error("The object has been deleted");

    Instance* instance = dynamic_cast<Instance*>(object.get());
    fn_0061bcd0(instance);

    // INFERRED: DescribedBase::findProperty / properties_end inline into
    // findDescriptor + Iterator(this, it) and a vector end() comparison
    Reflection::DescribedBase::PropertyIterator iter = object->findProperty(Name::lookup(name));

    if (iter == object->properties_end())
    {
        throw std::runtime_error(
            G3D::format("%s is not a valid member of %s", name,
                        object->getDescriptor().name.c_str()));
    }

    // INFERRED: 0x973d34 is the Instance "Parent" property descriptor
    if (PropAccess::get(*iter) == (const void*)&Instance::propParent)
    {
        Instance* inst = dynamic_cast<Instance*>(object.get());
        if (!inst)
        {
            throw std::runtime_error(
                G3D::format("%s is not a valid member of %s", name,
                            object->getDescriptor().name.c_str()));
        }

        boost::shared_ptr<Instance> newParent;
        fn_0061aac0(0, 0, (int)&newParent, (int)L, 3);

        if (inst->parent != newParent.get())
        {
            if (!inst->canSetParent(newParent.get()))
            {
                boost::shared_ptr<StandardOut> out = StandardOut::singleton();
                out->print(MESSAGE_ERROR, "%s should not be a child of %s",
                           inst->getFullName().c_str(),
                           newParent->getFullName().c_str());
            }
            // INFERRED: Instance::setParent(shared_ptr<Instance>) takes the pointer by value
            char buf[sizeof(boost::shared_ptr<Instance>)];
            new (buf) boost::shared_ptr<Instance>(newParent);
            int* w = (int*)buf;
            fn_004ab530(inst, 0, w[0], w[1]);
        }
    }
    else
    {
        fn_0061b190(*iter, L, 3);
    }
}

}
}
