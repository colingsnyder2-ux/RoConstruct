// from server: 100% by tester
struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" Vec3* __cdecl sub_62E880();

struct SpatialFilter {
    int field0;
    int field4;
    Vec3 field8;
    Vec3 field14;
    Vec3 field20;
    SpatialFilter* construct();
};

SpatialFilter* SpatialFilter::construct() {
    field0 = 0;
    field4 = -1;
    Vec3* p1 = sub_62E880();
    field8 = *p1;
    Vec3* p2 = sub_62E880();
    field14 = *p2;
    Vec3* p3 = sub_62E880();
    field20 = *p3;
    return this;
}
