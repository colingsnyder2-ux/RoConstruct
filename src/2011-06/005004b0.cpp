// from server: 38% by atomic.potato
struct ReplicatorJob {
    char pad0[0x1a18];
    char field_1a18[0x38];
    void* field_1a50;
    void* field_1a54;
    void func(void* a, void* b, void* c);
};

extern "C" void* __stdcall sub_80a05e(unsigned int);
extern "C" void __stdcall sub_4b45b0(void*, void*);
extern "C" void __stdcall sub_4fc040(void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_4fc0d0(void*);
extern "C" void __stdcall sub_5180d0(void*, void*);
extern "C" void __stdcall sub_721520(void*, void*);
extern "C" void __stdcall sub_7736f0(void*);

void ReplicatorJob::func(void* a, void* b, void* c)
{
    if (a == this->field_1a54)
        return;

    if (this->field_1a50 != 0) {
        void* p = (a != 0) ? (char*)a + 0x1c : 0;
        void* local18 = b;
        void* local1c = p;
        sub_4b45b0(&local18, &local1c);
        void* q = this->field_1a50;
        if (local18 == *(void**)q && local1c == *(void**)((char*)q + 4)) {
            goto found;
        }
    }
    {
        void* mem = sub_80a05e(0x40);
        if (mem != 0) {
            void* tmp = 0;
            sub_721520(&tmp, c);
            sub_4fc040(mem, this, tmp, b, c);
        }
        sub_5180d0((char*)this + 0x1a18, mem);
    }
found:
    ;
}
