        static_cast<DemoSceneManager*>(scene)->createWorld();
        const float treePosition[6][2]={{-11,-10},{11,-10},{-11,0},{11,0},{-11,10},{11,10}};
        Builder rock(scene,"Dark stone grey",brickColour(199));
        rock.castShadows=false;
        for(int layer=0;layer<5;++layer) rock.brick(0,-2-layer*1.5f,0,27-layer*3,2,27-layer*3,false);
        for(int i=0;i<6;++i) rock.brick(treePosition[i][0],0.5f,treePosition[i][1],3,1,3,false);
        rock.finish(scene);
        Builder grass(scene,"Dark green",brickColour(28));
        grass.castShadows=false;
        grass.brick(0,-0.5f,0,26,1,26);grass.finish(scene);
        Builder stone(scene,"Light stone grey",brickColour(208));
        stone.brick(0,0.5f,0,17,1,17);
        // Wall spans end exactly at the four tower footprints.
        stone.brick(-6,4,0,2,6,7);stone.brick(6,4,0,2,6,7);
        stone.brick(0,4,-6,7,6,2);
        stone.brick(-2.5f,3.5f,6,2,5,2);stone.brick(2.5f,3.5f,6,2,5,2);
        stone.brick(0,6.5f,6,7,1,2);
        stone.brick(0,5,0,6,8,6,false);
        for(int x=-1;x<=1;x+=2) for(int z=-1;z<=1;z+=2) {
            stone.brick(x*6,5,z*6,5,8,5);
            // Every merlon follows the same one-on, one-off, two-stud rhythm.
            for(int i=-2;i<=2;i+=2) for(int j=-2;j<=2;j+=2)
                if(abs(i)==2||abs(j)==2) stone.brick(x*6+i,9.5f,z*6+j,1,1,1);
        }
        for(int i=-2;i<=2;i+=2) {
            stone.brick(i,7.5f,-6,1,1,1);stone.brick(i,7.5f,6,1,1,1);
            stone.brick(-6,7.5f,i,1,1,1);stone.brick(6,7.5f,i,1,1,1);
        }
        stone.finish(scene);
        Builder roof(scene,"Bright red",brickColour(21));
        for(int layer=0;layer<5;++layer) roof.brick(0,9.5f+layer,0,10-layer*2,1,std::max(2,8-layer*2));
        roof.finish(scene);
        Builder wood(scene,"Reddish brown",brickColour(192));
        for(int i=0;i<7;++i) wood.brick(0,0.5f,9+i,4,1,1);
        wood.brick(-2,1.5f,12,0.5f,0.5f,7,false);wood.brick(2,1.5f,12,0.5f,0.5f,7,false);
        for(int i=-1;i<=1;++i) wood.brick(i,3,6,1,4,1,false);
        wood.brick(0,1.5f,6.5f,3,0.5f,0.5f,false);wood.brick(0,4.5f,6.5f,3,0.5f,0.5f,false);
        for(int i=0;i<6;++i) wood.brick(treePosition[i][0],2,treePosition[i][1],1,2,1,false);
        wood.finish(scene);
        Builder dark(scene,"Black",brickColour(26));
        for(int x=-2;x<=2;x+=2) dark.brick(x,6.5f,3,0.5f,1.5f,0.5f,false);
        dark.finish(scene);
        Builder gold(scene,"Bright yellow",brickColour(24));
        gold.brick(0,15.5f,0,0.5f,3,0.5f,false);gold.brick(1,16.5f,0,2,1,0.5f,false);
        gold.brick(1,3,7,0.5f,0.5f,0.5f,false);
        gold.brick(-1.5f,1.5f,6.5f,0.5f,0.5f,0.5f,false);gold.brick(-1.5f,4.5f,6.5f,0.5f,0.5f,0.5f,false);
        gold.finish(scene);
        Builder trees(scene,"Earth green",brickColour(141));
        for(int i=0;i<6;++i) for(int tier=0;tier<3;++tier)
            trees.brick(treePosition[i][0],3.5f+tier,treePosition[i][1],3-tier,1,3-tier);
        trees.finish(scene);
