// from server: 48% by atomic.potato
struct Sub_95AD90 { void f(); };
struct Sub_7BB710 { void g(); };
struct Sub_62C250 { void f(void*); };
struct Sub_7219D0 { void f(); };
struct Sub_959DC0 { void f(void*); };
struct Sub_95AB80 { void* f(void*, void*); };
struct Sub_95B500 { char f(); };
struct Sub_95C100 { char f(void*); };
struct Sub_95C2A0 { char f(); };
struct Sub_9594F0 { char f(); };
struct Sub_95C620 { void f(void*); };
struct Sub_95CF20 { void f(); };
struct Sub_81CF90 { void f(); };
struct Sub_82BAE0 { char f(void*, void*); };
struct Sub_868720 { void f(int, int); };
struct Sub_8E2EB0 { void f(void*, void*); };

struct AdvRunDragger {
    char pad0[0x4c];
    void* m_4c;
    void* m_50;
    char pad54[0xc];
    void* m_60;
    char pad64[0x20];
    char m_84[0x24];
    void f(void*);
};

void AdvRunDragger::f(void* arg)
{
    Sub_95AD90* p = (Sub_95AD90*)this;
    p->f();

    float* src = (float*)arg;
    float* dst = (float*)((char*)this + 0x84);
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];

    Sub_7BB710* p50 = (Sub_7BB710*)m_50;
    p50->g();
    void* esi = p50;

    char sphere[0x24];
    Sub_62C250* s = (Sub_62C250*)sphere;
    s->f(esi);

    float tmp[3];
    tmp[0] = *(float*)((char*)esi + 0x24);
    tmp[1] = *(float*)((char*)esi + 0x28);
    tmp[2] = *(float*)((char*)esi + 0x2c);

    char vec[0x24];
    Sub_7219D0* v = (Sub_7219D0*)vec;
    v->f();

    void* m60 = m_60;
    char* esi2 = (char*)this + 0x60;
    int flag = 0;

    if (m60 != 0) {
        Sub_959DC0* d = (Sub_959DC0*)esi2;
        d->f(dst);
    } else {
        char out[0x24];
        Sub_95AB80* a = (Sub_95AB80*)this;
        void* r = a->f(out, vec);
        *(void**)esi2 = *(void**)r;
        *(int*)(esi2 + 4) = *(int*)((char*)r + 4);
        *(int*)(esi2 + 8) = *(int*)((char*)r + 8);
        *(float*)(esi2 + 0xc) = *(float*)((char*)r + 0xc);
        *(float*)(esi2 + 0x10) = *(float*)((char*)r + 0x10);
        *(float*)(esi2 + 0x14) = *(float*)((char*)r + 0x14);
        *(float*)(esi2 + 0x18) = *(float*)((char*)r + 0x18);
        *(float*)(esi2 + 0x1c) = *(float*)((char*)r + 0x1c);
        *(float*)(esi2 + 0x20) = *(float*)((char*)r + 0x20);
    }

    void* edi = *(void**)esi2;
    while (edi != 0) {
        int count = *(int*)(vec + 4);
        void** data = *(void***)vec;
        int i = 0;
        while (i < count) {
            if (data[i] == edi) break;
            i++;
        }
        if (i == count) {
            if (count < *(int*)(vec + 8)) {
                if (data != 0) {
                    data[count] = *(void**)esi2;
                }
                *(int*)(vec + 4) = count + 1;
            } else {
                if (esi2 >= (char*)data && esi2 < (char*)(data + count)) {
                    void* val = *(void**)esi2;
                    Sub_8E2EB0* e = (Sub_8E2EB0*)vec;
                    e->f(&val, vec);
                } else {
                    Sub_868720* g = (Sub_868720*)vec;
                    g->f(count + 1, 0);
                    void* val = *(void**)esi2;
                    void** d2 = *(void***)vec;
                    int c2 = *(int*)(vec + 4);
                    d2[c2 - 1] = val;
                }
            }
        }

        Sub_95B500* b = (Sub_95B500*)this;
        char r1 = b->f();

        char flag2 = r1;
        Sub_95C100* c = (Sub_95C100*)this;
        char r2 = c->f(&flag2);
        if (r2 != 0) goto do_update;

        {
            void* edx = m_4c;
            float f = *(float*)0xb979f4;
            void* eax = *(void**)((char*)edx + 0x170);
            eax = *(void**)((char*)eax + 0xa4);
            Sub_82BAE0* ba = (Sub_82BAE0*)eax;
            char r3 = ba->f(m_50, *(void**)&f);
            if (r3 != 0) goto do_update;
        }

        {
            Sub_95C2A0* c2 = (Sub_95C2A0*)this;
            char r4 = c2->f();
            if (r4 != 0) goto do_update;
        }

        {
            Sub_9594F0* c3 = (Sub_9594F0*)this;
            char r5 = c3->f();
            if (r5 == 0) goto skip_update;
        }

    do_update:
        {
            char out[0x24];
            Sub_95AB80* a = (Sub_95AB80*)this;
            void* r = a->f(out, vec);
            *(void**)esi2 = *(void**)r;
            *(int*)(esi2 + 4) = *(int*)((char*)r + 4);
            *(int*)(esi2 + 8) = *(int*)((char*)r + 8);
            *(float*)(esi2 + 0xc) = *(float*)((char*)r + 0xc);
            *(float*)(esi2 + 0x10) = *(float*)((char*)r + 0x10);
            *(float*)(esi2 + 0x14) = *(float*)((char*)r + 0x14);
            *(float*)(esi2 + 0x18) = *(float*)((char*)r + 0x18);
            *(float*)(esi2 + 0x1c) = *(float*)((char*)r + 0x1c);
            *(float*)(esi2 + 0x20) = *(float*)((char*)r + 0x20);
            edi = *(void**)esi2;
            if (edi != 0) continue;
        }
        break;

    skip_update:
        {
            Sub_95C620* c4 = (Sub_95C620*)this;
            c4->f(sphere);
            Sub_95CF20* c5 = (Sub_95CF20*)this;
            c5->f();
            Sub_81CF90* c6 = (Sub_81CF90*)vec;
            c6->f();
            return;
        }
    }

    Sub_95C620* c4 = (Sub_95C620*)this;
    c4->f(sphere);
    Sub_95CF20* c5 = (Sub_95CF20*)this;
    c5->f();
    Sub_81CF90* c6 = (Sub_81CF90*)vec;
    c6->f();
}
