// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_contact_execute_native_family_ec6db4ca48e835bd.cpp

// Candidate translation unit (score above; library headers required).
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

