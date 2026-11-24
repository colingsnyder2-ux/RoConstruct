// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fe76 is a one-instruction import thunk: jmp dword ptr [0x804230], i.e. the IAT slot for
// rgmain!?resetToInitialState@Node@Ogre@@UAEXXZ. It has no body of its own.
// INFERRED: the import is modelled as a dllimport thiscall member of a stand-in type, so the
// compiler emits a tail call through the IAT (jmp [iat]). The real import symbol is the Ogre
// one named above, which cannot be both defined and imported in the same file.

namespace Ogre
{
	// INFERRED: stand-in for the imported rgmain symbol, same thiscall shape (this in ecx, no args).
	struct NodeImportStub
	{
		__declspec(dllimport) void resetToInitialState();
	};

	class Node
	{
	public:
		virtual void resetToInitialState();
	};

	void Node::resetToInitialState()
	{
		reinterpret_cast<NodeImportStub*>(this)->resetToInitialState();
	}
}
