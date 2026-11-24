// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original at 0069ff54 is a linker-generated import thunk:
//   jmp dword ptr [0x8042e8]
// 0x8042e8 is the import-address slot holding the Ogre DLL's
// SceneNode::getAutoTrackLocalDirection. It is modelled as an external function
// pointer named after its slot address. The member forwards "this" (ecx)
// unchanged; with no stack arguments /O2 can turn the call into a tail jump
// through the slot.
namespace Ogre
{
	class Vector3
	{
	public:
		float x, y, z;
	};

	class SceneNode;
}

// INFERRED: IAT slot at 0x008042e8; __fastcall with a single pointer keeps the object in ecx.
extern "C" const Ogre::Vector3& (__fastcall* fn_008042e8)(Ogre::SceneNode* self);

namespace Ogre
{
	class SceneNode
	{
	public:
		virtual const Vector3& getAutoTrackLocalDirection(void);
	};

	const Vector3& SceneNode::getAutoTrackLocalDirection(void)
	{
		return fn_008042e8(this);
	}
}
