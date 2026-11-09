// from server: 50% by colin
struct Vector3Item {
    char pad[0x114];
    int field114;
    int field118;
    int field11c;
    int field120;
    int field124;
    void method();
};

extern "C" void __stdcall sub_698240();
extern "C" void* __cdecl sub_62fef6(unsigned int size);
extern "C" void __stdcall sub_699d00();
extern "C" void* __fastcall sub_43e670(void* self, int, int, int);

void Vector3Item::method()
{
    sub_698240();
    int i = 0;
    int* p = &field11c;
    do {
        void* mem = sub_62fef6(0x12c);
        void* obj;
        if (mem != 0) {
            obj = sub_43e670(mem, field114, field118, i);
        } else {
            obj = 0;
        }
        *p = (int)obj;
        sub_699d00();
        i++;
        p++;
    } while (i < 3);
}
