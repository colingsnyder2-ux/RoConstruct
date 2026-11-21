@echo off
rem Host the RoConstruct group server: public HTTPS address (Cloudflare tunnel),
rem website updated and pushed every hour. Automatically restarts on crash/exit.
cd /d "%~dp0"
title RoConstruct server
set PY=py -3.12
%PY% -c "import sys" >nul 2>nul || set PY=py

:loop
echo [%date% %time%] Starting RoConstruct server...
%PY% roc.py server --publish
echo [%date% %time%] Server stopped with exit code %errorlevel%. Restarting in 5 seconds...
timeout /t 5 /nobreak >nul
goto loop
