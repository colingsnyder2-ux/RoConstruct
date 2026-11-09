// from server: 42% by atomic.potato
struct EventInvocationItem {
    char pad0[0xc];
    void* begin;
    void* end;
    int field18;
    void addItem(void*);
void sub_532D80(void*);
};


extern "C" void __stdcall sub_532D00(void*, void*);
extern "C" void __stdcall sub_5330A0(void*, void*);
extern "C" void __stdcall sub_7B7840(void*, void*, int);
extern "C" void __stdcall sub_537090(void*, void*);

extern "C" void* __stdcall string_ctor_copy(void*, void*);
extern "C" void* __stdcall string_ctor_default(void*);
extern "C" void* __stdcall string_dtor(void*);

void EventInvocationItem::addItem(void* src)
{
    char buf1[0x1c];
    char buf2[0x1c];
    unsigned int count;
    unsigned int i;

    sub_532D80(src);
    sub_7B7840(this, src, 0);

    count = *(unsigned int*)((char*)this + 0x40);
    for (i = 0; i < count; i++) {
        sub_532D00(this, src);
        string_ctor_default(buf2);
        sub_5330A0(this, src);
        string_ctor_copy(buf1, buf2);
        sub_537090(this, buf1);
        string_dtor(buf2);
    }

    int n = (int)(((char*)this->end - (char*)this->begin) >> 2);
    int bits = -1;
    if (n > 0) {
        unsigned int v = (unsigned int)n;
        do {
            v >>= 1;
            bits++;
        } while (v > 0);
    }
    bits++;
    this->field18 = bits;
}
