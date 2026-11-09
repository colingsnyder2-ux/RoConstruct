// from server: 100% by atomic.potato
struct Inner {
    char pad0[4];
    unsigned int field4;
    int field8;
    char padC[0x28];
    void* field34;
    unsigned int field38;
    unsigned int field3C;
};

struct Outer {
    char pad0[0x10];
    Inner* field10;
};

extern "C" void __cdecl sub_9361D0(Outer* self, int n);
extern "C" void* __cdecl sub_936F40(Outer* self);
extern "C" void* __cdecl sub_936F60(Outer* self, void* p, unsigned int oldsize, unsigned int newsize);

void __cdecl sub_932D90(Outer* self)
{
    Inner* s = self->field10;
    int c = s->field8;
    int q = c / 4;
    if (s->field4 < (unsigned int)q && c > 0x40)
    {
        sub_9361D0(self, c / 2);
    }
    unsigned int a = s->field3C;
    if (a > 0x40)
    {
        unsigned int half = a >> 1;
        unsigned int nc = half + 1;
        if (nc <= 0xFFFFFFFD)
        {
            void* p = sub_936F60(self, s->field34, a, half);
            s->field3C = half;
            s->field34 = p;
        }
        else
        {
            void* p = sub_936F40(self);
            s->field3C = half;
            s->field34 = p;
        }
    }
}
