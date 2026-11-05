// from server: 100% by colin
struct Vec4 {
    float x, y, z, w;
};

struct VWidget {
    Vec4 getColor() const;
};

extern "C" Vec4* __cdecl sub_50B200();

Vec4 VWidget::getColor() const {
    Vec4* src = sub_50B200();
    Vec4 result;
    result.x = src->x;
    result.y = src->y;
    result.z = src->z;
    result.w = 1.0f;
    return result;
}
