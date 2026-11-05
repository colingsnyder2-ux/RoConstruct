// from server: 77% by Intel
struct SYSTEMTIME {
    short wYear;
    short wMonth;
    short wDayOfWeek;
    short wDay;
    short wHour;
    short wMinute;
    short wSecond;
    short wMilliseconds;
};

struct FILETIME {
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

extern "C" int __stdcall FileTimeToSystemTime(const FILETIME*, SYSTEMTIME*);
extern "C" int __stdcall SystemTimeToTzSpecificLocalTime(void*, const SYSTEMTIME*, SYSTEMTIME*);

struct CPropGrid {
    char pad[12];
    void* field_C;
    void* field_10;
    bool UpdateItemsJob();
};

bool CPropGrid::UpdateItemsJob()
{
    void* pC = field_C;
    if (pC != 0 && field_10 == 0)
        return false;

    SYSTEMTIME st1;
    SYSTEMTIME st2;
    FileTimeToSystemTime(static_cast<const FILETIME*>(pC), &st1);
    SystemTimeToTzSpecificLocalTime(0, &st1, &st2);
    return true;
}
