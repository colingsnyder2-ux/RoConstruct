// from server: 100% by king_originala
struct Result {
    void finish();
};

struct CRbxPlayDocTemplate {
    char pad[0x58];
    void* field_58;
    void method();
};

void CRbxPlayDocTemplate::method()
{
    void* q = *(void**)((char*)field_58 + 0x24);
    void** vtable = *(void***)q;
    Result* (__thiscall *fn)(void*, int, int) =
        (Result* (__thiscall *)(void*, int, int))vtable[0x88 / 4];
    fn(q, 0, 1)->finish();
}
