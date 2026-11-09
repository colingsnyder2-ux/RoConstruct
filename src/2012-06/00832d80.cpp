// from server: 27% by Intel
struct ExceptionRegistration {
    ExceptionRegistration* prev;
    void* handler;
};

extern "C" void __stdcall __CxxFrameHandler3();

struct PAVPrimitive {
    void __cdecl func(int a1, int a2);
};

void PAVPrimitive::func(int a1, int a2) {
    ExceptionRegistration reg;
    reg.prev = *reinterpret_cast<ExceptionRegistration**>(0);
    reg.handler = __CxxFrameHandler3;
    *reinterpret_cast<ExceptionRegistration**>(0) = &reg;

    int* v4 = reinterpret_cast<int*>(a1 - 32);
    if (!a1) {
        v4 = 0;
    }

    int* saved_v4 = v4;
    int v6 = 0;

    if (v4) {
        v4[0] = a2;
        v4[1] = 0;
        v4[2] = 0;
        v4[3] = 0;
        v4[4] = 0;
        v4[5] = 0;
        v4[6] = 0;
        v4[7] = 0;
    }

    *reinterpret_cast<ExceptionRegistration**>(0) = reg.prev;
}
