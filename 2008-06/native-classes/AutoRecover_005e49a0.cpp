// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/JointInstance.h"

// INFERRED: allocator (called with 0x120) reached through a fixed-name extern.
extern "C" void* fn_006a0920(int size);

namespace RBX
{
	// INFERRED: Joints2008.h redefines RBX::Joint, so it is not included. GlueJoint is declared
	// locally with its real constructor symbol (??0GlueJoint@RBX@@QAE@XZ, 00646b60), left external.
	// The constructor is a real C++ function that may throw, so `new GlueJoint()` gets the
	// state -1 -> 0 -> -1 EH frame seen in the original.
	class GlueJoint
	{
	public:
		GlueJoint();
		static void* operator new(size_t)
		{
			return fn_006a0920(0x120);
		}
		static void operator delete(void*)
		{
		}
	};

	// 005e49a0: vendor JointInstance.cpp default constructor.
	// INFERRED: base ctor (005e4010) is DescribedCreatable<Glue, JointInstance, sGlue>(Joint*).
	Glue::Glue()
		: DescribedCreatable<Glue, JointInstance, sGlue>(reinterpret_cast<Joint*>(new GlueJoint()))
	{
	}
}
