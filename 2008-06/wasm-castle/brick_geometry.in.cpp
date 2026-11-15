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
    // Slice all adjoining faces at the same atlas boundaries. The visible and
    // shadow meshes then have identical cap triangles and watertight shared edges.
    float surfaceX=0,surfaceZ=0,surfaceW=0,surfaceDepth=0;
    bool texturedTop=false;
    void face(Ogre::Vector3 a,Ogre::Vector3 b,Ogre::Vector3 c,Ogre::Vector3 d,Ogre::Vector3 outward) {
        if((b-a).crossProduct(c-a).dotProduct(outward)<0) std::swap(b,d);
        for(float start=0;start<surfaceDepth;start+=4) {
            float low=surfaceZ-surfaceDepth/2+start,high=std::min(low+4,surfaceZ+surfaceDepth/2);
            std::vector<Ogre::Vector3> polygon={a,b,c,d};
            for(int side=0;side<2;++side) {
                std::vector<Ogre::Vector3> clipped;
                float boundary=side?high:low;
                auto append=[&](Ogre::Vector3 v) {
                    if(clipped.empty()||(clipped.back()-v).squaredLength()>1e-12f) clipped.push_back(v);
                };
                for(unsigned i=0;i<polygon.size();++i) {
                    Ogre::Vector3 from=polygon[(i+polygon.size()-1)%polygon.size()],to=polygon[i];
                    bool fromIn=side?from.z<=boundary:from.z>=boundary;
                    bool toIn=side?to.z<=boundary:to.z>=boundary;
                    if(fromIn!=toIn) {
                        Ogre::Vector3 v=from+(to-from)*((boundary-from.z)/(to.z-from.z));
                        v.z=boundary;append(v);
                    }
                    if(toIn) append(to);
                }
                if(clipped.size()>1&&(clipped.front()-clipped.back()).squaredLength()<1e-12f) clipped.pop_back();
                polygon.swap(clipped);
            }
            for(unsigned i=1;i+1<polygon.size();++i) {
                Ogre::Vector3 v[3]={polygon[0],polygon[i],polygon[i+1]};
                if((v[1]-v[0]).crossProduct(v[2]-v[0]).squaredLength()<1e-12f) continue;
                triangle(v[0],v[1],v[2],outward);
                if(texturedTop&&outward.y==1&&outward.x==0&&outward.z==0) for(int q=0;q<3;++q) {
                    texCoords[texCoords.size()-6+q*2]=-(v[q].x-(surfaceX-surfaceW/2))*0.5f;
                    texCoords[texCoords.size()-5+q*2]=(v[q].z-low)*0.0625f;
                }
            }
        }
    }
    void brick(float x,float y,float z,float w,float h,float depth,bool studs=true) {
        float grid[6]={x,y,z,w,h,depth};
        for(int i=0;i<6;++i) if(fabs(grid[i]*2-std::floor(grid[i]*2+0.5f))>0.0001f)
            throw std::runtime_error("Castle block off half-stud grid");
        // Ogre 1.4 shadow extrusion duplicates vertices into 16-bit indices.
        // Flush between complete closed bricks, never through a solid's faces.
        unsigned count=132*unsigned(std::ceil(depth/4));
        if(index&&index+count>30000) finish(owner);
        unsigned firstVertex=index;
        ++castleBevelCount;
        castleBlocks.push_back({{x,y,z},{w,h,depth},material->getName(),studs});
        surfaceX=x;surfaceZ=z;surfaceW=w;surfaceDepth=depth;texturedTop=studs;
        if(studs)++castleStudCount;
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
                face(p[0],p[1],p[2],p[3],n);
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
