// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewRbxGfxSkybox2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src a773549e | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include <winsock2.h>
#include "util/NativeContentProvider.h"
#include "RenderLib/ViewNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Lighting2008.h"
#include "v8datamodel/Sky.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbx/RbxSceneManager2008.h"
#include <OgreMaterialManager.h>
#include <OgreDataStream.h>
#include <OgreLogManager.h>
#include <OgreString.h>
#include <OgreSceneManager.h>
#include <G3D/GImage.h>
#include <windows.h>
// INFERRED: path-helper spellings; original direct callees 0055d0b0/0055c4c0.
namespace RBX { std::string nativeAssetPath(const char*); std::string nativeAssetFolder(); }
using namespace RBX;
static const char* const imageExtensions[] = {"JPG","BMP","TGA","PCX","ICO","PNG","PPM","PPM"};
static const char materialTemplate[] = "material %s\n{\n\ttechnique\n\t{\n\t\tpass\n\t\t{\n\t\t\tlighting off\n\t\t\tdepth_write off\n\t\t\ttexture_unit\n\t\t\t{\n\t\t\t\tcubic_texture %s %s %s %s %s %s separateUV\n\t\t\t\ttex_address_mode clamp\n\t\t\t}\n\t\t}\n\t}\n}\n";
void RBX::ViewNew::ViewRbxGfx::updateSkybox(Ogre::VisualEngine* engine)
{
    std::string filenames[6];
    DataModel* context = dataModel.get();
    Lighting* lighting = ServiceProvider::create<Lighting>(static_cast<ServiceProvider*>(context));
    ContentId up, left, right, back, front, down;
    if (!lighting->sky.get()) {
        up = ContentId::fromAssets("Sky\\null_plainsky512_up.jpg");
        left = ContentId::fromAssets("Sky\\null_plainsky512_lf.jpg");
        right = ContentId::fromAssets("Sky\\null_plainsky512_rt.jpg");
        back = ContentId::fromAssets("Sky\\null_plainsky512_bk.jpg");
        front = ContentId::fromAssets("Sky\\null_plainsky512_ft.jpg");
        down = ContentId::fromAssets("Sky\\null_plainsky512_dn.jpg");
    } else {
        up = lighting->sky->skyUp;
        down = lighting->sky->skyDn;
        left = lighting->sky->skyLf;
        right = lighting->sky->skyRt;
        front = lighting->sky->skyFt;
        back = lighting->sky->skyBk;
    }
    try {
        // Nullable create-service receiver is inlined at each call in the target.
        filenames[0] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(front);
        filenames[1] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(back);
        filenames[2] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(left);
        filenames[3] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(right);
        filenames[4] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(up);
        filenames[5] = ServiceProvider::create<ContentProvider>(static_cast<ServiceProvider*>(dataModel.get()))->getFile(down);
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
    std::string materialName = "rbxskybox" + engine->sceneManager->getName();
    char materialText[2048];
    _snprintf(materialText,sizeof(materialText),materialTemplate,materialName.c_str(),shortNames[1].c_str(),shortNames[0].c_str(),shortNames[2].c_str(),shortNames[3].c_str(),shortNames[4].c_str(),shortNames[5].c_str());
    Ogre::DataStreamPtr stream(new Ogre::MemoryDataStream(materialText,strlen(materialText)+1,false));
    if (Ogre::MaterialManager::getSingleton().resourceExists(materialName))
        Ogre::MaterialManager::getSingleton().remove(materialName);
    try {
        Ogre::MaterialManager::getSingleton().parseScript(stream,"General");
        Ogre::MaterialPtr material(Ogre::MaterialManager::getSingleton().getByName(materialName));
        // Target assigns a native string at scene-manager extension +8bbc.
        static_cast<Ogre::RbxSceneManager*>(engine->sceneManager)->mRbxSkyName = nativeAssetFolder()+"Sky\\";
        engine->sceneManager->setSkyBox(true,materialName,2700.0f);
    } catch (std::exception& e) {
        Ogre::LogManager::getSingleton().logMessage(std::string("RBX error in skybox: ")+e.what(),Ogre::LML_NORMAL,false);
    }
    if (originalNames[0] != "") {
        for (int i=0; i<6; ++i)
            MoveFileExA(originalNames[i].c_str(),filenames[i].c_str(),MOVEFILE_REPLACE_EXISTING);
    }
}
