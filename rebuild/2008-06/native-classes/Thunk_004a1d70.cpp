// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /I{headers}/../native-classes
// 004a1d70: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "NetworkClientServer2008Server.cpp"
// INFERRED: 004a1d70 is a 5-byte jump to RBX::FactoryProduct<class RBX::Network::Server,class RBX::Network::Peer,RBX::Network::sServer>::~FactoryProduct<class RBX::Network::Server,class RBX::Network::Peer,RBX::Network::sServer>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_004a1d70 : RBX::FactoryProduct<class RBX::Network::Server,class RBX::Network::Peer,RBX::Network::sServer> { ~Thunk_004a1d70(); };
Thunk_004a1d70::~Thunk_004a1d70() {}
