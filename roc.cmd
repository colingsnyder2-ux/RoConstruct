@echo off
setlocal
cd /d "%~dp0"
title RoConstruct
set PY=py -3.12
%PY% -c "import sys" >nul 2>nul || set PY=py
%PY% -c "import pefile, capstone" >nul 2>nul || (
  echo RoConstruct is not set up yet. Double-click install.cmd first.
  pause & exit /b 1
)
%PY% roc.py %*
if "%~1"=="" pause
