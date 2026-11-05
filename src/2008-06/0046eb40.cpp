// from server: 100% by king_originala
struct String;

extern void (__thiscall *destroyString)(String *);
extern const char *(__thiscall *stringCStr)(const String *);
extern unsigned int (__thiscall *stringFindFirstOf)(
    const String *, const char *, unsigned int);
extern String *(__thiscall *stringSubstr)(
    const String *, String *, unsigned int, unsigned int);

struct String {
    char storage[28];
    String(const String *source, unsigned int start, unsigned int count);
    ~String();
};

inline String::String(
    const String *source, unsigned int start, unsigned int count)
{
    stringSubstr(source, this, start, count);
}

inline String::~String()
{
    destroyString(this);
}

struct Stream {};

extern Stream &__cdecl writeText(Stream &, const char *);
extern Stream &(__thiscall *writeInteger)(Stream *, int);

struct Part {
    int shape;
    int formFactor;
    String size;
};

struct S {
    char padding[112];
    String description;

    bool write(Stream &stream, const Part *part);
};

bool S::write(Stream &stream, const Part *part)
{
    writeText(
        writeText(
            writeText(stream, (const char *)0x0081cbc8),
            (const char *)0x0081caac),
        (const char *)0x0081cbcc);

    writeText(
        writeText(stream, (const char *)0x0081ca90),
        (const char *)0x0081cbcc);

    String name(
        &description, 0,
        stringFindFirstOf(&description, (const char *)0x0081ca8c, 0));

    writeText(
        writeText(
            writeText(
                writeText(stream, (const char *)0x0081ca78),
                stringCStr(&name)),
            (const char *)0x0081ca88),
        (const char *)0x0081cbcc);

    int shape = part->shape;
    writeText(
        writeInteger(
            &writeText(stream, (const char *)0x0081ca68), shape),
        (const char *)0x0081cbcc);

    if (shape != 0 && shape != 2) {
        int formFactor = part->formFactor;
        writeText(
            writeInteger(
                &writeText(stream, (const char *)0x0081ca54),
                formFactor),
            (const char *)0x0081cbcc);
    } else {
        writeText(
            writeText(stream, (const char *)0x0081ca30),
            (const char *)0x0081cbcc);
    }

    writeText(
        writeText(
            writeText(
                writeText(stream, (const char *)0x0081ca14),
                stringCStr(&part->size)),
            (const char *)0x00812e5c),
        (const char *)0x0081cbcc);

    return true;
}
