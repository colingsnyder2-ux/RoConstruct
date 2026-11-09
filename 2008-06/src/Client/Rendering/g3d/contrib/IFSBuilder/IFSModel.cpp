/**
  @file MeshBuilder/XIFSModel.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @cite 3DS loader based on code by Max McGuire and Matthew Fairfax
  @cite MD2 format by id software

  @created 2002-02-27
  @edited  2004-10-27
 */

#include "IFSModel.h"
#include "MD2.h"
#include "Load3DS.h"

extern RenderDevice* renderDevice;
extern GCamera       camera;
extern CFontRef      font;



static double gaussian2D(double x, double z) {
    return exp(-4 * (square(x) + square(z)));
}


static double bump2D(double x, double z) {
    double t = min(G3D_PI, 7 * sqrt(square(x) + square(z)) / sqrt(0.5));
    return cos(t) * .15;
}

static double saddle2D(double x, double z) {
    return (square(x*1.5) - square(z*1.5)) * .75;
}

static double flat2D(double x, double z) {
    return 0.0;
}


static double sin2D(double x, double z) {
    static double angle = toRadians(-25);
    double t = G3D_TWO_PI * (cos(angle) * x + sin(angle) * z);
    return sin(t * 2) * 0.1;
}

static double lumpy2D(double x, double z) {
    x *= G3D_TWO_PI;
    z *= G3D_TWO_PI;
    return 
        (cos(x) * 0.1 + cos(2*x + 1) * 0.15 + cos(3*x - 2) * 0.1 + cos(5*x + 4) * 0.05 - x * .1 +
         cos(z) * 0.2 + cos(2.5*z - 1) * 0.15 + cos(4*z + 2) * 0.15 + cos(5*z + 4) * 0.05 - z * .1) / 2;
}


static double cliff2D(double x, double z) {
	if (x + z > .25) {
		return 0.5;
	} else {
		return 0.0;
	}
}


void XIFSModel::set(MeshBuilder& builder) {
    Array<int> indexArray;
    builder.commit(name, indexArray, geometry.vertexArray);

    triangleArray.resize(indexArray.size() / 3);
    for (int t = 0; t < triangleArray.size(); ++t) {
        int i = t * 3;
        for (int j = 0; j < 3; ++j) {
            triangleArray[t].index[j] = indexArray[i + j];
        }
    }

    Array<MeshAlg::Face> faceArray;
    Array<Array<int> >   adjacentFaceArray;

    // Apply a transformation.
    /*
    CoordinateFrame cframe;
    cframe.rotation = Matrix3::fromAxisAngle(Vector3::UNIT_Y, toRadians(180));
    for (int i = 0; i < geometry.vertexArray.size(); ++i) {
        geometry.vertexArray[i] = cframe.pointToWorldSpace(geometry.vertexArray[i]);
    }
    */

    MeshAlg::computeAdjacency(geometry.vertexArray, indexArray, faceArray, edgeArray, adjacentFaceArray);
    MeshAlg::computeNormals(geometry.vertexArray, faceArray, adjacentFaceArray, geometry.normalArray, faceNormalArray);

    // Find broken edges
    brokenEdgeArray.resize(0);
    for (int e = 0; e < edgeArray.size(); ++e) {
        const MeshAlg::Edge& edge = edgeArray[e];

        debugAssert(edge.vertexIndex[0] != edge.vertexIndex[1]);

        if ((edge.faceIndex[1] == MeshAlg::Face::NONE) ||
            (edge.faceIndex[0] == MeshAlg::Face::NONE) ||
            (edge.faceIndex[0] == edge.faceIndex[1])) {
            // Dangling edge
            brokenEdgeArray.append(edge);
        } else {
            // Each vertex must appear in each adjacent face.  If it doesn't, something
            // has gone wrong.
            int numFound = 0;
            // Check each vertex
            for (int i = 0; i < 2; ++i) {
                // Check each face
                for (int j = 0; j < 2; ++j) {
                    const int f = edge.faceIndex[j];
                    const MeshAlg::Face& face = faceArray[f];
                    for (int j = 0; j < 3; ++j) {
                        if (geometry.vertexArray[face.vertexIndex[j]] == 
                            geometry.vertexArray[edge.vertexIndex[i]]) {
                            ++numFound;
                            break;
                        }
                    }
                }
            }

            if (numFound < 4) {
                brokenEdgeArray.append(edge);
            }
        }
    }
}


