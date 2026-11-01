// from server: 67% by colin
struct PropBase {
    char pad[0xe8];
    void* field_e8;
};

struct ArgType {
    char pad[0xc];
    void* field_c;
};

struct ArgHolder {
    char pad[4];
    void* field_4;
};

extern "C" void* __stdcall sub_53e7a0(void*);
extern "C" void* __fastcall sub_4432c0(void*);

struct S {
    void* f(void* arg);
};

void* S::f(void* arg)
{
    PropBase* self = (PropBase*)this;
    void* p = self->field_e8;
    void* r;
    if (p != 0) {
        ArgType* a = (ArgType*)arg;
        void* q = a->field_c;
        void* v = *(void**)((char*)q + 4);
        r = sub_53e7a0((char*)v + 4);
    } else {
        r = 0;
    }
    if (r != 0) {
        void* s = sub_4432c0(r);
        if (s != 0) {
            ArgHolder* h = (ArgHolder*)arg;
            void* t = (char*)h->field_4 + 4;
            return sub_53e7a0(t);
        }
    }
    return 0;
}
