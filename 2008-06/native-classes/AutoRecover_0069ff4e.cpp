// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// The original at 0x0069ff4e is a bare import thunk: jmp dword ptr [IAT slot].
// INFERRED: forward to a __thiscall dllimport member with the same `this`
// (ecx untouched), so /O2 emits a tail-call jmp through the IAT with no extra
// setup.

namespace Ogre
{
	class Vector3;

	// INFERRED: stand-in for the OgreMain export; only used to produce the
	// indirect jump through the import slot.
	class SceneNodeImport
	{
	public:
		__declspec(dllimport) const Vector3& getAutoTrackOffsetImpl(void);
	};

	class SceneNode
	{
	public:
		virtual const Vector3& getAutoTrackOffset(void);
	};
}

const Ogre::Vector3& Ogre::SceneNode::getAutoTrackOffset(void)
{
	return reinterpret_cast<SceneNodeImport*>(this)->getAutoTrackOffsetImpl();
}
