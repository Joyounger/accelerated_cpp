BCB = $(MAKEDIR)\..
BCC32 = bcc32
LINKER = ilink32

USERDEFINES = _DEBUG
INCLUDEPATH = $(BCB)\include;..\chapter04
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
WARNINGS= -w-csu
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -tWC -tWM- -c
LFLAGS = -D"" -ap -Tpe -x -Gn -v
SYSOBJ = c0x32.obj
SYSLIB = import32.lib cw32.lib


all:		fails_vec1.exe fails_vec2.exe fails_iters.exe fails_list.exe \
		split_main.exe split_main2.exe pics_main.exe

median.obj:	..\chapter04\median.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) /c ..\chapter04\median.cpp

Student_info.obj: ..\chapter04\Student_info.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) ..\chapter04\Student_info.cpp

fails_vec1.exe:	fails_vec1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) fails_vec1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!
fails_vec2.exe:	fails_vec2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) fails_vec2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

fails_iters.exe: fails_iters.obj ext_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) fails_iters.obj ext_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

fails_list.exe:	fails_list.obj list_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) fails_list.obj list_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

pics_main.exe:	pics_main.obj pics.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) pics_main.obj pics.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

split_main.exe:	split_main.obj split.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) split_main.obj split.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

split_main2.exe: split_main2.obj split.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) split_main2.obj split.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

test:		all
	fails_vec1.exe <..\data\grades
	fails_vec2.exe <..\data\grades
	fails_iters.exe <..\data\grades
	fails_list.exe <..\data\grades
	split_main.exe < split_main.cpp
	split_main2.exe < split_main2.cpp
	pics_main.exe



# Say "make -fchapter05.bor clobber" to get rid of files created by nmake
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