// from server: 100% by king_originala
struct Context
{
    int f(int);
};

struct Stream;

extern "C" Stream * __cdecl append(Stream *, const char *);
extern Stream * (__thiscall *writeInteger)(Stream *, int);

struct Command
{
    int reserved0;
    Context *context;
    int reserved8;
    int value;

    bool f(Stream *);
};

bool Command::f(Stream *out)
{
    append(
        writeInteger(
            append(out, (const char *)0x81cae4),
            context->f(value)),
        (const char *)0x81cb08);
    append(out, (const char *)0x81cbcc);
    return true;
}
