// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// RBX::Network::Peer::~Peer() 004ac830 (rakPeer->DetachPlugin(this); __ehhandler 007c8420) is exact in
// NetworkClientServer2008Peer.cpp. The duplicate was removed so the body is kept only once; this unit previously
// failed to compile (no flags line: ReliabilityLayer.h could not find DS_LinkedList.h).
