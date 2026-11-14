        sceneBuildId=1;
        Builder millRock(scene,"Dark stone grey",brickColour(199));
        millRock.castShadows=false;
        for(int layer=0;layer<5;++layer) millRock.brick(80,-2-layer*1.5f,0,30-layer*4,2,26-layer*3,false);
        millRock.finish(scene);
        Builder millGrass(scene,"Dark green",brickColour(28));
        millGrass.castShadows=false;millGrass.brick(80,-0.5f,0,28,1,24);millGrass.finish(scene);
        Builder millBody(scene,"White",brickColour(1));
        // A hollow house: wall pieces stop at every window and doorway.
        millBody.brick(80,7,-3.5f,10,14,1,false);
        millBody.brick(80,0.5f,0,8,1,6,false);
        millBody.brick(80,4.5f,-0.5f,8,0.5f,5,false);
        millBody.brick(80,8.5f,-0.5f,8,0.5f,5,false);
        millBody.brick(80,13.5f,-0.5f,8,0.5f,5,false);
        const float frontRows[][2]={{0,4},{5,7},{9,11}};
        for(const auto& row:frontRows) {
            float y=(row[0]+row[1])*0.5f,h=row[1]-row[0];
            millBody.brick(77,y,3.5f,4,h,1,false);
            millBody.brick(83,y,3.5f,4,h,1,false);
        }
        const float frontBands[][2]={{4,5},{7,9},{11,14}};
        for(const auto& band:frontBands) millBody.brick(80,(band[0]+band[1])*0.5f,3.5f,10,band[1]-band[0],1,false);
        for(int side=-1;side<=1;side+=2) {
            for(int y=6;y<=10;y+=4) {
                millBody.brick(80+side*4.5f,y,-2,1,2,2,false);
                millBody.brick(80+side*4.5f,y,2,1,2,2,false);
            }
            millBody.brick(80+side*4.5f,2.5f,0,1,5,6,false);
            millBody.brick(80+side*4.5f,8,0,1,2,6,false);
            millBody.brick(80+side*4.5f,12.5f,0,1,3,6,false);
        }
        for(int layer=0;layer<5;++layer) {
            int width=10-layer*2;
            if(layer==2||layer==3) {
                millBody.brick(80-(width+2)*0.25f,14.5f+layer,0,(width-2)*0.5f,1,8,false);
                millBody.brick(80+(width+2)*0.25f,14.5f+layer,0,(width-2)*0.5f,1,8,false);
            } else millBody.brick(80,14.5f+layer,0,width,1,8,false);
        }
        for(int side=-1;side<=1;side+=2) {
            float x=80+side*8;
            millBody.brick(x,3,-3,6,4,1,false);
            millBody.brick(x-2.5f,3,0,1,4,5,false);
            millBody.brick(x+2.5f,3,0,1,4,5,false);
            millBody.brick(x-2,3,3,2,4,1,false);
            millBody.brick(x+2,3,3,2,4,1,false);
            millBody.brick(x,4.5f,3,2,1,1,false);
            if(side<0) millBody.brick(x,1.5f,3,2,1,1,false);
            millBody.brick(x,1,0,4,0.5f,5,false);
        }
        millBody.finish(scene);
        Builder millTrim(scene,"Dark orange",brickColour(38));
        // Thin exterior belt, clear of the window and door openings.
        millTrim.brick(80,4.5f,-4.5f,10,0.5f,0.5f,false);
        for(int side=-1;side<=1;side+=2) millTrim.brick(80+side*5.5f,4.5f,0,0.5f,0.5f,8,false);
        for(int x=-1;x<=1;x+=2) {
            for(int z=-1;z<=1;z+=2) {
                millTrim.brick(80+x*5,7,z*4,0.5f,14,0.5f,false);
                millTrim.brick(80+x*10.5f,0.5f,z*2.5f,0.5f,1,0.5f,false);
            }
        }
        millTrim.finish(scene);
        Builder millRoof(scene,"Bright red",brickColour(21));
        // Whole gable plates, with a long ridge rather than a pyramid roof.
        for(int layer=0;layer<7;++layer) millRoof.brick(80,14.5f+layer,0,14-layer*2,1,11);
        for(int layer=0;layer<3;++layer) millRoof.brick(72,5.5f+layer*0.5f,0,7-layer,0.5f,8-layer);
        millRoof.brick(88,5.5f,0,7,0.5f,8);millRoof.finish(scene);
        Builder millFrames(scene,"Light stone grey",brickColour(208));
        for(int y=6;y<=10;y+=4) {
            for(int edge=-1;edge<=1;edge+=2) {
                millFrames.brick(80+edge,y,3.5f,0.5f,2.5f,0.5f,false);
                millFrames.brick(80,y+edge,3.5f,1.5f,0.5f,0.5f,false);
                for(int side=-1;side<=1;side+=2) {
                    millFrames.brick(80+side*4.5f,y,edge,0.5f,2.5f,0.5f,false);
                    millFrames.brick(80+side*4.5f,y+edge,0,0.5f,0.5f,1.5f,false);
                }
            }
        }
        for(int edge=-1;edge<=1;edge+=2) {
            millFrames.brick(80+edge,17,3.5f,0.5f,2.5f,0.5f,false);
            millFrames.brick(80,17+edge,3.5f,1.5f,0.5f,0.5f,false);
            millFrames.brick(72+edge,3,3,0.5f,2.5f,0.5f,false);
            millFrames.brick(72,3+edge,3,1.5f,0.5f,0.5f,false);
        }
        millFrames.finish(scene);
        Builder glass(scene,"Windmill glass",brickColour(102));
        glass.castShadows=false;
        for(int y=6;y<=10;y+=4) {
            glass.brick(80,y,3,1.5f,1.5f,0.5f,false);
            for(int side=-1;side<=1;side+=2) glass.brick(80+side*4,y,0,0.5f,1.5f,1.5f,false);
        }
        glass.brick(80,17,3,1.5f,1.5f,0.5f,false);
        glass.brick(72,3,2.5f,1.5f,1.5f,0.5f,false);
        applyWindowReflectance(glass.material,0.45f);
        glass.finish(scene);
        Builder millDoor(scene,"Reddish brown",brickColour(192));
        for(int plank=-1;plank<=1;plank+=2) {
            millDoor.brick(80+plank*0.5f,2,3,1,4,0.5f,false);
            millDoor.brick(88+plank*0.5f,2.5f,2.5f,1,3,0.5f,false);
        }
        for(int edge=-1;edge<=1;edge+=2) {
            millDoor.brick(80+edge*1.5f,2,4,1,4,1,false);
            millDoor.brick(88+edge*1.5f,2.5f,3.5f,1,3,1,false);
        }
        millDoor.brick(80,4.5f,4,4,1,1,false);
        millDoor.brick(88,4.5f,3.5f,4,1,1,false);
        millDoor.brick(80,0,4.5f,3,0.5f,2);
        millDoor.finish(scene);
        Builder handles(scene,"Bright yellow",brickColour(24));
        handles.brick(80.5f,2,3.5f,0.5f,0.5f,0.5f,false);
        handles.brick(88.5f,2.5f,3,0.5f,0.5f,0.5f,false);handles.finish(scene);
        Builder trunks(scene,"Reddish brown",brickColour(192));
        Builder leaves(scene,"Earth green",brickColour(141));
        const float millTree[5][2]={{-11,-8},{11,-8},{-3,-9},{-11,8},{11,8}};
        for(int tree=0;tree<5;++tree) {
            float x=80+millTree[tree][0],z=millTree[tree][1];
            trunks.brick(x,1.5f,z,1,3,1,false);
            for(int tier=0;tier<3;++tier) leaves.brick(x,3.5f+tier,z,4-tier,1,4-tier);
        }
        trunks.finish(scene);leaves.finish(scene);
        // Lattice rails and open slots, not solid paddle blades. All geometry
        // moves through the recovered scene-node/entity transform and shadows.
        Builder sails(scene,"Brick yellow",brickColour(5));
        for(int arm=0;arm<4;++arm) {
            for(int rail=0;rail<2;++rail) {
                float x=rail*1.5f,y=4.5f;
                for(int turn=0;turn<arm;++turn) {float previous=x;x=-y;y=previous;}
                sails.brick(x,y,0,arm%2?7:0.5f,arm%2?0.5f:7,0.5f,false);
            }
            for(int rung=0;rung<8;++rung) {
                float x=0.5f,y=1+rung;
                for(int turn=0;turn<arm;++turn) {float previous=x;x=-y;y=previous;}
                sails.brick(x,y,0,arm%2?0.5f:1.5f,arm%2?1.5f:0.5f,0.5f,false);
            }
        }
        sails.brick(0,0,0,1.5f,1.5f,1,false);
        sails.finish(scene);windmillRotor=sails.object;
        windmillTransformKey=static_cast<DemoSceneManager*>(scene)->parts.size();
