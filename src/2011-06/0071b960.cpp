// from server: 100% by atomic.potato
struct SelectionPointLasso
{
    char padding[188];
    float x;
    float y;
    float z;
    bool get(float* value);
};

bool SelectionPointLasso::get(float* value)
{
    value[0] = x;
    value[1] = y;
    value[2] = z;
    return true;
}
