// from server: 92% by atomic.potato
struct S_func_00653f40 {
    char pad[4];
    int field4;
    int field8;
    bool f();
};

extern "C" int __stdcall FileTimeToSystemTime(const void* lpFileTime, void* lpSystemTime);
extern "C" int __stdcall SystemTimeToTzSpecificLocalTime(const void* lpTimeZoneInformation, const void* lpUniversalTime, void* lpLocalTime);

bool S_func_00653f40::f()
{
    if (field4 == 0 && field8 == 0)
        return false;

    char buf[16];
    FileTimeToSystemTime(&field4, buf);
    SystemTimeToTzSpecificLocalTime(0, buf, &buf[4]);
    return true;
}