XIFSModel::XIFSModel(const std::string& filename, bool t) : _twoSided(t) {
    if (! fileExists(filename)) {
        error("Critical Error", std::string("File not found: \"") + filename + "\"", true);
        exit(-1);
    }

    std::string f = toLower(filename);

    createCylinder(); return;

    //createHalfGear(); return;
    //createGrid(flat2D, 1024, true); return;
    //createGrid(lumpy2D, 1024, true); return;
    //createGrid(cliff2D, 1024, true); return;
    //createIsoGrid(cliff2D, 1024); return;
    //createGrid(bump2D, 900, true); return;
    //createIsoGrid(lumpy2D, 800); return;
    //createGrid(lumpy2D, 900, true); return;
    //createPolygon(); return;
    //createRing();  return;

    if (endsWith(f, ".ifs")) {
        loadIFS(filename);
    } else if (endsWith(f, ".md2")) {
        loadMD2(filename);
    } else if (endsWith(f, ".3ds")) {
        load3DS(filename);
    } else if (endsWith(f, ".obj")) {
        loadOBJ(filename);
    } else if (endsWith(f, ".sm")) {
        loadSM(filename);
    } else {
        debugAssert(false);
    }
}


void XIFSModel::createCylinder() {
    MeshBuilder builder(false);

    int N = 36;

    Vector3 top(0,.5,0);
    Vector3 bottom(0,-.5,0);

    for (int i = 0; i < N; ++i) {
        float a = i * G3D_TWO_PI / N;
        float b = (i + 1) * G3D_TWO_PI / N;

        Vector3 A = Vector3(cos(a), 0, sin(a)) * sqrt(2)/2;
        Vector3 B = Vector3(cos(b), 0, sin(b)) * sqrt(2)/2;

        builder.addTriangle(A + bottom, A + top, B + bottom);
        builder.addTriangle(B + bottom, A + top, B + top);

        builder.addTriangle(A + top, top, B + top);
        builder.addTriangle(A + bottom, B + bottom, bottom);
    }

    set(builder);
}


