// Real PNG/JPEG decoding/encoding for Ogre's Codec interface. stb is pinned by
// setup_deps.py; no browser image placeholders or replacement sky assets.
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_JPEG
#define STBI_ONLY_PNG
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "OgreImageCodec.h"
#include "OgreDataStream.h"
#include "OgreException.h"
#include <fstream>

namespace Ogre {
class BrowserImageCodec : public ImageCodec {
    String extension;
    static void append(void* context, void* data, int size) {
        std::vector<unsigned char>& bytes = *static_cast<std::vector<unsigned char>*>(context);
        unsigned char* first = static_cast<unsigned char*>(data);
        bytes.insert(bytes.end(), first, first + size);
    }
public:
    BrowserImageCodec(const char* type) : extension(type) {}
    String getType() const { return extension; }
    DecodeResult decode(DataStreamPtr& input) const {
        MemoryDataStream encoded(input);
        int width, height, channels;
        stbi_uc* pixels = stbi_load_from_memory(encoded.getPtr(), encoded.size(), &width, &height, &channels, 4);
        if (!pixels) OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, stbi_failure_reason(), "BrowserImageCodec::decode");
        ImageData* metadata = new ImageData;
        metadata->width = width;
        metadata->height = height;
        metadata->format = PF_BYTE_RGBA;
        metadata->size = width * height * 4;
        MemoryDataStreamPtr decoded(new MemoryDataStream(metadata->size));
        std::memcpy(decoded->getPtr(), pixels, metadata->size);
        stbi_image_free(pixels);
        return DecodeResult(decoded, CodecDataPtr(metadata));
    }
    DataStreamPtr code(MemoryDataStreamPtr& input, CodecDataPtr& data) const {
        const ImageData* metadata = static_cast<const ImageData*>(data.getPointer());
        std::vector<unsigned char> rgba(metadata->width * metadata->height * 4), encoded;
        PixelBox source(metadata->width, metadata->height, 1, metadata->format, input->getPtr());
        PixelBox target(metadata->width, metadata->height, 1, PF_BYTE_RGBA, &rgba[0]);
        PixelUtil::bulkPixelConversion(source, target);
        int result = extension == "png"
            ? stbi_write_png_to_func(append, &encoded, metadata->width, metadata->height, 4, &rgba[0], metadata->width * 4)
            : stbi_write_jpg_to_func(append, &encoded, metadata->width, metadata->height, 4, &rgba[0], 90);
        if (!result) OGRE_EXCEPT(Exception::ERR_INTERNAL_ERROR, "Image encoding failed", "BrowserImageCodec::code");
        MemoryDataStreamPtr output(new MemoryDataStream(encoded.size()));
        std::memcpy(output->getPtr(), &encoded[0], encoded.size());
        return output;
    }
    void codeToFile(MemoryDataStreamPtr& input, const String& filename, CodecDataPtr& data) const {
        DataStreamPtr encoded = code(input, data);
        std::vector<char> bytes(encoded->size());
        encoded->read(&bytes[0], bytes.size());
        std::ofstream output(filename.c_str(), std::ios::binary);
        output.write(&bytes[0], bytes.size());
        if (!output) OGRE_EXCEPT(Exception::ERR_CANNOT_WRITE_TO_FILE, filename, "BrowserImageCodec::codeToFile");
    }
};
void registerBrowserImageCodecs() {
    static BrowserImageCodec png("png"), jpg("jpg"), jpeg("jpeg");
    Codec::registerCodec(&png);
    Codec::registerCodec(&jpg);
    Codec::registerCodec(&jpeg);
}
}
