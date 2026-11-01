// from server: 100% by tester
struct S {
};

char __cdecl f(void* arg)
{
    return *reinterpret_cast<char*>(
        reinterpret_cast<char*(*)(void*)>(
            *reinterpret_cast<void**>(reinterpret_cast<char*>(arg) + 0)
        )(reinterpret_cast<void*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(arg) + 4)))
    );
}
