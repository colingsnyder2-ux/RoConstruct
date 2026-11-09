// from server: 42% by atomic.potato
struct Vec {
    char pad[0x10];
    char* end;
};

struct Alloc {
    void* p;
};

extern "C" void __stdcall sub_7a89b2(int, int);
extern "C" void __stdcall sub_8f3b80(void*, int);
extern "C" void __stdcall sub_8f3c50(void*, void*, void*);
extern "C" char* __stdcall sub_8f5c00(void*, void*, void*);
extern "C" void __stdcall sub_8f6790(void*, void*, int);
extern "C" void __stdcall sub_8f6b70(void*, void*, void*, void*);

struct SpecializedMeshGen {
    char pad[0x10];
    char* end;
    void func(char* first, char* last, int count, int flag);
};

void SpecializedMeshGen::func(char* first, char* last, int count, int flag) {
    char buf[0x44];
    sub_7a89b2(0, 0);
    int n = (int)((last - first) / 48);
    if ((unsigned)n < (unsigned)count) {
        sub_8f3b80(buf, flag);
        char* p = first + count * 48;
        sub_8f6b70(this, first, p, this->end);
        int m = (int)((this->end - first) / 48);
        sub_8f6790(this, this->end, count - m);
        this->end += count * 48;
        sub_8f3c50(buf, first, this->end - count * 48);
        return;
    }
    sub_8f3b80(buf, flag);
    char* e = this->end;
    char* p = e - count * 48;
    sub_8f6b70(this, p, e, e);
    this->end = sub_8f5c00(first, p, e);
    sub_8f3c50(buf, first, first + count * 48);
}
