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
    Ogre::Entity* entity;
    Ogre::MeshPtr mesh;
    float size[3];
    float color[3];

    DrawEntry() : node(NULL), entity(NULL) { size[0] = size[1] = size[2] = 0; color[0] = color[1] = color[2] = 0; }
};

static Ogre::SceneManager* g_sceneManager = NULL;
static std::map<const void*, DrawEntry> g_drawn;

static void addFace(Ogre::ManualObject* object, const Ogre::Vector3& a, const Ogre::Vector3& bvec,
                    const Ogre::Vector3& c, const Ogre::Vector3& d,
                    float cr, float cg, float cb)
{
    object->position(a); object->colour(cr, cg, cb);
    object->position(bvec); object->colour(cr, cg, cb);
    object->position(c); object->colour(cr, cg, cb);
    object->position(a); object->colour(cr, cg, cb);
    object->position(c); object->colour(cr, cg, cb);
    object->position(d); object->colour(cr, cg, cb);
}

static bool sizeChanged(const DrawEntry& entry, const float size[3], const float color[3])
{
    for (int i = 0; i < 3; ++i)
    {
        if (std::fabs(entry.size[i] - size[i]) > 1e-4f) return true;
        if (std::fabs(entry.color[i] - color[i]) > 1e-4f) return true;
    }
    return false;
}


static Ogre::MeshPtr createBoxMesh(const char* name, const float size[3], const float color[3])
{
    const float hx = size[0] * 0.5f, hy = size[1] * 0.5f, hz = size[2] * 0.5f;
    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().createManual(name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    Ogre::SubMesh* sub = mesh->createSubMesh();

    Ogre::VertexData* vd = new Ogre::VertexData();
    mesh->sharedVertexData = vd;
    Ogre::VertexDeclaration* decl = vd->vertexDeclaration;
    decl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    decl->addElement(0, 12, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
    vd->vertexCount = 8;

    Ogre::HardwareVertexBufferSharedPtr vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        16, 8, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    unsigned char* raw = static_cast<unsigned char*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    const float corners[8][3] = {
        {-hx,-hy,-hz}, {hx,-hy,-hz}, {hx,hy,-hz}, {-hx,hy,-hz},
        {-hx,-hy,hz}, {hx,-hy,hz}, {hx,hy,hz}, {-hx,hy,hz}
    };
    Ogre::ColourValue cv(color[0], color[1], color[2], 1.0f);
    Ogre::ARGB argb = cv.getAsARGB();
    for (int i = 0; i < 8; ++i)
    {
        float* fp = reinterpret_cast<float*>(raw + i * 16);
        fp[0] = corners[i][0];
        fp[1] = corners[i][1];
        fp[2] = corners[i][2];
        *reinterpret_cast<Ogre::ARGB*>(raw + i * 16 + 12) = argb;
    }
    vbuf->unlock();
    vd->vertexBufferBinding->setBinding(0, vbuf);

    Ogre::IndexData* id = sub->indexData;
    id->indexCount = 36;
    Ogre::HardwareIndexBufferSharedPtr ibuf = Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(
        Ogre::HardwareIndexBuffer::IT_16BIT, 36, Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);
    unsigned short* ip = static_cast<unsigned short*>(ibuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    static const unsigned short indices[36] = {
        0,1,2, 0,2,3,
        4,6,5, 4,7,6,
        1,5,6, 1,6,2,
        0,3,7, 0,7,4,
        3,2,6, 3,6,7,
        0,4,5, 0,5,1
    };
    for (int i = 0; i < 36; ++i) ip[i] = indices[i];
    ibuf->unlock();
    id->indexBuffer = ibuf;

    sub->useSharedVertices = true;

    std::string matName = std::string(name) + "_mat";
    Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().create(matName, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    Ogre::Pass* pass = mat->getTechnique(0)->getPass(0);
    pass->setLightingEnabled(false);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setAmbient(color[0], color[1], color[2]);
    pass->setDiffuse(color[0], color[1], color[2], 1.0f);
    sub->setMaterialName(matName);
    mat->load();

    mesh->_setBounds(Ogre::AxisAlignedBox(-hx, -hy, -hz, hx, hy, hz));
    mesh->_setBoundingSphereRadius(std::sqrt(hx*hx + hy*hy + hz*hz));
    mesh->load();
    return mesh;
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
        if (!entry.entity || sizeChanged(entry, model.size, model.color))
        {
            if (entry.entity)
            {
                entry.node->detachObject(entry.entity);
                entry.entity = NULL;
                entry.mesh.setNull();
            }
            std::string name = "mesh_";
            char suffix[32];
            _snprintf(suffix, sizeof(suffix), "%p", model.id);
            name += suffix;
            entry.mesh = createBoxMesh(name.c_str(), model.size, model.color);
            Ogre::RbxEntity* trace = new Ogre::RbxEntity();
            trace->setMesh(entry.mesh);
            Ogre::SubMesh* subMesh = entry.mesh->getSubMesh(0);
            trace->createSubEntity(subMesh, 0);
            (void)trace;
            entry.entity = g_sceneManager->createEntity(name.c_str(), entry.mesh->getName());
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
            }
            it->second.entity = NULL;
            it->second.mesh.setNull();
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

static bool capture(Ogre::Root* root, Ogre::RenderWindow* win, const char* path, Image& image)
{
    root->renderOneFrame();
    win->update();
    Sleep(100);
    win->writeContentsToFile(path);
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

// ---------------------------------------------------------------------- main

int main(int argc, char** argv)
{
    bool selftest = false;
    bool frames = false;
    int frameCount = 0;
    std::string placeText;
    std::string placePath;

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "--selftest") == 0) selftest = true;
        else if (std::strcmp(argv[i], "--frames") == 0 && i + 1 < argc) { frames = true; frameCount = std::atoi(argv[++i]); }
        else if (argv[i][0] != '-') placePath = argv[i];
    }

    if (selftest)
        placeText = kPartPlace;
    else
        placeText = placePath.empty() ? "" : readPlace(placePath.c_str());
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

    if (selftest)
    {
        int rc = runSelftest(root, win);
        SceneDetach();
        delete root;
        ClosePlace();
        return rc;
    }

    if (SceneAttach() != 0) { std::printf("scene attach failed\n"); delete root; ClosePlace(); return 6; }

    bool quick = (getenv("ROC_BUILD") != NULL);
    if (quick)
    {
        drawModels();
        root->renderOneFrame(); win->update(); win->writeContentsToFile("frame1.png"); std::printf("frame1 written\n");
        MovePartTo(4.0f, 0.0f, 0.0f);
        drawModels();
        root->renderOneFrame(); win->update(); win->writeContentsToFile("frame2.png"); std::printf("frame2 written\n");
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
        root->renderOneFrame(); win->update(); win->writeContentsToFile("last.png");
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
    delete root;
    ClosePlace();
    return 0;
}