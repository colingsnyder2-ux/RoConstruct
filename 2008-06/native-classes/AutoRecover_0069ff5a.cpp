// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069ff5a is a linker import thunk (jmp [0x8042ec]) for the
// rgmain export Ogre::SceneNode::setVisible(bool,bool); it has no body of its
// own. No class header was supplied, so this is a minimal local declaration.
// The forwarder below is a tail call through the import slot and is intended
// to compile to the same single jmp.

namespace Ogre
{
	class SceneNode
	{
	public:
		virtual void setVisible(bool visible, bool cascade);
	};

	// INFERRED: import address slot of rgmain's exported setVisible.
	// The slot name is local because the real __imp_ symbol cannot be named here.
	extern "C" void (__thiscall * const rgmain_imp_SceneNode_setVisible)(SceneNode* self, bool visible, bool cascade);

	void SceneNode::setVisible(bool visible, bool cascade)
	{
		rgmain_imp_SceneNode_setVisible(this, visible, cascade);
	}
}
