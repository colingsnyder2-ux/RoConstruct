// native-flags: /O1 /GS- /MD /hotpatch /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/src/atl/atls /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// 2008-06 native AtlWinModuleRecovery (inactive): upstream tools/libs/mfc-9.0-rtm/atlmfc/src/atl/atls/atlwinmodule.cpp, verbatim (atls.lib member).
// Emits the header-inline ATL::CAtlWinModule constructor (007a6196) and destructor (007a61be) from atlbase.h. Module instance: _AtlWinModule. 
#include "StdAfx.H"

#pragma warning( disable: 4073 )  // initializers put in library initialization area

namespace ATL
{
#pragma init_seg( lib )
CAtlWinModule _AtlWinModule;

};  // namespace ATL
