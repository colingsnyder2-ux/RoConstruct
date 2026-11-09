// from server: 44% by atomic.potato
struct SpatialFilter {
    float field0;
    float field4;
    float field8;
};

extern float g_scale;

void scaleVec3(SpatialFilter* dst, const SpatialFilter* src) {
    dst->field0 = src->field0 * g_scale;
    dst->field4 = src->field4 * g_scale;
    dst->field8 = src->field8 * g_scale;
}
