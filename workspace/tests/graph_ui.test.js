const test=require('node:test'), assert=require('node:assert/strict');
const ui=require('../docs/graph.js');
test('address and class search',()=>{assert(ui.matches(['0067d9b0','Ogre::RbxEntity::createSubEntity','Ogre::RbxEntity'],'0x0067D9B0'));assert(ui.matches(['1','A::f','A'],'a::'));assert(!ui.matches(['1','A::f','A'],'missing'));});
test('mining and integration independent filters',()=>{const n={states:{MINED:true,BLOCKED:true,LINKED:false}};assert(ui.visible(n,'MINED','BLOCKED'));assert(!ui.visible(n,'MINED','LINKED'));assert(ui.visible(n,'MINED','NOT_LINKED'));});
test('partitioning and hard rendering cap',()=>{assert.equal(ui.partition('0067d9b0'),'0067d');assert.equal(ui.partition('external:kernel32!Sleep'),'external');assert.equal(ui.partition('symbol:?missing@@'),'external');assert.equal(ui.limit,150);});
