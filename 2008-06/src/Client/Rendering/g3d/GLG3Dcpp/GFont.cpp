/**
 @file GFont.cpp
 
 @maintainer Morgan McGuire, morgan@graphics3d.com

 @created 2002-11-02
 @edited  2006-02-10
 */

#include "GLG3D/GFont.h"
#include "GLG3D/RenderDevice.h"
#include "GLG3D/TextureFormat.h"
#include "G3D/Vector2.h"
#include "G3D/System.h"
#include "G3D/fileutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

GFontRef GFont::fromFile(const std::string& filename) {
    if (! fileExists(filename)) {
        debugAssertM(false, format("Could not load font: %s", filename.c_str()));
        return NULL;
    }

    BinaryInput b(filename, G3D_LITTLE_ENDIAN, true);
    return new GFont(NULL, filename, b);
}

GFontRef GFont::fromFile(RenderDevice* _rd, const std::string& filename) {
    if (! fileExists(filename)) {
        debugAssertM(false, format("Could not load font: %s", filename.c_str()));
        return NULL;
    }

    BinaryInput b(filename, G3D_LITTLE_ENDIAN, true);
    return new GFont(_rd, filename, b);
}

GFontRef GFont::fromMemory(const std::string& name, const uint8* bytes, const int size) {
    BinaryInput b(bytes, size, G3D_LITTLE_ENDIAN, true, false); 
    return new GFont(NULL, name, b);
} 

GFont::GFont(RenderDevice* _rd, const std::string& filename, BinaryInput& b) : renderDevice(_rd) {

    debugAssertM(GLCaps::supports(TextureFormat::A8),
        "This graphics card does not support the GL_ALPHA8 texture format used by GFont.");
    debugAssertGLOk();

    int ver = b.readInt32();
    debugAssertM(ver == 1, "Can't read font files other than version 1");
    (void)ver;

    // Read the widths
    for (int c = 0; c < 128; ++c) {
        subWidth[c] = b.readUInt16();
    }

    baseline = b.readUInt16();
    int texWidth = b.readUInt16();
    charWidth  = texWidth / 16;
    charHeight = texWidth / 16;

    // The input may not be a power of 2
    int width  = ceilPow2(charWidth * 16);
    int height = ceilPow2(charHeight * 8);
  
    // Create a texture
    const uint8* ptr = ((uint8*)b.getCArray()) + b.getPosition();

    texture = 
        Texture::fromMemory(filename, &ptr,
            TextureFormat::A8, width, height, 1, TextureFormat::A8, 
            Texture::CLAMP, Texture::TRILINEAR_MIPMAP, Texture::DIM_2D,
            Texture::DEPTH_NORMAL, 1.0);
}


Vector2 GFont::texelSize() const {
    return Vector2(charWidth, charHeight);
}


Vector2 GFont::drawString(
    RenderDevice*       renderDevice,
    const std::string&  s,
    double              x,
    double              y,
    double              w,
    double              h,
    Spacing             spacing) const {

    debugAssert(renderDevice != NULL);
    const double propW = w / charWidth;
    const int n = s.length();

    // Shrink the vertical texture coordinates by 1 texel to avoid
    // bilinear interpolation interactions with mipmapping.
    float sy = h / charHeight;

    float x0 = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i] & 127; // s[i] % 128; avoid using illegal chars

        if (c != ' ') {
            int row   = c / 16;
            int col   = c & 15; // c % 16

            // Fixed width
            float sx = 0;
            
            if (spacing == PROPORTIONAL_SPACING) {
                sx = (charWidth - subWidth[(int)c]) * propW * 0.5f;
            }

            float xx = x - sx;
            //renderDevice->setTexCoord(0, Vector2(col * charWidth, row * charHeight + 1));
            //renderDevice->sendVertex(Vector2(x - sx,     y + sy));
            glTexCoord2f(col * charWidth, row * charHeight + 1);
            glVertex2f(xx,     y + sy);

            //renderDevice->setTexCoord(0, Vector2(col * charWidth, (row + 1) * charHeight - 2));
            //renderDevice->sendVertex(Vector2(x- sx,      y + h - sy)); 
            glTexCoord2f(col * charWidth, (row + 1) * charHeight - 2);
            glVertex2f(xx,     y + h - sy); 

            xx += w;
            //renderDevice->setTexCoord(0, Vector2((col + 1) * charWidth - 1, (row + 1) * charHeight - 2));
            //renderDevice->sendVertex(Vector2(x + w - sx, y + h - sy)); 
            glTexCoord2f((col + 1) * charWidth - 1, (row + 1) * charHeight - 2);
            glVertex2f(xx, y + h - sy); 

            //renderDevice->setTexCoord(0, Vector2((col + 1) * charWidth - 1, row * charHeight + 1));
            //renderDevice->sendVertex(Vector2(x + w - sx, y + sy));            
            glTexCoord2f((col + 1) * charWidth - 1, row * charHeight + 1);
            glVertex2f(xx, y + sy);
                        
        }

        if (spacing == PROPORTIONAL_SPACING) {
            x += propW * subWidth[(int)c];
        } else {
            x += propW * subWidth[(int)'M'] * 0.85f;
        }
    }

    renderDevice->minGLStateChange(8 * n);
    renderDevice->minGLStateChange(8 * n);

    // TODO: update the RenderDevice state count
    return Vector2(x - x0, h);
}


