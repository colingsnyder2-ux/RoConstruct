// Inactive 2008-06 native recovery: RBX::Lua atomic bridges (Vector3, Color3, CoordinateFrame, BrickColor).
// Body shapes follow the donor reconstruction; counted rows are proven by tests/record_native_lua_bridge2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// LuaBridge2008Atomic | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src afd3f7f2 | roc native-status --write
#include "LuaBridge2008/LuaBridge2008.h"
#include "G3D/Quat.h"
#include "lua.h"
#include <float.h>
#include <limits>

using namespace RBX;
using namespace RBX::Lua;

// 0095b1cc: a constant-initialized pointer to "" in this unit's data block (after the className statics), read by
// tostringOrEmpty 0061c790 (mov eax, [0095b1cc]).
const char* RBX::Lua::emptyString2008 = "";

// 0061c790: lua_tostring, or "" for a non-string (called by ScriptContext 005aec88 / 005afb7f / 005b02ff).
const char* RBX::Lua::tostringOrEmpty(lua_State* L, int index)
{
    const char* s = lua_tostring(L, index);
    if (!s)
        return emptyString2008;
    return s;
}

// 0061c7b0: lua_tostring that throws "String expected" (called by ObjectBridge::newInstance 0061bb91, the property
// assignment 0061b190 and ScriptContext 005ade74).
const char* RBX::Lua::tostringChecked(lua_State* L, int index)
{
    const char* s = lua_tostring(L, index);
    if (!s)
        throw std::runtime_error("String expected");
    return s;
}

// 0061c830: lapi lua_tonumber (00611f60) clamped into float range: +-inf map to the float infinities (the MSVCP90 _Inf /
// _FInf imports), NaN passes through, finite values beyond FLT_MAX clamp to +-FLT_MAX (double compare constants, float
// results). Called by this unit's constructors / operators and by the instance bridge (0061b255, 0061b29c). It
// returns float without a rounding store, so this unit is compiled with /fp:fast (the recorder's atomic profile).
float RBX::Lua::tonumberClamped(lua_State* L, int index)
{
    double value = lua_tonumber(L, index);
    if (value == std::numeric_limits<double>::infinity())
        return std::numeric_limits<float>::infinity();
    if (value == -std::numeric_limits<double>::infinity())
        return -std::numeric_limits<float>::infinity();
    if (!(value < 0.0) && !(value >= 0.0))
        return value;
    if (value > FLT_MAX)
        return FLT_MAX;
    if (value < -FLT_MAX)
        return -FLT_MAX;
    return value;
}

const luaL_Reg Color3Bridge::classLibrary[] = 
{
    {"new", Color3Bridge::newColor3},
    {NULL, NULL}
};

int Color3Bridge::newColor3(lua_State* L)
{
    float color[3];
    int nargs = std::min(3, lua_gettop(L));

    for (int i = 0; i < nargs; i++)
        color[i] = tonumberClamped(L, i+1);

    for (int i = nargs; i < 3; i++)
        color[i] = 0;

    pushColor3(L, color);
    return 1;
}

