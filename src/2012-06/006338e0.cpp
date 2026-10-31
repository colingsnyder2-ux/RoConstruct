// from server: 60% by Intel
extern "C" int __stdcall InterlockedCompareExchange(long volatile*, long, long);
extern "C" void __stdcall Sleep(unsigned long);

struct StringTable {
    bool func();
};

bool StringTable::func() {
    unsigned char bl = 1;
    int edi = InterlockedCompareExchange((long volatile*)this, 1, 0);
    if (edi == 1) {
        do {
            Sleep(0);
            edi = InterlockedCompareExchange((long volatile*)this, 1, 0);
        } while (edi == 1);
        bl = 0;
    }
    return bl != 0;
}
