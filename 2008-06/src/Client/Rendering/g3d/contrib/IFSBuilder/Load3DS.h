
#include <G3DAll.h>


// TODO: Create two polygons when MATTWOSIDE is detected
// TODO: read material colors

/**
 @cite Keyframe chunks from http://www.republika.pl/design3d/delphi/004.html
 MLI chunks from  http://www.programmersheaven.com/zone10/cat454/941.htm
 */
class Load3DS {
public:

    enum ChunkHeaderID {
        MAIN3DS       = 0x4d4d,
        M3D_VERSION   = 0x0002,

        EDIT3DS       = 0x3D3D,
            // Subchunks of EDIT3DS
            MESH_VERSION  = 0x3D3E,
            EDITMATERIAL  = 0xAFFF,
                // Subchunks of EDITMATERIAL
                MATNAME       = 0xA000,
                MATAMBIENT    = 0xA010,
                MATDIFFUSE    = 0xA020,
                MATSPECULAR   = 0xA030,
                MATSHININESS  = 0xA040,

                MATSHIN2PCT     = 0xA041,
 	            MATSHIN3PC      = 0xA042, 
                MATTRANSPARENCY = 0xA050, 
 	            MATXPFALL       = 0xA052,
	            MATREFBLUR      = 0xA053, 
 	            MATSELFILLUM    = 0xA080,
 	            MATTWOSIDE      = 0xA081,
 	            MATDECAL        = 0xA082,
 	            MATADDITIVE     = 0xA083,
 	            MATSELFILPCT    = 0xA084,
 	            MATWIRE         = 0xA085,
 	            MATSUPERSMP     = 0xA086,
 	            MATWIRESIZE     = 0xA087,
 	            MATFACEMAP      = 0xA088,
 	            MATXPFALLIN     = 0xA08A,
 	            MATPHONG        = 0xA08C,
 	            MATWIREABS      = 0xA08E,
 	            MATSHADING      = 0xA100,

                MATMAP        = 0xA200,
                MATMAPFILE    = 0xA300,

            EDIT_CONFIG1 = 0x0100,
            EDIT_CONFIG2 = 0x3E3D,
            EDIT_VIEW_P1 = 0x7012,
            EDIT_VIEW_P2 = 0x7011,
            EDIT_VIEW_P3 = 0x7020,
            EDIT_VIEW1   = 0x7001, 
            EDIT_BACKGR  = 0x1200, 
            EDIT_AMBIENT = 0x2100,

            EDITOBJECT    = 0x4000,

            OBJTRIMESH    = 0x4100,
                // Subchunks of OBJTRIMESH
                TRIVERT       = 0x4110,
                TRIFACE       = 0x4120,
                TRIFACEMAT    = 0x4130,
                TRIUV         = 0x4140,
                TRISMOOTH     = 0x4150,
                TRIMATRIX     = 0x4160,

        EDITKEYFRAME  = 0xB000,
            // Subchunks of EDITKEYFRAME
            KFAMBIENT     = 0xB001,
            KFMESHINFO    = 0xB002,
                KFNAME        = 0xB010,
                KFPIVOT       = 0xB013,
                KFMORPHANGLE  = 0xB015,
                KFTRANSLATION = 0xB020,
                KFROTATION    = 0xB021,
                KFSCALE       = 0xB022,
            KFCAMERA      = 0xB003,
            KFCAMERATARGET= 0xB004,
            KFOMNILIGHT   = 0xB005,
            KFSPOTTARGET  = 0xB006,
            KFSPOTLIGHT   = 0xB007,
            KFFRAMES      = 0xB008,
            KFFOV         = 0xB023,
            KFROLL        = 0xB024,
            KFCOLOR       = 0xB025,
            KFMORPH       = 0xB026,
            KFHOTSPOT     = 0xB027,
            KFFALLOFF     = 0xB028,
            KFHIDE        = 0xB029,
            KFHIERARCHY   = 0xB030,

		// float32 color
		RGBF   = 0x0010,

