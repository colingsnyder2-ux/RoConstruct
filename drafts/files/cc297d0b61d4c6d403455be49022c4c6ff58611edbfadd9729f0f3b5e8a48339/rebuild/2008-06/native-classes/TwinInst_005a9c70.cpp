// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005a9c70: explicit instantiation of the class the body at 005a9c70 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "lua/LuaBridge.h"
#include "LuaBridge2008/LuaEnumBridge2008.h"
#include "reflection/reflection.h"
#include "LuaBridge2008/LuaInstanceBridge2008.h"
template class RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>;
template bool RBX::Lua::Bridge<RBX::Lua::EnumDescriptorItemPtr, true>::getValue<RBX::Reflection::Value>(lua_State*, size_t, RBX::Reflection::Value&);

// LuaArguments::pushTable instances of the ScriptContext / Lua bridge range. Identity: the registry decorated names
// ??$pushTable@V?$_Vector_const_iterator@VValue@Reflection@RBX@@...@LuaArguments@Lua@RBX@@SAH... (005aa000) and
// ...shared_ptr@VInstance...@LuaArguments@Lua@RBX@@SAH... (005ac2f0) and the RTTI .?AVLuaArguments@Lua@RBX@@ of vtable
// 00844174 name the class RBX::Lua::LuaArguments. The shared LuaBridge2008/LuaArguments2008.h declares the same shape
// under the analog name LuaArguments2008 (the donor script/LuaArguments.h still needs RBX::Instances), so this unit
// declares the class under its RTTI name, member for member as LuaArguments2008 (header proposal: rename the analog).
#include "reflection/function.h"
#include "script/LuaAtomicClasses.h"
#include "script/ThreadRef.h"
#include "v8tree/Instance.h"
#include "util/ContentProvider.h"
#include "lua.h"
namespace RBX
{
	namespace Lua
	{
		// INFERRED: unit-local declaration; layout and members copied from LuaBridge2008/LuaArguments2008.h (vtable
		// 00844174: size() 0061a5f0, get(int, Value&) 0061bcb0; offset +0xc, L +0x10).
		class LuaArguments : public Reflection::FunctionDescriptor::Arguments
		{
		private:
			const int offset;
			lua_State* L;

		public:
			LuaArguments(lua_State* L, int offset)
				: offset(offset),
				  L(L)
			{
			}
			virtual size_t size() const;
			virtual void get(int index, Reflection::Value& value) const;

		public:
			static bool get(lua_State* L, int luaIndex, Reflection::Value& value, bool nested); // 005ad380
			static int push(const Reflection::Value& value, lua_State* const L);                // 005aba50

			// Donor script/LuaArguments.h pushTable: lua_createtable 00612570, push 005aba50 per element,
			// lua_rawseti(L, -2, ++i) 00612780, return 1.
			template<typename T>
			static int pushTable(T first, T last, lua_State* const L)
			{
				lua_createtable(L, last - first, 0);

				int i = 0;
				for (; first != last; first++)
				{
					push(*first, L);
					lua_rawseti(L, -2, ++i);
				}

				return 1;
			}
		};
	}
}
// @005aa000 pushTable<vector<Value>::const_iterator> (200 B)
template int RBX::Lua::LuaArguments::pushTable<std::vector<RBX::Reflection::Value>::const_iterator>(
	std::vector<RBX::Reflection::Value>::const_iterator, std::vector<RBX::Reflection::Value>::const_iterator, lua_State* const);
// @005ac2f0 pushTable<vector<shared_ptr<Instance> >::const_iterator> (350 B)
// Exact since batch 43 (with LuaArguments::push below in the same unit). Earlier note: PARKED (batch 28, 3 hypotheses): built 356 B. Same calls and block order, but the target keeps the counter i in ebp,
// the any holder in esi across the push call (its delete reads esi, not the Value's memory) and reloads L from its
// argument slot; this body keeps L in ebp, spills i and re-reads the holder from the temporary. Rejected: donor
// `first++` (kept), `++first` (same 356 B), a named `const Value value(*first)` local (367 B; Value instance 303 B).
template int RBX::Lua::LuaArguments::pushTable<std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator>(
	std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator, std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator,
	lua_State* const);

