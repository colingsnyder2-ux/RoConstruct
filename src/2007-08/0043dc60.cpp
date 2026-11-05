// from server: 31% by colin
struct ContentId {
    char pad[0x24];
};

struct SoundId {
    char pad[0x24];
    SoundId(const ContentId& id, int a, int b, int c, char d);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl ContentId_ctor(void*, const char*);

SoundId::SoundId(const ContentId& id, int a, int b, int c, char d)
{
    char* p = (char*)operator_new(0x24);
    if (p) {
        *(const ContentId**)p = &id;
        *(int*)(p + 4) = a;
        *(int*)(p + 8) = b;
        *(int*)(p + 0xc) = c;
        ContentId_ctor(p + 0x10, 0);
        p[0x20] = d;
        p[0x21] = 0;
    }
}
