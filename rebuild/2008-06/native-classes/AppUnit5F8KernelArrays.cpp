// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native G3D::Array<T*> instances of v8kernel/Kernel.cpp (inactive). Verified by
// tests/record_native_app_unit5f8.py (built with /fp:fast like the kernel-stages units; without it resize is 264/256 B).
// Explicit member instantiations only: the element types are the kernel's pointer arrays, identified by their callers
// in the Kernel.cpp unit (no other unit calls these rows):
//   Array<Connector*>  resize 005fa670 / append 005fab50: stepWorld 005fb3f0 calls both on Kernel +0x14
//                      (realTimeConnectors, native-headers/v8kernel/Kernel2008.h).
// Array<Body*> (resize 005fa770 / append 005fabc0) is not instantiated here: Body.cpp also calls it (onChildAdded
// 006147f0 / onChildRemoved 00614760), so it is not a template only this unit references.
//   Array<Point*>      resize 005fa870 / append 005fac30: newPoint 005fb260 (new 0x34, Point ctor 0064dc00) appends
//                      to KernelData +0x18; removePoint 005fb1a0 resizes it.
#include <G3D/Array.h>

namespace RBX
{
	class Point;
	class Connector;
}

template void G3D::Array<RBX::Connector*>::resize(int, bool);
template void G3D::Array<RBX::Connector*>::append(RBX::Connector* const&);
template void G3D::Array<RBX::Point*>::resize(int, bool);
template void G3D::Array<RBX::Point*>::append(RBX::Point* const&);
