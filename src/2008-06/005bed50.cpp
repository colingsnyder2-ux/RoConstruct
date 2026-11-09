// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_color_kernel_native_family_d08788802cbb1f87.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "v8tree/Property.cpp"
bool (*roc_color_parser)(const std::string&, G3D::Color3&) = &RBX::StringConverter<G3D::Color3>::convertToValue;
bool (*roc_vector_parser)(const std::string&, G3D::Vector3&) = &RBX::StringConverter<G3D::Vector3>::convertToValue;

#undef _RELEASEASSERT
#include <v8world/Contact.h>
#include <util/Math.h>
namespace RBX {
	Block* BlockBlockContact::block(int i)
	{
		return rbx_static_cast<Block*>(this->getPrimitive(i)->getGeometry());
	}

	int BlockBlockContact::intersectRectQuad(G3D::Vector2& planeRect, G3D::Vector2 (&otherQuad)[4])
	{
		bool quadCrossRect[4][4];

		bool quadIn[4] = {true, true, true, true};

		int foundCounter = 0;

		for (int i = 3; i >= 0; i--)
		{
			if (otherQuad[i].y <= planeRect.y)
			{
				quadCrossRect[0][i] = true;
			}
			else
			{
				quadCrossRect[0][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].x >= -planeRect.x)
			{
				quadCrossRect[1][i] = true;
			}
			else
			{
				quadCrossRect[1][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].y >= -planeRect.y)
			{
				quadCrossRect[2][i] = true;
			}
			else
			{
				quadCrossRect[2][i] = false;
				quadIn[i] = false;
			}

			if (otherQuad[i].x <= planeRect.x)
			{
				quadCrossRect[3][i] = true;
			}
			else
			{
				quadCrossRect[3][i] = false;
				quadIn[i] = false;
			}
		}

		for (int i = 3; i >= 0; i--)
		{
			if (quadIn[i])
			{
				loadGeoPairPointPlane((*(int*)((char*)this+0x70)), (*(int*)((char*)this+0x6c)), i, (*(NormalId*)((char*)this+0x78)), (*(NormalId*)((char*)this+0x74)));
				foundCounter++;
			}
		}

		if (foundCounter == 4)
			return foundCounter;
		else
		{
			bool rectCrossQuad[4][4];
			G3D::Vector2 rect[4];
			rect[0] = G3D::Vector2(planeRect.x, planeRect.y);
			rect[1] = G3D::Vector2(-planeRect.x, planeRect.y);
			rect[2] = G3D::Vector2(-planeRect.x, -planeRect.y);
			rect[3] = G3D::Vector2(planeRect.x, -planeRect.y);

			bool rectIn[4] = {true, true, true, true};

			for (int i = 3; i >= 0; i--)
			{
				G3D::Vector2& current = otherQuad[i];
				G3D::Vector2& currentO = otherQuad[(i + 3) % 4];
				for (int j = 0; j < 4; j++)
				{
					G3D::Vector2 math1 = rect[j] - current;
					G3D::Vector2 math2 = currentO - current;

					if ((math2.x * math1.y) - (math2.y * math1.x) >= 0.0f)
					{
						rectCrossQuad[i][j] = true;
					}
					else
					{
						rectCrossQuad[i][j] = false;
						rectIn[j] = false;
					}
				}
			}

			int wasZero = foundCounter == 0;

			for (int i = 0; i < 4; i++)
			{
				if (rectIn[i])
				{
					loadGeoPairPointPlane((*(int*)((char*)this+0x6c)), (*(int*)((char*)this+0x70)), i, (*(NormalId*)((char*)this+0x74)), (*(NormalId*)((char*)this+0x78)));
					foundCounter++;
				}
			}

			if (wasZero && foundCounter == 4)
				return foundCounter;
			else
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 3; j >= 0; j--)
					{
						if (quadCrossRect[i][j] != quadCrossRect[i][(j + 3) % 4] && rectCrossQuad[j][i] != rectCrossQuad[j][(i + 1) % 4])
						{

							loadGeoPairEdgeEdgePlane((*(int*)((char*)this+0x70)), (*(int*)((char*)this+0x6c)), block((*(int*)((char*)this+0x70)))->faceVertexToEdge((*(NormalId*)((char*)this+0x78)), (j+3)%4), block((*(int*)((char*)this+0x6c)))->faceVertexToEdge((*(NormalId*)((char*)this+0x74)), i));
							foundCounter++;
						}
					}
				}
				RBXASSERT(foundCounter != 1 && foundCounter <= 8);
				return foundCounter;
			}
		}
	}


}

