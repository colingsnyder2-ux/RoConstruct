// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /DNATIVE_CLUMP_DECL /DNATIVE_CLUMP_DECL
// INFERRED: RBX::Clump::sub_005e6240 (placeholder name for 005e6240 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

void RBX::Clump::sub_005e6240(Assembly* value)
{
	assembly = value;
	for (unsigned int i = 0; i < children.size(); ++i)
	{
		children[i]->sub_005e6240(value);
	}
}
