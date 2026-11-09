/**
  @file measurePerformance.cpp
  
  Measures the performance of rendering in various modes on this machine.

 */
#include "../include/G3DAll.h"

// All return FPS
float measureBeginEndPerformance(class Model&);
float measureDrawElementsRAMPerformance(class Model&);
float measureDrawElementsVBOPerformance(class Model&);
float measureDrawElementsVBO16Performance(class Model&);
float measureDrawElementsVBOIPerformance(class Model&);
float measureDrawElementsVBOPeakPerformance(class Model&);
float measureDrawArraysVBOPeakPerformance(class Model&);

/** Number of frames to render in tests */
static const int frames = 15;

/** How fast to rotate the objects */
static const float kstep = 360.0f / (frames + 2.0f);

/** Number of models per frame */
int count = 5;

class Model {
private:

    TextureRef          tex;

public:

    class Vec2 {
    public:
        float x, y;
    };

    class Vec3 {
    public:
        float x, y, z;
    };

    class Vec4 {
    public:
        float x, y, z, w;
    };

    std::vector<unsigned int>       cpuIndex;
    std::vector<unsigned short>     cpuIndex16;
    std::vector<Vec3>               cpuVertex;
    std::vector<Vec2>               cpuTexCoord;
    std::vector<Vec4>               cpuColor;
    std::vector<Vec3>               cpuNormal;

    GLuint                          textureID;

    /** Flattens an existing model so that the indices are linear */
    void flatten() {
        const Model source(*this);

        int N = source.cpuIndex.size();
        cpuVertex.resize(N);
        cpuTexCoord.resize(N);
        cpuColor.resize(N);
        cpuNormal.resize(N);
        cpuIndex.resize(0);
        cpuIndex16.resize(0);

        for (int i = 0; i < N; ++i) {
            int v = source.cpuIndex[i];
            cpuVertex[i] = source.cpuVertex[v];
            cpuTexCoord[i] = source.cpuTexCoord[v];
            cpuColor[i] = source.cpuColor[v];
            cpuNormal[i] = source.cpuNormal[v];
        }
    }

