// from server: 93% by colin
struct CRobloxControlColorSelector {
    char pad[4];
    int* begin;
    int* end;
    int* capacity;
    void clear();
};

extern "C" void __stdcall sub_77DDBC(int*);
extern "C" void __cdecl sub_62FC62(void*);

void CRobloxControlColorSelector::clear()
{
    if (begin != 0) {
        int* p = begin;
        int* e = end;
        while (p != e) {
            sub_77DDBC(p + 2);
            p += 3;
        }
        sub_62FC62(begin);
    }
    begin = 0;
    end = 0;
    capacity = 0;
}
