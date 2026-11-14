// Runtime acceptance for the original-method toolbar subset, not all of MFC/XTP.
const {chromium}=require('../../../work/codejock-wasm/browser-test/node_modules/playwright');
const assert=require('node:assert/strict');
const fs=require('node:fs');
const path=require('node:path');
(async()=>{
  const browser=await chromium.launch({executablePath:'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe',headless:true});
  const page=await browser.newPage({viewport:{width:960,height:420}});
  const errors=[];page.on('pageerror',e=>errors.push(e.message));
  try {
    await page.goto('http://127.0.0.1:8877/');
    await page.waitForFunction(()=>window.Module?.toolbarState?.controls?.length===4);
    assert.equal(await page.locator('button,input,select,[role=button]').count(),0);
    const state=()=>page.evaluate(()=>Module.toolbarState);
    const pos=async i=>{const s=await state();const r=s.controls[i];const c=await page.locator('canvas').boundingBox();return {x:c.x+(r.left+r.right)/2,y:c.y+(r.top+r.bottom)/2};};
    const move=async i=>{const p=await pos(i);await page.mouse.move(p.x,p.y);await page.waitForTimeout(50);};
    await move(0);await page.waitForFunction(()=>Module.toolbarState.selected===0);
    await page.mouse.down();await page.waitForFunction(()=>Module.toolbarState.capture&&Module.toolbarState.controls[0].pressed);
    await page.screenshot({path:path.resolve(__dirname,'../../../work/codejock-wasm/pressed.png')});
    await page.mouse.up();await page.waitForFunction(()=>Module.toolbarState.commands===1&&!Module.toolbarState.capture);
    assert.equal((await state()).lastCommand,100);assert.equal((await state()).controls[0].checked,true);
    await move(1);await page.mouse.down();await page.mouse.move(700,220);await page.waitForTimeout(50);await page.mouse.up();await page.waitForTimeout(80);
    assert.equal((await state()).commands,1,'outside release executed command');
    await move(3);await page.mouse.down();await page.mouse.up();await page.waitForTimeout(80);assert.equal((await state()).commands,1,'disabled control executed');
    await move(2);await page.keyboard.press('Enter');await page.waitForFunction(()=>Module.toolbarState.commands===2);
    assert.equal((await state()).lastCommand,102);
    await move(0);await page.mouse.down();await page.keyboard.press('Escape');await page.mouse.up();await page.waitForTimeout(100);assert.equal((await state()).commands,2,'escape did not cancel');
    await move(1);await page.mouse.down();await page.mouse.move(700,220);await move(1);await page.mouse.up();await page.waitForFunction(()=>Module.toolbarState.commands===3);
    assert.equal((await state()).lastCommand,101,'drag-out-and-back did not execute');
    await move(0);await page.mouse.down();await page.evaluate(()=>window.dispatchEvent(new Event('blur')));await page.mouse.up();await page.waitForTimeout(100);
    assert.equal((await state()).commands,3,'focus loss did not cancel');
    assert.equal((await state()).capture,false);
    await move(2);await page.keyboard.press('Space');await page.waitForFunction(()=>Module.toolbarState.commands===4);
    await page.keyboard.press('ArrowLeft');await page.keyboard.press('Enter');await page.waitForFunction(()=>Module.toolbarState.commands===5);
    assert.equal((await state()).lastCommand,101,'keyboard navigation failed');
    await page.mouse.click(700,220);await page.waitForTimeout(50);assert.equal((await state()).commands,5,'empty canvas executed a command');
    await page.setViewportSize({width:190,height:420});await page.waitForTimeout(100);const narrow=await state();assert(narrow.controls.some(r=>r.top>narrow.controls[0].top),'toolbar did not wrap');
    await page.setViewportSize({width:960,height:420});await page.waitForTimeout(100);
    const pixels=await page.locator('canvas').evaluate(canvas=>{
      const data=canvas.getContext('2d').getImageData(0,0,canvas.width,50).data;
      const colors=new Set();for(let i=0;i<data.length;i+=4)colors.add(`${data[i]},${data[i+1]},${data[i+2]}`);return colors.size;
    });
    assert(pixels>10,'toolbar paint/text missing');
    const result={passed:true,errors,state:await state()};assert.equal(errors.length,0);
    fs.writeFileSync(path.resolve(__dirname,'../../../work/codejock-wasm/browser-test.json'),JSON.stringify(result,null,2));
    await page.screenshot({path:path.resolve(__dirname,'../../../work/codejock-wasm/toolbar.png')});
    console.log(JSON.stringify(result));
  } finally {await browser.close();}
})().catch(e=>{console.error(e);process.exitCode=1;});
