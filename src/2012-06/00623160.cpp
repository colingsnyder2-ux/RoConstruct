// from server: 57% by atomic.potato
// roc 2012-06 00623160  unit: RBX::WedgeBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00623160

struct WedgeBuilder {
    void __cdecl copy_backward(float* first, float* last, float* dest);
};

void WedgeBuilder::copy_backward(float* first, float* last, float* dest) {
    while (last != first) {
        last -= 4;
        dest -= 4;
        dest[0] = last[0];
        dest[1] = last[1];
        dest[2] = last[2];
        dest[3] = last[3];
    }
}
