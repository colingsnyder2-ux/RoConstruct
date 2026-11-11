// Recovered004d9e00 default-face material and Ogre setup; file root is explicit.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerSkybox.h"
#include <cstdio>
#include <cstring>
#include <stdexcept>
namespace PlayerSkybox {
void apply(Ogre::SceneManager& manager,const std::string& contentRoot){
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(contentRoot+"/sky","FileSystem","General");
    // Native template order is back,front,left,right,up,down (separate UV faces).
    static const char* const faces[]={"null_plainsky512_bk.jpg","null_plainsky512_ft.jpg",
        "null_plainsky512_lf.jpg","null_plainsky512_rt.jpg","null_plainsky512_up.jpg","null_plainsky512_dn.jpg"};
    for(int i=0;i<6;++i)if(!Ogre::ResourceGroupManager::getSingleton().resourceExists("General",faces[i]))
        throw std::runtime_error(std::string("missing sky face: ")+faces[i]);
    std::string name="rbxskybox"+manager.getName();
    char text[2048];
    _snprintf(text,sizeof(text),"material %s\n{\n\ttechnique\n\t{\n\t\tpass\n\t\t{\n\t\t\tlighting off\n\t\t\tdepth_write off\n\t\t\ttexture_unit\n\t\t\t{\n\t\t\t\tcubic_texture %s %s %s %s %s %s separateUV\n\t\t\t\ttex_address_mode clamp\n\t\t\t}\n\t\t}\n\t}\n}\n",
        name.c_str(),faces[0],faces[1],faces[2],faces[3],faces[4],faces[5]);
    Ogre::DataStreamPtr stream(new Ogre::MemoryDataStream(text,std::strlen(text)+1,false));
    Ogre::MaterialManager& materials=Ogre::MaterialManager::getSingleton();
    if(materials.resourceExists(name))materials.remove(name);
    materials.parseScript(stream,"General");
    manager.setSkyBox(true,name,2700.0f);
    // Period G3D polar faces use a different UV basis from stock Ogre planes.
    // Match their cloud edges without changing the original image files.
    Ogre::MaterialPtr up=materials.getByName(manager.getName()+"SkyBoxPlane4"),down=materials.getByName(manager.getName()+"SkyBoxPlane5");
    up->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureRotate(Ogre::Degree(90));
    down->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureRotate(Ogre::Degree(-90));
    std::printf("skybox: original=004d9e00 material=%s faces=6 distance=2700\n",name.c_str());
}
}
