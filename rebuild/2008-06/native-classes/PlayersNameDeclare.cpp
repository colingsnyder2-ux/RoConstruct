// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Name registration of the Network::Players class name (2008-06 client).
// 00411420 ??$doDeclare@$1?sPlayers@Network@RBX@@3PADA@Name@RBX@@CAABV01@XZ (101 B) and its EH handler 007bd6ae.
// Identity: the registry decorated name at 00411420; the body tests guard 0096cbd8, pushes -1 and 0093784c
// (Network::sPlayers, "Players") to Name::declare(const char*, int) 00553f90 and caches the result in 0096cbd4.
// It sits in the CChatPrompt object range (00411360 CChatPrompt::GetThisClass, 00411490 doGetClassIndex<Players>):
// CChatPrompt::bind's DataModel::create<Network::Players>() reaches Name::declare<sPlayers>() there. The COMDAT is
// emitted here by explicit instantiation, the way DataModelClassName.cpp emits doDeclare<sDataModel>.
// Flags: the AppUnit410ChatPrompt.cpp line (same CChatPrompt object).
#include "Network/Players.h"

template void RBX::Name::callDoDeclare<RBX::Network::sPlayers>();
