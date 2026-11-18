// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native RBX::Network::Replicator::NewInstanceItem::write 004b8620 (byte + identity + references EXACT).
// Real class member of native-headers/Replicator.h; vftable-slot (own-vft tier) identity from RTTI/link order.
// Statement order from byte-exact analog src/2008-06/004b8620.cpp.
// Layout helper offsets (Replicator +0x2bb0/+0x2c90/+0x2d54, Instance +0x14) are INFERRED from the target binary.
// External helper declarations are name-agnostic; every call/data relocation is bound to the original image address.
#include "Replicator.h"
#include <string>
#include <intrin.h>
#include <utility>

namespace nboost {
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

namespace NIIWriter {

typedef std::string NII_Text;

struct NII_NamedText {
    unsigned prefix;
    std::string text;
    const char* c_str() const { return text.c_str(); }
};

struct NII_NameInterface {
    virtual void unused();
    virtual NII_NamedText* name();
};

struct NII_Object {
    unsigned prefix[2];
    unsigned textPart[2];
    NII_NameInterface namePart;
    unsigned callbackPart;
    unsigned unknown;
    unsigned identifier;
    void prepare();
};

struct NII_TextPart {
    NII_Text format(int);
};

typedef nboost::shared_ptr<unsigned> NII_Shared;

struct NII_Lookup {
    int find(NII_Object**);
};

struct NII_IdentifierWriter {
    void write(void*, unsigned);
};

struct NII_LabelProvider {
    const char* get(int);
};

struct NII_Callback {
    const void* tag;
    void* object;
};

struct NII_Owner {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual bool flag(NII_Object*);
    void writeObject(void*, NII_Object*);
    void finishObject(NII_Object*, void*);
    void writeCallback(NII_Callback*, int, void*);
};

struct NII_Settings {
    char padding[0x131];
    bool logging;
};

extern NII_Settings* __cdecl NII_settings();
extern void __cdecl NII_writeKind(void*, int);
extern NII_Shared __cdecl NII_acquire();
extern void __cdecl NII_report(unsigned*, int, const char*, const char*, const char*, const char*);
extern void* __cdecl NII_writeFlag(void*, bool);
extern const char NII_message[];
extern const char NII_callbackTag[];

struct NII_Self {
    void* vftable;
    NII_Owner* owner;
    NII_Object* object;
};

inline NII_Owner* ownerOf(void* thiz) { return *reinterpret_cast<NII_Owner**>(reinterpret_cast<char*>(thiz)+4); }
inline NII_Object* objectOf(void* thiz) { return *reinterpret_cast<NII_Object**>(reinterpret_cast<char*>(thiz)+8); }

} // namespace NIIWriter

using namespace NIIWriter;

void RBX::Network::Replicator::NewInstanceItem::write(RakNet::BitStream& stream)
{
    NII_Self* self = reinterpret_cast<NII_Self*>(this);

    {
    NII_Object* key = self->object;
    if (!reinterpret_cast<NII_Lookup*>(
            reinterpret_cast<char*>(self->owner) + 0x2c90)->find(&key))
        return;
    }

    NII_writeKind((void*)&stream, 2);
    NII_Object* writtenObject = self->object;
    self->owner->writeObject((void*)&stream, writtenObject);

    if (NII_settings()->logging) {
        NII_Object* instance = self->object;
        NII_NameInterface* names = &instance->namePart;
        instance->prepare();

        NII_report(NII_acquire().get(), 1, NII_message, names->name()->c_str(),
            reinterpret_cast<NII_TextPart*>(reinterpret_cast<char*>(instance)+8)->format(4).c_str(),
            reinterpret_cast<NII_LabelProvider*>(reinterpret_cast<char*>(self->owner)+0x2d54)->get(1));
    }

    reinterpret_cast<NII_IdentifierWriter*>(
        reinterpret_cast<char*>(self->owner) + 0x2bb0)->write(
            (void*)&stream, self->object->identifier);

    NII_Object* testedObject = self->object;
    bool enabled = self->owner->flag(testedObject);
    NII_writeFlag((void*)&stream, enabled);
    self->owner->finishObject(self->object, (void*)&stream);

    void* callbackObject = self->object
        ? reinterpret_cast<char*>(self->object) + 0x14
        : 0;

    NII_Callback callback;
    callback.object = callbackObject;
    callback.tag = NII_callbackTag;
    self->owner->writeCallback(&callback, 0, (void*)&stream);
}
