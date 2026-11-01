// from server: 65% by Intel




struct ExceptionBase {
    virtual ~ExceptionBase() {}
};

struct TrieDepthExceededException : ExceptionBase {
    TrieDepthExceededException(int depth);
};

extern "C" void __stdcall InitializeException(ExceptionBase* thisptr, const char* message);
extern "C" void __stdcall Memset(void* dest, int value, int count);

TrieDepthExceededException::TrieDepthExceededException(int depth) {
    int* field1 = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x180);
    int* field2 = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x184);
    
    *field1 = 0;
    *field2 = depth;
    
    if (depth > 50) {
        ExceptionBase temp;
        InitializeException(&temp, "trie depth exceeded");
        Memset(this, 0xB970A4, 0x180);
    }
    
    Memset(this, 0, 0x180);
}
