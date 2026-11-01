// from server: 71% by Intel

struct VInstance {
    int field_70;

    int __thiscall method_0042A130(int arg);
};

extern "C" int __stdcall GetProcAddress(int, int);
extern "C" int __cdecl sub_418A10(int);

int __thiscall VInstance::method_0042A130(int arg)
{
    if (this->field_70 == 0) {
        int proc = GetProcAddress(sub_418A10(0xB4EA44), 0);
        this->field_70 = proc;
    }
    *(int*)arg = this->field_70;
    return 0;
}
