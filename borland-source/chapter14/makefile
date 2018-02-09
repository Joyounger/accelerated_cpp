BCB = $(MAKEDIR)\..
BCC32 = bcc32
LINKER = ilink32

USERDEFINES = _DEBUG
INCLUDEPATH = $(BCB)\include;..\chapter08
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
WARNINGS= -w-par -w-lvc
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -tWC -tWM- -c
LFLAGS = -D"" -ap -Tpe -x -Gn -v
SYSOBJ = c0x32.obj
SYSLIB = import32.lib cw32.lib

all: std_main1.exe std_main2.exe std_main3.exe urls_main.exe

std_main1.exe:	std_main1.obj Student_info.obj Core.obj grade.obj read_hw.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) std_main1.obj Student_info.obj Core.obj grade.obj read_hw.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

std_main2.exe:	std_main2.obj Student_info.obj Core.obj grade.obj read_hw.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) std_main2.obj Student_info.obj Core.obj grade.obj read_hw.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

std_main3.exe:	std_main3.obj Student_info.obj Core.obj grade.obj read_hw.obj
			    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) std_main3.obj Student_info.obj Core.obj grade.obj read_hw.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

urls_main.exe:	urls_main.obj urls.obj Vec_clone.obj Str.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) urls_main.obj urls.obj Vec_clone.obj Str.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

test:	all
	std_main1.exe <..\data\mixed_grades
	std_main2.exe <..\data\mixed_grades
	std_main3.exe <..\data\mixed_grades
	urls_main.exe <..\data\urls.htm


# Say "make -fchapter00.bor clobber" to get rid of files created by nmake
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