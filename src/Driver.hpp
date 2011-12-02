/*
 * Driver.hpp
 *
 *  Created on: 30.11.2011
 *      Author: jrenken
 */

#ifndef CTD_SEABIRD_DRIVER_HPP
#define CTD_SEABIRD_DRIVER_HPP

#include <iodrivers_base/Driver.hpp>
#include "CtdTypes.hpp"

namespace ctd_seabird
{

    class Driver : public iodrivers_base::Driver
    {
    public:
        Driver();

        /** Tries to access the CTD at the provided URI
         *
         */
        void open(std::string const& uri);
        /** Reads available data and update the \c data structure. If
         * this method returns true, then \c data has been updated with
         * a new, synchronized set of information. Otherwise, call
         * collectPeriodicData again.
         */
        void collectPeriodicData();

        ctd_seabird::CtdData getData() const;

        void dumpData() const;

    protected:
        /** Read available packets on the I/O */
        std::string read(int timeout);

        /** Extract an ASCII line from incoming Data
         *
         */
        int extractPacket (uint8_t const *buffer, size_t buffer_size) const;

    private:
        ctd_seabird::CtdData     data;
    };

} /* namespace ctd_seabird */
#endif /* CTD_SEABIRD_DRIVER_HPP */
