// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_processimage_e8b5aa72eb9630f4.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <exception>
struct Texture {
    void* data;
    int width;
    int height;
    int format;

    Texture(const std::string&, int);
    virtual ~Texture();
    void save(const std::string&, int);
};

int getFormat(const std::string&);
void resizeTexture(Texture&, std::string&);
void processTexture(const std::string&, std::string, int);

void processTexture(const std::string& source, std::string destination,
                    int maximumSize)
{
    int format = getFormat(source);
    if (format == 9)
        throw std::exception("unknown texture format");

    Texture texture(source, format);
    if (texture.width <= maximumSize && texture.height <= maximumSize) {
        if (destination != source)
            texture.save(destination, 5);
    } else {
        resizeTexture(texture, destination);
        processTexture(destination, destination, maximumSize);
    }
}
