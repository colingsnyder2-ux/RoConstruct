// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits;
template<class T, class Traits> struct basic_streambuf {
    unsigned char padding[60];
    unsigned char eof;
};
}

extern int (__thiscall *sgetn)(
    std::basic_streambuf<char, std::char_traits<char> > *, char *, int);

extern int finish_mode;
extern int normal_mode;
extern int stream_end;
extern "C" void __cdecl check_status(int);

struct Buffer {
    char *data;
    int size;
    char *next;
    char *end;
};

struct State {
    void *state;
    unsigned char padding[16];
    Buffer buffer;
    unsigned int flags;

    void before(char **, char *, char **, char *);
    int inflate(int);
    void after(char **, char **, int);
};

struct S {
    State *state;
    int f(std::basic_streambuf<char, std::char_traits<char> > *, char *, int);
};

int S::f(std::basic_streambuf<char, std::char_traits<char> > *source,
         char *destination, int length)
{
    if (!(state->flags & 1)) {
        state->flags |= 1;
        Buffer &buffer = state->buffer;
        buffer.next = buffer.data;
        buffer.end = buffer.data;
    }

    int mode = ((~(state->flags >> 2)) & 1) | 4;
    char *output = destination;
    char *output_end = destination + length;
    char **end = &state->buffer.end;
    char **next = &state->buffer.next;

    for (;;) {
        bool finishing = mode == 4;

        if (*next != *end || finishing) {
            char *input = *next;
            State *current = state;
            current->before(&input, *end, &output, output_end);
            int result = current->inflate(finishing ? finish_mode : normal_mode);
            current->after(&input, &output, 1);
            check_status(result);
            bool done = result == stream_end;
            *next = input;

            if (done) {
                int count = output - destination;
                return count ? count : -1;
            }
        }

        if (mode == 6 && *next == *end)
            break;
        if (output == output_end)
            break;

        if (mode == 5) {
            int size = state->buffer.size;
            char *data = state->buffer.data;
            int result = sgetn(source, data, size);
            int count = result ? result : (source->eof ? -1 : 0);

            if (count == -1) {
                mode = 4;
                state->flags |= mode;
            } else {
                Buffer &buffer = state->buffer;
                buffer.next = buffer.data;
                buffer.end = buffer.data + count;
                mode = 5 + (count != state->buffer.size);
            }
        }
    }

    return output - destination;
}
