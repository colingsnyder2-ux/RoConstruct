// from server: 39% by colin
struct StdOutMsg {
    char pad0[0x2c];
};

struct StdOut {
    char pad0[8];
    int* begin;
    int* end;
    int* cap;
    char pad1[0x18 - 0x14];
    StdOutMsg* msg;
    void remove(int id);
};

extern "C" {
    void __stdcall LeaveCriticalSection(void*);
    int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
    void __cdecl _invalid_parameter_noinfo();
}

void StdOut::remove(int id)
{
    char flag = 0;
    StdOutMsg* m = msg;
    StdOutMsg* p = (StdOutMsg*)((char*)m + 0x2c);
    void* local = p;
    // call 0x41d870 with ecx = &local
    // (some helper taking pointer)
    extern void helper(void*);
    helper(&local);

    int* first = begin;
    int* last = end;
    while (first != last) {
        if (*first == id) {
            int* next = first + 1;
            int count = (int)((char*)last - (char*)next) >> 2;
            if (count > 0) {
                memmove_s(first, count * 4, next, count * 4);
            }
            end = end - 1;
            break;
        }
        first++;
    }
}