    /** If given an IFS filename, loads it, otherwise generates
        a gear with high vertex coherence.
        Only the constructor uses G3D.  */
    Model(const std::string& filename) {

        tex = Texture::fromFile("tiny.jpg");
        textureID = tex->getOpenGLID();

        if (filename != "") {
            PosedModelRef m = IFSModel::create(filename)->pose();
            // Copy fields out into arrays
            {
                const Array<int>& index = m->triangleIndices();
                int N = index.size();
                cpuIndex.resize(N);
                System::memcpy(&cpuIndex[0], index.getCArray(), sizeof(int) * N);
            }

            {
                const MeshAlg::Geometry& g = m->objectSpaceGeometry(); 
                int N = g.vertexArray.size();
                cpuVertex.resize(N);
                cpuNormal.resize(N);
                cpuColor.resize(N);
                cpuTexCoord.resize(N);
                System::memcpy(&cpuVertex[0], g.vertexArray.getCArray(), N * sizeof(Vec3));
                System::memcpy(&cpuNormal[0], g.normalArray.getCArray(), N * sizeof(Vec3));

                for (int i = 0; i < N; ++i) {
                    // Copy the normals over the colors, too
                    cpuColor[i].x = g.normalArray[i].x * 0.5 + 0.5;
                    cpuColor[i].y = g.normalArray[i].y * 0.5 + 0.5;
                    cpuColor[i].z = g.normalArray[i].z * 0.5 + 0.5;
                    cpuColor[i].w = 1.0f;

                    // Cylindrical projection to get tex coords
                    Vector3 dir = g.vertexArray[i].direction();
                    cpuTexCoord[i].x = (atan2(dir.x, dir.z) / G3D_TWO_PI + 0.5) * 5;
                    cpuTexCoord[i].y = (0.5 - dir.y * 0.5) * 5;
                }
            }
        } else {

            // Generate gear
            // Vertices per side
            const int sq = 187;

            // Number of indices
            const int N = (sq - 1) * (sq - 1) * 3 * 2;

            // Number of vertices
            const int V = sq * sq;

            // Make a grid of triangles
            cpuIndex.resize(N);
            {
                int k = 0;
                for (int i = 0; i < sq - 1; ++i) {
                    for (int j = 0; j < sq - 1; ++j) {
                        debugAssert(k < N - 5);

                        // Bottom triangle
                        cpuIndex[k + 0] = i + j * sq;
                        cpuIndex[k + 1] = i + (j + 1) * sq;
                        cpuIndex[k + 2] = (i + 1) + (j + 1) * sq;

                        // Top triangle
                        cpuIndex[k + 3] = i + j * sq;
                        cpuIndex[k + 4] = (i + 1) + (j + 1) * sq;
                        cpuIndex[k + 5] = (i + 1) + j * sq;

                        k += 6;
                    }
                }
            }

            // Create data
            cpuVertex.resize(V);
            cpuNormal.resize(V);
            cpuTexCoord.resize(V);
            cpuColor.resize(V);

            // Map V indices to a sq x sq grid
            for (int i = 0; i < sq; ++i) {
                for (int j = 0; j < sq; ++j) {

                    int v = (i + j * sq);

                    float x = (i / (float)sq - 0.5) * 2;
                    float y = 0.5 - j / (float)sq;
                    float a = x * 2 * 3.1415927;
                    float r = ceil(cos(a * 10)) * 0.05 + 0.3;

                    cpuVertex[v].x = -cos(a) * r;
                    cpuVertex[v].y = y;
                    cpuVertex[v].z = sin(a) * r;

                    // Scale the normal
                    float s = 1.0 / sqrt(0.0001 + square(cpuVertex[v].x) + square(cpuVertex[v].y) + square(cpuVertex[v].z));
                    cpuNormal[v].y = cpuVertex[v].x * s;
                    cpuNormal[v].x = cpuVertex[v].y * s;
                    cpuNormal[v].z = cpuVertex[v].z * s;

                    cpuColor[v].x = r + 0.7;
                    cpuColor[v].y = 0.5;
                    cpuColor[v].z = 1.0 - r;
                    cpuColor[v].w = 1.0f;

                    cpuTexCoord[v].x = i / (float)sq;
                    cpuTexCoord[v].y = j / (float)sq;
                }
            }
        } // if

        cpuIndex16.resize(cpuIndex.size());
        for (uint16 i = 0; i < cpuIndex.size(); ++i) {
            cpuIndex16[i] = (uint16)cpuIndex[i];
        }
    }
};

static GWindow* window = NULL;
void glSwapBuffers() {
    window->swapGLBuffers();
}

void measureVertexPerformance(
    GWindow* w,     
    int&    numTris,
    float   beginEndFPS[2],
    float   drawElementsRAMFPS[2], 
    float   drawElementsVBOFPS[2], 
    float   drawElementsVBO16FPS[2], 
    float   drawElementsVBOIFPS[2],
    float   drawElementsVBOPeakFPS[2],
    float&  drawArraysVBOPeakFPS) {

    window = w;
    std::string filename = "bunny.ifs";

    glPushAttrib(GL_ALL_ATTRIB_BITS);

    for (int i = 0; i < 2; ++i) {
        Model model(filename);

        beginEndFPS[i] = measureBeginEndPerformance(model);
        drawElementsRAMFPS[i] = measureDrawElementsRAMPerformance(model);
        drawElementsVBOFPS[i] = measureDrawElementsVBOPerformance(model);
        drawElementsVBO16FPS[i] = measureDrawElementsVBO16Performance(model);
        drawElementsVBOIFPS[i] = measureDrawElementsVBOIPerformance(model);
        drawElementsVBOPeakFPS[i] = measureDrawElementsVBOPeakPerformance(model);

        numTris = count * model.cpuIndex.size() / 3;

        if (i == 1) {
            model.flatten();
            drawArraysVBOPeakFPS = measureDrawArraysVBOPeakPerformance(model);
        }
        // Second time around, load the gear
        filename = "";
    }

    glPopAttrib();
}


