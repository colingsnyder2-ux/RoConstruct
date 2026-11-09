// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};

class Instance;
namespace std {
class streambuf_;
}
class Ios {
public:
    __declspec(dllimport) std::streambuf* rdbuf() const;
};
class IStream : public virtual Ios {
};
class Base1 { public: virtual ~Base1(); };
class Base2 { public: virtual ~Base2(); };
class Instance : public Base1, public Base2 {
public:
    void setParent(Instance* parent);
};

typedef std::vector<shared_ptr<Instance> > Instances;
class Workspace : public Instance {
public:
    void insertInstances(Instances& instances, Instance* parent, int mode, int flag);
};

class DataModel {
public:
    Instance* findFirstChildByName(std::string name);
    char pad[0x204];
    Workspace* workspace;
};

inline Workspace* getWorkspace(DataModel* dm) { return dm ? dm->workspace : 0; }

class Selection {
public:
    char pad[0x154];
    Instances* selection;
    shared_ptr<Instance> front();
    void setSelection(Instances::iterator begin, Instances::iterator end);
};
Selection* __cdecl getSelection(Workspace* ws);

class Lock {
public:
    Lock(shared_ptr<DataModel> dm);
    ~Lock();
    int a, b, c;
};

class XmlElement {
public:
    ~XmlElement();
};

class XmlReader {
public:
    XmlReader(std::streambuf* buf);
    ~XmlReader();
    std::auto_ptr<XmlElement> parse();
    char data[0x48];
};

class Serializer {
public:
    int x;
    void loadInstances(XmlElement* root, Instances& instances);
};

struct ClearParent {
    void (Instance::*f)(Instance*);
    Instance* value;
    int pad;
    void operator()(shared_ptr<Instance>& p) const { (p.get()->*f)(value); }
};
inline ClearParent clearParent() { ClearParent c; c.f = &Instance::setParent; c.value = 0; return c; }

class Doc {
public:
    char pad[0x1b4];
    int locked;
};

class VCWorkspace {
public:
    char pad[0x24];
    shared_ptr<DataModel> dm;
    Doc* doc;
    void insert(IStream& stream, bool flag);
};

void VCWorkspace::insert(IStream& stream, bool flag)
{
    if (dm->findFirstChildByName("NetworkClient"))
        return;
    Lock lock(dm);
    Selection* sel = getSelection(getWorkspace(dm.get()));
    Instance* parent = (flag && sel->selection->size() == 1) ? sel->front().get() : getWorkspace(dm.get());
    int mode = flag ? 1 : 2;
    int f = flag ? 1 : 0;
    Instances instances;
    try
    {
        {
            XmlReader reader(stream.rdbuf());
            std::auto_ptr<XmlElement> root(reader.parse());
            Serializer serializer;
            serializer.loadInstances(root.get(), instances);
        }
        getWorkspace(dm.get())->insertInstances(instances, parent, mode, f);
        Doc* d = doc;
        if (!d->locked)
            sel->setSelection(instances.begin(), instances.end());
    }
    catch (std::exception&)
    {
        std::for_each(instances.begin(), instances.end(), clearParent());
        throw;
    }
}
