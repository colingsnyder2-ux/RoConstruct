@echo off
rem Host the RoConstruct group server: public HTTPS address (Cloudflare tunnel),
rem website updated and pushed every hour. Keep this window open.
cd /d "%~dp0"
title RoConstruct server
set PY=py -3.12
%PY% -c "import sys" >nul 2>nul || set PY=py
:loop
%PY% roc.py server --tunnel --publish
echo Server stopped. Restarting in 30 seconds (close this window to quit)...
timeout /t 30 >nul
goto loop
