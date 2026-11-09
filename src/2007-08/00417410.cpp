// from server: 42% by colin
struct S {
    void* field0;
    void* field4;
    void* field8;
    void init(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_415910(void*, void*);
extern "C" void __cdecl sub_413D00(void*);

void S::init(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    char local;
    void* p;

    if (!sub_4879D0(&local)) {
        field8 = (void*)0x416AB0;
        field0 = (void*)0x416AE0;
        p = sub_62FEF6(0x38);
        sub_415910(p, &local);
        field4 = p;
    }
    sub_413D00(&local);
}
