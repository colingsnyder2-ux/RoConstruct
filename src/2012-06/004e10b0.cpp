// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_91aa4c87e61b5685.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <string>
namespace RBX { namespace LDraw2Lua {
struct NativeRobloxPart {
    int shape,formFactor;
    std::string size,offset;
    NativeRobloxPart(int,int,std::string,std::string);
};
}}
typedef std::vector<RBX::LDraw2Lua::NativeRobloxPart> PV;
template void PV::_Insert_n(PV::const_iterator, PV::size_type, const RBX::LDraw2Lua::NativeRobloxPart&);