template<>
int Color3Bridge::on_index(const G3D::Color3& object, const char* name, lua_State* L)
{
    if (strcmp(name, "r") == 0)
    {
        lua_pushnumber(L, object.r);
        return 1;
    }

    if (strcmp(name, "g") == 0)
    {
        lua_pushnumber(L, object.g);
        return 1;
    }

    if (strcmp(name, "b") == 0)
    {
        lua_pushnumber(L, object.b);
        return 1;
    }
    
    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

const luaL_Reg Vector3Bridge::classLibrary[] = 
{
    {"new", Vector3Bridge::newVector3},
    {NULL, NULL}
};
        
int Vector3Bridge::on_add(lua_State* L)
{
    G3D::Vector3& a = getObject(L, 1);
    G3D::Vector3& b = getObject(L, 2);
    pushVector3(L, a+b);
    return 1;
}

int Vector3Bridge::on_sub(lua_State* L)
{
    G3D::Vector3& a = getObject(L, 1);
    G3D::Vector3& b = getObject(L, 2);
    pushVector3(L, a-b);
    return 1;
}

int Vector3Bridge::on_mul(lua_State* L)
{
    G3D::Vector3 a;
    if (getValue(L, 1, a))
    {
        G3D::Vector3 b;
        if (getValue(L, 2, b))
        {
            pushVector3(L, a*b);
            return 1;
        }
        else
        {
            float x = tonumberClamped(L, 2);
            pushVector3(L, a*x);
            return 1;
        }
    }
    else
    {
        a = getObject(L, 2);
        float x = tonumberClamped(L, 1);
        pushVector3(L, a*x);
        return 1;
    }
}

int Vector3Bridge::on_div(lua_State* L)
{
    G3D::Vector3 a;
    if (getValue(L, 1, a))
    {
        G3D::Vector3 b;
        if (getValue(L, 2, b))
        {
            pushVector3(L, a/b);
            return 1;
        }
        else
        {
            float x = tonumberClamped(L, 2);
            pushVector3(L, a/x);
            return 1;
        }
    }
    else
    {
        a = getObject(L, 2);
        float x = tonumberClamped(L, 1);
        G3D::Vector3 xVec(x,x,x);
        pushVector3(L, xVec/a);
        return 1;
    }
}

int Vector3Bridge::on_unm(lua_State* L)
{
    G3D::Vector3& vec = getObject(L, 1);
    pushVector3(L, -vec);
    return 1;
}

int Vector3Bridge::newVector3(lua_State* L)
{
    float vector[3];
    int nargs = std::min(3, lua_gettop(L));

    for (int i = 0; i < nargs; i++)
        vector[i] = tonumberClamped(L, i+1);

    for (int i = nargs; i < 3; i++)
        vector[i] = 0;

    pushVector3(L, vector);
    return 1;
}

static int lerp(lua_State* L)
{
    G3D::Vector3& a = Vector3Bridge::getObject(L, 1);
    G3D::Vector3& b = Vector3Bridge::getObject(L, 2);
    float c = tonumberClamped(L, 3);

    G3D::Vector3 result = (b-a)*c + a;
    
    Vector3Bridge::pushNewObject(L, result);
    return 1;
}

template<>
int Vector3Bridge::on_index(const G3D::Vector3& object, const char* name, lua_State* L)
{
    if (strcmp(name, "x") == 0)
    {
        lua_pushnumber(L, object.x);
        return 1;
    }

    if (strcmp(name, "y") == 0)
    {
        lua_pushnumber(L, object.y);
        return 1;
    }

    if (strcmp(name, "z") == 0)
    {
        lua_pushnumber(L, object.z);
        return 1;
    }

    if (strcmp(name, "unit") == 0)
    {
        Vector3Bridge::pushNewObject(L, object.unit());
        return 1;
    }

    if (strcmp(name, "magnitude") == 0)
    {
        lua_pushnumber(L, object.magnitude());
        return 1;
    }

    if (strcmp(name, "lerp") == 0)
    {
        lua_pushcfunction(L, lerp);
        return 1;
    }
    
    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

static int pushRed(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoRed());
    return 1;
}

static int pushWhite(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoWhite());
    return 1;
}

static int pushGray(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoGray());
    return 1;
}

static int pushDarkGray(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoDarkGray());
    return 1;
}

static int pushBlack(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoBlack());
    return 1;
}

static int pushYellow(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoYellow());
    return 1;
}

static int pushGreen(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoGreen());
    return 1;
}

static int pushBlue(lua_State* L)
{
    BrickColorBridge::pushNewObject(L, BrickColor::legoBlue());
    return 1;
}

