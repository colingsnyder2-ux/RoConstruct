// from server: 100% by atomic.potato
struct SelectionPointLasso {
    char padding[0xb0];
    float x;
    float y;
    float z;
    bool f(float* out);
};

bool SelectionPointLasso::f(float* out)
{
    out[0] = x;
    out[1] = y;
    out[2] = z;
    return true;
}