void XIFSModel::createHalfGear() {
    MeshBuilder builder(false);
    
    // Outer tooth radius
    double ro = 1;

    // Center tooth radius
    double rm = 0.7;

    // Inner hole radius
    double ri = 0.35;

    // Half height
    double sy = .125;

    int n = 4;
    for (int a = 0; a <= n; ++a) {
        double a1, a2, a3, a4, a5;

        if (a == 0) {
            // Half-tooth on end
            a1 = 0;
            a4 = 0;
        } else {
            a1 = -(a - 0.3) * G3D_PI / n;
            a4 = -(a - 0.20) * G3D_PI / n;
        }

        if (a == n) {
            // Half-tooth on end
            a2 = -G3D_PI;
            a5 = -G3D_PI;
        } else {
            a2 = -(a + 0.3) * G3D_PI / n;
            a5 = -(a + 0.20) * G3D_PI / n;
        }

        a3 = -(a + .7) * G3D_PI / n;

        Vector3 A = Vector3(cos(a4) * ro, sy, sin(a4) * ro);
        Vector3 B = Vector3(cos(a5) * ro, sy, sin(a5) * ro);
        Vector3 C = Vector3(cos(a1) * rm, sy, sin(a1) * rm);
        Vector3 D = Vector3(cos(a2) * rm, sy, sin(a2) * rm);
        Vector3 E = Vector3(cos(a1) * ri, sy, sin(a1) * ri);
        Vector3 F = Vector3(cos(a2) * ri, sy, sin(a2) * ri);
        Vector3 G = Vector3(cos(a3) * rm, sy, sin(a3) * rm);
        Vector3 H = Vector3(cos(a3) * ri, sy, sin(a3) * ri);

        builder.addTriangle(A, B, D);
        builder.addTriangle(A, D, C);

        builder.addTriangle(C, D, F);
        builder.addTriangle(C, F, E);

        if (a < n) {
            // Between teeth
            builder.addTriangle(F, D, H);
            builder.addTriangle(D, G, H);
        }

        // Bottom
        Vector3 Y(0, -sy*2, 0);
        Vector3 A2 = A + Y;
        Vector3 B2 = B + Y;
        Vector3 C2 = C + Y;
        Vector3 D2 = D + Y;
        Vector3 E2 = E + Y;
        Vector3 F2 = F + Y;
        Vector3 G2 = G + Y;
        Vector3 H2 = H + Y;

        builder.addTriangle(D2, B2, A2);
        builder.addTriangle(C2, D2, A2);

        builder.addTriangle(F2, D2, C2);
        builder.addTriangle(E2, F2, C2);

        if (a < n) {
            // Between teeth
            builder.addTriangle(H2, D2, F2);
            builder.addTriangle(H2, G2, D2);
        }

        // Sides
        builder.addTriangle(A, A2, B);
        builder.addTriangle(A2, B2, B);

        builder.addTriangle(B, B2, D);
        builder.addTriangle(B2, D2, D);

        if (a < n) {
            builder.addTriangle(D, D2, G);
            builder.addTriangle(D2, G2, G);

            builder.addTriangle(H, H2, F);
            builder.addTriangle(H2, F2, F);
        }

        builder.addTriangle(C, C2, A);
        builder.addTriangle(C2, A2, A);

        builder.addTriangle(F, F2, E);
        builder.addTriangle(F2, E2, E);

        if (a == 0) {
            builder.addTriangle(E, E2, C);
            builder.addTriangle(E2, C2, C);
        }

        if (a == n) {
            builder.addTriangle(D, F2, F);
            builder.addTriangle(D, D2, F2);
        }
    }

    set(builder);
}

static Vector3 isoToObjectSpace(int r, int c, int R, int C) {
    
    // We don't have the invisible, 1-vertex border so the
    // scale becaomes S = (1/(2(C-2)), 1, 1/(R-1)) and the edge
    // is one vertex closer to the body

    double edge = 0.0;
    
    if (isEven(r)) {
        if (c == 0) {
            edge = 1.0;
        } else if (c == C) {
            edge = -1.0;
        }
    }

    return 
        Vector3(2 * c + (r & 1) + edge - 2, 0, r) * 
        Vector3(0.5 / (C - 2.0), 1, 1.0 / (R - 1.0)) - Vector3(0.5, 0.0, 0.5);
}

