BCB = $(MAKEDIR)\..
BCC32 = bcc32
LINKER = ilink32

USERDEFINES = _DEBUG
INCLUDEPATH = $(BCB)\include;..\chapter04;..\chapter05
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -tWC -tWM- -c
LFLAGS = -D"" -ap -Tpe -x -Gn -v
SYSOBJ = c0x32.obj 
SYSLIB = import32.lib cw32.lib

all:		split_main.exe palin.exe urls_main.exe grade_analysis.exe \
		ext_fails1.exe ext_fails2.exe


median.obj:	..\chapter04\median.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) ..\chapter04\median.cpp

Student_info.obj:	..\chapter04\Student_info.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES)  ..\chapter04\Student_info.cpp

split_main.obj:	..\chapter05\split_main.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES)  ..\chapter05\split_main.cpp

split_main.exe:	split_main.obj split.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) split_main.obj split.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

urls_main.exe:	urls_main.obj urls.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) urls_main.obj urls.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

grade_analysis.exe: grade_analysis.obj analysis.obj grade_check.obj \
		 grade.obj median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) grade_analysis.obj analysis.obj grade_check.obj \
		 grade.obj median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!
ext_main.obj:	..\chapter05\ext_main.cpp
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES)  ..\chapter05\ext_main.cpp

ext_fails1.exe:	ext_fails1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) ext_fails1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!
ext_fails2.exe: ext_fails2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) ext_fails2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!
test:		all
	split_main <split.cpp
	palin <..\data\palins_input
	urls_main <..\data\urls.htm
	grade_analysis <..\data\grades
	ext_fails1 <..\data\grades
	ext_fails2 <..\data\grades



# Say "make -fchapter06.bor clobber" to get rid of files created by nmake
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