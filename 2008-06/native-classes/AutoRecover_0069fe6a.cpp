// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fe6a is a linker import thunk (jmp [0x804228]) to rgmain.dll's
// ?getListener@Node@Ogre@@UBEPAVListener@12@XZ. It is not Roblox source code.
// INFERRED: a tail call through a dllimport function with the same register
// convention (ecx = this) compiles to `jmp dword ptr [__imp_...]`, which
// reproduces the thunk bytes.
// INFERRED: the layout below is a placeholder, not the Ogre 1.4.5 layout.
namespace Ogre
{
	class Node
	{
	public:
		class Listener;
		virtual Listener* getListener(void) const;
	protected:
		Listener* mListener;
	};

	extern "C" __declspec(dllimport) Node::Listener* __fastcall rgmain_Node_getListener(const Node* self);

	Node::Listener* Node::getListener(void) const
	{
		return rgmain_Node_getListener(this);
	}
}
