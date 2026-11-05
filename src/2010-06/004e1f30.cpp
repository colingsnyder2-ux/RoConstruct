// from server: 70% by atomic.potato
struct Ray {
    float origin[3];
    float direction[3];
};

extern "C" void __cdecl copy3(float* dst, const float* src);

Ray* setOrigin(Ray* self, const float* v) {
    copy3(self->origin, v);
    copy3(self->direction, v + 1);
    copy3(self->direction + 1, v + 2);
    return self;
}
