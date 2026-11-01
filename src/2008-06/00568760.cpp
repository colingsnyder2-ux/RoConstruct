// from server: 100% by coldek
// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// GlobalSettings::loadState analog (2008-06 00568760): the catch funclet prints
// "Exception thrown in loadState %s" through StandardOut::singleton() (MESSAGE_INFO=1);
// the early return on an empty path (instead of if/try nesting) gives the target's frame layout.
#include <exception>
#include <string>
#include <memory>
#include <fstream>

enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
struct StandardOut;
struct StandardOutPtr {
    StandardOut* px;
    void* pn;
    ~StandardOutPtr();
    StandardOut* operator->() const { return px; }
};
struct StandardOut {
    static StandardOutPtr singleton();
    void __cdecl print(MessageType, const char*, ...);
};

std::string __cdecl getSourceName();

struct Product {
    ~Product();
};

struct Parser {
    char storage[72];
    explicit Parser(std::streambuf*);
    ~Parser();
    std::auto_ptr<Product> read();
};

struct Mutex {
    void lock();
    void unlock();
};

extern Mutex productMutex;

struct Lock {
    Mutex *mutex;
    bool acquired;
    explicit Lock(Mutex &);
    ~Lock();
};

__forceinline Lock::Lock(Mutex &m)
    : mutex(&m), acquired(false) {
    mutex->lock();
    acquired = true;
}

__forceinline Lock::~Lock() {
    if (acquired)
        mutex->unlock();
}

struct TokenData {
    char storage[24];
    ~TokenData();
};

struct Token {
    unsigned int tag;
    TokenData data;
    Token();
    void finish();
    ~Token();
};

__forceinline Token::~Token() {}

struct S {
    void load();
    void apply(Product *, Token *);
};

void S::load() {
    std::string name = getSourceName();
    if (name.empty())
        return;
    try {
        std::ifstream stream(name.c_str(), std::ios_base::in | std::ios_base::binary, 0x40);
        Parser parser(stream.rdbuf());
        std::auto_ptr<Product> product(parser.read());
        Lock lock(productMutex);
        Token token;
        apply(product.get(), &token);
        token.finish();
    } catch (std::exception& e) {
        StandardOut::singleton()->print(MESSAGE_INFO, "Exception thrown in loadState %s", e.what());
    }
}
