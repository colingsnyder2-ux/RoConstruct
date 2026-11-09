// from server: 100% by atomic.potato
struct SelectionPointLasso
{
    bool get(float* value);
    char data[0xbc];
    float x;
    float y;
    float z;
};

bool SelectionPointLasso::get(float* value)
{
    value[0] = x;
    value[1] = y;
    value[2] = z;
    return true;
}
