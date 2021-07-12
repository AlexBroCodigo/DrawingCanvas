#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ArbolAvlUsuarios.o \
	${OBJECTDIR}/ArbolCapas.o \
	${OBJECTDIR}/ListaCabeceras.o \
	${OBJECTDIR}/ListaCircularImagenes.o \
	${OBJECTDIR}/ListaHorizontal.o \
	${OBJECTDIR}/ListaLaterales.o \
	${OBJECTDIR}/ListaSimpleCapas.o \
	${OBJECTDIR}/ListaSimpleImagenes.o \
	${OBJECTDIR}/ListaTopImagenes.o \
	${OBJECTDIR}/ListaTopUsuarios.o \
	${OBJECTDIR}/ListaVertical.o \
	${OBJECTDIR}/MatrizCapa.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawingcanvas.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawingcanvas.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/drawingcanvas ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ArbolAvlUsuarios.o: ArbolAvlUsuarios.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArbolAvlUsuarios.o ArbolAvlUsuarios.cpp

${OBJECTDIR}/ArbolCapas.o: ArbolCapas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ArbolCapas.o ArbolCapas.cpp

${OBJECTDIR}/ListaCabeceras.o: ListaCabeceras.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaCabeceras.o ListaCabeceras.cpp

${OBJECTDIR}/ListaCircularImagenes.o: ListaCircularImagenes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaCircularImagenes.o ListaCircularImagenes.cpp

${OBJECTDIR}/ListaHorizontal.o: ListaHorizontal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaHorizontal.o ListaHorizontal.cpp

${OBJECTDIR}/ListaLaterales.o: ListaLaterales.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaLaterales.o ListaLaterales.cpp

${OBJECTDIR}/ListaSimpleCapas.o: ListaSimpleCapas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaSimpleCapas.o ListaSimpleCapas.cpp

${OBJECTDIR}/ListaSimpleImagenes.o: ListaSimpleImagenes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaSimpleImagenes.o ListaSimpleImagenes.cpp

${OBJECTDIR}/ListaTopImagenes.o: ListaTopImagenes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaTopImagenes.o ListaTopImagenes.cpp

${OBJECTDIR}/ListaTopUsuarios.o: ListaTopUsuarios.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaTopUsuarios.o ListaTopUsuarios.cpp

${OBJECTDIR}/ListaVertical.o: ListaVertical.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaVertical.o ListaVertical.cpp

${OBJECTDIR}/MatrizCapa.o: MatrizCapa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatrizCapa.o MatrizCapa.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
