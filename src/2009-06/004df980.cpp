// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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
    void encode(Stream* stream, const void* data);
};

extern "C" unsigned char* __cdecl defaultData();

struct S {
    unsigned char padding[0x8c];
    State state;
    unsigned char pad2[0x2ab0-0x8c-1];
    Registry* registry;

    void f(Stream* stream, Source* source);
};

void S::f(Stream* stream, Source* source)
{
    if (source) {
        registry->prepare(source);

        struct Record {
            unsigned char* data;
            unsigned int value;
        } record;

        record.data = source->data;
        record.value = source->value;

        state.encode(stream, record.data);
        stream->write(&record.value, 24, true);
        return;
    }

    state.encode(stream, defaultData());
}
