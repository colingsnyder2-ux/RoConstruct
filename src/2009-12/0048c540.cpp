// from server: 63% by atomic.potato
// roc 2009-12 0048c540  unit: G3D::Shader  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048c540

struct Shader {
    float x, y, z;
    int w;
};

void copy_shader_range(Shader* first, Shader* last, Shader* out) {
    while (first != last) {
        if (out) {
            out->x = first->x;
            out->y = first->y;
            out->z = first->z;
            out->w = first->w;
        }
        ++first;
        ++out;
    }
}
