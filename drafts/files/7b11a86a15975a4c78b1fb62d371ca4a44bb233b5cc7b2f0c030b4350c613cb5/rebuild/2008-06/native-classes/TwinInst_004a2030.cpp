// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 004a2030: explicit instantiation of the class the body at 004a2030 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "Network/Server2008.h"
#include "reflection/reflection.h"
#include "reflection/Metadata.h"
template std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<int >::GetSet> RBX::Reflection::PropDescriptor<class RBX::Network::Server,int>::getset<int (__thiscall RBX::Network::Server::*)(void)const>(int (__thiscall RBX::Network::Server::*)(void)const, int);