static void configureCameraAndLights() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float w = 0.8f, h = 0.6f;
    glFrustum(-w/2, w/2, -h/2, h/2, 0.5f, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);

    glCullFace(GL_BACK);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        float pos[4] = {-1.0f, 1.0f, 1.0f, 0.0f};
        glLightfv(GL_LIGHT0, GL_POSITION, pos);

        float col[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, col);

    }

    glEnable(GL_LIGHT1);
    {
        float pos[4] = {1.0f, -1.0f, 1.0f, 0.0f};
        glLightfv(GL_LIGHT1, GL_POSITION, pos);

        float col[4] = {0.4f, 0.1f, 0.1f, 1.0f};
        glLightfv(GL_LIGHT1, GL_DIFFUSE, col);
    }

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    {
        float amb[4] = {0.5f, 0.5f, 0.5f, 1.0f};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
    }

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}


float measureBeginEndPerformance(Model& model) {

    int N = model.cpuIndex.size();
    const unsigned int*   index   = &model.cpuIndex[0];
    const float* vertex  = reinterpret_cast<const float*>(&model.cpuVertex[0]);
    const float* normal  = reinterpret_cast<const float*>(&model.cpuNormal[0]);
    const float* color   = reinterpret_cast<const float*>(&model.cpuColor[0]);
    const float* texCoord= reinterpret_cast<const float*>(&model.cpuTexCoord[0]);

    glPushAttrib(GL_ALL_ATTRIB_BITS);

    configureCameraAndLights();
    

    float k = 0;

    double t0 = 0, t1 = 0;
    for (int j = 0; j < frames + 1; ++j) {
        // Don't count the first frame against us; it is cache warmup
        if (j == 1) {
            t0 = System::time();
        }
        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, model.textureID);

        for (int c = 0; c < count; ++c) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glBegin(GL_TRIANGLES);
            for (int i = 0; i < N; ++i) {
                const int v = index[i];
                const int v3 = 3 * v;
                glColor4fv(color + v * 4);
                glTexCoord2fv(texCoord + v + v);
                glNormal3fv(normal + v3);
                glVertex3fv(vertex + v3);
            }
            glEnd();
        }

        glSwapBuffers();
    }
    glFinish();
    t1 = System::time();

    glPopAttrib();

    return frames / (System::time() - t0);
}


float measureDrawElementsRAMPerformance(Model& model) {

    // Number of indices
    const int N = model.cpuIndex.size();
    // Number of vertices
    const int V = model.cpuVertex.size();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    configureCameraAndLights();
    
    float k = 0;

    double t0 = 0, t1 = 0;
    glFinish();
    for (int j = 0; j < frames + 1; ++j) {
        // Don't count the first frame against us; it is cache warmup
        if (j == 1) {
            t0 = System::time();
        }
        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, model.textureID);

        for (int c = 0; c < count; ++c) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glNormalPointer(GL_FLOAT, 0, &model.cpuNormal[0]);
            glColorPointer(4, GL_FLOAT, 0, &model.cpuColor[0]);
            glTexCoordPointer(2, GL_FLOAT, 0, &model.cpuTexCoord[0]);
            glVertexPointer(3, GL_FLOAT, 0, &model.cpuVertex[0]);

            glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_INT, &model.cpuIndex[0]);
        }

        glSwapBuffers();
    }
    glFinish();
    t1 = System::time();

    glPopClientAttrib();
    glPopAttrib();

    return frames / (t1 - t0);
}


