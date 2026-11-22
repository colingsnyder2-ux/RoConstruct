// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// RBX::Network::Peer::Peer() 004b4640 (and its __ehhandler 007c888e) is exact in NetworkClientServer2008Peer.cpp,
// with the same body this unit held (profilePacketsThread(new CodeProfiler("Packets Thread")), rakPeer.reset(new
// ProfiledRakPeer(...)), rakPeer->AttachPlugin(this)). The duplicate was removed so the body is kept only once;
// this unit previously failed to compile (no flags line: ReliabilityLayer.h could not find DS_LinkedList.h).
