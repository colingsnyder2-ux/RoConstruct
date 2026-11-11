// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include "util/LDrawEntities.h"

namespace RBX { namespace LDraw2Lua {
void LDrawModel::writeLua(std::ostream& out) const
{
    if (items.size() > 0) {
        out << "-- " << "Get the current workspace" << "\n";
        out << "local w = game:service(\"Workspace\")" << "\n";
        out << "\n";
        out << "-- " << "Create a new model" << "\n";
        out << "m = Instance.new(\"Model\")" << "\n";
        out << "m.Name = \"" << name.c_str() << "\"" << "\n";
        out << "m.Parent = w" << "\n";
        out << "\n";
        size_t count = items.size();
        for (size_t i = 0; i < count; ++i) items.at(i)->writeLua(out, "m");
    }
}
} }

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::LDraw2Lua::LDrawItem *,std::allocator<RBX::LDraw2Lua::LDrawItem *> >;
template class std::vector<RBX::LDraw2Lua::LDrawItem *,std::allocator<RBX::LDraw2Lua::LDrawItem *> >;
