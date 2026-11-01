// from server: 72% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct placeholder {
    char pad[0xe8];
    int field_e8;
    long* field_ec;
    void get(int* out);
};

void placeholder::get(int* out) {
    out[0] = this->field_e8;
    long* p = this->field_ec;
    out[1] = (int)p;
    if (p == 0) {
        _InterlockedExchangeAdd(p + 1, 1);
    }
}
