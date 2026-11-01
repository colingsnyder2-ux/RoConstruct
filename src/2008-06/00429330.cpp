// from server: 100% by king_originala
extern "C" void __cdecl prepareLog(int, int);
extern "C" void __stdcall writeLog(int, int, int, int, const char*, int);
extern const char logFormat[];

void __cdecl logMessage(int context, int value, int argument)
{
    prepareLog(1, value);
    writeLog(context, value, 0, 0, logFormat, argument);
}
