// from server: 75% by atomic.potato
struct QuadVolumeBuilder
{
    int f(int value, const float* bounds);
};

int QuadVolumeBuilder::f(int value, const float* bounds)
{
    if (value == 0 && bounds[1] > bounds[0])
        return 1;
    return 0;
}
