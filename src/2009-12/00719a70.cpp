// from server: 55% by atomic.potato
struct EventDesc
{
    float __cdecl get(float *a, float *b);
};

float EventDesc::get(float *a, float *b)
{
    float x = a[0] - b[0];
    float y = a[1] - b[1];
    float z = b[2];
    return (x * x + y * y) / z;
}
