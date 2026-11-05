// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native G3D 6.09 interface view; unrelated methods omitted.
#include <algorithm>
#include <limits>
#include <intrin.h>
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

class Vector3 { public: float x,y,z; };
class Vector4 { public: float x,y,z,w; };
class Matrix3 { public:float elt[3][3]; };
class CoordinateFrame { public:Matrix3 rotation;Vector3 translation; };
class Color3 { public:float r,g,b;
 Color3& operator*=(float fScalar){r*=fScalar;g*=fScalar;b*=fScalar;return *this;}
};
class Texture;
typedef ReferenceCountedPointer<Texture> TextureRef;
class GLight  {
public:
    Vector4             position;
    Vector3             spotDirection;
    double              spotCutoff;
    double              attenuation[3];
    Color3              color;
    bool                enabled;
    bool                specular;
    bool                diffuse;
    GLight();
    static GLight directional(const Vector3& toLight, const Color3& color, bool specular = true, bool diffuse = true);
    static GLight point(const Vector3& pos, const Color3& color, double constAtt = 1, double linAtt = 0, double quadAtt = 0, bool specular = true, bool diffuse = true);
    static GLight spot(const Vector3& pos, const Vector3& pointDirection, double cutOffAngleDegrees, const Color3& color, double constAtt = 1, double linAtt = 0, double quadAtt = 0, bool specular = true, bool diffuse = true);
    bool operator==(const GLight& other) const;
    bool operator!=(const GLight& other) const;
};

template<class T> class Array {
 T* data;int num,numAllocated;
public:
 int size()const{return num;}
 T& operator[](int n){return data[n];}
 const T& operator[](int n)const{return data[n];}
 void sort(bool (__cdecl *lessThan)(const T&,const T&)){std::sort(data,data+num,lessThan);}
 void append(const T&);
 void resize(int,bool);
 ~Array();
 Array&operator=(const Array&);
};
class LightingParameters { public: LightingParameters& operator=(const LightingParameters&);
public:
    Color3                  emissiveScale;
    Color3                  skyAmbient;
    Color3                  diffuseAmbient;
    Color3                  lightColor;
    Color3                  ambient;
    Vector3                 lightDirection;
    enum {SUN, MOON}        source;
    bool                    physicallyCorrect;
    Vector3		            trueSunPosition;
    Vector3                 sunPosition;
    Vector3		            trueMoonPosition;
    Vector3                 moonPosition;
	double			        moonPhase;	
    CoordinateFrame	        starFrame;
	CoordinateFrame		    trueStarFrame;
    Vector3		            starVec;
    float                   geoLatitude;
    LightingParameters();
     LightingParameters(
	     const double     _time,
	     bool 	            _physicallyCorrect = true,
	     float              _latitude = 41.7333f);
    void setTime(const double _time);
	void setLatitude(float _latitude);
    GLight directionalLight() const;
};
class Lighting : public ReferenceCountedObject {
private:
    Lighting();
public:
    Color3              emissiveScale;
    Color3              ambientTop;
    Color3              ambientBottom;
    TextureRef          environmentMap;
    Color3              environmentMapColor;
    Array<GLight>       lightArray;
    Array<GLight>       shadowedLightArray;
    static ReferenceCountedPointer<Lighting> create();
Lighting&operator=(const Lighting&);
};

class ToneMap {public:
 void setEnabled(bool);
 ReferenceCountedPointer<Lighting> prepareLighting(const ReferenceCountedPointer<Lighting>&)const;
 LightingParameters prepareLightingParameters(const LightingParameters&)const;
};
int glGetInteger(unsigned int);
inline const double& inf(){static const double i=std::numeric_limits<double>::infinity();return i;}
}
typedef char glight_size[sizeof(G3D::GLight)==80?1:-1];
typedef char lighting_size[sizeof(G3D::Lighting)==88?1:-1];
typedef char lighting_array_offset[offsetof(G3D::Lighting,lightArray)==0x40?1:-1];
typedef char lighting_parameters_size[sizeof(G3D::LightingParameters)==248?1:-1];
bool brighter(const G3D::GLight& A, const G3D::GLight& B);

