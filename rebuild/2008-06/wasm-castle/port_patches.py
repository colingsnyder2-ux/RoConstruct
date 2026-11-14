"""Explicit browser backend adaptations; only generated copies are changed."""
import re
import shutil

def native_headers(root, output):
    shutil.copytree(root / 'rebuild/2008-06/native-headers', output, dirs_exist_ok=True)
    for path in output.rglob('*.h'):
        text = path.read_text(errors='replace')
        # These assert the original MSVC object ABI, not portable C++ semantics.
        # Every ported class and its dependencies are rebuilt for the Wasm ABI.
        text = re.sub(r'typedef char\s+[^;]+;',
            lambda m: '#ifndef __EMSCRIPTEN__\n' + m.group() + '\n#endif', text)
        if path.name == 'VisualEngine2008.h':
            text = text.replace('#include <windows.h>', '#include <cstdint>\ntypedef void* HWND;\ntypedef uint32_t DWORD;')
        if 'std::exception("' in text:
            text = '#include <stdexcept>\n' + text.replace('std::exception("', 'std::runtime_error("')
        path.write_text(text)
    # Only the static tint operation is linked, never a TextureProxy object.
    (output / 'RenderLib/TextureShadeWasm.h').write_text(
        '#pragma once\n#include <G3D/Color3uint8.h>\nnamespace RBX { namespace RenderNew {\n'
        'class TextureProxy { public: static void shadePixel(const G3D::Color3uint8&,G3D::Color3uint8&); };\n}}\n')

def g3d_headers(root, output):
    shutil.copytree(root / 'tools/rbxgs/Client/Rendering/g3d/include', output, dirs_exist_ok=True)
    platform = output / 'G3D/platform.h'
    text = platform.read_text().replace('#elif __linux__', '#elif defined(__EMSCRIPTEN__) || __linux__')
    text = text.replace('#   ifndef __i386__', '#   if !defined(__i386__) && !defined(__EMSCRIPTEN__)')
    platform.write_text(text)
    atomic = output / 'G3D/AtomicInt32.h'
    text = atomic.read_text()
    for signature, code in (
        ('inline int32 add(', 'return __atomic_fetch_add(&_value, x, __ATOMIC_SEQ_CST);'),
        ('inline void increment(', '__atomic_add_fetch(&_value, 1, __ATOMIC_SEQ_CST);'),
        ('inline uint32 decrement(', 'return __atomic_sub_fetch(&_value, 1, __ATOMIC_SEQ_CST) != 0;'),
        ('inline int32 compareAndSet(', '''int32 old = comperand;
        __atomic_compare_exchange_n(&_value, &old, exchange, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
        return old;''')):
        text = body(text, signature, code)
    atomic.write_text(text)
    system = output / 'G3D/System.h'
    text = system.read_text()
    text = '#include <emscripten/emscripten.h>\n' + text
    text = text.replace('#ifdef _MSC_VER\n    inline uint64 System::getCycleCount()',
        '#if defined(__EMSCRIPTEN__)\n'
        '    // Browser has no CPU cycle counter. Use monotonic nanoseconds.\n'
        '    inline uint64 System::getCycleCount() { return uint64(emscripten_get_now() * 1000000.0); }\n'
        '#elif defined(_MSC_VER)\n    inline uint64 System::getCycleCount()')
    system.write_text(text)
    gl = output / 'GLG3D/glheaders.h'
    original = gl.read_text()
    gl.write_text('#if defined(__EMSCRIPTEN__)\n'
        '// Ogre owns the browser GL loader; do not redeclare G3D desktop extension globals.\n'
        '#include "OgreGLPrerequisites.h"\n#else\n' + original + '\n#endif\n')

