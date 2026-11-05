// from server: 21% by atomic.potato
struct Slot {
    void* m_vt;
    float m_val;
};

struct SlotArray {
    Slot** m_begin;
    Slot** m_end;
    Slot** m_cap;
};

struct Signal {
    SlotArray m_slots;
    void addSlot(Slot* s);
    void operator()(float a, float b, float c, float d);
};

extern "C" void __stdcall sub_4ab810(void*);
extern "C" void* __cdecl sub_7a79a0(unsigned int);
extern "C" void __stdcall sub_4ab4b0(void*);
extern "C" void __stdcall sub_9ea90c(void);

void Signal::operator()(float a, float b, float c, float d)
{
    SlotArray tmp;
    sub_4ab810(&tmp);
    tmp.m_begin = tmp.m_end = tmp.m_cap = 0;

    Slot* s0 = (Slot*)sub_7a79a0(8);
    if (s0) {
        s0->m_vt = (void*)0xa046c8;
        s0->m_val = a;
    } else {
        s0 = 0;
    }
    {
        Slot* old = tmp.m_begin[0];
        tmp.m_begin[0] = s0;
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    Slot* s1 = (Slot*)sub_7a79a0(8);
    if (s1) {
        s1->m_vt = (void*)0xa046c8;
        s1->m_val = b;
    } else {
        s1 = 0;
    }
    {
        Slot* old = tmp.m_begin[1];
        tmp.m_begin[1] = s1;
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    Slot* s2 = (Slot*)sub_7a79a0(8);
    if (s2) {
        s2->m_vt = (void*)0xa046c8;
        s2->m_val = c;
    } else {
        s2 = 0;
    }
    {
        Slot* old = tmp.m_begin[2];
        tmp.m_begin[2] = s2;
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    Slot* s3 = (Slot*)sub_7a79a0(8);
    if (s3) {
        s3->m_vt = (void*)0xa046c8;
        s3->m_val = d;
    } else {
        s3 = 0;
    }
    {
        Slot* old = tmp.m_begin[3];
        tmp.m_begin[3] = s3;
        if (old) {
            void** vt = *(void***)old;
            ((void (__stdcall*)(void*, int))vt[0])(old, 1);
        }
    }

    void** vt = *(void***)this;
    ((void (__stdcall*)(void*, SlotArray*))vt[1])(this, &tmp);

    sub_4ab4b0(&tmp);
}
