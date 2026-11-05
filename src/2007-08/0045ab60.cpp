// from server: 100% by colin
struct StatsService {
    bool construct(const char* name);
};

extern "C" int __cdecl sub_630D36(int, int, int, int, int);

bool StatsService::construct(const char* name) {
    int r = sub_630D36((int)name, 0, 0x881f4c, 0x889ad4, 0);
    return r != 0;
}
