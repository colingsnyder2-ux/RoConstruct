// from server: 100% by king_originala
struct Parameters {
    int level;
    int method;
    int window_bits;
    int memory_level;
    int strategy;
    bool no_header;
    bool calculate_crc;
};

typedef void* (__cdecl *AllocFunction)(void*, unsigned int, unsigned int);
typedef void (__cdecl *FreeFunction)(void*, void*);

struct Stream {
    unsigned char padding[32];
    AllocFunction allocate;
    FreeFunction release;
    void* opaque;
    unsigned char trailing[12];
};

extern "C" int __stdcall initialize_deflate(
    Stream*, int, int, int, int, int, const char*, int);
extern "C" int __stdcall initialize_inflate(
    Stream*, int, const char*, int);
extern void __cdecl check_result(int);

struct S {
    Stream* stream;
    bool calculate_crc;

    void initialize(const Parameters&, bool, AllocFunction, FreeFunction, void*);
};

void S::initialize(const Parameters& parameters, bool compress,
                   AllocFunction, FreeFunction, void* opaque)
{
    calculate_crc = parameters.calculate_crc;
    Stream* const current = stream;
    current->allocate = 0;
    current->release = 0;
    current->opaque = opaque;

    int window_bits = parameters.window_bits;
    if (parameters.no_header)
        window_bits = -window_bits;

    int result;
    if (compress) {
        result = initialize_deflate(
            current, parameters.level, parameters.method, window_bits,
            parameters.memory_level, parameters.strategy, "1.2.3", 56);
    } else {
        result = initialize_inflate(current, window_bits, "1.2.3", 56);
    }
    check_result(result);
}
