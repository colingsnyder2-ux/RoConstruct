// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>

namespace RBX { namespace LDraw2Lua { class LDrawItem; } }

// INFERRED: no class header was provided, so Resource is declared locally.
// The vector<LDrawItem*> sits at +0xd8 (its end pointer at +0xe8), and the
// disassembly is a checked-iterator erase(begin(), end()), i.e. clear().
class Resource {
public:
    void release();
private:
    char pad[0xd8];
    std::vector<RBX::LDraw2Lua::LDrawItem*> drawItems;
};

void Resource::release()
{
    drawItems.erase(drawItems.begin(), drawItems.end());
}
