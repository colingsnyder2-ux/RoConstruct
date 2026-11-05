// from server: 31% by atomic.potato
struct GenericJob
{
    int value;
    int result;
    int pad[126];
    void getValue(double* output);
};

void GenericJob::getValue(double* output)
{
    double value = result > 0 ? 0.0 : 1.0;
    *output = value;
}
