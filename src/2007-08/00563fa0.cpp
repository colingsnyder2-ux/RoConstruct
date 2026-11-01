// from server: 72% by colin
struct DataModel;

struct IDataState;

struct EditSelectionVerb {
    char pad0[0x14];
    int field14;
    char pad1[0x8];
    int field20;
};

struct UngroupSelectionVerb : EditSelectionVerb {
    bool isEnabled() const;
};

extern "C" int __stdcall sub_562300(int*, int);
extern "C" int __stdcall sub_5619D0(int);
extern "C" int __stdcall sub_55F610(int, int);

bool UngroupSelectionVerb::isEnabled() const {
    int v = sub_562300((int*)&this->field14, 1);
    int* p = *(int**)(v + 0x104);
    int count = 0;
    if (p[1] != 0) {
        count = (p[2] - p[1]) >> 3;
    }
    if (count == 0) {
        return false;
    }
    int r;
    if (this->field20 != 0) {
        r = sub_5619D0(this->field20);
    } else {
        r = 0;
    }
    int result = sub_55F610(r, 0x55f040);
    return result != 0;
}
