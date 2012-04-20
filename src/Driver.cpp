/*
 * Driver.cpp
 *
 *  Created on: 30.11.2011
 *      Author: jrenken
 */

#include <string>
#include <iostream>
#include <errno.h>
#include <iodrivers_base/Timeout.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

#include "Driver.hpp"

using namespace ctd_seabird;
using namespace std;
using namespace boost;


Driver::Driver()
    : iodrivers_base::Driver(64)
{
    data.temperature = 0;
    data.conductivity = 0;
    data.pressure = 0;
    data.salinity = 0;
    data.soundvel = 0;
}

void Driver::open(const std::string & uri)
{
    openURI(uri);
}


void Driver::collectPeriodicData()
{
    string message;
    try {
        message = read(2000);
    } catch (iodrivers_base::TimeoutError&) {
        cout << "ctd_seabird timeout" << endl;
        return;
    }

    vector<string> fields;
    split( fields, message, is_any_of(", "),  token_compress_on  );
//    cout << "Data received: " << fields.size() << " >>" << message;
    if (fields.size() > 2 ) {
        data.time = base::Time::now();
        data.temperature = atof(fields[0].c_str());
        data.conductivity = atof(fields[1].c_str());
        data.pressure = atof(fields[2].c_str());
        if (fields.size() > 3) {
            data.salinity = atof(fields[3].c_str());
            if (fields.size() > 4)
                data.soundvel = atof(fields[4].c_str());
        }
    }

}

ctd_seabird::CtdData Driver::getData() const
{
    return data;
}

void Driver::dumpData() const
{
    cout << setprecision(3) << data.time << " "
         << setprecision(4) << data.temperature << " "
         << setprecision(5) << data.conductivity << " "
         << setprecision(3) << data.pressure << " "
         << setprecision(4) << data.salinity << " "
         << setprecision(3) << data.soundvel << endl;
}

std::string Driver::read(int timeout)
{
//  ttt.tttt, cc.ccccc, pppp.ppp, sss.ssss, vvvv.vvv

    char buffer[MAX_PACKET_SIZE];
    size_t packet_size = readPacket(reinterpret_cast<uint8_t *>( buffer), MAX_PACKET_SIZE, 5000, timeout);
    return string(buffer, packet_size);
}



int Driver::extractPacket(const uint8_t *buffer, size_t buffer_size) const
{
//    std::cout << "ctd_seabird: " << iodrivers_base::Driver::printable_com(buffer, buffer_size) << std::endl;

    for (size_t i = 0; i < buffer_size; i++) {
        if (buffer[i] == '\n') {
            if ( i < 22 ) {
                return -(i + 1);
            }
            return i + 1;
        }
    }
    return 0;
}



