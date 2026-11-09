// from server: 46% by colin
struct ArgStream {
    int capacity;
    int pad;
    int bitPos;
    unsigned char* buffer;
    bool readBit(bool def);
    void readBits(int count, void* out, int bitCount);
};

struct Vector3 {
    float x, y, z;
};

struct Descriptor {
    char pad[0x24];
    float a, b, c;
};

extern "C" {
    void __cdecl sub_5aae70(int, void*);
    void __cdecl sub_5aa9e0(void*, void*);
    void __cdecl sub_5ac1f0(void*);
}

extern double g_795b48;
extern double g_795b68;

ArgStream* readVector(ArgStream* s, Descriptor* d);

ArgStream* readVector(ArgStream* s, Descriptor* d)
{
    bool hasX = s->readBit(true);
    if (hasX) {
        int v1 = 0, v2 = 0, v3 = 0;
        s->readBits(0xb, &v1, 1);
        s->readBits(0xb, &v2, 1);
        s->readBits(0xb, &v3, 1);
        if (v1 & 0x400) v1 |= 0xfffffc00;
        if (v2 & 0x400) v2 |= 0xfffffc00;
        short sx = (short)v1;
        unsigned short ux = *(unsigned short*)&v3;
        short sy = (short)v2;
        d->a = (float)sx * (float)g_795b48;
        d->b = (float)ux / (float)g_795b68;
        d->c = (float)sy * (float)g_795b48;
    } else {
        s->readBits(0x20, &d->a, 1);
        s->readBits(0x20, &d->b, 1);
        s->readBits(0x20, &d->c, 1);
    }

    bool hasY = s->readBit(true);
    if (hasY) {
        int v = 0;
        s->readBits(6, &v, 1);
        sub_5aae70(v, d);
        return s;
    } else {
        float f1, f2, f3, f4;
        s->readBits(0x20, &f1, 1);
        s->readBits(0x20, &f2, 1);
        s->readBits(0x20, &f3, 1);
        s->readBits(0x20, &f4, 1);
        Vector3 tmp;
        tmp.x = f1;
        tmp.y = f2;
        tmp.z = f3;
        sub_5aa9e0(d, &tmp);
        sub_5ac1f0(d);
        return s;
    }
}
