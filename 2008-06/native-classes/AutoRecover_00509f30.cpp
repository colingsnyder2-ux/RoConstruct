// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdio.h>
#include <time.h>
#include <string>

// INFERRED: object layout; only the FILE* at +4 is used by this function.
struct LogFile {
    int unknown0;
    FILE* file;
};

extern "C" int __fastcall fn_00509f30(void* self, int unusedEdx);

extern "C" int __fastcall fn_00509f30(void* self, int unusedEdx)
{
    LogFile* me = (LogFile*)self;
    __time64_t t;
    if (_time64(&t) == (__time64_t)-1) {
        std::string msg("[Error getting time]");
        if (me->file != 0) {
            // INFERRED: the disassembly calls the function's own address here.
            fn_00509f30(me, 0);
            // INFERRED: the format string at 0x827ab4 is assumed to be "%s".
            fprintf(me->file, "%s", msg.c_str());
        }
    }
    // INFERRED: return value is not used by the code; eax is left as is.
    return 0;
}
