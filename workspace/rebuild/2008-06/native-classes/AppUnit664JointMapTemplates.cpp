// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native (inactive): the std::multimap<Primitive*, Joint*> lower_bound row 00667fd0 of the JointStage unit.
// Evidence: the map's insert / _Insert rows 00668210 / 00668010 carry the evidence names of
// _Tree<_Tmap_traits<Primitive*, Joint*, less<Primitive*>, allocator<...>, true>> (the multimap of
// native v8world/JointStage2008.h, JointStage +0x30); 00667fd0 is called only by JointStage::removeFromMap 00668280
// (call site 006682a1), walks the tree from _Myhead (+0x18 of the tree) comparing the key at node +0xc and the
// _Isnil byte at +0x15, and returns the iterator by hidden pointer (`ret 8`). Explicit member instantiation only;
// Primitive and Joint are used as pointers, so forward declarations suffice.
#include <map>

namespace RBX
{
	class Primitive;
	class Joint;
}

typedef std::multimap<RBX::Primitive*, RBX::Joint*> NativeAppUnit664JointMap;
typedef NativeAppUnit664JointMap::_Mybase NativeAppUnit664JointTree;

template NativeAppUnit664JointTree::iterator NativeAppUnit664JointTree::lower_bound(RBX::Primitive* const&);
