// from server: 26% by colin
struct VerbContainer;

struct Verb {
    char pad[0x0c];
    VerbContainer* container;
    char pad2[0x188 - 0x10];
    void* field188;
};

struct TToolVerb {
    char pad[0x0c];
    VerbContainer* container;
    char pad2[0x188 - 0x10];
    void* field188;

    void* constructToolVerb();
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct VerbCtor {
    void ctor(void* arg);
};

void* TToolVerb::constructToolVerb()
{
    void* mem = operator_new(0x78);
    if (mem != 0) {
        ((VerbCtor*)mem)->ctor(this->field188);
    }
    return mem;
}
