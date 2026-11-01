// from server: 100% by king_originala
extern "C" void __cdecl cleanup();
extern "C" int __cdecl register_exit(void (__cdecl *)());
extern "C" void __cdecl initialize();

int __cdecl f()
{
    register_exit(cleanup);
    initialize();
    return 0;
}
