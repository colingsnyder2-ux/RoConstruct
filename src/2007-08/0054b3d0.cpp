// from server: 100% by colin
struct UString_sink_stream_buffer {
    void reset(int mode);
};

void UString_sink_stream_buffer::reset(int mode)
{
    if (mode == 1) {
        if ((*(unsigned char*)((char*)this + 0x58) & 2) == 0) {
            *(int*)(*(int*)((char*)this + 0x10)) = 0;
            *(int*)(*(int*)((char*)this + 0x20)) = 0;
            *(int*)(*(int*)((char*)this + 0x30)) = 0;
            *(unsigned int*)((char*)this + 0x58) |= 2;
        }
    } else if (mode == 2) {
        if ((*(unsigned char*)((char*)this + 0x58) & 4) == 0) {
            (*(void (__thiscall**)(void*))(*(int*)this + 0x30))(this);
            *(int*)(*(int*)((char*)this + 0x14)) = 0;
            *(int*)(*(int*)((char*)this + 0x24)) = 0;
            *(int*)(*(int*)((char*)this + 0x34)) = 0;
            *(unsigned int*)((char*)this + 0x58) |= 4;
        }
    }
}