def native_source(name, text):
    if name == 'TextureShadePixel2008.cpp':
        text = text.replace('RenderLib/TextureProxy2008.h', 'RenderLib/TextureShadeWasm.h')
    text = text.replace('#include "OgreRbxEntityImports/OgreVector3.h"', '#include <OgreVector3.h>')
    if name == 'OgreRbxSceneManager.cpp':
        # DLL and executable originally each carried this identical asset. A
        # static Wasm link shares OgreMain's actual array rather than defining it twice.
        text = text.replace('#include "OgreSpotShadowFadePng.h"',
            'namespace Ogre { extern unsigned char SPOT_SHADOW_FADE_PNG[9728]; }\n'
            '#define SPOT_SHADOW_FADE_PNG_SIZE sizeof(Ogre::SPOT_SHADOW_FADE_PNG)')
    if name == 'OgreVisualEngine.cpp':
        functions = []
        for signature in ('void releaseUnusedResources(', 'void dumpResources('):
            start = text.index(signature)
            first = text.index('{', start)
            end, depth = first + 1, 1
            while depth:
                depth += (text[end] == '{') - (text[end] == '}')
                end += 1
            functions.append(text[start:end])
        start = text.index('FrameHistory::FrameHistory()')
        end = text.index('static __forceinline bool has32BitMode', start)
        # Compile actual recovered portable lifetimes/history/resource bodies.
        # Windows device enumeration and DLL initialization are replaced by the
        # browser entry, not emitted as fake VisualEngine methods.
        text = '''#include <Ogre.h>
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
#include <boost/thread/once.hpp>
namespace Ogre {
Root* sRoot = 0;
''' + '\n'.join(functions) + '\n' + text[start:end] + '\n}\n'
    # These trailing explicit instantiations request MSVC-only COMDATs for byte
    # matching. Clang emits the real template members needed by its own ABI.
    text = re.sub(r'^template [^;{]+;', '', text, flags=re.MULTILINE)
    text = '#include <stdexcept>\n' + text.replace('std::exception("', 'std::runtime_error("')
    # Xlib's global macro collides with Ogre's scoped Status enum. The browser
    # never uses Xlib; prevent its transitive declarations leaking into Ogre.
    text = re.sub(r'(#include[^\n]+)', r'\1\n#undef Status\n#undef TIME_UTC\ntypedef int Status;', text)
    if name == 'G3DSystem.cpp':
        # Obsolete STREAMS terminal header is not used by this source.
        text = text.replace('#include <stropts.h>', '')
    return text

