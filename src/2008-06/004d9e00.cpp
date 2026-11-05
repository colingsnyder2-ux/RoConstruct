// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5 roc_claudeL_a8c771929549b29e.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#define _DLL 1
#define _CPPUNWIND 1
#include <windows.h>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "OgreSceneManager.h"
#include "OgreMaterialManager.h"
#include "OgreMaterial.h"
#include "OgreDataStream.h"
#include "OgreLogManager.h"
#include "OgreString.h"
namespace RBX {
// Receiver-only declaration of the native Name lookup; no Name object is created.
class Name {public: static const Name& getNullName();};
	class ContentId
	{
	private:
		std::string id;
		const Name* mimeTypePtr;

	public:
		ContentId()
			: id(), 
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const char* id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id, const Name& mimeType)
			: id(id),
			  mimeTypePtr(&mimeType)
		{
		}

	public:
		const Name& mimeType() const
		{
			return *mimeTypePtr;
		}
		const char* c_str() const
		{
			return id.c_str();
		}
		const std::string& toString() const
		{
			return id;
		}
		bool isNull() const
		{
			return id.empty();
		}
		bool isFile() const
		{
			return id.substr(0, 7) == "file://";
		}
		bool isAsset() const
		{
			return id.substr(0, 11) == "rbxasset://";
		}
		bool isHttp() const
		{
			return id.substr(0, 4) == "http";
		}

