#include <Ogre.h>
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

extern "C" int LoadPlace(const char* text);
extern "C" void GetPartPosition(float* x, float* y, float* z);
extern "C" void GetPartExtent(float* x, float* y, float* z);
extern "C" void GetPartColor(float* r, float* g, float* b);
extern "C" int  PartAlive(void);
extern "C" void MovePartTo(float x, float y, float z);
extern "C" void StepEngine(float dt);
extern "C" void ClosePlace();
extern "C" void RemovePart(void);

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
    return p[1] > 120 && p[0] < 90 && p[2] < 90;
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
    float size[3];
    float color[3];

    DrawEntry() : node(NULL), entity(NULL) { size[0] = size[1] = size[2] = 0; color[0] = color[1] = color[2] = 0; }
};

static Ogre::SceneManager* g_sceneManager = NULL;
static std::map<const void*, DrawEntry> g_drawn;

// Geometry is produced by recovered 004e2c80 and uploaded by 00549a50.
// Ogre Mesh here supplies entity bounds only; Level owns the detached RbxSubMesh.
static Ogre::MeshPtr createRecoveredMesh(const char* name, PlayerBlockMesh::BlockMesh* geometry, const float color[3])
{
    Ogre::MeshPtr existing=Ogre::MeshManager::getSingleton().getByName(name);
    if(!existing.isNull())return existing;
    PlayerBlockMesh::Level& level=geometry->level0();
    Ogre::AxisAlignedBox bounds;
    level.upload(false,bounds);
    Ogre::MeshPtr mesh=Ogre::MeshManager::getSingleton().createManual(name,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    // SDK SubMesh::getVertexAnimationType dereferences parent. Mesh is metadata
    // only: it does not adopt this Level-owned submesh into its deletion list.
    level.backend->parent=mesh.getPointer();
    std::string matName=std::string(name)+"_mat";
    Ogre::MaterialPtr mat=Ogre::MaterialManager::getSingleton().create(matName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    Ogre::Pass* pass=mat->getTechnique(0)->getPass(0);
    pass->setLightingEnabled(false);
    pass->setCullingMode(Ogre::CULL_NONE);
    // Recovered upload has no diffuse stream; fixed-function manual colour supplies Part colour.
    pass->setDiffuse(color[0],color[1],color[2],1.0f);
    Ogre::TextureUnitState* unit=pass->createTextureUnitState();
    unit->setColourOperationEx(Ogre::LBX_SOURCE1,Ogre::LBS_MANUAL,Ogre::LBS_CURRENT,Ogre::ColourValue(color[0],color[1],color[2]));
    level.backend->setMaterialName(matName);mat->load();
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
    entry.mesh.setNull();
    if(lastUser){
        Ogre::MeshManager::getSingleton().remove(name);
        Ogre::MaterialManager::getSingleton().remove(name+"_mat");
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
            entry.mesh = createRecoveredMesh(name.c_str(), model.geometry, model.color);
            entry.entity = new Ogre::RbxEntity();
            entry.entity->setMesh(entry.mesh);
            Ogre::SubMesh* subMesh = entry.geometry->level0().backend;
            entry.entity->createSubEntity(subMesh, 0);
            entry.node->attachObject(entry.entity);
            const Ogre::AxisAlignedBox& b = entry.entity->getBoundingBox();
            std::memcpy(entry.size, model.size, sizeof(entry.size));
            std::memcpy(entry.color, model.color, sizeof(entry.color));
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

    RemovePart();
    SceneBeginFrame();
    drawModels();
    Image removed;
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
            if(entry.geometry->levels.size()!=2 || entry.geometry->level0().backend->parent!=entry.mesh.getPointer())return 4;
            ++users[entry.geometry.getPointer()];
        }
        bool shared=false;
        for(std::map<PlayerBlockMesh::BlockMesh*,int>::iterator it=users.begin();it!=users.end();++it)
            if(it->second>1)shared=true;
        if(!shared)return 5;
        Image image;
        if(!capture(root,win,"cache_initial.png",image) || !countGreen(image,110,90,210,150))return 6;
        RemovePart();drawModels();
        if(g_drawn.size()!=8)return 7;
        for(std::map<const void*,DrawEntry>::iterator it=g_drawn.begin();it!=g_drawn.end();++it){
            DrawEntry& entry=it->second;
            if(entry.geometry->level0().backend->parent!=entry.mesh.getPointer() ||
               entry.entity->getMesh().getPointer()!=entry.mesh.getPointer() ||
               Ogre::MeshManager::getSingleton().getByName(entry.mesh->getName()).getPointer()!=entry.mesh.getPointer() ||
               entry.node->getPosition()!=Ogre::Vector3::ZERO)return 8;
        }
        if(!capture(root,win,"cache_remaining.png",image) || !countGreen(image,110,90,210,150))return 9;
        SceneDetach();drawModels();ClosePlace();PlayerBlockMesh::flushUnused();
        if(!g_drawn.empty() || PlayerBlockMesh::cachedMeshes() || PlayerBlockMesh::liveLevels() ||
           PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())return 10;
        if(resourceCount(Ogre::MeshManager::getSingleton())!=meshes ||
           resourceCount(Ogre::MaterialManager::getSingleton())!=materials)return 11;
        std::printf("cachetest cycle=%d models9->8->0 metadata/material baseline PASS\n",cycle);
    }
    return 0;
}

// ---------------------------------------------------------------------- main

int main(int argc, char** argv)
{
    bool selftest = false;
    bool cachetest = false;
    bool frames = false;
    int frameCount = 0;
    std::string placeText;
    std::string placePath;

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "--selftest") == 0) selftest = true;
        else if (std::strcmp(argv[i], "--cachetest") == 0) cachetest = true;
        else if (std::strcmp(argv[i], "--frames") == 0 && i + 1 < argc) { frames = true; frameCount = std::atoi(argv[++i]); }
        else if (argv[i][0] != '-') placePath = argv[i];
    }

    if (selftest)
        placeText = kPartPlace;
    else
        placeText = placePath.empty() ? "" : readPlace(placePath.c_str());
    if(cachetest && placeText.empty()){std::printf("cachetest requires readable fixture\n");return 1;}
    if (!selftest && placeText.empty())
    {
        std::printf("could not read %s; using built-in part place\n", placePath.empty() ? "(none)" : placePath.c_str());
        placeText = kPartPlace;
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
    rs->setConfigOption("Video Mode", "320 x 240 @ 32-bit colour");
    Ogre::RenderWindow* win = root->initialise(true, "Player2008");
    if (!win) { std::printf("window failed\n"); delete root; ClosePlace(); return 4; }
    Ogre::SceneManager* sm = root->createSceneManager(Ogre::ST_GENERIC, "sm");
    g_sceneManager = sm;
    Ogre::Camera* cam = sm->createCamera("cam");
    cam->setPosition(0, 0, 10);
    cam->lookAt(0, 0, 0);
    cam->setNearClipDistance(0.1f);
    Ogre::Viewport* vp = win->addViewport(cam);
    vp->setBackgroundColour(Ogre::ColourValue(1, 0, 1));

    if (selftest || cachetest)
    {
        int rc = selftest ? runSelftest(root, win) : runCacheTest(root,win,placeText);
        SceneDetach();
        drawModels();
        PlayerBlockMesh::flushUnused();
        std::printf("mesh cleanup: levels=%u refs=%u backends=%u\n",PlayerBlockMesh::liveLevels(),PlayerBlockMesh::activeReferences(),PlayerMeshBackend::liveMeshes());
        if(PlayerBlockMesh::liveLevels() || PlayerBlockMesh::activeReferences() || PlayerMeshBackend::liveMeshes())rc=7;
        delete root;
        ClosePlace();
        return rc;
    }

    if (SceneAttach() != 0) { std::printf("scene attach failed\n"); delete root; ClosePlace(); return 6; }

    bool quick = (getenv("ROC_BUILD") != NULL);
    if (quick)
    {
        drawModels();
        root->renderOneFrame(); if(!writeBackbuffer(win,"frame1.png"))return 7; std::printf("frame1 written\n");
        MovePartTo(4.0f, 0.0f, 0.0f);
        drawModels();
        root->renderOneFrame(); if(!writeBackbuffer(win,"frame2.png"))return 7; std::printf("frame2 written\n");
    }
    else if (frames)
    {
        for (int i = 0; i < frameCount; ++i)
        {
            StepEngine(1.0f / 60.0f);
            drawModels();
            root->renderOneFrame(); win->update();
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
    std::printf("mesh cleanup: levels=%u refs=%u backends=%u\n",PlayerBlockMesh::liveLevels(),PlayerBlockMesh::activeReferences(),PlayerMeshBackend::liveMeshes());
    delete root;
    ClosePlace();
    return 0;
}