def castle_entry(root, template, output):
    source = (root / 'work/wasm-castle/native-reference/source/ogre_demo.cpp').read_text()
    prefix = source[:source.index('int main(')]
    prefix = prefix.replace('#include <windows.h>', '').replace('WNDPROC previousProc;', '')
    prefix = '#include "OgreGLPrerequisites.h"\n' + prefix.replace('#include <GL/gl.h>', '')
    first = prefix.index('LRESULT CALLBACK demoProc(')
    last = prefix.index('// Native GeometryBuilder', first)
    prefix = prefix[:first] + prefix[last:]
    prefix = prefix.replace('    void skyLighting(',
        '    float capDepthBias=0;\n'
        '    void stencilBias(float bias) {capDepthBias=bias;}\n'
        '    void skyLighting(')
    prefix = prefix.replace('        Ogre::SceneManager::renderSingleObject(renderable,pass,iterate,lights);',
        '        bool stencil=pass==mShadowStencilPass && capDepthBias!=0;\n'
        '        if(stencil) mDestRenderSystem->_setDepthBias(capDepthBias,0);\n'
        '        Ogre::SceneManager::renderSingleObject(renderable,pass,iterate,lights);\n'
        '        if(stencil) mDestRenderSystem->_setDepthBias(0,0);')
    # Demo styling changes live beside the browser port; frozen native reference
    # remains byte-for-byte unchanged. All materials come from the 2008 palette.
    folder = template.parent
    prefix = prefix.replace('// Native GeometryBuilder',
        (folder / 'brick_surfaces.in.cpp').read_text() + '\n// Native GeometryBuilder')
    palette = (root / 'tools/rbxgs/Client/App/v8datamodel/BrickColor.cpp').read_text()
    colours = {int(i): (int(r), int(g), int(b)) for i, r, g, b in re.findall(
        r'insert\(lego_(\d+),\s*(\d+),\s*(\d+),\s*(\d+),', palette)}
    cases = '\n'.join(f'case {i}: return Ogre::ColourValue({colours[i][0]}/255.0f,{colours[i][1]}/255.0f,{colours[i][2]}/255.0f);'
                      for i in (199,28,208,21,23,192,26,24,141,18,38,5,1,102))
    marker = '// Native GeometryBuilder'
    prefix = prefix.replace(marker, 'unsigned castleStudCount=0,castleBevelCount=0;\n'
        'int sceneBuildId=0;\n'
        'struct CastleBlock {Ogre::Vector3 center,size;Ogre::String material;bool studs;};\n'
        'std::vector<CastleBlock> castleBlocks;\n'
        'Ogre::ColourValue brickColour(int id) { switch(id) {\n' + cases +
        '\ndefault: throw std::runtime_error("Unknown castle BrickColor"); } }\n' + marker)
    prefix = prefix.replace('    void finish(Ogre::SceneManager* scene) {',
        (folder / 'brick_geometry.in.cpp').read_text() + '\n    void finish(Ogre::SceneManager* scene) {')
    prefix = prefix.replace('    unsigned index;', '    unsigned index;\n    Ogre::SceneManager* owner;\n    bool castShadows=true;')
    prefix = prefix.replace('    unsigned index;',
        '    bool suppressShadow=false;\n    std::vector<float> shadowVertices,shadowNormals;\n'
        '    std::vector<unsigned> shadowIndices;\n    unsigned index;')
    prefix = prefix.replace('        index+=4;',
        '        if(!suppressShadow) {shadowTriangle(a,b,c);shadowTriangle(a,c,d);}\n        index+=4;')
    prefix = prefix.replace('    void shadows(bool enabled) { mCastShadows=enabled; }',
        '    int sceneId=0;\n'
        '    void transform(const Ogre::Matrix4& matrix) {mTransform=matrix;}\n'
        '    void shadows(bool enabled) { mCastShadows=enabled; }\n'
        '    void shadowMesh(Ogre::RbxSubMesh* mesh) {mShadowSubMesh=mesh;}')
    prefix = prefix.replace('Ogre::AxisAlignedBox(-18,-12,-18,18,17,18)', 'Ogre::AxisAlignedBox(-30,-20,-30,110,30,30)')
    prefix = prefix.replace('mesh->_setBoundingSphereRadius(32)', 'mesh->_setBoundingSphereRadius(150)')
    prefix = prefix.replace('if(parts[i]->getCastShadows())', 'if(parts[i]->getCastShadows()&&parts[i]->isVisible())')
    prefix = prefix.replace('std::vector<float> vertices,normals;', 'std::vector<float> vertices,normals,texCoords;')
    prefix = prefix.replace('material->setDiffuse(colour); material->setAmbient(colour);',
        'if(fresh) applyBrickSurface(material,colour);')
    prefix = prefix.replace('material=Ogre::MaterialManager::getSingleton().create(name,"General");',
        'material=Ogre::MaterialManager::getSingleton().getByName(name);\n'
        '        bool fresh=material.isNull();\n'
        '        if(fresh) material=Ogre::MaterialManager::getSingleton().create(name,"General");')
    prefix = prefix.replace('normals.push_back(normal.x); normals.push_back(normal.y); normals.push_back(normal.z);',
        'normals.push_back(normal.x); normals.push_back(normal.y); normals.push_back(normal.z);\n'
        '            texCoords.push_back(0.125f);texCoords.push_back(0.25f);')
    prefix = prefix.replace('&normals[0],0,0,0,&indices[0]', '&normals[0],0,&texCoords[0],0,&indices[0]')
    prefix = prefix.replace(':index(0) {', ':index(0),owner(scene) {')
    prefix = prefix.replace('native->meshes.push_back(mesh); native->parts.push_back(object);',
        'native->meshes.push_back(mesh); native->parts.push_back(object);\n'
        '        object->sceneId=sceneBuildId;\n'
        '        if(castShadows) {\n'
        '            Ogre::RbxSubMesh* shadow=builder.createIndexed(&shadowVertices[0],shadowVertices.size()/3,\n'
        '                &shadowNormals[0],0,0,0,&shadowIndices[0],shadowIndices.size()/3,&minimum,&maximum);\n'
        '            object->shadowMesh(shadow);native->meshes.push_back(shadow);\n        }\n'
        '        object->shadows(castShadows);\n'
        '        shadowVertices.clear();shadowNormals.clear();shadowIndices.clear();\n'
        '        vertices.clear();normals.clear();texCoords.clear();indices.clear();index=0;')
    start = source.index('        DemoFactory factory;')
    end = source.index('        HWND hwnd=0;', start)
    setup = source[start:end].replace('        DemoFactory factory;', '')
    scene_start = setup.index('        static_cast<DemoSceneManager*>(scene)->createWorld();')
    scene_end = setup.index('        trees.finish(scene);', scene_start) + len('        trees.finish(scene);')
    setup = setup[:scene_start] + (folder / 'brick_scene.in.cpp').read_text() + setup[scene_end:]
    setup += '\n' + (folder / 'windmill_scene.in.cpp').read_text()
    setup = setup.replace('Ogre::Root root("","","ogre_demo.log");',
        'rootHandle = new Ogre::Root("", "", "castle_browser.log");\n'
        '        Ogre::Root& root = *rootHandle;\n        Ogre::registerBrowserImageCodecs();')
    setup = re.sub(r'root.loadPlugin\([^\n]+', 'root.installPlugin(new Ogre::GLPlugin);', setup)
    setup = setup.replace('root.initialise(false);', '')
    setup = re.sub(r'Ogre::RenderWindow\* window=root.createRenderWindow\([^\n]+',
                   'window = root.initialise(true, "Castle Island");', setup)
    for typename, name in (('Ogre::SceneManager', 'scene'), ('Ogre::Camera', 'camera'), ('Ogre::Light', 'sun')):
        setup = setup.replace(typename + '* ' + name + '=', name + '=')
    for declaration in ('Ogre::VisualEngine skyContext;', 'G3D::LightingParameters lighting(14*3600.0,true);',
                        'Ogre::TwoDManager hud;', 'Ogre::FrameHistory history;'):
        setup = setup.replace(declaration, '')
    first = source.index('            // Lighting::setTime uses whole seconds')
    end = source.index('            // Direct DLL render-target', first)
    frame = source[first:end]
    first_hud=frame.index('            if(hudVisible) {')
    end_hud=frame.index('            if(orbit',first_hud)
    frame=frame[:first_hud]+frame[end_hud:]
    setup=re.sub(r'^.*hud\.setup\([^\n]+\n|^.*scene->removeRenderQueueListener\(&hud\);\n', '',setup,flags=re.M)
    frame = frame.replace("focused && (GetAsyncKeyState('R')&0x8000)", "keys['R']")
    frame = frame.replace('celestial || (smoke && (frame==19 || frame==43))', 'celestial')
    frame = frame.replace('camera->setPosition(zoom*cos(pitch)*sin(yaw),(activeScene?9:3)+zoom*sin(pitch),zoom*cos(pitch)*cos(yaw));',
        'camera->setPosition((activeScene?80:0)+zoom*cos(pitch)*sin(yaw),(activeScene?9:3)+zoom*sin(pitch),zoom*cos(pitch)*cos(yaw));')
    frame = frame.replace('camera->lookAt(0,3,0);','camera->lookAt(activeScene?80:0,activeScene?9:3,0);')
    frame += '\n            for(auto* part:static_cast<DemoSceneManager*>(scene)->parts) part->setVisible(part->sceneId==activeScene);\n'
    frame = frame.replace('24,736,624,600,0,0,1,1', '24,window->getHeight()-24,624,window->getHeight()-160,0,0,1,1')
    frame = frame.replace('520+a', 'window->getHeight()-240+a').replace('520+b', 'window->getHeight()-240+b')
    text = template.read_text().replace('// NATIVE_PREFIX', prefix).replace('// NATIVE_SETUP', setup).replace('// NATIVE_FRAME', frame)
    output.parent.mkdir(exist_ok=True)
    output.write_text(text)

