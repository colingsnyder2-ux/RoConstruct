// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00496c20: translated from its byte-exact mined analog against the 2007 rbxgs donor headers (donor_translate.py); byte-proved standalone
#include <string>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<void> Shared;

namespace RBX {
    void __cdecl makeGuidString(std::string& s);
}

struct S {
    std::string first;
    std::string second;
    Shared owner;
    Shared empty;
    S(const char* text, Shared value);
};

S::S(const char* text, Shared value)
    : first(), second(text), owner(value), empty()
{
    RBX::makeGuidString(first);
}

