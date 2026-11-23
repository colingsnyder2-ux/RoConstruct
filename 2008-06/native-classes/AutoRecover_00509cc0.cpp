// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdio.h>
#include <time.h>

// INFERRED: class layout from the constructor: vptr, FILE* at +4,
// std::string at +8, int at +0x24.
struct LogFile
{
    FILE*       file;
    std::string name;
    int         level;

    LogFile(const std::string& fileName, int lvl)
        : file(0), name(), level(0)
    {
        level = lvl;
        name = fileName;
        file = fopen(name.c_str(), "w"); // INFERRED: mode string
        if (file)
        {
            setvbuf(file, 0, _IONBF, 0);
            fprintf(file, "Roblox Log\n"); // INFERRED: header text
            __time64_t t;
            _time64(&t);
            fprintf(file, "%s", _ctime64(&t)); // INFERRED: format
            fflush(file);
        }
    }
    virtual ~LogFile() {}
};

// INFERRED: global singleton pointer at 0x9735d4
static LogFile* g_logFile;

extern "C" LogFile* __fastcall fn_00509cc0(LogFile* self, int unusedEdx, const std::string& fileName, int level)
{
    new (self) LogFile(fileName, level);
    if (!g_logFile)
        g_logFile = self;
    return self;
}
