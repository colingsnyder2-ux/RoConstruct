// from server: 100% by colin
struct Allocator {
    char unused;
};

struct Buffer {
    char unused;
};

struct InputBase {
    char unused;
};

struct Input {
    int* table;
};

struct Output {
    int reserved;
    Buffer buffer;
};

extern Allocator* (__thiscall *prepare)(Allocator*, unsigned int, const void*);
extern char* (__thiscall *allocate)(Allocator*);
extern void (__thiscall *deallocate)(Allocator*);
extern Buffer* (__thiscall *rdbuf)(const InputBase*);
extern int (__thiscall *sgetn)(Buffer*, char*, int);
extern int (__thiscall *sputn)(Buffer*, const char*, int);

struct Temporary {
    char* data;
    unsigned int size;

    Temporary(unsigned int);
    ~Temporary();
};

Temporary::Temporary(unsigned int n)
{
    Allocator allocator;
    data = allocate(prepare(&allocator, n, 0));
    size = n;
}

Temporary::~Temporary()
{
    if (data) {
        Allocator allocator;
        deallocate(prepare(&allocator,
                           reinterpret_cast<unsigned int>(data),
                           reinterpret_cast<const void*>(size)));
    }
}

int func_00451210(Input** input, Output** output, unsigned int size)
{
    Temporary temporary(size);
    int total = 0;
    int count = 0;
    Output** destination = output;
    bool done;

    do {
        Input* stream = *input;
        int received = sgetn(
            rdbuf(reinterpret_cast<InputBase*>(
                reinterpret_cast<char*>(stream) + stream->table[1])),
            temporary.data, size);

        count = received ? received : -1;
        done = count == -1;

        if (count != -1) {
            int written = 0;
            while (written < count) {
                Output* currentDestination = *destination;
                written += sputn(&currentDestination->buffer,
                                 temporary.data + written,
                                 count - written);
            }
            total += count;
        }
    } while (!done);

    return total;
}
