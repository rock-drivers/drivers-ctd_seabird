rock_library(ctd_seabird
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(ctd_seabird_bin Main.cpp
    DEPS ctd_seabird)