Vector2 GFont::computePackedArray(
    const std::string&  s,
    double              x,
    double              y,
    double              w,
    double              h,
    Spacing             spacing,
    Vector2*            array) const {

    const double propW = w / charWidth;
    const int n = s.length();

    // Shrink the vertical texture coordinates by 1 texel to avoid
    // bilinear interpolation interactions with mipmapping.
    float sy = h / charHeight;

    float x0 = 0;

    const float mwidth = subWidth[(int)'M'] * 0.85f * propW;

    int count = -1;
    for (int i = 0; i < n; ++i) {
        char c = s[i] & 127; // s[i] % 128; avoid using illegal chars

        if (c != ' ') {
            int row   = c >> 4; // fast version of c / 16
            int col   = c & 15; // fast version of c % 16

            // Fixed width
            float sx = (spacing == PROPORTIONAL_SPACING) ?
                (charWidth - subWidth[(int)c]) * propW * 0.5f : 0.0f;

            float xx = x - sx;
            // Tex, Vert
            ++count;
            array[count].x = col * charWidth;
            array[count].y = row * charHeight + 1;

            ++count;
            array[count].x = xx;
            array[count].y = y + sy;

            
            ++count;
            array[count].x = col * charWidth;
            array[count].y = (row + 1) * charHeight - 2;
            
            ++count;
            array[count].x = xx;
            array[count].y = y + h - sy;


            xx += w;
            ++count;
            array[count].x = (col + 1) * charWidth - 1;
            array[count].y = (row + 1) * charHeight - 2;
            
            ++count;
            array[count].x = xx;
            array[count].y = y + h - sy;
    

            ++count;
            array[count].x = (col + 1) * charWidth - 1;
            array[count].y = row * charHeight + 1;

            ++count;
            array[count].x = xx;
            array[count].y = y + sy;
        }

        x += (spacing == PROPORTIONAL_SPACING) ?
            propW * subWidth[(int)c] : mwidth;
    }

    return Vector2(x - x0, h);
}


