// from server: 75% by colin
struct CVideoStream {
    long __stdcall Receive(void* pSample, long* pFlags);
};

long __stdcall CVideoStream::Receive(void* pSample, long* pFlags) {
    if (pSample == 0) {
        return 0x80004003;
    }
    CVideoStream* self = (CVideoStream*)((char*)this - 0xc);
    long (__stdcall *fn)(void*, long*) = *(long (__stdcall **)(void*, long*))((char*)*(void**)self + 0x20);
    long hr = fn(pSample, pFlags);
    if (hr < 0) {
        return 1;
    }
    return hr;
}
