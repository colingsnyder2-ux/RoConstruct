// Rebuild glue: Lua metatable names for the RBX::Lua::Bridge instantiations rbxgs uses but never names.
// Values are the 2008-verified OpenRBX definitions (script/ThreadRef.cpp, ScriptContext.cpp,
// LuaSignalBridge.cpp, LuaAtomicClasses.cpp).
#include "lua/LuaBridge.h"
#include "script/ThreadRef.h"
#include "reflection/signal.h"
#include "v8datamodel/BrickColor.h"
#include <g3d/color3.h>
#include <g3d/vector3.h>
#include <g3d/coordinateframe.h>
#include <boost/signals/connection.hpp>

namespace RBX
{
	namespace Lua
	{
		template<> const char* Bridge<boost::shared_ptr<ThreadRef::Node>, true>::className = "shared_ptr<ThreadRef::Node>";
		template<> const char* Bridge<boost::shared_ptr<Reflection::DescribedBase>, false>::className = "Object";
		template<> const char* Bridge<boost::signals::connection, true>::className = "RBXScriptConnection";
		template<> const char* Bridge<boost::shared_ptr<Reflection::SignalInstance>, false>::className = "RBXScriptSignal";
		template<> const char* Bridge<G3D::Color3, true>::className = "Color3";
		template<> const char* Bridge<G3D::Vector3, true>::className = "Vector3";
		template<> const char* Bridge<BrickColor, true>::className = "BrickColor";
		template<> const char* Bridge<G3D::CoordinateFrame, true>::className = "CFrame";
	}
}