const luaL_Reg BrickColorBridge::classLibrary[] = 
{
    {"new", BrickColorBridge::newBrickColor},
    {"random", BrickColorBridge::randomBrickColor},
    {"New", BrickColorBridge::newBrickColor},
    {"Random", BrickColorBridge::randomBrickColor},
    {"White", pushWhite},
    {"Gray", pushGray},
    {"DarkGray", pushDarkGray},
    {"Black", pushBlack},
    {"Red", pushRed},
    {"Yellow", pushYellow},
    {"Green", pushGreen},
    {"Blue", pushBlue},
    {NULL, NULL}
};

int BrickColorBridge::newBrickColor(lua_State* L)
{
    int nargs = std::min(4, lua_gettop(L));

    if (nargs == 0)
    {
        pushNewObject(L, BrickColor::defaultColor());
        // bug! there's no return here lol
    }

    if (nargs == 1)
    {
        if (lua_isnumber(L ,1))
        {
            int num = lua_tointeger(L, 1);
            pushNewObject(L, BrickColor(num));
            return 1;
        }
        else if (lua_isstring(L, 1))
        {
            const char* name = lua_tostring(L, 1);
            pushNewObject(L, BrickColor::parse(name));
            return 1;
        }
        else
        {
            G3D::Color3& color3 = Color3Bridge::getObject(L, 1);
            pushNewObject(L, BrickColor::closest(color3));
            return 1;
        }
    }

    G3D::Color4 color(0, 0, 0);

    for (int i = 0; i < nargs; i++)
        color[i] = tonumberClamped(L, i+1);

    pushNewObject(L, BrickColor::closest(color));
    return 1;
}

int BrickColorBridge::randomBrickColor(lua_State* L)
{
    pushNewObject(L, BrickColor::random().number);
    return 1;
}

template<>
int BrickColorBridge::on_index(const BrickColor& object, const char* name, lua_State* L)
{
    if (strcmp(name, "number") == 0)
    {
        lua_pushinteger(L, object.number);
        return 1;
    }

    if (strcmp(name, "Number") == 0)
    {
        lua_pushinteger(L, object.number);
        return 1;
    }

    if (strcmp(name, "Color") == 0)
    {
        Color3Bridge::pushColor3(L, object.color3());
        return 1;
    }

    if (strcmp(name, "r") == 0)
    {
        lua_pushnumber(L, object.color3().r);
        return 1;
    }

    if (strcmp(name, "g") == 0)
    {
        lua_pushnumber(L, object.color3().g);
        return 1;
    }

    if (strcmp(name, "b") == 0)
    {
        lua_pushnumber(L, object.color3().b);
        return 1;
    }

    if (strcmp(name, "name") == 0)
    {
        lua_pushstring(L, object.name().c_str());
        return 1;
    }

    if (strcmp(name, "Name") == 0)
    {
        lua_pushstring(L, object.name().c_str());
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

const luaL_Reg CoordinateFrameBridge::classLibrary[] =
{
    {"new", CoordinateFrameBridge::newCoordinateFrame},
    {"fromEulerAnglesXYZ", CoordinateFrameBridge::fromEulerAnglesXYZ},
    {"fromAxisAngle", CoordinateFrameBridge::fromAxisAngle},
    {NULL, NULL}
};

int CoordinateFrameBridge::newCoordinateFrame(lua_State* L)
{
    G3D::CoordinateFrame cf;

    int nargs = lua_gettop(L);

    switch (nargs)
    {
    case 0:
        break;

    case 1:
        cf.translation = Vector3Bridge::getObject(L, 1);
        break;

    case 2:
        cf.translation = Vector3Bridge::getObject(L, 1);
        cf.lookAt(Vector3Bridge::getObject(L, 2));
        break;

    case 3:
        for (int i = 0; i < 3; i++)
            cf.translation[i] = tonumberClamped(L, i+1);
        break;

    case 7:     // the switch byte table at 0061dbe0 maps 7 (not 4) to the quaternion case
    {
        for (int i = 0; i < 3; i++)
            cf.translation[i] = tonumberClamped(L, i+1);

        G3D::Quat q;
        q.x = tonumberClamped(L, 4);
        q.y = tonumberClamped(L, 5);
        q.z = tonumberClamped(L, 6);
        q.w = tonumberClamped(L, 7);

        cf.rotation = q;
        break;
    }

    case 12:
    {
        for (int i = 0; i < 3; i++)
            cf.translation[i] = tonumberClamped(L, i+1);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cf.rotation[i][j] = tonumberClamped(L, 4 + i*3 + j);
        }

        break;
    }
        
    default:
        throw std::runtime_error(G3D::format("Invalid number of arguments: %d", nargs));
    }
    
    pushNewObject(L, cf);
    return 1;
}

int CoordinateFrameBridge::on_add(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    G3D::Vector3& b = Vector3Bridge::getObject(L, 2);
    pushCoordinateFrame(L, a+b);
    return 1;
}

int CoordinateFrameBridge::on_sub(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    G3D::Vector3& b = Vector3Bridge::getObject(L, 2);
    pushCoordinateFrame(L, a-b);
    return 1;
}

int CoordinateFrameBridge::on_mul(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    G3D::CoordinateFrame b;

    if (getValue(L, 2, b))
    {
        pushCoordinateFrame(L, a*b);
        return 1;
    }
    else
    {
        G3D::Vector4 v(Vector3Bridge::getObject(L, 2), 1.0f);
        Vector3Bridge::pushVector3(L, a.toWorldSpace(v).xyz());
        return 1;
    }
}

int CoordinateFrameBridge::on_inverse(lua_State* L)
{
    G3D::CoordinateFrame& cf = getObject(L, 1);
    pushCoordinateFrame(L, cf.inverse());
    return 1;
}

int CoordinateFrameBridge::on_toWorldSpace(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
        pushCoordinateFrame(L, a);
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::CoordinateFrame& b = getObject(L, 2+i);
        pushCoordinateFrame(L, a*b);
    }   

    return count;
}