		// uint8 color
        RGB24  = 0x0011
    };

    struct ChunkHeader {
        ChunkHeaderID     id;

        /** In bytes, includes the size of the header itself. */
        int         length;

        /** Absolute start postion */
        int         begin;

        /** Absolute last postion + 1 */
        int         end;

    };


	class Material {
	public:
		std::string					name;
		bool						twoSided;
		Color3						diffuse;
		Color3						specular;

		// "Self illumination"
		double						emissive;

		double						shininess;
		double						shininessStrength;
		double						transparency;
		double						transparencyFalloff;
		double						reflectionBlur;

		/** 1 = flat, 2 = gouraud, 3 = phong, 4 = metal */
		int							materialType;

		Material() : twoSided(false) {
		}
	};


    class Object {
    public:
        /** Loaded from the TRIVERTEX chunk (transformed to G3D coordinates).
            In World Space.*/
        Array<Vector3>              vertexArray;

        /** Triangle list indices (loaded from the TRIFACE chunk) */
        Array<int>                  indexArray;

        /** Part of the EDITOBJECT chunk */
        std::string                 name;

        /** From KFNAME.
            // The object hierarchy is a bit complex but works like this. 
            // Each Object in the scene is given a number to identify its
            // order in the tree. Also each object is orddered in the 3ds
            // file as it would appear in the tree. The root object is 
            // given the number -1 ( FFFF ). As the file is read a counter
            // of the object number is kept. Is the counter increments the
            // objects are children of the previous objects. But when the 
            // pattern is broken by a number what will be less than the 
            // current counter the hierarchy returns to that level.
        */
        int                         hierarchyIndex;

        /** TRI_LOCAL chunk (transformed to G3D coordinates).  
            In the file, this has already been applied to the
            vertices.
          */
        Matrix4                     cframe;

        /** In object space or world space? */
        Vector3                     pivot;

        /** From object space or world space? */
        Matrix4                     keyframe;

        Object() : pivot(Vector3::ZERO) {
        }
    };

    /** Inside an object chunk, this is the object we're editing.
        Index into objectArray. */
    int                 currentObject;

	int					currentMaterial;

    Array<Object>       objectArray;
	Array<Material>		materialArray;

    /** Animation start and end frames from KFFRAMES chunk */
    uint32              startFrame;
    uint32              endFrame;

    /** Used in Keyframe chunk */
    Matrix3             currentRotation;
    Vector3             currentScale;
    Vector3             currentTranslation;

    BinaryInput& b;

    /**
     Reads the next chunk from the file and returns it.
     */
    ChunkHeader readChunkHeader();

    /**
     Reads a vector in the 3DS coordinate system and converts it to
     the G3D coordinate system.
     */
    Vector3 read3DSVector();

    /**
     Read either of the 3DS color chunk types and return the result.
     */
    Color3 read3DSColor();

    /**
     Reads (and ignores) TCB information from a track part of 
     a keyframe chunk.
     */
    void readTCB();

    /**
     The translation and scale information in a keyframe is packed
     with additional interpolation information.  This reads all of
     it, then throws away everything except the 3D vector.
     */
    Vector3 readLin3Track();
    Matrix3 readRotTrack();

    /**
     Reads the next chunk from a file and processes it.
     */
    void processChunk(const ChunkHeader& prevChunkHeader);

    /** Version number of the file */
    int fileVersion;
    int meshVersion;


	/**
	 @param t Should polygons be two sided?
	 */
    Load3DS(BinaryInput& _b) : currentRotation(Matrix3::IDENTITY), b(_b) {

        fileVersion     = 0;
        meshVersion     = 0;
        currentObject   = -1;
        currentMaterial = -1;

        ChunkHeader chunk = readChunkHeader();

        alwaysAssertM(chunk.id == MAIN3DS, "Not a 3DS file!");
        processChunk(chunk);
    }

};


Vector3 Load3DS::read3DSVector() {
    Vector3 v;

    v.x = -b.readFloat32();
    v.z = b.readFloat32();
    v.y = b.readFloat32();

    return v;
}


