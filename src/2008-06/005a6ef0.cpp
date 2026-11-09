// from server: 100% by king_originala
struct LocalTime {
    unsigned short year, month, dayOfWeek, day;
    unsigned short hour, minute, second, milliseconds;
};

struct Stream {};

extern "C" void (__stdcall *GetLocalTime)(LocalTime*);
extern "C" int (__cdecl *sprintf)(char*, const char*, ...);
extern "C" Stream& (__thiscall *flush)(Stream*);

Stream& __cdecl appendText(Stream*, const char*);
Stream& __cdecl appendCharacter(Stream*, char);

extern const char* prefix0;
extern const char* prefix1;
extern const char* prefix2;

struct Workspace {
    void log(int level, const char* text);
};

void Workspace::log(int level, const char* text)
{
    LocalTime time;
    char buffer[256];
    Stream* stream = reinterpret_cast<Stream*>(
        reinterpret_cast<char*>(this) + 0x40);

    GetLocalTime(&time);
    sprintf(buffer, "%02u:%02u:%02u.%03u ",
            time.hour, time.minute, time.second, time.milliseconds);
    appendText(stream, buffer);
    flush(stream);

    switch (level) {
    case 0:
        appendText(stream, prefix0);
        break;
    case 1:
        appendText(stream, prefix1);
        break;
    case 2:
        appendText(stream, prefix2);
        break;
    }

    appendText(stream, text);
    appendCharacter(stream, '\n');
    flush(stream);
}
