#include <Ogre.h>
#include <OgreWindowEventUtilities.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <cmath>

#include <windows.h>
#include <d3d9.h>
#include "zlib.h"
#include "PlayerScene.h"
#include "RbxEntity.h"
#include "../PlayerSkybox.h"

extern "C" int LoadPlace(const char* text);
extern "C" void GetPartPosition(float* x, float* y, float* z);
extern "C" void GetPartExtent(float* x, float* y, float* z);
extern "C" void GetPartColor(float* r, float* g, float* b);
extern "C" int  PartAlive(void);
extern "C" void MovePartTo(float x, float y, float z);
extern "C" void StepEngine(float dt);
extern "C" void ClosePlace();
extern "C" void RemovePart(void);
extern "C" void SetPartYaw(float);
extern "C" int GetContactState(float*,float*,int*);
extern "C" int ExecutePlayerScript(const char*);

static const char* kPartPlace =
    "<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties>"
    "<Item class=\"Part\" referent=\"RBX1\"><Properties>"
    "<string name=\"Name\">Brick</string><bool name=\"Anchored\">true</bool>"
    "<Vector3 name=\"size\"><X>2</X><Y>1</Y><Z>1</Z></Vector3>"
    "<Color3 name=\"Color\"><R>0</R><G>1</G><B>0</B></Color3>"
    "<CoordinateFrame name=\"CFrame\"><X>0</X><Y>0</Y><Z>0</Z>"
    "<R00>1</R00><R01>0</R01><R02>0</R02><R10>0</R10><R11>1</R11><R12>0</R12>"
    "<R20>0</R20><R21>0</R21><R22>1</R22></CoordinateFrame>"
    "</Properties></Item></Item></roblox>";

static const char* kEmptyPlace =
    "<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties>"
    "</Item></roblox>";

static const char* kDemoPlace =
    "<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties>"
    "<Item class=\"Part\" referent=\"RBX1\"><Properties>"
    "<string name=\"Name\">Brick</string><bool name=\"Anchored\">true</bool>"
    "<Vector3 name=\"size\"><X>4</X><Y>1.2</Y><Z>2</Z></Vector3>"
    "<Color3 name=\"Color\"><R>1</R><G>0</G><B>0</B></Color3>"
    "<token name=\"TopSurface\">3</token><token name=\"BottomSurface\">0</token>"
    "<CoordinateFrame name=\"CFrame\"><X>0</X><Y>0</Y><Z>0</Z>"
    "<R00>1</R00><R01>0</R01><R02>0</R02><R10>0</R10><R11>1</R11><R12>0</R12>"
    "<R20>0</R20><R21>0</R21><R22>1</R22></CoordinateFrame>"
    "</Properties></Item></Item></roblox>";

static std::string readPlace(const char* path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) return "";
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

// ---------------------------------------------------------------- PNG input

struct Image
{
    int width;
    int height;
    std::vector<unsigned char> rgb;
};

static unsigned be32(const unsigned char* p)
{
    return ((unsigned)p[0] << 24) | ((unsigned)p[1] << 16) | ((unsigned)p[2] << 8) | p[3];
}

