// from server: 47% by atomic.potato
struct CRobloxApp {
    char pad[0xa4];
    bool sub_424ed0();

    bool sub_44bab0();
};

extern "C" void __stdcall sub_45ba40(int, const char*);

bool CRobloxApp::sub_44bab0()
{
    if (sub_424ed0()) {
        sub_45ba40(0, (const char*)0x9ab050);
        return true;
    }
    sub_45ba40(0x30, (const char*)0x9ab0a4);
    return false;
}