void XIFSModel::createIsoGrid(double(*func)(double, double), int n) {
    MeshBuilder builder(_twoSided);

    double sin60 = sin(G3D_PI / 3.0);
    
    int C = iFloor(sqrt(n / 4.0));

    int R = iFloor(C / sin60);
    if (! isOdd(R)) {
        ++R;
    }


    Vector3 BOTTOM(0,-0.25,0);

    // Top & bottom
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {

            Vector3 D = isoToObjectSpace(r, c, R, C);
            D.y = func(D.x, D.z);

            Vector3 E = isoToObjectSpace(r, c + 1, R, C);
            E.y = func(E.x, E.z);

            Vector3 F = isoToObjectSpace(r + 1, c, R, C);
            F.y = func(F.x, F.z);

            Vector3 G = isoToObjectSpace(r + 1, c + 1, R, C);
            G.y = func(G.x, G.z);

            if (isOdd(r)) {
                //  D-----E
                //  |\    |
                //  |  \  |
                //  |    \|
                //  F-----G

                if (c < C - 1) {
                    builder.addTriangle(D, G, E);
                    builder.addTriangle(E + BOTTOM, G + BOTTOM, D + BOTTOM);
                }

                builder.addTriangle(D, F, G);
                builder.addTriangle(G + BOTTOM, F + BOTTOM, D + BOTTOM);
            } else {
                //  D-----E
                //  |    /|
                //  |  /  |
                //  |/    |
                //  F-----G
                builder.addTriangle(D, F, E);
                builder.addTriangle(E + BOTTOM, F + BOTTOM, D + BOTTOM);
                if (c < C - 1) {
                    builder.addTriangle(E, F, G);
                    builder.addTriangle(G + BOTTOM, F + BOTTOM, E + BOTTOM);
                }
            }
        }
    }

    // East and West edges
    for (int r = 0; r < R; ++r) {

        int c = 0;
        // West
        Vector3 D = isoToObjectSpace(r, c, R, C);
        D.y = func(D.x, D.z);

        Vector3 E = isoToObjectSpace(r + 1, c, R, C);
        E.y = func(E.x, E.z);

        builder.addTriangle(E, D, D + BOTTOM);
        builder.addTriangle(E + BOTTOM, E, D + BOTTOM);

        // East
        int s = r & 1;
        c = C;
        D = isoToObjectSpace(r, c - s, R, C);
        D.y = func(D.x, D.z);

        E = isoToObjectSpace(r + 1, c - 1 + s, R, C);
        E.y = func(E.x, E.z);

        builder.addTriangle(D + BOTTOM, D, E);
        builder.addTriangle(D + BOTTOM, E, E + BOTTOM);
    }

    // North and South edges
    for (int c = 0; c < C; ++c) {
        int r = 0;

        // North
        Vector3 D = isoToObjectSpace(r, c, R, C);
        D.y = func(D.x, D.z);

        Vector3 E = isoToObjectSpace(r, c + 1, R, C);
        E.y = func(E.x, E.z);

        builder.addTriangle(D + BOTTOM, D, E);
        builder.addTriangle(D + BOTTOM, E, E + BOTTOM);

        // South
        if (c < C - 1) {
            r = R;
            D = isoToObjectSpace(r, c, R, C);
            D.y = func(D.x, D.z);

            E = isoToObjectSpace(r, c + 1, R, C);
            E.y = func(E.x, E.z);
            builder.addTriangle(E, D, D + BOTTOM);
            builder.addTriangle(E + BOTTOM, E, D + BOTTOM);
        }
    }
    set(builder);
}


