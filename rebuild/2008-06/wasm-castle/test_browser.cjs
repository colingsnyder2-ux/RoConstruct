// Isolated browser runtime gate. This diagnostic is not the final castle test.
const {chromium} = require('../../../work/wasm-castle/browser-test/node_modules/playwright');
const fs = require('fs');
const path = require('path');
const output = path.resolve(__dirname, '../../../work/wasm-castle/build');
const castle = process.argv.includes('--castle');
(async () => {
  const browser = await chromium.launch({
    executablePath: 'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe',
    headless: true,
    args: ['--enable-webgl', '--enable-unsafe-swiftshader', '--use-angle=swiftshader']
  });
  const page = await browser.newPage({viewport: {width: 1100, height: 780}});
  const messages = [], errors = [];
  page.on('console', message => messages.push({type: message.type(), text: message.text()}));
  page.on('pageerror', error => errors.push(error.stack));
  let initialized = false, state = null;
  try {
    await page.goto(process.env.CASTLE_URL || 'http://127.0.0.1:8765/', {waitUntil: 'load'});
    for (let i = 0; i < 60; ++i) {
      if (messages.some(m => m.text.includes(castle ? 'Native RBX castle initialized' : 'Browser Ogre renderer initialized'))) { initialized = true; break; }
      if (errors.length || messages.some(m => /bootstrap failed|Aborted\(/.test(m.text))) break;
      await page.waitForTimeout(250);
    }
    await page.waitForTimeout(250);
    state = await page.evaluate(() => {
      const canvas = document.querySelector('canvas'), gl = canvas.getContext('webgl2');
      if (!gl) return {context: false};
      const pixels = new Uint8Array(4);
      gl.readPixels(canvas.width >> 1, canvas.height >> 1, 1, 1, gl.RGBA, gl.UNSIGNED_BYTE, pixels);
      const corner = new Uint8Array(4);
      gl.readPixels(2, 2, 1, 1, gl.RGBA, gl.UNSIGNED_BYTE, corner);
      const image = new Uint8Array(canvas.width * canvas.height * 4);
      gl.readPixels(0, 0, canvas.width, canvas.height, gl.RGBA, gl.UNSIGNED_BYTE, image);
      const colours = new Set();
      for (let i = 0; i < image.length; i += 16) colours.add(image.slice(i, i + 4).join(','));
      return {context: true, stencil: gl.getParameter(gl.STENCIL_BITS),
        width: canvas.width, height: canvas.height, pixel: [...pixels], corner: [...corner],
        colours: colours.size, error: gl.getError(), version: gl.getParameter(gl.VERSION), castle: Module.castleState};
    });
    await page.screenshot({path: path.join(output, castle ? 'browser-castle.png' : 'browser-bootstrap.png')});
  } catch (error) { errors.push(error.stack); }
  const passed = initialized && !errors.length && state?.stencil >= 8 &&
    (castle ? state.castle?.batches === 8 && state.castle.frames > 1 && state.colours > 100 :
      state.corner[0] >= 13 && state.corner[0] <= 18 && state.corner[2] >= 60 && state.corner[2] <= 68 && state.colours > 5)
    && state.error === 0;
  const result = {passed, initialized, state, errors, messages};
  fs.writeFileSync(path.join(output, castle ? 'browser-castle.json' : 'browser-bootstrap.json'), JSON.stringify(result, null, 2));
  console.log(JSON.stringify({passed, initialized, state, errors, tail: messages.slice(-8)}, null, 2));
  await browser.close();
  process.exitCode = passed ? 0 : 1;
})();
