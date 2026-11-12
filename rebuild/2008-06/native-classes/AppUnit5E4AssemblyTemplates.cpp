// 2008-06 Roblox-instantiated templates of the v8world/Assembly.cpp (Clump) unit 005e5f00..005e729f, application range
// 005e4000..005e8000 (inactive native unit). /fp:fast. Verified by tests/record_native_app_unit5e4.py.
//  * std::sort over MotorJoint* with a bool (*)(const MotorJoint*, const MotorJoint*) comparator (VS2008 RTM <algorithm>):
//    the helpers _Push_heap 005e61e0, _Med3 005e66b0, _Adjust_heap 005e6720, _Median 005e6830, _Make_heap 005e68e0,
//    _Insertion_sort1 005e6920, _Unguarded_partition 005e69d0, _Sort_heap 005e6ca0 and _Sort 005e6e90; std::sort itself
//    is inlined into its only caller 005e6f70 (push_back, then sort), so the explicit instantiation is of std::_Sort.
//  * G3D::Array<Edge*>::resize 005e6540 and append 005e6640 (G3D 6.09 Array.h; EdgeList::insertEdge 005e8990 and the
//    Assembly rows 005e6ba0 / 005e6c70 call them).
#undef _RELEASEASSERT
#include <algorithm>
#include <G3D/Array.h>

namespace RBX
{
	class Edge;
	class MotorJoint;
}

typedef bool (*MotorJointLess)(const RBX::MotorJoint*, const RBX::MotorJoint*);

template void std::_Sort<RBX::MotorJoint**, int, MotorJointLess>(RBX::MotorJoint**, RBX::MotorJoint**, int, MotorJointLess);

template void G3D::Array<RBX::Edge*>::resize(int, bool);
template void G3D::Array<RBX::Edge*>::append(RBX::Edge* const&);
