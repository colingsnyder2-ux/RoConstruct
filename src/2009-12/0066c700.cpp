// from server: 39% by atomic.potato
extern "C" double g_009a6ad0;

struct GenericJob
{
    int value;
    int value2;
    int pad[123];

    void getValue(double* result);
};

void GenericJob::getValue(double* result)
{
    double value = value2 > 0 ? 0.0 : g_009a6ad0;
    result[0] = value;
    result[1] = value;
}
