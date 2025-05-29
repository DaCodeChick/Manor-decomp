set(SOURCES
	maccompat.c
	network.c
	secure.c
	util.c
)

set(HEADERS
	maccompat.h
	manor.h
	network.h
	secure.h
	typedefs.h
	util.h
)

add_library(
	TheManor SHARED
	${SOURCES}
	${HEADERS}
)
