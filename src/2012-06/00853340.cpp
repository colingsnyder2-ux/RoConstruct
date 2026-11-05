// from server: 40% by 41k
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct LuaStatsItem {
    long* vptr;
    long field_4;
    long field_8;
    long field_C;
    long field_10;
    long field_14;
    long field_18;
    long field_1C;
    long field_20;
    long field_24;
    long field_28;

    void UpdateStats();
};

void LuaStatsItem::UpdateStats() {
    long* this_ptr = (long*)this;
    long old_value = _InterlockedExchangeAdd(this_ptr, 1);
    if (old_value == 1) {
        this_ptr[0x1C] = this_ptr[0];
        this_ptr[0x20] = this_ptr[1];
        if (this_ptr[1] != 0) {
            _InterlockedExchangeAdd(&this_ptr[1], 1);
        }
        this_ptr[0x24] = this_ptr[2];
        this_ptr[0x28] = this_ptr[3];
        if (this_ptr[3] != 0) {
            _InterlockedExchangeAdd(&this_ptr[3], 1);
        }
    }
}
