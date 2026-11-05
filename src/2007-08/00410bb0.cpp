// from server: 35% by colin
// roc 2007-08 00410bb0  unit: CopyVerb  size: 398 bytes

struct VerbContainer;

struct Verb {
    void* vtable;
    int refCount;
    char pad_08[4];
    void* begin;
    void* end;
    void* cap;
};

struct String {
    char pad[0x1c];
};

struct Elem {
    char pad_00[0x1c];
    void* p1c;
    void* p20;
    char pad_24[0x24];
};

extern "C" {
    void __stdcall sub_40f800();
    void __stdcall sub_410800();
    void __stdcall sub_4108b0();
    void __stdcall sub_62fc62(void*);
    void __stdcall sub_630a1e();
    void __stdcall sub_77e690();
    void __stdcall sub_77e69c();
    void __stdcall sub_77e6ac();
    void __stdcall sub_77e6d8();
}

struct CopyVerb {
    void func(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};

void CopyVerb::func(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    Verb* self = (Verb*)this;
    char buf[0x30];
    int flag = 0;
    sub_4108b0();
    sub_77e69c();
    *(int*)(buf + 0x1c) = a;
    *(int*)(buf + 0x20) = b;
    sub_410800();
    flag = 1;
    while (true) {
        void* vt = self->vtable;
        int (*fn)(void*) = *(int(**)(void*))vt;
        self->refCount++;
        if (!fn(self)) break;
        Elem* e = (Elem*)self->begin;
        if (e > (Elem*)self->cap) sub_77e6d8();
        if (e < (Elem*)self->cap) sub_77e6d8();
        void* p20 = e->p20;
        void* p1c = e->p1c;
        if (p20) {
            sub_40f800();
            sub_62fc62(p20);
        }
        if (p1c) {
            sub_40f800();
            sub_62fc62(p1c);
        }
        Elem* dst = (Elem*)self->cap;
        Elem* src = e + 1;
        if (src != dst) {
            int off = (char*)src - (char*)e;
            Elem* s = e;
            do {
                sub_77e690();
                *(void**)((char*)s + 0x1c) = *(void**)((char*)src + 0x1c);
                *(void**)((char*)s + 0x20) = *(void**)((char*)src + 0x20);
                src = (Elem*)((char*)src + 0x24);
                s = (Elem*)((char*)s + 0x24);
            } while (src != dst);
        }
        Elem* last = (Elem*)self->cap;
        Elem* it = last - 1;
        while (it != last) {
            sub_77e6ac();
            it = (Elem*)((char*)it + 0x24);
        }
        self->cap = (char*)self->cap - 0x24;
        self->refCount--;
    }
    sub_77e6ac();
    sub_77e6ac();
    sub_630a1e();
}
