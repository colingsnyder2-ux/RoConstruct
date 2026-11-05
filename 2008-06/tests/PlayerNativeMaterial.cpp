// Existing 007ad1a0/007ad230/007ad310/007ad760/007ad790/007ad8a0
// and 004f1a60 material-cache behavior, using measured real member types.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerNativeMaterial.h"
#include <boost/thread/once.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstddef>
namespace PlayerNativeMaterial {
typedef char MaterialBaseSize[sizeof(MaterialBase)==0x0c?1:-1];
typedef char MaterialSize[sizeof(Material)==0x18?1:-1];
typedef char MaterialLevels[offsetof(Material,levels)==0x0c?1:-1];
typedef char LevelBaseSize[sizeof(MaterialBase::Level)==4?1:-1];
typedef char LevelSize[sizeof(Material::Level)==0x38?1:-1];
typedef char LevelEmpty[offsetof(Material::Level,empty)==4?1:-1];
typedef char LevelMatte[offsetof(Material::Level,matteTexture)==8?1:-1];
typedef char LevelTexture[offsetof(Material::Level,texture)==0x0c?1:-1];
typedef char LevelColour[offsetof(Material::Level,colorValue)==0x10?1:-1];
typedef char LevelSpecular[offsetof(Material::Level,specularValue)==0x1c?1:-1];
typedef char LevelShiny[offsetof(Material::Level,shinyValue)==0x20?1:-1];
typedef char LevelReflectance[offsetof(Material::Level,reflectance)==0x24?1:-1];
typedef char LevelTransparency[offsetof(Material::Level,transparency)==0x28?1:-1];
typedef char LevelBackend[offsetof(Material::Level,backend)==0x2c?1:-1];
typedef char FactorySize[sizeof(MaterialFactory)==0x10?1:-1];
MaterialBase::Level::~Level(){} // Abstract interface owns no state (native RTTI/Level field4).
MaterialBase::~MaterialBase(){} // Intrusive reference lifetime belongs to genuine G3D base.
Material::Level::Level():empty(true),colorValue(G3D::Color3::white()),specularValue(0),shinyValue(0),reflectance(0),transparency(0){}
Material::Level::Level(TextureRef proxy,G3D::Color3 color,float specular,float shiny,float reflect,float transparent):
    empty(false),texture(proxy),colorValue(color),specularValue(specular),shinyValue(shiny),reflectance(reflect),transparency(transparent){}
Material::Level::~Level(){
    if(!backend.isNull()){
        Ogre::String name(backend->getName());
        Ogre::MaterialManager::getSingleton().remove(backend->getHandle());
        Ogre::LogManager::getSingleton().logMessage("RBX removed "+name,Ogre::LML_NORMAL,false);
    }
}
bool Material::Level::isEmptyLevel() const{return empty;}
G3D::TextureRef Material::Level::baseTexture(void* engine) const{return texture.isNull()?G3D::TextureRef():texture->resolve(engine);}
TextureRef Material::Level::baseTexture() const{return texture;}
void Material::Level::setBaseTexture(TextureRef proxy){texture=proxy;}
G3D::TextureRef Material::Level::matte(void* engine) const{return matteTexture.isNull()?G3D::TextureRef():matteTexture->resolve(engine);}
const G3D::Color3& Material::Level::color() const{return colorValue;}
float Material::Level::specular() const{return specularValue;}
float Material::Level::shiny() const{return shinyValue;}
float Material::Level::reflect() const{return reflectance;}
float Material::Level::transparent() const{return transparency;}
const MaterialBase::Level& Material::appendEmptyLevel(){return levels.next();}
const MaterialBase::Level& Material::appendLevel(G3D::Color3 color,float specular,float shiny,float reflect,float transparent){return appendLevel(TextureRef(),color,specular,shiny,reflect,transparent);}
const MaterialBase::Level& Material::appendLevel(TextureRef proxy,G3D::Color3 color,float specular,float shiny,float reflect,float transparent){
    levels.push_back(Level(proxy,color,specular,shiny,reflect,transparent));return levels.last();
}
int Material::levelCount() const{return levels.size();}
MaterialBase::Level& Material::getLevel(int index){return levels[index];}
const MaterialBase::Level* Material::detailLevel(float value) const{
    if(levelCount()==0)return 0;
    int index=value*levels.size();index=std::max(0,std::min(index,levels.size()-1));
    return levels[index].isEmptyLevel()?0:&levels[index];
}
bool Material::veryTransparent() const{return levels.size()>0 && levels[0].transparency>0.25f;}
bool Attributes::operator<(const Attributes& other) const{
    if(color.number<other.color.number)return true;
    if(color.number>other.color.number)return false;
    if(transparency<other.transparency)return true;
    if(transparency>other.transparency)return false;
    return reflectance<other.reflectance;
}
namespace {
struct Cache {
    std::map<Attributes,G3D::WeakReferenceCountedPointer<MaterialBase> > database,megaDatabase;
    boost::recursive_mutex mutex;
};
typedef char CacheSize[sizeof(Cache)==0x4c?1:-1];
typedef char CacheMega[offsetof(Cache,megaDatabase)==0x20?1:-1];
typedef char CacheMutex[offsetof(Cache,mutex)==0x40?1:-1];
Cache* cache;
boost::once_flag once=BOOST_ONCE_INIT;
void closeCache(){delete cache;}
void initializeCache(){cache=new Cache;std::atexit(closeCache);}
}
MaterialFactory::MaterialFactory(void* engine,const std::string& surfaces,const std::string& file,const std::string& mega){
    surfacesTexture=new TextureProxy(engine,surfaces,true);
    fileMeshTexture=new TextureProxy(engine,file,false);
    megaTexture=new MegaTextureProxy(engine,mega);
}
MaterialRef MaterialFactory::getMegaMaterial(Attributes attributes){
    boost::call_once(initializeCache,once);
    boost::recursive_mutex::scoped_lock lock(cache->mutex);
    Attributes filtered={RBX::BrickColor::defaultColor(),attributes.transparency,attributes.reflectance};
    MaterialRef material;
    std::map<Attributes,G3D::WeakReferenceCountedPointer<MaterialBase> >::iterator it=cache->megaDatabase.find(filtered);
    if(it!=cache->megaDatabase.end())material=it->second.createStrongPtr();
    if(material.isNull()){
        material=new Material;
        if(filtered.transparency==1.0f)material->appendEmptyLevel();
        else material->appendLevel(megaTexture,G3D::Color3::white(),0.9f,50.0f,filtered.reflectance,filtered.transparency);
        cache->megaDatabase[filtered]=material;
    }
    return material;
}
MaterialRef MaterialFactory::getMaterial(Attributes attributes){
    boost::call_once(initializeCache,once);
    boost::recursive_mutex::scoped_lock lock(cache->mutex);
    MaterialRef material;
    std::map<Attributes,G3D::WeakReferenceCountedPointer<MaterialBase> >::iterator it=cache->database.find(attributes);
    if(it!=cache->database.end())material=it->second.createStrongPtr();
    if(material.isNull()){
        TextureRef surfaces=surfacesTexture->shade(attributes.color.color3(),TextureRef());
        material=new Material;
        if(attributes.transparency==1.0f)material->appendEmptyLevel();
        else material->appendLevel(surfaces,G3D::Color3::white(),0.9f,50.0f,attributes.reflectance,attributes.transparency);
        cache->database[attributes]=material;
    }
    return material;
}
}
