// from server: 37% by Intel
extern "C" void __stdcall exit(int);

struct G3D_Log {
    void func();
};

void G3D_Log::func() {
    exit(-1);
}
