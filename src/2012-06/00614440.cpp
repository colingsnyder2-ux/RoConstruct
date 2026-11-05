// from server: 75% by atomic.potato
struct QuadVolumeBuilder
{
    int f(int a, float* b);
};

int QuadVolumeBuilder::f(int a, float* b)
{
    if (a == 0 && b[1] > b[0])
        return 1;
    return 0;
}
