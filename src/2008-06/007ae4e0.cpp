// from server: 100% by EspClaude
// true extent: 0x558 bytes (server extent 0x2df; was 0x378)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
#include <algorithm>

namespace Ogre {
typedef std::string String;
typedef unsigned long ResourceHandle;
enum LogMessageLevel { LML_TRIVIAL = 1, LML_NORMAL = 2, LML_CRITICAL = 3 };
enum PixelFormat { PF_BYTE_RGB = 11 };
class ManualResourceLoader;
typedef void NameValuePairList;

template<class T> class SharedPtr {
protected:
	T* pRep;
	unsigned int* pUseCount;
public:
	SharedPtr() : pRep(0), pUseCount(0) {}
	virtual ~SharedPtr() { release(); }
	inline T* operator->() const { return pRep; }
	inline bool isNull(void) const { return pRep == 0; }
protected:
	inline void release(void) {
		bool destroyThis = false;
		if (pUseCount) {
			if (--(*pUseCount) == 0) {
				destroyThis = true;
			}
		}
		if (destroyThis)
			destroy();
	}
	virtual void destroy(void);
};

class Image;
class __declspec(dllimport) Resource {
public:
	virtual ~Resource();
	char resourcePad[0x58];
	ResourceHandle mHandle;
	ResourceHandle getHandle(void) const { return mHandle; }
};
typedef SharedPtr<Resource> ResourcePtr;

class Texture : public Resource {
public:
	virtual void slot01(); virtual void slot02(); virtual void slot03(); virtual void slot04();
	virtual void slot05(); virtual void slot06(); virtual void slot07(); virtual void slot08();
	virtual void slot09(); virtual void slot10(); virtual void slot11(); virtual void slot12();
	virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
	virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
	virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
	virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28();
	virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32();
	virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36();
	virtual void slot37();
	virtual void loadImage(const Image& img);
};

class TexturePtr : public SharedPtr<Texture> {
public:
	__declspec(dllimport) TexturePtr& operator=(const ResourcePtr& r);
};

class TextureManager {
public:
	virtual ~TextureManager();
	virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual ResourcePtr create(const String& name, const String& group, bool isManual = false, ManualResourceLoader* loader = 0, const NameValuePairList* createParams = 0);
	virtual void slot05(); virtual void slot06(); virtual void slot07(); virtual void slot08();
	virtual void slot09(); virtual void slot10(); virtual void slot11(); virtual void slot12();
	virtual void slot13(); virtual void slot14();
	virtual void remove(ResourceHandle handle);
	virtual void slot16(); virtual void slot17(); virtual void slot18();
	virtual ResourcePtr getByName(const String& name);
	__declspec(dllimport) static TextureManager& getSingleton(void);
};

class Image {
public:
	enum Filter { FILTER_NEAREST, FILTER_LINEAR, FILTER_BILINEAR };
	__declspec(dllimport) Image();
	__declspec(dllimport) virtual ~Image();
	__declspec(dllimport) Image& loadDynamicImage(unsigned char* pData, size_t uWidth, size_t uHeight, size_t depth, PixelFormat eFormat, bool autoDelete = false, size_t numFaces = 1, size_t numMipMaps = 0);
	__declspec(dllimport) size_t getWidth(void) const;
	__declspec(dllimport) size_t getHeight(void) const;
	__declspec(dllimport) void resize(unsigned short width, unsigned short height, Filter filter = FILTER_BILINEAR);
private:
	char imagePad[0x28];
};

class LogManager {
public:
	__declspec(dllimport) static LogManager& getSingleton(void);
	__declspec(dllimport) void logMessage(const String& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);
};
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace G3D {
typedef unsigned char uint8;
class AtomicInt32 {
	volatile long m_value;
public:
	void increment() { InterlockedIncrement(&m_value); }
	long decrement() { return InterlockedDecrement(&m_value); }
};
class ReferenceCountedObject {
public:
	AtomicInt32 ReferenceCountedObject_refCount;
	void* ReferenceCountedObject_weakPointer;
	void ReferenceCountedObject_zeroWeakPointers();
	virtual ~ReferenceCountedObject();
};
template<class T> class ReferenceCountedPointer {
	T* m_pointer;
	void zeroPointer() {
		if (m_pointer != NULL) {
			if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
				m_pointer->ReferenceCountedObject_zeroWeakPointers();
				delete m_pointer;
			}
			m_pointer = NULL;
		}
	}
	void setPointer(T* x) {
		if (x != m_pointer) {
			zeroPointer();
			if (x != NULL) {
				m_pointer = x;
				m_pointer->ReferenceCountedObject_refCount.increment();
			}
		}
	}
public:
	ReferenceCountedPointer() : m_pointer(NULL) {}
	ReferenceCountedPointer(const ReferenceCountedPointer& r) : m_pointer(NULL) { setPointer(r.m_pointer); }
	~ReferenceCountedPointer() { zeroPointer(); }
	ReferenceCountedPointer& operator=(T* p) { setPointer(p); return *this; }
};
class Color3 { public: float r, g, b; };
class Color3uint8 {
public:
	uint8 r, g, b;
	Color3uint8() : r(0), g(0), b(0) {}
	Color3uint8(const uint8 _r, const uint8 _g, const uint8 _b) : r(_r), g(_g), b(_b) {}
	Color3uint8(const Color3& c);
};
class GImage {
public:
	enum Format { JPEG, BMP, TGA, PCX, ICO, PPM_ASCII, PPM, PNG, AUTODETECT, UNKNOWN };
	uint8* _byte;
	int width;
	int height;
	int channels;

