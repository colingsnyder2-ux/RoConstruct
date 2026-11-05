// from server: 98% by atomic.potato
struct NetworkOwnerJob
{
    void sub_52EB90(int, int, int*);
    void sub_532610(int*);
    void __cdecl run(int*);
};

void NetworkOwnerJob::run(int* out)
{
    *out = 0;
    sub_52EB90(2, 1, out);
    int v = *out;
    if (v < 1 || v > 3)
        sub_532610(out);
}
