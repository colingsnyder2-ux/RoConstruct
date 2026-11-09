// from server: 41% by colin
struct S {
    char pad[0x84];
    void f();
};

extern "C" void __stdcall sub_4890A0(void*, void*);
extern "C" void __stdcall sub_5F1A40(void*);
extern "C" void __stdcall sub_728F60(void*);
extern "C" void __stdcall sub_413C00(void*);
extern "C" void __stdcall sub_414170(void*);
extern "C" int __stdcall sub_77E708(void*, void*);

void S::f() {
    char buf1[0x40];
    char buf2[0x40];
    char flag;
    void* p;

    flag = 0;
    sub_4890A0(buf1, &flag);
    if (flag) return;

    while (true) {
        char* name = *(char**)((char*)this + 0x84);
        if (*name != 0) break;

        sub_728F60(buf2);
        void** pp = (void**)(buf2 + 0x10);
        void* obj;
        if (pp) {
            void* v = *pp;
            if (v) {
                obj = (void*)(*(int(__thiscall**)(void*))(*(int*)v + 4))(v);
            } else {
                obj = (void*)0x8827C8;
            }
        } else {
            obj = 0;
        }

        if (sub_77E708(obj, (void*)0x886688)) {
            void* v = *pp;
            obj = (void*)((char*)v + 4);
        } else {
            obj = 0;
        }

        if (*(int*)obj != 0) {
            void* ecx = *(void**)((char*)this + 0x80);
            ecx = *(void**)ecx;
            void* edx = *(void**)((char*)obj + 4);
            void* eax = *(void**)((char*)obj + 8);
            ((void(__stdcall*)(void*, void*))eax)(edx, ecx);
            char* pflag = *(char**)((char*)this + 0x8C);
            if (*pflag == 0) {
                *pflag = 1;
            }
        } else {
            sub_413C00(buf1);
            *(int*)(buf1 + 0x34) = 0;
            sub_414170(buf1);
        }

        sub_5F1A40(buf2);
        sub_4890A0(buf1, &flag);
        if (!flag) continue;
        break;
    }
}
