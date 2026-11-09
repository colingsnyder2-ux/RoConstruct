// from server: 15% by colin
struct Flag;

struct FlagStand;

struct FlagStandService {
    char pad[0xe8];
    void* listHead;
    void* listTail;
    int count;
    int field_f0;

    FlagStand* findRandomEmptyStandForFlag(Flag* f);
};

extern "C" int __stdcall rand();
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Flag {
    char pad[0x294];
    int field_294;
};

struct FlagStand {
    char pad[8];
    Flag* flag;
};

extern "C" int __stdcall sub_5e6120(void* a, void* b);
extern "C" int __stdcall sub_5e9a30(void* a);
extern "C" int __stdcall sub_5b4070(void* a, void* b);
extern "C" void __stdcall sub_62fc62(void* a);

FlagStand* FlagStandService::findRandomEmptyStandForFlag(Flag* f) {
    if (field_f0 == 0)
        return 0;

    void* head = listHead;
    void* tail = listTail;
    int* arr = 0;
    int arrSize = 0;
    int arrCap = 0;

    void* node = head;
    while (node != tail) {
        FlagStand* fs = *(FlagStand**)((char*)node + 8);
        if (fs->flag->field_294 == f->field_294) {
            if (sub_5e9a30(fs->flag) == 0) {
                if (arrSize == arrCap) {
                    // grow
                }
                arr[arrSize++] = (int)fs;
            }
        }
        node = *(void**)node;
    }

    if (arrSize == 0) {
        if (arr) sub_62fc62(arr);
        return 0;
    }

    int idx = rand() % arrSize;
    FlagStand* result = (FlagStand*)arr[idx];
    if (arr) sub_62fc62(arr);
    return result;
}
