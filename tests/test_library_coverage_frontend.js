"use strict";
const assert = require("node:assert/strict"), fs = require("node:fs"), vm = require("node:vm");
const html = fs.readFileSync("docs/index.html", "utf8");
const context = {integrationData: {client:"2008-06",native:["00000001"]},
  hex:n=>n.toString(16).padStart(8,"0"),fmt:String,pct:(n,t)=>String(t?100*n/t:0),mb:String,
  esc:String,codeBar:()=>"mining",integrationCoverageBar:()=>"native",sectionMode:()=>"switch"};
vm.createContext(context);
vm.runInContext(html.slice(html.indexOf("const MFC ="), html.indexOf("function libraryTable(")),context);
vm.runInContext(fs.readFileSync("docs/library-coverage.js","utf8"),context);
const data={name:"2008-06",units:["Ogre::RbxSceneManager","Ogre::SharedPtr","G3D::Image"],funcs:[
  [1,100,100,0,true,["ogre-1.4.5-dll","OgreSceneManager.cpp"]],
  [2,100,100,1,true,["ogre-1.6.4","OgreSharedPtr.cpp"]],
  [3,100,100,0,false],
  [4,100,100,2,true,["g3d-6.09-png-dll","pngread.c"]],
  [5,100,100,2,true,["wildmagic-2-core","Vector.cpp"]],
]};
const kinds=context.classify(data);
assert.equal(kinds[0][1],"Ogre 1.4.5 recipe");
assert.equal(kinds[1][1],"Other Ogre versions (codegen analogs)");
assert.equal(kinds[2][1],"Roblox Ogre extensions (class label)");
assert.equal(kinds[3][1],"Bundled PNG source");
assert.equal(kinds[4][0],"Codegen analogs");
const rendered=context.libraryTable(data,true,true);
assert.match(rendered,/<th>Byte-exact<\/th><th>Integrated<\/th>/);
assert.match(rendered,/>Ogre<\/td><td>3 \/ 3<\/td><td>1 \/ 3<\/td>/);
assert.match(rendered,/full forced link blocked by 12/);
assert.match(rendered,/Imported DLL bodies are outside this denominator/);
assert.equal([...data.groups.values()].reduce((n,row)=>n+row[1].size,0),data.funcs.length);
assert.doesNotMatch(context.libraryTable({...data,name:"2007-03"}),/<th>Integrated<\/th>|Local native builds/);
assert.match(context.libraryTable({name:"2008-06",units:[],funcs:[]}),/<tbody>\s*<\/tbody>/);
new vm.Script(html.match(/<script>([\s\S]*?)<\/script>/)[1]);
console.log("Library coverage frontend tests passed.");
