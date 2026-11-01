// from server: 100% by king_originala
struct Allocator {};

struct StreamBuffer {};

struct Input {
    char padding[8];
    const int* virtualBaseTable;
};

struct String {};

extern char* (__thiscall *allocate)(Allocator*, unsigned int, const void*);
extern void (__thiscall *deallocate)(Allocator*, char*, unsigned int);
extern int (__thiscall *sgetn)(StreamBuffer*, char*, int);
extern String& (__thiscall *append)(String*, const char*, unsigned int);

struct Buffer {
    char* data;
    unsigned int size;

    Buffer(unsigned int);
    ~Buffer();
};

inline Buffer::Buffer(unsigned int count)
{
    Allocator allocator;
    data = allocate(&allocator, count, 0);
    size = count;
}

inline Buffer::~Buffer()
{
    if (data) {
        Allocator allocator;
        deallocate(&allocator, data, size);
    }
}

int copy_stream(Input*& input, String*& output, int size)
{
    Buffer buffer(size);
    int total = 0;
    bool finished;

    do {
        Input* source = input;
        StreamBuffer* stream = *reinterpret_cast<StreamBuffer**>(
            reinterpret_cast<char*>(source) +
            source->virtualBaseTable[1] + 48);

        int result = sgetn(stream, buffer.data, size);
        int count = result ? result : -1;

        finished = count == -1;

        if (count != -1) {
            int written = 0;
            while (written < count) {
                int remaining = count - written;
                append(output, buffer.data + written, remaining);
                written += remaining;
            }
            total += count;
        }
    } while (!finished);

    return total;
}
