// from server: 53% by Intel





struct ExceptionBase {
    virtual ~ExceptionBase();
};

struct TrieDepthExceededException : ExceptionBase {
    TrieDepthExceededException(int depth);
    int field_180;
    int field_184;
};

extern "C" void __stdcall InitializeException(void* thisptr, int a2);
extern "C" void __stdcall RaiseException(const char* message, void* exceptionObj, int vtableAddr);
extern "C" void __stdcall Memset(void* dest, int value, int size);

TrieDepthExceededException::TrieDepthExceededException(int depth) {
    field_180 = 0;
    field_184 = depth;
    if (depth > 50) {
        void* exceptionObj;
        InitializeException(&exceptionObj, 0);
        RaiseException("trie depth exceeded", exceptionObj, 0xB97098);
    }
    Memset(this, 0, 0x180);
}
