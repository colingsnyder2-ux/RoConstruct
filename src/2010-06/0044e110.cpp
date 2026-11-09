// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Buffer;
struct Stream;

struct IOS {
    char reserved[0x30];
    char fill;

    __declspec(dllimport) void setstate(int, bool = false);
    __declspec(dllimport) void width(int);
};

struct Stream : virtual IOS {
    struct Sentry {
        Stream *stream;
        bool ready;
        Sentry(Stream *);
        ~Sentry();
    };
};

extern int (__thiscall *get_width)(const IOS *);
extern int (__thiscall *get_flags)(const IOS *);
extern Buffer *(__thiscall *get_buffer)(const IOS *);
extern int (__thiscall *put_character)(Buffer *, char);
extern int (__cdecl *end_of_file)();
extern bool (__cdecl *equal_int_type)(const int &, const int &);

#define STREAM_IOS \
    reinterpret_cast<IOS *>(reinterpret_cast<char *>(&stream) + \
                            (*reinterpret_cast<int **>(&stream))[1])

Stream &__cdecl insert_character(Stream &stream, char character)
{
    int state = 0;
    Stream::Sentry sentry(&stream);

    if (sentry.ready) {
        int padding = 0;
        if (get_width(STREAM_IOS) > 1)
            padding = get_width(STREAM_IOS) - 1;

        try {
            if ((get_flags(STREAM_IOS) & 0x1c0) != 0x40) {
                for (; !state && padding > 0; --padding) {
                    char fill = stream.fill;
                    int result = put_character(get_buffer(STREAM_IOS), fill);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }
            }

            if (!state) {
                {
                    int result = put_character(get_buffer(STREAM_IOS), character);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }

                for (; !state && padding > 0; --padding) {
                    char fill = STREAM_IOS->fill;
                    int result = put_character(get_buffer(STREAM_IOS), fill);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }
            }
        }
        catch (...) {
            stream.setstate(4, true);
        }
    }

    stream.width(0);
    stream.setstate(state);
    return stream;
}

#undef STREAM_IOS