// from server: 100% by king_originala
struct Stream;

struct String {
    char storage[28];
};

extern void (__thiscall *stringClear)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

extern void __cdecl readTag(Stream*, unsigned char*);
extern void __cdecl readString(Stream*, String*);

struct Creator {
    String strings[128];
    void read(Stream*, String*);
};

void Creator::read(Stream* stream, String* result)
{
    unsigned char tag;
    readTag(stream, &tag);

    if (tag == 0) {
        stringClear(result);
    } else if (tag & 128) {
        readString(stream, result);
        stringAssign(&strings[tag & 127], *result);
    } else {
        stringAssign(result, strings[tag]);
    }
}
