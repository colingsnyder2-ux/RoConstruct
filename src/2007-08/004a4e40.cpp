// from server: 100% by colin
struct FilePacketLogger {
    void Log(const char* text);
    char pad[0x20c];
    void* file;
};

extern "C" int (__cdecl *fputs)(const char* text, void* file);

void FilePacketLogger::Log(const char* text)
{
    if (file)
        fputs(text, file);
}
