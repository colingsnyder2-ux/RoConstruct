// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_01b2951c1522d87e.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <stdexcept>
#include <memory>
#include <istream>
// Both XmlElement tag (0x10) and XmlAttribute value base (0x08)
// establish four additional bytes in the shared Sibling base in this binary.
#define Sibling LegacySibling
#include "util/Utilities.h"
#undef Sibling
namespace RBX { template<class T> class Sibling : public LegacySibling<T> { unsigned char layoutPadding[4]; }; }
#include "v8xml/XmlElement.h"
struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct XmlPool { char cs[0x18]; void* first; };
XmlPool& xmlPool();
extern long xmlNodeCount;
struct XmlNode : public XmlElement {
    static void operator delete(void* p) {
        XmlPool& pool = xmlPool();
        EnterCriticalSection((_RTL_CRITICAL_SECTION*)&pool);
        *(void**)p = pool.first;
        pool.first = p;
        LeaveCriticalSection((_RTL_CRITICAL_SECTION*)&pool);
        InterlockedDecrement(&xmlNodeCount);
    }
};
struct ArchiveBinder;
struct DataModel;

extern void __cdecl operator delete(void *);
extern void __cdecl loadXml(XmlNode *, DataModel *);
extern const RBX::Name& robloxTag;
extern const RBX::Name& versionAttribute;

typedef std::auto_ptr<XmlNode> TemporaryOwner;
typedef std::auto_ptr<XmlNode> NodeOwner;

struct Parser {
    char storage[72];
    explicit Parser(void *);
    ~Parser();
    TemporaryOwner parse();
};

typedef std::istream Stream;

struct Completion {
    virtual void finish(int);
};

struct DataModel {
    char padding[0xf8];
    Completion completion;
};

struct ArchiveBinder {
    int schemaVersionLoading;
    void load(Stream *, DataModel *);
};

void ArchiveBinder::load(Stream *stream, DataModel *model) {
    Parser parser(stream->rdbuf());
    NodeOwner root(parser.parse());

    if (root->getTag() == robloxTag) {
        XmlAttribute* version = root->findAttribute(versionAttribute);
        if (!version->getValue(schemaVersionLoading)) {
            throw std::runtime_error("SerializerV2::loadXML no version number");
        }

        if (schemaVersionLoading < 4) {
            throw std::runtime_error("SerializerV2::loadXML schemaVersionLoading<4");
        }

        loadXml(root.get(), model);
        model->completion.finish(0);
    } else {
        schemaVersionLoading = 1;
        throw std::runtime_error("SerializerV2::loadXML ill-formed XML. No Roblox tag");
    }
}

