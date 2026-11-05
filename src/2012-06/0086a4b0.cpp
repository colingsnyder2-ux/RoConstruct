// from server: 50% by atomic.potato
struct S {
    char pad0[4];
    void* end;
    void* find(void*, void**);
};

extern "C" void* __stdcall sub_7065c0(void*);
extern "C" bool __stdcall sub_b22650(void*, void*);

void* S::find(void* key, void** out) {
    void* it = sub_7065c0(key);
    if (it != this->end) {
        if (!sub_b22650(key, (char*)it + 0xc)) {
            *out = it;
            return it;
        }
    }
    *out = this->end;
    return this->end;
}
