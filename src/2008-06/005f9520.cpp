// from server: 100% by colin
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
struct UString_sink {
    struct stream_buffer {
        DWORD this_offset;
        stream_buffer(DWORD this_offset) : this_offset(this_offset) {}
        int get();
    };
};

int UString_sink::stream_buffer::get() {
    DWORD eax = *(DWORD*)((DWORD)this + 0x58);
    eax >>= 4;
    eax &= 1;
    return eax;
}