namespace RBX {
namespace Render {

class EffectSettings
{
private:
    bool _stencilShadows;
    bool _alphaBlendShadowLights;
    bool _useAllLightsInUnshadowedPass;
    bool _skyBox;
    bool _toneMap;
    bool _hemisphereLighting;
    bool _depthBlur;
    float _farCullZ;
    float _groundLOD;
    float _LODShift;

public:
    static G3D::ToneMap* getToneMap();

    G3D::ReferenceCountedPointer<G3D::Lighting> update(
        float shadingDetail,
        float meshDetail,
        bool shadows,
        float cameraDistanceFromCharacters,
        const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
        const G3D::LightingParameters& desiredSkyParameters,
        G3D::LightingParameters& outSkyParameters);
};

G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
    float shadingDetail,
    float meshDetail,
    bool shadows,
    float cameraDistanceFromCharacters,
    const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
    const G3D::LightingParameters& desiredSkyParameters,
    G3D::LightingParameters& outSkyParameters)
{
    int lightCount = desiredLighting->lightArray.size();
    int shadowLightCount = desiredLighting->shadowedLightArray.size();
    int numShadowLights = shadowLightCount >= 8 ? 8 : shadowLightCount;
    int maxLights = G3D::glGetInteger(0xd31) - 3;
    int numNonShadowLights = lightCount >= maxLights ? maxLights : lightCount;
    numNonShadowLights = numNonShadowLights > 0 ? numNonShadowLights : 0;

    _groundLOD = 1.0f;
    _LODShift = 0.0f;
    _skyBox = false;
    _alphaBlendShadowLights = true;
    _stencilShadows = false;
    _useAllLightsInUnshadowedPass = false;
    _toneMap = false;
    _hemisphereLighting = false;
    _depthBlur = false;
    _farCullZ = -G3D::inf();

    G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
    *lighting = *desiredLighting;

    G3D::glGetInteger(0xd57);

    if (shadingDetail >= 10) {
        _skyBox = true;
    }

    _groundLOD = meshDetail * 0.01f;

    if (shadingDetail >= 30.0f) {
        _hemisphereLighting = true;
    }

    _LODShift = meshDetail * 0.02f - 1.0f;

    if (shadows && numShadowLights > 0) {
        _stencilShadows = true;
        numShadowLights = 1;

        if (numNonShadowLights == 0) {
            _alphaBlendShadowLights = false;
        }
    }

    lighting->shadowedLightArray.sort(brighter);

    int excessShadowLights = lighting->shadowedLightArray.size() - numShadowLights;

    if (excessShadowLights > 0) {
        for (int i = 0; i < excessShadowLights; i++) {
            lighting->lightArray.append(
                lighting->shadowedLightArray[lighting->shadowedLightArray.size() - excessShadowLights + i]);
        }

        lighting->shadowedLightArray.resize(lighting->shadowedLightArray.size() - excessShadowLights, true);
    }

    lighting->lightArray.sort(brighter);

    int excessLights = lighting->lightArray.size() - numNonShadowLights;

    if (excessLights > 0) {
        lighting->lightArray.resize(lighting->lightArray.size() - excessLights, true);
    }

    _useAllLightsInUnshadowedPass = _stencilShadows == false;

    for (int i = 0; i < lighting->lightArray.size(); i++) {
        G3D::GLight& l = lighting->lightArray[i];
        l.color *= 1.0f;
    }
    for (int i = 0; i < lighting->shadowedLightArray.size(); i++) {
        G3D::GLight& l = lighting->shadowedLightArray[i];
        l.color *= 1.0f;
    }

    if (_toneMap) {
        getToneMap()->setEnabled(true);
        lighting = getToneMap()->prepareLighting(lighting);
        outSkyParameters = getToneMap()->prepareLightingParameters(desiredSkyParameters);
    }
    else {
        outSkyParameters = desiredSkyParameters;
    }

    return lighting;
}

}
}


