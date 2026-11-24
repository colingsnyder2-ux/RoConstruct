// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0056be10 is an identical-COMDAT-folded function-local-static getter, not a real Shape::axes body.
// It is labelled Shape::axes only because of the folded symbol name. The bytes build a static
// RBX::GuidRegistryMutex (ctor 00563070) with an atexit dtor and return its address.

namespace G3D
{
	class CoordinateFrame;

	class Shape
	{
	public:
		virtual CoordinateFrame& axes();
	};
}

namespace RBX
{
	// INFERRED: opaque layout; the ctor and dtor live elsewhere (ctor 00563070, dtor stub 007fd1a0)
	class GuidRegistryMutex
	{
	public:
		GuidRegistryMutex();
		~GuidRegistryMutex();
	};
}

G3D::CoordinateFrame& G3D::Shape::axes()
{
	static RBX::GuidRegistryMutex mutex;
	return *reinterpret_cast<G3D::CoordinateFrame*>(&mutex);
}
