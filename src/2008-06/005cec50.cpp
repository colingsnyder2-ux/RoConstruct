// from server: 100% by king_originala
struct String {
    char data[0x1c];
};

struct Value {
    String text;
    int extra;
};

struct Reference {
    virtual ~Reference();
    volatile long count;
    void release();
};

extern bool __cdecl different(const Value*, const Value*);

extern "C" {
    extern String& (__thiscall *assignString)(String*, const String*);
    extern long (__stdcall *InterlockedDecrement)(volatile long*);
}

struct DxUserInput {
    char padding[4];
    Value value;
    Reference* reference;

    void setValue(int unused, const Value& source);
};

void DxUserInput::setValue(int unused, const Value& source)
{
    const Value* input = &source;
    Value* destination = &value;

    if (different(destination, input)) {
        assignString(&destination->text, &input->text);
        destination->extra = input->extra;

        if (reference) {
            if (InterlockedDecrement(&reference->count) == 0) {
                reference->release();
                delete reference;
            }
            reference = 0;
        }
    }
}
