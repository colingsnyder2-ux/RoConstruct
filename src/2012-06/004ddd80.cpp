// from server: 43% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct OgreVertexStreamer {
    void set();
};

void OgreVertexStreamer::set() {
    if (*(char*)(*(DWORD*)this + 0x69)) {
        DWORD* p = *(DWORD**)this;
        while (*(char*)(p[2] + 0x69)) {
            p = (DWORD*)p[2];
        }
        *(DWORD*)this = (DWORD)p;
    } else {
        DWORD* p = *(DWORD**)this;
        while (!*(char*)(p[2] + 0x69)) {
            p = (DWORD*)p[2];
        }
        *(DWORD*)this = (DWORD)p;
    }
}