	public:
		static ContentId fromUrl(const std::string&);
		static ContentId fromFile(const std::string&);
		static ContentId fromAssets(const char* filePath); // 0055bd80 reads caller C string directly
		static ContentId fromMD5Hash(const std::string&);
	};

}
typedef char native_content_extent[sizeof(RBX::ContentId)==32?1:-1];
typedef char native_stream_extent[sizeof(Ogre::MemoryDataStream)==52?1:-1];
// Binary reconstruction of the 2008 renderer; later renderer code is reference only.
namespace RBX {
class NativeLighting;
class ContentProvider { public: std::string getFile(ContentId); };
class NativeServiceContext { public: NativeLighting* lighting(); ContentProvider* content(); };
inline ContentProvider* nativeContentProvider(NativeServiceContext* context) {return context ? context->content() : NULL;}
class NativeVisualEngine;
class NativeView { public: void updateSkybox(NativeVisualEngine* engine); };
std::string nativeAssetPath(const char* path); // 0055d0b0
std::string nativeAssetFolder(); // 0055c4c0
}
namespace G3D {
class GImage { public:
    enum Format {JPEG, BMP, TGA, PCX, ICO, PNG, PPM_ASCII, PPM, AUTODETECT, UNKNOWN};
    static Format resolveFormat(const std::string& filename);
};
}
static const char* const imageExtensions[] = {"JPG","BMP","TGA","PCX","ICO","PNG","PPM","PPM"};
static const char materialTemplate[] = "material %s\n{\n\ttechnique\n\t{\n\t\tpass\n\t\t{\n\t\t\tlighting off\n\t\t\tdepth_write off\n\t\t\ttexture_unit\n\t\t\t{\n\t\t\t\tcubic_texture %s %s %s %s %s %s separateUV\n\t\t\t\ttex_address_mode clamp\n\t\t\t}\n\t\t}\n\t}\n}\n";
namespace RBX {
// Sky ContentId fields at 0x130 + 32*k, proven by the target's six offsets.
struct NativeSkyFields { char observed[0x130]; ContentId skyUp, skyLeft, skyRight, skyBack, skyFront, skyDown; };
inline NativeSkyFields* nativeSky(NativeLighting* l) { return *reinterpret_cast<NativeSkyFields**>(reinterpret_cast<char*>(l)+0x2d4); }
void NativeView::updateSkybox(NativeVisualEngine* engine)
{
    std::string filenames[6];
    NativeServiceContext* context = *reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14);
    NativeLighting* lighting = context ? context->lighting() : NULL;
    ContentId up, left, right, back, front, down;
    if (!*reinterpret_cast<void**>(reinterpret_cast<char*>(lighting)+0x2d4)) {
        up = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
        left = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
        right = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
        back = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
        front = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
        down = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
    } else {
        up = nativeSky(lighting)->skyUp;
        down = nativeSky(lighting)->skyDown;
        left = nativeSky(lighting)->skyLeft;
        right = nativeSky(lighting)->skyRight;
        front = nativeSky(lighting)->skyFront;
        back = nativeSky(lighting)->skyBack;
    }
    try {
        // Nullable create-service receiver is inlined at each call in the target.
        filenames[0] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(front);
        filenames[1] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(back);
        filenames[2] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(left);
        filenames[3] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(right);
        filenames[4] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(up);
        filenames[5] = nativeContentProvider(*reinterpret_cast<NativeServiceContext**>(reinterpret_cast<char*>(this)+0x14))->getFile(down);
    } catch (...) {
        filenames[0] = nativeAssetPath("Sky\\null_plainsky512_ft.jpg");
        filenames[1] = nativeAssetPath("Sky\\null_plainsky512_bk.jpg");
        filenames[2] = nativeAssetPath("Sky\\null_plainsky512_lf.jpg");
        filenames[3] = nativeAssetPath("Sky\\null_plainsky512_rt.jpg");
        filenames[4] = nativeAssetPath("Sky\\null_plainsky512_up.jpg");
        filenames[5] = nativeAssetPath("Sky\\null_plainsky512_dn.jpg");
    }
    std::string originalNames[6];
    std::string basename, directory;
    Ogre::StringUtil::splitFilename(filenames[0], basename, directory);
    if (basename.find(".") == std::string::npos) {
        G3D::GImage::Format format = G3D::GImage::resolveFormat(filenames[0]);
        std::string extension;
        if (format >= 0 && format < sizeof(imageExtensions)/sizeof(imageExtensions[0]))
            extension = std::string(".") + imageExtensions[format];
        else
            extension = ".raw";
        for (int i=0; i<6; ++i) {
            originalNames[i] = filenames[i] + extension;
            MoveFileExA(filenames[i].c_str(), originalNames[i].c_str(), MOVEFILE_REPLACE_EXISTING);
            filenames[i] = originalNames[i];
        }
    }
    std::string shortNames[6];
    char shortPath[1024];
    for (int i=0; i<6; ++i) {
        GetShortPathNameA(filenames[i].c_str(),shortPath,sizeof(shortPath));
        shortNames[i] = shortPath;
    }
    std::string materialName = "rbxskybox" + (*reinterpret_cast<Ogre::SceneManager**>(reinterpret_cast<char*>(engine)+4))->getName();
    char materialText[2048];
    _snprintf(materialText,sizeof(materialText),materialTemplate,materialName.c_str(),shortNames[1].c_str(),shortNames[0].c_str(),shortNames[2].c_str(),shortNames[3].c_str(),shortNames[4].c_str(),shortNames[5].c_str());
    Ogre::DataStreamPtr stream(new Ogre::MemoryDataStream(materialText,strlen(materialText)+1,false));
    if (Ogre::MaterialManager::getSingleton().resourceExists(materialName))
        Ogre::MaterialManager::getSingleton().remove(materialName);
    try {
        Ogre::MaterialManager::getSingleton().parseScript(stream,"General");
        Ogre::MaterialPtr material(Ogre::MaterialManager::getSingleton().getByName(materialName));
        // Target assigns a native string at scene-manager extension +8bbc.
        *reinterpret_cast<std::string*>(reinterpret_cast<char*>(*reinterpret_cast<Ogre::SceneManager**>(reinterpret_cast<char*>(engine)+4))+0x8bbc) = nativeAssetFolder()+"Sky\\";
        (*reinterpret_cast<Ogre::SceneManager**>(reinterpret_cast<char*>(engine)+4))->setSkyBox(true,materialName,2700.0f);
    } catch (std::exception& e) {
        Ogre::LogManager::getSingleton().logMessage(std::string("RBX error in skybox: ")+e.what(),Ogre::LML_NORMAL,false);
    }
    if (originalNames[0] != "") {
        for (int i=0; i<6; ++i)
            MoveFileExA(originalNames[i].c_str(),filenames[i].c_str(),MOVEFILE_REPLACE_EXISTING);
    }
}
}
