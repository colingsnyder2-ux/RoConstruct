// from server: 87% by atomic.potato
struct Part {
    char pad0[4];
    void* begin;
    void* end;
    void* cap;
    void clear();
};

extern "C" void __stdcall sub_982114(void*);
extern "C" void __cdecl sub_b2263c(void*);

void Part::clear()
{
    if (begin) {
        char* p = (char*)begin;
        char* e = (char*)end;
        while (p != e) {
            sub_b2263c(p);
            p += 0x20;
        }
        sub_982114(begin);
    }
    begin = 0;
    end = 0;
    cap = 0;
}
