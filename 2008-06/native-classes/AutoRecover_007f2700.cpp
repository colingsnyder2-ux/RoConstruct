// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)
struct HuffmanEncodingTreeNode;
namespace DataStructures {
template <class T> struct CircularLinkedList { CircularLinkedList(); };
}
extern DataStructures::CircularLinkedList<HuffmanEncodingTreeNode*> g_00973928;
extern "C" int __cdecl atexit(void (__cdecl *fn)(void));
extern "C" void __cdecl fn_007fc670(void);

// INFERRED: static-initializer for a global CircularLinkedList instance
extern "C" void fn_007f2700(void)
{
    g_00973928.CircularLinkedList<HuffmanEncodingTreeNode*>::CircularLinkedList();
    atexit(fn_007fc670);
}
