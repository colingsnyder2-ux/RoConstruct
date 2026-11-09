// from server: 100% by king_originala
struct Stream {
    void write(const void* data, int bits, bool flag);
};

struct Source {
    unsigned char padding[8];
    unsigned char* data;
    unsigned int value;

    void prepare();
};

struct State {
    bool encode(Stream* stream, const void* data);
    void encodeDefault(Stream* stream, const void* data);
};

extern "C" unsigned char* __cdecl defaultData();

struct S {
    unsigned char padding[0x130];
    State state;

    bool f(Stream* stream, Source* source);
};

bool S::f(Stream* stream, Source* source)
{
    if (source) {
        source->prepare();

        struct Record {
            unsigned char* data;
            unsigned int value;
        } record;

        record.data = source->data;
        record.value = source->value;

        if (!state.encode(stream, record.data + 4))
            return false;

        stream->write(&record.value, 24, true);
        return true;
    }

    state.encodeDefault(stream, defaultData() + 4);
    return true;
}
