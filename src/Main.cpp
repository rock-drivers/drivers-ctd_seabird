#include <iostream>
#include <ctd_seabird/Driver.hpp>

int main(int argc, char** argv)
{
    ctd_seabird::Driver driver;
    driver.open("udpserver://4949");

    while (true) {
        driver.collectPeriodicData();
        ctd_seabird::CtdData data = driver.getData();
        std::cout << data.time.toString() << "    ";
        driver.dumpData();
    }

	return 0;
}