	GImage(const std::string& filename, Format format = AUTODETECT);
	GImage(int width, int height, int channels = 3);
	virtual ~GImage();
	Color3uint8* pixel3() { return (Color3uint8*)_byte; }
	Color3uint8& pixel3(int x, int y) { return pixel3()[x + y * width]; }
};
class Texture : public ReferenceCountedObject {};
class RenderDevice;
}

namespace RBX {
class BrickColor {
	int number;
public:
	G3D::Color3 color3() const;
	static const std::vector<BrickColor>& colorPalette();
};

std::string stringify(double);

namespace Render {
class TextureProxyBase : public G3D::ReferenceCountedObject {
protected:
	std::string filename;
	int pad28;
	int pad2c;
};
class TextureProxy : public TextureProxyBase {
protected:
	G3D::ReferenceCountedPointer<G3D::Texture> texture;
	bool loaded;
	void* textureManager;
	bool tiled;
	G3D::ReferenceCountedPointer<TextureProxy> root;
	G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;
	G3D::Color3 shadeColor;
public:
	virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);
	static void shadePixel(const G3D::Color3uint8&, G3D::Color3uint8&);
};
}

namespace RenderNew {
class MegaTextureProxy : public Render::TextureProxy {
	Ogre::TexturePtr ogreTexture;
public:
	static const size_t numStrips = 32;
	virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);
};

G3D::ReferenceCountedPointer<G3D::Texture> MegaTextureProxy::resolve(G3D::RenderDevice* rd)
{
	if (!loaded) {
		MegaTextureProxy* self = this;
		size_t count = std::min(numStrips, BrickColor::colorPalette().size());

		G3D::GImage strip(filename, G3D::GImage::AUTODETECT);
		int atlasWidth = strip.width * numStrips;
		G3D::GImage atlas(atlasWidth, strip.height, 3);

		for (size_t i = 0; i < count; i++) {
			G3D::Color3uint8 color(BrickColor::colorPalette()[i].color3());

			G3D::Color3uint8 colorTable[256];
			for (size_t j = 0; j < 256; j++) {
				colorTable[j] = G3D::Color3uint8(j, j, j);
				shadePixel(color, colorTable[j]);
			}

			for (int x = 0; x < strip.width; x++) {
				for (int y = 0; y < strip.height; y++) {
					const G3D::Color3uint8& src = strip.pixel3(x, y);
					G3D::Color3uint8& dst = atlas.pixel3(x + i * strip.width, y);
					dst = colorTable[src.r];
				}
			}
		}

		const char* name = "TextureAtlas";
		ogreTexture = Ogre::TextureManager::getSingleton().getByName(name);

		if (ogreTexture.isNull()) {
			Ogre::Image image;
			image.loadDynamicImage(atlas._byte, atlas.width, atlas.height, 1, Ogre::PF_BYTE_RGB, false, 1, 0);

			while (true) {
				try {
					ogreTexture = Ogre::TextureManager::getSingleton().create(name, "General");
					ogreTexture->loadImage(image);
					break;
				}
				catch (...) {
					if (image.getWidth() > 512 || image.getHeight() > 512) {
						Ogre::TextureManager::getSingleton().remove(ogreTexture->getHandle());
						image.resize(image.getWidth() / 2, image.getHeight() / 2);
						Ogre::LogManager::getSingleton().logMessage(std::string("Error loading texture. Reduce size to ") + stringify(atlas.width) + "x" + stringify(atlas.height) + " and try again\n");
					}
					else {
						Ogre::LogManager::getSingleton().logMessage(std::string("Give up on loading texture ") + name);
						break;
					}
				}
			}
		}

		self->root = NULL;
		self->loaded = true;
	}

	return texture;
}
}
}