def body(text, signature, replacement):
    start = text.index('{', text.index(signature))
    depth = 1
    end = start + 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[:start] + '{\n' + replacement + '\n}' + text[end:]

def gl_source(name, text):
    if name == 'OgreGLPixelFormat.cpp':
        text = text.replace('case PF_A8R8G8B8:\n            case PF_B8G8R8A8:\n                return GL_RGBA8;',
            'case PF_A8R8G8B8:\n            case PF_A8B8G8R8:\n            case PF_R8G8B8A8:\n            case PF_B8G8R8A8:\n                return GL_RGBA8;')
    if name == 'OgreGLTextureManager.cpp':
        text = body(text, 'void GLTextureManager::createWarningTexture()', '''
    std::vector<unsigned char> data(8 * 8 * 4);
    for (size_t y = 0; y < 8; ++y) for (size_t x = 0; x < 8; ++x) {
        size_t i = (y * 8 + x) * 4;
        data[i] = data[i + 1] = ((x + y) % 8) < 4 ? 0 : 255;
        data[i + 2] = 0; data[i + 3] = 255;
    }
    glGenTextures(1, &mWarningTextureID);
    glBindTexture(GL_TEXTURE_2D, mWarningTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
''')
        text = body(text, 'PixelFormat GLTextureManager::getNativeFormat(', 'return PF_BYTE_RGBA;')
    if name == 'OgreGLRenderSystem.cpp':
        text = body(text, 'GpuProgram* createGLGpuNvparseProgram(',
            'OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "NV register-combiner programs require desktop OpenGL", "Browser renderer");')
    if name == 'OgreGLTexture.cpp':
        text = text.replace('doSoftware && mip==0);', 'doSoftware && mip==0,\n'
            'std::max(size_t(1), mWidth >> mip), std::max(size_t(1), mHeight >> mip),\n'
            'std::max(size_t(1), mDepth >> mip), mFormat);')
    if name == 'OgreGLHardwarePixelBuffer.cpp':
        text = text.replace('else if(GLPixelUtil::getGLOriginFormat(src.format) == 0)',
                            'else if(src.format != mFormat || GLPixelUtil::getGLOriginFormat(src.format) == 0)')
        text = text.replace('bool crappyCard):',
            'bool crappyCard, size_t width, size_t height, size_t depth, PixelFormat pixelFormat):')
        first = text.index('\t// Get width', text.index('GLTextureBuffer::GLTextureBuffer'))
        last = text.index('\n\t// Default', first)
        text = text[:first] + '''
    // WebGL has no glGetTexLevelParameteriv. The allocating Texture owns this
    // exact metadata, so pass it into the surface instead of querying the driver.
    mWidth = width; mHeight = height; mDepth = depth;
    mFormat = pixelFormat;
    mGLInternalFormat = GLPixelUtil::getGLInternalFormat(pixelFormat);
''' + text[last:]
        text = text.replace('glGetTexLevelParameteriv(mTarget, mLevel, GL_TEXTURE_INTERNAL_FORMAT, &internalFormat);',
                            'internalFormat = mGLInternalFormat;')
        text = body(text, 'void GLTextureBuffer::blit(const ',
                    'GLHardwarePixelBuffer::blit(src, srcBox, dstBox);')
        text = body(text, 'void GLTextureBuffer::blitFromMemory(',
                    'GLHardwarePixelBuffer::blitFromMemory(src_orig, dstBox);')
        text = body(text, 'void GLTextureBuffer::blitFromTexture(',
            'OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Desktop FBO blitter replaced by pixel-buffer blit", "Browser renderer");')
        text = 'extern "C" void browserReadTexture(unsigned, unsigned, int, unsigned, unsigned, void*);\n' + text
        text = body(text, 'void GLTextureBuffer::download(', '''
    if (PixelUtil::isCompressed(mFormat))
        OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Compressed texture readback unavailable", "Browser renderer");
    std::vector<unsigned char> pixels(mWidth * mHeight * 4);
    browserReadTexture(mTextureID, mFaceTarget, mLevel, mWidth, mHeight, &pixels[0]);
    PixelBox rgba(mWidth, mHeight, 1, PF_BYTE_RGBA, &pixels[0]);
    PixelUtil::bulkPixelConversion(rgba, data);
''')
    return text