float measureDrawElementsVBOPerformance(Model& model) {

    bool hasVBO = 
        (strstr((char*)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_buffer_object") != NULL) &&
            (glGenBuffersARB != NULL) && 
            (glBufferDataARB != NULL) &&
            (glDeleteBuffersARB != NULL);

    if (! hasVBO) {
        return 0.0;
    }

    int N = model.cpuIndex.size();
    int V = model.cpuVertex.size();

    size_t vertexSize   = V * sizeof(float) * 3;
    size_t normalSize   = V * sizeof(float) * 3;
    size_t colorSize    = V * sizeof(float) * 4;
    size_t texCoordSize = V * sizeof(float) * 2;
    size_t totalSize    = vertexSize + normalSize + texCoordSize + colorSize;

    size_t indexSize    = N * sizeof(int);

    double t0 = 0;

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

        GLuint vbo, indexBuffer;
        glGenBuffersARB(1, &vbo);
        glGenBuffersARB(1, &indexBuffer);

        // Pointers relative to the start of the vbo in video memory
        GLintptrARB vertexPtr   = 0;
        GLintptrARB normalPtr   = vertexSize + vertexPtr;
        GLintptrARB texCoordPtr = normalSize  + normalPtr;
        GLintptrARB colorPtr    = texCoordSize + texCoordPtr;

        GLintptrARB indexPtr    = 0;

        // Upload data
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
        glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexSize, &model.cpuIndex[0], GL_STATIC_DRAW_ARB);

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, totalSize, NULL, GL_STATIC_DRAW_ARB);

        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, texCoordPtr, texCoordSize, &model.cpuTexCoord[0]);
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, normalPtr,   normalSize,   &model.cpuNormal[0]);
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, colorPtr,    colorSize,    &model.cpuColor[0]);
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, vertexPtr,   vertexSize,   &model.cpuVertex[0]);
        double t1;

        {
            float k = 0;
            configureCameraAndLights();
            glDisable(GL_TEXTURE_2D);
            glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
            glColor3f(1, .5, 0);
            glFinish();
            for (int j = 0; j < frames + 1; ++j) {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                // Don't count the first frame against us; it is cache warmup
                if (j == 1) {
                    t0 = System::time();
                }
                k += kstep;

                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, model.textureID);

                glEnableClientState(GL_NORMAL_ARRAY);
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glEnableClientState(GL_VERTEX_ARRAY);

                glNormalPointer(GL_FLOAT, 0, (void*)normalPtr);
                glTexCoordPointer(2, GL_FLOAT, 0, (void*)texCoordPtr);
                glColorPointer(4, GL_FLOAT, 0, (void*)colorPtr);
                glVertexPointer(3, GL_FLOAT, 0, (void*)vertexPtr);

                for (int c = 0; c < count; ++c) {
                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                    glTranslatef(c - (count - 1) / 2.0, 0, -2);
                    glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

                    glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_INT, (void*)indexPtr);
                }
                glSwapBuffers();
            }
            glFinish();
            t1 = System::time();
        }


    glPopClientAttrib();
    glPopAttrib();

    glDeleteBuffersARB(1, &indexBuffer);
    glDeleteBuffersARB(1, &vbo);

    return frames / (t1 - t0);
}



float measureDrawElementsVBO16Performance(Model& model) {
    
    bool hasVBO = 
        (strstr((char*)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_buffer_object") != NULL) &&
            (glGenBuffersARB != NULL) && 
            (glBufferDataARB != NULL) &&
            (glDeleteBuffersARB != NULL);

    if (! hasVBO) {
        return 0.0;
    }

    // Load the vertex arrays

    // Number of indices
    const int N = model.cpuIndex.size();
    // Number of vertices
    const int V = model.cpuVertex.size();
    
    GLuint vbo, indexBuffer;
    glGenBuffersARB(1, &vbo);
    glGenBuffersARB(1, &indexBuffer);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    size_t vertexSize   = V * sizeof(float) * 3;
    size_t normalSize   = V * sizeof(float) * 3;
    size_t texCoordSize = V * sizeof(float) * 2;
    size_t colorSize    = V * sizeof(float) * 4;   
    size_t totalSize    = vertexSize + normalSize + texCoordSize + colorSize;

    size_t indexSize    = N * sizeof(unsigned short);

    // Pointers relative to the start of the vbo in video memory
    // (would interleaving be faster?)
    GLintptrARB vertexPtr   = 0;
    GLintptrARB normalPtr   = vertexSize + vertexPtr;
    GLintptrARB colorPtr    = normalSize + normalPtr;
    GLintptrARB texCoordPtr = colorSize  + colorPtr;

    GLintptrARB indexPtr    = 0;

    // Upload data
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexSize, &model.cpuIndex16[0], GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, totalSize, NULL, GL_STATIC_DRAW_ARB);

    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, vertexPtr,  vertexSize, &model.cpuVertex[0]);
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, colorPtr,       colorSize, &model.cpuColor[0]);
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, normalPtr,      normalSize, &model.cpuNormal[0]);
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, texCoordPtr, texCoordSize, &model.cpuTexCoord[0]);

    configureCameraAndLights();
    
    float k = 0;

    double t0 = 0, t1 = 0;
    for (int j = 0; j < frames + 1; ++j) {
        if (j == 1) {
            t0 = System::time();
        }

        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, model.textureID);

        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);

        glColorPointer(4, GL_FLOAT, 0, (void*)colorPtr);
        glTexCoordPointer(2, GL_FLOAT, 0, (void*)texCoordPtr);
        glNormalPointer(GL_FLOAT, 0, (void*)normalPtr);
        glVertexPointer(3, GL_FLOAT, 0, (void*)vertexPtr);

        for (int c = 0; c < count; ++c) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_SHORT, (void*)indexPtr);
        }

        glSwapBuffers();

    }

    glFinish();
    t1 = System::time();

    glPopClientAttrib();
    glPopAttrib();

    glDeleteBuffersARB(1, &indexBuffer);
    glDeleteBuffersARB(1, &vbo);

    return frames / (t1 - t0);
}



