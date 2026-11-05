// from server: 31% by atomic.potato
struct S
{
    float x;
    float y;
    float z;
    int f();
};

int S::f()
{
    float ax = x < 0.0f ? -x : x;
    float ay = y < 0.0f ? -y : y;
    float az = z < 0.0f ? -z : z;

    if (ax > ay)
    {
        if (ax > az)
            return 0;
        return 2;
    }

    if (ay > az)
        return 1;
    return 2;
}
