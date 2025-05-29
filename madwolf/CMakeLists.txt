set(SOURCES
	maccompat.c
	MWF.c
	MWFile.cpp
	MWThreadManager.cpp
	network.c
	secure.c
	util.c
)

set(HEADERS
	maccompat.h
	manor.h
	mw_exception.h
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