void XIFSModel::createGrid(double(*func)(double, double), int n, bool consistentDiagonal) {
    MeshBuilder builder(_twoSided);

    int X = iFloor(sqrt(n / 4.0));
    int Z = X;
    double x, y, z;

    Vector3 BOTTOM(0,-0.25,0);

    // Top & bottom
    for (int ix = 0; ix < X; ++ix) {
        for (int iz = 0; iz < Z; ++iz) {

            x = ix / (double)X - 0.5;
            z = iz / (double)Z - 0.5;
            y = func(x, z);

            Vector3 A(x, y, z);

            x = (ix + 1) / (double)X - 0.5;
            z = (iz) / (double)Z - 0.5;
            y = func(x, z);

            Vector3 B(x, y, z);

            x = (ix + 1) / (double)X - 0.5;
            z = (iz + 1) / (double)Z - 0.5;
            y = func(x, z);

            Vector3 C(x, y, z);

            x = (ix) / (double)X - 0.5;
            z = (iz + 1) / (double)Z - 0.5;
            y = func(x, z);

            Vector3 D(x, y, z);

            if (! consistentDiagonal && ((A - C).length() > (D - B).length())) {
                // Cut the longer diagonal
                Vector3 a = A, b = B, c = C, d = D;
                A = d; B = a; C = b; D = c;
            }

            builder.addTriangle(A, D, C);
            builder.addTriangle(A, C, B);

            A += BOTTOM;
            B += BOTTOM;
            C += BOTTOM;
            D += BOTTOM;

            builder.addTriangle(C, D, A);
            builder.addTriangle(B, C, A);
        }
    }

    // Stitch up edges
    for (int ix = 0; ix < X; ++ix) {
        int iz = 0;
        x = ix / (double)X - 0.5;
        z = iz / (double)Z - 0.5;
        y = func(x, z);

        Vector3 A(x, y, z);
        Vector3 B(x, y-0.25, z);

        x = (ix + 1) / (double)X - 0.5;
        y = func(x, z);

        Vector3 C(x, y-0.25, z);
        Vector3 D(x, y, z);

        builder.addTriangle(A, D, C);
        builder.addTriangle(A, C, B);

        iz = Z;
        x = ix / (double)X - 0.5;
        z = iz / (double)Z - 0.5;
        y = func(x, z);

        A = Vector3(x, y, z);
        B = Vector3(x, y-0.25, z);

        x = (ix + 1) / (double)X - 0.5;
        y = func(x, z);

        C = Vector3(x, y-0.25, z);
        D = Vector3(x, y, z);

        builder.addTriangle(C, D, A);
        builder.addTriangle(B, C, A);
    }

    // Stitch up edges
    for (int iz = 0; iz < Z; ++iz) {
        int ix = X;
        x = ix / (double)X - 0.5;
        z = iz / (double)Z - 0.5;
        y = func(x, z);

        Vector3 A(x, y, z);
        Vector3 B(x, y-0.25, z);

        z = (iz + 1) / (double)Z - 0.5;
        y = func(x, z);

        Vector3 C(x, y-0.25, z);
        Vector3 D(x, y, z);

        builder.addTriangle(A, D, C);
        builder.addTriangle(A, C, B);

        ix = 0;
        x = ix / (double)X - 0.5;
        z = iz / (double)Z - 0.5;
        y = func(x, z);

        A = Vector3(x, y, z);
        B = Vector3(x, y-0.25, z);

        z = (iz + 1) / (double)Z - 0.5;
        y = func(x, z);

        C = Vector3(x, y-0.25, z);
        D = Vector3(x, y, z);

        builder.addTriangle(C, D, A);
        builder.addTriangle(B, C, A);
    }


    set(builder);
}


void XIFSModel::createPolygon() {
    MeshBuilder builder(_twoSided);

    int sides = 8;

    double shift = isEven(sides) ? (G3D_PI / sides) : 0;
    for (int i = 1; i < sides - 1; ++i) {
        double angle0 = 2 * G3D_PI * i / sides + shift;
        double angle1 = 2 * G3D_PI * (i + 1) / sides + shift;

        Vector3 a(sin(shift), 0, -cos(shift));
        Vector3 b(sin(angle1), 0, -cos(angle1));
        Vector3 c(sin(angle0), 0, -cos(angle0));

        builder.addTriangle(a, b, c);
    }

    set(builder);

}


/** Called from createRing */
static void addSubdividedQuad(
    MeshBuilder& builder,
    const Vector3&   A,
    const Vector3&   B,
    const Vector3&   C,
    const Vector3&   D,
    int              numSubdivisions) {

    if (numSubdivisions == 0) {
        // Base case
        builder.addTriangle(A, B, C);
        builder.addTriangle(A, C, D);
    } else {
        
        //   D----C
        //   |__--|
        //   F----E
        //   |__--|
        //   A----B

        Vector3 F = (A + D) / 2;
        Vector3 E = (C + B) / 2;
        // Cut in half along the long axis
        addSubdividedQuad(builder, A, B, E, F, numSubdivisions - 1);
        addSubdividedQuad(builder, F, E, C, D, numSubdivisions - 1);
    }
}