float measureDrawElementsVBOIPerformance(Model& model) {
    
    bool hasVBO = 
        (strstr((char*)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_buffer_object") != NULL) &&
            (glGenBuffersARB != NULL) && 
            (glBufferDataARB != NULL) &&
            (glDeleteBuffersARB != NULL);

    if (! hasVBO) {
        return 0.0;
    }

    // Load the vertex arrays

    // Number of indices
    const int N = model.cpuIndex.size();
    // Number of vertices
    const int V = model.cpuVertex.size();

    GLuint vbo, indexBuffer;
    glGenBuffersARB(1, &vbo);
    glGenBuffersARB(1, &indexBuffer);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    size_t vertexSize   = V * sizeof(float) * 3;
    size_t normalSize   = V * sizeof(float) * 3;
    size_t colorSize    = V * sizeof(float) * 4;   
    size_t texCoordSize = V * sizeof(float) * 2;
    size_t totalSize    = vertexSize + normalSize + texCoordSize + colorSize;

    size_t indexSize    = N * sizeof(int);

    // Pointers relative to the start of the vbo in video memory
    // (would interleaving be faster?)
    GLintptrARB texCoordPtr = 0;
    GLintptrARB colorPtr    = texCoordPtr + 2 * sizeof(float);
    GLintptrARB normalPtr   = colorPtr  + 4 * sizeof(float);
    GLintptrARB vertexPtr   = normalPtr + 3 * sizeof(float);

    GLintptrARB indexPtr    = 0;

    // Upload data
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, N * sizeof(unsigned short), &model.cpuIndex16[0], GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    float* interleave = (float*)malloc(totalSize);
    // Interleave the buffers in memory
    float* ptr = interleave;
    for (int i = 0; i < V; ++i) {
        ptr[0] = model.cpuTexCoord[i].x;
        ++ptr;
        ptr[0] = model.cpuTexCoord[i].y;
        ++ptr;

        ptr[0] = model.cpuColor[i].x;
        ++ptr;
        ptr[0] = model.cpuColor[i].y;
        ++ptr;
        ptr[0] = model.cpuColor[i].z;
        ++ptr;
        ptr[0] = model.cpuColor[i].w;
        ++ptr;

        ptr[0] = model.cpuNormal[i].x;
        ++ptr;
        ptr[0] = model.cpuNormal[i].y;
        ++ptr;
        ptr[0] = model.cpuNormal[i].z;
        ++ptr;

        ptr[0] = model.cpuVertex[i].x;
        ++ptr;
        ptr[0] = model.cpuVertex[i].y;
        ++ptr;
        ptr[0] = model.cpuVertex[i].z;
        ++ptr;
    }
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, totalSize, interleave, GL_STATIC_DRAW_ARB);
    free(interleave);

    configureCameraAndLights();
    
    float k = 0;

    double t0 = 0, t1 = 0;
    for (int j = 0; j < frames + 1; ++j) {
        if (j == 1) {
            t0 = System::time();
        }
        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, model.textureID);

        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glInterleavedArrays(GL_T2F_C4F_N3F_V3F, 0, (void*)0);

        for (int c = 0; c < count; ++c) {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_SHORT, (void*)indexPtr);
        }

        glSwapBuffers();

    }
    glFinish();
    t1 = System::time();


    glPopClientAttrib();
    glPopAttrib();

    glDeleteBuffersARB(1, &indexBuffer);
    glDeleteBuffersARB(1, &vbo);

    return frames / (t1 - t0);
}


