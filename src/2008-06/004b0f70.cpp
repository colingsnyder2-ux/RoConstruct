// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_049e9d88cc7b9efa.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/shared_ptr.hpp>
struct S;
struct Buffer;

struct Item {
    virtual void unused();
    virtual void write(Buffer*);
};

struct CodeProfiler;
template<class T> struct SP { T* px; T& operator*() const { return *px; } };
struct Guard {
    unsigned char storage[24];
    Guard(CodeProfiler&, bool);
    ~Guard();
};

struct Buffer {
    int bits;
    unsigned char storage[272];
    unsigned int limit;
};

struct Addr { unsigned int v; };

struct Stream {
    unsigned char prefix[8];
    Buffer buffer;
    bool result;
    unsigned char tail[3];

    Stream(S*, Addr);
    ~Stream();
};

void __cdecl putByte(Buffer*, unsigned char);

struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool ready();

    unsigned char prefix[0x2c70];
    std::list<boost::shared_ptr<Item> > pending;
    unsigned char pad2[0x2d28-0x2c74-0x1c];
    SP<CodeProfiler> context;
    unsigned char suffix[0x24];
    Addr parameter;

    bool f();
};

bool S::f() {
    if (!ready())
        return false;

    Guard guard(*context, false);
    Stream stream(this, parameter);

    while (pending.size() > 0) {
        boost::shared_ptr<Item> item = pending.front();
        if (item) {
            if (static_cast<unsigned int>((stream.buffer.bits + 7) >> 3)
                >= stream.buffer.limit)
                break;

            if (!stream.buffer.bits)
                putByte(&stream.buffer, 78);

            item->write(&stream.buffer);
            stream.result = true;
        }
        pending.pop_front();
    }

    return stream.result;
}
