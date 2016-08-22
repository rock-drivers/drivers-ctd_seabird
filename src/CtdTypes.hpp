/*
 * Types.hpp
 *
 *  Created on: 01.12.2011
 *      Author: jrenken
 */

#ifndef CTD_SEABIRD_CTDTYPES_HPP
#define CTD_SEABIRD_CTDTYPES_HPP

#include <base/Time.hpp>

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


#endif /* CTD_SEABIRD_CTDTYPES_HPP */
