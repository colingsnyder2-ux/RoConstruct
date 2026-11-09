// from server: 50% by Intel
struct CChildFrame {
    int field_0;
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" int __stdcall sub_6303ca(void* thisptr);

int __cdecl sub_40ee60(CChildFrame* thisptr)
{
    __try {
        void* esi = operator_new(0xdc);
        if (esi != 0)
            return 0;

        sub_6303ca(esi);
        *(int*)esi = 0x786944;
        return (int)esi;
    }
    __except (1) {
        return 0;
    }
}
