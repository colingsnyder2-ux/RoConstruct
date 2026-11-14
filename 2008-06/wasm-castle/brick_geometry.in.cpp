    // Fixture geometry only; finish() still uses the recovered GeometryBuilder,
    // RbxSubMesh, RbxSubEntity, RbxEntity and RbxSceneNode path.
    void shadowTriangle(Ogre::Vector3 a,Ogre::Vector3 b,Ogre::Vector3 c) {
        unsigned base=shadowVertices.size()/3;
        Ogre::Vector3 n=(b-a).crossProduct(c-a).normalisedCopy(),p[3]={a,b,c};
        for(int i=0;i<3;++i) {
            shadowVertices.push_back(p[i].x);shadowVertices.push_back(p[i].y);shadowVertices.push_back(p[i].z);
            shadowNormals.push_back(n.x);shadowNormals.push_back(n.y);shadowNormals.push_back(n.z);
            shadowIndices.push_back(base+i);
        }
    }
    void triangle(Ogre::Vector3 a,Ogre::Vector3 b,Ogre::Vector3 c,Ogre::Vector3 outward) {
        if((b-a).crossProduct(c-a).dotProduct(outward)<0) std::swap(b,c);
        shadowTriangle(a,b,c);
        Ogre::Vector3 n=(b-a).crossProduct(c-a).normalisedCopy();
        Ogre::Vector3 p[3]={a,b,c};
        for(int i=0;i<3;++i) {
            vertices.push_back(p[i].x);vertices.push_back(p[i].y);vertices.push_back(p[i].z);
            normals.push_back(n.x);normals.push_back(n.y);normals.push_back(n.z);
            texCoords.push_back(0.125f);texCoords.push_back(0.25f);
            indices.push_back(index++);
        }
    }
    void face(Ogre::Vector3 a,Ogre::Vector3 b,Ogre::Vector3 c,Ogre::Vector3 d,Ogre::Vector3 outward) {
        if((b-a).crossProduct(c-a).dotProduct(outward)<0) std::swap(b,d);
        quad(a,b,c,d);
    }
    void brick(float x,float y,float z,float w,float h,float depth,bool studs=true) {
        float grid[6]={x,y,z,w,h,depth};
        for(int i=0;i<6;++i) if(fabs(grid[i]*2-std::floor(grid[i]*2+0.5f))>0.0001f)
            throw std::runtime_error("Castle block off half-stud grid");
        // Ogre 1.4 shadow extrusion duplicates vertices into 16-bit indices.
        // Flush between complete closed bricks, never through a solid's faces.
        unsigned count=96;
        if(index&&index+count>30000) finish(owner);
        unsigned firstVertex=index;
        ++castleBevelCount;
        castleBlocks.push_back({{x,y,z},{w,h,depth},material->getName(),studs});
        Ogre::Vector3 center(x,y,z),half(w/2,h/2,depth/2);
        float bevel=std::min(0.07f,std::min(w,std::min(h,depth))*0.16f);
        for(int axis=0;axis<3;++axis) {
            int j=(axis+1)%3,k=(axis+2)%3;
            for(int s=-1;s<=1;s+=2) {
                Ogre::Vector3 p[4],n=Ogre::Vector3::ZERO;n[axis]=s;
                for(int q=0;q<4;++q) {
                    p[q]=center;p[q][axis]+=s*half[axis];
                    p[q][j]+=(q==0||q==3?-1:1)*(half[j]-bevel);
                    p[q][k]+=(q<2?-1:1)*(half[k]-bevel);
                }
                if(axis==1&&s==1&&studs) {
                    quad(p[0],p[1],p[2],p[3]);
                    // Keep the closed, unsplit top in the native shadow mesh.
                    // Visible atlas strips reset V every four studs, as in
                    // LevelBuilder::buildFace. A plate remains one solid.
                    vertices.resize(vertices.size()-12);normals.resize(normals.size()-12);
                    texCoords.resize(texCoords.size()-8);indices.resize(indices.size()-6);index-=4;
                    suppressShadow=true;
                    for(float start=0;start<depth;start+=4) {
                        float end=std::min(start+4,depth);
                        float z0=std::max(z-depth/2+start,z-depth/2+bevel);
                        float z1=std::min(z-depth/2+end,z+depth/2-bevel);
                        Ogre::Vector3 v[4]={{x-w/2+bevel,y+h/2,z0},{x-w/2+bevel,y+h/2,z1},
                                           {x+w/2-bevel,y+h/2,z1},{x+w/2-bevel,y+h/2,z0}};
                        quad(v[0],v[1],v[2],v[3]);
                        for(int q=0;q<4;++q) {
                            texCoords[texCoords.size()-8+q*2]=-(v[q].x-(x-w/2))*0.5f;
                            texCoords[texCoords.size()-7+q*2]=(v[q].z-(z-depth/2)-start)*0.0625f;
                        }
                    }
                    suppressShadow=false;
                    ++castleStudCount;
                } else face(p[0],p[1],p[2],p[3],n);
            }
            for(int si=-1;si<=1;si+=2) for(int sj=-1;sj<=1;sj+=2) {
                Ogre::Vector3 p[4],n=Ogre::Vector3::ZERO;n[axis]=si;n[j]=sj;
                for(int q=0;q<4;++q) {
                    p[q]=center;
                    p[q][axis]+=si*(half[axis]-(q==1||q==2?bevel:0));
                    p[q][j]+=sj*(half[j]-(q==0||q==3?bevel:0));
                    p[q][k]+=(q<2?-1:1)*(half[k]-bevel);
                }
                face(p[0],p[1],p[2],p[3],n);
            }
        }
        for(int sx=-1;sx<=1;sx+=2) for(int sy=-1;sy<=1;sy+=2) for(int sz=-1;sz<=1;sz+=2) {
            Ogre::Vector3 n(sx,sy,sz),p[3];
            for(int axis=0;axis<3;++axis) {
                p[axis]=center;
                for(int j=0;j<3;++j) p[axis][j]+=n[j]*(half[j]-(j==axis?0:bevel));
            }
            triangle(p[0],p[1],p[2],n);
        }
        // Rounded-box normals blend over chamfers while broad faces stay flat.
        for(unsigned i=firstVertex;i<index;++i) {
            Ogre::Vector3 p(vertices[i*3]-x,vertices[i*3+1]-y,vertices[i*3+2]-z),n;
            for(int axis=0;axis<3;++axis) {
                float inner=half[axis]-bevel;
                n[axis]=p[axis]-std::max(-inner,std::min(inner,p[axis]));
            }
            n.normalise();normals[i*3]=n.x;normals[i*3+1]=n.y;normals[i*3+2]=n.z;
        }
    }
