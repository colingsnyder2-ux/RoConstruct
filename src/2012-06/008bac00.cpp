// from server: 36% by tester
struct HttpQueueStatsItem {
    int field0;
    int field4;
    char pad8[0x38];
    HttpQueueStatsItem(int, int, int, int, int, int, int, int);
    ~HttpQueueStatsItem();
};

struct Http {
    int field0;
    HttpQueueStatsItem field4;
    Http(int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_8b9180(int*, int*);
extern "C" void __stdcall sub_8ba820();
extern "C" void __stdcall sub_8b8f60();

Http::Http(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
    : field4(a1, a2, a3, a4, a5, a6, a7, a8)
{
    sub_8b9180((int*)&field4, (int*)&field4);
    sub_8ba820();
    field0 = 0;
    sub_8b8f60();
}