Load3DS::ChunkHeader Load3DS::readChunkHeader() {
    ChunkHeader c;
    c.begin  = b.getPosition();
    c.id     = (ChunkHeaderID)b.readUInt16();
    c.length = b.readInt32();
    c.end    = c.length + c.begin;
    return c;
}


void Load3DS::processChunk(const Load3DS::ChunkHeader& parentChunkHeader) {

    // Parse all sub-chunks
    while (b.getPosition() < parentChunkHeader.end) {
        ChunkHeader curChunkHeader = readChunkHeader();

        switch (curChunkHeader.id) {
        case M3D_VERSION:
            fileVersion = b.readUInt16();
            debugAssertM(fileVersion == 3, "Unsupported 3DS file version");
            break;


        case EDIT3DS:
            processChunk(curChunkHeader);
            break;

            case MESH_VERSION:
                meshVersion = b.readUInt16();
                debugAssertM(meshVersion == 3, "Unsupported 3DS mesh version");
                break;


            case EDIT_CONFIG1:
            case EDIT_CONFIG2:
            case EDIT_VIEW_P1:
            case EDIT_VIEW_P2:
            case EDIT_VIEW_P3:
            case EDIT_VIEW1: 
            case EDIT_BACKGR: 
            case EDIT_AMBIENT:
                // These are the configuration of 3DS Max itself;
                // window positions, etc.  Ignore them when loading
                // a model.
                break;

            case EDITMATERIAL:

                // Create a new object
                currentMaterial = materialArray.size();
                materialArray.next();
                processChunk(curChunkHeader);
                break;

                // EDITMATERIAL subchunks
                case MATNAME:					
					materialArray[currentMaterial].name = b.readString();
                    break;

                case MATAMBIENT:
                    break;

                case MATDIFFUSE:
					materialArray[currentMaterial].diffuse = read3DSColor();
                    break;

                case MATSPECULAR:
					materialArray[currentMaterial].specular = read3DSColor();
                    break;

                case MATSHININESS:
                    break;

                case MATMAP:
                    break;

                case MATMAPFILE:
                    break;

				case MATTWOSIDE:
					materialArray[currentMaterial].twoSided = true;
					break;

            case EDITOBJECT:
                // Create a new object
                currentObject = objectArray.size();
                objectArray.next();
                // Read the object name
                objectArray[currentObject].name = b.readString();
                processChunk(curChunkHeader);
                break;

                // EDITOBJECT subchunks
                case OBJTRIMESH:
                    processChunk(curChunkHeader);
                    break;

                    // Subchunks of OBJTRIMESH
                    case TRIVERT:
                        {
                            int n = b.readUInt16();

                            // Read the vertices
                            objectArray[currentObject].vertexArray.resize(n);
                            for (int v = 0; v < n; ++v) {
                                objectArray[currentObject].vertexArray[v] = read3DSVector();
                            }
                            debugAssert(b.getPosition() == curChunkHeader.end);
                        }
                        break;

                    case TRIFACE:
                        {
                            int n = b.readUInt16();
                            objectArray[currentObject].indexArray.resize(n * 3);
                            for (int i = 0; i < n; ++i) {
                                // Indices are in clockwise winding order
                                int v0 = b.readUInt16();
                                int v1 = b.readUInt16();
                                int v2 = b.readUInt16();

                                uint16 flags = b.readUInt16();
                                (void)flags;

                                /*
                                Here's the only documentation I've found on the flags:

                                this number is is a binary number which expands to 3 values.
                                 for example 0x0006 would expand to 110 binary. The value should be
                                 read as 1 1 0 .This value can be found in 3d-studio ascii files as
                                 AB:1 BC:1 AC:0 .Which probably indicated the order of the vertices.
                                 For example AB:1 would be a normal line from A to B. But AB:0 would
                                 mean a line from B to A.

                                 bit 0       AC visibility
                                 bit 1       BC visibility
                                 bit 2       AB visibility
                                 bit 3       Mapping (if there is mapping for this face)
                                 bit 4-8   0 (not used ?)
                                 bit 9-10  x (chaotic ???)
                                 bit 11-12 0 (not used ?)
                                 bit 13      face selected in selection 3
                                 bit 14      face selected in selection 2
                                 bit 15      face selected in selection 1
                               */

                                bool ccw = true;
                                if (ccw) {
                                    objectArray[currentObject].indexArray[i * 3 + 0] = v0;
                                    objectArray[currentObject].indexArray[i * 3 + 1] = v1;
                                    objectArray[currentObject].indexArray[i * 3 + 2] = v2;
                                } else {
                                    objectArray[currentObject].indexArray[i * 3 + 0] = v2;
                                    objectArray[currentObject].indexArray[i * 3 + 1] = v1;
                                    objectArray[currentObject].indexArray[i * 3 + 2] = v0;
                                }
                            }
                        }
                        processChunk(curChunkHeader);
                        break;

                    case TRIFACEMAT:
						// TODO: is this the material index?
                        break;

                    case TRIUV:
                        break;

                    case TRISMOOTH:
                        break;

                    case TRIMATRIX: 
                        {
                            // Coordinate frame.  Convert to G3D coordinates
                            // by swapping y and z and then negating the x.
                            float c[12];
                            for (int i = 0; i < 12; ++i) {
                                c[i] = b.readFloat32();
                            }

                            // Note that this transformation has *already*
                            // been applied to the vertices.
                       
                            objectArray[currentObject].cframe =
                                Matrix4( c[0],  c[3],  c[6], -c[9],
                                         c[1],  c[4],  c[7],  c[11],
                                         c[2],  c[5],  c[8],  c[10],
                                         0,      0,      0,     1);
                                         
                            
                            //debugPrintf("%s\n", objectArray[currentObject].name.c_str());
                            //for (int r = 0; r < 4; ++r) {
                            //    for (int c = 0; c < 4; ++c) {
                            //        debugPrintf("%3.3f ", objectArray[currentObject].cframe[r][c]);
                            //    }
                            //    debugPrintf("\n");
                            //}
                            //debugPrintf("\n");
                        }
                        break;

        case EDITKEYFRAME:
            processChunk(curChunkHeader);
            break;

            // Subchunks of EDITKEYFRAME            
            case KFSPOTLIGHT:
                break;

            case KFFRAMES:
                startFrame = b.readUInt32();
                endFrame   = b.readUInt32();
                debugPrintf("\nStart frame = %d, end frame = %d\n\n", startFrame, endFrame);
                processChunk(curChunkHeader);
                break;

            case KFMESHINFO:
                currentRotation = Matrix3::IDENTITY;
                currentScale = Vector3(1,1,1);
                currentTranslation = Vector3::ZERO;

                processChunk(curChunkHeader);

                // Copy the keyframe information
                if (currentObject != -1) {
                    CoordinateFrame cframe(currentRotation, currentTranslation);
                    objectArray[currentObject].keyframe = Matrix4(cframe);
                    for (int r = 0; r < 3; ++r) {
                        for (int c = 0; c < 3; ++c) {
                            objectArray[currentObject].keyframe[r][c] *= currentScale[c];
                        }
                    }
                }
                break;

                // Subchunks of KFMESHINFO
                case KFNAME:
                    {
                        std::string name = b.readString();                    
                        b.readUInt16(); 
                        b.readUInt16();
                        int hierarchyIndex = b.readUInt16();
                        debugPrintf("\n\"%s\", %d\n\n", name.c_str(), hierarchyIndex);

                        // Find the current object
                        currentObject = -1;

                        if (name != "$$$DUMMY") {
                            for (int i = 0; i < objectArray.size(); ++i) {
                                if (name == objectArray[i].name) {
                                    currentObject = i;
                                    break;
                                }
                            }
                        }

                        if (currentObject != -1) {
                            objectArray[currentObject].hierarchyIndex = hierarchyIndex;
                        }
                    }
                    break;

                case KFPIVOT:
                    {
                        Vector3 pivot = read3DSVector();
                        debugPrintf("pivot = %s\n", pivot.toString().c_str());
                    }
                    break;

                case KFTRANSLATION:
                    currentTranslation = readLin3Track();
                    debugPrintf("translation = %s\n", currentTranslation.toString().c_str());
                    break;

                case KFSCALE:
                    currentScale = readLin3Track();
                    debugPrintf("scale = %s\n", currentScale.toString().c_str());
                    break;

                case KFROTATION:
                    currentRotation = readRotTrack();
                    break;

                case KFHIERARCHY:
                    break;
        default:
            debugPrintf("Skipped unknown chunk 0x%x\n", curChunkHeader.id);
        }

        if (b.getPosition() != curChunkHeader.end) {
            debugPrintf("Skipping %d bytes of chunk 0x%x\n", 
                curChunkHeader.end - b.getPosition(),
                curChunkHeader.id);
        }

        // Jump to the end of the chunk
        b.setPosition(curChunkHeader.end);
    }
}
            