int CoordinateFrameBridge::on_toObjectSpace(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
        pushCoordinateFrame(L, a.inverse());
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::CoordinateFrame& b = getObject(L, 2+i);
        pushCoordinateFrame(L, a.toObjectSpace(b));
    }   

    return count;
}

int CoordinateFrameBridge::on_pointToWorldSpace(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
        Vector3Bridge::pushVector3(L, a.pointToWorldSpace(G3D::Vector3::zero()));
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::Vector3& b = Vector3Bridge::getObject(L, 2+i);
        Vector3Bridge::pushVector3(L, a.pointToWorldSpace(b));
    }   

    return count;
}

int CoordinateFrameBridge::on_pointToObjectSpace(lua_State *L)
{
	G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
		Vector3Bridge::pushVector3(L, a.pointToObjectSpace(G3D::Vector3::zero()));
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::Vector3& b = Vector3Bridge::getObject(L, 2+i);
		Vector3Bridge::pushVector3(L, a.pointToObjectSpace(b));
    }   

    return count;
}

int CoordinateFrameBridge::on_vectorToWorldSpace(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
        Vector3Bridge::pushVector3(L, a.vectorToWorldSpace(G3D::Vector3::zero()));
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::Vector3& b = Vector3Bridge::getObject(L, 2+i);
        Vector3Bridge::pushVector3(L, a.vectorToWorldSpace(b));
    }   

    return count;
}

int CoordinateFrameBridge::on_components(lua_State* L)
{
    G3D::CoordinateFrame& cf = getObject(L, 1);

    lua_pushnumber(L, cf.translation.x);
    lua_pushnumber(L, cf.translation.y);
    lua_pushnumber(L, cf.translation.z);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            lua_pushnumber(L, cf.rotation[i][j]);
    }

    return 12;
}

int CoordinateFrameBridge::on_toEulerAnglesXYZ(lua_State* L)
{
    G3D::CoordinateFrame& cf = getObject(L, 1);
    float x, y, z;
    cf.rotation.toEulerAnglesXYZ(x, y, z);
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    lua_pushnumber(L, z);
    return 3;
}

