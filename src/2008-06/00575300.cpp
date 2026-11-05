// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" int (__cdecl *sprintf)(char *, const char *, ...);

struct String
{
    unsigned char allocator;
    union
    {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String(const char *);
    __declspec(dllimport) ~String();
};

String __cdecl formatTime(double);
__declspec(noinline) static String __cdecl formatRate(double);

__declspec(noinline) static String __cdecl formatRate(double seconds)
{
    if (seconds > 0.0)
    {
        String text = formatTime(seconds);
        char buffer[256];
        int percent = (int)(3000.0 * seconds);
        const char *value = text.storage.pointer;
        if (text.capacity < 16)
            value = text.storage.buffer;
        sprintf(buffer, "%i %%  %s (%.3gfps)",
                percent, value, 1.0 / seconds);
        return String(buffer);
    }
    return formatTime(seconds);
}

String formatRateCaller(double seconds) { return formatRate(seconds); }
