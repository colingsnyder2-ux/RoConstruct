// from server: 100% by king_originala
extern "C" int (__cdecl *fclose_import)(void *);
void __cdecl operator delete(void *);

struct B_func_004baa40 {
    virtual ~B_func_004baa40();
};

struct S_func_004baa40 : B_func_004baa40 {
    ~S_func_004baa40();
};

struct FilePacketLogger : S_func_004baa40 {
    char padding[0x208];
    void *file;
    FilePacketLogger *destroy(unsigned int flags);
};

FilePacketLogger *FilePacketLogger::destroy(unsigned int flags)
{
    void *stream = file;
    *reinterpret_cast<unsigned int *>(this) = 0x82450c;
    if (stream)
        fclose_import(stream);
    S_func_004baa40::~S_func_004baa40();
    if (flags & 1)
        operator delete(this);
    return this;
}
