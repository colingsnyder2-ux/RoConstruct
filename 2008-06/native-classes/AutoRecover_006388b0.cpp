// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "script/Script.h"
#include "v8datamodel/Value.h"

extern "C" const unsigned int g_0084978c[];
extern "C" const unsigned int g_00849780[];
extern "C" const unsigned int g_00849778[];
extern "C" const unsigned int g_00849770[];
extern "C" const unsigned int g_00849760[];
extern "C" const unsigned int g_00849750[];
extern "C" const unsigned int g_00849740[];
extern "C" const unsigned int g_00849730[];
extern "C" const unsigned int g_00849720[];
extern "C" const unsigned int g_00849710[];
extern "C" const float g_0097d320;
extern "C" const float g_0097d324;
extern "C" const float g_0097d328;

namespace
{
    typedef RBX::DescribedCreatable<RBX::Script, RBX::Instance,
        RBX::sScript> ValueConstructorBase;

    // INFERRED: The three floats begin at +0x130.
    struct __declspec(novtable) Color3ValueLayout : ValueConstructorBase
    {
        float x;
        float y;
        float z;

        __forceinline Color3ValueLayout()
        {
            unsigned int* p = reinterpret_cast<unsigned int*>(this);
            p[0x00 / 4] = reinterpret_cast<unsigned int>(g_0084978c);
            p[0x10 / 4] = reinterpret_cast<unsigned int>(g_00849780);
            p[0x14 / 4] = reinterpret_cast<unsigned int>(g_00849778);
            p[0x20 / 4] = reinterpret_cast<unsigned int>(g_00849770);
            p[0x24 / 4] = reinterpret_cast<unsigned int>(g_00849760);
            p[0x44 / 4] = reinterpret_cast<unsigned int>(g_00849750);
            p[0x64 / 4] = reinterpret_cast<unsigned int>(g_00849740);
            p[0x84 / 4] = reinterpret_cast<unsigned int>(g_00849730);
            p[0xa4 / 4] = reinterpret_cast<unsigned int>(g_00849720);
            p[0xc4 / 4] = reinterpret_cast<unsigned int>(g_00849710);

            x = g_0097d320;
            y = g_0097d324;
            z = g_0097d328;

            std::string name("Value");
            RBX::Instance::setName(name);
        }
    };
}

extern "C" RBX::Color3Value* __fastcall fn_006388b0(
    RBX::Color3Value* self, int unusedEdx)
{
    // INFERRED: Direct construction removes the allocation null branch.
    // MSVC 2008 byte match remains unverified.
    Color3ValueLayout* value = reinterpret_cast<Color3ValueLayout*>(self);
    value->Color3ValueLayout::Color3ValueLayout();
    return self;
}
