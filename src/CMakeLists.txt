rock_library(ctd_seabird
    SOURCES Driver.cpp
    HEADERS Driver.hpp CtdTypes.hpp
    DEPS_PKGCONFIG base-types iodrivers_base)

rock_executable(ctd_seabird_bin 
	Main.cpp
    DEPS ctd_seabird)

