// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX /I{headers} /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network
// 2008-06 native FilePacketLogger unit (inactive): 004aae00..004ab8ec.
// Class declared in native-headers/Replicator.h (FilePacketLogger : public PacketLogger, FILE* packetLogFile).
// PacketLogger is the vendor RakNet 3.0 class: RakPeerInterface* rakPeer (+4), bool printId/printAcks (+8/+9),
// char prefix[256] (+0xa), char suffix[256] (+0x10a) -> sizeof(PacketLogger) == 0x20c, which is exactly where
// the binary reads packetLogFile ([esi+0x20c] in 004aab... , 004aaea0, 004ab7f0).
// The packaged workspace has no PacketLogger.h/PluginInterface.h/BitStream.h/RakNetStatistics.h/Streaming.h,
// so the authentic vendor tree (tools/rbxgs/Client/Network/raknet30/Source) and the network source dir are
// pinned as extra include roots on the native-flags line. No field or layout is invented: every offset above
// is read out of the binary (SetPrefix/SetSuffix strncpy +0xa/+0x10a of 0xff bytes, the ctor's
// mov [edi+0x20c],0, and the two 256-byte arrays implied by [this+0x109]/[this+0x209] terminators).
#include "Replicator.h"

void FilePacketLogger::OnAttach(RakPeerInterface* peer)
{
	PacketLogger::OnAttach(peer);
	LogHeader();
}

void FilePacketLogger::WriteLog(const char* str)
{
	if (packetLogFile)
	{
		fputs(str, packetLogFile);
		fputs("\n", packetLogFile);
	}
}

FilePacketLogger::~FilePacketLogger()
{
	if (packetLogFile)
		fclose(packetLogFile);
}
