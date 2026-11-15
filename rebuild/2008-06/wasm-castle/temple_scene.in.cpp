        sceneBuildId=2;
        const float tx=160;
        // Every centre and size sits on the half-stud grid. Neighbouring pieces
        // touch but never overlap, so no face is drawn twice (no z-fighting).
        Builder tRock(scene,"Dark stone grey",brickColour(199));
        tRock.castShadows=false;
        for(int layer=0;layer<5;++layer) tRock.brick(tx,-2-layer*1.5f,0,60-layer*6,2,60-layer*6,false);
        tRock.finish(scene);
        // Island top: grass ring, then a sand beach, around a 40x40 stone floor.
        Builder tGrass(scene,"Dark green",brickColour(28));
        tGrass.castShadows=false;
        tGrass.brick(tx-23.5f,-0.5f,0,7,1,54);tGrass.brick(tx+23.5f,-0.5f,0,7,1,54);
        tGrass.brick(tx,-0.5f,-23.5f,40,1,7);tGrass.brick(tx,-0.5f,23.5f,40,1,7);
        tGrass.finish(scene);
        Builder tSand(scene,"Brick yellow",brickColour(5));
        tSand.castShadows=false;
        tSand.brick(tx-28.5f,-0.5f,0,3,1,60);tSand.brick(tx+28.5f,-0.5f,0,3,1,60);
        tSand.brick(tx,-0.5f,-28.5f,54,1,3);tSand.brick(tx,-0.5f,28.5f,54,1,3);
        tSand.finish(scene);
        // Building: 28 wide (x), 20 deep (z), 16 tall, 6x9 doorway.
        // Floor all around it: thin red square-key lines on white tiles.
        Builder fw(scene,"White",brickColour(1));
        Builder fr(scene,"Bright red",brickColour(21));
        fw.castShadows=false;fr.castShadows=false;
        fw.brick(tx,-0.5f,-9.5f,28,1,1,false);fw.brick(tx,-0.5f,9.5f,28,1,1,false);
        fw.brick(tx-13.5f,-0.5f,0,1,1,18,false);fw.brick(tx+13.5f,-0.5f,0,1,1,18,false);
        for(int r=0;r<40;++r) {
            int j=r%10,cell[40];
            for(int c=0;c<40;++c) {
                if(c>=6&&c<34&&r>=10&&r<30) {cell[c]=2;continue;}   // building footprint
                int i=c%10,ring=std::min(std::min(i,j),std::min(9-i,9-j));
                bool on=(ring==1||ring==3);
                if(ring==1&&i==1&&(j==4||j==5)) on=false;   // key gap, left
                if(ring==3&&i==6&&(j==4||j==5)) on=false;   // key gap, right
                cell[c]=on?1:0;
            }
            for(int c=0;c<40;) {
                int e=c;while(e<40&&cell[e]==cell[c]) ++e;
                if(cell[c]!=2) (cell[c]?fr:fw).brick(tx-20+c+(e-c)*0.5f,-0.5f,-19.5f+r,e-c,1,1,false);
                c=e;
            }
        }
        fw.finish(scene);fr.finish(scene);
        // Interior: grey floor, stair up the back wall, columns and wall lamps.
        Builder inside(scene,"Light stone grey",brickColour(208));
        inside.brick(tx,-0.5f,0,26,1,18,false);
        for(int k=0;k<8;++k) inside.brick(tx,(k+1)*0.5f,-1.5f-k,6,k+1,1,false);
        for(int s=-1;s<=1;s+=2) inside.brick(tx+s*8,8,4,1,16,1,false);
        inside.finish(scene);
        Builder lamps(scene,"Bright yellow",brickColour(24));
        for(int s=-1;s<=1;s+=2) for(int z=-4;z<=4;z+=8) lamps.brick(tx+s*12.5f,6,z,1,1,1,false);
        lamps.finish(scene);
        // Sixteen blue/white bands; the front wall leaves a doorway 6 wide, 9 tall.
        Builder blue(scene,"Bright blue",brickColour(23));
        Builder white(scene,"White",brickColour(1));
        for(int i=0;i<16;++i) {
            Builder& b=(i%2==0)?blue:white;
            float y=0.5f+i;
            b.brick(tx,y,-9.5f,28,1,1,false);
            b.brick(tx-13.5f,y,0,1,1,18,false);
            b.brick(tx+13.5f,y,0,1,1,18,false);
            if(i<9) {b.brick(tx-8.5f,y,9.5f,11,1,1,false);b.brick(tx+8.5f,y,9.5f,11,1,1,false);}
            else b.brick(tx,y,9.5f,28,1,1,false);
        }
        blue.finish(scene);white.finish(scene);
        Builder trim(scene,"White",brickColour(1));
        trim.brick(tx,16.5f,0,30,1,22,false);
        trim.brick(tx-13,18,9,2,2,2,false);trim.brick(tx+13,18,9,2,2,2,false);
        trim.finish(scene);
        // Slight canopy over the doorway.
        Builder canopy(scene,"Light stone grey",brickColour(208));
        canopy.brick(tx,9.5f,10.5f,8,1,1,false);
        canopy.finish(scene);
        // Thick open double doors swung outward, with iron straps.
        Builder doors(scene,"Reddish brown",brickColour(192));
        doors.brick(tx-3.5f,4.5f,12.5f,1,9,5,false);
        doors.brick(tx+3.5f,4.5f,12.5f,1,9,5,false);
        doors.finish(scene);
        Builder irons(scene,"Black",brickColour(26));
        for(int s=-1;s<=1;s+=2) for(int y=0;y<2;++y) irons.brick(tx+s*4,1.5f+y*6,12.5f,0.5f,0.5f,4.5f,false);
        irons.finish(scene);
        // Stepped gold dome (unchanged size), half-stud layers.
        Builder dome(scene,"Bright yellow",brickColour(24));
        for(int i=0;i<12;++i) {
            float h=(i+0.5f)*0.5f;
            float w=std::floor(2*std::sqrt(36.0f-h*h)+0.5f);
            dome.brick(tx,17+i*0.5f,0,w,0.5f,w,false);
        }
        dome.brick(tx,22.5f,0,1,1,1,false);
        for(int s=-1;s<=1;s+=2) {
            float x=tx+s*13;
            dome.brick(x,20.5f,9,1,3,1,false);
            dome.brick(x,22.5f,9,1,1,1,false);
            dome.brick(x,22.5f,10,0.5f,0.5f,1,false);
            dome.brick(x+s*1,20.5f,9,1,2,1,false);
        }
        dome.finish(scene);
        // Palm trees: leaning trunks with a crown of drooping fronds.
        Builder trunk(scene,"Reddish brown",brickColour(192));
        Builder frond(scene,"Earth green",brickColour(141));
        const float palms[][2]={{-24,-12},{-23,4},{-25,18},{24,-14},{23,8},{25,22},
            {-12,-24},{13,-25},{-14,24},{16,25},{-27,-3},{27,-4},{-6,28},{7,-28}};
        for(const auto& p:palms) {
            float x=tx+p[0],z=p[1];int dir=p[0]<0?-1:1;
            for(int k=0;k<7;++k) trunk.brick(x+dir*(k/3),k+0.5f,z,1,1,1,false);
            float cx=x+dir*2;
            frond.brick(cx,7.5f,z,1,1,1,false);
            for(int arm=1;arm<=3;++arm) {
                float y=8-arm*0.5f;
                frond.brick(cx+arm,y,z,1,1,1,false);frond.brick(cx-arm,y,z,1,1,1,false);
                frond.brick(cx,y,z+arm,1,1,1,false);frond.brick(cx,y,z-arm,1,1,1,false);
            }
            for(int s1=-1;s1<=1;s1+=2) for(int s2=-1;s2<=1;s2+=2) frond.brick(cx+s1,7,z+s2,1,1,1,false);
        }
        trunk.finish(scene);frond.finish(scene);
