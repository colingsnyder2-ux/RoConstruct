// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <vector>

namespace Ogre
{
    class Light;

    class Node
    {
    public:
        virtual const std::vector<Light*>& getLights() const;
    };

    // INFERRED: This is a thunk/import that jumps to the actual implementation
    // The disassembly shows jmp dword ptr [0x80414c] which is an import table entry
    extern "C" const std::vector<Light*>& (__thiscall *g_0080414c)(const Node*);

    const std::vector<Light*>& Node::getLights() const
    {
        // INFERRED: Call through the import table pointer
        return g_0080414c(this);
    }
}
