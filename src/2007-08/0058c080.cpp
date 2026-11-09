// from server: 54% by colin
struct Stats_Item {
    void formatValue(double, const char*, ...);
    void setValue(double, const char*);
};

struct SoundServiceStatsItem : Stats_Item {
    char pad[0x110];
    void* service;
    unsigned int currentalloced;
    unsigned int maxalloced;
    unsigned int numSounds;
    unsigned int numUnusedSounds;
    int channelsPlaying;
    char pad2[0x120 - 0x11c];
    void update();
};

extern "C" {
    int __stdcall FMOD_Memory_GetStats(int* a, int* b);
    void __stdcall sub_596ae0();
    int __stdcall sub_62fc50(void*, void*);
    void __stdcall sub_588bd0(void*, void*, void*);
    void __stdcall sub_77e698(void*);
    void __stdcall sub_77e690(void*, void*);
    void __stdcall sub_77e6ac(void*);
}

void SoundServiceStatsItem::update()
{
    if (*(int*)((char*)service + 0xec) != 0) {
        int v = *(int*)((char*)service + 0xf0);
        double d = (double)v;
        formatValue(d, "fmod %08x", v);
        int a, b;
        if (FMOD_Memory_GetStats(&a, &b) == 0) {
            currentalloced = (unsigned int)a;
            maxalloced = (unsigned int)b;
        }
        *(int*)((char*)this + 0x11c) = 0;
        *(int*)((char*)this + 0x120) = 0;
        sub_588bd0((char*)service + 0x120, (char*)this + 0x11c, (char*)this + 0x120);
        sub_588bd0((char*)service + 0x12c, (char*)this + 0x11c, (char*)this + 0x120);
    } else {
        setValue(0.0, "-disabled-");
    }
}
