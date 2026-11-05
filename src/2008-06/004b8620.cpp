// from server: 100% by king_originala
// from server: 78% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}



typedef std::string Text;

struct NamedText {
    unsigned prefix;
    std::string text;
    const char* c_str() const { return text.c_str(); }
};

struct NameInterface {
    virtual void unused();
    virtual NamedText* name();
};

struct Object {
    unsigned prefix[2];
    unsigned textPart[2];
    NameInterface namePart;
    unsigned callbackPart;
    unsigned unknown;
    unsigned identifier;
    void prepare();
};

struct TextPart {
    Text format(int);
};

typedef boost::shared_ptr<unsigned> Shared;

struct Lookup {
    int find(Object**);
};

struct IdentifierWriter {
    void write(void*, unsigned);
};

struct LabelProvider {
    const char* get(int);
};

struct Callback {
    const void* tag;
    void* object;
};

struct Owner {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual bool flag(Object*);
    void writeObject(void*, Object*);
    void finishObject(Object*, void*);
    void writeCallback(Callback*, int, void*);
};

struct Settings {
    char padding[0x131];
    bool logging;
};

extern Settings* __cdecl settings();
extern void __cdecl writeKind(void*, int);
extern Shared __cdecl acquire();
extern void __cdecl report(unsigned*, int, const char*, const char*, const char*, const char*);
extern void* __cdecl writeFlag(void*, bool);
extern const char message[];
extern const char callbackTag[];

struct Item {
    unsigned prefix;
    Owner* owner;
    Object* object;
    void write(void*);
};

void Item::write(void* stream)
{
    {
    Object* key = object;
    if (!reinterpret_cast<Lookup*>(
            reinterpret_cast<char*>(owner) + 0x2c90)->find(&key))
        return;
    }

    writeKind(stream, 2);
    Object* writtenObject = object;
    owner->writeObject(stream, writtenObject);

    if (settings()->logging) {
        Object* instance = object;
        NameInterface* names = &instance->namePart;
        instance->prepare();

        report(acquire().get(), 1, message, names->name()->c_str(),
            reinterpret_cast<TextPart*>(reinterpret_cast<char*>(instance)+8)->format(4).c_str(),
            reinterpret_cast<LabelProvider*>(reinterpret_cast<char*>(owner)+0x2d54)->get(1));
    }

    reinterpret_cast<IdentifierWriter*>(
        reinterpret_cast<char*>(owner) + 0x2bb0)->write(
            stream, object->identifier);

    Object* testedObject = object;
    bool enabled = owner->flag(testedObject);
    writeFlag(stream, enabled);
    owner->finishObject(object, stream);

    void* callbackObject = object
        ? reinterpret_cast<char*>(object) + 0x14
        : 0;

    Callback callback;
    callback.object = callbackObject;
    callback.tag = callbackTag;
    owner->writeCallback(&callback, 0, stream);
}