static bool readPng(const char* path, Image& image)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) return false;
    std::vector<unsigned char> file((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    static const unsigned char sig[8] = { 137, 80, 78, 71, 13, 10, 26, 10 };
    if (file.size() < 8 || std::memcmp(&file[0], sig, 8) != 0) return false;

    int width = 0, height = 0, bitDepth = 0, colorType = 0, interlace = 0;
    std::vector<unsigned char> idat;
    size_t pos = 8;
    while (pos + 8 <= file.size())
    {
        unsigned len = be32(&file[pos]);
        const unsigned char* type = &file[pos + 4];
        const unsigned char* data = &file[pos + 8];
        if (pos + 12 + len > file.size()) return false;
        if (std::memcmp(type, "IHDR", 4) == 0)
        {
            width = (int)be32(data);
            height = (int)be32(data + 4);
            bitDepth = data[8];
            colorType = data[9];
            interlace = data[12];
        }
        else if (std::memcmp(type, "IDAT", 4) == 0)
        {
            idat.insert(idat.end(), data, data + len);
        }
        else if (std::memcmp(type, "IEND", 4) == 0)
        {
            break;
        }
        pos += 12 + len;
    }
    if (width <= 0 || height <= 0 || bitDepth != 8 || interlace != 0) return false;

    int channels = 0;
    switch (colorType)
    {
    case 0: channels = 1; break;
    case 2: channels = 3; break;
    case 4: channels = 2; break;
    case 6: channels = 4; break;
    default: return false;
    }

    size_t rowBytes = (size_t)width * channels;
    size_t stride = rowBytes + 1;
    std::vector<unsigned char> raw(stride * height);
    z_stream stream;
    std::memset(&stream, 0, sizeof(stream));
    stream.next_in = idat.empty() ? Z_NULL : &idat[0];
    stream.avail_in = (uInt)idat.size();
    stream.next_out = &raw[0];
    stream.avail_out = (uInt)raw.size();
    if (inflateInit(&stream) != Z_OK)
        return false;
    int inflateResult = inflate(&stream, Z_FINISH);
    inflateEnd(&stream);
    if (inflateResult != Z_STREAM_END || stream.total_out != raw.size())
        return false;

    std::vector<unsigned char> pixels(rowBytes * height);
    const unsigned char* src = &raw[0];
    unsigned char* dst = &pixels[0];
    size_t bpp = (size_t)channels;
    for (int y = 0; y < height; ++y)
    {
        unsigned char filter = *src++;
        const unsigned char* rowSrc = src;
        unsigned char* rowDst = dst;
        const unsigned char* prevRow = (y > 0) ? (dst - rowBytes) : NULL;
        for (size_t x = 0; x < rowBytes; ++x)
        {
            unsigned char value = rowSrc[x];
            unsigned char left = (x >= bpp) ? rowDst[x - bpp] : 0;
            unsigned char up = (prevRow) ? prevRow[x] : 0;
            unsigned char upLeft = (prevRow && x >= bpp) ? prevRow[x - bpp] : 0;
            switch (filter)
            {
            case 0: break;
            case 1: value = (unsigned char)(value + left); break;
            case 2: value = (unsigned char)(value + up); break;
            case 3: value = (unsigned char)(value + ((left + up) >> 1)); break;
            case 4:
            {
                int p = (int)left + (int)up - (int)upLeft;
                int pa = std::abs(p - (int)left);
                int pb = std::abs(p - (int)up);
                int pc = std::abs(p - (int)upLeft);
                unsigned char predictor = (pa <= pb && pa <= pc) ? left : (pb <= pc ? up : upLeft);
                value = (unsigned char)(value + predictor);
                break;
            }
            default: return false;
            }
            rowDst[x] = value;
        }
        src += rowBytes;
        dst += rowBytes;
    }

    image.width = width;
    image.height = height;
    image.rgb.resize((size_t)width * height * 3);
    for (int y = 0; y < height; ++y)
    {
        const unsigned char* row = &pixels[(size_t)y * rowBytes];
        for (int x = 0; x < width; ++x)
        {
            unsigned char r, g, b;
            const unsigned char* pp = row + (size_t)x * channels;
            if (channels == 1) { r = g = b = pp[0]; }
            else if (channels == 2) { r = g = b = pp[0]; }
            else { r = pp[0]; g = pp[1]; b = pp[2]; }
            unsigned char* out = &image.rgb[((size_t)y * width + x) * 3];
            out[0] = r; out[1] = g; out[2] = b;
        }
    }
    return true;
}

static bool isGreen(const unsigned char* p)
{
    // Fixture quantizes to BrickColor(40,127,70). Native ambient/atlas shading
    // makes its front face about(23,72,40); the old unlit G>120 is inapplicable.
    // Require green chroma and visible brightness; keep all area/noise gates.
    return p[1] > 50 && p[1] > p[0]*2 && p[1]*2 > p[2]*3;
}

static int countGreen(const Image& image, int x0, int y0, int x1, int y1)
{
    int count = 0;
    if (x1 > image.width) x1 = image.width;
    if (y1 > image.height) y1 = image.height;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    for (int y = y0; y < y1; ++y)
        for (int x = x0; x < x1; ++x)
            if (isGreen(&image.rgb[((size_t)y * image.width + x) * 3]))
                ++count;
    return count;
}

// --------------------------------------------------------------- Ogre scene

struct DrawEntry
{
    Ogre::SceneNode* node;
    Ogre::RbxEntity* entity;
    Ogre::MeshPtr mesh;
    PlayerBlockMesh::MeshRef geometry;
    PlayerNativeMaterial::MaterialRef material;
    float size[3];
    float color[3];

    DrawEntry() : node(NULL), entity(NULL) { size[0] = size[1] = size[2] = 0; color[0] = color[1] = color[2] = 0; }
};

static Ogre::SceneManager* g_sceneManager = NULL;
static std::map<const void*, DrawEntry> g_drawn;

// Geometry is produced by recovered 004e2c80 and uploaded by 00549a50.
// Ogre Mesh here supplies entity bounds only; Level owns the detached RbxSubMesh.
static Ogre::MeshPtr createRecoveredMesh(const char* name, PlayerBlockMesh::BlockMesh* geometry)
{
    Ogre::MeshPtr existing=Ogre::MeshManager::getSingleton().getByName(name);
    if(!existing.isNull())return existing;
    PlayerBlockMesh::Level& level=geometry->level0();
    Ogre::AxisAlignedBox bounds;
    level.upload(false,bounds);
    PlayerSphereCache::set(reinterpret_cast<PlayerSphereCache::Key>(level.backend),
        Ogre::Sphere(bounds.getCenter(),bounds.getHalfSize().length())); // 007aba1d ->00682350.
    Ogre::MeshPtr mesh=Ogre::MeshManager::getSingleton().createManual(name,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    // Native00684fd0 binds detached submesh data directly. No fabricated parent
    // link or adoption into this bounds-only Mesh's deletion list is required.
    mesh->_setBounds(bounds);mesh->_setBoundingSphereRadius(level.backend->radius);mesh->load();
    std::printf("recovered block: producer=004e2c80 upload=00549a50 calls=%u indices=%u\n",PlayerBlockMesh::producerCalls(),static_cast<unsigned>(level.backend->indexData->indexCount));
    return mesh;
}

static void releaseGeometry(DrawEntry& entry)
{
    if(entry.mesh.isNull())return;
    std::string name=entry.mesh->getName();
    bool lastUser=entry.mesh.useCount()==Ogre::ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS+1;
    entry.geometry=PlayerBlockMesh::MeshRef();
    entry.material=PlayerNativeMaterial::MaterialRef();
    entry.mesh.setNull();
    if(lastUser){
        Ogre::MeshManager::getSingleton().remove(name);
    }
}

static void drawModels()
{
    int count = SceneBeginFrame();
    std::map<const void*, bool> seen;

    for (int i = 0; i < count; ++i)
    {
        SceneModel model;
        if (SceneModelGet(i, &model) != 0)
            continue;
        seen[model.id] = true;

        DrawEntry& entry = g_drawn[model.id];
        if (!entry.node)
        {
            std::string name = "chunk_";
            char suffix[32];
            _snprintf(suffix, sizeof(suffix), "%p", model.id);
            name += suffix;
            entry.node = g_sceneManager->getRootSceneNode()->createChildSceneNode(name + "_node");
            entry.size[0] = -1;
        }
        if (!entry.entity || entry.geometry.operator->()!=model.geometry)
        {
            if (entry.entity)
            {
                entry.node->detachObject(entry.entity);
                delete entry.entity;
                entry.entity = NULL;
                releaseGeometry(entry);
            }
            std::string name = "mesh_";
            char suffix[32];
            _snprintf(suffix, sizeof(suffix), "%p", model.geometry);
            name += suffix;
            entry.geometry=model.geometry;
            entry.mesh = createRecoveredMesh(name.c_str(), model.geometry);
            entry.entity = new Ogre::RbxEntity();
            entry.entity->setMesh(entry.mesh);
            Ogre::SubMesh* subMesh = entry.geometry->level0().backend;
            entry.entity->createSubEntity(subMesh, 0);
            entry.node->attachObject(entry.entity);
            const Ogre::AxisAlignedBox& b = entry.entity->getBoundingBox();
            std::memcpy(entry.size, model.size, sizeof(entry.size));
            std::memcpy(entry.color, model.color, sizeof(entry.color));
        }
        if(entry.material.getPointer()!=model.material){
            entry.material=model.material;
            const char* sky=getenv("ROC_SKY_SPHERE");
            Ogre::MaterialPtr backend=PlayerNativeMaterial::prepareBackend(*entry.material,0,
                entry.geometry->geometryKind,entry.geometry->level0().primitive,0,sky?sky:"");
            entry.entity->getSubEntity(0)->setMaterialName(backend->getName());
            std::printf("native material: getter=004eb190 renderer=007ab0a0 name=%s texture=%s lit=%d\n",
                backend->getName().c_str(),backend->getTechnique(0)->getPass(0)->getTextureUnitState(0)->getTextureName().c_str(),
                backend->getTechnique(0)->getPass(0)->getLightingEnabled());
        }

        entry.node->setPosition(model.position[0], model.position[1], model.position[2]);
        Ogre::Matrix3 rotation(
            model.rotation[0], model.rotation[1], model.rotation[2],
            model.rotation[3], model.rotation[4], model.rotation[5],
            model.rotation[6], model.rotation[7], model.rotation[8]);
        entry.node->setOrientation(Ogre::Quaternion(rotation));
    }

    for (std::map<const void*, DrawEntry>::iterator it = g_drawn.begin(); it != g_drawn.end(); )
    {
        if (seen.find(it->first) == seen.end())
        {
            if (it->second.entity)
            {
                it->second.node->detachObject(it->second.entity);
                delete it->second.entity;
            }
            it->second.entity = NULL;
            releaseGeometry(it->second);
            g_sceneManager->destroySceneNode(it->second.node->getName());
            g_drawn.erase(it++);
        }
        else
        {
            ++it;
        }
    }
    Ogre::AxisAlignedBox bounds;
    for(std::map<const void*,DrawEntry>::iterator it=g_drawn.begin();it!=g_drawn.end();++it){
        Ogre::AxisAlignedBox transformed=it->second.mesh->getBounds();
        transformed.transformAffine(it->second.node->_getFullTransform());bounds.merge(transformed);
    }
    SceneApplyLighting(g_sceneManager,&bounds);
}

// ------------------------------------------------------------------ selftest

static bool writeBackbuffer(Ogre::RenderWindow* win, const char* path)
{
    // Ogre 1.4's window screenshot uses GetFrontBufferData (desktop pixels).
    // Read our rendered backbuffer before Present, even while another app covers it.
    win->update(false);
    IDirect3DDevice9* device=0;
    IDirect3DSurface9* back=0;
    IDirect3DSurface9* copy=0;
    win->getCustomAttribute("D3DDEVICE",&device);
    win->getCustomAttribute("DDBACKBUFFER",&back); // Borrowed surface.
    D3DSURFACE_DESC desc;
    HRESULT result=back->GetDesc(&desc);
    if(FAILED(result) || (desc.Format!=D3DFMT_X8R8G8B8 && desc.Format!=D3DFMT_A8R8G8B8))return false;
    result=device->CreateOffscreenPlainSurface(desc.Width,desc.Height,desc.Format,D3DPOOL_SYSTEMMEM,&copy,0);
    if(FAILED(result))return false;
    result=device->GetRenderTargetData(back,copy);
    if(FAILED(result)){copy->Release();return false;}
    D3DLOCKED_RECT pixels;
    result=copy->LockRect(&pixels,0,D3DLOCK_READONLY);
    if(FAILED(result)){copy->Release();return false;}
    std::vector<unsigned char> rgb(desc.Width*desc.Height*3);
    for(unsigned y=0;y<desc.Height;++y)
        for(unsigned x=0;x<desc.Width;++x){
            const unsigned char* pixel=static_cast<unsigned char*>(pixels.pBits)+y*pixels.Pitch+x*4;
            unsigned char* out=&rgb[(y*desc.Width+x)*3];
            out[0]=pixel[2];out[1]=pixel[1];out[2]=pixel[0];
        }
    copy->UnlockRect();copy->Release();
    Ogre::Image output;
    output.loadDynamicImage(&rgb[0],desc.Width,desc.Height,1,Ogre::PF_BYTE_RGB,false);
    output.save(path);
    win->swapBuffers();
    return true;
}

static bool capture(Ogre::Root* root, Ogre::RenderWindow* win, const char* path, Image& image)
{
    root->renderOneFrame();
    if(!writeBackbuffer(win,path))return false;
    if (!readPng(path, image))
    {
        std::printf("selftest: could not read %s\n", path);
        return false;
    }
    return true;
}

static int runSelftest(Ogre::Root* root, Ogre::RenderWindow* win)
{
    int failures = 0;

    if (LoadPlace(kPartPlace) != 0) { std::printf("selftest: place load failed\n"); return 1; }
    if (SceneAttach() != 0) { std::printf("selftest: scene attach failed\n"); return 1; }
    if(getenv("ROC_TRACE_STAGES"))OutputDebugStringA("P2_STAGE_LOADED");

    float sx, sy, sz;
    GetPartExtent(&sx, &sy, &sz);
    std::printf("selftest: part size=(%g,%g,%g) models=%d\n", sx, sy, sz, SceneModelCount());

    const int ax0 = 110, ax1 = 210, ay0 = 90, ay1 = 150;
    const int bx0 = 240, bx1 = 320, by0 = 90, by1 = 150;

    drawModels();
    Image initial;
    if (!capture(root, win, "selftest_initial.png", initial)) return 1;
    int initialA = countGreen(initial, ax0, ay0, ax1, ay1);
    int initialB = countGreen(initial, bx0, by0, bx1, by1);
    bool okInitial = SceneModelCount() == 1 && initialA > 300 && initialB < 30;
    std::printf("selftest: initial models=%d greenA=%d greenB=%d %s\n",
        SceneModelCount(), initialA, initialB, okInitial ? "PASS" : "FAIL");
    if (!okInitial) ++failures;

    if(getenv("ROC_TRACE_STAGES"))OutputDebugStringA("P2_STAGE_BEFORE_MOVE");
    MovePartTo(4.0f, 0.0f, 0.0f);
    drawModels();
    Image moved;
    if (!capture(root, win, "selftest_moved.png", moved)) return 1;
    int movedA = countGreen(moved, ax0, ay0, ax1, ay1);
    int movedB = countGreen(moved, bx0, by0, bx1, by1);
    bool okMoved = SceneModelCount() == 1 && movedA < 30 && movedB > 300;
    std::printf("selftest: moved models=%d greenA=%d greenB=%d %s\n",
        SceneModelCount(), movedA, movedB, okMoved ? "PASS" : "FAIL");
    if (!okMoved) ++failures;

    if(getenv("ROC_TRACE_STAGES"))OutputDebugStringA("P2_STAGE_BEFORE_REMOVE");
    RemovePart();
    SceneBeginFrame();
    drawModels();
    Image removed;
    if(getenv("ROC_TRACE_STAGES"))OutputDebugStringA("P2_STAGE_AFTER_REMOVE");
    if (!capture(root, win, "selftest_removed.png", removed)) return 1;
    int removedAll = countGreen(removed, 0, 0, removed.width, removed.height);
    bool okRemoved = SceneModelCount() == 0 && removedAll < 30;
    std::printf("selftest: removed models=%d green=%d %s\n",
        SceneModelCount(), removedAll, okRemoved ? "PASS" : "FAIL");
    if (!okRemoved) ++failures;

    SceneDetach();
    ClosePlace();
    if (LoadPlace(kEmptyPlace) != 0) { std::printf("selftest: empty place load failed\n"); return 1; }
    if (SceneAttach() != 0) { std::printf("selftest: empty scene attach failed\n"); return 1; }
    drawModels();
    Image empty;
    if (!capture(root, win, "selftest_empty.png", empty)) return 1;
    int emptyAll = countGreen(empty, 0, 0, empty.width, empty.height);
    bool okEmpty = SceneModelCount() == 0 && emptyAll < 30;
    std::printf("selftest: empty models=%d green=%d %s\n",
        SceneModelCount(), emptyAll, okEmpty ? "PASS" : "FAIL");
    if (!okEmpty) ++failures;

    std::ostringstream json;
    json << "{\n"
         << "  \"pixel_metric\": \"lit green: G>50, G>2R, 2G>3B\",\n"
         << "  \"initial\": {\"models\": 1, \"greenA\": " << initialA << ", \"greenB\": " << initialB
         << ", \"pass\": " << (okInitial ? "true" : "false") << "},\n"
         << "  \"moved\": {\"models\": 1, \"greenA\": " << movedA << ", \"greenB\": " << movedB
         << ", \"pass\": " << (okMoved ? "true" : "false") << "},\n"
         << "  \"removed\": {\"models\": 0, \"green\": " << removedAll
         << ", \"pass\": " << (okRemoved ? "true" : "false") << "},\n"
         << "  \"empty\": {\"models\": 0, \"green\": " << emptyAll
         << ", \"pass\": " << (okEmpty ? "true" : "false") << "},\n"
         << "  \"failures\": " << failures << "\n"
         << "}\n";
    std::ofstream out("selftest_result.json", std::ios::binary);
    out << json.str();
    std::printf("selftest: %d failure(s); wrote selftest_result.json\n", failures);
    return failures == 0 ? 0 : 5;
}

static unsigned resourceCount(Ogre::ResourceManager& manager){
    unsigned count=0;
    Ogre::ResourceManager::ResourceMapIterator it=manager.getResourceIterator();
    while(it.hasMoreElements()){it.getNext();++count;}
    return count;
}

static int runCacheTest(Ogre::Root* root,Ogre::RenderWindow* win,const std::string& place){
    unsigned meshes=resourceCount(Ogre::MeshManager::getSingleton());
    unsigned materials=resourceCount(Ogre::MaterialManager::getSingleton());
    for(int cycle=0;cycle<2;++cycle){
        if(cycle && LoadPlace(place.c_str()))return 1;
        if(SceneAttach())return 2;
        drawModels();
        if(g_drawn.size()!=9)return 3;
        std::map<PlayerBlockMesh::BlockMesh*,int> users;
        for(std::map<const void*,DrawEntry>::iterator it=g_drawn.begin();it!=g_drawn.end();++it){
            DrawEntry& entry=it->second;
            if(entry.geometry->levels.size()!=2 || entry.geometry->level0().backend->parent)return 4;
            PlayerSphereCache::Key key=reinterpret_cast<PlayerSphereCache::Key>(entry.geometry->level0().backend);
            if(!PlayerSphereCache::has(key) || PlayerSphereCache::get(key).getRadius()!=entry.geometry->level0().backend->radius)return 12;
            ++users[entry.geometry.getPointer()];
        }
        bool shared=false;
        for(std::map<PlayerBlockMesh::BlockMesh*,int>::iterator it=users.begin();it!=users.end();++it)
            if(it->second>1)shared=true;
        if(!shared)return 5;
        if(PlayerSphereCache::size()!=users.size())return 13;
        Image image;
        if(!capture(root,win,"cache_initial.png",image) || !countGreen(image,110,90,210,150))return 6;
        RemovePart();drawModels();
        if(g_drawn.size()!=8)return 7;
        for(std::map<const void*,DrawEntry>::iterator it=g_drawn.begin();it!=g_drawn.end();++it){
            DrawEntry& entry=it->second;
            if(entry.geometry->level0().backend->parent ||
               entry.entity->getMesh().getPointer()!=entry.mesh.getPointer() ||
               Ogre::MeshManager::getSingleton().getByName(entry.mesh->getName()).getPointer()!=entry.mesh.getPointer() ||
               entry.node->getPosition()!=Ogre::Vector3::ZERO)return 8;
            if(!PlayerSphereCache::has(reinterpret_cast<PlayerSphereCache::Key>(entry.geometry->level0().backend)))return 14;
        }
        if(!capture(root,win,"cache_remaining.png",image) || !countGreen(image,110,90,210,150))return 9;
        SceneDetach();drawModels();ClosePlace();PlayerBlockMesh::flushUnused();
        if(!g_drawn.empty() || PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() ||
           PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes() || PlayerSphereCache::size())return 10;
        if(resourceCount(Ogre::MeshManager::getSingleton())!=meshes ||
           resourceCount(Ogre::MaterialManager::getSingleton())!=materials)return 11;
        std::printf("cachetest cycle=%d models9->8->0 metadata/material baseline PASS\n",cycle);
    }
    return 0;
}

// ---------------------------------------------------------------------- main

// P3 block lifetime gate. Non-box/reference silhouette remains a separate gate.
static bool lifetimeFrame(Ogre::Root* root,Ogre::RenderWindow* win,int cycle,
    const char* stage,int expected,bool green,const void* stationaryId,
    Ogre::SceneNode* stationaryNode,PlayerBlockMesh::BlockMesh* stationaryMesh,
    int& redBaseline,std::ofstream& records)
{
    drawModels();
    char name[96];_snprintf(name,sizeof(name),"p3_%d_%s.png",cycle,stage);
    Image image;
    if(!capture(root,win,name,image))return false;
    int red=0;
    for(int y=0;y<image.height;++y)for(int x=0;x<image.width;++x){
        const unsigned char* pixel=&image.rgb[(y*image.width+x)*3];
        if(pixel[0]>50 && pixel[0]>2*pixel[1] && 2*pixel[0]>3*pixel[2])++red;
    }
    int greenPixels=countGreen(image,0,0,image.width,image.height);
    if(redBaseline<0)redBaseline=red;
    std::map<const void*,DrawEntry>::iterator stationary=g_drawn.find(stationaryId);
    bool stable=stationary!=g_drawn.end() && stationary->second.node==stationaryNode &&
        stationary->second.geometry.getPointer()==stationaryMesh &&
        stationaryNode->getPosition()==Ogre::Vector3(2,0,0) &&
        stationaryNode->getOrientation()==Ogre::Quaternion::IDENTITY &&
        stationary->second.size[0]==1 && stationary->second.size[1]==2.4f && stationary->second.size[2]==1;
    bool pass=SceneModelCount()==expected && g_drawn.size()==static_cast<unsigned>(expected) &&
        stable && red>100 && red==redBaseline && (green?greenPixels>100:greenPixels<30);
    records<<cycle<<","<<stage<<","<<SceneModelCount()<<","<<g_drawn.size()<<","<<red<<","<<greenPixels<<","<<stable<<","<<pass<<"\n";
    std::printf("p3 cycle=%d %s models=%d red=%d green=%d stationary=%d %s\n",
        cycle,stage,SceneModelCount(),red,greenPixels,stable,pass?"PASS":"FAIL");
    return pass;
}

static int runLifetimeTest(Ogre::Root* root,Ogre::RenderWindow* win,const std::string& place)
{
    unsigned meshes=resourceCount(Ogre::MeshManager::getSingleton());
    unsigned materials=resourceCount(Ogre::MaterialManager::getSingleton());
    unsigned textures=resourceCount(Ogre::TextureManager::getSingleton());
    unsigned nodes=g_sceneManager->getRootSceneNode()->numChildren();
    std::ofstream records("p3_lifetime.csv",std::ios::binary);
    if(!records)return 1;
    records<<"cycle,stage,models,drawn,red,green,stationary,pass\n";
    for(int cycle=0;cycle<2;++cycle){
        if(cycle && LoadPlace(place.c_str()))return 2;
        if(SceneAttach())return 3;
        drawModels();
        const void* stationaryId=0;
        for(std::map<const void*,DrawEntry>::iterator it=g_drawn.begin();it!=g_drawn.end();++it)
            if(it->second.node->getPosition()==Ogre::Vector3(2,0,0))stationaryId=it->first;
        if(!stationaryId)return 4;
        DrawEntry& stationary=g_drawn.find(stationaryId)->second;
        Ogre::SceneNode* stationaryNode=stationary.node;
        PlayerBlockMesh::BlockMesh* stationaryMesh=stationary.geometry.getPointer();
        int red=-1;
        if(!lifetimeFrame(root,win,cycle,"loaded",2,true,stationaryId,stationaryNode,stationaryMesh,red,records))return 5;
        const char* commands[]={
            "game.Workspace.Brick.Size=Vector3.new(3,1.2,1); game.Workspace.Brick.CFrame=CFrame.new(-2,.5,0)*CFrame.fromEulerAnglesXYZ(0,0,.6)",
            "p3Group=Instance.new('Model');p3Group.Name='Group';p3Group.Parent=game.Workspace;p3Held=game.Workspace.Brick;p3Held.Parent=p3Group",
            "p3Held.Parent=nil",
            "p3Held.Parent=game.Workspace",
            "p3Inserted=Instance.new('Part');p3Inserted.Name='Inserted';p3Inserted.Anchored=true;p3Inserted.Size=Vector3.new(1,1.2,1);p3Inserted.CFrame=CFrame.new(-2,-2,0);p3Inserted.Parent=game.Workspace",
            "p3Inserted.Parent=nil;p3Inserted=nil",
            "p3Held.Parent=nil;p3Held=nil"
        };
        const char* stages[]={"transformed","reparented","detached","reattached","inserted","insert_removed","removed"};
        const int counts[]={2,2,1,2,3,2,1};
        for(int step=0;step<7;++step){
            if(ExecutePlayerScript(commands[step]))return 6;
            if(!lifetimeFrame(root,win,cycle,stages[step],counts[step],step!=2 && step!=6,
                stationaryId,stationaryNode,stationaryMesh,red,records))return 7;
            if(step==0){
                bool transformed=false;
                for(int i=0;i<SceneModelCount();++i){
                    SceneModel model;
                    if(!SceneModelGet(i,&model) && model.position[0]==-2 && model.position[1]==.5f &&
                        model.size[0]==3 && model.size[1]==1.2f && model.size[2]==1 &&
                        std::fabs(model.rotation[0]-.8253356f)<.0001f &&
                        std::fabs(model.rotation[1]+.5646425f)<.0001f)transformed=true;
                }
                if(!transformed){std::printf("p3 resize/rotation model values FAIL\n");return 13;}
            }
        }
        SceneDetach();drawModels();ClosePlace();PlayerBlockMesh::flushUnused();
        for(int i=0;i<32;++i)PlayerNativeMaterial::collectUnusedTextures();
        if(!g_drawn.empty() || PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() ||
            PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes() || PlayerSphereCache::size())return 8;
        if(resourceCount(Ogre::MeshManager::getSingleton())!=meshes ||
            resourceCount(Ogre::MaterialManager::getSingleton())!=materials ||
            resourceCount(Ogre::TextureManager::getSingleton())!=textures ||
            g_sceneManager->getRootSceneNode()->numChildren()!=nodes)return 9;
        if(LoadPlace(kEmptyPlace) || SceneAttach())return 10;
        drawModels();
        Image empty;char name[64];_snprintf(name,sizeof(name),"p3_%d_empty.png",cycle);
        if(!capture(root,win,name,empty) || SceneModelCount() || !g_drawn.empty() ||
            countGreen(empty,0,0,empty.width,empty.height))return 11;
        SceneDetach();drawModels();ClosePlace();
        std::printf("p3 cycle=%d empty/reopen mesh/material/texture/node baseline PASS counts=%u/%u/%u/%u\n",
            cycle,meshes,materials,textures,nodes);
    }
    std::ofstream result("p3_result.json",std::ios::binary);
    result<<"{\"block_lifetime_pass\":true,\"cycles\":2,\"non_box_proven\":false,"
        <<"\"mesh_baseline\":"<<meshes<<",\"material_baseline\":"<<materials
        <<",\"texture_baseline\":"<<textures<<",\"node_baseline\":"<<nodes<<"}\n";
    return result?0:12;
}

int main(int argc, char** argv)
{
    bool selftest = false;
    bool cachetest = false;
    bool lifetest = false;
    bool frames = false;
    bool demo = false;
    bool skytest = false;
    bool stability = false;
    int stabilityExit = 0;
    int spinFrames = 0;
    std::string contentRoot;
    int frameCount = 0;
    std::string placeText;
    std::string placePath;

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "--selftest") == 0) selftest = true;
        else if (std::strcmp(argv[i], "--p3test") == 0) lifetest = true;
        else if (std::strcmp(argv[i], "--demo") == 0) demo = true;
        else if (std::strcmp(argv[i], "--stability-test") == 0) stability = true;
        else if (std::strcmp(argv[i], "--capture-sky") == 0) { demo=true;skytest=true; }
        else if (std::strcmp(argv[i], "--capture-spin") == 0 && i+1<argc) { spinFrames=std::atoi(argv[++i]);demo=true; }
        else if (std::strcmp(argv[i], "--content-root") == 0 && i+1<argc) contentRoot=argv[++i];
        else if (std::strcmp(argv[i], "--cachetest") == 0) cachetest = true;
        else if (std::strcmp(argv[i], "--frames") == 0 && i + 1 < argc) { frames = true; frameCount = std::atoi(argv[++i]); }
        else if (argv[i][0] != '-') placePath = argv[i];
    }
    if(stability && (!frames || frameCount<240)){std::printf("stability test requires --frames 240 or more\n");return 1;}

    if(contentRoot.empty()){
        char path[MAX_PATH];GetModuleFileNameA(0,path,sizeof(path));
        contentRoot=std::string(path).substr(0,std::string(path).find_last_of("\\/"))+"/Content";
    }
    if(!getenv("ROC_TEXTURE_STRIP"))_putenv(("ROC_TEXTURE_STRIP="+contentRoot+"/textures/SurfacesStrip.png").c_str());
    if(!std::ifstream(getenv("ROC_TEXTURE_STRIP"),std::ios::binary)){
        std::printf("missing SurfacesStrip.png; provide original Content with --content-root\n");return 1;
    }
    if(!selftest && !cachetest && !lifetest && !frames && placePath.empty())demo=true;

    if (selftest)
        placeText = kPartPlace;
    else if(demo)placeText=kDemoPlace;
    else
        placeText = placePath.empty() ? "" : readPlace(placePath.c_str());
    if(cachetest && placeText.empty()){std::printf("cachetest requires readable fixture\n");return 1;}
    if(lifetest && placeText.empty()){std::printf("p3test requires readable lifetime fixture\n");return 1;}
    if (!selftest && placeText.empty())
    {
        std::printf("could not read place: %s\n",placePath.c_str());return 1;
    }

    if (!selftest && LoadPlace(placeText.c_str()) != 0) { std::printf("place load failed\n"); return 1; }

    Ogre::Root* root = new Ogre::Root("", "", "player.log");
    if (!root) { std::printf("root failed\n"); ClosePlace(); return 2; }
    try { root->loadPlugin("rgdx.dll"); } catch (...) { std::printf("load plugin failed\n"); }
    Ogre::RenderSystem* rs = NULL;
    Ogre::RenderSystemList* rlist = root->getAvailableRenderers();
    for (size_t i = 0; i < rlist->size(); ++i)
    {
        if ((*rlist)[i]->getName().find("Direct3D9") != std::string::npos) rs = (*rlist)[i];
    }
    if (!rs) { std::printf("no d3d9 renderer\n"); delete root; ClosePlace(); return 3; }
    root->setRenderSystem(rs);
    rs->setConfigOption("Full Screen", "No");
    rs->setConfigOption("Video Mode", demo?"800 x 600 @ 32-bit colour":"320 x 240 @ 32-bit colour");
    Ogre::RenderWindow* win = root->initialise(true, "Player2008");
    if (!win) { std::printf("window failed\n"); delete root; ClosePlace(); return 4; }
    Ogre::SceneManager* sm = root->createSceneManager(Ogre::ST_GENERIC, "sm");
    g_sceneManager = sm;
    Ogre::Camera* cam = sm->createCamera("cam");
    cam->setPosition(0, 0, 10);
    cam->lookAt(0, 0, 0);
    cam->setNearClipDistance(0.1f);
    if(demo){cam->setPosition(6,4.5f,8);cam->lookAt(0,0,0);}
    Ogre::Viewport* vp = win->addViewport(cam);
    vp->setBackgroundColour(Ogre::ColourValue(1, 0, 1));
    if(demo){
        try{PlayerSkybox::apply(*sm,contentRoot);}
        catch(const std::exception& error){std::printf("skybox failed: %s\n",error.what());delete root;ClosePlace();return 8;}
    }
    if(skytest){
        cam->setPosition(0,0,0);cam->setFOVy(Ogre::Degree(90));
        const char* names[]={"front","back","left","right","up","down"};
        Ogre::Quaternion views[]={Ogre::Quaternion::IDENTITY,Ogre::Quaternion(Ogre::Degree(180),Ogre::Vector3::UNIT_Y),
            Ogre::Quaternion(Ogre::Degree(90),Ogre::Vector3::UNIT_Y),Ogre::Quaternion(Ogre::Degree(-90),Ogre::Vector3::UNIT_Y),
            Ogre::Quaternion(Ogre::Degree(90),Ogre::Vector3::UNIT_X),Ogre::Quaternion(Ogre::Degree(-90),Ogre::Vector3::UNIT_X)};
        for(int i=0;i<6;++i){
            cam->setOrientation(views[i]);std::string path=std::string("sky_")+names[i]+".png";
            if(!writeBackbuffer(win,path.c_str()))return 7;
        }
        delete root;ClosePlace();return 0;
    }

    if (selftest || cachetest || lifetest)
    {
        int rc = selftest ? runSelftest(root, win) : lifetest ? runLifetimeTest(root,win,placeText) : runCacheTest(root,win,placeText);
        SceneDetach();
        drawModels();
        PlayerBlockMesh::flushUnused();
        std::printf("mesh cleanup: levels=%u refs=%u backends=%u spheres=%u\n",PlayerBlockMesh::liveLevels(),PlayerBlockMesh::activeReferences(),PlayerMeshBackend::liveMeshes(),PlayerSphereCache::size());
        if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes() || PlayerSphereCache::size())rc=7;
        delete root;
        ClosePlace();
        return rc;
    }

    if (SceneAttach() != 0) { std::printf("scene attach failed\n"); delete root; ClosePlace(); return 6; }

    bool quick = (getenv("ROC_BUILD") != NULL);
    if(demo && spinFrames>0){
        for(int i=0;i<spinFrames;++i){
            SetPartYaw(i*6.28318530718f/spinFrames);drawModels();
            char name[64];_snprintf(name,sizeof(name),"spin_%04d.png",i);
            if(!writeBackbuffer(win,name))return 7;
        }
        std::printf("spin captured: frames=%d size=%ux%u\n",spinFrames,win->getWidth(),win->getHeight());
    }
    else if (quick)
    {
        drawModels();
        root->renderOneFrame(); if(!writeBackbuffer(win,"frame1.png"))return 7; std::printf("frame1 written\n");
        MovePartTo(4.0f, 0.0f, 0.0f);
        drawModels();
        root->renderOneFrame(); if(!writeBackbuffer(win,"frame2.png"))return 7; std::printf("frame2 written\n");
    }
    else if (frames)
    {
        float expectedY=0,initialFloorY=0,minY=1e30f,maxY=-1e30f;
        int anchored=0,tailSamples=0;bool stable=true,floorStable=true;
        std::ofstream samples;
        if(stability){
            if(GetContactState(&expectedY,&initialFloorY,&anchored)){std::printf("stability fixture needs Brick and Floor\n");return 9;}
            samples.open("stability_samples.csv",std::ios::binary);samples.precision(9);
            if(!samples)return 7;
            samples<<"frame,brick_y,floor_y,expected_y,anchored\n";
        }
        for (int i = 0; i < frameCount; ++i)
        {
            StepEngine(1.0f / 60.0f);
            drawModels();
            root->renderOneFrame(); win->update();
            if(stability){
                float x,y,z,currentExpected,floorY;
                GetPartPosition(&x,&y,&z);
                if(GetContactState(&currentExpected,&floorY,&anchored))return 9;
                floorStable=floorStable && anchored && std::fabs(floorY-initialFloorY)<.0001f && std::fabs(currentExpected-expectedY)<.0001f;
                samples<<(i+1)<<","<<y<<","<<floorY<<","<<currentExpected<<","<<anchored<<"\n";
                if(i>=frameCount/2){
                    ++tailSamples;stable=stable && std::fabs(y-expectedY)<=.01f;
                    minY=std::min(minY,y);maxY=std::max(maxY,y);
                }
            }
        }
        if(stability){
            stable=stable && floorStable && tailSamples>=120 && maxY-minY<=.002f;
            std::ofstream result("stability_result.json",std::ios::binary);result.precision(9);
            result<<"{\"pass\":"<<(stable?"true":"false")<<",\"frames\":"<<frameCount<<",\"expected_y\":"<<expectedY
                  <<",\"initial_floor_y\":"<<initialFloorY<<",\"floor_stable_and_anchored\":"<<(floorStable?"true":"false")
                  <<",\"tail_samples\":"<<tailSamples<<",\"tail_min_y\":"<<minY<<",\"tail_max_y\":"<<maxY<<"}\n";
            if(!result || !samples)return 7;
            std::printf("stability: %s tail=%d y=[%g,%g] expected=%g anchored=%d\n",stable?"PASS":"FAIL",tailSamples,minY,maxY,expectedY,anchored);
            if(!stable)stabilityExit=9;
        }
        float x, y, z;
        GetPartPosition(&x, &y, &z);
        std::printf("after %d frames: Brick at (%g,%g,%g), models=%d\n", frameCount, x, y, z, SceneModelCount());
        drawModels();
        root->renderOneFrame(); if(!writeBackbuffer(win,"last.png"))return 7;
    }
    else
    {
        Ogre::Timer timer;
        unsigned long last = timer.getMilliseconds();
        bool moved = false, removed = false;
        while (!win->isClosed())
        {
            Ogre::WindowEventUtilities::messagePump();
            if(win->isClosed())break;
            unsigned long now = timer.getMilliseconds();
            float dt = (now - last) / 1000.0f;
            if (dt <= 0) dt = 1.0f / 60.0f;
            last = now;

            Ogre::Vector3 camMove(0, 0, 0);
            if (GetAsyncKeyState('A') & 0x8000) camMove.x -= 1;
            if (GetAsyncKeyState('D') & 0x8000) camMove.x += 1;
            if (GetAsyncKeyState('W') & 0x8000) camMove.z -= 1;
            if (GetAsyncKeyState('S') & 0x8000) camMove.z += 1;
            if (GetAsyncKeyState('Q') & 0x8000) camMove.y += 1;
            if (GetAsyncKeyState('E') & 0x8000) camMove.y -= 1;
            cam->moveRelative(camMove * dt * 5.0f);

            if (!moved && (GetAsyncKeyState('M') & 0x8000)) { MovePartTo(4.0f, 0.0f, 0.0f); moved = true; }
            if (!removed && (GetAsyncKeyState('X') & 0x8000)) { RemovePart(); removed = true; }
            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

            StepEngine(dt);
            drawModels();
            root->renderOneFrame();
            win->update();
        }
    }

    SceneDetach();
    drawModels();
    PlayerBlockMesh::flushUnused();
    std::printf("mesh cleanup: levels=%u refs=%u backends=%u spheres=%u\n",PlayerBlockMesh::liveLevels(),PlayerBlockMesh::activeReferences(),PlayerMeshBackend::liveMeshes(),PlayerSphereCache::size());
    delete root;
    ClosePlace();
    return stabilityExit;
}
