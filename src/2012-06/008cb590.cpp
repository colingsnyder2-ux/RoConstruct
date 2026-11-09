// from server: 100% by Intel
extern "C" void* __stdcall sub_8cb190(void* arg);

struct UnknownObject {
    void __thiscall method(void* arg);
};

struct FlagStandService {
    void __thiscall func(void* arg);
};

void __thiscall FlagStandService::func(void* arg) {
    void* result = sub_8cb190(arg);
    if (result != 0) {
        static_cast<UnknownObject*>(result)->method(arg);
    }
}