def gl_headers(folder):
    path = folder / 'OgreGLHardwarePixelBuffer.h'
    text = path.read_text()
    text = text.replace('bool softwareMipmap);',
        'bool softwareMipmap, size_t width, size_t height, size_t depth, PixelFormat pixelFormat);')
    path.write_text(text)

def emulation_library(sdk, output):
    text = (sdk / 'upstream/emscripten/src/lib/libglemu.js').read_text()
    # The original library is loaded first. Keep compile-time macro helpers
    # distinct when this complete, patched implementation overrides it.
    text = text.replace('copySigs', 'castleCopySigs').replace('fromPtr', 'castleFromPtr')
    # Emscripten's generic legacy layer advertises assembly-program extensions
    # despite WebGL not implementing ARB assembly programs. Ogre must choose its
    # actual CPU stencil-extrusion path, not call nonexistent assembly entrypoints.
    text = text.replace(' GL_ARB_vertex_program GL_ARB_fragment_program', '')
    text = text.replace("err('WARNING: Unhandled `pname` in call to `glTexEnvf`.');",
        'GLImmediate.TexEnvJIT.hook_texEnvi(target, pname, param);')
    text = re.sub(r"glShadeModel:.*?warnOnce\('TODO: glShadeModel'\).*?[,\n]",
                  "glShadeModel: (mode) => { if (mode != 0x1D01) abort('Flat interpolation requires a flat-shader variant'); },\n", text)
    # Roblox's GeometryBuilder emits 32-bit indices. WebGL 2 supports them;
    # extend Emscripten's client-array upload path instead of truncating indices.
    text = text.replace('flush(numProvidedIndexes = undefined, startIndex = 0, ptr = 0)',
                        'flush(numProvidedIndexes = undefined, startIndex = 0, ptr = 0, indexType = 0x1403)')
    text = text.replace("var currIndex = {{{ makeGetValue('ptr', 'i*2', 'u16') }}};",
        'var currIndex = indexType == 0x1405 ? HEAPU32[(ptr >> 2) + i] :\n'
        '              indexType == 0x1401 ? HEAPU8[ptr + i] : HEAPU16[(ptr >> 1) + i];')
    text = text.replace('var byteSize = numProvidedIndexes << 1;',
                        'var byteSize = numProvidedIndexes * (indexType == 0x1405 ? 4 : indexType == 0x1401 ? 1 : 2);')
    text = text.replace('GLctx.drawElements(GLImmediate.mode, numIndexes, GLctx.UNSIGNED_SHORT, ptr);',
                        'GLctx.drawElements(GLImmediate.mode, numIndexes, indexType, ptr);')
    start = text.index('  glDrawElements: (mode, count, type, indices, start, end) => {')
    end = text.index('  // Vertex array object', start)
    draw = text[start:end]
    draw = draw.replace('assert(type == GLctx.UNSIGNED_SHORT);',
                        'assert(type == GLctx.UNSIGNED_SHORT || type == GLctx.UNSIGNED_INT || type == GLctx.UNSIGNED_BYTE);')
    draw = draw.replace('GLImmediate.prepareClientAttributes(count, false);', '''
    var verticesNeeded = count;
    if (!GLctx.currentArrayBufferBinding && !GLctx.currentElementArrayBufferBinding && count) {
      var maximum = 0;
      for (var i = 0; i < count; ++i) {
        var index = type == 0x1405 ? HEAPU32[(indices >> 2) + i] :
                    type == 0x1401 ? HEAPU8[indices + i] : HEAPU16[(indices >> 1) + i];
        maximum = Math.max(maximum, index);
      }
      verticesNeeded = maximum + 1;
    }
    GLImmediate.prepareClientAttributes(verticesNeeded, false);''')
    draw = draw.replace('GLImmediate.flush(count, 0, indices);', 'GLImmediate.flush(count, 0, indices, type);')
    draw = draw.replace('warnOnce("DrawElements doesn\'t actually prepareClientAttributes properly.");', '')
    text = text[:start] + draw + text[end:]
    # Upstream's texture-fetch CSE regex stops at the first ')' and corrupts
    # matrix-transformed UV expressions. Keep the complete GLSL expressions;
    # shader compilers can perform common-subexpression elimination themselves.
    first = text.index("        var texLoadLines = '';")
    last = text.index('        return [texLoadLines + lines];', first)
    text = text[:first] + '        return [lines];' + text[last + len('        return [texLoadLines + lines];'):]
    text = text.replace('  glPolygonMode: () => {}, // TODO', '''
  glPolygonMode: (face, mode) => {
    var extension = GLctx.getExtension('WEBGL_polygon_mode');
    if (extension) extension.polygonModeWEBGL(face, mode);
    else if (mode != 0x1B02) abort('Wireframe requires WEBGL_polygon_mode');
  },''')
    for kind, source in (('vertex', 'vsSource'), ('fragment', 'fsSource')):
        statement = f'GLctx.compileShader(this.{kind}Shader);'
        text = text.replace(statement, statement + f'''
            if (!GLctx.getShaderParameter(this.{kind}Shader, GLctx.COMPILE_STATUS))
              abort('{kind} shader failed: ' + GLctx.getShaderInfoLog(this.{kind}Shader) + '\\n' + {source});''')
    text = text.replace('GLctx.linkProgram(this.program);', '''GLctx.linkProgram(this.program);
            if (!GLctx.getProgramParameter(this.program, GLctx.LINK_STATUS))
              abort('Fixed-function shader link failed: ' + GLctx.getProgramInfoLog(this.program));''')
    # Stencil light caps reuse receiver positions in a different shader variant.
    # GLSL invariance prevents independently optimized transforms disagreeing in Z.
    text = text.replace("            var vsSource = [", "            var vsSource = [\n              'invariant gl_Position;',")
    text = text.replace('} else if (pname == 0x1601) { // GL_SHININESS',
        '} else if (pname == 0x1600) { // GL_EMISSION\n'
        '      GLEmulation.materialEmission.set(HEAPF32.subarray(param >> 2, (param >> 2) + 4));\n'
        '    } else if (pname == 0x1601) { // GL_SHININESS')
    for operation, enabled in (('Enable', 'true'), ('Disable', 'false')):
        prefix = f'_gl{operation} = _emscripten_gl{operation} = (cap) => {{'
        text = text.replace(prefix, prefix + f'''
        if (cap == 0x0B57) {{
          GLImmediate.lastRenderer?.cleanup();
          GLImmediate.currentRenderer = null;
          GLEmulation.colorMaterialEnabled = {enabled};
          return;
        }}''')
    text = text.replace('var keyView = cacheMap.getStaticKeyView().reset();',
        'var keyView = cacheMap.getStaticKeyView().reset();\n'
        '      keyView.next(GLEmulation.colorMaterialEnabled ? (GLEmulation.colorMaterialMode || 0x1602) : 0);')
    # Ogre selects local-viewer specular and separate specular colour. Implement
    # both in the generated shaders, rather than accepting and ignoring the state.
    text = text.replace("vsLightingDefs += 'uniform vec4 u_materialEmission;';",
        "vsLightingDefs += 'uniform vec4 u_materialEmission; varying vec3 v_secondaryColor;';")
    text = text.replace("vsLightingPass += '  vec3 ecNormal", "vsLightingPass += '  v_secondaryColor = vec3(0.0);';\n              vsLightingPass += '  vec3 ecNormal")
    text = text.replace('normalize(lightDirection + vec3(0,0,1))', 'normalize(lightDirection + normalize(-ecPosition.xyz))')
    text = text.replace('v_color.xyz += ambient + diffuse + specular;',
                        'v_color.xyz += ambient + diffuse; v_secondaryColor += specular;')
    text = text.replace("'varying vec4 v_color;',\n              fogHeaderIfNeeded,",
        "'varying vec4 v_color;',\n              (GLEmulation.lightingEnabled ? 'varying vec3 v_secondaryColor;' : ''),\n              fogHeaderIfNeeded,")
    text = text.replace('              fsTexEnvPass,\n              fogPass,',
        "              fsTexEnvPass,\n              (GLEmulation.lightingEnabled ? 'gl_FragColor.rgb = clamp(gl_FragColor.rgb + v_secondaryColor, 0.0, 1.0);' : ''),\n              fogPass,")
    begin = text.index("vsLightingPass += '  v_secondaryColor")
    end = text.index('            var vsSource =', begin)
    lighting = text[begin:end]
    for component in ('Ambient', 'Diffuse', 'Specular', 'Emission'):
        lighting = lighting.replace('u_material' + component, 'material' + component)
    declarations = '''
              var colourMode = GLEmulation.colorMaterialEnabled ? (GLEmulation.colorMaterialMode || 0x1602) : 0;
              for (var [component, mode] of [['Ambient', 0x1200], ['Diffuse', 0x1201], ['Specular', 0x1202], ['Emission', 0x1600]]) {
                var tracked = colourMode == mode || (colourMode == 0x1602 && (mode == 0x1200 || mode == 0x1201));
                vsLightingPass += 'vec4 material' + component + ' = ' + (tracked ? 'a_color' : 'u_material' + component) + ';';
              }
'''
    text = text[:begin] + declarations + lighting + text[end:]
    output.write_text(text)

