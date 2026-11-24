// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the 110-byte body at 0049eef0 is only the Peer base constructor call followed by
// vtable-pointer stores. The real ScriptContext constructor (with member initialisers and an EH
// frame) cannot produce it, so the header is not included and a minimal layout-free class is
// defined with the same mangled name.

// Unknown vtable globals, referenced by address only.
extern "C" char g_00822e44[];
extern "C" char g_00822e38[];
extern "C" char g_00822e30[];
extern "C" char g_00822e28[];
extern "C" char g_00822e18[];
extern "C" char g_00822e08[];
extern "C" char g_00822df8[];
extern "C" char g_00822de8[];
extern "C" char g_00822dd8[];
extern "C" char g_00822dc8[];
extern "C" char g_00822d98[];
extern "C" char g_00822d8c[];

namespace RBX
{
    namespace Network
    {
        // ??0Peer@Network@RBX@@IAE@XZ : protected constructor, defined elsewhere.
        class Peer
        {
        protected:
            Peer();
        };
    }

    class ScriptContext : public Network::Peer
    {
    public:
        ScriptContext();
    };

    static inline void setVptr(void* self, unsigned offset, const void* value)
    {
        *reinterpret_cast<const void**>(reinterpret_cast<char*>(self) + offset) = value;
    }

    ScriptContext::ScriptContext()
    {
        setVptr(this, 0x00, g_00822e44);
        setVptr(this, 0x10, g_00822e38);
        setVptr(this, 0x14, g_00822e30);
        setVptr(this, 0x20, g_00822e28);
        setVptr(this, 0x24, g_00822e18);
        setVptr(this, 0x44, g_00822e08);
        setVptr(this, 0x64, g_00822df8);
        setVptr(this, 0x84, g_00822de8);
        setVptr(this, 0xa4, g_00822dd8);
        setVptr(this, 0xc4, g_00822dc8);
        setVptr(this, 0x130, g_00822d98);
        setVptr(this, 0x134, g_00822d8c);
    }
}
