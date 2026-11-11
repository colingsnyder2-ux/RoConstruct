#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaInstanceBridge2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src df3e9b40 | roc native-status --write
// 2008-06 ObjectBridge / SharedPtrBridge<DescribedBase>::on_tostring declarations for the inactive Lua bridge recovery.
// Replaces the read-only donor script/LuaInstanceBridge.h for this recovery (that header is no longer included by
// LuaBridge2008.h; nothing is declared at the donor path). Shapes are the donor's except ObjectBridge::getInstance
// (COMDAT 0061aac0), whose error message reads the descriptor pointer inline (mov esi,[esi+8] at 0061ab23).

#include "lua/LuaBridge.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "lua.h"
#include "lauxlib.h"
#include "G3D/format.h"

namespace RBX
{
    namespace Lua
    {
        void newweaktable(lua_State* L, const char* mode);

        template <>
        int SharedPtrBridge<Reflection::DescribedBase>::on_tostring(const boost::shared_ptr<Reflection::DescribedBase>& object, lua_State* L)
        {
            Instance* instance = dynamic_cast<Instance*>(object.get());

            if (instance)
                lua_pushstring(L, instance->getName().c_str());
            else
                lua_pushstring(L, object->classDescriptor().name.c_str());

            return 1;
        }

        class ObjectBridge : public SharedPtrBridge<Reflection::DescribedBase>
        {
        private:
            static const luaL_Reg classLibrary[2];
  
        public:
            static int callMemberFunction(lua_State* L);
            static void registerInstanceClassLibrary(lua_State* L)
            {
                luaL_register(L, "Instance", classLibrary);
                lua_pop(L, 1);
            }
            static int newInstance(lua_State* thread);
            // 0061aac0: the message reads the descriptor pointer at +8 inline (getDescriptor), not classDescriptor().
            static boost::shared_ptr<Instance> getInstance(lua_State* L, size_t index)
            {
                boost::shared_ptr<Reflection::DescribedBase> object = getPtr(L, index);
                Reflection::DescribedBase* object2 = object.get();

                if (object2 && !dynamic_cast<Instance*>(object2))
                    throw std::runtime_error(G3D::format("Object %s is not an Instance", object2->getDescriptor().name.c_str()));

                return shared_from(static_cast<Instance*>(object2));
            }
        };
    }
}
