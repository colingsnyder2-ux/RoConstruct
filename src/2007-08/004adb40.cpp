// from server: 38% by colin
struct DeleteInstanceItem {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int method();
};

extern "C" int __stdcall sub_55E610();
extern "C" int __stdcall sub_4EE620();
extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __stdcall sub_77E6D8();

extern unsigned int dword_8BE954;
extern unsigned int dword_8BE950;
extern unsigned int dword_8BE728;

int DeleteInstanceItem::method()
{
    unsigned int local = 0;
    unsigned int idx;
    int* p;

    for (;;) {
        unsigned int flags = dword_8BE954;
        if ((flags & 1) == 0) {
            unsigned int v = dword_8BE728;
            idx = v;
            dword_8BE954 = flags | 1;
            dword_8BE950 = idx;
            dword_8BE728 = v + 1;
        } else {
            idx = dword_8BE950;
        }

        if (sub_55E610() > idx) {
            break;
        }

        int* begin = (int*)field4;
        if (begin == 0) {
            local = 0;
        } else {
            local = (unsigned int)((field8 - (int)begin) >> 2);
        }

        if (begin != 0) {
            unsigned int cap = (unsigned int)((fieldC - (int)begin) >> 2);
            if (local < cap) {
                *(int*)field8 = 0;
                field8 += 4;
                continue;
            }
        }

        int* end = (int*)field8;
        if (begin > end) {
            sub_77E6D8();
        }
        sub_4EE620();
    }

    unsigned int flags2 = dword_8BE954;
    if ((flags2 & 1) == 0) {
        unsigned int v = dword_8BE728;
        idx = v;
        dword_8BE954 = flags2 | 1;
        dword_8BE950 = idx;
        dword_8BE728 = v + 1;
    } else {
        idx = dword_8BE950;
    }

    int* begin2 = (int*)field4;
    if (begin2 == 0 || idx >= (unsigned int)((field8 - (int)begin2) >> 2)) {
        sub_77E6D8();
    }

    int* slot = (int*)(field4 + idx * 4);
    if (*slot == 0) {
        void* mem = sub_62FEF6(8);
        if (mem != 0) {
            *(int*)mem = 0x79D5F0;
            *slot = (int)mem;
            return (int)mem + 4;
        }
        *slot = 0;
    }
    return *slot + 4;
}
