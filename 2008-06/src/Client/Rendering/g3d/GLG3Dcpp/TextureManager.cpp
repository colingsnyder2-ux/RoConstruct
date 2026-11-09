/**
  @file TextureManager.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com
  @cite by Morgan McGuire & Peter Sibley

  @created 2003-11-25
  @edited  2005-02-24
*/

#include "GLG3D/TextureManager.h"

namespace G3D {

TextureManager::TextureManager(size_t _sizeHint) : size(0), sizeHint(_sizeHint) {}

unsigned int TextureManager::TextureArgs::hashCode() const {
    return 
        (int)format +
        (int)wrap + 
        (int)interpolate * 1027 +
        (int)dimension +
        ::hashCode(filename) +
        (int)brighten;
}


bool TextureManager::TextureArgs::operator==(const TextureArgs& other) const {
    return 
        (format         == other.format)        &&
        (wrap           == other.wrap)          &&
        (interpolate    == other.interpolate)   &&
        (filename       == other.filename)      &&
        (dimension      == other.dimension )    && 
        (brighten       == other.brighten);
}


void TextureManager::setMemorySizeHint(size_t _sizeHint){
    debugAssert(_sizeHint > 0 && _sizeHint < 1000*1024*1024);
    sizeHint = _sizeHint;
}

    
size_t TextureManager::memorySizeHint() const {
    return sizeHint;
}
    

size_t TextureManager::sizeInMemory() const {
    return size;
}

TextureRef TextureManager::findTexture(
									   const std::string&          filename, 
									   const TextureFormat*        desiredFormat,    
									   Texture::WrapMode           wrap,  
									   Texture::InterpolateMode    interpolate ,  
									   Texture::Dimension          dimension,  
									   double                      brighten)
{
	TextureArgs args(desiredFormat);

	args.filename       = filename;
	args.wrap           = wrap;
	args.interpolate    = interpolate;
	args.dimension      = dimension;
	args.brighten       = brighten;

	TextureRef texture;
	cache.get(args, texture);
	return texture;
}


bool TextureManager::cacheTexture(
					 TextureRef					texture,
					 const std::string&          filename, 
					 const TextureFormat*        desiredFormat,    
					 Texture::WrapMode           wrap,  
					 Texture::InterpolateMode    interpolate ,  
					 Texture::Dimension          dimension,  
					 double                      brighten)
{
	TextureArgs args(desiredFormat);

	args.filename       = filename;
	args.wrap           = wrap;
	args.interpolate    = interpolate;
	args.dimension      = dimension;
	args.brighten       = brighten;

	if (cache.containsKey(args))
		return false;
	cache.set(args, texture);
	size += texture->sizeInMemory();
	checkCacheSize();
	return true;
}

TextureRef TextureManager::loadTexture(
    const std::string&          filename, 
    const TextureFormat*        desiredFormat,    
    Texture::WrapMode           wrap,  
    Texture::InterpolateMode    interpolate ,  
    Texture::Dimension          dimension,  
    double                      brighten) {

    TextureArgs args(desiredFormat);

    args.filename       = filename;
    args.wrap           = wrap;
    args.interpolate    = interpolate;
    args.dimension      = dimension;
    args.brighten       = brighten;

    if (! cache.containsKey(args)) {
        // Not in the cache, so we must load it        
        TextureRef texture = NULL;

        texture = Texture::fromFile(
            filename,
            desiredFormat,  
            wrap,
            interpolate,
            dimension,
            brighten);

        alwaysAssertM(texture != NULL, std::string("Texture not found ") + filename); 
        cache.set(args, texture);
        size += texture->sizeInMemory();
        checkCacheSize();
    }
    return cache[args];
}

void TextureManager::checkCacheSize() {
    if (size <= sizeHint) {
        return;
    }

    Array <TextureArgs> staleEntry;
    getStaleEntries(staleEntry);
    
    //To avoid thrashing we we remove entries in a random order
    staleEntry.randomize();

    while ((size > sizeHint) && (staleEntry.size() > 0)) {
        size -= cache[staleEntry.last()]->sizeInMemory();
        debugPrintf(" CheckCacheSize is removing %s   \n" , staleEntry.last().filename.c_str());
        cache.remove(staleEntry.pop());
    }
}

void TextureManager::emptyCache() {
    cache.clear();
    size = 0;
}


void TextureManager::trimCache() {
    Array <TextureArgs> staleEntry;
    getStaleEntries(staleEntry);
    for (int i = 0; i < staleEntry.length(); ++i) {
        size -= cache[staleEntry[i]]->sizeInMemory();
            debugPrintf("TrimCache is removing %s   \n" , staleEntry.last().filename.c_str());
        cache.remove(staleEntry[i]);
    }
}


void TextureManager::getStaleEntries(Array <TextureArgs>& staleEntry) {
    Table <TextureArgs, TextureRef>::Iterator current   = cache.begin();
    Table <TextureArgs, TextureRef>::Iterator end       = cache.end();
    // We cannot modify the hash table while we iterate over it. 
    // So we create a list of entries to be removed.
    while (current != end) {
        if (current->value.isLastReference()) {
            staleEntry.append(current->key);
        }
        ++current;
    }
}

}