void Load3DS::readTCB() {
    enum {
        USE_TENSION    = 0x0001,
        USE_CONTINUITY = 0x0002,
        USE_BIAS       = 0x0004,
        USE_EASE_TO    = 0x0008,
        USE_EASE_FROM  = 0x0010
    };
    
    int tcbframe = b.readInt32();
    (void)tcbframe;
    int tcbflags = b.readUInt16();

    if (tcbflags & USE_TENSION) {
        float tcbtens = b.readFloat32();
        (void)tcbtens;
    }

    if (tcbflags & USE_CONTINUITY) {
        float tcbcont = b.readFloat32();
        (void)tcbcont;
    }

    if (tcbflags & USE_BIAS) {
        float tcbbias = b.readFloat32();
        (void)tcbbias;
    }

    if (tcbflags & USE_EASE_TO) {
        float tcbeaseto = b.readFloat32();
        (void)tcbeaseto;
    }

    if (tcbflags & USE_EASE_FROM) {
        float tcbeasefrom = b.readFloat32();
        (void)tcbeasefrom;
    }                                           
}


Vector3 Load3DS::readLin3Track() {
    int trackflags = b.readUInt16();
    (void)trackflags;
    b.readUInt32();
    b.readUInt32();

    // Number of key frames
    int keys = b.readInt32();
    debugAssertM(keys == 1, "Can only read 1 frame of animation");

    Vector3 vector;

    for (int k = 0; k < keys; ++k) {
        // Read but ignore the individual interpolation
        // parameters.
        readTCB();
        vector = read3DSVector();
    }

    return vector;
}


