// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RenderBase::AggregateChunk::randomColors (inactive): bool 009738a0 (.bss, 0; read by the ctor 00551f30).
#include "RenderLib/AggregateChunk2008.h"

namespace RBX
{
	namespace RenderBase
	{
		bool AggregateChunk::randomColors = false;
	}
}
