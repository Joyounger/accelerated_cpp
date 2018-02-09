BCB = $(MAKEDIR)\..
BCC32 = bcc32
LINKER = ilink32

USERDEFINES = _DEBUG
INCLUDEPATH = $(BCB)\include;..\chapter04;..\chapter08
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -tWC -tWM- -c
LFLAGS = -D"" -ap -Tpe -x -Gn -v
SYSOBJ = c0x32.obj
SYSLIB = import32.lib cw32.lib

all:		grading_prog.exe

median.obj: ..\chapter04\median.cpp

grading_prog.exe: grading_prog.obj grade.obj Student_info.obj median.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) grading_prog.obj grade.obj Student_info.obj median.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

test:		all
	grading_prog.exe <..\data\grades



# Say "make -fchapter09.bor clobber" to get rid of files created by nmake
clobber:
	del *.obj
	del *.exe
	del *.tds

# To convert a .cpp file to a .obj file, run the compiler with these options:
.cpp.obj:
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

# To convert a collection of .obj files to a .exe file,
.obj.exe:
    $(BCB)\BIN\$(LINKER) @&&! +
	 $** +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ), +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!