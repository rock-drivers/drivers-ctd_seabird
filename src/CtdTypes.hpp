/*
 * Types.hpp
 *
 *  Created on: 01.12.2011
 *      Author: jrenken
 */

#ifndef CTD_SEABIRD_TYPES_HPP
#define CTD_SEABIRD__TYPES_HPP

#include <base/time.h>

namespace ctd_seabird {
    // namespace ctd_seabird

    struct CtdData {
        base::Time  time;
        double  temperature;
        double  conductivity;
        double  pressure;
        double  salinity;
        double  soundvel;
    };


}


#endif /* CTD_SEABIRD_TYPES_HPP */