Matrix3 Load3DS::readRotTrack() {
    int trackflags = b.readUInt16();
    (void)trackflags;
	b.readUInt32();
	b.readUInt32();

	int keys = b.readInt32();
	debugAssertM(keys == 1, "Can only read 1 frame of animation");
	float   angle;
	Vector3 axis;
	for (int k = 0; k < keys; ++k) {
		readTCB();
		angle = b.readFloat32();
		axis  = read3DSVector();
	}

	debugPrintf("Axis = %s, angle = %g\n\n", axis.toString().c_str(), angle);
	return Matrix3::fromAxisAngle(axis, angle);
}


Color3 Load3DS::read3DSColor() {
    ChunkHeader curChunkHeader = readChunkHeader();
	Color3 color;

	switch (curChunkHeader.id) {
	case RGBF:
		color.r = b.readFloat32();
		color.g = b.readFloat32();
		color.b = b.readFloat32();
		break;

	case RGB24:
		color.r = b.readUInt8() / 255.0;
		color.g = b.readUInt8() / 255.0;
		color.b = b.readUInt8() / 255.0;
		break;

	default:
		debugAssertM(false, format("Expected a color chunk, found: %d", curChunkHeader.id));
	}

    // Jump to the end of the chunk
    b.setPosition(curChunkHeader.end);
	return color;
}
