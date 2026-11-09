// from server: 100% by EspClaude
// roc 2007-08 004a63a0  FilePacketLogger scalar deleting destructor
#include <stdio.h>

class PluginInterface { public: virtual ~PluginInterface(); };
class PacketLogger : public PluginInterface {
public:
    PacketLogger();
    ~PacketLogger();
    char data[0x208];
};
class FilePacketLogger : public PacketLogger {
    FILE* file;
public:
    FilePacketLogger();
    ~FilePacketLogger() { if (file) fclose(file); }
};

FilePacketLogger::FilePacketLogger() : file(0) {}