namespace RBX
{
	namespace Lua
	{
		// 005aba50 (registry placeholder; cdecl, the static push called by pushArguments 005abf90, the pushTable
		// instances 005aa000 / 005ac2f0, itself, and ObjectBridge::callMemberFunction 0061c0e0). The openrbx 2007
		// LuaArguments.h push with the 2008 Tuple case (cast 005ab1b0, every value pushed and the counts summed) before the
		// shared_ptr<const Instances> case (cast 005ab9e0 into a local; pushTable 005ac2f0, or lua_createtable(L, 0, 0)).
		int LuaArguments::push(const Reflection::Value& value, lua_State* const L)
		{
			if (value.isType<void>())
				return 0;

			if (value.isType<int>())
			{
				lua_pushinteger(L, value.cast<int>());
				return 1;
			}

			if (value.isType<bool>())
			{
				lua_pushboolean(L, value.cast<bool>());
				return 1;
			}

			if (value.isType<float>())
			{
				lua_pushnumber(L, value.cast<float>());
				return 1;
			}

			if (value.isType<double>())
			{
				lua_pushnumber(L, value.cast<double>());
				return 1;
			}

			if (value.isType<FunctionRef>())
			{
				lua_pushfunction(L, value.cast<const FunctionRef&>());
				return 1;
			}

			if (value.isType<std::string>())
			{
				lua_pushstring(L, value.cast<const std::string&>().c_str());
				return 1;
			}

			if (value.isType<G3D::Vector3>())
			{
				Vector3Bridge::pushVector3(L, value.cast<const G3D::Vector3&>());
				return 1;
			}

			if (value.isType<G3D::CoordinateFrame>())
			{
				CoordinateFrameBridge::pushCoordinateFrame(L, value.cast<const G3D::CoordinateFrame&>());
				return 1;
			}

			if (value.isType<G3D::Color3>())
			{
				Color3Bridge::pushColor3(L, value.cast<const G3D::Color3&>());
				return 1;
			}

			if (value.isType<BrickColor>())
			{
				Bridge<BrickColor, true>::pushNewObject(L, value.cast<const BrickColor&>());
				return 1;
			}

			if (value.isType<ContentId>())
			{
				lua_pushstring(L, value.cast<const ContentId&>().c_str());
				return 1;
			}

			if (value.isType<boost::shared_ptr<Instance> >())
			{
				SharedPtrBridge<Reflection::DescribedBase>::push(L, value.cast<const boost::shared_ptr<Instance>&>());
				return 1;
			}

			if (value.isType<boost::shared_ptr<Reflection::DescribedBase> >())
			{
				SharedPtrBridge<Reflection::DescribedBase>::push(L, value.cast<const boost::shared_ptr<Reflection::DescribedBase>&>());
				return 1;
			}

			if (value.isType<Reflection::ValueCollection>())
			{
				const Reflection::ValueCollection& values = value.cast<const Reflection::ValueCollection&>();
				return pushTable(values.begin(), values.end(), L);
			}

			if (value.isType<Reflection::Tuple>())
			{
				const Reflection::Tuple& tuple = value.cast<const Reflection::Tuple&>();
				int count = 0;
				for (Reflection::ValueCollection::const_iterator iter = tuple.values.begin(), end = tuple.values.end(); iter != end; ++iter)
					count += push(*iter, L);
				return count;
			}

			if (value.isType<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >())
			{
				boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > instances =
					value.cast<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >();
				if (instances)
					return pushTable(instances->begin(), instances->end(), L);

				lua_newtable(L);
				return 1;
			}

			return 0;
		}
	}
}