float measureDrawElementsVBOPeakPerformance(Model& model) {
    
    bool hasVBO = 
        (strstr((char*)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_buffer_object") != NULL) &&
            (glGenBuffersARB != NULL) && 
            (glBufferDataARB != NULL) &&
            (glDeleteBuffersARB != NULL);

    if (! hasVBO) {
        return 0.0;
    }

    // Load the vertex arrays

    // Number of indices
    const int N = model.cpuIndex.size();
    // Number of vertices
    const int V = model.cpuVertex.size();

    GLuint vbo, indexBuffer;
    glGenBuffersARB(1, &vbo);
    glGenBuffersARB(1, &indexBuffer);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    size_t vertexSize   = V * sizeof(float) * 3;
    size_t totalSize    = vertexSize;
    size_t indexSize    = N * sizeof(unsigned short);

    GLintptrARB vertexPtr   = 0;
    GLintptrARB indexPtr    = 0;

    // Upload data
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexSize, &model.cpuIndex16[0], GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, vertexSize, &model.cpuVertex[0], GL_STATIC_DRAW_ARB);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float w = 0.8f, h = 0.6f;
    glFrustum(-w/2, w/2, -h/2, h/2, 0.5f, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);
    glDisable(GL_NORMALIZE);
    glDisable(GL_COLOR_MATERIAL);

    glCullFace(GL_BACK);
    
    float k = 0;

    double t0 = 0, t1 = 0;
    glFinish();
    for (int j = 0; j < frames + 1; ++j) {
        if (j == 1) {
            t0 = System::time();
        }
        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);

        for (int c = 0; c < count; ++c) {
            static const float col[] = {1, 0, 0, 1, 0, 0};
            glColor3fv(col + (c % 3));

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glVertexPointer(3, GL_FLOAT, 0, (void*)vertexPtr);
            glDrawElements(GL_TRIANGLES, N, GL_UNSIGNED_SHORT, (void*)indexPtr);
        }

        glSwapBuffers();
    }
    glFinish();
    t1 = System::time();

    glPopClientAttrib();
    glPopAttrib();

    glDeleteBuffersARB(1, &indexBuffer);
    glDeleteBuffersARB(1, &vbo);
    glFinish();

    return frames / (t1 - t0);
}

float measureDrawArraysVBOPeakPerformance(Model& model) {
    
    bool hasVBO = 
        (strstr((char*)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_buffer_object") != NULL) &&
            (glGenBuffersARB != NULL) && 
            (glBufferDataARB != NULL) &&
            (glDeleteBuffersARB != NULL);

    if (! hasVBO) {
        return 0.0;
    }

    // Load the vertex arrays

    // Number of vertices
    const int V = model.cpuVertex.size();

    GLuint vbo, indexBuffer;
    glGenBuffersARB(1, &vbo);
    glGenBuffersARB(1, &indexBuffer);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    size_t vertexSize   = V * sizeof(float) * 3;
    size_t totalSize    = vertexSize;

    GLintptrARB vertexPtr   = 0;

    // Upload data
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, vertexSize, &model.cpuVertex[0], GL_STATIC_DRAW_ARB);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float w = 0.8f, h = 0.6f;
    glFrustum(-w/2, w/2, -h/2, h/2, 0.5f, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);
    glDisable(GL_NORMALIZE);
    glDisable(GL_COLOR_MATERIAL);

    glCullFace(GL_BACK);
    
    float k = 0;

    double t0 = 0, t1 = 0;
    glFinish();
    for (int j = 0; j < frames + 1; ++j) {
        if (j == 1) {
            t0 = System::time();
        }
        k += kstep;
        glClearColor(1.0f, 1.0f, 1.0f, 0.04f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);

        for (int c = 0; c < count; ++c) {
            static const float col[] = {1, 0, 0, 1, 0, 0};
            glColor3fv(col + (c % 3));

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(c - (count - 1) / 2.0, 0, -2);
            glRotatef(k * ((c & 1) * 2 - 1) + 90, 0, 1, 0);

            glVertexPointer(3, GL_FLOAT, 0, (void*)vertexPtr);
            glDrawArrays(GL_TRIANGLES, 0, V);
        }

        glSwapBuffers();
    }
    glFinish();
    t1 = System::time();

    glPopClientAttrib();
    glPopAttrib();

    glDeleteBuffersARB(1, &indexBuffer);
    glDeleteBuffersARB(1, &vbo);
    glFinish();

    return frames / (t1 - t0);
}
