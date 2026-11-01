// from server: 100% by colin
struct S {
    int* begin;
    int count;
    int capacity;
    void f();
};

extern void __fastcall destroy_element(void*);
extern void __cdecl free_mem(void*);

void S::f()
{
    int i = 0;
    if (count > 0) {
        int offset = 0;
        do {
            destroy_element((char*)begin + offset);
            i++;
            offset += 0x18;
        } while (i < count);
    }
    free_mem(begin);
    begin = 0;
    count = 0;
    capacity = 0;
}
