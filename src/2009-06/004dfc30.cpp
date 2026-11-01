// from server: 100% by EspClaude
struct Stream {
    void write(const void* data, int bits, bool flag);
};

struct Source {
    unsigned char padding[0xc];
    unsigned char* data;
    unsigned int value;
};

struct Registry {
    void prepare(Source* s);
};

struct State {
    bool encode(Stream* stream, const void* data);
    void encodeDefault(Stream* stream, const void* data);
};

extern "C" unsigned char* __cdecl defaultData();

struct S {
    unsigned char padding[0x8c];
    State state;
    unsigned char pad2[0x2ab0-0x8c-1];
    Registry* registry;

    bool f(Stream* stream, Source* source);
};

bool S::f(Stream* stream, Source* source)
{
    if (source) {
        registry->prepare(source);

        struct Record {
            unsigned char* data;
            unsigned int value;
        } record;

        record.data = source->data;
        record.value = source->value;

        if (!state.encode(stream, record.data))
            return false;

        stream->write(&record.value, 24, true);
        return true;
    }

    state.encodeDefault(stream, defaultData());
    return true;
}