Vector2 GFont::draw2D(
    RenderDevice*               renderDevice,
    const std::string&          s,
    const Vector2&              pos2D,
    double                      size,
    const Color4&               color,
    const Color4&               border,
    XAlign                      xalign,
    YAlign                      yalign,
    Spacing                     spacing) const {

	debugAssert(renderDevice != NULL);

    float x = pos2D.x;
    float y = pos2D.y;

    float h = size * 1.5f;
    float w = h * charWidth / charHeight;

    switch (xalign) {
    case XALIGN_RIGHT:
        x -= get2DStringBounds(s, size, spacing).x;
        break;

    case XALIGN_CENTER:
        x -= get2DStringBounds(s, size, spacing).x / 2;
        break;
    
    default:
        break;
    }

    switch (yalign) {
    case YALIGN_CENTER:
        y -= h / 2.0;
        break;

    case YALIGN_BASELINE:
        y -= baseline * h / (double)charHeight;
        break;

    case YALIGN_BOTTOM:
        y -= h;
        break;

    default:
        break;
    }

    float m[] = 
       {1.0f / texture->getTexelWidth(), 0, 0, 0,
        0, 1.0f / texture->getTexelHeight(), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};

    renderDevice->pushState();
        renderDevice->disableLighting();
        renderDevice->setTextureMatrix(0, m);
        renderDevice->setTexture(0, texture);

        renderDevice->setTextureCombineMode(0, RenderDevice::TEX_MODULATE);

        // This is BLEND_SRC_ALPHA because the texture has no luminance, only alpha
        renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA,
				   RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);

        renderDevice->setAlphaTest(RenderDevice::ALPHA_GEQUAL, 1/255.0);

        const float b = renderDevice->getBrightScale();

        if (GLCaps::supports_GL_ARB_multitexture()) {
            glActiveTextureARB(GL_TEXTURE0_ARB);
        }


        int numChars = 0;
        for (unsigned int i = 0; i < s.length(); ++i) {
            numChars += ((s[i] % 128) != ' ') ? 1 : 0;
        }
        if (numChars == 0) {
            renderDevice->popState();
            return Vector2(0, h);
        }

        // Packed vertex array; tex coord and vertex are interlaced
        // For each character we need 4 vertices.

        // MSVC 6 cannot use static allocation with a variable size argument
        // so we revert to the more compiler specific alloca call. Gcc does not
        // implement array[variable] well, so we use this everywhere.
        Vector2* array = (Vector2*)System::malloc(numChars * 4 * 2 * sizeof(Vector2));

        const Vector2 bounds = computePackedArray(s, x, y, w, h, spacing, array);

        int N = numChars * 4;

        renderDevice->beforePrimitive();

        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);

        // 2 coordinates per element, float elements, stride (for interlacing), count, pointer
        glTexCoordPointer(2, GL_FLOAT, sizeof(Vector2) * 2, &array[0]);
        glVertexPointer(2, GL_FLOAT, sizeof(Vector2) * 2, &array[1]);

        if (border.a > 0.05f) {
            renderDevice->setColor(Color4(border.r * b, border.g * b, border.b * b, border.a));
            glMatrixMode(GL_MODELVIEW);
            float lastDx = 0, lastDy = 0;
            for (int dy = -1; dy <= 1; dy += 2) {
                for (int dx = -1; dx <= 1; dx += 2) {
                    if ((dx != 0) || (dy != 0)) {
                        // Shift modelview matrix by dx, dy, but also undo the 
                        // shift from the previous outline
                        glTranslatef(dx - lastDx, dy - lastDy, 0);
                        glDrawArrays(GL_QUADS, 0, N);
                        lastDx = dx; lastDy = dy;
                    }
                }
            }
            glTranslatef(-lastDx, -lastDy, 0);
        }

        // Draw foreground
        renderDevice->setColor(Color4(color.r * b, color.g * b, color.b * b, color.a));
        glDrawArrays(GL_QUADS, 0, N);

        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        renderDevice->afterPrimitive();
    renderDevice->popState();

    System::free(array);
    debugAssertGLOk();

    return bounds;
}


Vector2 GFont::draw3D(
    RenderDevice*               renderDevice,
    const std::string&          s,
    const CoordinateFrame&      pos3D,
    double                      size,
    const Color4&               color,
    const Color4&               border,
    XAlign                      xalign,
    YAlign                      yalign,
    Spacing                     spacing) const {
    
	debugAssert(renderDevice != NULL);

    double x = 0;
    double y = 0;

    double h = size * 1.5;
    double w = h * charWidth / charHeight;

    switch (xalign) {
    case XALIGN_RIGHT:
        x -= get2DStringBounds(s, size, spacing).x;
        break;

    case XALIGN_CENTER:
        x -= get2DStringBounds(s, size, spacing).x / 2;
        break;
    
    default:
        break;
    }

    switch (yalign) {
    case YALIGN_CENTER:
        y -= h / 2.0;
        break;

    case YALIGN_BASELINE:
        y -= baseline * h / (double)charHeight;
        break;

    case YALIGN_BOTTOM:
        y -= h;
        break;

    default:
        break;
    }


    double m[] = 
       {1.0 / texture->getTexelWidth(), 0, 0, 0,
        0, 1.0 / texture->getTexelHeight(), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};

    renderDevice->pushState();
        // We need to get out of Y=up coordinates.
        CoordinateFrame flipY;
        flipY.rotation[1][1] = -1;
        renderDevice->setObjectToWorldMatrix(pos3D * flipY);

        renderDevice->setCullFace(RenderDevice::CULL_NONE);
        renderDevice->setTextureMatrix(0, m);
        renderDevice->setTexture(0, texture);

        renderDevice->setTextureCombineMode(0, RenderDevice::TEX_MODULATE);
        renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, 
				   RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        renderDevice->setAlphaTest(RenderDevice::ALPHA_GEQUAL, 0.05);

        renderDevice->disableLighting();
        renderDevice->beginPrimitive(RenderDevice::QUADS);

            if (border.a > 0.05f) {

	        // Make the equivalent of a 3D "1 pixel" offset (the
	        // default 2D text size is 12-pt with a 1pix border)

 	        const double borderOffset = size / 12.0;
                renderDevice->setColor(border);
                for (int dy = -1; dy <= 1; dy += 2) {
                    for (int dx = -1; dx <= 1; dx += 2) {
                        if ((dx != 0) || (dy != 0)) {
                            drawString(renderDevice, s,
				               x + dx * borderOffset, 
				               y + dy * borderOffset,
				               w, h, spacing);
                        }
                    }
                }
            }

            renderDevice->setColor(
		        Color4(color.r * renderDevice->getBrightScale(),
			       color.g * renderDevice->getBrightScale(), 
			       color.b * renderDevice->getBrightScale(), 
			       color.a));
            Vector2 bounds = drawString(renderDevice, s, x, y, w, h, spacing);

        renderDevice->endPrimitive();

    renderDevice->popState();

    return bounds;
}