int CoordinateFrameBridge::on_vectorToObjectSpace(lua_State* L)
{
    G3D::CoordinateFrame& a = getObject(L, 1);
    int count = lua_gettop(L)-1;

    if (count == 0)
    {
        Vector3Bridge::pushVector3(L, a.vectorToObjectSpace(G3D::Vector3::zero()));
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        G3D::Vector3& b = Vector3Bridge::getObject(L, 2+i);
        Vector3Bridge::pushVector3(L, a.vectorToObjectSpace(b));
    }   

    return count;
}

int CoordinateFrameBridge::fromEulerAnglesXYZ(lua_State* L)
{
    G3D::CoordinateFrame cf;
    cf.rotation = G3D::Matrix3::fromEulerAnglesXYZ(
        luaL_checknumber(L, 1),
        luaL_checknumber(L, 2),
        luaL_checknumber(L, 3)
    );

    pushNewObject(L, cf);
    return 1;
}

int CoordinateFrameBridge::fromAxisAngle(lua_State* L)
{
    G3D::CoordinateFrame cf;
    G3D::Vector3& v = Vector3Bridge::getObject(L, 1);
    float r = luaL_checknumber(L, 2);
    cf.rotation = G3D::Matrix3::fromAxisAngle(v, r);

    pushNewObject(L, cf);
    return 1;
}

template<>
int CoordinateFrameBridge::on_index(const G3D::CoordinateFrame& object, const char* name, lua_State* L)
{
    if (strcmp(name, "p") == 0)
    {
        Vector3Bridge::pushVector3(L, object.translation);
        return 1;
    }

    if (strcmp(name, "lookVector") == 0)
    {
        Vector3Bridge::pushVector3(L, object.lookVector());
        return 1;
    }

    if (strcmp(name, "inverse") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_inverse, 1);
        return 1;
    }

    if (strcmp(name, "toWorldSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_toWorldSpace, 1);
        return 1;
    }

    if (strcmp(name, "toObjectSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_toObjectSpace, 1);
        return 1;
    }

    if (strcmp(name, "pointToWorldSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_pointToWorldSpace, 1);
        return 1;
    }

    if (strcmp(name, "pointToObjectSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_pointToObjectSpace, 1);
        return 1;
    }

    if (strcmp(name, "vectorToWorldSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_vectorToWorldSpace, 1);
        return 1;
    }

    if (strcmp(name, "vectorToObjectSpace") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_vectorToObjectSpace, 1);
        return 1;
    }

    if (strcmp(name, "toEulerAnglesXYZ") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_toEulerAnglesXYZ, 1);
        return 1;
    }

    if (strcmp(name, "components") == 0)
    {
        lua_pushvalue(L, -1);
        lua_pushcclosure(L, CoordinateFrameBridge::on_components, 1);
        return 1;
    }

    if (strcmp(name, "x") == 0)
    {
        lua_pushnumber(L, object.translation.x);
        return 1;
    }

    if (strcmp(name, "y") == 0)
    {
        lua_pushnumber(L, object.translation.y);
        return 1;
    }

    if (strcmp(name, "z") == 0)
    {
        lua_pushnumber(L, object.translation.z);
        return 1;
    }

    throw std::runtime_error(G3D::format("%s is not a valid member", name));
}

// 0061ca00: the generic Bridge<T>::on_newindex(T&, name, L) body ('%s cannot be assigned to'), defined inside the
// class body of lua/LuaBridge.h. It is identical for every T and ICF-folded: the ScriptContext __newindex wrappers of
// CFrame 005a9543, Vector3 005a9663, RBXScriptConnection 005a9783, ThreadRef::Node 005a9863, Color3 005a9903 and
// BrickColor 005a9a13 all call 0061ca00, which lies in this unit (after Color3 on_index 0061c8c0). Instantiating the
// Color3 wrapper emits it here; the symbol is a codegen analog of the folded body, the wrapper is not a row.
namespace RBX { namespace Lua {
template int Bridge<G3D::Color3, true>::on_newindex(lua_State*);
}}
