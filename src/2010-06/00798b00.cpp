// from server: 49% by atomic.potato
extern "C" int __cdecl func_008c3234(int, int, int, int);

struct RBX_Log {
    void __cdecl func_00798b00(int a, double *out);
};

void RBX_Log::func_00798b00(int a, double *out)
{
    double local;
    func_008c3234(a, 0x200, 0, (int)&local);
    *out = local;
}
