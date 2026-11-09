// from server: 100% by colin
// roc 2008-06 004aae00  unit: FilePacketLogger  size: 116 bytes

extern const char ID_CHAT_ALL[];
extern const char ID_DATA[];
extern const char ID_PHYSICS[];
extern const char ID_REPORT_ABUSE[];
extern const char ID_REQUEST_CHARACTER[];
extern const char ID_REQUEST_MARKER[];
extern const char ID_SET_GLOBALS[];
extern const char Unknown[];

struct FilePacketLogger {
    const char* GetNameFromId(unsigned char id);
};

const char* FilePacketLogger::GetNameFromId(unsigned char id)
{
    switch (id)
    {
    case 0x4b: return ID_CHAT_ALL;
    case 0x4c: return ID_DATA;
    case 0x4d: return ID_PHYSICS;
    case 0x4e: return ID_REPORT_ABUSE;
    case 0x4f: return ID_REQUEST_CHARACTER;
    case 0x50: return ID_REQUEST_MARKER;
    case 0x51: return ID_SET_GLOBALS;
    case 0x52: return ID_CHAT_ALL;
    default:   return Unknown;
    }
}
