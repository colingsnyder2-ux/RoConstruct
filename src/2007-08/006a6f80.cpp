// from server: 37% by colin
struct CMap {
    char pad0[0xf8];
    void* field_f8;
    char pad_fc[0x1b4 - 0xfc];
    void* field_1b4;
    void* field_1b8;
    void* field_1bc;
    void SetAt(void* key, void* value);
};

extern "C" void* __stdcall sub_62fef6(unsigned int size);
extern "C" void __stdcall sub_6301e4(void* p);
extern "C" void* __stdcall sub_643980(void* p);
extern "C" void __stdcall sub_6444e0(void* p, void* arg);
extern "C" void __stdcall sub_67a640(void* p, void* arg);
extern "C" void* __stdcall sub_67be90(void* p);
extern "C" void __stdcall sub_67d150(void* p);
extern "C" void* __stdcall sub_6a5a30(void* p, void* arg);
extern "C" void* __stdcall sub_6a6af0(void* p, void* arg);
extern "C" void __stdcall sub_6a6e60(void* p, void* arg);
extern "C" void __stdcall sub_6a6f60(void* p, void* a, void* b);
extern "C" void* __stdcall sub_77d2ec(void* p);

void CMap::SetAt(void* key, void* value)
{
    if (key == 0) return;
    if (field_1b8 == 0) return;
    if (field_1b8 == key) return;

    void* v = sub_643980(this);
    if (*(int*)((char*)v + 0x60) == 0) {
        void* r = sub_6a6af0(field_1bc, key);
        if (r == 0) {
            if (value != 0) {
                void** vt = *(void***)this;
                void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0x144/4];
                fn(this, value, 1);
            }
            return;
        }
    }

    if (value == 0) {
        void* r = sub_6a6af0(field_1bc, key);
        if (r == 0) return;
    }

    void* r2 = sub_6a6af0(field_1bc, field_1b8);
    void* interlocked = (void*)0x77d2ec;

    if (r2 == 0) {
        void* mem = sub_62fef6(0x38);
        void* obj = 0;
        if (mem != 0) {
            void* a = sub_643980(this);
            obj = sub_6a5a30(mem, a);
        }
        void* old = *(void**)((char*)obj + 0x20);
        sub_6301e4(old);
        *(void**)((char*)obj + 0x20) = field_f8;
        sub_77d2ec((char*)field_f8 + 4);
        sub_6a6f60(field_1bc, field_1b8, obj);
    }

    sub_67a640(field_f8, 0);
    sub_6301e4(field_f8);
    field_f8 = 0;

    void* r3 = sub_6a6af0(field_1bc, key);
    if (r3 == 0) {
        void* mem = sub_62fef6(0x38);
        void* obj = 0;
        if (mem != 0) {
            void* a = sub_643980(this);
            obj = sub_6a5a30(mem, a);
        }
        field_f8 = *(void**)((char*)obj + 0x20);
        sub_77d2ec((char*)field_f8 + 4);
        sub_67a640(field_f8, this);

        if (value != 0) {
            void** vt = *(void***)this;
            void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0x144/4];
            fn(this, value, 1);
        }

        sub_67d150(field_f8);
        sub_6a6f60(field_1bc, key, obj);
    } else {
        field_f8 = *(void**)((char*)r3 + 0x20);
        sub_67a640(field_f8, this);
        sub_77d2ec((char*)field_f8 + 4);

        if (*(int*)((char*)field_f8 + 0x3c) == 0 && value != 0) {
            void* mem = sub_62fef6(0x40);
            void* obj = 0;
            if (mem != 0) {
                obj = sub_67be90(mem);
            }
            *(void**)((char*)field_f8 + 0x3c) = obj;
            sub_6444e0(*(void**)((char*)field_f8 + 0x3c), value);
        }

        if (key == field_1b4) {
            sub_6a6e60(field_1bc, key);
        }
    }

    void** vt = *(void***)this;
    void (*fn)(void*) = (void (*)(void*))vt[0x17c/4];
    fn(this);
    field_1b8 = key;
}
