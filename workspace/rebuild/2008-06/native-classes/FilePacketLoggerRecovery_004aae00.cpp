// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdio.h>
#include <Replicator.h>

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

char* FilePacketLogger::UserIDTOString(unsigned char id)
{
	switch (id)
	{
	case 0x4b: return "ID_SET_GLOBALS";
	case 0x4c: return "ID_REQUEST_CHARACTER";
	case 0x4e: return "ID_DATA";
	case 0x4f: return "ID_REQUEST_MARKER";
	case 0x50: return "ID_PHYSICS";
	case 0x51: return "ID_CHAT_ALL";
	case 0x52: return "ID_REPORT_ABUSE";
	default: return "Unknown";
	}
}
