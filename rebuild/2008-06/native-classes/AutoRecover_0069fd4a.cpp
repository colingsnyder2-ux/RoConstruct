// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: This function is a thunk that jumps through a function pointer table.
// The disassembly shows: jmp dword ptr [0x804168]
// This is a typical pattern for virtual function implementations that are redirected
// through a table, possibly for DLL boundary crossing or dynamic dispatch.

extern "C" void (__thiscall *g_00804168)(const void*);

namespace Ogre
{
    class Node
    {
    protected:
        virtual void _updateFromParent() const;
    };
}

void Ogre::Node::_updateFromParent() const
{
    // INFERRED: Call through the function pointer stored in the global table
    g_00804168(this);
}