void XIFSModel::createRing() {
    MeshBuilder builder(_twoSided);

    int quads = 150;

    // Creates 2^n triangles
    int subdivisions = 3;

    // Radius is fixed at 1.0
    // Half width
    double w = .25;

    // 3x half twist torus
    double numTwists = 1.5;

    for (int i = 0; i < quads; ++i) {
        double angle0 = 2 * G3D_PI * i / quads;
        double angle1 = 2 * G3D_PI * (i + 1) / quads;

        double twist0 = numTwists * 2 * G3D_PI * i / quads;
        double twist1 = numTwists * 2 * G3D_PI * (i + 1) / quads;
        
        // Midline of ring
        Vector3 a, b;

        // Normals
        Vector3 c, d;

        // Outer (twisted) vertices
        Vector3 e, f, g, h;

        a = Vector3(cos(angle0), 0, sin(angle0));
        b = Vector3(cos(angle1), 0, sin(angle1));

        c = a;
        d = b;

        // center of ring
        //
        //   -f--h- 
        //    | /|
        //    |/ |
        //  --e--g--
        //
        //   outside

        e = a + w * (cos(twist0) * Vector3::UNIT_Y + sin(twist0) * c);
        f = a - w * (cos(twist0) * Vector3::UNIT_Y + sin(twist0) * c);
        g = b + w * (cos(twist1) * Vector3::UNIT_Y + sin(twist1) * c);
        h = b - w * (cos(twist1) * Vector3::UNIT_Y + sin(twist1) * c);

        // Want to add quad eghf, but we need to subdivide it along edges
        // ef and hg.

        addSubdividedQuad(builder, e, g, h, f, subdivisions);
    }

    set(builder);
}


void XIFSModel::loadIFS(const std::string& filename) {
    MeshBuilder builder(_twoSided);
    
    BinaryInput b(filename, G3D_LITTLE_ENDIAN);

    std::string fmt         = b.readString32();
    float       version     = b.readFloat32();
    
    builder.setName(b.readString32());
    debugAssert(fmt     == "IFS");
    debugAssert(version == 1.0);

    std::string vertexHeader = b.readString32();

    Array<Vector3> va (b.readUInt32());

    for (int v = 0; v < va.size(); ++v) {
        va[v] = b.readVector3();
    }

    b.readString32();
    int n = b.readUInt32();

    int t;
    for (t = 0; t < n; ++t) {
        int v0 = b.readUInt32();
        int v1 = b.readUInt32();
        int v2 = b.readUInt32();

        builder.addTriangle(va[v0], va[v1], va[v2]);
    }

    set(builder);
}



void XIFSModel::loadSM(const std::string& filename) {
    MeshBuilder builder(_twoSided);

    TextInput ti(filename);

    // Read vertices
    Array<Vector3> va((int)ti.readNumber());
    for (int v = 0; v < va.size(); ++v) {
        for (int i = 0; i < 3; ++i) {
            va[v][i] = ti.readNumber();
        }
    }

    // Read faces
    int n = (int)ti.readNumber();

    int t;
    for (t = 0; t < n; ++t) {
        int v0 = (int)ti.readNumber();
        int v1 = (int)ti.readNumber();
        int v2 = (int)ti.readNumber();

        builder.addTriangle(va[v0], va[v1], va[v2]);
    }

    set(builder);
}


