// from server: 56% by Intel
struct VUDimXItem {
    void func(int);
};

extern "C" void __stdcall OutputDebugStringA(const char*);

void __thiscall VUDimXItem::func(int arg) {
    OutputDebugStringA("RBXAuthenticationNegotiation:");
    char* this_adj = reinterpret_cast<char*>(this) - 0x10C;
    reinterpret_cast<void(__thiscall*)(void*)>(0x9F1F40)(this_adj);
    reinterpret_cast<void(__thiscall*)(void*, int)>(0x9F1650)(this_adj, 0);
}
