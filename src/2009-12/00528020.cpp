// from server: 42% by atomic.potato
struct S {
    char pad0[0x114];
    char field114[0x10];
    char pad124[0x1c];
    char field140[4];
    char field144[4];
    char field148[4];
    void destroy();
};

extern "C" void __stdcall sub_98b6e4();
extern "C" void __cdecl sub_7f385a(void*);
extern "C" void __cdecl sub_540ae0();
extern "C" void __cdecl sub_664370();
extern "C" void __cdecl sub_41af50();
extern "C" void __cdecl sub_550330();

void S::destroy()
{
    *(int*)((char*)this + 0) = 0x9bbd9c;
    *(int*)((char*)this + 4) = 0x9bbd90;
    *(int*)((char*)this + 0x18) = 0x9bbd84;
    *(int*)((char*)this + 0x1c) = 0x9bbd7c;
    *(int*)((char*)this + 0x94) = 0x9bbd4c;

    void* p148 = *(void**)((char*)this + 0x148);
    if (p148) {
        sub_540ae0();
        sub_7f385a(p148);
    }

    void* p144 = *(void**)((char*)this + 0x144);
    if (p144) {
        sub_540ae0();
        sub_7f385a(p144);
    }

    void* p140 = *(void**)((char*)this + 0x140);
    if (p140) {
        sub_540ae0();
        sub_7f385a(p140);
    }

    sub_98b6e4();

    sub_664370();
    sub_41af50();

    *(int*)((char*)this + 0) = 0x9bbb9c;
    *(int*)((char*)this + 4) = 0x9bbb90;
    *(int*)((char*)this + 0x18) = 0x9bbb84;
    *(int*)((char*)this + 0x1c) = 0x9bbb7c;
    *(int*)((char*)this + 0x94) = 0x9bbb4c;

    sub_550330();
}