void XIFSModel::loadMD2(const std::string& filename) {
    MeshBuilder builder(_twoSided);
    
    BinaryInput b(filename, G3D_LITTLE_ENDIAN);

    MD2ModelHeader header;

    // This code only works on little endian machines
    
    b.readBytes(sizeof(header), (unsigned char*)&header);
    debugAssert(header.version == 8);
    debugAssert(header.numVertices <= 4096);

    // One frame of animation
    MD2Frame    md2Frame;

    // Read a single frame
    const int frameNum = 0;
    b.setPosition(header.offsetFrames + frameNum * header.frameSize);
    b.readBytes(sizeof(MD2Frame), (unsigned char*)&md2Frame);

    // Read the vertices for the frame
    Vector3     va[2048];

    // Quake's axes are permuted and scaled
    double scale[3]   = {.07, .07, -.07};
    int    permute[3] = {2, 0, 1};
    int v, i;
    for (v = 0; v < header.numVertices; ++v) {
        for (i = 0; i < 3; ++i) {
            va[v][permute[i]] = (b.readUInt8() * md2Frame.scale[i] + md2Frame.translate[i]) * scale[permute[i]];
        }
        b.skip(1);
    }

    // Read the triangles
    int t;
    b.setPosition(header.offsetTriangles);
    for (t = 0; t < header.numTriangles; ++t) {
        int v0 = b.readUInt16();
        int v1 = b.readUInt16();
        int v2 = b.readUInt16();
 
        builder.addTriangle(va[v0], va[v1], va[v2]);
        // Skip the texture indices
        b.skip(6);
    }


    set(builder);
}



void XIFSModel::load3DS(const std::string& filename) {
    MeshBuilder builder(_twoSided);

    BinaryInput b(filename, G3D_LITTLE_ENDIAN);

    Load3DS loader(b);

    for (int obj = 0; obj < loader.objectArray.size(); ++obj) {
        const Matrix4& keyframe = loader.objectArray[obj].keyframe;
        
        Vector3 pivot = loader.objectArray[obj].pivot;

        const Array<int>&     index   = loader.objectArray[obj].indexArray;
        const Array<Vector3>& vertex  = loader.objectArray[obj].vertexArray;

        // The cframe has already been applied in the 3DS file.  If
        // we change the Load3DS object representation to move
        // coordinates back to object space, this is the code
        // that will promote them to world space before constructing
        // the mesh.

        const Matrix4&        cframe  = loader.objectArray[obj].cframe;
        (void)cframe;
        //#define vert(V) (keyframe * cframe * Vector4(vertex[index[V]], 1)).xyz()

        // TODO: Figure out correct transformation
        #define vert(V) \
          ((keyframe * \
           ( Vector4(vertex[index[V]], 1) - Vector4(pivot, 0)) \
           )).xyz() 

        for (int i = 0; i < index.size(); i += 3) {
            builder.addTriangle(
                vert(i),
                vert(i + 1),
                vert(i + 2));
        }

        #undef vert
    }
      
    builder.setName(loader.objectArray[0].name);

    set(builder);
}



void XIFSModel::loadOBJ(const std::string& filename) {
    MeshBuilder builder(_twoSided);
    
    TextInput::Options options;
    options.cppComments = false;
    TextInput t(filename, options);

    Array<Vector3> va;

    try {
        while (t.hasMore()) {
            Token tag = t.read();

            if (tag.type() == Token::SYMBOL) {
                if (tag.string() == "v") {
                    // Vertex
                    Vector3 vertex;
                    vertex.x = t.readNumber();
                    vertex.y = t.readNumber();
                    vertex.z = t.readNumber();

                    va.append(vertex);

                } else if (tag.string() == "f") {
                    // Face (may have an arbitrary number of vertices)
                    Array<int> vertexIndex;
            
                    while ((t.peek().line() == tag.line()) && t.hasMore()) {  
                        vertexIndex.append((int)t.readNumber());
                        debugAssert(vertexIndex.last() > 0);
                        --vertexIndex.last();

                        // Fix illegal vertex numbers
                        if ((vertexIndex.last() <= 0) || vertexIndex.last() >= va.size()) {
                            vertexIndex[vertexIndex.size() - 1] = 0;
                        }

                        // Skip over the slashes
                        Token next = t.peek();
                        while ((next.type() == Token::SYMBOL) && (next.string() == "/")) {
                            next = t.read();
                        }

                        if (vertexIndex.size() >= 3) {
                            int i = vertexIndex.size() - 1;
                            builder.addTriangle(va[vertexIndex[0]],
                                                va[vertexIndex[i - 1]],
                                                va[vertexIndex[i]]);
                        }
                    }

                }
            }

            // Read to the next line
            while ((t.peek().line() == tag.line()) && t.hasMore()) {
                t.read();
            }
        }
    } catch (TextInput::WrongTokenType& e) {
        debugAssert(e.expected != e.actual);
        (void)e;
    }
    
    builder.setName(filename);

    set(builder);
}


