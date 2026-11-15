// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/StandardVerbs.h"

namespace RBX {
EngineStatsCommand::EngineStatsCommand(RBX::DataModel* dm)
    : Verb(dm ? reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(dm) + 0x1c8) : 0,
           std::string("EngineStats")),
      dataModel(dm)
{
}
}
