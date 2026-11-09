// from server: 100% by atomic.potato
typedef void (__thiscall *TStringDtor)(void *);

extern TStringDtor g_stringDtor;
extern "C" void __cdecl sub_718a32(void *ptr);

struct Elem_004904f0 {
    char storage[0x44];
};

struct S_004904f0 {
    char gap0[0xc];
    Elem_004904f0 *begin;
    Elem_004904f0 *end;
    Elem_004904f0 *capacity;

    void f();
};

void S_004904f0::f()
{
    Elem_004904f0 *first = begin;
    if (first != 0) {
        Elem_004904f0 *last = end;
        for (Elem_004904f0 *it = first; it != last; ++it)
            g_stringDtor(it);
        sub_718a32(begin);
    }
    begin = 0;
    end = 0;
    capacity = 0;
}
