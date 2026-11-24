// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069fcfc is a one-instruction thunk, "jmp dword ptr [0x80446c]", for the Ogre DLL's
// ?getWorldTransforms@Node@Ogre@@UBEXPAVMatrix4@2@@Z.
// INFERRED: no Ogre headers are available, so Node and Matrix4 are forward-declared minimally here.
// INFERRED: the thunk is recreated as an optimized tail call. The forwarded call has the same this
// and the same single stack argument, so /O2 should emit "jmp dword ptr [__imp_...]".
// INFERRED: the imported callee is declared on a separate stand-in class (NodeImport) so it has a
// different decorated name from the function being defined. The IAT slot is a masked relocation,
// so only the jmp-through-IAT shape matters for matching.
// This has not been compiled, so the jmp output is unverified.
namespace Ogre
{
	class Matrix4;

	class NodeImport
	{
	public:
		__declspec(dllimport) void getWorldTransformsImported(Matrix4* xform) const;
	};

	class Node
	{
	public:
		virtual void getWorldTransforms(Matrix4* xform) const;
	};

	void Node::getWorldTransforms(Matrix4* xform) const
	{
		reinterpret_cast<const NodeImport*>(this)->getWorldTransformsImported(xform);
	}
}
