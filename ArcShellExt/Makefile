TARGETOS = BOTH
!include <win32.mak>
# $Id: Makefile 497 2008-12-07 03:17:37Z andre $

lflags  = /INCREMENTAL:NO /RELEASE /NOLOGO
dlllflags = $(lflags) -entry:_DllMainCRTStartup$(DLLENTRY) -dll

all: ArcShellExt$(XVER).dll

ArcShellExt$(XVER).dll: ArcShellExt.obj ArcShellExt.res
	$(implib) -machine:$(CPU) -def:ArcShellExt.def $** -out:ArcShellExt.lib
	$(link) $(dlllflags) -base:0x00400000  -out:$*.dll $** $(olelibsdll) shell32.lib ArcShellExt.lib comctl32.lib ArcShellExt.exp Lua\lua5.1$(XVER).lib

.cpp.obj:
	$(cc) $(cflags) -D_UNICODE -DUNICODE -I..\HsLua\src $*.cpp

ArcShellExt.res: ArcShellExt.rc
	$(rc) $(rcflags) $(rcvars) ArcShellExt.rc

clean:
	-1 del ArcShellExt$(XVER).dll ArcShellExt.lib ArcShellExt.dll.manifest ArcShellExt.obj ArcShellExt.exp ArcShellExt.res

zip:
	-1 del *.zip
	perl abpack.pl