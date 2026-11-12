// from server: 100% by EspClaude
// from server: 72% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_claude_0983d7a6c027c920.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 Replicator::sendItems analog (004acf80). Layout from target bytes:
// pendingItems list at this+0x1d90 (size at +0x1d98), profileDataOut at +0x1e04, peer at +0x1e14;
// ItemSender: bitStream at +8 (bits), maxStreamSize at +0x11c (signed jge), sentItems at +0x120;
// Profiling::Mark ctor inline (TlsGetValue/GetThreadTimes(GetCurrentThread())/TlsSetValue), dtor out of line.
#include <windows.h>
#include <list>
#include <boost/shared_ptr.hpp>
struct S;
struct Buffer;

struct Item {
    virtual void unused();
    virtual void write(Buffer*);
    virtual bool ready();
};

struct CodeProfiler;

struct Mark {
    CodeProfiler& section;
    CodeProfiler* enclosingSection;
    FILETIME creationTime;
    FILETIME exitTime;
    FILETIME kernelTime;
    FILETIME userTime;
    bool frameTick;
    static DWORD markTlsIndex;
    Mark(CodeProfiler& sectionSet, bool frameTickSet)
        : section(sectionSet), frameTick(frameTickSet)
    {
        if (markTlsIndex)
        {
            enclosingSection = (CodeProfiler*)TlsGetValue(markTlsIndex);
            GetThreadTimes(GetCurrentThread(), &creationTime, &exitTime, &kernelTime, &userTime);
            TlsSetValue(markTlsIndex, (void*)&sectionSet);
        }
    }
    ~Mark();
};

struct Buffer {
    int bits;
    unsigned char storage[272];
    int limit;
};

struct Peer;

struct Stream {
    unsigned char prefix[8];
    Buffer buffer;
    bool result;
    unsigned char tail[3];

    Stream(S*, Peer*);
    ~Stream();
};

void __cdecl putByte(Buffer*, unsigned char);

struct S {
    virtual void v0();

    unsigned char prefix[0x1d90 - 4];
    std::list<boost::shared_ptr<Item> > pending;
    unsigned char pad2[0x1e04 - 0x1d90 - sizeof(std::list<boost::shared_ptr<Item> >)];
    CodeProfiler* profileDataOut;
    unsigned char pad3[0x1e14 - 0x1e08];
    Peer* peer;

    bool f();
};

bool S::f() {
    Mark mark(*profileDataOut, false);
    Stream stream(this, peer);

    while (pending.size() > 0) {
        boost::shared_ptr<Item> item = pending.front();
        if (item) {
            if (!item->ready())
                break;
            if (((stream.buffer.bits + 7) >> 3) >= stream.buffer.limit)
                break;

            if (!stream.buffer.bits)
                putByte(&stream.buffer, 0x49);

            item->write(&stream.buffer);
            stream.result = true;
        }
        pending.pop_front();
    }

    return stream.result;
}
