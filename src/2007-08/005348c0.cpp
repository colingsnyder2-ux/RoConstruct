// from server: 100% by colin
extern int G_008abe7c;

extern void* __cdecl func_005be5b0(void* ptr, int size);
extern void __cdecl func_005bde00(void* ptr, int value, int arg);
extern void __cdecl func_005be160(void* ptr, int value);

void* __cdecl func_005348c0(void* ptr, int value)
{
    void* result = func_005be5b0(ptr, 4);
    if (result != 0) {
        *(int*)result = value;
    }
    func_005bde00(ptr, -10000, G_008abe7c);
    func_005be160(ptr, -2);
    return result;
}
