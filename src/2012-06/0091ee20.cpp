// from server: 100% by Intel
// External function declarations
extern "C" int __cdecl func_751300(int arg);
extern "C" int __cdecl func_79b020(int arg);

struct FilterHumanoidParts {
    static int __stdcall someFunction(int arg);
};

int __stdcall FilterHumanoidParts::someFunction(int arg) {
    int result1 = func_751300(arg);
    int result2 = func_79b020(result1);
    
    // neg eax; sbb eax, eax; add eax, 2
    // Returns 1 if result2 != 0, 2 if result2 == 0
    return (result2 != 0) ? 1 : 2;
}
