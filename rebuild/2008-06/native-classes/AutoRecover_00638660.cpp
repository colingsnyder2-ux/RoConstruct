// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "script/Script.h"
#include "v8datamodel/Value.h"

extern "C" const unsigned int g_0084960c[];
extern "C" const unsigned int g_00849600[];
extern "C" const unsigned int g_008495f8[];
extern "C" const unsigned int g_008495f0[];
extern "C" const unsigned int g_008495e0[];
extern "C" const unsigned int g_008495d0[];
extern "C" const unsigned int g_008495c0[];
extern "C" const unsigned int g_008495b0[];
extern "C" const unsigned int g_008495a0[];
extern "C" const unsigned int g_00849590[];
extern "C" const float g_009611c0;
extern "C" const float g_009611c4;
extern "C" const float g_009611c8;

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
            p[0x00 / 4] = reinterpret_cast<unsigned int>(g_0084960c);
            p[0x10 / 4] = reinterpret_cast<unsigned int>(g_00849600);
            p[0x14 / 4] = reinterpret_cast<unsigned int>(g_008495f8);
            p[0x20 / 4] = reinterpret_cast<unsigned int>(g_008495f0);
            p[0x24 / 4] = reinterpret_cast<unsigned int>(g_008495e0);
            p[0x44 / 4] = reinterpret_cast<unsigned int>(g_008495d0);
            p[0x64 / 4] = reinterpret_cast<unsigned int>(g_008495c0);
            p[0x84 / 4] = reinterpret_cast<unsigned int>(g_008495b0);
            p[0xa4 / 4] = reinterpret_cast<unsigned int>(g_008495a0);
            p[0xc4 / 4] = reinterpret_cast<unsigned int>(g_00849590);

            x = g_009611c0;
            y = g_009611c4;
            z = g_009611c8;

            std::string name("Value");
            RBX::Instance::setName(name);
        }
    };
}

extern "C" RBX::Color3Value* __fastcall fn_00638660(
    RBX::Color3Value* self, int unusedEdx)
{
    // INFERRED: Direct construction removes the allocation null branch.
    // MSVC 2008 byte match remains unverified.
    Color3ValueLayout* value = reinterpret_cast<Color3ValueLayout*>(self);
    value->Color3ValueLayout::Color3ValueLayout();
    return self;
}
