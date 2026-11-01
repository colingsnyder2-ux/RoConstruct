// from server: 58% by Intel




extern "C" void __stdcall _exit(int);

int __cdecl sub_558310(int);

struct CrashReporter {
    int func(int arg);
};

int CrashReporter::func(int arg) {
    int result = sub_558310(arg);
    _exit(1);
    return result;
}
