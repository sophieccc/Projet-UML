
#if ! defined ( PURIFICATEUR_H )
#define PURIFICATEUR_H

#include <ctime>
#include <string>

class Purificateur 
{

public:

    Purificateur ( const Purificateur & unPurificateur );
    Purificateur();
    ~Purificateur ( );
    Purificateur (float latitude, float longitude, string begin, string end);

    float GetLatitude() const;
    float GetLongitude() const;   
    time_t GetTimestampBegin() const;
    time_t GetTimestampEnd() const;

    int calculateEfficiency(float rayon, time_t begin, time_t end) const;
    int calculateAirQuality(float rayon) const;
    float calculatePurifiedZone() const;

protected:

    float latitude;
    float longitude;
    time_t timestampBegin;
    time_t timestampEnd;

    time_t& processTimestampString(string time) const;

};

#endif // PURIFICATEUR_H
