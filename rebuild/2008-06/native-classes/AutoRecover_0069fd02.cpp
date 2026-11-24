// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fd02 is an import thunk: a single "jmp dword ptr [0x804468]" to the imported
// Ogre::Node::getWorldOrientation. There is no body to recover.
// INFERRED: no Ogre headers are available, so Ogre::Node and Ogre::Quaternion are declared minimally here.
// INFERRED: the previous draft's __fastcall pointer forced "xor edx, edx". To keep ecx (this) untouched and
// emit no extra instructions, the thunk is modelled as a tail call to a __thiscall dllimport member.

namespace Ogre
{
	class Quaternion;

	// INFERRED: stand-in for the imported __thiscall member (IAT slot 0x804468). The real import is
	// Ogre::Node::getWorldOrientation, which cannot be declared dllimport inside the class it is defined in.
	class NodeImport
	{
	public:
		__declspec(dllimport) const Quaternion& getWorldOrientation() const;
	};

	class Node
	{
	public:
		virtual const Quaternion& getWorldOrientation() const;
	};
}

const Ogre::Quaternion& Ogre::Node::getWorldOrientation() const
{
	return reinterpret_cast<const Ogre::NodeImport*>(this)->getWorldOrientation();
}