Vector2 GFont::get2DStringBounds(
    const std::string&  s,
    double              size,
    Spacing             spacing) const {

    int n = s.length();

    double h = size * 1.5;
    double w = h * charWidth / charHeight;
    double propW = w / charWidth;
    double x = 0;
    double y = h;

    if (spacing == PROPORTIONAL_SPACING) {
        for (int i = 0; i < n; ++i) {
            char c   = s[i] & 127;
            x += propW * subWidth[(int)c];
        }
    } else {
        x = subWidth[(int)'M'] * n * 0.85 * propW;
    }

    return Vector2(x, y);
}


void GFont::convertRAWINItoPWF(const std::string& infileBase, std::string outfile) {
    debugAssert(fileExists(infileBase + ".raw"));
    debugAssert(fileExists(infileBase + ".ini"));

    if (outfile == "") {
        outfile = infileBase + ".fnt";
    }

    BinaryInput  pixel(infileBase + ".raw", G3D_LITTLE_ENDIAN);
    TextInput    ini(infileBase + ".ini");
    BinaryOutput out(outfile, G3D_LITTLE_ENDIAN);

    ini.readSymbol("[");
    ini.readSymbol("Char");
    ini.readSymbol("Widths");
    ini.readSymbol("]");

    // Version
    out.writeInt32(1);

    // Character widths
    for (int i = 0; i < 128; ++i) {
        int n = (int)ini.readNumber();
        (void)n;
        debugAssert(n == i);
        ini.readSymbol("=");
        int cw = (int)ini.readNumber();
        out.writeInt16(cw);
    }

    int width = (int)sqrt((double)pixel.size());
    
    // Autodetect baseline from capital E
    {
        // Size of a character, in texels
        int          w        = width / 16;

        int          x0       = ('E' % 16) * w;
        int          y0       = ('E' / 16) * w;
        
        const uint8* p        = pixel.getCArray();
        bool         done     = false;
        int          baseline = w * 2 / 3;
    
        // Search up from the bottom for the first pixel
        for (int y = y0 + w - 1; (y >= y0) && ! done; --y) {
            for (int x = x0; (x < x0 + w) && ! done; ++x) {
                if (p[x + y * w * 16] != 0) {
                    baseline = y - y0 + 1;
                    done = true;
                }
            }
        }
        out.writeUInt16(baseline);
    }

    // Texture width
    out.writeUInt16(width);

    // The input may not be a power of 2, so size it up
    int width2  = ceilPow2(width);
    int height2 = ceilPow2(width / 2);

    if ((width2 == width) && (height2 == (width/2))) {
        // Texture
        int num = width * (width / 2);
        out.writeBytes(pixel.getCArray(), num);
    } else {
        // Pad
        const uint8* ptr = pixel.getCArray();
    
//        int num = width * (width / 2);
        for (int y = 0; y < height2; ++y) {
            // Write the row
            out.writeBytes(ptr, width);
            ptr += width;

            // Write the horizontal padding
            out.skip(width2 - width);
        }

        // Write the vertical padding
        out.skip((height2 - (width / 2)) * width2);
    }
 
    out.compress();
    out.commit(false);
}

}
