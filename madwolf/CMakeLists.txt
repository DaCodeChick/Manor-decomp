set(SOURCES
	error.cpp
	maccompat.c
	MWF.c
	MWFile.cpp
	MWThreadManager.cpp
	network.c
	secure.c
	util.c
)

set(HEADERS
	error.h
	maccompat.h
	manor.h
	MWF.h
	MWFile.h
	MWThreadManager.h
	network.h
	secure.h
	util.h
)

add_library(
	MWF SHARED
	${SOURCES}
	${HEADERS}
)
