// from server: 100% by colin
// from server: 84% by king_originala
// Manually recovered: fputs must be __declspec(dllimport) so MSVC caches the IAT
// pointer in edi and reuses it across both calls (target uses `mov edi,[imp]; call edi`).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" __declspec(dllimport) int __cdecl fputs(const char *, void *);
extern const char lineEnding[];

struct FilePacketLogger {
    char padding[0x20c];
    void *file;
    void write(const char *text);
};

void FilePacketLogger::write(const char *text)
{
    if (file) {
        fputs(text, file);
        fputs(lineEnding, file);
    }
}