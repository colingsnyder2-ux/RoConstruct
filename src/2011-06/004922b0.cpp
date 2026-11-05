// from server: 48% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    void __stdcall sub_a40360(void*, void*);
    void __stdcall sub_a42db4(void*);
    void __stdcall sub_a404bc(void*);
    void __stdcall sub_a404a8(void*, void*);
    bool __stdcall sub_a404a4(void*, void*, void*);
    void __stdcall sub_a404b4(void*, const char*);
    bool __stdcall sub_a4050c(void*, const char*);
    const char* __stdcall sub_a404cc(void*);
    void __stdcall sub_a404d0(void*);
    void __stdcall sub_a42dc8(void*);
    void __stdcall sub_a42e08(void*);
    void __stdcall sub_a42334(void*, int, ...);
    bool __stdcall sub_a40434(void*, const char*);
}

struct Str {
    char pad[0x1c];
    Str();
    ~Str();
    Str& operator=(const Str&);
    Str& operator=(const char*);
    const char* c_str() const;
};

struct Vec {
    char pad[4];
    void* begin;
    void* end;
};

struct Obj {
    char pad[0x94];
    Vec* vec;
};

struct Inner {
    char pad[0x18];
    virtual int get();
};

struct Elem {
    Inner* inner;
    char pad[4];
};

struct CSelectionCaption {
    char pad0[0x20];
    void* field20;
    char pad1[0x160 - 0x24];
    void* field160;
    char pad2[0x194 - 0x164];
    void* field194;
    void* field198;
    void* field19c;
    char pad3[0x1a8 - 0x1a0];
    char field1a8[8];
    void method(int, int);
};

void CSelectionCaption::method(int a, int b)
{
    sub_a40360(field1a8, 0);
    if (field20 == 0)
        return;

    Str s1;
    Str s2;
    sub_a42db4(&s1);
    sub_a404bc(&s2);

    if (field19c != 0) {
        void* p = field194;
        void* q = field198;
        if (q) {
            _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
        }
        sub_a404a8(&s1, &p);
        sub_a404a8(&s2, &p);

        Obj* o = (Obj*)field19c;
        Vec* v = o->vec;
        Elem* it = (Elem*)v->begin;
        Elem* end = (Elem*)v->end;

        int found = 0;
        if (it != end) {
            Inner* first = it->inner;
            found = first->get();
            it = (Elem*)((char*)it + 8);
            while (it != end) {
                Inner* cur = it->inner;
                if (sub_a404a4(&s2, (char*)cur + 0x50, &s1)) {
                    sub_a404b4(&s1, "Authoring");
                    if (found == 0)
                        break;
                }
                if (cur->get() != found) {
                    found = 0;
                    if (sub_a40434(&s1, "Authoring"))
                        break;
                }
                it = (Elem*)((char*)it + 8);
            }
        }

        if (found != 0) {
            if (sub_a4050c(&s1, "Authoring")) {
                Vec* v2 = ((Obj*)field19c)->vec;
                int n = (int)(((char*)v2->end - (char*)v2->begin) >> 3);
                if (n > 1) {
                    const char* p1 = sub_a404cc((char*)found + 4);
                    const char* p2 = sub_a404cc((void*)n);
                    sub_a42334(&s1, 0xb5, p1, p2);
                } else {
                    const char* p1 = sub_a404cc((char*)found + 4);
                    const char* p2 = sub_a404cc(&s1);
                    sub_a42334(&s1, 0xb4, p1, p2);
                }
            } else {
                Vec* v2 = ((Obj*)field19c)->vec;
                int n = (int)(((char*)v2->end - (char*)v2->begin) >> 3);
                const char* p1 = sub_a404cc((char*)found + 4);
                const char* p2 = sub_a404cc((void*)n);
                sub_a42334(&s1, 0xb6, p1, p2);
            }
        } else {
            Vec* v2 = ((Obj*)field19c)->vec;
            int n = (int)(((char*)v2->end - (char*)v2->begin) >> 3);
            sub_a42334(&s1, 0xb7, n);
        }
    }

    sub_a404d0(&s2);
    sub_a42e08(&s1);

    void* vt = *(void**)this;
    sub_a42dc8(&s1);
    ((void (__thiscall*)(void*, void*))*(void**)((char*)vt + 0x160))(this, &s1);
}
