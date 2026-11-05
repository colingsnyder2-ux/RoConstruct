// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <stddef.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class AtomicInt32 {
 volatile long _value;
public:
 AtomicInt32(int x):_value(x){}
 void increment(){InterlockedIncrement(&_value);}
 unsigned int decrement(){return InterlockedDecrement(&_value)!=0;}
};
class _WeakPtr {
public:
    inline virtual ~_WeakPtr() {}
protected:
    friend class ReferenceCountedObject;
    virtual void objectCollected() = 0;
};
class _WeakPtrLinkedList {
public:
    _WeakPtr*                   weakPtr;
    _WeakPtrLinkedList*         next;
    inline _WeakPtrLinkedList() : weakPtr(0), next(0) {}
    inline _WeakPtrLinkedList(_WeakPtr* p, _WeakPtrLinkedList* n) : weakPtr(p), next(n) {}
};
class ReferenceCountedObject {
public:
    AtomicInt32                 ReferenceCountedObject_refCount;
    _WeakPtrLinkedList*         ReferenceCountedObject_weakPointer;
protected:
    ReferenceCountedObject() : 
        ReferenceCountedObject_refCount(0), 
        ReferenceCountedObject_weakPointer(0) {
        do {} while (0);
    }
public:
    void ReferenceCountedObject_zeroWeakPointers() {
        _WeakPtrLinkedList* node = ReferenceCountedObject_weakPointer;
        while (node != 0) {
            node->weakPtr->objectCollected();
            _WeakPtrLinkedList* tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    virtual ~ReferenceCountedObject() {}
    ReferenceCountedObject(const ReferenceCountedObject& notUsed) : 
        ReferenceCountedObject_refCount(0),
        ReferenceCountedObject_weakPointer(0) {
        (void)notUsed;
        do {} while (0);
    }
    ReferenceCountedObject& operator=(const ReferenceCountedObject& other) {
        (void)other;
        return *this;
    }
};
template <class T>
class ReferenceCountedPointer {
private:
    T*           m_pointer;
public:
	typedef T element_type;
    inline T* pointer() const {
        return m_pointer;
    }
    inline T* getPointer() const {
        return m_pointer;
    }
private:
    void zeroPointer() {
        if (m_pointer != 0) {
            do {} while (0);
            do {} while (0);
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    void setPointer(T* x) {
        if (x != m_pointer) {
            zeroPointer();
            if (x != 0) {
                do {} while (0);
		        m_pointer = x;
                do {} while (0);
                m_pointer->ReferenceCountedObject_refCount.increment();
            }
        }
    }
public:      
    inline ReferenceCountedPointer() : m_pointer(0) {}
    template <class S>
    inline ReferenceCountedPointer(const ReferenceCountedPointer<S>& p) : 
        m_pointer(0) {
        setPointer(p.getPointer());
    }
    template <class S>
    ReferenceCountedPointer<S> downcast() {
        return ReferenceCountedPointer<S>(dynamic_cast<S*>(m_pointer));
    }
    inline ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(0) {
        setPointer(p.m_pointer);
    }
    inline ReferenceCountedPointer(T* p) : m_pointer(0) { 
        setPointer(p); 
    }
    inline ~ReferenceCountedPointer() {
        zeroPointer();
    }
    inline const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p) {
        setPointer(p.m_pointer);
        return *this;
    }   
    inline ReferenceCountedPointer<T>& operator=(T* p) {
        setPointer(p);
        return *this;
    }
    inline bool operator==(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer == y.m_pointer); 
    }
    inline bool operator!=(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer != y.m_pointer); 
    }
	bool operator < (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer < y.m_pointer); 
	}
	bool operator > (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer > y.m_pointer); 
	}
	bool operator <= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer <= y.m_pointer); 
	}
	bool operator >= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer >= y.m_pointer); 
	}
    inline T& operator*() const {
        do {} while (0);
        return (*m_pointer);
    }
    inline T* operator->() const {
        return m_pointer;
    }
    inline bool isNull() const {
        return (m_pointer == 0);
    }
    inline bool notNull() const {
        return (m_pointer != 0);
    }
    inline int isLastReference() const {
        return (m_pointer->ReferenceCountedObject_refCount.value() == 1);
    }
};

class Color3 { public: float r, g, b; Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {} };
class Color4 { public: float r, g, b, a; Color4(const Color4& o) : r(o.r), g(o.g), b(o.b), a(o.a) {} Color4& operator=(const Color4& o) { r = o.r; g = o.g; b = o.b; a = o.a; return *this; } };
class LightingParameters { public: LightingParameters(const LightingParameters&); ~LightingParameters(); char pad[0xf8]; };
class Texture : public ReferenceCountedObject {};
}
namespace boost {
template<class T> class shared_ptr { T* px; void* pn; public: T* get() const { return px; } T* operator->() const { return px; } };
template<class T> class scoped_ptr { T* px; public: T* get() const { return px; } T* operator->() const { return px; } };
}
namespace RBX {
class Lighting {
public:
	char pad[0x90];
	G3D::LightingParameters skyParameters;
	G3D::Color3 ambientTop;
	G3D::Color3 ambientBottom;
	char pad1a0[4];
	G3D::Color4 clearColor;
	G3D::Color4 fogColor;
	const G3D::LightingParameters& getSkyParameters() const { return skyParameters; }
	const G3D::Color3& getAmbientTop() const { return ambientTop; }
	const G3D::Color3& getAmbientBottom() const { return ambientBottom; }
	G3D::Color4 getClearColor() const { return clearColor; }
	G3D::Color4 getFogColor() const { return fogColor; }
};
class ServiceProvider {
public:
	template<class T> T* create() const;
	template<class T> static T* create(const ServiceProvider* context) { return context ? context->create<T>() : 0; }
};
class DataModel : public ServiceProvider {};
class RenderSceneBase {
public:
	virtual ~RenderSceneBase();
	virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Texture> sky, G3D::LightingParameters skyParameters, G3D::Color3 top, G3D::Color3 bottom);
	char pad4[0xc];
	G3D::Color4 colorClearValue;
};
namespace RenderNew {
class RenderScene : public RenderSceneBase {
public:
	char pad20[0x84 - 0x20];
	G3D::Color4 fogColor;
};
}
namespace View {
class View {
public:
	virtual ~View();
	int i4;
	boost::scoped_ptr<RenderSceneBase> renderLibScene;
	int ic, i10;
	boost::shared_ptr<DataModel> dataModel;
	void suppressSkybox();
};
void View::suppressSkybox()
{
	Lighting* lighting = ServiceProvider::create<Lighting>(dataModel.get());
	renderLibScene->presetLighting(0, lighting->getSkyParameters(), lighting->getAmbientTop(), lighting->getAmbientBottom());
	renderLibScene->colorClearValue = lighting->getClearColor();
	dynamic_cast<RenderNew::RenderScene*>(renderLibScene.get())->fogColor = lighting->getFogColor();
}
}
}
