// from server: 37% by colin
struct LDrawCommand {
    void* m_stream;
    void destroy();
};

extern "C" {
    int __stdcall std_uncaught_exception();
    void __stdcall ostream_Osfx(void*);
    void __stdcall streambuf_Unlock(void*);
    void* __stdcall ios_rdbuf(void*);
}

void LDrawCommand::destroy()
{
    void* p = m_stream;
    if (!std_uncaught_exception()) {
        ostream_Osfx(p);
    }
    void* rdbuf = ios_rdbuf((char*)p + *(int*)(*(int*)p + 4));
    if (rdbuf) {
        streambuf_Unlock(ios_rdbuf((char*)p + *(int*)(*(int*)p + 4)));
    }
}
