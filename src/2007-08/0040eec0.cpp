// from server: 49% by Intel
struct CChildFrame {
    int field_0;
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" int __stdcall sub_6303ca(CChildFrame*);

int __cdecl sub_40eec0(CChildFrame* self)
{
    __try {
        void* mem = operator_new(0xdc);
        CChildFrame* obj = static_cast<CChildFrame*>(mem);
        int result = 0;
        if (obj == 0) {
            obj->field_0 = 0;
            sub_6303ca(obj);
            *reinterpret_cast<int*>(obj) = 0x786b1c;
            result = reinterpret_cast<int>(obj);
        }
        return result;
    }
    __except(1) {
        return 0;
    }
}
