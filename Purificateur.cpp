using namespace std;

#include "Purificateur.h"

Purificateur::Purificateur ( const Purificateur & unPurificateur )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Purificateur>" << endl;
#endif
    latitude = unPurificateur.latitude;
    longitude = unPurificateur.longitude;
    timestampBegin = unPurificateur.timestampBegin;
    timestampEnd = unPurificateur.timestampEnd;
} 

Purificateur::Purificateur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur>" << endl;
#endif
} 

Purificateur::Purificateur(float latitudeInput, float longitudeInput, string begin, string end)
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur>" << endl;
#endif
    latitude = latitudeInput;
    longitude = longitudeInput;
    timestampBegin = processTimestampString(begin);
    timestampEnd = processTimestampString(end);   
}

time_t& Purificateur::processTimestampString(string time) const {
    int year, month, day, hour, minute, second;
    const char *zStart = time.c_str();
    sscanf(zStart, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    // e.g. 2019-02-01 12:00:00
    struct tm timeStruct;
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    timeStruct.tm_hour = hour;
    timeStruct.tm_min = minute;
    timeStruct.tm_sec = second;
    timeStruct.tm_isdst = -1;
    time_t result = mktime(&timeStruct);
    return result;

}

Purificateur::~Purificateur ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Purificateur>" << endl;
#endif
} 

float Purificateur::GetLatitude() const {
    return latitude;
}

float Purificateur::GetLongitude() const {
    return longitude;
}

time_t Purificateur::GetTimestampBegin() const {
    return timestampBegin;
}

time_t Purificateur::GetTimestampEnd() const {
    return timestampEnd;
}

// difference in air quality before vs after cleaner added
int Purificateur::calculateEfficiency(float rayon, time_t begin, time_t end) const {
    int before = 1; // =Catalogue.getAverageQuality(latitude, longitude, rayon, begin)
    int after = 2; // =Catalogue.getAverageQuality(latitude, longitude, rayon, end)
    int result = after - before;
    return result;
}

// appeler la méthode getAverageQuality de 'Catalogue'
int Purificateur::calculateAirQuality(float rayon) const {
    int quality = 1; // = Catalogue.getAverageQuality(latitude, longitude, rayon)
    return quality;
}

// area that has improved after cleaner added
float Purificateur::calculatePurifiedZone() const {
    int rayon = 10.0; // call calculate efficiency with different radii until result < certain-value
    // radius is then that value
    return rayon;
}