static void drawBillboardString(
    CFontRef            font,
    const std::string&  s,
    const Vector3&      pos,
    double              screenSize,
    const Color4&       color,
    const Color4&       outline = Color4::CLEAR) {

    // Find the point

    Vector3 screenPos = camera.project(pos, renderDevice->getViewport());

    renderDevice->push2D();
        font->draw2D(s, screenPos.xy(), screenSize, color, outline, GFont::XALIGN_CENTER, GFont::YALIGN_CENTER);
    renderDevice->pop2D();
}


void XIFSModel::render() {
    renderDevice->pushState();

        int t, i, j;

        glEnable(GL_LINE_SMOOTH);
        renderDevice->setColor(Color3::WHITE);
        renderDevice->setLineWidth(.5);

        renderDevice->setPolygonOffset(.5);
        renderDevice->setDepthTest(RenderDevice::DEPTH_LEQUAL);
        // First iteration draws surfaces, 2nd draws wireframe
        for (j = 0; j < 2; ++j) {
            renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
                for (t = 0; t < triangleArray.size(); ++t) {
                    renderDevice->setNormal(faceNormalArray[t]);
                    for (i = 0; i < 3; ++i) {
                        const int idx = triangleArray[t].index[i];
                        renderDevice->sendVertex(geometry.vertexArray[idx]);
                    }
                }
            renderDevice->endPrimitive();
            renderDevice->setPolygonOffset(0);
            renderDevice->setRenderMode(RenderDevice::RENDER_WIREFRAME);
            renderDevice->setColor(Color3::BLACK);
            renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
        }
        renderDevice->setRenderMode(RenderDevice::RENDER_SOLID);

        /*
        // Label vertices (when there are too many, don't draw all)
        const double S = 10;
        int step = iMax(1, geometry.vertexArray.size() / 50);
        for (int v = 0; v < geometry.vertexArray.size(); v += step) {
            drawBillboardString(font, format("%d", v), geometry.vertexArray[v], S, Color3::YELLOW, Color3::BLACK);
        }*/

        //Draw::vertexNormals(geometry, renderDevice);

        // Label edges
        //for (int e = 0; e < edgeArray.size(); ++e) {
        //    const Vector3 pos = (geometry.vertexArray[edgeArray[e].vertexIndex[0]] + geometry.vertexArray[edgeArray[e].vertexIndex[1]]) / 2; 
        //    drawBillboardString(font, format("%d", e), pos, D * 20, Color3::BLUE, Color3::BLACK);
        //}


        // Show broken edges
        renderDevice->disableLighting();
        renderDevice->setColor(Color3::RED);
        renderDevice->setLineWidth(3);
        renderDevice->beginPrimitive(RenderDevice::LINES);
            for (int b = 0; b < brokenEdgeArray.size(); ++b) {
                for (int j = 0; j < 2; ++j) {
                    renderDevice->sendVertex(geometry.vertexArray[brokenEdgeArray[b].vertexIndex[j]]);
                }
            }
        renderDevice->endPrimitive();

        //Draw::axes(renderDevice);
        glDisable(GL_LINE_SMOOTH);

    renderDevice->popState();
}


void XIFSModel::save(const std::string& filename) {

    Array<int> index;
    for (int i = 0; i < triangleArray.size(); ++i) {
        index.append(triangleArray[i].index[0], triangleArray[i].index[1], triangleArray[i].index[2]);
    }

    IFSModel::save(filename, name, index, geometry.vertexArray, texCoordArray);
}

