// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly reads two stack arguments and ends in a plain `ret`,
// so this is cdecl (void* dest, const void* src), not the __thiscall the header
// claims. It looks like a placement copy-construct of a list/bind node.
// INFERRED: the node layout is a dword, 4 bytes of padding, then a
// boost::bind storage2 member at +8, plus one trailing dword at storage+0x40.

struct NodeStorage {
    char bytes[0x44];
};

struct BindNode {
    int first;
    int pad;
    NodeStorage storage;
};

// storage2 copy constructor (thiscall: ecx = this, one stack arg)
extern "C" void __fastcall fn_005962d0(NodeStorage* self, int unusedEdx, const NodeStorage* src);

extern "C" void fn_00596a50(BindNode* dest, const BindNode* src)
{
    if (dest) {
        dest->first = src->first;
        fn_005962d0(&dest->storage, 0, &src->storage);
        *(int*)(dest->storage.bytes + 0x40) = *(const int*)(src->storage.bytes + 0x40);
    }
}
