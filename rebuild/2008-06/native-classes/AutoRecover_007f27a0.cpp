// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("g", off)
struct HuffmanEncodingTreeNode;
namespace DataStructures {
template <class T>
class CircularLinkedList {
public:
    CircularLinkedList();
    char pad[12];
};
}

// INFERRED: tag type for an in-place construction helper (no matching delete -> no EH cleanup)
struct InPlaceTag {};
inline void* operator new(unsigned int, InPlaceTag* p) { return p; }

// INFERRED: global list instance at 0x009738c4
extern DataStructures::CircularLinkedList<HuffmanEncodingTreeNode*> g_009738c4;
extern "C" void __cdecl fn_007fc6c0(void);
extern "C" int __cdecl atexit(void (__cdecl *)(void));

// INFERRED: static-initializer; the global is constructed in place by a direct call
extern "C" void fn_007f27a0(void)
{
    new ((InPlaceTag*)&g_009738c4) DataStructures::CircularLinkedList<HuffmanEncodingTreeNode*>();
    atexit(fn_007fc6c0);
}
