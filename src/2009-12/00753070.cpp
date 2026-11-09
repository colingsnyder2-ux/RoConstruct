// from server: 31% by atomic.potato
struct XmlElement {
    char pad0[4];
    int type;
    bool isValueType() const;
};

struct XmlNameValuePair {
    char pad0[0x10];
    XmlElement elem;
    bool isValueType() const;
    bool getValue(int* out) const;
    bool getValue2(int* out) const;
};

struct PropDesc {
    char pad0[0x20];
    void* iface;
    void* mgr;
    bool invoke(void* a, void* b, void* c);
};

extern "C" {
    void __stdcall sub_98b6e8(void* p);
    void __stdcall sub_98b6e4(void* p);
    void* __cdecl sub_6325b0(void* a, void* b);
}

bool __fastcall sub_64cf00(void* self, void* edx, void* a);
bool __fastcall sub_677460(void* self, void* edx, void* a);
bool __fastcall sub_677150(void* self, void* edx, void* a);

bool PropDesc::invoke(void* a, void* b, void* c)
{
    if (sub_677460(this, 0, a))
        return true;

    XmlNameValuePair* pair = (XmlNameValuePair*)a;
    if (pair->isValueType()) {
        int val;
        sub_98b6e8(&val);
        if (pair->getValue(&val)) {
            void* p = sub_6325b0(&val, c);
            if (sub_64cf00(this->mgr, 0, p)) {
                void* v = *(void**)c;
                void* iface = this->iface;
                void** vt = *(void***)iface;
                void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[4];
                fn(iface, v, c);
                sub_98b6e4(&val);
                return true;
            }
            if (*(int*)((char*)&val + 0x14) == 0) {
                void** vt = *(void***)this;
                bool (*fn)(void*, void*, void*) = (bool (*)(void*, void*, void*))vt[0x38/4];
                if (fn(this, b, 0)) {
                    sub_98b6e4(&val);
                    return true;
                }
            }
            sub_98b6e4(&val);
        }
    }

    int val2;
    if (pair->getValue2(&val2)) {
        void* iface = this->iface;
        void** vt = *(void***)iface;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[4];
        fn(iface, b, &val2);
    }
    return false;
}
