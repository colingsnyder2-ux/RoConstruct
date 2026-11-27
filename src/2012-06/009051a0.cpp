// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Result {
    double value;
    bool flag;
};
struct ContentProviderJob {
    char pad[0x278];
    unsigned int resolution;
    Result f(const double& scale);
};
Result ContentProviderJob::f(const double& scale)
{
    Result r;
    r.flag = false;
    r.value = (double)resolution * scale;
    return r;
}