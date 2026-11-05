// from server: 51% by atomic.potato
struct BuoyancyBallContact
{
    float value[26];
    void getValue(float*, float*);
};

void BuoyancyBallContact::getValue(float* first, float* second)
{
    *first = value[26];
    *second = value[26] * 1.0f;
}
