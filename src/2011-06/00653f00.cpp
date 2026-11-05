// from server: 92% by atomic.potato
struct S_func_00653f00 {
    char pad[12];
    int field_c;
    int field_10;
    bool f();
};

extern "C" int __stdcall FileTimeToSystemTime(const void* ft, void* st);
extern "C" int __stdcall SystemTimeToTzSpecificLocalTime(const void* tz, const void* st, void* out);

bool S_func_00653f00::f()
{
    if (field_c == 0 && field_10 == 0)
        return false;
    char buf[16];
    FileTimeToSystemTime(&field_c, buf);
    SystemTimeToTzSpecificLocalTime(0, buf, &buf[4]);
    return true;
}
