// from server: 100% by king_originala
extern unsigned long moduleData;
extern void* callbackArgument;
extern long (__cdecl *registrationCallback)(void*);

extern "C" long __stdcall registerClasses(void*, unsigned long, unsigned long);

long __stdcall registerModuleClasses(unsigned long context, unsigned long flags)
{
    long result = registerClasses(&moduleData, context, flags);
    if (result >= 0 && registrationCallback)
        result = registrationCallback(callbackArgument);
    return result;
}
