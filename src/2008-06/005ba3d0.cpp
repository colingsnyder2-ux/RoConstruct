// from server: 100% by colin
// from server: 67% by colin
struct Vector3 {
    float x, y, z;
};

struct Frame {
    unsigned char padding[0x24];
    Vector3 position;
};

struct Body {
    unsigned char padding[0xc4];
    Vector3 value;
    void updatePV(int);
};

extern "C" int __stdcall sub_69fbdc(int, unsigned char *);

struct SoundChannel {
    unsigned char padding[0xc];
    int field_c;

    void sub_5ba3d0(int, int, int);
};

void SoundChannel::sub_5ba3d0(int, int, int)
{
    unsigned char local;
    Body *body = (Body *)((unsigned char *)this - 0x130);
    int v = *(int*)((char*)body + 0x13c);
    if (v != 0) {
        if (sub_69fbdc(v, &local) == 0x24)
            return;
        if (local != 0)
            return;
        body->updatePV(field_c);
    }
}