#include <script/ScriptContext.h>
#include <util/standardout.h>
#include <lua/lua.hpp>
#include <lauxlib.h>
#include <cstring>
namespace RBX { namespace Lua { const char* safe_lua_tostring(lua_State*, int); } }
using namespace RBX;
void ScriptContext::executeInNewThread(Security::Identities identity, const char* script, const char* name, PushArgumentsClosure pushArguments, ReadResultsClosure readResults)
{
    openState();

    lua_State* L;
    lua_State* newThread;

    if (identity == Security::CmdLine)
    {
        if ((*(Lua::ThreadRef*)((char*)this+0x13c)).empty())
        {
            {
                Lua::ThreadRef threadRef(lua_newthread((*(lua_State**)((char*)this+0x138))));
                (*(Lua::ThreadRef*)((char*)this+0x13c)) = threadRef;
            }

            if ((*(Lua::ThreadRef*)((char*)this+0x13c)).empty())
                throw std::runtime_error("Unable to create trusted sandbox thread");

            sandboxThread((*(Lua::ThreadRef*)((char*)this+0x13c)).thread());
            setThreadIdentity((*(Lua::ThreadRef*)((char*)this+0x13c)).thread(), Security::CmdLine);
            lua_pop((*(lua_State**)((char*)this+0x138)), 1);
        }

        L = (*(Lua::ThreadRef*)((char*)this+0x13c)).thread();
        newThread = lua_newthread(L);
    }
    else
    {
        L = (*(lua_State**)((char*)this+0x138));
        newThread = lua_newthread(L);
        sandboxThread(newThread);
        setThreadIdentity(newThread, identity);
    }

    if (!newThread)
    {
        StandardOut::singleton()->print(MESSAGE_ERROR, "ScriptContext::execute: Unable to create a new thread");
        throw std::runtime_error("Unable to create a new thread");
    }

    Lua::ScopedPopper popper(L, 1);

    std::string sName("=");

    if (name)
        sName += name;
    else
        sName += "Script";

    if (luaL_loadbuffer(newThread, script, strlen(script), sName.c_str()))
    {
        std::string err = Lua::safe_lua_tostring(newThread, -1);
        lua_pop(newThread, 1);

        StandardOut::singleton()->print(MESSAGE_ERROR, err.c_str());
        throw std::runtime_error(err);
    }

    resume(newThread, pushArguments, readResults);
}


#undef _RELEASEASSERT
#include <v8world/RotateJoint.h>
#include <v8world/Primitive.h>
#include <v8world/World.h>
#include <v8kernel/Body.h>
#include <util/Math.h>
namespace RBX {
class RotatePrimitiveApi {
public:
    Body* getBody() { return *(Body**)((char*)this+0xa0); }
};
class RotateBodyApi {
private:
    void updatePV() const;
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const {
        updatePV();
        return *(const G3D::CoordinateFrame*)((const char*)this+0x94);
    }
};
	void RotateJoint::putInKernel(Kernel* _kernel)
	{
		MultiJoint::putInKernel(_kernel);

		Body* b0 = ((RotatePrimitiveApi*)getAxlePrim())->getBody();
		Body* b1 = ((RotatePrimitiveApi*)getHolePrim())->getBody();

		G3D::CoordinateFrame cAxleWorld = ((RotateBodyApi*)b0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame cHoleWorld = ((RotateBodyApi*)b1)->getCoordinateFrame() * jointCoord1;

		G3D::Vector3 vAxleWorld = cAxleWorld.rotation.getColumn(2);
		G3D::Vector3 vHoleWorld = cHoleWorld.rotation.getColumn(2);

		for (int i = 0; i < 2; i++)
		{
			float multiplier = i == 0 ? -1.0f : 1.0f;

			G3D::Vector3 pAxleWorldPos = vAxleWorld * multiplier + cAxleWorld.translation;
			G3D::Vector3 pHoleWorldPos = vHoleWorld * multiplier + cHoleWorld.translation;

			Point* pAxleWorld = getKernel()->newPoint(b0, pAxleWorldPos);
			Point* pHoleWorld = getKernel()->newPoint(b1, pHoleWorldPos);

			PointToPointBreakConnector* connector = new PointToPointBreakConnector(pAxleWorld, pHoleWorld, getJointK(), Math::inf());
			addToMultiJoint(pAxleWorld, pHoleWorld, connector);
		}

		if (getJointType() == ROTATE_P_JOINT || getJointType() == ROTATE_V_JOINT)
		{
			G3D::Vector3 center0 = cAxleWorld.translation;
			G3D::Vector3 perp = cAxleWorld.rotation.getColumn(0);
			G3D::Vector3 marker0 = perp * 10.0f + center0;

			Point* pMarker0 = getKernel()->newPoint(b0, marker0);
			Point* pMarker1 = getKernel()->newPoint(b1, marker0);

			RBXASSERT(!rotateConnector);
			RotateConnector* connector = new RotateConnector(getPoint(0), getPoint(2), pMarker0, pMarker1, getJointK(), getTorqueArmLength());
			rotateConnector = connector;
			addToMultiJoint(pMarker0, pMarker1, connector);
		}
	}


}
